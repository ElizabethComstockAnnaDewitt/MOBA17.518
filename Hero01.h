#ifndef __HAN_BIN_H__
#define __HAN_BIN_H__
#include "Hero.h"
#include "cocos2d.h"
USING_NS_CC;
class Hero01 :public Hero
{
public:
	CREATE_FUNC(Hero01);
	bool init();
	static Hero01* createHero01();
	

};
#endif // !__HAN_BIN_H__
