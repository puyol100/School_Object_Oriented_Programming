#pragma once
# include <stdio.h>
class Snake
{
public:
	int s_p_x;
	int s_p_y;
	Snake* prev;
	Snake* next;
public:
	Snake();
};
class SnakeList
{
public:
	Snake* Head;
	Snake* Tail;
public:
	SnakeList();
	void make_big_snake(int x, int y);

};