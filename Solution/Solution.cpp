#include "Solution.h"
#include <map>
#include <utility>
#include <string>
#include <bitset>
#include <set>
#include <algorithm>
using namespace std;
Solution::Solution(void)
{
}


Solution::~Solution(void)
{
}

vector<int> Solution::twoSum(vector<int>& nums,int target)
{
	//vector<int> result;
	// 	if (nums.size()<2)
	// 	{
	// 		return result;
	// 	}
	// 	for (vector<int>::size_type ix1=0;ix1 < nums.size()-1;ix1++)
	// 	{
	// 		for(vector<int>::size_type ix2=ix1+1;ix2 < nums.size();ix2++)
	// 		{
	// 			if( (nums[ix1]+nums[ix2]) == target)
	// 			{
	// 				result.push_back(ix1+1);
	// 				result.push_back(ix2+1);
	// 					return result;
	// 			}
	// 		}
	// 	}
	// 
	// 
	// 	return result;
	//  
	vector<int> results;  
	map<int, vector<int>::size_type> hmap;  
	for(vector<int>::size_type i=0; i<nums.size(); i++)
	{  
		if(!hmap.count(nums[i]))
		{  
			hmap.insert(map<int, vector<int>::size_type>::value_type(nums[i], i));  
		}  
		if(hmap.count(target-nums[i]))
		{  
			vector<int>::size_type n=hmap[target-nums[i]];  
			if(n<i)
			{  
				results.push_back(n+1);  
				results.push_back(i+1);  
				return results;  
			}  
	
		}  
	}  
	return results;  

}


ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *res=NULL,*head=NULL;
	int carryBit=0;
	bool bFst=true;
	while (NULL != l1  ||  NULL!= l2 || carryBit)
	{
			//divede into 3 parts:	NULL!=l1&& NULL !=l2
								//	NULL!=l1&& NULL ==l2
								//	NULL==l1&& NULL !=l2	
		if (bFst)
		{
			head=res=new ListNode(0);
			bFst=false;
		}			
		else
		{
			res->next=new ListNode(0);
			res=res->next;
		}

		int temp=0;
		if (NULL!=l1&& NULL !=l2)
		{
			temp=l1->val+l2->val+carryBit;
			l1=l1->next;l2=l2->next;
		}
		else if(NULL!=l1&& NULL ==l2)
		{
			temp=l1->val+carryBit;
			l1=l1->next;
		}
		else if(NULL==l1&& NULL !=l2)
		{
			temp=l2->val+carryBit;
			l2=l2->next;
		}
		else
		{
			temp=carryBit;
			carryBit=0;
		}
		res->val=temp%10;
		temp>=10 ? carryBit=1:carryBit=0; 
	}
	return head;
}

int Solution::lengthOfLongestSubstring(string s)
{
	string subString;int max=0;
	int ix=-1;
	for (int i=0;i<s.length();i++)
	{
		char ch=s[i];
		if ( (ix=subString.find(ch)) != -1)
		{
			max=subString.length()>max?subString.length():max;

			subString=subString.substr(ix+1);
		}
		subString+=s[i];
	}
	max=subString.length()>max?subString.length():max;
	return max;
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	if(nums2.size() ==0 && nums1.size() ==0 )
	{
		return 0;
	}
	long total=nums1.size()+nums2.size();
	bool flag= total%2 == 1 ? true :false;//true表示奇数个
	int cnt=0;//

	vector<int>::iterator iter1=nums1.begin();
	vector<int>::iterator iter2=nums2.begin();

	int temp=0;
	int oldone=0;
	while (true)
	{
		if (nums1.end() != iter1 && nums2.end() != iter2 )
		{
			temp=*iter1 < *iter2 ? *iter1++ : *iter2++;

			cnt++;

			if(flag && cnt*2 >total)
			{
				return temp;
			}
			else if(!flag && cnt*2 ==total)
			{
				oldone=temp;
			}
			else if(!flag && cnt*2 > total)
			{
				return (oldone+temp)/2.0;
			}
		}
		else if (nums1.end() != iter1 && nums2.end() == iter2)
		{
			if (flag)
			{
				return *(iter1+total/2-cnt);
			}
			else
			{
				if (cnt*2==total)
				{
					return (temp + *(iter1+total/2-cnt) )/2.0;
				}
				else
				{
					return ( *(iter1+total/2-cnt -1) + *(iter1+total/2-cnt) )/2.0;
				}

			}

		}
		else if (nums1.end() == iter1 && nums2.end() != iter2)
		{
			if (flag)
			{
				return *(iter2+total/2-cnt);
			}
			else
			{
				if (cnt*2==total)
				{
					return (temp + *(iter2+total/2-cnt) )/2.0;
				}
				else
				{
					return ( *(iter2+total/2-cnt -1) + *(iter2+total/2-cnt) )/2.0;
				}
			}
		}	
	}
}

