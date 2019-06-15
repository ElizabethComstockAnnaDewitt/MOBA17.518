#include"Tower.h"


extern Map<int, Enemy*> FindByNum;
extern Vector<Armor*> armors;

void Tower::shoot(float t)
{
	if (this->elist.empty())
		return;
	float x = this->elist.front()->getPositionX();
	float y = this->elist.front()->getPositionY();
	float mex = this->getPositionX();
	float mey = this->getPositionY();
		float dis = sqrt((x - mex)*(x - mex) + (y - mey)*(y - mey));
	float terminalx = mex + (this->range)*(x - mex) / dis;
	float terminaly = mey + (this->range)*(y - mey) / dis;
	Armor *armor = Armor::createone(this->getPositionX(), this->getPositionY(),1);
	armor->father = this;
	armor->color = this->color;
	armor->damage = 100;
	armors.pushBack(armor);
	
	auto act1 = MoveTo::create(this->range/armor->speed,Vec2(terminalx,terminaly));
	auto act2 = CallFunc::create(CC_CALLBACK_0(Armor::suicide, armor));
	auto seque = Sequence::create(act1, act2, NULL);
	armor->runAction(seque);
}

void Tower::Attack()
{
	//放置射线
	//判断是否需要重置子弹定时发射
	if (this->lastTarget != this->elist.front()->num)
	{
		this->unschedule(schedule_selector(Tower::shoot));
		this->schedule(schedule_selector(Tower::shoot), 3);
	}
	this->lastTarget = this->elist.front()->num;
}


void Tower::UPDATE()
{
	if (!this->elist.empty())
	{
		//移除出范围或死亡的目标
		int i = 0, num = 0, total = this->elist.size();
		while (num < total)
		{
			float x = this->elist.at(i)->getPositionX();
			float y = this->elist.at(i)->getPositionY();
			float dis = sqrt((x - this->getPositionX())*(x - this->getPositionX()) + (y - this->getPositionY())*(y - this->getPositionY()));
			if (dis > this->range||this->elist.at(i)->isDead==1)
				this->elist.eraseObject(this->elist.at(i)), i--;
			i++;
			num++;
		}
		//选择列表中第一个敌人进行攻击
		if (!this->elist.empty())
			this->Attack();
		else
		{
			if (this->lastTarget != -1)
				this->unschedule(schedule_selector(Tower::shoot));
			this->lastTarget = -1;
		}
	}
	else
	{
		if (this->lastTarget != -1)
			this->unschedule(schedule_selector(Tower::shoot));
		this->lastTarget = -1;
	}
}
