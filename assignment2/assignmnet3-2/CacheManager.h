#pragma once
# include "CacheNode.h"//for define cache manager header
# ifndef _CACHEMANEGER_
# define _CACHEMANEGER_H_
class CacheManager
{
public:
	int total_time;//timestamps
	int total_node_count;//for node count
	CacheNode* HeadNode;//for keep Head node address
public:
	CacheManager();
	~CacheManager();
	int determination(CacheNode* n);//for node delete
	void lingking(CacheNode* n);//for node linking
	
};
# endif