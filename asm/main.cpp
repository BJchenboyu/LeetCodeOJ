#include <stdio.h>
void _stdcall print(int a,int b)
{
	printf("\d  \d",a,b);
}
void main()
{
	int i=0,j=0;
	print(j=i,++i);
}