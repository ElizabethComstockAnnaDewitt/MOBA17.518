#include"Armor.h"
//#include "AppMacros.h"
#include "cocos2d.h"
#include"soldiers.h"
USING_NS_CC;
extern int total_num;
extern struct objs towers[2], heros[2], soldiers[2];
extern Sprite* MAP;
Vector<Armor *> armors;
Armor* Armor::createone(float x, float y,int armorType)
{
	Armor* armor = Armor::create();
	auto sprite = Sprite::create("armor.png");
	armor->speed = 150;
	armor->isFrozen = 0;
	armor->type = 5;
	armor->isDead = 0;
	armor->num = total_num + 1;
	total_num++;
	armor->setPosition(Vec2(x, y));
	sprite->setTag(166);
	armor->addChild(sprite);
	if(armorType==1||armorType==3||armorType==4)
	MAP->addChild(armor);

	PhysicsBody* body1;
	if (armorType == 1)
	{
		body1 = PhysicsBody::createBox(Size(15, 22)), 
		armor->damage = 50;
		body1->setPositionOffset(Vec2(0, 0));
	}
	else if (armorType == 2)
	{
		body1 = PhysicsBody::createBox(Size(40, 140));
		armor->damage = 100;
		body1->setPositionOffset(Vec2(0, 0));
	}
	else if (armorType == 3)
	{
		body1 = PhysicsBody::createBox(Size(45, 140));
		armor->damage = 100;
		body1->setPositionOffset(Vec2(0, 0));
	}
	else if (armorType == 4)
	{
		body1 = PhysicsBody::createBox(Size(15, 22));
		armor->isFrozen = 1;
		body1->setPositionOffset(Vec2(0, 0));
	}
	body1->setGroup(1);
	body1->setContactTestBitmask(1);
	body1->setCategoryBitmask(1);
	body1->setCollisionBitmask(1);
	armor->setPhysicsBody(body1);
	return armor;
}

void Armor::suicide()
{
    if(armors.find(this)!=armors.end())
	armors.eraseObject(armors.at(armors.find(this) - armors.begin()));
	this->removeAllChildren();
	this->removeFromParent();
}

void Armor::check()
{
	int i;
	Rect a(this->getPositionX() - 7.5, this->getPositionY() - 11, 15, 22);

	for (i = 0; i < towers[1 - this->color].list.size(); i++)
	{
		if (towers[1 - this->color].list.at(i)->isDead == 0)
		{
			float x = towers[1 - this->color].list.at(i)->getPositionX();
			float y = towers[1 - this->color].list.at(i)->getPositionY();
			float mx = this->getPositionX(), my = this->getPositionY();
			float dis = sqrt((x - mx)*(x - mx) + (y - my)*(y - my));
			if (dis < 80)
			{
				towers[1 - this->color].list.at(i)->health -= this->damage;
				if (towers[1 - this->color].list.at(i)->health <= 0)
				{
					towers[1 - this->color].list.at(i)->die();
					//Ó¢ÐÛ´òµôËþ½±Àø
					if (this->father->type == 3 && this->father->isDead == 0)
						this->father->exp += 300, this->father->money += 300;
				}
				this->suicide();
				return;
			}
		}
	}
}
//	for (i = 0; i < heros[1 - this->color].list.size(); i++)
//	{
//		if (this->getBoundingBox().intersectsRect(heros[1 - this->color].list.at(i)->getBoundingBox()))
//		{
//			heros[1 - this->color].list.at(i)->health -= this->damage;
	//
	//		if (heros[1 - this->color].list.at(i)->health <= 0)
	//		{
	//			heros[1 - this->color].list.at(i)->die();
	//			//Ó¢ÐÛ´òËÀÓ¢ÐÛµÄ½±Àø
	//			if (this->father->type == 3)
	//				this->father->exp += 600, this->father->money += 600;
	//			
	//		}
	//		this->suicide();
	//		return;
	//	}
	//
	//for (i = 0; i < soldiers[1 - this->color].list.size(); i++)
	//	{
	//		float x = soldiers[1 - this->color].list.at(i)->getPositionX();
	//		float y = soldiers[1 - this->color].list.at(i)->getPositionY();
	//		float mx = this->getPositionX(), my = this->getPositionY();
	//		float dis = sqrt((x - mx)*(x - mx) + (y - my)*(y - my));
	//		Rect b(x - 44, y - 44, 88, 88);
	//		if(dis<=3)
	//		{
	//			soldiers[1 - this->color].list.at(i)->health -= this->damage;
	//			//Ó¢ÐÛ´òËÀÐ¡±ø½±Àø
	//			if (soldiers[1 - this->color].list.at(i)->health <= 0)
	//			{
	//				soldiers[1 - this->color].list.at(i)->die();
	//				this->father->exp += 50, this->father->money += 50;
	//			}
	//			else
	//			{
	//				static_cast<soldier*>(soldiers[1 - this->color].list.at(i))->beAttacked(this->father);
	//			}
	//			this->suicide();
	//			return;
	//		}
	//		
	//	}


	void Armor::UPDATE()
	{
		this->check();
	}