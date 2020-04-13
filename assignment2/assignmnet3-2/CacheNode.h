#pragma once
# include <iostream>
using namespace std;
# ifndef _CASHENODE_H
# define _CASHNODE_H
class CacheNode//define cahe node
{
public:
	char* str;//store the word
	int Timestamp;//stores the timestamp value of the world
	CacheNode* NextNode;//Stores address of next node of the cache linked list 
public:
	CacheNode(char* s);
	~CacheNode();
};
# endif