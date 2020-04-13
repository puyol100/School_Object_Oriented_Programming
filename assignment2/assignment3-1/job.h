#pragma once
# include "human.h"//including human header
# ifndef _JOB_H
# define _JOB_H
class Peasant_Army :public Human//define peasant
{
public:
	Peasant_Army(int idx, int r, int c);
	~Peasant_Army();
};
class Sword_Master : public Human//define sword master
{
public:
	Sword_Master(int idx, int r, int c);
	~Sword_Master();
};
class Archer : public Human//define archer
{
public:
	Archer(int idx, int r, int c);
	~Archer();
	virtual void action(class Monster* m);//override action 
};
class Warlock : public Human//define Warlock
{
	bool mana;//mana for Warlock magic cool time
public:
	Warlock(int idx, int r, int c);
	~Warlock();
	virtual void action(class Monster* m);//override action
};
# endif