string Solution::longestPalindrome(string s) {

	if (s.length()<2)
	{
		return s;
	}

	string strRes="";int max=0;		int offset=0; int temp=0;
	for(int i=0;i<s.length()-1;i++)
	{
		//中轴是字符
		offset=0;
		while(true)
		{
			offset++;
			if ( (i-offset>=0 && i+offset <s.length()) && s[i-offset]==s[i+offset])
			{
				continue;
			}
			else
			{
				offset--;
				if ((temp=offset*2+1)>max)
				{
					max=temp;
					strRes=s.substr(i-offset,max);
				}
				break;
			}
		}
		if (s[i]==s[i+1])
		{//中轴无自符
			offset=0;
			while (true)
			{
				offset++;
				if ( (i-offset>=0 && i+1+offset <s.length()) && s[i-offset]==s[i+1+offset])
				{
					continue;
				}
				else
				{
					offset--;
					if ( (temp=(offset+1)*2) > max )
					{
						max=temp;
						strRes=s.substr(i-offset,max);
					}
					break;
				}
			}
		}
	}
	return strRes;
}

string Solution::convert(string s, int numRows) {

	if(numRows<1)
		return NULL;
	if (1==numRows)
	{
		return s;
	}
	vector<string> lines(numRows,string(s.length()/(numRows-1)+2,0));vector<string>::iterator iterLine=lines.begin();
	vector<string::size_type> ptr(numRows,0);vector<string::size_type>::iterator iterPtr=ptr.begin();
	bool dir=true;//方向
	for(int i=0;i<s.length();i++)
	{
		if (lines.begin()==iterLine)
		{
			dir=true;
		}

		if (dir)
		{
			(*iterLine++)[(*iterPtr++)++]=s[i];
			if (lines.end()==iterLine)
			{
				dir=false;
				iterLine--;iterPtr--;//走错一次方向，两次才能补回来
				iterLine--;iterPtr--;
				continue;
			}
		}
		else
		{
			(*iterLine--)[(*iterPtr--)++]=s[i];
		}

	}
	
	string strRes;
	for (int i=0;i<numRows;i++)
	{
		strRes+=lines[i].c_str();
	}
	return strRes;
}

// string Solution::convert(string s, int numRows)
// {
// 	if(numRows<1)
// 		return NULL;
// 	if (1==numRows)
// 		return s;
// 	vector<string> lines(numRows,"");
// 	int row=-1;int cnt=numRows*2-2;
// 	for(int i=0;i<s.length();i++)
// 	{
// 		row=i%cnt;
// 		if (row<numRows)
// 		{
// 			lines[row]+=s[i];
// 		}
// 		else
// 		{
// 			lines[2*(numRows-1)-row]+=s[i];
// 		}
// 	}
// 
// 	string strRes;
// 	for (int i=0;i<numRows;i++)
// 	{
// 		strRes+=lines[i];
// 	}
// 	return strRes;
// }


bool Solution::isMatch(const string s, const string p)
{//本机上结果没问题，但在leetcode上结果不对
	if('\0'==p[0])//空字符串，有串
		return '\0'==s[0];
	if('*'==p[0])//‘*’前必须有字符
		return false;

	if('*' !=  p[1])//下一个不是'*'，单字符匹配
	{
		if('\0'==s[0])
		{ 
			return false;
		}
		else if('.'==p[0] || s[0]==p[0])
		{
			return isMatch(s.substr(1),p.substr(1));
		}
		else// if(s[0]!=p[0])
		{
			return false;
		}
	}
	else//下一个是'*'
	{
		for(int i=0;i<s.length();i++)
		{
			if( isMatch(s.substr(i),p.substr(2) ) )
				return true;
			if('.'==p[0] || s[i]==p[0])
				continue;
			else
				return false;
		}
	}
}


