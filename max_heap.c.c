#include<stdio.h>
#include<stdlib.h>
void insertion (int);
void deletion () ;
void display() ;
int a[20], n=0;
void main() 
{
  int ch, x;
  printf("\nenter choice ") ;
  while(1) 
  {
    printf(" 1 2 3 4") ;
    scanf("%d", &ch) ;
    switch(ch) 
    {
      case 1:
         printf("value:");
         scanf("%d", &x) ;
         insertion (x) ;
         break;
     case 2:
     printf("deletion");
         deletion() ;
         break;
     case 3:
          display() ;
          break;
      case 4:
          exit(0) ;
      default:
         printf("\n invalid ") ;
    }
  }
}
void insertion (int ele) 
{
   int i,x,t;
   if(n==20)
   {
      printf("\nNo space to insert");
      return;
    }
    n=n+1;
    a[n]=ele;
    i=n;
    x=i/2;
    while(x>=1 && a[x]<a[i])
    {
        t=a[i];
        a[i]=a[x];
        a[x]=t;
        i=x;
        x=i/2;
    }
}
void deletion()
{
    int x,y,t,i,flag=0;
    printf("deletion function");
    if(n==0)
    {
        printf("\nempty");
        return;
    }
    printf("%d is deleted",a[1]);
    a[1]=a[n];
    n=n-1;
    i=1;
    while(flag==0 && i<=n)
    {
        if(2*i<=n)
        x=2*i;
        else 
        x=-9999;
        if(2*i+1<=n)
        y=2*i+1;
        else 
        y=-9999;
        if(a[i]>=a[x] && a[i]>=a[y])
        flag=1;
        else if(a[i]<a[x] &&a[x]>=a[y])
        {
            t=a[i];
        a[i]=a[x];
        a[x]=t;
        i=2*i;
        }
        else if(a[i]<a[y] &&a[y]>=[x])
        {
            t=a[i];
            a[i]=a[y];
            a[y]=t;
            i=2*i+1;
        }
    }
}
    
 void display()
 {
     int i=1;
     if(n==0)
     {
         printf("\nempty");
         return ;
     }
     printf("\nelements are ");
     for(i=1;i<=n;i++)
     printf("\t%d",a[i]);
     printf("\n");
 }