#include "Skill.h"
#include "Hero.h"
#include "cocos2d.h"
USING_NS_CC;
bool Skill::init()
{
	if (!Node::init())
		return false;
	return true;
}
Skill* Skill::createSkill(double ang, float x, float y, float dx, float dy)
{
	Skill* newSkill = Skill::create();
	if(Hero::judgeSkill==1)
	{
		auto skillFirePicture = Sprite::create("wsparticle_super01.png");
		skillFirePicture->setAnchorPoint(Vec2(0.5, 0));
		skillFirePicture->setTag(21574);
		//skillFirePicture->setRotation(ang);
		//skillFirePicture->setPosition(Vec2(x, y));
		newSkill->setRotation(ang);
		newSkill->setPosition(Vec2(x, y));
		newSkill->addChild(skillFirePicture);
		float howfar = Vec2(x, y).getDistance(Vec2(dx, dy));
		float time = howfar / 1000;
		auto move = MoveTo::create(time, Vec2(dx, dy));
		auto act2 = CallFunc::create(CC_CALLBACK_0(Skill::killMe, newSkill));
		newSkill->runAction(Sequence::create(move, act2, NULL));
	}
	if (Hero::judgeSkill == 3)
	{

	}
	return newSkill;
}
void Skill::killMe()
{
	this->removeFromParent();
}


//void Hero::skillFire(int t,double ang)
//{
//	switch (t)
//	{
//	case 1:
//		auto skillFirePicture=Sprite::create("wsparticle_super01.png");
//		skillFirePicture->setAnchorPoint(Vec2(0.5, 0));
//		skillFirePicture->setTag(21574);
//		this->getParent()->addChild(skillFirePicture);
//		skillFirePicture->setPosition(this->getPosition());
//		skillFirePicture->setRotation(-(ang - 90.0 - angle + 90.0));
//		auto move = MoveTo::create(0.5,Vec2(gameScene::ex, gameScene::ey));
//		auto act2 = CallFunc::create(CC_CALLBACK_0(Bullet::killMe, skillFirePicture));
//		newb->runAction(Sequence::create(move, act2, NULL));
//		break;
//
//	}
//}
//
//auto act2 = CallFunc::create(CC_CALLBACK_0(Bullet::killMe, newb));
//newb->runAction(Sequence::create(act1, act2, NULL));
//
//
//void Bullet::killMe()
//{
//	this->removeFromParent();
//}