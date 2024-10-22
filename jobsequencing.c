#include<stdio.h>
#include<conio.h>
Struct job
{
  char id[10];
  int d;
  int p;
}s[20],temp;
void JobSequencing(Struct job [],int);
int minValue(int x,int y)
{
 if(x<y)
 return x;
 else
 return y;
}
void main()
{
  int i,j,n;
  clrscr();
  printf("\nEnter no.of jobs:");
  scanf("%d",&n);
  printf("Enter job id's:");
  for(i=1;i<=n;i++)
  {
  scanf("%s",s[i].id);
  }
  printf("Enter deadlines:");
  for(i=1;i<=n;i++)
  {
  scanf("%d",&s[i].d);
  }
  printf("Enter profit values:");
  for(i=1;i<=n;i++)
  {
  scanf("%d",&s[i].p);
  }
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n-i+1;j++)
   {
     if(s[j].p<s[j+1].p)
     temp=s[j];
     s[j]=s[j+1];
     s[j+1]=temp;
   }
  }
  printf("\nJob deadline profits:\n");
  for(i=1;i<=n;i++)
  {
    printf("%s\t%d\t%d\n",s[i].id,s[i].d,s[i].p);
  }
  JobSequencing(s,n);
  getch();
}
void JobSequencing(Struct job a[],int n)
{
  int i,j,k,count=0,maxprofit=0,slot[20],dmax=0;
  for(i=1;i<=n;i++)
  {
    if(s[i].d>dmax)
    {
     dmax=s[i].d;
    }
  }
  for(i=1;i<=dmax;i++)
  {
    slot[i]=-1;
  }
  for(i=1;i<=n;i++)
  {
    k=minValue(dmax,s[i].d)
    while(k>=1)
    {
      if(slot[k]==-1)
      {
         slot[k]=i;
         count++;
         break;
      }
      k--;
   }
   if(count==dmax)
   {
     break;
   }
  }
  printf("\nOptimal solution sequence of jobs:");
  for(i=1;i<=dmax;i++)
  {
    printf("%s",a[slot[i]].id);
    if(i<dmax)
    {
      printf("-->");
    }
  }
  for(i=1;i<=dmax;i++)
  {
     maxprofit+=a[slot[i]].p;
  }
  printf("\nMaximum profit=%d",maxprofit);
}