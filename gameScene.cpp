
#include"gameScene.h"
#include "Hero.h"
#include "Hero01.h"
#include "Hero02.h"
#include <cmath>
#include "Bullet.h"
#include "Skill.h"
#include "Shop.h"

USING_NS_CC;



#include "SimpleAudioEngine.h"
int total_num;
int soldierGroup;
int soldierNum;
Sprite* MAP;
gameScene* LAYER;
Hero *myHero, *oppositeHero;
bool Visit[80][80];
Vector<Sprite*> healthS;
extern Map<int, hatred1*> hatred;
extern Vector<Armor*> armors;
extern struct objs soldiers[2], towers[2], heros[2];
int a = 1;
int b = 1;

void gameScene::createTowers()
{
	Tower * towerBlue1, *towerBlue2, *towerBlue3, *towerBlue4, *towerBlue5, *towerRed1, *towerRed2, *towerRed3, *towerRed4, *towerRed5;
	towerBlue1 = Tower::create();
	towerBlue2 = Tower::create();
	towerBlue3 = Tower::create();
	towerBlue4 = Tower::create();
	towerBlue5 = Tower::create();
	towerRed1 = Tower::create();
	towerRed2 = Tower::create();
	towerRed3 = Tower::create();
	towerRed4 = Tower::create();
	towerRed5 = Tower::create();
	Sprite* sB1 = Sprite::create("tower.png");
	Sprite* sB2 = Sprite::create("tower.png");
	Sprite* sB3 = Sprite::create("tower.png");
	Sprite* sB4 = Sprite::create("tower.png");
	Sprite* sB5 = Sprite::create("tower.png");
	Sprite* sR1 = Sprite::create("tower.png");
	Sprite* sR2 = Sprite::create("tower.png");
	Sprite* sR3 = Sprite::create("tower.png");
	Sprite* sR4 = Sprite::create("tower.png");
	Sprite* sR5 = Sprite::create("tower.png");
	sB1->setTag(666);
	sB2->setTag(666);
	sB3->setTag(666);
	sB4->setTag(666);
	sB5->setTag(666);
	sR1->setTag(666);
	sR2->setTag(666);
	sR3->setTag(666);
	sR4->setTag(666);
	sR5->setTag(666);
	auto healthPic1 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic1);
	auto healthPic2 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic2);
	auto healthPic3 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic3);
	auto healthPic4 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic4);
	auto healthPic5 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic5);
	auto healthPic6 = Sprite::create("france.jpg");
	if (healthPic6 != NULL)
		CCLOG("NonNULLLLLLLL");
	//	healthS.pushBack(healthPic6);
	auto healthPic7 = Sprite::create("health.png");
	//healthS.pushBack(healthPic7);
	auto healthPic8 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic8);
	auto healthPic9 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic9);
	auto healthPic10 = Sprite::create("health.png");
	//	healthS.pushBack(healthPic10);
	healthPic1->setTag(999);
	healthPic2->setTag(999);
	healthPic3->setTag(999);
	healthPic7->setTag(999);
	healthPic9->setTag(999);
	healthPic4->setTag(999);
	healthPic5->setTag(999);
	healthPic6->setTag(999);
	healthPic8->setTag(999);
	healthPic10->setTag(999);
	towerBlue1->addChild(healthPic1);
	towerBlue2->addChild(healthPic2);
	towerBlue3->addChild(healthPic3);
	towerBlue4->addChild(healthPic4);
	towerBlue5->addChild(healthPic5);

	towerRed1->addChild(healthPic6);
	towerRed2->addChild(healthPic7);
	towerRed3->addChild(healthPic8);
	towerRed4->addChild(healthPic9);
	towerRed5->addChild(healthPic10);
	towerBlue1->addChild(sB1);
	towerBlue2->addChild(sB2);
	towerBlue3->addChild(sB3);
	towerBlue4->addChild(sB4);
	towerBlue5->addChild(sB5);
	towerRed1->addChild(sR1);
	towerRed2->addChild(sR2);
	towerRed3->addChild(sR3);
	towerRed4->addChild(sR4);
	towerRed5->addChild(sR5);
	towerBlue1->setPosition(Vec2(192, 192));
	towerBlue2->setPosition(Vec2(384, 832));
	towerBlue3->setPosition(Vec2(832, 384));
	towerBlue4->setPosition(Vec2(1216, 1216));
	towerBlue5->setPosition(Vec2(1792, 1792));
	towerRed1->setPosition(Vec2(4576, 4576));
	towerRed2->setPosition(Vec2(3968, 4416));
	towerRed3->setPosition(Vec2(4416, 3968));
	towerRed4->setPosition(Vec2(3584, 3584));
	towerRed5->setPosition(Vec2(3008, 3008));
	//待写，设置六个塔的全局编号
	towerBlue1->num = 3; towerBlue2->num = 4; towerBlue3->num = 5, towerBlue4->num = 6, towerBlue5->num = 7;
	towerRed1->num = 8; towerRed2->num = 9; towerRed3->num = 10; towerRed4->num = 11, towerRed5->num = 12;
	total_num = 12;
	towerBlue1->color = 0;
	towerBlue2->color = 0;
	towerBlue3->color = 0;
	towerBlue4->color = 0;
	towerBlue5->color = 0;
	towerRed1->color = 1;
	towerRed2->color = 1;
	towerRed3->color = 1,
		towerRed4->color = 1;
	towerRed5->color = 1;
	towerBlue1->health = 100; towerBlue2->health = 100; towerBlue3->health = 100, towerBlue4->health = 100, towerBlue5->health = 100;
	towerRed1->health = 100; towerRed2->health = 100; towerRed3->health = 100, towerRed4->health = 100, towerRed5->health = 100;
	towerBlue1->originHealth = 100; towerBlue2->originHealth = 100; towerBlue3->originHealth = 100, towerBlue4->originHealth = 100, towerBlue5->originHealth = 100;
	towerRed1->originHealth = 100; towerRed2->originHealth = 100; towerRed3->originHealth = 100, towerRed4->originHealth = 100, towerRed5->originHealth = 100;
	towerBlue1->range = 300; towerBlue2->range = 300; towerBlue3->range = 300, towerBlue4->range = 300, towerBlue5->range = 300;
	towerRed1->range = 300; towerRed2->range = 300; towerRed3->range = 300, towerRed4->range = 300, towerRed5->range = 300;
	towerBlue1->type = 2; towerBlue2->type = 2; towerBlue3->type = 2, towerBlue4->type = 2, towerBlue5->type = 2;
	towerRed1->type = 2; towerRed2->type = 2; towerRed3->type = 2, towerRed4->type = 2, towerRed5->type = 2;
	towerBlue1->lastTarget = -1; towerBlue2->lastTarget = -1; towerBlue3->lastTarget = -1, towerBlue4->lastTarget = -1, towerBlue5->lastTarget = -1;
	towerRed1->lastTarget = -1; towerRed2->lastTarget = -1; towerRed3->lastTarget = -1, towerRed4->lastTarget = -1, towerRed5->lastTarget = -1;
	towerBlue1->born();
	towerBlue2->born();
	towerBlue3->born();
	towerBlue4->born();
	towerBlue5->born();
	towerRed1->born();
	towerRed2->born();
	towerRed3->born();
	towerRed4->born();
	towerRed5->born();
	towers[0].list.pushBack(towerBlue5);
	towers[0].list.pushBack(towerBlue4);
	towers[0].list.pushBack(towerBlue3);
	towers[0].list.pushBack(towerBlue2);
	towers[0].list.pushBack(towerBlue1);
	towers[1].list.pushBack(towerRed5);
	towers[1].list.pushBack(towerRed4);
	towers[1].list.pushBack(towerRed3);
	towers[1].list.pushBack(towerRed2);
	towers[1].list.pushBack(towerRed1);
	MAP->addChild(towerBlue1);
	MAP->addChild(towerBlue2);
	MAP->addChild(towerBlue3);
	MAP->addChild(towerBlue4);
	MAP->addChild(towerBlue5);
	MAP->addChild(towerRed1);
	MAP->addChild(towerRed2);
	MAP->addChild(towerRed3);
	MAP->addChild(towerRed4);
	MAP->addChild(towerRed5);
}



























