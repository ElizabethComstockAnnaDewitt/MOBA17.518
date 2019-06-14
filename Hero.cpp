#include "Hero.h"
#include "Bullet.h"
#include "gameScene.h"
#include <cmath>
const double pi = 3.1415926535;
//float gameScene::ex;
//float gameScene::ey;
int Hero::judgeSkill;
int Hero::skillType;
USING_NS_CC;
Vector<Bullet*> gameScene::allbullet;
bool Hero::init()
{
	if (!Node::init())
		return false;
	return true;
}

Hero* Hero::createHero(int type)
{
	Hero* nowhero = Hero::create();
	switch (type)
	{
	case 1:
	{
		nowhero->HeroAttackDistance = 300;
		nowhero->nowHeroPicture = Sprite::create("wsparticle_test_001.png");
		nowhero->addChild(nowhero->nowHeroPicture);
		nowhero->speed = 500;
		nowhero->damage = 1;
		nowhero->ht = 1;
		nowhero->level = 1;
		nowhero->experience = 0;
		nowhero->money = 50000 ;
		nowhero->skill_1_level = 0;
		nowhero->skill_2_level = 0;
		nowhero->skill_3_level = 0;
		break;
	}
	case 2:
	{
		nowhero->nowHeroPicture = Sprite::create("bang.png");
		nowhero->addChild(nowhero->nowHeroPicture);
		nowhero->speed = 500;
		nowhero->ht = 2;
		break;
	}
	}

	return nowhero;
}


void Hero::fire(float t)
{
	if (target != NULL)
	{
		float dx = target->getPositionX();
		float dy = target->getPositionY();
		Bullet* b = Bullet::createBullet(1, angle, getPositionX(), getPositionY(), dx, dy);
		gameScene::allbullet.pushBack(b);
		this->getParent()->addChild(b);
	}
}

void Hero::shot()
{
	this->schedule(schedule_selector(Hero::fire), 0.5);
	this->isFire = 1;
}

