#include<stdio.h>
#include<conio.h>
int a[50][50],visited[50];
int Q[50],front=-1,rear=-1;
int i,j,n,st,v;
void BFS();
void enqueue(int);
int dequeue();
void main()
{
   clrscr();
   printf("\nEnter number of elements in the graph:");
   scanf("%d",&n);
   printf("\nEnter adjacency matrix representation of a graph:");
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
   printf("\nEnter the starting vertex for BFS traversal:");
   scanf("%d",&st);
   enqueue(st);
   printf("\nBFS traversal of the graph:");
   BFS();
   getch();
}
void BFS()
{
  while(front!=-1 && rear!=-1)
  {
   v=dequeue();
   if(visited[v]==0)
   {
     visited[v]=1;
     printf("%d\t",v);
     for(i=1;i<=n;i++)
     {
       if(a[v][i]==1)
       {
	  if(visited[i]==0)
	  {
	    enqueue(i);
	  }
       } //if
     } //for
   }   //if
  }   //while
}//BFS

void enqueue(int ele)
{
 if(front==-1 && rear==-1)
 {
   front++;
   rear++;
   Q[rear]=ele;
 }
 else
 {
   rear++;
   Q[rear]=ele;
 }
}

int dequeue()
{
  if(front==-1 &&rear==-1)
  {
    printf("\nQueue is empty");
    return 0;
  }
  else
  {
   if(front==rear)
   {
     v=Q[front];
     front=rear=-1;
   }
   else
   {
     v=Q[front];
     front++;
   }
  }
  return v;
}