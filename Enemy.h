
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
	//������
	bool frozed;
	bool frozedJustNow;
	int expValue;
	int moneyValue;
	//ԭ��Ӧ�������ࣨ��������
	int exp;
	int money;
	//·�����߽���
	int count;
   Enemy *target;
//�ܱ��
	int num;
	//color�����Ӫ��0�� 1��
	int color;
	// ��λ���ͣ�����1 ��2 Ӣ��3 С��4 �ӵ�5
	int type;
	void die();
	void born();
	//�ɶ���̬�ָ�
	void FrozedToNormal(float t);
	//��ʱɾ��
	void delayRemove(float t);
};
struct objs
{
	Vector<Enemy*> list;
};
//���ϵͳ���
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