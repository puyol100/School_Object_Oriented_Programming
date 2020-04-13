#pragma once
# include "monster.h"//include monster header
# include <iostream>
using namespace std;
Monster::Monster(char idx, int r, int c)//define constructor
{
	row = r;
	column = c;
	index = idx;
	index = idx;
	health = 20;//monster health
	power = 7;//monster power
}
Monster::~Monster()
{
	health = 0;
	power = 0;
}
Human* Monster::closest_human(Human* h)//find closest human
{
	Human* Cur = h;//give human node list head
	int arr_row[5] = { 0. };
	int arr_column[5] = { 0. };
	int count = 0;
	int closest_index = 0;
	int closest_c = 0;
	int closest_r = 0;
	for (count = 0;; count++)//loop for find not abnomal node and make distance list
	{
		if (Cur->health == 0)//if human health is 0 pass
		{
			arr_row[count] = 100;
			arr_column[count] = 100;
			Cur = Cur->next;
			if (Cur == NULL)
			{
				break;
			}
			continue;
		}
		arr_row[count] = row - Cur->row;//save row distance
		if (arr_row[count] < 0) arr_row[count] = arr_row[count] * (-1);//if distance has - value
		arr_column[count] = column - Cur->column;//save column distance
		if (arr_column[count] < 0) arr_column[count] = arr_column[count] * (-1);//if column has - value
		Cur = Cur->next;
		if (Cur == NULL)
		{
			break;
		}
	}
	closest_c = arr_column[0];
	closest_r = arr_row[0];
	for (int i = 0; i < count+1; i++)//find closest index by row standard 
	{
		if (closest_c > arr_column[i])
		{
			closest_c = arr_column[i];
			closest_r = arr_row[i];
			closest_index = i;
		}
	}
	for (int i = 0; i < count+1; i++)//find closest ndex by column standard
	{
		if (closest_c == arr_column[i])
		{
			if (closest_r > arr_row[i])
			{
				closest_c = arr_column[i];
				closest_r = arr_row[i];
				closest_index = i;
			}
		}
	}
	///////////////////////////////////find closest value//////////////////////////
	Cur = h;
	for (int i = 0; i < closest_index; i++)
	{
		Cur = Cur->next;
	}
	return Cur;
}
void Monster::action(Human* h) // for monster action
{
	if ((h->column >= column - 1 && h->column <= column + 1) && (h->row >= row - 1 && h->row <= row + 1))
	{
			h->health = h->health - power;
			if (h->health <= 0)
			{
				h->health = 0;
			}
		
	} //monster attacked
	else
	{	//////////////case for monster move
		if (column != h->column)
		{
			if (column > h->column)
			{
				column = column - 1;
			}
			else
			{
				column = column + 1;
			}
		}
		else
		{
			if (row > h->row)
			{
				row = row - 1;
			}
			else
			{
				row = row + 1;
			}
		}
	}
}