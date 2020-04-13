# include "job.h"
# include <iostream>
using namespace std;
Peasant_Army ::Peasant_Army(int idx,int r, int c)//peasant constructor
{
	row = r;
	column = c;
	index = idx;
	health = 5;//health 5
	power = 5;//power 5
};
Peasant_Army ::~Peasant_Army()
{
	health = 0;
	power = 0;
}
Sword_Master::Sword_Master(int idx, int r, int c)//define sword master constructor
{
	row = r;
	column = c;
	index = idx;
	health = 10;//sword master health 10
	power = 10;//sword master power 10
}
Sword_Master::~Sword_Master()
{
	health = 0;
	power = 0;
}
Archer::Archer(int idx, int r, int c)//define archer constructor
{
	row = r;
	column = c;
	index = idx;
	health = 7;//health 7
	power = 10;//power 10
}
Archer::~Archer()
{
	health = 0;
	power = 0;
}
void Archer::action(Monster* m)//define overrided Archer action
{
	/////////////////////case for Archer attack///////////////////////////////////
	if ((column == m->column) &&(m->row <= row + 2 && m->row >= row - 2))
	{
			m->health = m->health - power;
			if (m->health <= 0)
			{
				m->health = 0;
			}
		
	}
	else if ( (m->column == column - 1 || m->column == column + 1) && (m->row <= row + 1 || m->row >= row - 1))
	{
			m->health = m->health - power;
			if (m->health <= 0)
			{
				m->health = 0;
			}
		
	}
	else if ((m->column == column - 2 || m->column == column + 2) &&(m->row == row))
	{
			m->health = m->health - power;
			if (m->health <= 0)
			{
				m->health = 0;
			}
		
	}
	else
	{//////////////case for archer move/////////////////////
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
Warlock::Warlock(int idx, int r, int c)//warlock constructor
{
	row = r;
	column = c;
	index = idx;
	health = 3;//warlock health 3
	power = 10;//power 10
	mana = true;//default mana true
}
Warlock::~Warlock()
{
	health = 0;
	power =  0;
}
void Warlock::action(Monster* m)//define overrided warlock action
{
	
	int count = 0;
	Monster* Cur = m;//Cur for monster iterate
	Monster* closest = NULL;
	closest = closest_monster(m);//find closest monster
	if (mana == true)//case for mana true -> it can attack
	{
		while (Cur != NULL)//because warlock can attack wide area attack so iterate 
		{/////////////////////case for warlock attack////////////////////////////////
			if (column == Cur->column && row == Cur->row)
			{
				Cur->health = (Cur->health) - power;
				if (Cur->health < 0)
				{
					Cur->health = 0;
				}
				count = count + 1;
			}
			else if (column - 1 == Cur->column && row == Cur->row)
			{
				Cur->health = (Cur->health) - power;
				if (Cur->health < 0)
				{
					Cur->health = 0;
				}
				count = count + 1;
			}
			else if (column + 1 == Cur->column && row == Cur->row)
			{
				Cur->health = (Cur->health) - power;
				if (Cur->health < 0)
				{
					Cur->health = 0;
				}
				count = count + 1;
			}
			else if (column == Cur->column && row + 1 == Cur->row)
			{
				Cur->health = (Cur->health) - power;
				if (Cur->health < 0)
				{
					Cur->health = 0;
				}
				count = count + 1;
			}
			else if (column == Cur->column && row - 1 == Cur->row)
			{
				Cur->health = (Cur->health) - power;
				if (Cur->health < 0)
				{
					Cur->health = 0;
				}
				count = count + 1;
			}
			if (count > 3) break;//if count>3 break beacause warlock can't attack more than 4 monseters
			Cur = Cur->next;
		}///////////////////////////////////////End of warlcok attack
		mana = false;//mana false beacuase of attack
		/////////////////////////case for warlock move///////////////////////////
		if(count ==0)
		{/////////////////////////case for warlock move because there is no attack monster in rage///////////////////////////
			if (column != closest->column)
			{
				if (column > closest->column)
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
				if (row > closest->row)
				{
					row = row - 1;
				}
				else
				{
					row = row + 1;
				}
			}
			mana = true;//cool time over
		}
	}
	else////////////////////////////case for mana is on cool time////////////////////////////////////
	{
		if (column != closest->column)
		{
			if (column > closest->column)
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
			if (row > closest->row)
			{
				row = row - 1;
			}
			else
			{
				row = row + 1;
			}
		}
		mana = true;//cool time over
	}//////////////////////////////////End of warlock move//////////////////////////////////////////
}
