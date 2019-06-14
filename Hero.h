#ifndef __HERO_H__
#define __HERO_H__
#include "character.h"
#include "cocos2d.h"
USING_NS_CC;
class Hero :public Node
{
public:
	int nowhp;//当前生命值
	int maxhp;//最大生命值
	int damage;//攻击力 
	int speed;//移动速度
	int attack_speed;//攻击速度
	int level;
	int experience;
	double angle;
	CREATE_FUNC(Hero);
	bool init();
	static Hero* createHero(int type);
	Sprite* nowHeroPicture;
	void fire(float t);
	void shot();
	int dx, dy;
	int isFire;
	Hero* target;
	void skillsSlector();
	void selectSkill_01(Ref *obj);
	void selectSkill_02(Ref* obj);
	void selectSkill_03(Ref* obj);
	static int judgeSkill;
	void skillFire(int t,double ang);
	int money;
	void moneyIncreaseBytime(float t);
	void experienceIncreaseBytime(float t);
	int HeroAttackDistance;
	int ht;//英雄类型
	static int skillType;
	void skillUpgrade();
	int skill_1_level;
	int skill_2_level;
	int skill_3_level;
	void skill_1_Upgrade(Ref* obj);
	void skill_2_Upgrade(Ref* obj);
	void skill_3_Upgrade(Ref* obj);

};




#endif // !__HERO_H__
