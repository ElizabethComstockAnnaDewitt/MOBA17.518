#ifndef  ARMOR
#define  ARMOR

#include"Enemy.h"
#include "cocos2d.h"
USING_NS_CC; 
class soldier;
class Armor :public Enemy
{
public:
	CREATE_FUNC(Armor);
	static Armor *createone(float x,float y,int armorType);
	float speed;
	void suicide();
	//�Ƕ�����
	bool isFrozen;
	Enemy* father;
	//��ײ���
	void UPDATE();
	void check();
};


#endif