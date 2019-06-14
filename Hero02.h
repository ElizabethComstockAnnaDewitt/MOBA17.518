#ifndef __HERO_02_H__
#define __HERO_02_H__
#include "Hero.h"
#include "cocos2d.h"
USING_NS_CC;
class Hero02 :public Hero
{
public:
	CREATE_FUNC(Hero02);
	bool init();
	static Hero02* createHero02();


};
#endif // !__HERO_02_H__

