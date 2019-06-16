#include"SelectMenu.h"
#include "gameScene.h"
USING_NS_CC;
int SelectMenu::Hero_type=0;
bool SelectMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(SelectMenu::menuCloseCallback, this));

	closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));




	/*

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


	*/
	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Select your hero", "fonts/arial.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height);

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("u=2922613058,2830050605&fm=26&gp=0.jpg");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize / 2) + origin);

	// add the sprite as a child to this layer
	this->addChild(sprite,-1);

	auto drawNode = DrawNode::create();
	drawNode->setPosition(Vec2(0, 0));
	addChild(drawNode);

	Rect safeArea = Director::getInstance()->getSafeAreaRect();
	drawNode->drawRect(safeArea.origin, safeArea.origin + safeArea.size, Color4F::BLUE);




	//ÐÂÔö²Ëµ¥
	auto gameitem = MenuItemFont::create("start", CC_CALLBACK_1(SelectMenu::menuCloseCallback, this));
	gameitem->setPosition(Point(origin.x + visibleSize.width / 2, 200));
	closeItem->setTag(10);
	gameitem->setTag(11);
	auto menu = Menu::create(closeItem, gameitem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);





	auto spbt01 = Sprite::create("TPQ@9)%C7(4VI2QWH$NW_3B.jpg");
	auto spbt01_select = Sprite::create("TPQ@9)%C7(4VI2QWH$NW_3B.jpg");
	spbt01_select->setScaleX(1.1);
	auto mitem01 = MenuItemSprite::create(spbt01, spbt01_select, CC_CALLBACK_1(SelectMenu::slectHero01, this));
	mitem01->setTag(99901);
	auto menuShop01 = Menu::create(mitem01, nullptr);
	menuShop01->setTag(99902);
	menuShop01->setPosition(Vec2(450, 550));
	this->addChild(menuShop01);


	auto spbt02 = Sprite::create("8OZK~Y5Z6%7HZB]43`%QGGR.jpg");
	auto spbt02_select = Sprite::create("8OZK~Y5Z6%7HZB]43`%QGGR.jpg");
	spbt02_select->setScaleX(1.1);
	auto mitem02 = MenuItemSprite::create(spbt02, spbt02_select, CC_CALLBACK_1(SelectMenu::slectHero02, this));
	mitem02->setTag(99901);
	auto menuShop02 = Menu::create(mitem02, nullptr);
	menuShop02->setTag(99902);
	menuShop02->setPosition(Vec2(550, 550));
	this->addChild(menuShop02);



	auto spbt03 = Sprite::create("A(0KCDZXRNJU`RPY@0%BC}7.jpg");
	auto spbt03_select = Sprite::create("A(0KCDZXRNJU`RPY@0%BC}7.jpg");
	spbt03_select->setScaleX(1.1);
	auto mitem03 = MenuItemSprite::create(spbt03, spbt03_select, CC_CALLBACK_1(SelectMenu::slectHero03, this));
	mitem03->setTag(99901);
	auto menuShop03 = Menu::create(mitem03, nullptr);
	menuShop03->setTag(99902);
	menuShop03->setPosition(Vec2(650, 550));
	this->addChild(menuShop03);

	auto labelSlect = Label::createWithTTF("your hero", "fonts/arial.ttf", 24);
	this->addChild(labelSlect);
	labelSlect->setPosition(Vec2(100, 500));
	return true;
}

Scene * SelectMenu::createscene()
{
	auto scene = Scene::create();
	auto layer = SelectMenu::create();
	scene->addChild(layer);
	return scene;
}

void SelectMenu::menuCloseCallback(Ref * sender)
{
	MenuItem* nowitem = (MenuItem*)sender;
	/*switch (nowitem->getTag())
	{
	case 10:
		Director::getInstance()->end();
		break;
	case 11:
		Director::getInstance()->replaceScene(gameScene::createscene());
		break;
	}*/
	if (nowitem->getTag() == 10)
	{
		Director::getInstance()->end();
	}
	if (nowitem->getTag() == 11)
	{
		if (SelectMenu::Hero_type == 0)
		{
			auto labLevel = Label::create("You have not chosen a hero", "Marker Felt", 20);
			labLevel->setPosition(Point(500, 300));
			this->addChild(labLevel);
			labLevel->setTag(89474651);
			CCFadeOut* delay = CCFadeOut::create(1.5);
			Action* act = Sequence::create(delay,
				CCCallFuncN::create(labLevel, callfuncN_selector(gameScene::killme)), NULL);
			labLevel->runAction(act);
		}
		else
		{
			Director::getInstance()->replaceScene(gameScene::createscene());

		}
	}
}
void SelectMenu::slectHero01(Ref* obj)
{
	SelectMenu::Hero_type = 1;
	auto herop = Sprite::create("TPQ@9)%C7(4VI2QWH$NW_3B.jpg");
	herop->setPosition(Vec2(100, 400));
	this->addChild(herop);
}
void SelectMenu::slectHero02(Ref* obj)
{
	SelectMenu::Hero_type = 2;
	auto herop = Sprite::create("8OZK~Y5Z6%7HZB]43`%QGGR.jpg");
	herop->setPosition(Vec2(100, 400));
	this->addChild(herop);
}
void SelectMenu::slectHero03(Ref* obj)
{
	SelectMenu::Hero_type = 3;
	auto herop = Sprite::create("A(0KCDZXRNJU`RPY@0%BC}7.jpg");
	herop->setPosition(Vec2(100, 400));
	this->addChild(herop);
}

