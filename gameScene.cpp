
#include"gameScene.h"
#include "Hero.h"
#include "Hero01.h"
#include "Hero02.h"
#include <cmath>
#include "Bullet.h"
#include "Skill.h"
#include "Shop.h"
USING_NS_CC;

const double pi = 3.1415926535;
bool judgeRange = 0;// 判断是否选中敌人
//Vector<Node*> heros, enemys;
//Hero *hero, *enemy;
//Sprite* p;
float gameScene::ex;
float gameScene::ey;
int gameScene::equipmentAmount;
int a = 1;
int b = 1;
bool gameScene::init()
{
	Scene::initWithPhysics();
	lastLevel = 0;
	upgradeTag = 0;
	equipmentAmount = 0;
	Intermediate_variable = 0;
	//背景wsparticle_19
	auto background = Sprite::create("timg (1).jpg");
	//auto background = Sprite::create("wsparticle_19.png");
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, -1);
	background->setTag(9845);

	tx = ty = 0;
	ex = ey = 500;
	if (!Scene::init())
	{
		return false;
	}
	//auto pic = Sprite::create("timg.jpg");
	//pic->setPosition(Vec2(0, 0));
	//pic->setAnchorPoint(Vec2(0, 0));
	//p = pic;
	//this->addChild(pic);
	// 事件处理
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = CC_CALLBACK_1(gameScene::onMouseDown, this);
	listener->onMouseMove = CC_CALLBACK_1(gameScene::onMouseMove, this);
	listener->onMouseUp = CC_CALLBACK_1(gameScene::onMouseUp, this);
	listener->onMouseScroll = CC_CALLBACK_1(gameScene::onMouseScroll, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);


	auto keyboardListener = EventListenerKeyboard::create();
	keyboardListener->onKeyPressed = CC_CALLBACK_2(gameScene::onKeyPressed, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this);





	Hero* nowHero = Hero::createHero(1);
	angle = 90.0;//角度
	nowHero->angle = 90.0;
	this->getChildByTag(9845)->addChild(nowHero);
	nowHero->setTag(478);
	nowHero->setAnchorPoint(Vec2(0.5, 0.5));
	nowHero->setPosition(Vec2(100, 100));
	nowHero->isFire = 0;



	Hero* nowHeroEnemy = Hero::createHero(2);
	this->getChildByTag(9845)->addChild(nowHeroEnemy);
	nowHeroEnemy->setTag(48512);
	nowHeroEnemy->setAnchorPoint(Vec2(0.5, 0.5));
	nowHeroEnemy->setPosition(Vec2(200, 200));
	nowHeroEnemy->maxhp = nowHeroEnemy->nowhp = 10;


	//nowHero->skillsSlector();

	//金钱显示
	auto labMoney = Label::create("Money:500", "Marker Felt", 20);
	labMoney->setPosition(Point(70, 300));
	this->addChild(labMoney);
	labMoney->setTag(120);


	// 金钱随时间增加
	nowHero->schedule(schedule_selector(Hero::moneyIncreaseBytime), 1);



	//等级显示
	auto labLevel = Label::create("Level:1", "Marker Felt", 20);
	labLevel->setPosition(Point(50, 150));
	this->addChild(labLevel);
	labLevel->setTag(121);


	//经验随时间增加
	nowHero->schedule(schedule_selector(Hero::experienceIncreaseBytime), 1);

	this->scheduleUpdate();

	return true;
}

