#include"HeroAI.h"
USING_NS_CC;
extern struct objs heros[2], soldiers[2], towers[2];
extern bool Visit[80][80];
extern Vector<Armor*> armors;
extern Hero* myHero;
extern Sprite* MAP;
struct FGH
{
	int F, G, H;
	int num;
	friend bool operator<(struct FGH A, struct FGH B)
	{
		return A.F > B.F;
	}
};

HeroAI* HeroAI::createone(int Type)
{
	HeroAI* nowhero = HeroAI::create();
	switch (Type)
	{
	case 1:
	{
		nowhero->count = 0;
		nowhero->num = 2;
		nowhero->range = 550;
		nowhero->nowhp = 100;
		nowhero->isInTower = 0;
		nowhero->isDead = 0;
		nowhero->HeroAttackDistance = 300;
		Sprite* nowHeroPicture = Sprite::create("wsparticle_test_001.png");
		nowHeroPicture->setTag(665);
		nowhero->addChild(nowHeroPicture);
		nowhero->speed = 150;
		nowhero->damage = 1;
		nowhero->ht = 1;
		nowhero->level = 1;
		nowhero->experience = 0;
		nowhero->money = 500;
		nowhero->color = 1;
		nowhero->type = 3;
		nowhero->frozed = 0;
		nowhero->frozedJustNow = 0;
		nowhero->skill_1_level = 0;
		nowhero->skill_2_level = 0;
		nowhero->skill_3_level = 0;
		break;
	}
	case 2:
	{
	
		nowhero->count = 0;
		nowhero->num = 2;
		nowhero->range = 550;
		nowhero->nowhp = 100;
		nowhero->isInTower = 0;
		nowhero->isDead = 0;
		nowhero->HeroAttackDistance = 300;
		Sprite* nowHeroPicture = Sprite::create("wsparticle_test_001.png");
		nowHeroPicture->setTag(665);
		nowhero->addChild(nowHeroPicture);
		nowhero->speed = 150;
		nowhero->damage = 1;
		nowhero->ht = 2;
		nowhero->level = 1;
		nowhero->experience = 0;
		nowhero->money = 500;
		nowhero->color = 1;
		nowhero->type = 3;
		nowhero->frozed = 0;
		nowhero->frozedJustNow = 0;
		nowhero->skill_4_level = 0;
		nowhero->skill_5_level = 0;
		nowhero->skill_6_level = 0;
		break;
	
	}
	case 3:
	{
		nowhero->count = 0;
		nowhero->num = 2;
		nowhero->range = 550;
		nowhero->nowhp = 500;
		nowhero->isInTower = 0;
		nowhero->isDead = 0;
		nowhero->HeroAttackDistance = 300;
		Sprite* nowHeroPicture = Sprite::create("wsparticle_test_001.png");
		nowHeroPicture->setTag(665);
		nowhero->addChild(nowHeroPicture);
		nowhero->speed = 250;
		nowhero->damage = 1;
		nowhero->ht = 3;
		nowhero->level = 1;
		nowhero->experience = 0;
		nowhero->money = 500;
		nowhero->color = 1;
		nowhero->type = 3;
		nowhero->frozed = 0;
		nowhero->frozedJustNow = 0;
		nowhero->skill_7_level = 0;
		nowhero->skill_8_level = 0;
		nowhero->skill_9_level = 0;
		break;
	}
	}
	heros[nowhero->color].list.pushBack(nowhero);
	nowhero->leftTime[0] = 0;
	nowhero->leftTime[1] = 0;
	nowhero->leftTime[2] = 0;
	nowhero->searchRange = 550;
	nowhero->born();
	return nowhero;
}


void HeroAI::FindPath()
{
	int ti = 80 - this->target->getPositionY() / 60;
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
			if (inclose[now_num] != 1 && Visit[newi][newj] == 1)
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
						openvalue[now_num].G = G + dG, openvalue[now_num].F = openvalue[now_num].G + openvalue[now_num].H, father[now_num] = n;
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
	reverse(this->path.begin(), this->path.end());
}


