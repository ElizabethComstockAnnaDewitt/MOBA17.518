#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include"cocos2d.h"
USING_NS_CC;
class character :public Node
{
public:
	CREATE_FUNC(character);
	bool init();
	int nowhp;//��ǰ����ֵ
	int maxhp;//�������ֵ
	int damage;//������ 
	int magic_resist;//ħ��
	int armor_resist;//����
	int speed;//�ƶ��ٶ�
	int attack_speed;//�����ٶ�
	void death();//����
};
#endif // !_CHARACTER_H_
