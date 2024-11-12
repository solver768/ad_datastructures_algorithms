#include<stdio.h>
#include<conio.h>
int w[20],p[20],i,j;
int n,m;
int y[20],x[20],fp=-1,fw;
void knapsack(int,float,float);
float bound(float,float,int);
void show();
void main()
{

   printf("\nEnter no. of objects:");
   scanf("%d",&n);
   printf("\nEnter weights of objects:");
   for(i=1;i<=n;i++)
     scanf("%d",&w[i]);
   printf("\nEnter profits of objects:");
   for(i=1;i<=n;i++)
     scanf("%d",&p[i]);
   printf("\nEnter weight of knapsack:");
   scanf("%d",&m);
   printf("The sack is arranged in the order\n");
   knapsack(0,0.0,0.0);
   show();
   getch();
}
void knapsack(int k,float cp,float cw)
{
  if(cw+w[k]<=m)
  {
     y[k]=1;
     if(k<n)
     {
       knapsack(k+1,cp+p[k],cw+w[k]);
     }
     if(((cp+p[k])>fp) && (k==n))
     {
       fp=cp+p[k];
       fw=cw+w[k];
       for(j=1;j<=k;j++)
       {
	  x[j]=y[j];
       }
     }
  }
  if ( bound(cp,cw,k)>=fp)
  {
    y[k]=0;
    if(k<=n)
    {
       knapsack(k+1,cp,cw);
    }
    if((cp>fp)&&(k==n))
    {
      fp=cp;
      fw=cw;
      for(j=1;j<=k;j++)
      {
	 x[j]=y[j];
      }
    }
  }
}
float bound(float cp,float cw,int k)
{
  float b=cp;
  float c=cw;
  for(i=k+1;i<=n;i++)
  {
     c=c+w[i];
     if(c<m)
     {
       b=b+p[i];
     }
     else
     {
       return (b+(1-(c-m)/(float)w[i]*p[i]));
     }
  }
  return b;
}
void show()
{
  float s=0.0;
  printf("\n\tItem\tweight\tcost\tselect");
  for(i=1;i<=n;i++)
  {
    printf("\n\t%d\t%d\t%d\t%d",i,w[i],p[i],x[i]);
  }
  printf("\n\nThe scak now holds following items:");
  for(i=1;i<=n;i++)
  {
     if(x[i]==1)
     {
       printf("%d\t",i);
       s+=(float)p[i]*(float)x[i];
     }
  }
  printf("\nMaximum profit:%f",s);
}