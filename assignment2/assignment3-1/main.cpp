# include <iostream>
# include "human.h"//for human obj header
# include "monster.h"//for monster obj header
# include "job.h"//for job header
using namespace std;
Human* node_insert_Human(Human* h_head, Human* h_data)//make human node list
{
	Human* Cur;//for Cur
	Cur = h_head;
	h_data->next = NULL;
	if (h_head == NULL)//if list is empty
	{
		h_data->prev = NULL;
		h_head = h_data;	
		return h_head;//make header and returning
	}
	else//if list is not empty
	{
		while (Cur != NULL)//iterate list untill NULL
		{
			if (Cur->next == NULL)//if list's final node
			{
				h_data->prev = Cur;
				Cur->next = h_data;
				break;
			}
			Cur = Cur->next;
		}
		return h_head;//return head address
	}
}
Human* node_delete_Human(Human* h_head)//for delete human list node
{
	Human* Cur = h_head;//Cur has head node address
	Human* tmp = NULL;//for human temporarly
	while (Cur != NULL)
	{
		if (Cur->health == 0)//node for deleting
		{
			tmp = Cur->prev;
			if (tmp == NULL)//case for head node health ==0
			{
				if (Cur->next == NULL)//delete
				{
					h_head = NULL;
					Cur = NULL;
					break;
				}
				else//delete
				{
					h_head = Cur->next;
					h_head->prev = NULL;
				}
			}
			else//delete
			{

				if (Cur->next == NULL)
				{
					Cur->prev->next = NULL;
					Cur = NULL;
					break;
				}
				else
				{
					Cur->next->prev = tmp;
					tmp->next = Cur->next;
				}
			}
		}
		Cur = Cur->next;
	}
	return h_head;
}
Monster* node_insert_Monster(Monster* m_head,Monster* m_data)//make monster node list
{
	Monster* Cur;//for Cur
	Cur = m_head;
	m_data->next = NULL;
	if (m_head == NULL)//if list is empty
	{
		m_data->prev = NULL;
		m_head = m_data;
		return m_head; // make header and returning
	}
	else//if list is not empty
	{
		while (Cur != NULL)//iterate list untill NULL
		{
			if (Cur->next == NULL)//if list's final node
			{
				m_data->prev = Cur;
				Cur->next = m_data;
				break;
			}
			Cur = Cur->next;
		}
		return m_head;
	}
}
Monster* node_delete_Monster(Monster* m_head)//for monster node delete
{
	Monster* Cur = m_head;//Cur for iterate 
	Monster* tmp = NULL;
	while (Cur != NULL)
	{
		if (Cur->health == 0)//if dead node catch
		{
			tmp = Cur->prev;
			if (tmp == NULL)//case for head node health ==0
			{
				if (Cur->next == NULL)//delete
				{
					m_head = NULL;
					Cur = NULL;
					break;
				}
				else//delete
				{
					m_head = Cur->next;
					m_head->prev = NULL;
				}
			}
			else//delete
			{
				if (Cur->next == NULL)//delete
				{
					Cur->prev->next = NULL;
					Cur = NULL;
					break;
				}
				else//delete
				{
					Cur->next->prev = tmp;
					tmp->next = Cur->next;
				}
			}
		}
		Cur = Cur->next;
	}
	return m_head;
}
void Battle(Human* h, Monster* m)//function for Battle
{
	Human* h_Cur = NULL;
	Monster* m_Cur = NULL;
	Human* h_t = NULL;
	Monster* m_t = NULL;
	Human* Cur1 = NULL;
	Monster* Cur2 = NULL;
	int h_count = 0, m_count = 0;//for human and monster counter
	int count = 1;
	while (1)
	{
		h_Cur = h;
		m_Cur = m;
		h_t = h;
		m_t = m;
		while (h_Cur != NULL)//human camp case
		{
			if (h_Cur->index == 5)//if warlock
			{
				h_Cur->action(m);//warlock case
			}
			else
			{
				m_t = h_Cur->closest_monster(m);//find closest monster
				h_Cur->action(m_t);
			}
			h_Cur = h_Cur->next;
		}
		while (m_Cur != NULL)//monster camp case
		{
			h_t = m_Cur->closest_human(h);//find closest human
			m_Cur->action(h_t);
			m_Cur = m_Cur->next;
		}
		/*
		while (h_t != NULL)//loop for human node list counting
		{
			h_t = h_t->next;
			h_count = h_count + 1;
		}
		while (m_t != NULL)//loop for monster node list counting
		{
			m_t = m_t->next;
			m_count = m_count + 1;
		}
		if (h_count == m_count)//human and monster count same
		{
			while (h_Cur != NULL && m_Cur != NULL)//loop for each turn
			{
				if (h_Cur->index == 5)//if warlock
				{
					h_Cur->action(m);
				}
				else
				{
					m_t = h_Cur->closest_monster(m);
					h_Cur->action(m_t);
				}
				h_t = m_Cur->closest_human(h);
				m_Cur->action(h_t);
				h_Cur = h_Cur->next;
				m_Cur = m_Cur->next;
			}
		}
		else if (h_count > m_count)//if human list bigger than monster list
		{
			while (h_Cur != NULL)//loop human cur
			{
				if (h_Cur->index == 5)
				{
					h_Cur->action(m);
				}
				else
				{
					m_t = h_Cur->closest_monster(m);
					h_Cur->action(m_t);
				}
				if (m_Cur != NULL)
				{
					h_t = m_Cur->closest_human(h);
					m_Cur->action(h_t);
					m_Cur = m_Cur->next;
				}
				h_Cur = h_Cur->next;
			}
		}
		else if (h_count < m_count)//if monster list is bigger than human list
		{
			while (m_Cur != NULL)//loop monster list
			{
				if (h_Cur != NULL)
				{
					if (h_Cur->index == 5)
					{
						h_Cur->action(m);
					}
					else
					{
						m_t = h_Cur->closest_monster(m);
						h_Cur->action(m_t);
					}
					h_Cur = h_Cur->next;
				}
				h_t = m_Cur->closest_human(h);
				m_Cur->action(h_t);
				m_Cur = m_Cur->next;
			}
		}*/
		h_count = 0;
		m_count = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	/*	Cur1 = h;
		Cur2 = m;
		cout << "Human case: " << endl;
		while (Cur1 != NULL)
		{
			cout << Cur1->index << "->  health:" << Cur1->health << "  Column: " << Cur1->column << "  Row:  " << Cur1->row << endl;
			Cur1 = Cur1->next;
		}
		cout << endl;
		cout << "Monster case" << endl;
		while (Cur2 != NULL)
		{
			cout << Cur2->index << "->  health:" << Cur2->health << "  Column: " << Cur2->column << "  Row:  " << Cur2->row << endl;
			Cur2 = Cur2->next;
		}
		cout <<"-----------------------------------------------------------------------"<< endl;*/
	///////////////////////////////////////////////////////////////////////////////////////////////////////////	
		
		Cur1 = h;
		Cur2 = m;
		cout << "#### Result of round "<<count<<" ####" << endl;//for printing result
		count = count + 1;
		cout << "<Human>" << endl;//printing human result
		while (Cur1 != NULL)
		{
			if (Cur1->health == 0)
			{
				Cur1 = Cur1->next;//if human health 0 than skip printing 
				continue;
			}
			cout << Cur1->index << endl;//print human info
			Cur1 = Cur1->next;
		}
		cout << "<Monster>" << endl;//for printing monster
		while (Cur2 != NULL)
		{
			if (Cur2->health == 0)//if moster health 0 than skip printing 
			{
				Cur2 = Cur2->next;
				continue;
			}
			cout << Cur2->index << endl;//print monster info
			Cur2 = Cur2->next;
		}
		Cur1 = h;
		Cur2 = m;
		while (Cur1 != NULL)//loop for print which human was killed
		{
			if (Cur1->health == 0)//print health is 0 human
			{
				cout << "Human " << Cur1->index << " has " << "died" << endl;
			}
			Cur1 = Cur1->next;
		}
		while (Cur2 != NULL)//loop for print which monser was killed
		{
			if (Cur2->health == 0)//print health is 0 monster
			{
				cout << "Monster " << Cur2->index << " has " << "died" << endl;
			}
			Cur2 = Cur2->next;
		}
		h = node_delete_Human(h);//delete human node killed
		m = node_delete_Monster(m);//delete monster node killed
		cout << endl;
		if (h == NULL || m == NULL)//if finally mosnter list or human list empty
		{
			if (h == NULL && m != NULL)//case for monster win
			{
				cout << "#### Final result of battle ####" << endl;
				cout << "Human has been defeated" << endl;
				break;
			}
			else if (h != NULL && m == NULL)//case for human win
			{
				cout << "#### Final result of battle ####" << endl;
				cout << "Monster has been defeated" << endl;
				break;
			}
			else if (h == NULL && m == NULL)//case for draw
			{
				cout << "#### Final result of battle ####" << endl;
				cout << "Battle was drawed" << endl;
				break;
			}
		}
	}
	
}
int main(void)
{
	Human* H_Head = NULL;
	Monster* M_Head = NULL;
	Peasant_Army P(1,0,0);//make peasant node
	H_Head = node_insert_Human(H_Head, &P);
	Sword_Master S1(2,1,0);//make sword node
	H_Head = node_insert_Human(H_Head, &S1);
	Sword_Master S2(3,2,0);//make sword node
	H_Head = node_insert_Human(H_Head, &S2);
	Archer A(4,3,0);//make archer node
	H_Head = node_insert_Human(H_Head, &A);
	Warlock W(5,4,0);//make warlock node
	H_Head = node_insert_Human(H_Head, &W);
	Monster M1('A',0,4);//make monster node
	M_Head = node_insert_Monster(M_Head, &M1);
	Monster M2('B',1,4);//make monster node
	M_Head = node_insert_Monster(M_Head, &M2);
	Monster M3('C',2,4);//make monster node
	M_Head = node_insert_Monster(M_Head, &M3);
	Monster M4('D',3,4);//make monster node
	M_Head = node_insert_Monster(M_Head, &M4);
	Monster M5('E',4,4);//make monster node
	M_Head = node_insert_Monster(M_Head, &M5);
	Battle(H_Head,M_Head);//call Battle func
	return 0;
}