Scene* gameScene::createscene()
{
	auto scene = Scene::createWithPhysics();
	PhysicsWorld* world = scene->getPhysicsWorld();
	world->setGravity(Vec2(0, 0));
	world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	auto layer = gameScene::create();
	scene->addChild(layer);
	return scene;
}
bool gameScene::onMouseDown(Event* event)
{
	if (a == b)
	{
		judgeRange = 0;
		Hero* nowHeroEnemy = (Hero*)this->getChildByTag(9845)->getChildByTag(48512);


		this->unschedule(schedule_selector(Hero::fire));
		//Director::getInstance()->getActionManager()->pauseAllRunningActions();
		EventMouse* e = (EventMouse*)event;
		Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
		float nx = nowHero->getPositionX();
		float ny = nowHero->getPositionY();
		HeroSkillx = nx;
		HeroSkilly = ny;
		nowHero->stopActionByTag(9649);
		nowHero->setAnchorPoint(Vec2(0.5, 0.5));
		float eex = e->getCursorX();
		float eey = e->getCursorY();
		//Sprite* nowHeroPicture = (Sprite*)this->getChildByTag(783);

		Rect mr(eex - tx - 1, eey - ty - 1, 2, 2);


		if ((int)(e->getMouseButton()) == 0)
		{
			if (Hero::judgeSkill == 1)
			{
				double tagetAngle = std::atan2(ey - ty - nowHero->getPositionY(), ex - tx - nowHero->getPositionX()) * (180.0 / pi);
				double skillRotation = -(tagetAngle - 90.0);
				auto nowSkill = Skill::createSkill(skillRotation, nowHero->getPositionX(), nowHero->getPositionY(), eex - tx, eey - ty);
				nowSkill->setTag(12415);
				this->getChildByTag(9845)->addChild(nowSkill);
				this->getChildByTag(9845)->getChildByTag(478)->getChildByTag(2678)->removeFromParent();
				Hero::judgeSkill = 0;

			}

			if (Hero::judgeSkill == 2)
			{
				tnx = nx;
				tny = ny;
				double tagetAngle = std::atan2(eey - ty - ny, eex - tx - nx) * (180.0 / pi);
				double tangle = angle - tagetAngle;
				if (angle != tagetAngle)
				{
					auto heroRotate = RotateBy::create(0.01, tangle);
					angle = tagetAngle;
					nowHero->angle = angle;
					nowHero->runAction(heroRotate);
				}
				//double tagetAngle = std::atan2(eey - ty - ny, eex - tx - nx) * (180.0 / pi);
				//double tangle = angle - tagetAngle;
				////nowHero->setRotation(tagetAngle);
				//angle = tagetAngle;
				//nowHero->angle = angle;
				//移动过去
				double howfar = Vec2(nx, ny).getDistance(Vec2(eex - tx, eey - ty));
				double time = howfar / 1500;
				auto heroSkillMove = MoveTo::create(time, Vec2(eex - tx, eey - ty));
				nowHero->runAction(heroSkillMove);
				heroSkillMove->setTag(1111);
				this->getChildByTag(9845)->getChildByTag(478)->getChildByTag(2678)->removeFromParent();
				Hero::judgeSkill = 0;
			}

			if (Hero::judgeSkill == 3)
			{
				skill3x = ex;
				skill3y = ey;
				double tagetAngle = std::atan2(eey - ty - ny, eex - tx - nx) * (180.0 / pi);
				double tangle = angle - tagetAngle;
				if (angle != tagetAngle)
				{
					auto heroRotate = RotateBy::create(0.15, tangle);
					angle = tagetAngle;
					nowHero->angle = angle;
					nowHero->runAction(heroRotate);
				}
				double howfar = Vec2(nx, ny).getDistance(Vec2(eex - tx, eey - ty));
				double time = howfar / nowHero->speed;
				auto heroMove = MoveTo::create(time, Vec2(eex - tx, eey - ty));
				nowHero->runAction(heroMove);
				heroMove->setTag(9649);
				this->getChildByTag(9845)->getChildByTag(2678)->removeFromParent();
				this->getChildByTag(9845)->getChildByTag(478)->getChildByTag(267856)->removeFromParent();
				Hero::judgeSkill = 0;
				Intermediate_variable = 1;
			}

		}


		if ((int)(e->getMouseButton()) == 1)
		{
			Intermediate_variable = 0;
			if (nowHeroEnemy)
			{
				auto nowHeroEnemyX = nowHeroEnemy->nowHeroPicture->getBoundingBox().size.width;
				auto nowHeroEnemyY = nowHeroEnemy->nowHeroPicture->getBoundingBox().size.height;
				Rect ehr
				(
					nowHeroEnemy->getPositionX() - nowHeroEnemyX / 2 + 10,
					nowHeroEnemy->getPositionY() - nowHeroEnemyY / 2 + 10,
					nowHeroEnemyX - 10,
					nowHeroEnemyY - 10
				);

				/*Rect ehr
				(
					nowHeroEnemy->getPositionX() ,
					nowHeroEnemy->getPositionY() ,
					nowHeroEnemy->getPositionX() ,
					nowHeroEnemy->getPositionY()
				);*/

				if (mr.intersectsRect(ehr))
				{
					//攻击敌人
					nowHero->target = nowHeroEnemy;
					double tagetAngle = std::atan2(eey - ty - ny, eex - tx - nx) * (180.0 / pi);
					double tangle = angle - tagetAngle;
					if (angle != tagetAngle)
					{
						auto heroRotate = RotateBy::create(0.15, tangle);
						angle = tagetAngle;
						nowHero->angle = angle;
						nowHero->runAction(heroRotate);
					}
					double howfar = Vec2(nx, ny).getDistance(Vec2(eex - tx, eey - ty));
					double time = howfar / nowHero->speed;
					auto heroMove = MoveTo::create(time, Vec2(eex - tx, eey - ty));
					nowHero->runAction(heroMove);
					heroMove->setTag(9649);
					judgeRange = 1;


				}
				else
				{
					nowHero->isFire = 0;
					nowHero->unschedule(schedule_selector(Hero::fire));
					double tagetAngle = std::atan2(eey - ty - ny, eex - tx - nx) * (180.0 / pi);
					double tangle = angle - tagetAngle;
					if (angle != tagetAngle)
					{
						auto heroRotate = RotateBy::create(0.1, tangle);
						angle = tagetAngle;
						nowHero->angle = angle;
						nowHero->runAction(heroRotate);
					}
					//	CCLOG("ooooo%f,%f", ex, ey);
					click(eex - tx, eey - ty);
					//移动过去
					double howfar = Vec2(nx, ny).getDistance(Vec2(eex - tx, eey - ty));
					double time = howfar / nowHero->speed;
					auto heroMove = MoveTo::create(time, Vec2(eex - tx, eey - ty));
					nowHero->runAction(heroMove);
					heroMove->setTag(9649);

				}
			}
			else
			{
				nowHero->isFire = 0;
				nowHero->unschedule(schedule_selector(Hero::fire));
				double tagetAngle = std::atan2(eey - ty - ny, eex - tx - nx) * (180.0 / pi);
				double tangle = angle - tagetAngle;
				if (angle != tagetAngle)
				{
					auto heroRotate = RotateBy::create(0.15, tangle);
					angle = tagetAngle;
					nowHero->angle = angle;
					nowHero->runAction(heroRotate);
				}

				click(eex - tx, eey - ty);
				//移动过去
				double howfar = Vec2(nx, ny).getDistance(Vec2(eex - tx, eey - ty));
				double time = howfar / nowHero->speed;
				auto heroMove = MoveTo::create(time, Vec2(eex - tx, eey - ty));
				nowHero->runAction(heroMove);
				heroMove->setTag(9649);

			}
		}
	}
	b = !b;
	return true;
}

