#pragma once
# include "human.h"
#ifndef MONSTER_H
#define MONSTER_H
class Monster//define Monster class
{
public:
	int health;
	int power;
	int row;
	int column;
	char index;
	Monster* prev;
	Monster* next;
public:
	Monster(char idx, int r, int c);//constructor
	~Monster();
	void action(class Human* h);//member func for monster action
	Human* closest_human(class Human* h);//member func for find closest human
};
#endif 