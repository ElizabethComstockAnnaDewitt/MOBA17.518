#ifndef __MOBA_MENU_H__
#define __MOBA_MENU_H__

#include "cocos2d.h"
USING_NS_CC;
class MobaMenu : public Scene
{
public:
	virtual bool init() override;

	static Scene* scene();

	// a selector callback
	void menuCloseCallback(Ref* sender);

	// implement the "static create()" method manually
	CREATE_FUNC(MobaMenu);
};

#endif // __MOBA_MENU_H__

