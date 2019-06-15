#pragma once

#include"Enemy.h"
#include"Tower.h"
#include"Hero.h"
#include"armor.h"
#include "cocos2d.h"

USING_NS_CC;


class soldier:public Enemy
{
public:
	CREATE_FUNC(soldier);
	void MoveOrAttack(float t);
	void Attack(float t);
	Enemy *FindNewTarget();
	int soldierType;
	int isInTower;
	float searchRange;
	void addtoHatred();
	void inTower();
	void MoveToTarget();
	void specialUpdate();
	float attackRange;
	std::vector<int> path;
	// С����������������
	void beAttacked(Enemy* rival);
	void FindPath();
	void TEST(float t);
void UPDATE();
};