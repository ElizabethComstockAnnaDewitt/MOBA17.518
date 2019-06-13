
#include"soldiers.h"

USING_NS_CC;
extern bool Visit[80][80];
extern Map<int, hatred1*> hatred;
extern int total_num;
extern Vector<Armor *> armors;
extern int soldierNum;
extern TMXTiledMap* MAP;
extern struct objs towers[2], heros[2], soldiers[2];
struct FGH
{
	int F, G, H;
	int num;
	friend bool operator<(struct FGH A, struct FGH B)
	{
		return A.F > B.F;
	}
};

void soldier::FindPath()
{
	int ti = 80 - this->target->getPositionY()/60;
	int tj = this->target->getPositionX() / 60;
	int mi = 80 - this->getPositionY() / 60;
	int mj = this->getPositionX() / 60;
	std::map<int, int> inopen, inclose, father;
	std::priority_queue< struct FGH> open;
	std::map<int, struct FGH> openvalue;
	int di[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	int dn[8] = { -80,-79,1,81,80,79,-1,-81 };
	inopen[80 * (mi - 1) + mj] = 1;
	struct FGH fir;
	fir.G = 0, fir.H = (abs(mi - ti) + abs(mj - tj)) * 10, fir.F = fir.G + fir.H;
	fir.num = 80 * (mi - 1) + mj;
	open.push(fir);
	openvalue[fir.num] = fir;
	father[fir.num] = -1;

	while (inopen[80 * (ti - 1) + tj] != 1)
	{
		if (open.empty())
			return;
		int n = open.top().num;
		int G = open.top().G;
		open.pop();
	//	CCLOG("%d", n);
		int ni, nj;
		if (n % 80 == 0)
			ni = n / 80, nj = 80;
		else
			ni = n / 80 + 1, nj = n % 80;
		
		for (int i = 0; i < 8; i++)
		{
			int newi = ni + di[i][0], newj = nj + di[i][1];
			int now_num = n + dn[i];
		//	int id = MAP->getLayer("layer0")->getTileGIDAt(Vec2(newi, newj));
			int dG;
			if (abs(ni - newi) + abs(nj - newj) == 1)
				dG = 14;
			else
				dG = 10;
			if (inclose[now_num]!=1 && Visit[newi][newj]==1)
			{
						if (inopen[now_num] != 1)
				{
							inopen[now_num] = 1;
					struct FGH now;
					
					now.H = 10 * (abs(newi - ti) + abs(newj - tj)), now.G = G + dG;
					now.num = now_num, now.F = now.G + now.H;
					open.push(now);
					father[now_num] = n;
					openvalue[now_num] = now;
				}
				else
				{
					if (G + dG < openvalue.at(now_num).G)
						openvalue[now_num].G = G + dG, openvalue[now_num].F =openvalue[now_num].G + openvalue[now_num].H, father[now_num] = n;
				}
			}
		}
		inopen[n] = 0;
		inclose[n] = 1;
	}
	int last = father[80 * (ti - 1) + tj];
		while (last != -1)
		{
			this->path.push_back(last);
			last = father[last];
		}
		reverse(this->path.begin(),this->path.end());
}
void soldier::addtoHatred()
{
	hatred1 *h1 = new hatred1;
	h1->color = this->color;
	//添加至仇恨系统
	int i;
	for (i = 0; i < towers[1 - this->color].list.size(); i++)
	{
		hatred2 *h2 = new hatred2;
		if(towers[1-this->color].list.at(i)->isDead==0)
		h2->enemy = towers[1 - this->color].list.at(i);
		//待改，设定初始仇恨值
		h2->hatredValue = 5;
		h1->mylist.pushBack(h2);
	}
	for (i = 0; i < soldiers[1 - this->color].list.size(); i++)
	{
		hatred2 *h2 = new hatred2;
		if (soldiers[1 - this->color].list.at(i)->isDead == 0)
		h2->enemy = soldiers[1 - this->color].list.at(i);
		//待改，设定初始仇恨值
		h2->hatredValue = 10;
		h1->mylist.pushBack(h2);
	}
	for (i = 0; i < heros[1 - this->color].list.size(); i++)
	{
		hatred2 *h2 = new hatred2;
		if (heros[1 - this->color].list.at(i)->isDead == 0)
		h2->enemy = heros[1 - this->color].list.at(i);
		//待改，设定初始仇恨值
		h2->hatredValue = 0;
		h1->mylist.pushBack(h2);
	
	}
	
	hatred.insert(this->num, h1);
}

Enemy* soldier::FindNewTarget()
{
	float max=-1;
	Enemy *tag;
	if (!hatred.at(this->num)->mylist.empty())
	{
		
		int i=0, n= 0, total = hatred.at(this->num)->mylist.size();
		while(n<total)
		{

			if (hatred.at(this->num)->mylist.at(i)->enemy->isDead == 1)
			{
				delete hatred.at(this->num)->mylist.at(i);
				hatred.at(this->num)->mylist.eraseObject(hatred.at(this->num)->mylist.at(i));
				i--;
			}
			else
			{
				float x = hatred.at(this->num)->mylist.at(i)->enemy->getPositionX();
				float y = hatred.at(this->num)->mylist.at(i)->enemy->getPositionY();;
				float mex = this->getPositionX();
				float mey = this->getPositionY();
				float dis = sqrt((x - mex)*(x - mex) + (y - mey)*(y - mey));
				if (dis <= this->searchRange)
				{
					if (hatred.at(this->num)->mylist.at(i)->hatredValue > max&&hatred.at(this->num)->mylist.at(i)->enemy->type!=2)
						max = hatred.at(this->num)->mylist.at(i)->hatredValue, tag = hatred.at(this->num)->mylist.at(i)->enemy;
				}
			}
			i++;
			n++;
		}
	}
	if (max == -1)
		return NULL;
	return tag;
}

void soldier::Attack(float t)
{
//	this->停止动画与动作
	this->stopAllActions();

//this->攻击动画开始

//	近战
	if (this->range <= 2.5)
	{
		target->health -= this->damage;
		if (target->damage <= 0)
		{
			target->die();
			this->target = NULL;
		}
	}
	//远程
	else
	{
		Armor *armor = Armor::createone(this->getPositionX(), this->getPositionY(),1);
		armor->father = this;
		armor->color = this->color;
		armor->damage = this->damage;
		float mex = this->getPositionX();
		float mey = this->getPositionY();
		float x = this->target->getPositionX();
		float y = this->target->getPositionY();
		float dis = sqrt((x - mex)*(x - mex) + (y - mey)*(y - mey));
		auto act = MoveTo::create(dis/armor->speed,Vec2(x,y));
		auto act1 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, armor));
		auto seque = Sequence::create(act, act1, NULL);
		armor->runAction(seque);
		armors.pushBack(armor);
	}

}