void gameScene::onMouseMove(Event* event)
{
	EventMouse* e = (EventMouse*)event;
	ex = e->getCursorX();
	ey = e->getCursorY();
	//CCLOG("%f,%f", ex, ey);
	if (Hero::judgeSkill == 1 || Hero::judgeSkill == 2)
	{
		Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
		auto skillPicture = nowHero->getChildByTag(2678);
		double tagetAngle = std::atan2(ey - ty - nowHero->getPositionY(), ex - tx - nowHero->getPositionX()) * (180.0 / pi);
		skillPicture->setRotation(-(tagetAngle - 90.0 - angle + 90.0));
	}
	if (Hero::judgeSkill == 3)
	{
		Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
		auto skillPicture = this->getChildByTag(9845)->getChildByTag(2678);
		skillPicture->setPosition(Vec2(ex - tx, ey - ty));
	}
}

void gameScene::onMouseUp(Event* event)
{

}
void gameScene::onMouseScroll(Event* event)
{

}

void gameScene::click(int x, int y)
{
	CCFadeOut* delay = CCFadeOut::create(0.3);
	auto sprite = Sprite::create("srdiugho.jpg");
	sprite->setPosition(Point(x, y));
	//sprite->runAction(delay);
	this->getChildByTag(9845)->addChild(sprite);
	Action* act = Sequence::create(delay,
		CCCallFuncN::create(sprite, callfuncN_selector(gameScene::killme)), NULL);
	sprite->runAction(act);
	//sprite->removeFromParentAndCleanup(true);
}
void gameScene::killme(Node* pSender)//删除自己
{
	pSender->removeFromParentAndCleanup(true);
}

