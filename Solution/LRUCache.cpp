#include"LRUCache.h"
#include<map>
#include<mutex>

using namespace std;

LRUNode::LRUNode(int key, int value)
{
	pref = next = NULL; this->key = key; this->value = value;
}


LRUCache::LRUCache(int capacity)
{
	//lruMaps=new lruMaps();
	this->_capacity = capacity;
	_head = _tail = NULL;
}

int LRUCache::get(int key)
{
	if (lruMaps.count(key)<1) return -1;
	LRUNode *node = lruMaps[key];
	UpdateNode(node);
	return node->value;
}

void LRUCache::set(int key, int value)
{
	if (lruMaps.count(key)<1)
	{
		if (lruMaps.size() >= _capacity)
		{
			lruMaps.erase(_tail->key);
			DeleteNode();
		}
		LRUNode *node = new  LRUNode(key, value);
		lruMaps.insert(map<int, LRUNode*>::value_type(key, node));
		AddNode(node);
	}
	else
	{
		lruMaps[key]->value = value;
		UpdateNode(lruMaps[key]);
	}
}

//add node to head
void LRUCache::AddNode(LRUNode *node)
{
	if (NULL == _head) { _head = _tail = node; }
	else { node->next = _head; _head->pref = node; _head = node; }
}
//delete the tail node
void LRUCache::DeleteNode()
{
	if (NULL == _head) { return; }
	else if (_head == _tail) { delete _head; _head = _tail = NULL; }
	else { _tail = _tail->pref; delete _tail->next; _tail->next = NULL; }
}
//move node to head
void LRUCache::UpdateNode(LRUNode *node)
{
	if (node == _head)
	{
		return;
	}
	else
	{
		node->pref->next = node->next;
		if (NULL != node->next) { node->next->pref = node->pref; }
		else { _tail = _tail->pref; }
		node->next = _head; node->pref = NULL;
		_head->pref = node;
		_head = node;
	}
}