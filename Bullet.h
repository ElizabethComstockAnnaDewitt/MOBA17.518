#ifndef __BULLET_H__
#define __BULLET_H__
#include "cocos2d.h"
USING_NS_CC;
class Bullet :public Node
{
public:
	int bx, by;
	int objx, objy;//Ä¿±êµã
	int type;
	CREATE_FUNC(Bullet);
	bool init();
	static Bullet* createBullet(int t, double ang, int x, int y, int dx, int dy);
	void killMe();

};
#endif // !__BULLET_H__

