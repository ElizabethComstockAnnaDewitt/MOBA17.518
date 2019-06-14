#include "Hero02.h"
//#include "cocos2d.h"
//USING_NS_CC;

bool Hero02::init()
{
	if (!Hero::init())
		return false;
	return true;
}
Hero02* Hero02::createHero02()
{
	Hero02* nowHero = Hero02::create();
	nowHero->speed = 500;
	nowHero->setPosition(Vec2(100, 100));
	/*Sprite* nowHeroPicture = Sprite::create("wsparticle_test_001.png");
	nowHeroPicture->setPosition(nowHero->getPosition());*/
	return nowHero;
}