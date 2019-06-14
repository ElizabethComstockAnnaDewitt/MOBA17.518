#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include"cocos2d.h"
USING_NS_CC;
class character :public Node
{
public:
	CREATE_FUNC(character);
	bool init();
	int nowhp;//当前生命值
	int maxhp;//最大生命值
	int damage;//攻击力 
	int magic_resist;//魔抗
	int armor_resist;//护甲
	int speed;//移动速度
	int attack_speed;//攻击速度
	void death();//死亡
};
#endif // !_CHARACTER_H_