void gameScene::update(float t)
{
	Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
	Hero* nowHeroEnemy = (Hero*)this->getChildByTag(9845)->getChildByTag(48512);
	if (nowHeroEnemy)
	{
		float nx = nowHero->getPositionX();
		float ny = nowHero->getPositionY();
		float nex = nowHeroEnemy->getPositionX();
		float ney = nowHeroEnemy->getPositionY();
		auto nowHeroEnemyX = nowHeroEnemy->nowHeroPicture->getContentSize().width;
		auto nowHeroEnemyY = nowHeroEnemy->nowHeroPicture->getContentSize().height;
		Rect ehr
		(
			nowHeroEnemy->getPositionX() - nowHeroEnemyX / 2 + 10,
			nowHeroEnemy->getPositionY() - nowHeroEnemyY / 2 + 10,
			nowHeroEnemyX - 10,
			nowHeroEnemyY - 10
		);

		//auto testlocation1 = Sprite::create("button_red.9.png");
		//auto testlocation2 = Sprite::create("button_red.9.png");
		//auto testlocation3 = Sprite::create("button_red.9.png");
		//auto testlocation4 = Sprite::create("button_red.9.png");
		//testlocation1->setPosition(Vec2(nowHeroEnemy->getPositionX() - nowHeroEnemyX / 2, nowHeroEnemy->getPositionY() - nowHeroEnemyY / 2));
		//testlocation2->setPosition(Vec2(nowHeroEnemy->getPositionX() + nowHeroEnemyX / 2, nowHeroEnemy->getPositionY() + nowHeroEnemyY / 2));
		//this->addChild(testlocation1);
		//this->addChild(testlocation2);

		if (nowHeroEnemy->nowhp <= 0)
		{
			CCLOG("IIIIIIIIIIIIIIIIIIII");
			nowHeroEnemy->removeFromParent();
			nowHero->target = NULL;
			nowHero->money = nowHero->money + 300;
			return;
		}





		if (judgeRange)
		{
			if (Vec2(nx, ny).getDistance(Vec2(nex, ney)) < nowHero->HeroAttackDistance)
			{
				nowHero->stopActionByTag(9649);
				if (nowHero->isFire == 0)
				{
					//	CCLOG("gameScene%lf", angle);
					nowHero->shot();

				}
			}
			else
			{
				nowHero->isFire = 0;
				nowHero->unschedule(schedule_selector(Hero::fire));
			}
		}
	}
	float nx = nowHero->getPositionX();
	float ny = nowHero->getPositionY();
	//技能3
	if (Intermediate_variable == 1)
	{
		if (Vec2(nx, ny).getDistance(Vec2(skill3x - tx, skill3y - ty)) < 250)
		{
			nowHero->stopActionByTag(9649);
			auto skill3 = Sprite::create("PicsArt_06-06-06.43.56.png");
			skill3->setPosition(Vec2(skill3x - tx, skill3y - ty));
			this->getChildByTag(9845)->addChild(skill3);

			CCFadeOut* delay = CCFadeOut::create(0.5);
			Action* act = Sequence::create(delay,
				CCCallFuncN::create(skill3, callfuncN_selector(gameScene::killme)), NULL);
			skill3->runAction(act);
			Intermediate_variable = 0;
		}
	}


	if (ex > 1010)//1910
	{
		this->getChildByTag(9845)->setPositionX(this->getChildByTag(9845)->getPositionX() - 20);
		tx = tx - 20;
	}
	if (ey > 750)//1070
	{
		this->getChildByTag(9845)->setPositionY(this->getChildByTag(9845)->getPositionY() - 20);
		ty = ty - 20;
	}
	if (ex < 20)
	{
		this->getChildByTag(9845)->setPositionX(this->getChildByTag(9845)->getPositionX() + 20);
		tx = tx + 20;
	}
	if (ey < 20)
	{
		this->getChildByTag(9845)->setPositionY(this->getChildByTag(9845)->getPositionY() + 20);
		ty = ty + 20;
	}
	//技能栏
	skillsSlector();
	//子弹碰撞检测
	if (nowHeroEnemy)
	{
		float nex = nowHeroEnemy->getPositionX();
		float ney = nowHeroEnemy->getPositionY();
		for (int i = 0; i < allbullet.size(); i++)
		{
			Bullet* b = allbullet.at(i);
			float bh = b->getContentSize().height;
			float bw = b->getContentSize().width;

			Rect br
			(
				b->getPositionX() - bh / 2, b->getPositionY() - bw / 2, bh, bw
			);
			if (Vec2(b->getPositionX(), b->getPositionY()).getDistance(Vec2(nex, ney)) < 50)
			{
				CCLOG("%d", nowHeroEnemy->nowhp);
				b->removeFromParent();
				allbullet.eraseObject(b);
				nowHeroEnemy->nowhp--;
				i--;
			}
		}
	}
	auto nowSkill = this->getChildByTag(9845)->getChildByTag(12415);
	if (nowSkill)
	{
		if (nowHeroEnemy)
		{
			float nex = nowHeroEnemy->getPositionX();
			float ney = nowHeroEnemy->getPositionY();
			if (Vec2(nowSkill->getPositionX(), nowSkill->getPositionY()).getDistance(Vec2(nex, ney)) < 80)
			{
				nowHeroEnemy->nowhp = nowHeroEnemy->nowhp - 3;
				nowSkill->removeFromParent();
				nowSkill = nullptr;
			}
		}
		if (nowSkill != nullptr)
		{
			if (Vec2(nowSkill->getPositionX(), nowSkill->getPositionY()).getDistance(Vec2(HeroSkillx, HeroSkilly)) > 480)
			{
				nowSkill->removeFromParent();
			}
		}

	}
	//金钱显示
	Label* labMoney = (Label*)this->getChildByTag(120);
	labMoney->setPosition(Point(70, 300));
	labMoney->setTag(120);
	labMoney->setString(String::createWithFormat("Money:%d", nowHero->money)->_string);
	//位移技能
	if (Vec2(nowHero->getPositionX(), nowHero->getPositionY()).getDistance(Vec2(tnx, tny)) > 300)
	{
		nowHero->stopActionByTag(1111);
	}


	//装备栏
	inventory();


	//等级
	if (nowHero->experience < 50)
	{
		nowHero->level = 1;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 1;
	}
	else if (nowHero->experience < 105)
	{
		nowHero->level = 2;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 2;
	}
	else if (nowHero->experience < 165)
	{
		nowHero->level = 3;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 3;
	}
	else if (nowHero->experience < 230)
	{
		nowHero->level = 4;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 4;
	}
	else if (nowHero->experience < 300)
	{
		nowHero->level = 5;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 5;
	}
	else if (nowHero->experience < 375)
	{
		nowHero->level = 6;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 6;
	}
	else if (nowHero->experience < 455)
	{
		nowHero->level = 7;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 7;
	}
	else if (nowHero->experience < 530)
	{
		nowHero->level = 8;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 8;
	}
	else if (nowHero->experience < 610)
	{
		nowHero->level = 9;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 9;
	}
	else if (nowHero->experience < 695)
	{
		nowHero->level = 10;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 10;
	}
	else if (nowHero->experience < 785)
	{
		nowHero->level = 11;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 11;
	}
	else if (nowHero->experience < 880)
	{
		nowHero->level = 12;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 12;
	}
	else if (nowHero->experience < 980)
	{
		nowHero->level = 13;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 13;
	}
	else if (nowHero->experience < 1085)
	{
		nowHero->level = 14;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 14;
	}
	else if (nowHero->experience < 1195)
	{
		nowHero->level = 15;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 15;
	}
	else if (nowHero->experience < 1310)
	{
		nowHero->level = 16;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 16;
	}
	else if (nowHero->experience < 1430)
	{
		nowHero->level = 17;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 17;
	}
	else if (nowHero->experience < 1555)
	{
		nowHero->level = 17;
		if (nowHero->level - lastLevel)
		{
			skillUpgrade();
			lastLevel = nowHero->level;
		}
		upgradeTag = 17;
	}
	Label* labLevel = (Label*)this->getChildByTag(121);
	labLevel->setPosition(Point(50, 150));
	labLevel->setTag(121);
	labLevel->setString(String::createWithFormat("Level:%d", nowHero->level)->_string);

}


