#include "Shop.h"
#include "cocos2d.h"
#include "gameScene.h"
#include "Hero.h"
bool Shop::init()
{
	if (!Node::init())
		return false;
	return true;
}

Shop* Shop::createShop()
{
	Shop* newShop = Shop::create();
	auto shopPicture = Sprite::create("15487946.jpg");
	shopPicture->setTag(8546);
	shopPicture->setPosition(Vec2(600, 500));
	//equipment

	auto spbt01 = Sprite::create("zb01.jpg");
	auto spbt01_select = Sprite::create("zb01.jpg");
	spbt01_select->setScaleX(1.1);
	auto mitem01 = MenuItemSprite::create(spbt01, spbt01_select, CC_CALLBACK_1(Shop::buyEquipment01, newShop));
	mitem01->setTag(99901);
	auto menuShop01 = Menu::create(mitem01, nullptr);
	menuShop01->setTag(99902);
	menuShop01->setPosition(Vec2(450,550));
	newShop->addChild(menuShop01);
	newShop->addChild(shopPicture, -1);


	auto spbt02 = Sprite::create("zb02.jpg");
	auto spbt02_select = Sprite::create("zb02.jpg");
	spbt02_select->setScaleX(1.1);
	auto mitem02 = MenuItemSprite::create(spbt02, spbt02_select, CC_CALLBACK_1(Shop::buyEquipment02, newShop));
	mitem02->setTag(99901);
	auto menuShop02 = Menu::create(mitem02, nullptr);
	menuShop02->setTag(99902);
	menuShop02->setPosition(Vec2(550, 550));
	newShop->addChild(menuShop02);



	auto spbt03 = Sprite::create("zb03.jpg");
	auto spbt03_select = Sprite::create("zb03.jpg");
	spbt03_select->setScaleX(1.1);
	auto mitem03 = MenuItemSprite::create(spbt03, spbt03_select, CC_CALLBACK_1(Shop::buyEquipment03, newShop));
	mitem03->setTag(99901);
	auto menuShop03 = Menu::create(mitem03, nullptr);
	menuShop03->setTag(99902);
	menuShop03->setPosition(Vec2(650, 550));
	newShop->addChild(menuShop03);


	auto spbt04 = Sprite::create("(P%U6RP21X~B8{~$KE%0A{Q.jpg");
	auto spbt04_select = Sprite::create("(P%U6RP21X~B8{~$KE%0A{Q.jpg");
	spbt04_select->setScaleX(1.1);
	auto mitem04 = MenuItemSprite::create(spbt04, spbt04_select, CC_CALLBACK_1(Shop::buyEquipment04, newShop));
	mitem04->setTag(99901);
	auto menuShop04 = Menu::create(mitem04, nullptr);
	menuShop04->setTag(99902);
	menuShop04->setPosition(Vec2(750, 550));
	newShop->addChild(menuShop04);



	auto spbt05 = Sprite::create("$YG~Z[~9TH~71R%]{PH)PK1.jpg");
	auto spbt05_select = Sprite::create("$YG~Z[~9TH~71R%]{PH)PK1.jpg");
	spbt05_select->setScaleX(1.1);
	auto mitem05 = MenuItemSprite::create(spbt05, spbt05_select, CC_CALLBACK_1(Shop::buyEquipment05, newShop));
	mitem05->setTag(99901);
	auto menuShop05 = Menu::create(mitem05, nullptr);
	menuShop05->setTag(99902);
	menuShop05->setPosition(Vec2(450, 450));
	newShop->addChild(menuShop05);





	auto spbt06 = Sprite::create("G{(VA2S0AG8`J`E6BJ{UU9C.jpg");
	auto spbt06_select = Sprite::create("G{(VA2S0AG8`J`E6BJ{UU9C.jpg");
	spbt06_select->setScaleX(1.1);
	auto mitem06 = MenuItemSprite::create(spbt06, spbt06_select, CC_CALLBACK_1(Shop::buyEquipment06, newShop));
	mitem06->setTag(99901);
	auto menuShop06 = Menu::create(mitem06, nullptr);
	menuShop06->setTag(99902);
	menuShop06->setPosition(Vec2(550, 450));
	newShop->addChild(menuShop06);



	auto spbt07 = Sprite::create("QSHSNLSDOEIMIFJ2[R7%@SY.jpg");
	auto spbt07_select = Sprite::create("QSHSNLSDOEIMIFJ2[R7%@SY.jpg");
	spbt07_select->setScaleX(1.1);
	auto mitem07 = MenuItemSprite::create(spbt07, spbt07_select, CC_CALLBACK_1(Shop::buyEquipment07, newShop));
	mitem07->setTag(99901);
	auto menuShop07 = Menu::create(mitem07, nullptr);
	menuShop07->setTag(99902);
	menuShop07->setPosition(Vec2(650, 450));
	newShop->addChild(menuShop07);



	return newShop;
}




