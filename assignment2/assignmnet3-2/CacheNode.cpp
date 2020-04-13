# include "CacheNode.h"
CacheNode::CacheNode(char* s)//Cache node constructor
{
	str = s;
	Timestamp =0;
	NextNode = NULL;
}
CacheNode::~CacheNode()
{

}
