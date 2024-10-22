#include<stdio.h>
#include<conio.h>
void mergesort_divide(int[],int,int);
void mergesort_merge(int[],int,int,int);
int main()
{
  int a[20],i,n;
  printf("\n Enter no of elements to be sorted:");
  scanf("%d",&n);
  printf("\nEnter array elements:\n");
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  mergesort_divide(a,0,n-1);
  printf("\nAfter sorting:\n");
  for(i=0;i<n;i++)
  {
  printf("%d\t",a[i]);
  }
  printf("\n");
  getch();
  return 0;
}
void mergesort_divide(int a[],int first,int last)
{
  int mid;
  if(first<last)
  {
   mid=(first+last)/2;
   mergesort_divide(a,first,mid);
   mergesort_divide(a,mid+1,last);
   mergesort_merge(a,first,mid,last);
   }
}
void mergesort_merge(int a[],int first,int mid,int last)
{
  int i,j,index,temp[20],k;
  i=first;
  j=mid+1;
  while(i<=mid &&j<=last)
  {
    if(a[i]<=a[j])
    {
      temp[index]=a[i];
      i++;
      index++;
    }
    if(a[i]>=a[j])
    {
      temp[index]=a[j];
      j++;
      index++;
    }
    }
/*    if(a[i]==a[j])
    {
      temp[index]=a[i];
      i++;
      index++;
      temp[index]=a[j];
      j++;
      index++;
    } */

  if(i>=mid)
  {
    while(j<=last)
    {
     temp[index]=a[j];
      j++;
      index++;
    }
  }
  if(j>=last)
  {
   while(i<=mid)
   {
     temp[index]=a[i];
     i++;
     index++;
   }
  }
  k=first;
  while(k<index)
  {
     a[k]=temp[k];
     k++;
  }
}