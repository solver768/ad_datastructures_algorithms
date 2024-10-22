#include<stdio.h>
#include<conio.h>
int max(int,int);
int knapsack(int,int[],int[],int);
void main()
{
 int i, n,m,wt[20],profit[20];
 printf("Enter no. of objects:");
 scanf("%d",&n);
 printf("Enter profits:");
 for(i=0;i<n;i++)
 {
   scanf("%d",&profit[i]);
 }
 printf("Enter weights:");
 for(i=0;i<n;i++)
 {
   scanf("%d",&wt[i]);
 }
 printf("Enter knapsack weight:");
 scanf("%d",&m);
 printf("Maximum profit value=%d",knapsack(m,wt,profit,n));
 getch();
}
int max(int a,int b)
{
 return (a>b)?a:b;
}
int knapsack(int m,int wt[],int val[],int n)
{
  int k[10][10],i,j;
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=m;j++)
    {
       if(i==0 || j==0)
       {
	 k[i][j]=0;
       }
       else if(wt[i-1]<=j)
       {
	k[i][j]=max((val[i-1]+k[i-1][j-wt[i-1]]),k[i-1][j]);
       }
       else
       {
	k[i][j]=k[i-1][j];
       }
    }
  }
  return k[n][m];
}

