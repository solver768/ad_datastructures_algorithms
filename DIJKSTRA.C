#include<stdio.h>
#include<conio.h>
void shortest_path();
int select();
void printpath(int);
int s,n,i,j,k,m,a[10][10],length[15],set[10],path[10];
void main()
{
   clrscr();
   printf("\nEnter number of vertices:");
   scanf("%d",&n);
   printf("\nEnter adjacency matrix representation:");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=n;j++)
      {
	 scanf("%d",&a[i][j]);
      }
   }
   shortest_path();
   printf("\n--------------------------------------------------------------\n");
   printf("Node\t Shortest path\t Path length");
   for(i=1;i<=n;i++)
   {
       if(length[i]==999)
       {
	 printf("\n%d\tNo path\t\t0",i);
       }

       else
       {
	printf("\n%d",i);
	if(i==s)
	{
	  printf("\tNo path\t\t0");
	}
	else
	{
	  printpath(i);
	  printf("\t\t%d",length[i]);
	}
       }

   }
   getch();
}
void shortest_path()
{
 printf("\nEnter the source vertex:");
 scanf("%d",&s);
 for(i=1;i<=n;i++)
 {
    set[i]=0;
 }
 for(i=1;i<=n;i++)
 {
   if(a[s][i]==0)
   {
     length[i]=999;
     path[i]=0;
   }
   else
   {
     length[i]=a[s][i];
     path[i]=s;
   }
 }
 length[s]=0;
 set[s]=1;
 for(m=1;m<=n;m++)
 {
   j=select();
   set[j]=1;
   for(i=1;i<=n;i++)
   {
     if(set[i]!=1)
     {
      if(a[j][i]!=0)
      {
	if(length[j]+a[j][i]<length[i])
	{
	  length[i]=length[j]+a[j][i];
	  path[i]=j;
	}
      }
     }
   }
 }
}
int select()
{
   int minvertex=-1,minlen=999;
   for(k=1;k<=n;k++)
   {
     if(set[k]!=1&&minlen>length[k])
     {
       minlen=length[k];
       minvertex=k;
     }
   }
   return minvertex;
}
void printpath(int i)
{
    printf("\t%d",i);
    while(i!=s)
    {
      i=path[i];
      printf("<--%d",i);
    }
}
