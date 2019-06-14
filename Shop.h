#ifndef __SHOP_H__
#define __SHOP_H__
#include "cocos2d.h"
USING_NS_CC;
class Shop :public Node
{
public:
	CREATE_FUNC(Shop);
	bool init();
	static Shop* createShop();
	void buyEquipment01(Ref* obj);
	void buyEquipment02(Ref* obj);
	void buyEquipment03(Ref* obj);
	void buyEquipment04(Ref* obj);
	void buyEquipment05(Ref* obj);
	void buyEquipment06(Ref* obj);
	void buyEquipment07(Ref* obj);
	void setEquipmentPosition();
	Vector<Sprite*> allEquipment;

};
#endif // !__SHOP_H__