const double pi = 3.1415926535;
bool judgeRange = 0;// 判断是否选中敌人
//Vector<Node*> heros, enemys;
//Hero *hero, *enemy;
//Sprite* p;
float gameScene::ex;
float gameScene::ey;
int gameScene::equipmentAmount;

bool gameScene::init()
{
	lastLevel = 0;
	upgradeTag = 0;
	equipmentAmount = 0;
	Intermediate_variable = 0;
	//清空vector
	heros[1].list.clear();
	heros[0].list.clear();
	soldiers[0].list.clear();
	soldiers[1].list.clear();
	towers[0].list.clear();
	towers[1].list.clear();
	armors.clear();
	//背景wsparticle_19
	auto background = Sprite::create("FormalMap.png");
	//auto background = Sprite::create("wsparticle_19.png");
	background->setAnchorPoint(Vec2::ZERO);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, -1);
	background->setTag(9845);
	MAP = background;
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

	Scene::initWithPhysics();
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
	myHero = nowHero;


	/*Hero* nowHeroEnemy = Hero::createHero(2);
	this->getChildByTag(9845)->addChild(nowHeroEnemy);
	nowHeroEnemy->setTag(48512);
	nowHeroEnemy->setAnchorPoint(Vec2(0.5, 0.5));
	nowHeroEnemy->setPosition(Vec2(200, 200));
	nowHeroEnemy->maxhp = nowHeroEnemy->nowhp = 200;
	nowHero->health = 500;*/
	HeroAI* AI = HeroAI::createone(1);
	AI->setPosition(Vec2(4000, 4000));
	PhysicsBody* body1 = PhysicsBody::createBox(Size(70, 70));
	body1->setGroup(1);
	body1->setContactTestBitmask(1);
	body1->setCategoryBitmask(1);
	body1->setCollisionBitmask(1);
	body1->setPositionOffset(Vec2(0, 0));
	AI->setPhysicsBody(body1);
	AI->color = 1;
	oppositeHero = AI;
	MAP->addChild(AI);
	AI->schedule(schedule_selector(HeroAI::MoveOrAttack), 6);
	//	nowHero->skillsSlector();

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
	// 更新技能冷却
