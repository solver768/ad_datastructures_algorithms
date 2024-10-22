#include<stdio.h>
#include<conio.h>
int a[50][50],visited[50],s[50];
int top=-1;
int n,i,j,st,v;
void DFS();
int pop();
void push(int);
void main()
{
 clrscr();
 printf("\nEnter number of vertices in a graph:");
 scanf("%d",&n);
 printf("\nEnter adjacency matrix representation of a graph:\n");
 for(i=1;i<=n;i++)
 {
   for(j=1;j<=n;j++)
   {
     scanf("%d",&a[i][j]);
   }
 }
 for(i=1;i<=n;i++)
 {
   visited[i]=0;
 }
 printf("\nEnter the starting vertex to DFS traversal:");
 scanf("%d",&st);
 push(st);
 printf("\nDFS traversal of graph:");
 DFS();
 getch();
}
void DFS()
{
   while(top!=-1)
   {
     v=pop();
     if(visited[v]==0)
     {
       visited[v]=1;
       printf("%d",v);
       for(i=1;i<=n;i++)
       {
	  if(a[v][i]==1)
	  {
	     if(visited[i]==0)
	     {
		push(i);
	     }
	  } //if
       }   //for
     }  //if
   }  //while
}//DFS

void push(int ele)
{
 top++;
 s[top]=ele;
}

int pop()
{
 if(top==-1)
 {
   printf("\nstack is empty");
   return 0;
 }
 v=s[top];
 top--;
 return v;
}