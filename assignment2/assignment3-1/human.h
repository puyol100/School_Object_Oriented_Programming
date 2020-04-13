#pragma once
# include "monster.h"//header for monster
# ifndef _HUMAN_H_
# define _HUMAN_H_
class Human//define human class
{
public:
	int health;
	int power;
	int row;
	int column;
	int index;
	Human* prev;
	Human* next;
public:
	Human();
	~Human();
	virtual void action(class Monster* m);//member func for human action
	Monster* closest_monster(class Monster* m);//member func for find closest_monster
};
#endif