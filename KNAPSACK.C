#include<stdio.h>
#include<conio.h>
struct ks
{
 char id[5];
 int p;
 int w;
 float x;
 float profit_value;
}s[20],temp;
void main()
{
  int n,i,j,rm,m;
  float profit=0;
  clrscr();
  printf("\nEnter NO.of items:");
  scanf("%d",&n);
  printf("Enter maximum weight of the knapsack:");
  scanf("%d",&m);
  printf("Enter item ids:");
  for(i=1;i<=n;i++)
  {
   scanf("%s",s[i].id);
  }
  printf("Enter profits:");
  for(i=1;i<=n;i++)
  {
    scanf("%d",&s[i].p);
  }
  printf("Enter weights:");
  for(i=1;i<=n;i++)
  {
    scanf("%d",&s[i].w);
  }
  for(i=1;i<=n;i++)
  {
    s[i].x=0;
  }
  for(i=1;i<=n;i++)
  {
    s[i].x=(float)s[i].p/s[i].w;
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(s[j].x<s[j+1].x)
      {
	temp=s[j];
	s[j]=s[j+1];
	s[j+1]=temp;
      }
    }
  }
  printf("items:");
  for(i=1;i<=n;i++)
  {
    printf("%s\t",s[i].id);
  }
  printf("\nProfits:");
  for(i=1;i<=n;i++)
  {
    printf("%d\t",s[i].p);
  }
  printf("\nWeights:");
  for(i=1;i<=n;i++)
  {
    printf("%d\t",s[i].w);
  }
  printf("\np/w value:");
  for(i=1;i<=n;i++)
  {
    printf("%.2f\t",s[i].x);
  }
  rm=m;
  i=1;
  while(i<=n && rm>0)
  {
    if(rm>=s[i].w)
    {
      s[i].profit_value=1;
      rm=rm-s[i].w;

    }
    else
    {
      s[i].profit_value=(float)rm/s[i].w;
      rm=rm-rm;
    }
    i++;
  }
  for(i=1;i<=n;i++)
  {
   for(j=i;j<n-i+1;j++)
   {
     if(strcmp(s[j],s[j+1])>0)
     {
       temp=s[j];
       s[j]=s[j+1];
       s[j+1]=temp;
     }
   }
  }
  printf("\nprofit values:");
  for(i=1;i<=n;i++)
  {
    printf("%.1f\t",s[i].profit_value);
  }

  for(i=1;i<=n;i++)
  {
    profit=profit+s[i].p*s[i].profit_value;
  }
  printf("\nThe total profit=%.2f",profit);

  getch();
}