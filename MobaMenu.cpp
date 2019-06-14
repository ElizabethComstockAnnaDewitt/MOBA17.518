
#include "MobaMenu.h"
#include "SelectMenu.h"

USING_NS_CC;

Scene* MobaMenu::scene()
{
	return MobaMenu::create();
}

// on "init" you need to initialize your instance
bool MobaMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(MobaMenu::menuCloseCallback, this));

	closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));



	auto label = Label::createWithTTF("LOL", "fonts/arial.ttf", 24);

	// position the label on the center of the screen
	label->setPosition(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height);

	// add the label as a child to this layer
	this->addChild(label, 1);

	// add "HelloWorld" splash screen"
	auto sprite = Sprite::create("HelloWorld.png");

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
	auto gameitem = MenuItemFont::create("start", CC_CALLBACK_1(MobaMenu::menuCloseCallback, this));
	gameitem->setPosition(Point(origin.x + visibleSize.width / 2, 200));
	closeItem->setTag(10);
	gameitem->setTag(11);
	auto menu = Menu::create(closeItem, gameitem, nullptr);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);







	return true;
}

void MobaMenu::menuCloseCallback(Ref * sender)
{
	MenuItem* nowitem = (MenuItem*)sender;
	switch (nowitem->getTag())
	{
	case 10:
		Director::getInstance()->end();
		break;
	case 11:
		Director::getInstance()->replaceScene(SelectMenu::createscene());
		break;
	}
}
