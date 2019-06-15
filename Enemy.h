
#ifndef  _ENEMY_H_
#define  _ENEMY_H_

#include "cocos2d.h"
USING_NS_CC;

struct POS
{
	float x;
	float y;
};

class Enemy :public cocos2d::Sprite
{
public:
	float range;
	float damage;
	float speed;
	float originHealth;
	float health;
	int isDead;
	float x;
	float y;
	float ang;
	//被冻僵
	bool frozed;
	bool frozedJustNow;
	int expValue;
	int moneyValue;
	//原本应属于子类（待调整）
	int exp;
	int money;
	//路径行走进度
	int count;
   Enemy *target;
//总编号
	int num;
	//color标记阵营，0蓝 1红
	int color;
	// 单位类型：主城1 塔2 英雄3 小兵4 子弹5
	int type;
	void die();
	void born();
	//由冻僵态恢复
	void FrozedToNormal(float t);
	//延时删除
	void delayRemove(float t);
};
struct objs
{
	Vector<Enemy*> list;
};
//仇恨系统相关
class hatred2:public cocos2d::Node
{
public:
	int hatredValue;
	Enemy* enemy;
};

class hatred1 :public cocos2d::Node {
public:
	int color;
	Vector <hatred2*> mylist;
};
#endif