Enemy* HeroAI::FindNewTarget()
{
	float dis;
	float mx = this->getPositionX();
	float my = this->getPositionY();
	float tx = myHero->getPositionX();
	float ty = myHero->getPositionY();
	dis = sqrt((mx - tx)*(mx - tx) + (my - ty)*(my - ty));
	if (dis < this->searchRange)
	{
		return myHero;
		
	}
	for (int i = 0; i < soldiers[0].list.size(); i++)
	{
		if (soldiers[0].list.at(i)->isDead == 0)
		{
			float tx = myHero->getPositionX();
			float ty = myHero->getPositionY();
			float d = sqrt((mx - tx)*(mx - tx) + (my - ty)*(my - ty));
			if (d < this->range)
			{
				return soldiers[0].list.at(i);
			}
		}
	}
	return NULL;
}
void HeroAI::skill_01()
{
	Armor *skillArmor = Armor::createone(this->getPositionX(), this->getPositionY(), 2);
	skillArmor->removeChildByTag(166);
	skillArmor->setPosition(Vec2(this->getPositionX() - 100, this->getPositionY() - 100));
	auto skillFirePicture = Sprite::create("wsparticle_super01.png");
	
	MAP->addChild(skillArmor);
	skillArmor->father = this;
	skillArmor->color = 1;
	skillArmor->damage = 60;
	skillArmor->speed = 300;
	skillArmor->addChild(skillFirePicture);
	double tagetAngle = std::atan2(this->target->getPositionY() - this->getPositionY(), this->target->getPositionX() - this->getPositionX()) * (180.0 / 3.14);
	double skillRotation = -(tagetAngle - 90.0);
	skillFirePicture->setAnchorPoint(Vec2(0.5, 0));
	skillFirePicture->setTag(21574);
	skillArmor->setRotation(skillRotation);
	armors.pushBack(skillArmor);
	float tagx = this->target->getPositionX();
	float tagy = this->target->getPositionY();
	float mx = this->getPositionX();
	float my = this->getPositionY();
	float Range = 500;
	float dis = sqrt((tagx - mx)*(tagx - mx) + (tagy - my)*(tagy - my));
	float finalX = mx + Range * (tagx - mx) / dis;
	float finalY = my + Range * (tagy - my) / dis;
	auto act1 = MoveTo::create(Range / skillArmor->speed, Vec2(finalX, finalY));
	auto act2 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, skillArmor));
	auto seque = Sequence::create(act1, act2, NULL);
//	skillArmor->runAction(Sequence::create(act1, act2, NULL));
}

void HeroAI::skill_02()
{
	float moveDis = 350;
	double time =moveDis / 1500;
	float mx = this->getPositionX();
	float my = this->getPositionY();
	float tx = mx + moveDis * 0.7;
	float ty = my + moveDis * 0.7;
	auto heroSkillMove = MoveTo::create(time, Vec2(tx,  ty));
	this->runAction(heroSkillMove);
}

void HeroAI::skill_03()
{
	float tagx = this->target->getPositionX();
	float tagy = this->target->getPositionY();
	float mx = this->getPositionX();
	float my = this->getPositionY();
	Armor* boundArmor = Armor::createone(mx, my, 3);
	boundArmor->speed = 100;
	boundArmor->removeChildByTag(166);
	Sprite* FirePic = Sprite::create("wsparticle_27.png");
	FirePic->setTag(21574);
	boundArmor->addChild(FirePic);
	boundArmor->father = this;
	boundArmor->color = 1;
	boundArmor->damage = 90;
	double tagetAngle = std::atan2(tagy - my, tagx - mx) * (180.0 / 3.14);
	double skillRotation = -(tagetAngle - 90.0);
	boundArmor->setRotation(skillRotation);
	armors.pushBack(boundArmor);
	FirePic->setAnchorPoint(Vec2(0.5, 0));
	float Range = 500;
	float dis = sqrt((tagx - mx)*(tagx - mx) + (tagy - my)*(tagy - my));
	float finalX = mx + Range * (tagx - mx) / dis;
	float finalY = my + Range * (tagy - my) / dis;
	auto act1 = MoveTo::create(Range / boundArmor->speed, Vec2(finalX, finalY));
	auto act2 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, boundArmor));
	auto seque = Sequence::create(act1, act2, NULL);
	boundArmor->runAction(seque);
//	boundArmor->runAction(act1);
}

