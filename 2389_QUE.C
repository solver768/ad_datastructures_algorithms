#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int board[20],count;
void print(int);
int place(int,int);
void nqueen(int,int);
void main()
{
  int n;
  printf("Enter no. of queens:");
  scanf("%d",&n);
  nqueen(1,n);
}
int place(int k,int i)
{
  int j;
  for(j=1;j<k;j++)
  {
    if(board[j]==i||(abs(board[j]-i)==abs(j-k)))
    {
       return 0;
    }
  }
  return 1;
}
void nqueen(int k,int n)
{
  int i;
  for(i=1;i<=n;i++)
  {
     if(place(k,i))
     {
       board[k]=i;
       if(k==n)
	 print(n);
       else
	 nqueen(k+1,n);
     }
  }
}
void print(int n)
{
  int i,j;
  printf("\n\nSolution%d:\n\n",++count);
  for(i=1;i<=n;i++)
  {
    printf("\t%d",i);
  }
  for(i=1;i<=n;i++)
  {
    printf("\n\n%d",i);
    for(j=1;j<=n;j++)
    {
      if(board[i]==j)
	  printf("\tQ%d",i);
      else
	  printf("\t-");
    }
  }
  exit(0);
}