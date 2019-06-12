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
	void click(int x, int y);//���������
	void killme(Node* pSender);//ɾ���Լ�
	static float ex;
	static float ey;
	double angle;
	void update(float t);
	static Vector<Bullet*> allbullet;
	float tx, ty;
	void skillsSlector();
	float HeroSkillx, HeroSkilly;
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	float tnx;//λ�Ʊ������
	float tny;
	int Intermediate_variable;//����3�м����
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