void HeroAI::skill_04()
{
	float tagx =this->target->getPositionX();
	float tagy = this->target->getPositionY();
	float mx = this->getPositionX();
	float my = this->getPositionY();
	Armor* boundArmor = Armor::createone(mx, my, 3);
	boundArmor->speed = 500;
	boundArmor->removeChildByTag(166);
	Sprite* FirePic = Sprite::create("wsparticle_27.png");
	FirePic->setTag(21574);
	boundArmor->addChild(FirePic);
	boundArmor->father = this;
	boundArmor->color = 1;
	boundArmor->damage = 90;
	double tagetAngle = std::atan2(tagy - my, tagx- mx) * (180.0 / 3.14);
	double skillRotation = -(tagetAngle - 90.0);
	boundArmor->setRotation(skillRotation);
	armors.pushBack(boundArmor);
	FirePic->setAnchorPoint(Vec2(0.5, 0));
	float range = 500;
	float dis = sqrt((tagx - mx)*(tagx - mx) + (tagy - my)*(tagy - my));
	float finalX = mx + range * (tagx - mx) / dis;
	float finalY = my + range * (tagy - my) / dis;
	auto act1 = MoveTo::create(range / boundArmor->speed, Vec2(finalX, finalY));
	auto act2 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, boundArmor));
	auto seque = Sequence::create(act1, act2, NULL);
	boundArmor->runAction(seque);
}

void HeroAI::skill_05()
{
	float dx[8] = { 0,1.414,1,1.414,0,-1.414,-1,-1.414 };
	float dy[8] = { 1,1.414,0,-1.414,-1,-1.414,0,1.414 };
	Armor* scatters[8];
	int i;
	float mx = this->getPositionX();
	float my =this->getPositionY();
	for (i = 0; i < 8; i++)
	{
		scatters[i] = Armor::createone(mx, my, 1);
		scatters[i]->speed = 250;
		scatters[i]->removeChildByTag(166);
		Sprite* pic = Sprite::create("armor.png");
		scatters[i]->addChild(pic);
		scatters[i]->color = 1;
		scatters[i]->father = myHero;
		scatters[i]->damage = 45;
		armors.pushBack(scatters[i]);
		float range = 170;
		float finalX = mx + range * dx[i];
		float finalY = my + range * dy[i];
		auto act1 = MoveTo::create(range / scatters[i]->speed, Vec2(finalX, finalY));
		auto act2 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, scatters[i]));
		auto seque = Sequence::create(act1, act2, NULL);
		scatters[i]->runAction(seque);
	}
}

void HeroAI::skill_06()
{
    this->speed += 550;
	this->scheduleOnce(schedule_selector(Hero::resetSpeed), 3);
}

void HeroAI::skill_07()
{
	float dx[8] = { 0,1.414,1,1.414,0,-1.414,-1,-1.414 };
	float dy[8] = { 1,1.414,0,-1.414,-1,-1.414,0,1.414 };
	Armor* scatters[8];
	int i;
	float mx = myHero->getPositionX();
	float my = myHero->getPositionY();
	for (i = 0; i < 8; i++)
	{
		scatters[i] = Armor::createone(mx, my, 4);
		scatters[i]->speed = 150;
		scatters[i]->removeChildByTag(166);
		Sprite* pic = Sprite::create("armor.png");
		scatters[i]->addChild(pic);
		scatters[i]->isFrozen = 1;
		scatters[i]->father = myHero;
		scatters[i]->color = 0;
		scatters[i]->damage = 45;
		armors.pushBack(scatters[i]);
		float range = 120;
		float finalX = mx + range * dx[i];
		float finalY = my + range * dy[i];
		auto act1 = MoveTo::create(range / scatters[i]->speed, Vec2(finalX, finalY));
		auto act2 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, scatters[i]));
		auto seque = Sequence::create(act1, act2, NULL);
		scatters[i]->runAction(seque);
		Hero::judgeSkill = 0;
	}
}

void HeroAI::AIConstant(float t)
{
	CCLOG("CONSTANT SHOOT");
	Armor* armor = Armor::createone(this->armorSx, this->armorSy, 1);
	armor->color = 1;
	armor->father = this;
	armor->speed = 690;
	armor->setRotation(this->armorAng);
	armors.pushBack(armor);
	float dis = sqrt((this->armorSx - this->armorTx)*(this->armorSx - this->armorTx) + (this->armorSy - this->armorTy)*(this->armorSy - this->armorTy));
	float finalX = this->armorSx + 400 * (this->armorTx - this->armorSx) / dis;
	float finalY = this->armorSy + 400 * (this->armorTy - this->armorSy) / dis;
	auto act1 = MoveTo::create(dis / armor->speed, Vec2(finalX, finalY));
	auto act2 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, armor));
	auto seque = Sequence::create(act1, act2, NULL);
	armor->runAction(seque);
}