void deleteEmptyLists(vector<ListNode*>& lists)
{
	for(vector<ListNode*>::iterator iter=lists.begin();iter!=lists.end();iter++)
	{
		if(NULL==*iter)
		{
			iter--;
			lists.erase(iter+1);
		}
	}
}
void quicksortLists(vector<ListNode*>& lists, int low, int high)
{
	if (low >= high) return;

	int i = low;
	int j = high;

	ListNode* temp;
	temp = lists[low];
	while (i<j)
	{
		while ( i < j   &&  (lists[j]->val >= temp->val ) )
		{
			j--;
		}
		lists[i] = lists[j];

		while (i < j && (lists[i]->val <= temp->val))
		{
			i++;
		}
		lists[j] = lists[i];
	}
	lists[i] = temp;
	quicksortLists(lists, low, i - 1);
	quicksortLists(lists, j + 1, high);
}
void sortLists(vector<ListNode*>& lists)
{
	if(lists.size()<2)
		return;
	quicksortLists(lists,0,lists.size()-1);
}
void updateLists(vector<ListNode*>& lists)
{
	if(NULL==lists[0])
	{ 
		lists.erase(lists.begin());
		return;
	}
	if(lists.size()<2)
		return;
	for(vector<ListNode*>::size_type i=0;i<lists.size()-1;i++)
	{
		if( lists[i]->val > lists[i+1]->val )
		{
			ListNode *temp=lists[i];
			lists[i]=lists[i+1];
			lists[i+1]=temp;
			if ( i+2<lists.size() && temp->val < lists[i+2]->val)
			{
				break;
			}
		}
	}
}
ListNode* Solution::mergeKLists(vector<ListNode*>& lists) 
{
	vector<ListNode*> cpylists(lists);
	deleteEmptyLists(cpylists);
	if(cpylists.empty()) return NULL;

	sortLists(cpylists);
	ListNode *res=new ListNode(cpylists[0]->val);
	ListNode *last=res;
	while(true)
	{ 
		if(cpylists.size()<2)
		{
			while(cpylists[0])
			{
				last->next=new ListNode(cpylists[0]->val);
				last=last->next;
				cpylists[0]=cpylists[0]->next;
			}
			break;
		}
		else
		{
			while(cpylists[0])
			{
				last->next=new ListNode(cpylists[0]->val);
				last=last->next;
				cpylists[0]=cpylists[0]->next;
				if (cpylists[0] && cpylists[0]->val <= cpylists[1]->val)
				{
					continue;
				}
				else
				{
					updateLists(cpylists);
					break;
				}
			}
		}		
	}
	return res->next;

}

int Solution::findDuplicate(vector<int>& nums) {
	bitset<INT_MAX> bs;
	for(vector<int>::iterator iter=nums.begin();iter!=nums.end();iter++)
	{
		if(bs[*iter])
			return *iter;
		else
			bs.set(*iter);
	}
	return 0;
}

int maxProfit(const vector<int>& prices) {
	if(prices.size()<2)//zero transaction
		return 0;

	vector<pair<int,int>> through_crest;//the rise part through and crest
	pair<int,int> min_max;
	min_max.first=min_max.second=prices[0];
	bool dir=true;//if dir is true,it means the stock price is rising;false means dropping;invariance won't change; 
	for(vector<int>::const_iterator iter=prices.begin()+1;prices.end()!=iter;iter++)
	{
		if(dir)
		{//last time rise
			if( *iter >= min_max.second)
			{//update the crest    
				min_max.second=*iter;

				if(prices.end()-1==iter)
				{//the last one
					through_crest.push_back(min_max);
					break;
				}
			}
			else if( *iter < min_max.second)
			{//record the crest and update the max profit;change dir;
				through_crest.push_back(min_max);
				dir=false;
				min_max.first=*iter;
			}
		}
		else
		{//last time drop
			if( *iter <= min_max.first)
			{//update the through      
				min_max.first=*iter;
			}
			else if( *iter > min_max.first)
			{//record the through;change dir;
				min_max.second=*iter;
				dir=true;

				if(prices.end()-1==iter)
				{//the last one
					through_crest.push_back(min_max);
					break;
				}
			}
		}
	}
	int profit=0;//find the best profit
	for(vector<pair<int,int>>::const_iterator iter=through_crest.begin();through_crest.end()!=iter;iter++)
	{
		for(vector<pair<int,int>>::const_iterator iter2=iter;through_crest.end()!=iter2;iter2++)
		{
			if( (*iter2).second-(*iter).first > profit )
				profit=(*iter2).second-(*iter).first;
		}
	}
	return profit;
}

