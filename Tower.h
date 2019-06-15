
#ifndef  TOWER
#define  TOWER

#include"Enemy.h"
#include"armor.h"
class Tower :public Enemy
{
public:
	CREATE_FUNC(Tower);
	int heroFighting;
	void UPDATE();
	int lastTarget;
	void Attack();
	void shoot(float t);
	Vector<Enemy*> elist;
};
#endif