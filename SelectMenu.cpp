#include"SelectMenu.h"
#include "gameScene.h"
USING_NS_CC;
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
	auto sprite = Sprite::create("wsparticle_test_001.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize / 2) + origin);

	// add the sprite as a child to this layer
	this->addChild(sprite);

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
	switch (nowitem->getTag())
	{
	case 10:
		Director::getInstance()->end();
		break;
	case 11:
		Director::getInstance()->replaceScene(gameScene::createscene());
		break;
	}
}

