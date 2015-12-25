#pragma once
#include<map>
#include<mutex>
using namespace std;
class  LRUNode
{
public:
	LRUNode *pref;
	LRUNode *next;
	int key;
	int value;

	LRUNode(int key, int value);
};

class LRUCache {
	map<int, LRUNode*>  lruMaps;
	int _capacity;

	LRUNode *_head;
	LRUNode *_tail;

public:
	LRUCache(int capacity);

	int get(int key);

	void set(int key, int value);

private:
	//add node to head
	void AddNode(LRUNode *node);
	//delete the tail node
	void DeleteNode();
	//move node to head
	void UpdateNode(LRUNode *node);
};