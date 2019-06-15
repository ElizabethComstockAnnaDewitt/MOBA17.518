#ifndef __AI_H__
#define __AI_H__
#include "cocos2d.h"
#include "Hero.h"
#include"armor.h"
USING_NS_CC;

class HeroAI :public Hero
{
public:
	CREATE_FUNC(HeroAI);
	std::vector<int> path;
	int searchRange;
	int count;
	float dir;
    static	HeroAI *createone(int type);
    void MoveOrAttack(float t);
   void Attack(float t);
    Enemy* FindNewTarget();
	void AIConstant(float t);
    void FindPath();
    void MoveToTarget();
   void inTower();
	void skill_01();
	void skill_02();
	void skill_03();
	void skill_04();
	void skill_05();
	void skill_06();
	void skill_07();
	void skill_08();
	void skill_09();
	void UPDATE();
};
#endif