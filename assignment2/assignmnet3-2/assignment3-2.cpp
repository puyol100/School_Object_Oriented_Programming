# include <iostream>
# include <string.h>
# include <fstream>
# include "CacheNode.h"
# include "CacheManager.h"
using namespace std;

int main(void)
{
	char* str;//for keep file input
	CacheNode* Cach;
	CacheManager Manager;

	ifstream ifs("Sentences.txt");//open file of seteneces .txt
	while (!ifs.eof())//read file
	{
		str = new char[100];
		ifs >> str;//input from file
		for (int i = 0;; i++)
		{
			if (str[i + 1] == '\0')//if that is last line of string
			{
				if (str[i] == '.')
				{
					str[i] = '\0';
				}
				break;
			}
		}
		Cach = new CacheNode(str);//make node
		Manager.lingking(Cach);//for linking and printing
	}
	ifs.close();
	return 0;
}