//getcontentsize

//void gameScene::skillsSlector()
//{
//	Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
//	if (this->getChildByTag(9845)->getChildByTag(546) == nullptr)
//	{
//		auto bt01 = Sprite::create("wsparticle_money01.png");
//		auto bt01_select = Sprite::create("wsparticle_money01.png");
//		bt01_select->setScaleX(1.1);
//		auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::selectSkill, nowHero));
//		mitem01->setTag(829);
//		auto menuSkill = Menu::create(mitem01, nullptr);
//		menuSkill->setTag(546);
//		menuSkill->setPosition(Vec2(300 - tx, 50 - ty));
//		this->getChildByTag(9845)->addChild(menuSkill);
//	}
//	else
//	{
//		auto nowMenu = this->getChildByTag(9845)->getChildByTag(546);
//		nowMenu->setPosition(Vec2(300 - tx, 50 - ty));
//	}
//
//}



void gameScene::skillsSlector()
{
	Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
	if (nowHero->ht == 1)
	{
		if (this->getChildByTag(546) == nullptr)
		{
			auto bt01 = Sprite::create("963.jpg");
			auto bt01_select = Sprite::create("963.jpg");
			bt01_select->setScaleX(1.1);
			auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::selectSkill_01, nowHero));
			mitem01->setTag(829);
			auto menuSkill01 = Menu::create(mitem01, nullptr);
			menuSkill01->setTag(546);
			menuSkill01->setPosition(Vec2(300, 50));
			this->addChild(menuSkill01);



			auto bt02 = Sprite::create("84651.jpg");
			auto bt02_select = Sprite::create("84651.jpg");
			bt02_select->setScaleX(1.1);
			auto mitem02 = MenuItemSprite::create(bt02, bt02_select, CC_CALLBACK_1(Hero::selectSkill_02, nowHero));
			mitem02->setTag(4345);
			auto menuSkill02 = Menu::create(mitem02, nullptr);
			menuSkill02->setTag(452);
			menuSkill02->setPosition(Vec2(400, 50));
			this->addChild(menuSkill02);


			auto bt03 = Sprite::create("234567.jpg");
			auto bt03_select = Sprite::create("234567.jpg");
			bt03_select->setScaleX(1.1);
			auto mitem03 = MenuItemSprite::create(bt03, bt03_select, CC_CALLBACK_1(Hero::selectSkill_03, nowHero));
			mitem03->setTag(300);
			auto menuSkill03 = Menu::create(mitem03, nullptr);
			menuSkill03->setTag(301);
			menuSkill03->setPosition(Vec2(500, 50));
			this->addChild(menuSkill03);





			/*		auto bt01 = Sprite::create("963.jpg");
					auto bt01_select = Sprite::create("963.jpg");
					bt01_select->setScaleX(1.1);
					auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::selectSkill, nowHero));
					mitem01->setTag(829);
					auto menuSkill = Menu::create(mitem01, nullptr);
					menuSkill->setTag(546);
					menuSkill->setPosition(Vec2(300, 50));
					this->addChild(menuSkill);*/


		}
	}

}





void gameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
	switch (keyCode)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_P:
	{
		auto nowShop = this->getChildByTag(854);
		if (nowShop == nullptr)
		{
			auto shop = Shop::createShop();
			shop->setTag(854);
			this->addChild(shop);
		}
		else
		{
			nowShop->removeFromParent();
			nowShop = nullptr;
		}
		break;
	}

	case cocos2d::EventKeyboard::KeyCode::KEY_Q:
	{
		nowHero->selectSkill_01(nowHero);
		break;
	}
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
	{
		nowHero->selectSkill_02(nowHero);
		break;
	}
	case cocos2d::EventKeyboard::KeyCode::KEY_E:
	{
		nowHero->selectSkill_03(nowHero);
		break;
	}

	default:
		break;
	}
}


void gameScene::inventory()
{
	if (this->getChildByTag(7284) == nullptr)
	{

		auto equipmentInventory = Sprite::create("PicsArt_06-08-03.56.46.png");
		this->addChild(equipmentInventory);
		equipmentInventory->setPosition(Vec2(700, 100));
		equipmentInventory->setTag(7284);
	}
}







//switch (keyCode) {
//case cocos2d::EventKeyboard::KeyCode::KEY_W: {
//	CCMoveBy* moveby = CCMoveBy::create(3.0f, ccp(0, 20));
//	CCActionInterval* SineOUt = CCEaseSineInOut::create(moveby);
//	plane->runAction(moveby);
//	break;
//}
//case cocos2d::EventKeyboard::KeyCode::KEY_S: {
//	CCMoveBy* moveby = CCMoveBy::create(3.0f, ccp(0, -20));
//	CCActionInterval * SineOUt = CCEaseSineInOut::create(moveby);
//	plane->runAction(moveby);
//	break;
//}
//case cocos2d::EventKeyboard::KeyCode::KEY_A: {
//	CCMoveBy* moveby = CCMoveBy::create(3.0f, ccp(-20, 0));
//	CCActionInterval* SineOUt = CCEaseSineInOut::create(moveby);
//	plane->runAction(moveby);
//	break;
//}
//case cocos2d::EventKeyboard::KeyCode::KEY_D: {
//	CCMoveBy* moveby = CCMoveBy::create(3.0f, ccp(20, 0));
//	CCActionInterval* SineOUt = CCEaseSineInOut::create(moveby);
//	plane->runAction(moveby);
//	break;
//}
//default:
//	break;
//}

