#include "Hero01.h"
//#include "cocos2d.h"
//USING_NS_CC;

bool Hero01::init()
{
	if (!Hero::init())
		return false;
	return true;
}
Hero01* Hero01::createHero01()
{
	Hero01* nowHero = Hero01::create();
	nowHero->speed = 500;
	nowHero->setPosition(Vec2(60, 60));
	/*Sprite* nowHeroPicture = Sprite::create("wsparticle_test_001.png");
	nowHeroPicture->setPosition(nowHero->getPosition());*/
	return nowHero;
}