void soldier::MoveToTarget()
{
	if (this->count == this->path.size())
	{
		this->path.clear();
		this->count = 0;
		return;
	}
	float dis1, dis;
	float mex = this->getPositionX();
	float mey = this->getPositionY();
	float x = this->target->getPositionX();
	float y = this->target->getPositionY();
	dis1= sqrt((x - mex)*(x - mex) + (y - mey)*(y - mey));
	if (dis1 < this->range)
	{
		this->scheduleOnce(schedule_selector(soldier::Attack), 0);
		return;
	}
	int ni, nj;
	if (this->path.at(this->count) % 80 == 0)
		ni = this->path.at(this->count) / 80, nj = 80;
	else
		ni = this->path.at(this->count) / 80 + 1, nj = this->path.at(this->count) % 80;
		float dx = nj * 60-mex;
	float dy =(80 - ni) * 60-mey;
	float tagAng = std::atan2(dy, dx)*(180.0 / 3.1415926535);
	auto act0 = RotateBy::create(0.2,this->ang - tagAng);
	this->ang = tagAng;
	dis = sqrt(dx*dx + dy * dy);
	auto act1 = MoveTo::create(dis / this->speed, Vec2(nj*60, (80-ni)*60));
	auto act2 = CallFunc::create(CC_CALLBACK_0(soldier::MoveToTarget, this));
	auto seque = Sequence::create(act1, act2, NULL);
	//this->runAction(act0);
	this->runAction(seque);
	this->count++;


}

void soldier::MoveOrAttack(float t)
{
	this->stopAllActions();
	this->unschedule(schedule_selector(soldier::Attack));
	this->target = this->FindNewTarget();
	this->path.clear();
	this->count = 0;
	if (this->target == NULL)
	{
		if (!towers[1 - this->color].list.empty())
			this->target = towers[1 - this->color].list.front();
	}
	
	if (this->target != NULL)
	{
		float targetX = this->target->getPositionX();
		float targetY = this->target->getPositionY();
		float meX = this->getPositionX();
		float meY = this->getPositionY();
		float dis = sqrt((targetX - meX)*(targetX - meX) + (targetY - meY)*(targetY - meY));
		
		if (dis <= this->range&&this->target->isDead==0)
		{
			this->schedule(schedule_selector(soldier::Attack), 2, 2, 0);
		
		}
		else
		{
			this->FindPath();
			if (!this->path.empty())
				this->MoveToTarget();
		}
	}
}


void soldier::specialUpdate()
{
	this->schedule(schedule_selector(soldier::MoveOrAttack), 4.5);
}

void soldier::inTower()
{
	float mex = this->getPositionX(), mey = this->getPositionY();
	float dis;
	int i, ret = 0;
	for (i = 0; i < towers[1 - this->color].list.size(); i++)
	{
		float x = towers[1 - this->color].list.at(i)->getPositionX();
		float y = towers[1 - this->color].list.at(i)->getPositionY();
		dis = sqrt((x - mex)*(x - mex) + (y - mey)*(y - mey));
		if (dis <= towers[1 - this->color].list.at(i)->range)
			ret = 1;
		if (ret&&this->isInTower==0)
		{
			static_cast<Tower*>(towers[1 - this->color].list.at(i))->elist.pushBack(this);
			this->isInTower = 1;
			return;
		}
	}
	this->isInTower = ret;
	
}

void soldier::UPDATE()
{
	this->inTower();
	if (this->frozed == 1)
	{
		this->unscheduleAllSelectors();
		this->stopAllActions();
	}
	if (this->frozed == 0 && this->frozedJustNow == 1)
	{
		this->schedule(schedule_selector(soldier::MoveOrAttack), 4.5);
		this->frozedJustNow = 0;
	}
}

void soldier::beAttacked(Enemy* rival)
{
	int i;
	for (i = 0; i < hatred.at(this->num)->mylist.size(); i++)
	{
		if (rival == hatred.at(this->num)->mylist.at(i)->enemy)
			//待定，小兵被攻击时所增长的仇恨值
		{
			hatred.at(this->num)->mylist.at(i)->hatredValue += 10;
			return;
		}
	}
	
}