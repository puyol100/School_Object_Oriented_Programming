# include "CacheManager.h"
# include "CacheNode.h"
CacheManager::CacheManager()//cache manager construuctor
{
	total_node_count = 0;
	total_time = 0;
	HeadNode = NULL;//head node pointer NULL
}
CacheManager::~CacheManager()
{

}
void CacheManager::lingking(CacheNode* n)//for nod linking
{
	int flag = 0;
	int cmp = 0;
	CacheNode* Cur;
	CacheNode* tmp = NULL;
	Cur = HeadNode;
	flag = determination(n);//decide determination node exist
	if (total_node_count != 5)//if total linked node is under five
	{
		if (flag == 0)//there is no same string
		{
			HeadNode = n;
			HeadNode->NextNode = NULL;
			total_node_count = total_node_count + 1;
			cout << "Miss ";
			cout << HeadNode->str << ":" << HeadNode->Timestamp << endl;
		}
		else if (flag == 1)//case for there are same string
		{
			cout << "Hit  ";
			while (Cur != NULL)
			{
				if (stricmp(n->str, Cur->str) == 0)//finde same string node
				{
					break;
				}
				Cur = Cur->NextNode;
			}
				Cur->Timestamp = n->Timestamp;//make Time stamp info
				delete(n);//delete that node
			
			Cur = HeadNode;
			while (Cur != NULL)
			{
				cout << Cur->str << ":" << Cur->Timestamp;
				cout << "  ";
				Cur = Cur->NextNode;
			}
			cout << endl;
		}
		else if (flag == 2)//if that string posioned final node 
		{
			cout << "Miss ";//miss case
			while (Cur->NextNode != NULL)
			{
				Cur = Cur->NextNode;//find final node
			}
			total_node_count = total_node_count + 1;
			n->NextNode = NULL;//add node
			Cur->NextNode = n;
			Cur = HeadNode;
			while (Cur != NULL)//print node
			{
				cout << Cur->str << ":" << Cur->Timestamp;
				cout << "  ";
				Cur = Cur->NextNode;
			}
			cout << endl;
		}
	}
	else//if node list has over five nodes
	{
		if (flag == 0)
		{
			HeadNode = n;
			HeadNode->NextNode = NULL;
			total_node_count = total_node_count + 1;
			cout << "Miss ";
			Cur = HeadNode;
			while (Cur != NULL)
			{
				cout << Cur->str << ":" << Cur->Timestamp;
				cout << "  ";
				Cur = Cur->NextNode;
			}
			cout << endl;
			
		}
		else if (flag == 1)//case for there are same string
		{
			cout << "Hit  ";
			while (Cur != NULL)
			{
				if (stricmp(n->str, Cur->str) == 0)
				{
					break;
				}
				Cur = Cur->NextNode;
			}
				Cur->Timestamp = n->Timestamp;
				delete(n);
			Cur = HeadNode;
			while (Cur != NULL)
			{
				cout << Cur->str << ":" << Cur->Timestamp;
				cout << "  ";
				Cur = Cur->NextNode;
			}
			cout << endl;
		}
		else if (flag == 2)
		{
			cmp = Cur->Timestamp;
			tmp = Cur;
			while(Cur!=NULL)
			{
				if (cmp > Cur->Timestamp)
				{
					cmp = Cur->Timestamp;
					tmp = Cur;
				}
				Cur = Cur->NextNode;
			}
			Cur = HeadNode;
			n->NextNode = tmp->NextNode;
			if (Cur == tmp)//head case
			{
				HeadNode = n;
			}
			else
			{
				while (Cur->NextNode != tmp)
				{
					Cur = Cur->NextNode;

				}
				Cur->NextNode = n;
			}
			delete(tmp);
			cout << "Miss ";
			Cur = HeadNode;
			while (Cur != NULL)
			{
				cout << Cur->str << ":" << Cur->Timestamp;
				cout << "  ";
				Cur = Cur->NextNode;
			}
			cout << endl;
		}
	}
}
int CacheManager::determination(CacheNode* n)//for determination and give node stamps
{
	CacheNode* Cur;
	Cur = HeadNode;
	while (Cur != NULL)
	{
		if (stricmp(n->str, Cur->str) == 0)//if In node list there is same string node
		{
			total_time = total_time + 1;
			n->Timestamp = total_time;//give time stamps
			return 1;//decision value is 1
		}
		Cur = Cur->NextNode;
	}
	Cur = HeadNode;
	while (1)
	{
		if (HeadNode == NULL)//head is NULL
		{
			n->Timestamp = 1;
			total_time = n->Timestamp;//setting basic Head timestamp
			return 0;
		}
		else if (Cur->NextNode == NULL)//if last node case 
		{
			total_time = total_time + 1;
			n->Timestamp = total_time;
			return 2;
		}
		Cur = Cur->NextNode;
	}
}
