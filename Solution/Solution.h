/************************************************************************
创建时间：2015-10-30 10:06
编辑：陈伯羽
功能：leetcode第一题
  
第一次修改：
时间：2015-10-30 10:36
编辑：陈伯羽
目的：由于第一次使用的两重循环，时间复杂度不符合要求，参考网上的做法，用Hash表查找的优势降低时间复杂度

************************************************************************/

#pragma once

#include <vector>
using namespace std;



struct ListNode
{
	int val;
	ListNode *next;

public :
	ListNode(int x):val(x),next(NULL)
	{}
};

class Solution
{
public:
	Solution(void);
	~Solution(void);
	static vector<int> twoSum(vector<int>& nums,int target);

	static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	
	static int lengthOfLongestSubstring(string s);

	static double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

	static string longestPalindrome(string s);

	static string convert(string s, int numRows);

	static bool isMatch(const string s, const string p);

	static ListNode* mergeKLists(vector<ListNode*>& lists);

	static int findDuplicate(vector<int>& nums);

	static int maxProfit(const vector<int>& prices);

	static  int maxProfit(int k, vector<int>& prices);
};