//	this->schedule(schedule_selector(gameScene::coldTime), 1);


	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	ex = ey = 500;
	//初始化visit数组
	int i, j;
	for (i = 1; i <= 80; i++)
	{
		for (j = 1; j <= 80; j++)
		{
			if (i<-j + 60 || i>-j + 100)
				Visit[i][j] = 0;
			else
				Visit[i][j] = 1;
		}
	}

	/*auto map = Sprite::create("FormalMap.png");
	map->setAnchorPoint(Vec2(0, 0));
	map->setPosition(Vec2(0, 0));*/


	//	this->ex = 0, this->ey = 0;
		//放塔
	this->createTowers();
	//每隔30秒双方各产生一批小兵
	soldierGroup = 0;
	soldierNum = 0;

	//监听刚体碰撞事件
	EventListenerPhysicsContact* eventContact = EventListenerPhysicsContact::create();
	eventContact->onContactBegin = CC_CALLBACK_1(gameScene::phyContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(eventContact, this);
	this->scheduleOnce(schedule_selector(gameScene::startGenerateSoldiers), 2);
	//每帧更新内容



	return true;
}

Scene* gameScene::createscene()
{
	auto scene = Scene::createWithPhysics();
	auto layer = gameScene::create();
	PhysicsWorld* world = scene->getPhysicsWorld();
	world->setGravity(Vec2(0, 0));
	world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->addChild(layer);
	return scene;
}
bool gameScene::onMouseDown(Event* event)
{
	if (a == b)
	{
		judgeRange = 0;
		Hero* nowHeroEnemy = static_cast<Hero*>(this->getChildByTag(9845)->getChildByTag(48512));


		this->unschedule(schedule_selector(Hero::fire));
		//Director::getInstance()->getActionManager()->pauseAllRunningActions();
		EventMouse* e = (EventMouse*)event;
		Hero* nowHero = static_cast<Hero*>(this->getChildByTag(9845)->getChildByTag(478));
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
				auto nowSkill = Skill::createSkill(skillRotation, nowHero->getPositionX(), nowHero->getPositionY(), eex - tx, eey - ty, nowHero);
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
				auto heroRotate = RotateBy::create(0.01, tangle);
				angle = tagetAngle;
				nowHero->angle = angle;
				nowHero->runAction(heroRotate);
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
				auto heroRotate = RotateBy::create(0.15, tangle);
				angle = tagetAngle;
				nowHero->angle = angle;
				nowHero->runAction(heroRotate);
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
			//弹性飞弹
			if (Hero::judgeSkill == 4)
			{
				float tagx = ex - tx;
				float tagy = ey - ty;
				float mx = nowHero->getPositionX();
				float my = nowHero->getPositionY();
				Armor* boundArmor = Armor::createone(mx, my, 3);
				boundArmor->speed = 500;
				boundArmor->removeChildByTag(166);
				Sprite* FirePic = Sprite::create("wsparticle_27.png");
				FirePic->setTag(21574);
				boundArmor->addChild(FirePic);
				boundArmor->father = nowHero;
				boundArmor->color = 0;
				boundArmor->damage = 90;
				double tagetAngle = std::atan2(ey - ty - nowHero->getPositionY(), ex - tx - nowHero->getPositionX()) * (180.0 / pi);
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
				this->getChildByTag(9845)->getChildByTag(478)->getChildByTag(2678)->removeFromParent();
				Hero::judgeSkill = 0;
			}
		}



		if ((int)(e->getMouseButton()) == 1)
		{
			Intermediate_variable = 0;
			int i, ret = 0;
			for (i = 0; i < towers[1].list.size(); i++)
			{
					auto nowHeroEnemyX = towers[1].list.at(i)->getChildByTag(666)->getBoundingBox().size.width;
					auto nowHeroEnemyY = towers[1].list.at(i)->getChildByTag(666)->getBoundingBox().size.height;
					Rect ehr
					(
						towers[1].list.at(i)->getPositionX() - nowHeroEnemyX / 2 + 10,
						towers[1].list.at(i)->getPositionY() - nowHeroEnemyY / 2 + 10,
						nowHeroEnemyX - 10,
						nowHeroEnemyY - 10
					);

					if (mr.intersectsRect(ehr))
					{
						//攻击敌人
						nowHero->target = towers[1].list.at(i);
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
						return true;
					}
					
				}
			if (!soldiers[1].list.empty())
			{

				for (i = 0; i < soldiers[1].list.size(); i++)
				{

					auto nowHeroEnemyX = soldiers[1].list.at(i)->getChildByTag(666)->getBoundingBox().size.width;
					auto nowHeroEnemyY = soldiers[1].list.at(i)->getChildByTag(666)->getBoundingBox().size.height;
					Rect ehr
					(
						soldiers[1].list.at(i)->getPositionX() - nowHeroEnemyX / 2 + 3,
						soldiers[1].list.at(i)->getPositionY() - nowHeroEnemyY / 2 + 3,
						nowHeroEnemyX - 1,
						nowHeroEnemyY - 1
					);

					if (mr.intersectsRect(ehr))
					{
						//攻击敌人
						nowHero->target = soldiers[1].list.at(i);
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
						return true;
					}
					
				}
			}
				auto nowHeroEnemyX = oppositeHero->getChildByTag(666)->getBoundingBox().size.width;
				auto nowHeroEnemyY = oppositeHero->getChildByTag(666)->getBoundingBox().size.height;
				Rect ehr
				(
					oppositeHero->getPositionX() - nowHeroEnemyX / 2 + 10,
					oppositeHero->getPositionY() - nowHeroEnemyY / 2 + 10,
					nowHeroEnemyX - 10,
					nowHeroEnemyY - 10
				);

				if (mr.intersectsRect(ehr))
				{
					//攻击敌人
					nowHero->target = oppositeHero;
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
					return true;
				}
					myHero->target = NULL;
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
					
			//else
			//{
			//	nowHero->isFire = 0;
			//	nowHero->unschedule(schedule_selector(Hero::fire));
			//	double tagetAngle = std::atan2(eey - ty - ny, eex - tx - nx) * (180.0 / pi);
			//	double tangle = angle - tagetAngle;
			//	if (angle != tagetAngle)
			//	{
			//		auto heroRotate = RotateBy::create(0.15, tangle);
			//		angle = tagetAngle;
			//		nowHero->angle = angle;
			//		nowHero->runAction(heroRotate);
			//	}
			//	click(eex - tx, eey - ty);
			//	//移动过去
			//	double howfar = Vec2(nx, ny).getDistance(Vec2(eex - tx, eey - ty));
			//	double time = howfar / nowHero->speed;
			//	auto heroMove = MoveTo::create(time, Vec2(eex - tx, eey - ty));
			//	nowHero->runAction(heroMove);
			//	heroMove->setTag(9649);
			//}
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
	if (Hero::judgeSkill == 1 || Hero::judgeSkill == 2 || Hero::judgeSkill == 4)
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
//	if (nowHeroEnemy)
//	{
		/*float nx = nowHero->getPositionX();
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
		);*/

		//auto testlocation1 = Sprite::create("button_red.9.png");
		//auto testlocation2 = Sprite::create("button_red.9.png");
		//auto testlocation3 = Sprite::create("button_red.9.png");
		//auto testlocation4 = Sprite::create("button_red.9.png");
		//testlocation1->setPosition(Vec2(nowHeroEnemy->getPositionX() - nowHeroEnemyX / 2, nowHeroEnemy->getPositionY() - nowHeroEnemyY / 2));
		//testlocation2->setPosition(Vec2(nowHeroEnemy->getPositionX() + nowHeroEnemyX / 2, nowHeroEnemy->getPositionY() + nowHeroEnemyY / 2));
		//this->addChild(testlocation1);
		//this->addChild(testlocation2);

		/*if (nowHeroEnemy->nowhp <= 0)
		{
			CCLOG("IIIIIIIIIIIIIIIIIIII");
			nowHeroEnemy->removeFromParent();
			nowHero->target = NULL;
			nowHero->money = nowHero->money + 300;
			return;
		}

*/
	float nx = myHero->getPositionX();
	float ny = myHero->getPositionY();
	
	
	if(myHero->target!=NULL)
	{
		if (myHero->target->isDead == 1)
		{
			myHero->target = NULL;
			return;
		}
		float nex = myHero->target->getPositionX();
		float ney = myHero->target->getPositionY();

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
//	}
//	float nx = nowHero->getPositionX();
//	float ny = nowHero->getPositionY();
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
	/*if (nowHeroEnemy)
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

	}*/
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


























	int i;
	for (i = 0; i < towers[0].list.size(); i++)
	{
		if (towers[0].list.at(i)->isDead == 0)
			static_cast<Tower*>(towers[0].list.at(i))->UPDATE();
	}

	for (i = 0; i < towers[1].list.size(); i++)
	{
		if (towers[1].list.at(i)->isDead == 0)
			static_cast<Tower*>(towers[1].list.at(i))->UPDATE();
	}

	for (i = 0; i < armors.size(); i++)
	{
		static_cast<Armor*>(armors.at(i))->UPDATE();
	}

	for (i = 0; i < soldiers[0].list.size(); i++)
	{
		if (soldiers[0].list.at(i)->isDead == 0)
			static_cast<soldier*>(soldiers[0].list.at(i))->UPDATE();
	}

	for (i = 0; i < soldiers[1].list.size(); i++)
	{
		if (soldiers[1].list.at(i)->isDead == 0)
			static_cast<soldier*>(soldiers[1].list.at(i))->UPDATE();
	}

	for (i = 0; i < heros[0].list.size(); i++)
	{
		if (heros[0].list.at(i)->isDead == 0)
			static_cast<Hero*>(heros[0].list.at(i))->UPDATE();
	}

	for (i = 0; i < heros[1].list.size(); i++)
	{
		if (heros[1].list.at(i)->isDead == 0)
			static_cast<Hero*>(heros[1].list.at(i))->UPDATE();
	}






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

		}
	}
	if (nowHero->ht == 2)
	{
		if (this->getChildByTag(546) == nullptr)
		{
			auto bt01 = Sprite::create("963.jpg");
			auto bt01_select = Sprite::create("963.jpg");
			bt01_select->setScaleX(1.1);
			auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::selectSkill_04, nowHero));
			mitem01->setTag(829);
			auto menuSkill01 = Menu::create(mitem01, nullptr);
			menuSkill01->setTag(546);
			menuSkill01->setPosition(Vec2(300, 50));
			this->addChild(menuSkill01);



			auto bt02 = Sprite::create("84651.jpg");
			auto bt02_select = Sprite::create("84651.jpg");
			bt02_select->setScaleX(1.1);
			auto mitem02 = MenuItemSprite::create(bt02, bt02_select, CC_CALLBACK_1(Hero::selectSkill_05, nowHero));
			mitem02->setTag(4345);
			auto menuSkill02 = Menu::create(mitem02, nullptr);
			menuSkill02->setTag(452);
			menuSkill02->setPosition(Vec2(400, 50));
			this->addChild(menuSkill02);


			auto bt03 = Sprite::create("234567.jpg");
			auto bt03_select = Sprite::create("234567.jpg");
			bt03_select->setScaleX(1.1);
			auto mitem03 = MenuItemSprite::create(bt03, bt03_select, CC_CALLBACK_1(Hero::selectSkill_06, nowHero));
			mitem03->setTag(300);
			auto menuSkill03 = Menu::create(mitem03, nullptr);
			menuSkill03->setTag(301);
			menuSkill03->setPosition(Vec2(500, 50));
			this->addChild(menuSkill03);

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
		if (nowHero->ht == 1)
			nowHero->selectSkill_01(nowHero);
		else if (nowHero->ht == 2)
			nowHero->selectSkill_04(nowHero);
		break;
	}
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
	{
		if (nowHero->ht == 1)
			nowHero->selectSkill_02(nowHero);
		else if (nowHero->ht == 2)
			nowHero->selectSkill_05(nowHero);
		break;
	}
	case cocos2d::EventKeyboard::KeyCode::KEY_E:
	{
		if (nowHero->ht == 1)
			nowHero->selectSkill_03(nowHero);
		else if (nowHero->ht == 2)
			nowHero->selectSkill_06(nowHero);
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
	if (nowHero->ht == 2)
	{
		auto bt01 = Sprite::create("com.tencent.plus.ic_success.png");
		auto bt01_select = Sprite::create("com.tencent.plus.ic_success.png");
		bt01_select->setScaleX(1.1);
		auto mitem01 = MenuItemSprite::create(bt01, bt01_select, CC_CALLBACK_1(Hero::skill_4_Upgrade, nowHero));
		mitem01->setTag(1);
		auto menuSkill01 = Menu::create(mitem01, nullptr);
		menuSkill01->setTag(11);
		menuSkill01->setPosition(Vec2(300, 100));
		this->addChild(menuSkill01);



		auto bt02 = Sprite::create("com.tencent.plus.ic_success.png");
		auto bt02_select = Sprite::create("com.tencent.plus.ic_success.png");
		bt02_select->setScaleX(1.1);
		auto mitem02 = MenuItemSprite::create(bt02, bt02_select, CC_CALLBACK_1(Hero::skill_5_Upgrade, nowHero));
		mitem02->setTag(2);
		auto menuSkill02 = Menu::create(mitem02, nullptr);
		menuSkill02->setTag(22);
		menuSkill02->setPosition(Vec2(400, 100));
		this->addChild(menuSkill02);


		auto bt03 = Sprite::create("com.tencent.plus.ic_success.png");
		auto bt03_select = Sprite::create("com.tencent.plus.ic_success.png");
		bt03_select->setScaleX(1.1);
		auto mitem03 = MenuItemSprite::create(bt03, bt03_select, CC_CALLBACK_1(Hero::skill_6_Upgrade, nowHero));
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




















static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

//void gameScene::createTowers()
//{
//	Tower* towerBlue1, * towerBlue2, * towerBlue3, * towerBlue4, * towerBlue5, * towerRed1, * towerRed2, * towerRed3, * towerRed4, * towerRed5;
//	towerBlue1 = Tower::create();
//	towerBlue2 = Tower::create();
//	towerBlue3 = Tower::create();
//	towerBlue4 = Tower::create();
//	towerBlue5 = Tower::create();
//	towerRed1 = Tower::create();
//	towerRed2 = Tower::create();
//	towerRed3 = Tower::create();
//	towerRed4 = Tower::create();
//	towerRed5 = Tower::create();
//	Sprite* sB1 = Sprite::create("tower.png");
//	Sprite* sB2 = Sprite::create("tower.png");
//	Sprite* sB3 = Sprite::create("tower.png");
//	Sprite* sB4 = Sprite::create("tower.png");
//	Sprite* sB5 = Sprite::create("tower.png");
//	Sprite* sR1 = Sprite::create("tower.png");
//	Sprite* sR2 = Sprite::create("tower.png");
//	Sprite* sR3 = Sprite::create("tower.png");
//	Sprite* sR4 = Sprite::create("tower.png");
//	Sprite* sR5 = Sprite::create("tower.png");
//
//	auto healthPic1 = Sprite::create("health.png");
//	healthS.pushBack(healthPic1);
//	auto healthPic2 = Sprite::create("health.png");
//	healthS.pushBack(healthPic2);
//	auto healthPic3 = Sprite::create("health.png");
//	healthS.pushBack(healthPic3);
//	auto healthPic4 = Sprite::create("health.png");
//	healthS.pushBack(healthPic4);
//	auto healthPic5 = Sprite::create("health.png");
//	healthS.pushBack(healthPic5);
//	auto healthPic6 = Sprite::create("france.jpg");
//	if (healthPic6 != NULL)
//		CCLOG("NonNULLLLLLLL");
//	healthS.pushBack(healthPic6);
//	auto healthPic7 = Sprite::create("health.png");
//	//healthS.pushBack(healthPic7);
//	auto healthPic8 = Sprite::create("health.png");
////	healthS.pushBack(healthPic8);
//	auto healthPic9 = Sprite::create("health.png");
////	healthS.pushBack(healthPic9);
//	auto healthPic10 = Sprite::create("health.png");
////	healthS.pushBack(healthPic10);
//	healthPic1->setTag(999);
//	healthPic2->setTag(999);
//	healthPic3->setTag(999);
//	healthPic7->setTag(999);
//	healthPic9->setTag(999);
//	healthPic4->setTag(999);
//	healthPic5->setTag(999);
//	healthPic6->setTag(999);
//	healthPic8->setTag(999);
//	healthPic10->setTag(999);
//	towerBlue1->addChild(healthPic1);
//	towerBlue2->addChild(healthPic2);
//	towerBlue3->addChild(healthPic3);
//	towerBlue4->addChild(healthPic4);
//	towerBlue5->addChild(healthPic5);
//
//	towerRed1->addChild(healthPic6);
//	towerRed2->addChild(healthPic7);
//	towerRed3->addChild(healthPic8);
//	towerRed4->addChild(healthPic9);
//	towerRed5->addChild(healthPic10);
//	towerBlue1->addChild(sB1);
//	towerBlue2->addChild(sB2);
//	towerBlue3->addChild(sB3);
//	towerBlue4->addChild(sB4);
//	towerBlue5->addChild(sB5);
//	towerRed1->addChild(sR1);
//	towerRed2->addChild(sR2);
//	towerRed3->addChild(sR3);
//	towerRed4->addChild(sR4);
//	towerRed5->addChild(sR5);
//	towerBlue1->setPosition(Vec2(192, 192));
//	towerBlue2->setPosition(Vec2(384, 832));
//	towerBlue3->setPosition(Vec2(832, 384));
//	towerBlue4->setPosition(Vec2(1216, 1216));
//	towerBlue5->setPosition(Vec2(1792, 1792));
//	towerRed1->setPosition(Vec2(4576, 4576));
//	towerRed2->setPosition(Vec2(3968, 4416));
//	towerRed3->setPosition(Vec2(4416, 3968));
//	towerRed4->setPosition(Vec2(3584, 3584));
//	towerRed5->setPosition(Vec2(3008, 3008));
//	//待写，设置六个塔的全局编号
//	towerBlue1->num = 3; towerBlue2->num = 4; towerBlue3->num = 5, towerBlue4->num = 6, towerBlue5->num = 7;
//	towerRed1->num = 8; towerRed2->num = 9; towerRed3->num = 10; towerRed4->num = 11, towerRed5->num = 12;
//	total_num = 12;
//	towerBlue1->color = 0; towerBlue2->color = 0; towerBlue3->color = 0, towerBlue4->color = 0, towerBlue5->color = 0;
//	towerRed1->color = 1; towerRed2->color = 1; towerRed3->color = 1, towerRed4->color = 1, towerRed5->color = 1;
//	towerBlue1->health = 100; towerBlue2->health = 100; towerBlue3->health = 100, towerBlue4->health = 100, towerBlue5->health = 100;
//	towerRed1->health = 100; towerRed2->health = 100; towerRed3->health = 100, towerRed4->health = 100, towerRed5->health = 100;
//	towerBlue1->originHealth = 100; towerBlue2->originHealth = 100; towerBlue3->originHealth = 100, towerBlue4->originHealth = 100, towerBlue5->originHealth = 100;
//	towerRed1->originHealth = 100; towerRed2->originHealth = 100; towerRed3->originHealth = 100, towerRed4->originHealth = 100, towerRed5->originHealth = 100;
//	towerBlue1->range = 300; towerBlue2->range = 300; towerBlue3->range = 300, towerBlue4->range = 300, towerBlue5->range = 300;
//	towerRed1->range = 300; towerRed2->range = 300; towerRed3->range = 300, towerRed4->range = 300, towerRed5->range = 300;
//	towerBlue1->type = 2; towerBlue2->type = 2; towerBlue3->type = 2, towerBlue4->type = 2, towerBlue5->type = 2;
//	towerRed1->type = 2; towerRed2->type = 2; towerRed3->type = 2, towerRed4->type = 2, towerRed5->type = 2;
//	towerBlue1->lastTarget = -1; towerBlue2->lastTarget = -1; towerBlue3->lastTarget = -1, towerBlue4->lastTarget = -1, towerBlue5->lastTarget = -1;
//	towerRed1->lastTarget = -1; towerRed2->lastTarget = -1; towerRed3->lastTarget = -1, towerRed4->lastTarget = -1, towerRed5->lastTarget = -1;
//	towerBlue1->born();
//	towerBlue2->born();
//	towerBlue3->born();
//	towerBlue4->born();
//	towerBlue5->born();
//	towerRed1->born();
//	towerRed2->born();
//	towerRed3->born();
//	towerRed4->born();
//	towerRed5->born();
//	towers[0].list.pushBack(towerBlue5);
//	towers[0].list.pushBack(towerBlue4);
//	towers[0].list.pushBack(towerBlue3);
//	towers[0].list.pushBack(towerBlue2);
//	towers[0].list.pushBack(towerBlue1);
//	towers[1].list.pushBack(towerRed5);
//	towers[1].list.pushBack(towerRed4);
//	towers[1].list.pushBack(towerRed3);
//	towers[1].list.pushBack(towerRed2);
//	towers[1].list.pushBack(towerRed1);
//	MAP->addChild(towerBlue1);
//	MAP->addChild(towerBlue2);
//	MAP->addChild(towerBlue3);
//	MAP->addChild(towerBlue4);
//	MAP->addChild(towerBlue5);
//	MAP->addChild(towerRed1);
//	MAP->addChild(towerRed2);
//	MAP->addChild(towerRed3);
//	MAP->addChild(towerRed4);
//	MAP->addChild(towerRed5);
//}
//





void gameScene::startGenerateSoldiers(float t)
{
	this->schedule(schedule_selector(gameScene::soldierGroups), 30);
}

bool gameScene::phyContactBegin(PhysicsContact& contact)
{
	auto an = contact.getShapeA()->getBody()->getNode();
	auto bn = contact.getShapeB()->getBody()->getNode();
	Enemy* a = static_cast<Enemy*>(an);
	Enemy* b = static_cast<Enemy*>(bn);
	if (!b || !a)
		return true;
	if ((a->num == 2) || (b->num == 2))
	{
		if (a->color != b->color)
			CCLOG("PENG SHANG LE AI %d %d", a->num, b->num);
	}
	if (((a->type == 5 && b->type != 5) || (a->type != 5 && b->type == 5)))
	{

		if ((a->color != b->color) && a->isDead == 0 && b->isDead == 0)
		{

			Enemy* p, *q;
			float qHealth;
			if (a->type == 5)
				p = a, q = b;
			else
				p = b, q = a;
			if (static_cast<Armor*>(p)->father == myHero)
				CCLOG("NUM: %d COLOR:%d", q->num, q->color);
			//若子弹是冻僵类型
			if (static_cast<Armor*>(p)->isFrozen == 1)
			{
				q->frozed = 1;
				q->scheduleOnce(schedule_selector(Enemy::FrozedToNormal), 2);
			}
			if (q->type == 3)
				static_cast<Hero*>(q)->nowhp -= p->damage, qHealth = static_cast<Hero*>(q)->nowhp;
			else
				q->health -= p->damage, qHealth = q->health;
			if (qHealth <= 0)
			{
				//是英雄的话加经验加钱
				if (static_cast<Armor*>(p)->father->type == 3 && static_cast<Armor*>(p)->father->isDead == 0)
				{
					if (q->type == 2)
						static_cast<Armor*>(p)->father->exp += 100, static_cast<Armor*>(p)->father->money += 10;
					else if (q->type == 3)
						static_cast<Armor*>(p)->father->exp += 100, static_cast<Armor*>(p)->father->money += 10;
					else if (q->type == 4)
						static_cast<Armor*>(p)->father->exp += 100, static_cast<Armor*>(p)->father->money += 10;

				}
				if (q->isDead == 0)
					q->die();
			}
			else
			{
				if (q->type == 4)
					static_cast<soldier*>(q)->beAttacked(static_cast<Armor*>(p)->father);
			}
			static_cast<Armor*>(p)->suicide();
		}
	}
	return true;
}

void gameScene::coldTime(float t)
{
	int i;
	for (i = 0; i < 3; i++)
	{
		if (myHero->leftTime[i] > 0)
		{
			myHero->leftTime[i] -= 1;
			if (myHero->leftTime[i] < 0)
				myHero->leftTime[i] = 0;
		}
		if (oppositeHero->leftTime[i] > 0)
		{
			oppositeHero->leftTime[i] -= 1;
			if (oppositeHero->leftTime[i] < 0)
				oppositeHero->leftTime[i] = 0;
		}
	}
}



void gameScene::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void gameScene::createPair(float t)
{
	soldierNum += 2;
	int singleNum = soldierNum / 2;
	soldier* soldierBlue = soldier::create();
	soldier* soldierRed = soldier::create();
	Sprite* spriteBlue, *spriteRed;
	Point v1[] = { Point(6 / 9 ,232 / 9),Point(-34 / 9,73 / 9),Point(-237 / 9,37 / 9),Point(-21 / 9,-64 / 9),Point(7 / 9,-238 / 9),Point(34 / 9,-57 / 9),Point(243 / 9,33 / 9),Point(48 / 9,71 / 9) };
	PhysicsBody* body1 = PhysicsBody::createPolygon(v1, 8);
	body1->setGroup(1);
	body1->setContactTestBitmask(1);
	body1->setCategoryBitmask(1);
	body1->setCollisionBitmask(1);
	body1->setPositionOffset(Vec2(0, 0));

	PhysicsBody* body2 = PhysicsBody::createPolygon(v1, 8);
	body2->setGroup(1);
	body2->setContactTestBitmask(1);
	body2->setCategoryBitmask(1);
	body2->setCollisionBitmask(1);
	body2->setPositionOffset(Vec2(0, 0));
	soldierBlue->setPhysicsBody(body1);
	soldierRed->setPhysicsBody(body2);
	//添加血条
	auto healthPic1 = Sprite::create("health.png");
	if (healthPic1 == NULL)
		CCLOG("NULLLLLLLL");
	auto healthPic2 = Sprite::create("health.png");
	if (healthPic2 == NULL)
		CCLOG("NULLLLLLLL");
	healthPic1->setTag(999);
	healthPic1->setPosition(Vec2(0, 50));
	healthPic2->setTag(999);
	healthPic2->setPosition(Vec2(0, 50));
	healthS.pushBack(healthPic1);
	healthS.pushBack(healthPic2);
	soldierBlue->addChild(healthPic1);
	soldierRed->addChild(healthPic2);
	int tmp = singleNum % 19;
	if (tmp == 0)
	{
		//炮车
		spriteBlue = Sprite::create("soldierS.png");
		spriteRed = Sprite::create("soldierS.png");
		soldierBlue->range = 90;
		soldierRed->range = 90;
	}
	else
	{
		if (tmp % 3 == 0)
			tmp /= 3;
		else
			tmp = tmp / 3 + 1;
		//近战
		if (tmp % 2 == 1)
			spriteBlue = Sprite::create("soldier.png"), spriteRed = Sprite::create("soldier.png"), soldierBlue->range = 9, soldierRed->range = 9;
		//远程
		else
			spriteBlue = Sprite::create("soldier.png"), spriteRed = Sprite::create("soldier.png"), soldierBlue->range = 180, soldierRed->range = 180;
	}
	spriteBlue->setTag(666);
	spriteRed->setTag(666);
	soldierBlue->addChild(spriteBlue);
	soldierRed->addChild(spriteRed);
	soldierBlue->num = total_num + 1;
	soldierRed->num = total_num + 2;
	total_num += 2;
	//初始化小兵 
	soldierBlue->setPosition(Vec2(290, 290));
	soldierRed->setPosition(Vec2(2300, 2300));
	soldierBlue->color = 0;
	soldierRed->color = 1;
	soldierBlue->searchRange = 270;
	soldierRed->searchRange = 270;
	soldierBlue->health = 100;
	soldierBlue->originHealth = 100;
	soldierRed->originHealth = 100;
	soldierRed->health = 100;
	soldierBlue->type = 4;
	soldierRed->type = 4;
	soldierBlue->speed = 80;
	soldierRed->speed = 80;
	soldierBlue->isInTower = 0;
	soldierRed->isInTower = 0;
	
	soldierBlue->count = 0;
	soldierRed->count = 0;
	soldierBlue->frozed = 0;
	soldierRed->frozed = 0;
	soldierBlue->frozedJustNow = 0;
	soldierRed->frozedJustNow = 0;
	soldierBlue->addtoHatred();
	soldierRed->addtoHatred();
	soldierBlue->born();
	soldierRed->born();
	soldiers[0].list.pushBack(soldierBlue);
	soldiers[1].list.pushBack(soldierRed);
	MAP->addChild(soldierBlue);
	MAP->addChild(soldierRed);
	//小兵定时寻路
	soldierBlue->specialUpdate();
	soldierRed->specialUpdate();
}

void gameScene::soldierGroups(float t)
{
	soldierGroup++;
	if (soldierGroup % 3 == 0)
		this->schedule(schedule_selector(gameScene::createPair), 2, 7, 0);
	else
		this->schedule(schedule_selector(gameScene::createPair), 2, 6, 0);
}
