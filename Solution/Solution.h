/************************************************************************
����ʱ�䣺2015-10-30 10:06
�༭���²���
���ܣ�leetcode��һ��
  
��һ���޸ģ�
ʱ�䣺2015-10-30 10:36
�༭���²���
Ŀ�ģ����ڵ�һ��ʹ�õ�����ѭ����ʱ�临�ӶȲ�����Ҫ�󣬲ο����ϵ���������Hash����ҵ����ƽ���ʱ�临�Ӷ�

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