//void Hero::skillsSlector()
//{
//
//	auto bt01 = Sprite::create("wsparticle_money01.png");
//	auto bt01_select = Sprite::create("wsparticle_money01.png");
//	bt01_select->setScale(1.1);
//	auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::selectSkill, this));
//	mitem01->setTag(829);
//	auto menuSkill = Menu::create(mitem01, nullptr);
//	menuSkill->setPosition(Vec2(300, 50));
//
//
//	this->getParent()->addChild(menuSkill);
//	menuSkill->setTag(1873);
//
//
//}
void Hero::selectSkill_01(Ref* obj)
{
	if (skill_1_level)
	{
		if (this->getChildByTag(2678))
		{
			this->getChildByTag(2678)->removeFromParent();
			judgeSkill = 0;
		}
		else
		{
			judgeSkill = 1;
			auto skillTrack = Sprite::create("PicsArt_06-08-12.33.39.png");
			skillTrack->setOpacity(100);
			skillTrack->setAnchorPoint(Vec2(0.5, 0));
			skillTrack->setTag(2678);
			this->addChild(skillTrack);
		}
	}
	else
	{
		auto labLevel = Label::create("you have not learnt this skill", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("you have not learnt this skill");
	}
}



void Hero::selectSkill_02(Ref* obj)
{
	if (skill_2_level)
	{
		if (this->getChildByTag(2678))
		{
			this->getChildByTag(2678)->removeFromParent();
			judgeSkill = 0;
		}
		else
		{
			judgeSkill = 2;
			auto skillTrack = Sprite::create("wsparticle_27.png");
			skillTrack->setOpacity(100);
			skillTrack->setAnchorPoint(Vec2(0.5, 0));
			skillTrack->setTag(2678);
			this->addChild(skillTrack);
		}
	}
	else
	{
		auto labLevel = Label::create("you have not learnt this skill", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("you have not learnt this skill");
	}
}

void Hero::selectSkill_03(Ref* obj)
{
	if (skill_3_level)
	{
		if (this->getParent()->getChildByTag(2678))
		{
			this->getParent()->getChildByTag(2678)->removeFromParent();
			this->getChildByTag(267856)->removeFromParent();
			judgeSkill = 0;
		}
		else
		{
			judgeSkill = 3;
			auto skillTrack_001 = Sprite::create("PicsArt_06-06-06.43.56.png");
			skillTrack_001->setOpacity(100);
			skillTrack_001->setTag(2678);
			this->getParent()->addChild(skillTrack_001);

			auto skillTrack_002 = Sprite::create("PicsArt_06-08-12.19.27.png");
			skillTrack_002->setOpacity(100);
			skillTrack_002->setTag(267856);
			this->addChild(skillTrack_002);

		}
	}
	else
	{
		auto labLevel = Label::create("you have not learnt this skill", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("you have not learnt this skill");
	}
}


//void Hero::skillFire(int t,double ang)
//{
//	switch (t)
//	{
//	case 1:
//		auto skillFirePicture=Sprite::create("wsparticle_super01.png");
//		skillFirePicture->setAnchorPoint(Vec2(0.5, 0));
//		skillFirePicture->setTag(21574);
//		this->getParent()->addChild(skillFirePicture);
//		skillFirePicture->setPosition(this->getPosition());
//		skillFirePicture->setRotation(-(ang - 90.0 - angle + 90.0));
//		auto move = MoveTo::create(0.5,Vec2(gameScene::ex, gameScene::ey));
//		auto act2 = CallFunc::create(CC_CALLBACK_0(Bullet::killMe, skillFirePicture));
//		newb->runAction(Sequence::create(move, act2, NULL));
//		break;
//
//	}
//}
//
//auto act2 = CallFunc::create(CC_CALLBACK_0(Bullet::killMe, newb));
//newb->runAction(Sequence::create(act1, act2, NULL));
//
//
//void Bullet::killMe()
//{
//	this->removeFromParent();
//}



void Hero::moneyIncreaseBytime(float t)
{
	money++;
}


void Hero::experienceIncreaseBytime(float t)
{
	experience++;
}



//void Hero::experienceIncreaseBytime(float t)
//{
//	experience++;
//	if (experience == 50)
//	{
//		level = 2;
//		gameScene::skillUpgrade();
//	}
//	else if (experience == 105)
//	{
//		level = 3;
//		upgradeTag = 2;
//	}
//	else if (experience == 165)
//	{
//		level = 4;
//		upgradeTag = 3;
//	}
//	else if (experience == 230)
//	{
//		level = 5;
//		upgradeTag = 4;
//	}
//	else if (experience == 300)
//	{
//		level = 6;
//		upgradeTag = 5;
//	}
//	else if (experience == 375)
//	{
//		level = 7;
//		upgradeTag = 6;
//	}
//	else if (experience == 455)
//	{
//		level = 8;
//		upgradeTag = 7;
//	}
//	else if (experience == 530)
//	{
//		level = 9;
//		upgradeTag = 8;
//	}
//	else if (experience == 610)
//	{
//		level = 10;
//		upgradeTag = 9;
//	}
//	else if (experience == 695)
//	{
//		level = 11;
//		upgradeTag = 10;
//	}
//	else if (experience == 785)
//	{
//		level = 12;
//		upgradeTag = 11;
//	}
//	else if (experience == 880)
//	{
//		level = 13;
//		upgradeTag = 12;
//	}
//	else if (experience == 980)
//	{
//		level = 14;
//		upgradeTag = 13;
//	}
//	else if (experience == 1085)
//	{
//		level = 15;
//		upgradeTag = 14;
//	}
//	else if (experience == 1195)
//	{
//		level = 16;
//		upgradeTag = 15;
//	}
//	else if (experience == 1310)
//	{
//		level = 17;
//		upgradeTag = 16;
//	}
//	else if (experience == 1430)
//	{
//		level = 18;
//		upgradeTag = 17;
//	}
//}



//void Hero::skillUpgrade()
//{
//	Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
//	if (nowHero->ht == 1)
//	{
//		if (this->getChildByTag(546) == nullptr)
//		{
//			auto bt01 = Sprite::create("com.tencent.plus.ic_success.png");
//			auto bt01_select = Sprite::create("com.tencent.plus.ic_success.png");
//			bt01_select->setScaleX(1.1);
//			auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::selectSkill_01, nowHero));
//			mitem01->setTag(829);
//			auto menuSkill01 = Menu::create(mitem01, nullptr);
//			menuSkill01->setTag(546);
//			menuSkill01->setPosition(Vec2(300, 50));
//			this->addChild(menuSkill01);
//
//
//
//			auto bt02 = Sprite::create("84651.jpg");
//			auto bt02_select = Sprite::create("84651.jpg");
//			bt02_select->setScaleX(1.1);
//			auto mitem02 = MenuItemSprite::create(bt02, bt02_select, CC_CALLBACK_1(Hero::selectSkill_02, nowHero));
//			mitem02->setTag(4345);
//			auto menuSkill02 = Menu::create(mitem02, nullptr);
//			menuSkill02->setTag(452);
//			menuSkill02->setPosition(Vec2(400, 50));
//			this->addChild(menuSkill02);
//
//
//			auto bt03 = Sprite::create("234567.jpg");
//			auto bt03_select = Sprite::create("234567.jpg");
//			bt03_select->setScaleX(1.1);
//			auto mitem03 = MenuItemSprite::create(bt03, bt03_select, CC_CALLBACK_1(Hero::selectSkill_03, nowHero));
//			mitem03->setTag(300);
//			auto menuSkill03 = Menu::create(mitem03, nullptr);
//			menuSkill03->setTag(301);
//			menuSkill03->setPosition(Vec2(500, 50));
//			this->addChild(menuSkill03);
//		}
//	} 
//}



void Hero::skill_1_Upgrade(Ref* obj)
{
	if (skill_1_level < 6)
	{
		skill_1_level++;
		this->getParent()->getParent()->getChildByTag(11)->removeFromParent();
		this->getParent()->getParent()->getChildByTag(22)->removeFromParent();
		this->getParent()->getParent()->getChildByTag(33)->removeFromParent();
	}
	else
	{
		auto labLevel = Label::create("This skill is at full level", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("skillmax");
	}
}
void Hero::skill_2_Upgrade(Ref* obj)
{
	if (skill_2_level < 6)
	{
		skill_2_level++;
		this->getParent()->getParent()->getChildByTag(11)->removeFromParent();
		this->getParent()->getParent()->getChildByTag(22)->removeFromParent();
		this->getParent()->getParent()->getChildByTag(33)->removeFromParent();
	}
	else
	{
		auto labLevel = Label::create("This skill is at full level", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("skillmax");
	}
}
void Hero::skill_3_Upgrade(Ref* obj)
{
	if (skill_3_level < 6)
	{
		skill_3_level++;
		this->getParent()->getParent()->getChildByTag(11)->removeFromParent();
		this->getParent()->getParent()->getChildByTag(22)->removeFromParent();
		this->getParent()->getParent()->getChildByTag(33)->removeFromParent();
	}
	else
	{
		auto labLevel = Label::create("This skill is at full level", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("skillmax");
	}
}
