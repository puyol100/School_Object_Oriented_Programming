#pragma once
# include "human.h"//header human
# include <iostream>
using namespace std;
Human::Human()//human constructor
{
	health = 0;
	power =0;
}
Human:: ~Human()
{}
Monster* Human::closest_monster(Monster* m)//find closest monster 
{
	Monster* Cur = m;//give monster node list head
	int arr_row[5] = { 0. };
	int arr_column[5] = { 0. };
	int count = 0;
	int closest_index = 0;
	int closest_c = 0;
	int closest_r = 0;
	for(count = 0;;count++)//loop for find not abnomal node and make distance list
	{
		if (Cur->health == 0)//if monster health is 0 pass
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
		if (closest_c>arr_column[i])
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
	Cur = m;
	for (int i = 0; i < closest_index; i++)
	{
		Cur = Cur->next;
	}
	return Cur;
}
void Human::action(Monster* m)//for human action
{
	///////////case for monster in attack range/////
	if (column == m->column && row == m->row)
	{
		m->health = (m->health) - power;
		if (m->health < 0)
		{
			m->health = 0;
		}
	}
	else if(column -1 == m->column && row == m->row)
	{
		m->health = (m->health) - power;
		if (m->health < 0)
		{
			m->health = 0;
		}
	}
	else if (column + 1 == m->column && row == m->row)
	{
		m->health = (m->health) - power;
		if (m->health < 0)
		{
			m->health = 0;
		}
	}
	else if (column == m->column && row + 1 == m->row)
	{
		m->health = (m->health) - power;
		if (m->health < 0)
		{
			m->health = 0;
		}
	}
	else if (column == m->column && row - 1 == m->row)
	{
		m->health = (m->health) - power;
			if (m->health < 0)
			{
				m->health = 0;
			}
	}//////////////////////////End of attack////////////////////////////
	else
	{//////////////case for move////////////////////////////////
		if (column != m->column)
		{
			if (column > m->column)
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
			if (row > m->row)
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
