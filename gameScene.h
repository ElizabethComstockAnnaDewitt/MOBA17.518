#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_
#include"cocos2d.h"
#include "Bullet.h"
USING_NS_CC;
class gameScene :public Scene
{
public:
	bool init();
	CREATE_FUNC(gameScene);
	static Scene* createscene();
	virtual bool onMouseDown(Event* event);
	virtual void onMouseMove(Event* event);
	virtual void onMouseUp(Event* event);
	virtual void onMouseScroll(Event* event);
	void click(int x, int y);//鼠标点击动画
	void killme(Node* pSender);//删除自己
	static float ex;
	static float ey;
	double angle;
	void update(float t);
	static Vector<Bullet*> allbullet;
	float tx, ty;
	void skillsSlector();
	float HeroSkillx, HeroSkilly;
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	float tnx;//位移标记坐标
	float tny;
	int Intermediate_variable;//技能3中间变量
	float skill3x;
	float skill3y;
	void inventory();
	static int equipmentAmount;
	void skillUpgrade();
	int upgradeTag;
	int lastLevel;
	bool a, b;
};

#endif