void gameScene::skillUpgrade()
{
	Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
	if (nowHero->ht == 1)
	{
		auto bt01 = Sprite::create("com.tencent.plus.ic_success.png");
		auto bt01_select = Sprite::create("com.tencent.plus.ic_success.png");
		bt01_select->setScaleX(1.1);
		auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::skill_1_Upgrade, nowHero));
		mitem01->setTag(1);
		auto menuSkill01 = Menu::create(mitem01, nullptr);
		menuSkill01->setTag(11);
		menuSkill01->setPosition(Vec2(300, 100));
		this->addChild(menuSkill01);



		auto bt02 = Sprite::create("com.tencent.plus.ic_success.png");
		auto bt02_select = Sprite::create("com.tencent.plus.ic_success.png");
		bt02_select->setScaleX(1.1);
		auto mitem02 = MenuItemSprite::create(bt02, bt02_select, CC_CALLBACK_1(Hero::skill_2_Upgrade, nowHero));
		mitem02->setTag(2);
		auto menuSkill02 = Menu::create(mitem02, nullptr);
		menuSkill02->setTag(22);
		menuSkill02->setPosition(Vec2(400, 100));
		this->addChild(menuSkill02);


		auto bt03 = Sprite::create("com.tencent.plus.ic_success.png");
		auto bt03_select = Sprite::create("com.tencent.plus.ic_success.png");
		bt03_select->setScaleX(1.1);
		auto mitem03 = MenuItemSprite::create(bt03, bt03_select, CC_CALLBACK_1(Hero::skill_3_Upgrade, nowHero));
		mitem03->setTag(3);
		auto menuSkill03 = Menu::create(mitem03, nullptr);
		menuSkill03->setTag(33);
		menuSkill03->setPosition(Vec2(500, 100));
		this->addChild(menuSkill03);
	}

}


