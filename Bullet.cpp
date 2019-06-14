#include "Bullet.h"
bool Bullet::init()
{
	if (!Node::init())
		return false;
	return true;
}
Bullet* Bullet::createBullet(int t,double ang,int x, int y,int dx,int dy)
{
	Bullet* newb = Bullet::create();
	switch (t)
	{
	case 1:
		Sprite* spbullet = Sprite::create("button_green.9.png");
		newb->bx = x;
		newb->by = y;
		newb->setPosition(x, y);
		spbullet->setRotation(-(ang-90.0));
	/*	CCLOG("nowRotation%lf", spbullet->getRotation());
		CCLOG("Bullet%lf", ang);*/
		newb->addChild(spbullet);
		newb->objx = dx;
		newb->objy = dy;

		break;
	}
	float howfar = Vec2(x, y).getDistance(Vec2(dx, dy));
	float time = howfar / 1000;
	auto act1 = MoveTo::create(time, Vec2(dx, dy));
	auto act2 = CallFunc::create(CC_CALLBACK_0(Bullet::killMe ,newb));
	newb->runAction(Sequence::create(act1, act2, NULL));

	return newb;
}
void Bullet::killMe()
{
	this->removeFromParent();
}