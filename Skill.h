#ifndef __SKILL_H__
#define __SKILL_H__
#include "cocos2d.h"
USING_NS_CC;
class Skill :public Node
{
public:
	CREATE_FUNC(Skill);
	bool init();
	static Skill* createSkill( double ang, float x, float y, float dx, float dy);
	static Skill* createSkill_02(double ang, float x, float y, float dx, float dy);
	void killMe();

};
#endif // !__SKILL_H__