//void gameScene::skillsSlector()
//{
//	Hero* nowHero = (Hero*)this->getChildByTag(9845)->getChildByTag(478);
//	if (nowHero->ht == 1)
//	{
//		if (this->getChildByTag(546) == nullptr)
//		{
//			auto bt01 = Sprite::create("963.jpg");
//			auto bt01_select = Sprite::create("963.jpg");
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
//
//
//
//
//
//			/*		auto bt01 = Sprite::create("963.jpg");
//					auto bt01_select = Sprite::create("963.jpg");
//					bt01_select->setScaleX(1.1);
//					auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::selectSkill, nowHero));
//					mitem01->setTag(829);
//					auto menuSkill = Menu::create(mitem01, nullptr);
//					menuSkill->setTag(546);
//					menuSkill->setPosition(Vec2(300, 50));
//					this->addChild(menuSkill);*/
//
//
//		}
//	}
//
//}




//if (nowHero->experience == 50)
//{
//	nowHero->level = 2;
//	if ()
//		upgradeTag = 1;
//}
//else if (nowHero->experience == 105)
//{
//	nowHero->level = 3;
//	upgradeTag = 2;
//}
//else if (nowHero->experience == 165)
//{
//	nowHero->level = 4;
//	upgradeTag = 3;
//}
//else if (nowHero->experience == 230)
//{
//	nowHero->level = 5;
//	upgradeTag = 4;
//}
//else if (nowHero->experience == 300)
//{
//	nowHero->level = 6;
//	upgradeTag = 5;
//}
//else if (nowHero->experience == 375)
//{
//	nowHero->level = 7;
//	upgradeTag = 6;
//}
//else if (nowHero->experience == 455)
//{
//	nowHero->level = 8;
//	upgradeTag = 7;
//}
//else if (nowHero->experience == 530)
//{
//	nowHero->level = 9;
//	upgradeTag = 8;
//}
//else if (nowHero->experience == 610)
//{
//	nowHero->level = 10;
//	upgradeTag = 9;
//}
//else if (nowHero->experience == 695)
//{
//	nowHero->level = 11;
//	upgradeTag = 10;
//}
//else if (nowHero->experience == 785)
//{
//	nowHero->level = 12;
//	upgradeTag = 11;
//}
//else if (nowHero->experience == 880)
//{
//	nowHero->level = 13;
//	upgradeTag = 12;
//}
//else if (nowHero->experience == 980)
//{
//	nowHero->level = 14;
//	upgradeTag = 13;
//}
//else if (nowHero->experience == 1085)
//{
//	nowHero->level = 15;
//	upgradeTag = 14;
//}
//else if (nowHero->experience == 1195)
//{
//	nowHero->level = 16;
//	upgradeTag = 15;
//}
//else if (nowHero->experience == 1310)
//{
//	nowHero->level = 17;
//	upgradeTag = 16;
//}
//else if (nowHero->experience == 1430)
//{
//	nowHero->level = 18;
//	upgradeTag = 17;
//}