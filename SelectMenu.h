#ifndef __SELECT_MENU_H__
#define __SELECT_MENU_H__
#include"cocos2d.h"

USING_NS_CC;
class SelectMenu :Layer
{
public:
	bool init();
	CREATE_FUNC(SelectMenu);
	static Scene* createscene();
	void menuCloseCallback(Ref* sender);
	static int Hero_type;
	void slectHero01(Ref* obj);
	void slectHero02(Ref* obj);
	void slectHero03(Ref* obj);
};

#endif