void Shop::buyEquipment01(Ref* obj)
{
	if (gameScene::equipmentAmount == 6)
	{
		auto labLevel = Label::create("Your equipment inventory is full", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("max");
		return;
	}
	Hero *nowHero=(Hero *)(this->getParent()->getChildByTag(9845)->getChildByTag(478));
	if (nowHero->money < 2850)
	{
		auto labLevel = Label::create("your money is not enough", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("your money is not enough");
	}
	else
	{
		nowHero->money -= 2850;
		nowHero->maxhp += 10;
		gameScene::equipmentAmount++;
		auto newEquipment = Sprite::create("PicsArt_06-08-03.56.14.jpg");
		allEquipment.pushBack(newEquipment);
		this->getParent()->addChild(newEquipment);
		setEquipmentPosition();
	}
}


void Shop::buyEquipment02(Ref* obj)
{
	if (gameScene::equipmentAmount == 6)
	{
		auto labLevel = Label::create("Your equipment inventory is full", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("max");
		return;
	}
	Hero* nowHero = (Hero*)(this->getParent()->getChildByTag(9845)->getChildByTag(478));
	if (nowHero->money < 3500)
	{
		auto labLevel = Label::create("your money is not enough", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("your money is not enough");
	}
	else
	{
		nowHero->money -= 3500;
		nowHero->damage += 3;
		gameScene::equipmentAmount++;
		auto newEquipment = Sprite::create("PicsArt_06-09-10.56.00.jpg");
		allEquipment.pushBack(newEquipment);
		this->getParent()->addChild(newEquipment);
		setEquipmentPosition();
	}
}
void Shop::buyEquipment03(Ref* obj)
{
	if (gameScene::equipmentAmount == 6)
	{
		auto labLevel = Label::create("Your equipment inventory is full", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("max");
		return;
	}
	Hero* nowHero = (Hero*)(this->getParent()->getChildByTag(9845)->getChildByTag(478));
	if (nowHero->money < 3000)
	{
		auto labLevel = Label::create("your money is not enough", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("your money is not enough");
	}
	else
	{
		nowHero->money -= 3000;
		nowHero->maxhp += 3;
		nowHero->damage += 2;
		gameScene::equipmentAmount++;
		auto newEquipment = Sprite::create("PicsArt_06-09-10.55.32.jpg");
		allEquipment.pushBack(newEquipment);
		this->getParent()->addChild(newEquipment);
		setEquipmentPosition();
	}
}

void Shop::setEquipmentPosition()
{;
	for (int i = 0; i < allEquipment.size(); i++)
	{
		auto newEquipment = allEquipment.at(i);

		if (i == 0)
		{
			newEquipment->setPosition(Vec2(600, 125));
		}
		if (i == 1)
		{
			newEquipment->setPosition(Vec2(670, 125));
		}
		if (i == 2)
		{
			newEquipment->setPosition(Vec2(740, 125));
		}
		if (i == 3)
		{
			newEquipment->setPosition(Vec2(600, 55));
		}
		if (i == 4)
		{
			newEquipment->setPosition(Vec2(670, 55));
		}
		if (i == 5)
		{
			newEquipment->setPosition(Vec2(740, 55));
		}
	}
}





//Skill* newSkill = Skill::create();
//switch (Hero::judgeSkill)
//{
//case 1:
//
//	auto skillFirePicture = Sprite::create("wsparticle_super01.png");
//	skillFirePicture->setAnchorPoint(Vec2(0.5, 0));
//	skillFirePicture->setTag(21574);
//	//skillFirePicture->setRotation(ang);
//	//skillFirePicture->setPosition(Vec2(x, y));
//	newSkill->setRotation(ang);
//	newSkill->setPosition(Vec2(x, y));
//	newSkill->addChild(skillFirePicture);
//	float howfar = Vec2(x, y).getDistance(Vec2(dx, dy));
//	float time = howfar / 1000;
//	auto move = MoveTo::create(time, Vec2(dx, dy));
//	auto act2 = CallFunc::create(CC_CALLBACK_0(Skill::killMe, newSkill));
//	newSkill->runAction(Sequence::create(move, act2, NULL));
//	break;
//}
//return newSkill;



void Shop::buyEquipment04(Ref* obj)
{
	if (gameScene::equipmentAmount == 6)
	{
		auto labLevel = Label::create("Your equipment inventory is full", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("max");
		return;
	}
	Hero* nowHero = (Hero*)(this->getParent()->getChildByTag(9845)->getChildByTag(478));
	if (nowHero->money < 450)
	{
		auto labLevel = Label::create("your money is not enough", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("your money is not enough");
	}
	else
	{
		nowHero->money -= 450;
		nowHero->damage += 1;
		gameScene::equipmentAmount++;
		auto newEquipment = Sprite::create("PicsArt_06-11-11.39.45.jpg");
		allEquipment.pushBack(newEquipment);
		this->getParent()->addChild(newEquipment);
		setEquipmentPosition();
	}
}
void Shop::buyEquipment05(Ref* obj)
{
	if (gameScene::equipmentAmount == 6)
	{
		auto labLevel = Label::create("Your equipment inventory is full", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("max");
		return;
	}
	Hero* nowHero = (Hero*)(this->getParent()->getChildByTag(9845)->getChildByTag(478));
	if (nowHero->money < 2600)
	{
		auto labLevel = Label::create("your money is not enough", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("your money is not enough");
	}
	else
	{
		nowHero->money -= 2600;
		nowHero->attack_speed /= 2;
		gameScene::equipmentAmount++;
		auto newEquipment = Sprite::create("PicsArt_06-11-11.39.18.jpg");
		allEquipment.pushBack(newEquipment);
		this->getParent()->addChild(newEquipment);
		setEquipmentPosition();
	}
}
void Shop::buyEquipment06(Ref* obj)
{
	if (gameScene::equipmentAmount == 6)
	{
		auto labLevel = Label::create("Your equipment inventory is full", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("max");
		return;
	}
	Hero* nowHero = (Hero*)(this->getParent()->getChildByTag(9845)->getChildByTag(478));
	if (nowHero->money < 1100)
	{
		auto labLevel = Label::create("your money is not enough", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("your money is not enough");
	}
	else
	{
		nowHero->money -= 1100;
		nowHero->attack_speed /= 1.5;
		nowHero->speed += 50;
		gameScene::equipmentAmount++;
		auto newEquipment = Sprite::create("PicsArt_06-11-11.38.48.jpg");
		allEquipment.pushBack(newEquipment);
		this->getParent()->addChild(newEquipment);
		setEquipmentPosition();
	}

}


void Shop::buyEquipment07(Ref* obj)
{
	if (gameScene::equipmentAmount == 6)
	{
		auto labLevel = Label::create("Your equipment inventory is full", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("max");
		return;
	}
	Hero* nowHero = (Hero*)(this->getParent()->getChildByTag(9845)->getChildByTag(478));
	if (nowHero->money < 450)
	{
		auto labLevel = Label::create("your money is not enough", "Marker Felt", 20);
		labLevel->setPosition(Point(500, 300));
		this->getParent()->getParent()->addChild(labLevel);
		labLevel->setTag(89474651);
		CCFadeOut* delay = CCFadeOut::create(1.5);
		Action* act = Sequence::create(delay,
			CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
		labLevel->runAction(act);
		CCLOG("your money is not enough");
	}
	else
	{
		nowHero->money -= 450;
		nowHero->maxhp += 10;
	
		gameScene::equipmentAmount++;
		auto newEquipment = Sprite::create("PicsArt_06-11-11.38.26.jpg");
		allEquipment.pushBack(newEquipment);
		this->getParent()->addChild(newEquipment);
		setEquipmentPosition();
	}

}