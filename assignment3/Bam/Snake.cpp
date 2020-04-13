# include "stdafx.h"
# include "Snake.h"
Snake ::Snake()
{
}

SnakeList::SnakeList()
{
	Head = NULL;
	Tail = NULL;
}
void SnakeList::make_big_snake(int x, int y)
{
	Snake* pTemp = Head;
	Snake* n_snake = new Snake;
	n_snake->s_p_x = x;
	n_snake->s_p_y = y;
	if (Head == NULL)
	{
		n_snake->prev = NULL;
		n_snake->next = NULL;
		Head = n_snake;
		Tail = Head;
	}
	else
	{
		n_snake->next = Head;
		n_snake->prev = NULL;
		Head->prev = n_snake;
		Head = n_snake;
	}
	
}