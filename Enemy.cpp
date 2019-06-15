


#include"Enemy.h"
#include"Hero.h"
USING_NS_CC;

extern int total_num;
extern Vector<Sprite*> healthS;
extern Hero *myHero;
struct objs towers[2], heros[2], soldiers[2];
Map<int, hatred1*> hatred;
Map<int, Enemy*> FindByNum;
//std::map<Enemy*,map<Enemy*,float> > hatred;
//Map<int, Enemy*> hatred_findtarget;

void Enemy::die()
{
	if (this->isDead == 1)
		return;
	int ret = 0;
	this->isDead = 1;
	/*if (healthS.find(static_cast<Sprite*>(this->getChildByTag(999))) != healthS.end())
	{
		int pos = healthS.find(static_cast<Sprite*>(this->getChildByTag(999))) - healthS.begin();
		CCLOG("HAVE FIND %d %d",pos,healthS.size());
		if(pos<healthS.size())
		healthS.eraseObject(healthS.at(pos));
	}*/
	this->removeChildByTag(2678);
	this->setVisible(FALSE);
	int pos;
	this->unscheduleAllSelectors();
	struct objs* it;
	if (this->type == 1)
	{
		//GAME OVER

	}
	//是塔
	if (this->type == 2)
	{
		it = towers + this->color;
		pos = towers[this->color].list.find(this) - towers[this->color].list.begin();
	}
	//是英雄
	else if (this->type == 3)
	{
		it = heros + this->color;
		if(this->color==0)
		pos = heros[this->color].list.find(this) -heros[this->color].list.begin();
		this->isDead = 0;
			ret = 1;
	}
	//是小兵
	else if (this->type == 4)
	{
		it = soldiers + this->color;
		pos = soldiers[this->color].list.find(this) - soldiers[this->color].list.begin();
		//从仇恨系统中移除
		int i;
		for (i = hatred.at(this->num)->mylist.size()-1; i>=0;i--)
		{
			delete hatred.at(this->num)->mylist.at(i);
			hatred.at(this->num)->mylist.popBack();
		}
		delete hatred.at(this->num);
		hatred.erase(this->num);
	}
	if (ret==0)
	{
		(*it).list.eraseObject((*it).list.at(pos));
		this->scheduleOnce(schedule_selector(Enemy::delayRemove), 15);
	}
	if (ret == 1)
	{
		CCLOG("HERO DIE %d %d", this->color, this->type);
		myHero->setPosition(Vec2(400, 400));
		myHero->nowHeroPicture = Sprite::create("wsparticle_test_001.png");
		myHero->addChild(myHero->nowHeroPicture);
		myHero->nowHeroPicture->setTag(2678);
		myHero->setVisible(TRUE);
		//我死了，弹出复活选择界面
//		myHero->nowHeroPicture = NULL;
	//	myHero->removeAllChildren();
//		myHero->schedule(schedule_selector(Hero::respawn),3*myHero->level);
	}
}

void Enemy::delayRemove(float t)
{
	this->removeFromParent();
}


void Enemy::born()
{
	this->isDead = 0;
	this->target = NULL;
	for (int i = 0; i < soldiers[1 - this->color].list.size(); i++)
	{
		int n = soldiers[1 - this->color].list.at(i)->num;
		hatred2* h2 = new hatred2;
		h2->enemy = this;
		h2->hatredValue = 10;
		hatred.at(n)->mylist.pushBack(h2);
	}
}

void Enemy::FrozedToNormal(float t)
{
	this->frozed = 0;
	this->frozedJustNow = 1;
}