int Solution::maxProfit(const vector<int>& prices)
{
	if(prices.size()<2)//zero transaction
		return 0;

	vector<pair<int,int>> through_crest;//the rise part through and crest
	pair<int,int> min_max;
	min_max.first=min_max.second=prices[0];
	bool dir=true;//if dir is true,it means the stock price is rising;false means dropping;invariance won't change; 
	for(vector<int>::const_iterator iter=prices.begin()+1;prices.end()!=iter;iter++)
	{
		if(dir)
		{//last time rise
			if( *iter >= min_max.second)
			{//update the crest    
				min_max.second=*iter;

				if(prices.end()-1==iter)
				{//the last one
					through_crest.push_back(min_max);
					break;
				}
			}
			else if( *iter < min_max.second)
			{//record the crest and update the max profit;change dir;
				through_crest.push_back(min_max);
				dir=false;
				min_max.first=*iter;
			}
		}
		else
		{//last time drop
			if( *iter <= min_max.first)
			{//update the through      
				min_max.first=*iter;
			}
			else if( *iter > min_max.first)
			{//record the through;change dir;
				min_max.second=*iter;
				dir=true;

				if(prices.end()-1==iter)
				{//the last one
					through_crest.push_back(min_max);
					break;
				}
			}
		}
	}


	if(through_crest.size()<=2)
	{   int profit=0;//find the best  two profit
	for(vector<pair<int,int>>::const_iterator iter=through_crest.begin();through_crest.end()!=iter;iter++)
	{
		profit+=(*iter).second-(*iter).first;
	}
	return profit;
	}
	else
	{
		int maxprf=0;
		for(vector<pair<int,int>>::const_iterator iter_mid=through_crest.begin()+1;iter_mid<through_crest.end()-1;iter_mid++)
		{
			int profit=0,profit2=0;//find the best  two profit
			for(vector<pair<int,int>>::const_iterator iter1=through_crest.begin();iter1<=iter_mid;iter1++)
			{
				for(vector<pair<int,int>>::const_iterator iter2=iter1;iter2<=iter_mid;iter2++)
				{
					if( (*iter2).second-(*iter1).first > profit )
					{	
						profit=(*iter2).second-(*iter1).first;
					}
				}
			}
			for(vector<pair<int,int>>::const_iterator iter3=iter_mid+1;through_crest.end()!=iter3;iter3++)
			{
				for(vector<pair<int,int>>::const_iterator iter4=iter3;through_crest.end()!=iter4;iter4++)
				{
					if( (*iter4).second-(*iter3).first > profit2 )
					{	
						profit2=(*iter4).second-(*iter3).first;
					}
				}
			}
			if(profit+profit2>maxprf)
				maxprf=profit+profit2;
		}
		return maxprf;
	}
}

int findMinMax(const vector<int>& prices, vector<int>& minP, vector<int>& maxP)
	{
		int i, len = prices.size(), res = 0;
		for(i=0; i<len-1; i++)
		{
			while(i<len-1 && prices[i+1] <= prices[i]) i++; // detect the local minimum points
			if(i<len-1) minP.push_back(prices[i]);
			else break;
			while(i<len-1 && prices[i+1] >= prices[i]) i++; // detect the local maximum points
			maxP.push_back(prices[i]);
			res +=maxP.back()-minP.back(); // res  = sum(maxP - minP), the maximum margin we can make
		}
		return res;
	}
/*
	int FSM_stock(vector<int>& minP, vector<int>& maxP, int k)
	{
		int states[2][1+2*k], i, j, cur =0, next =1, res =0, numMax = maxP.size();
		fill_n(&states[0][1], 2*k, INT_MIN/2);
		states[0][0] = states[1][0] = 0;

		for(i=0; i<numMax;++i)
		{
			for(j=0; j<k; ++j)  
			{ // only buy at the local minimum points
				states[next][j*2+1] = max(states[cur][j*2+1], states[cur][j*2]-minP[i]); 
				states[next][j*2+2] = states[cur][j*2+2];
			}
			swap(cur, next);
			for(j=1; j<=k; ++j) 
			{ // only sell at the local maximum points
				states[next][j*2] = max(states[cur][j*2], states[cur][j*2-1] + maxP[i]);
				states[next][j*2-1] = states[cur][j*2-1];
			}
			swap(cur, next);
		}
		for(i=1; i<=k;++i) res = max(res, states[cur][i*2]);
		return res;
	}

	int Solution::maxProfit(int k, vector<int>& prices) {

		vector<int> minP, maxP;

		int res = findMinMax(prices, minP, maxP);
		if(maxP.size() <= k) return res;
		else
			return FSM_stock(minP, maxP, k);
	}


	*/