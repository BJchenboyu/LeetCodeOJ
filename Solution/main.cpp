
#include<iostream>
#include<fstream>
#include<ctime>
#include <cstdio>
#include "Solution.h"
#include "log.h"
#include <algorithm>
#include "LRUCache.h"
using namespace::std;


class MedianFinder {
public:
	vector<int> mem;
	// Adds a number into the data structure.
	void addNum(int num) {
		if(mem.size()==0 || num <= mem[0])
		{
			mem.insert(mem.begin(),num);
			return ;
		}
		else if(num >=mem[mem.size()-1])
		{
			return mem.push_back(num);
		}
		else
		{
			vector<int>::size_type i=findInsertIndex(0,mem.size(),num);
			mem.insert(mem.begin()+i,num);
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if(mem.empty())
			return 0;
		if(mem.size()%2 == 1)
			return mem[mem.size()/2.0];
		else
		{
			return (mem[mem.size()/2-1]+mem[mem.size()/2])/2.0;
		}
	}

private: vector<int>::size_type findInsertIndex(vector<int>::size_type index1,vector<int>::size_type index2,const int num)
		 {
			 if(index1 ==index2)
				 return index1;
			 if(index1 == index2-1)
				 return index2;
			 else if(num <= mem[(index1+index2)/2])
				 return findInsertIndex(index1,(index1+index2)/2,num);
			 else if(num > mem[(index1+index2)/2])
				 return findInsertIndex((index1+index2)/2,index2,num); 
			 else
				 return (index1+index2)/2;
		 }

};

void DestroyList(ListNode *head)
{
	ListNode *p1=head,*next=NULL;
	while (p1)
	{
		next=p1->next;
		delete p1;
		p1=next;
	}
}

class  cl
{
	
public:
	int i;
	cl* thispt()
	{
		return this;
	}
	static int  f (int a, int b)
	{
		return 0;
	}
	int(*Test())(int,int)
	{
		return f;
	}
protected:
private:
};



class alg
{
	int *aa;int n;
public:
	alg(int n)
	{
		this->n=n;
		aa=new int(n);
		while(n--)
		{
			aa[n]=rand();
		}
	}
	void print()
	{		
		cout<<endl;
		for (int i=0;i<n;i++)
		{
			cout<<aa[i]<<' ';
		}
	}
};

void main()
{
	void DestroyList(ListNode *head);
// 	vector<int> nums;
// 	nums.push_back(2);
// 	nums.push_back(7);
// 	nums.push_back(11);
// 	nums.push_back(15);
// 	vector<int> result=Solution::twoSum(nums,9);

// 	ListNode *l1=new ListNode(0);
// 	l1->next=new ListNode(1);
// 	ListNode *l2=new ListNode(0);
// 	l2->next=new ListNode(9);
// 	ListNode *res=Solution::addTwoNumbers(l1,l2);
// 
// 	Destroy(res);
// 	Destroy(l1);
// 	Destroy(l2);

// 	string s("123451678991369");
// 	int max=Solution::lengthOfLongestSubstring(s);

// 	vector<int> v1;
// 	v1.push_back(10000);
// 	vector<int> v2;
// 	v2.push_back(10001);
// 	double res=Solution::findMedianSortedArrays(v1,v2);

// 	string s="ccc";
// 	string str=Solution::longestPalindrome(s);

// 		string src="sfsfagahtrserhjreher";
// 		string res=Solution::convert(src,3);

// 
// 	string s="aa",p=".*";
// 	bool b=Solution::isMatch(s,p);
// 
// 	vector<ListNode *> lists;
// 	lists.push_back(new ListNode(1));
// 	lists[0]->next=new ListNode(2);
// 	lists[0]->next->next=new ListNode(2);
// 
// 	lists.push_back(new ListNode(1));
// 	lists[1]->next=new ListNode(1);
// 	lists[1]->next->next=new ListNode(2);
// 	ListNode *res=Solution::mergeKLists(lists);

// 	MedianFinder mf;double temp;
// 	mf.addNum(0);
// 	mf.addNum(0);
// 	temp=mf.findMedian();
/*	log::writeLog("second");*/

// 
// 	cl *c=new cl();
// 	cl* c2=c->thispt();
// 	int (*p)(int,int)=c->Test();

// 	vector<int> prices;
// 	prices.push_back(6);
// 	prices.push_back(1);
// 	prices.push_back(6);
// 	prices.push_back(4);
// 	prices.push_back(3);
// 	prices.push_back(0);
// 	prices.push_back(2);
// 	prices.push_back(5);
// 	prices.push_back(7);
// 	int max=Solution::maxProfit(1,prices);


// 	bool smaller(int a,int b);
// 	void print(int a);
// 	int ia[]={1,3,5,7,3,2};
// 	sort(ia,ia+sizeof(ia)/sizeof(ia[0]),smaller);
// 	for_each(ia,ia+sizeof(ia)/sizeof(ia[0]),print);

	//vector<alg*> v;
	//v.push_back(new alg(2));
	//v.push_back(new alg(3));
	//v.push_back(new alg(4));
	//for_each(v.begin(),v.end(),mem_fun(&alg::print));


	//LRUCache lruCache(2);
	//lruCache.set(1, 1);
	//lruCache.set(2,2);
	//lruCache.set(3, 3);
	//cout << lruCache.get(1);
	//lruCache.set(2, 4);
	//cout << lruCache.get(2);

	int* twoSum(int* nums, int numsSize, int target);
	int nums[] = { -1};
	twoSum(nums, 3, 6);



//	cout<<clock()<<endl;
}


bool smaller(int a,int b)
{
	return a<b;
}
void print(int a)
{
	cout<<a<<'\t';
}


int* twoSum(int* nums, int numsSize, int target) {
	for (int i = 0; i<numsSize; i++)
	{
		if (nums[i] > target) { continue; }
		for (int j = i + 1; j<numsSize; j++)
		{
			if(nums[j]>target) continue;

			if (nums[i] + nums[j] == target)
			{
				int *ret = (int*)malloc(sizeof(int) * 2);
				*ret = ++i;
				*(ret + 1) = ++j;
				return ret;
			}

		}

	}
	return NULL;
}