void HeroAI::skill_08()
{
	double tagetAngle = std::atan2(this->target->getPositionY() - this->getPositionY(), this->target->getPositionX() - this->getPositionX()) * (180.0 / 3.14);
	double skillRotation = -(tagetAngle - 90.0);
	this->armorAng = skillRotation;
	this->armorSx = this->getPositionX();
	this->armorSy = this->getPositionY();
	this->armorTx = this->target->getPositionX();
	this->armorTy = this->target->getPositionY();
	this->schedule(schedule_selector(HeroAI::AIConstant), 0.1, 12, 0);
}

void HeroAI::skill_09()
{
  
}

	void HeroAI::Attack(float t)
{
	this->stopAllActions();
	float mx = 4600;
	float my = 4600;
	float tx = this->getPositionX();
	float ty = this->getPositionY();
	if (this->target->type == 3)
	{
		int a = rand() % 10;
		//0.3µÄ¸ÅÂÊÌÓÅÜ
		if (a >= 9)
		{
			float dis = sqrt((tx - mx)*(tx - mx) + (ty - my)*(ty - my));
			this->runAction(MoveTo::create(dis / this->speed, Vec2(4600, 4600)));
			return;
		}
	}
	int a = rand() % 3;
	if (a == 0)
	{
		if (this->leftTime[0] <= 0)
		{
			if (this->ht == 1)
				this->skill_01();
			else if (this->ht == 2)
				this->skill_04();
			else if (this->ht == 3)
				this->skill_07();
			this->leftTime[0] = 3;
		}
	}
	if (a == 1)
	{
		if (this->leftTime[1] <= 0)
		{
			if (this->ht == 1)
				this->skill_02();
			else if (this->ht == 2)
				this->skill_05();
			else if (this->ht == 3)
				this->skill_08();
			this->leftTime[1] = 3;
		}
	}
	if (a == 2)
	{
		if (this->leftTime[2] <= 0)
		{
			if (this->ht == 1)
				this->skill_03();
			else if (this->ht == 2)
				this->skill_06();
			else if (this->ht == 3)
				this->skill_09();
			this->leftTime[2] = 3;
		}
	}
}

void HeroAI::MoveToTarget()
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
	dis1 = sqrt((x - mex)*(x - mex) + (y - mey)*(y - mey));
	if (dis1 < this->range)
	{
		this->schedule(schedule_selector(HeroAI::Attack),1.5,2,0);
		return;
	}
	int ni, nj;
	if (this->path.at(this->count) % 80 == 0)
		ni = this->path.at(this->count) / 80, nj = 80;
	else
		ni = this->path.at(this->count) / 80 + 1, nj = this->path.at(this->count) % 80;
	float dx = nj * 60 - mex;
	float dy = (80 - ni) * 60 - mey;
	float tagAng = std::atan2(dy, dx)*(180.0 / 3.1415926535);
	auto act0 = RotateBy::create(0.2, this->ang - tagAng);
	this->ang = tagAng;
	dis = sqrt(dx*dx + dy * dy);
	auto act1 = MoveTo::create(dis / this->speed, Vec2(nj * 60, (80 - ni) * 60));
	auto act2 = CallFunc::create(CC_CALLBACK_0(HeroAI::MoveToTarget, this));
	auto seque = Sequence::create(act1, act2, NULL);
	//this->runAction(act0);
	this->runAction(seque);
	this->count++;


}

void HeroAI::MoveOrAttack(float t)
{
	this->stopAllActions();
	this->unschedule(schedule_selector(HeroAI::Attack));
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

		if (dis <= this->range&&this->target->isDead == 0)
		{
			this->schedule(schedule_selector(HeroAI::Attack),1.5,2,0);

		}
		else
		{
			this->FindPath();
			if (!this->path.empty())
				this->MoveToTarget();
		}
	}
}

void HeroAI::UPDATE()
{
	if (this->frozed == 0 && this->frozedJustNow == 1)
	{
		this->schedule(schedule_selector(HeroAI::MoveOrAttack), 5);
		this->frozedJustNow = 0;
	}
}