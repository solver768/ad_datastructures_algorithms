/*name:p.v.s.l.deepthi
date:6,aug,2024
program description:"AVLOP.c" is a file with the program is written in c language to build a avl tree
with the help of input elements in another file of name "AVLin.c" and it's operations based on
the rotations for imbalance occurs during deletion and insertion operations*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lchild,*rchild;
    int height;
}*new,*root,*ptr,*ptr1,*ptr2,*ptr3,*ptr5,*ptr6,*ptr7,*aptr,*bptr,*pptr;
struct node *insertion(struct node*,int);
struct node *deletion(struct node*,int);
struct node *rotation_LL(struct node*);
struct node *rotation_LR(struct node*);
struct node *rotation_RR(struct node*);
struct node *rotation_RL(struct node*);
int BF(struct node*);
int compute_height(struct node*);
void inorder(struct node*);
void main ()
{
    int c,ch,x;
    FILE *FP1,*FP2;
    clrscr();
    root=NULL;

    FP1=fopen("avlinput.txt","r");
    if(FP1==NULL)
    {
	printf("\nflie cannot be open");
    }
    else
    {
	while(feof(FP1)==0)
	{
	    fscanf(FP1,"%d",&c);
	  //  printf("%d",c);
	    root=insertion(root,c);
	}
	inorder(root);
    }
	while(1)
	{
	    printf("\nOptions:\n1.insertion 2.deletion 3.inorder traversal 4. wrtie to file 5.exit\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		case 1:printf("\nEnter value to insert:");
		       scanf("%d",&x);
		       insertion(root,x);
		       break;
		case 2:printf("Enter value to delete:");
		       scanf("%d",&x);
		       deletion(root,x);
		       break;
		case 3:printf("inorder traversl");
		       inorder(root);
		       break;
      //	case 4:
	//       break;
		case 5:
		       exit(0);
	       default:
		       printf("Enter valid option");
	    } //switch
	}//whlie
}//main
//insertion
struct node *insertion(struct node*ptr,int value)
{
    if(ptr==NULL)
    {
	new=malloc(sizeof(struct node));
	new->data=value;
	new->height=1;
	new->lchild=NULL;
	new->rchild=NULL;
	ptr=new;
	printf("\nNode is inserted");
	return ptr;
    }
    if(ptr->data==value)
      {
	printf("\nNode already exist");
	return ptr;
    }
    else if(ptr->data>value)
    {
	ptr->lchild=insertion(ptr->lchild,value);
	if(BF(ptr)==2)
	{
	    if(value<ptr->lchild->data)
	    {
		printf("\nLL insertion");
		ptr=rotation_LL(ptr);
	    }
	    else if(value>ptr->lchild->data)
	    {
		printf("\nLR insertion");
		ptr=rotation_LR(ptr);
	    }
	}
    }

    else if(value>ptr->data)
    {
	ptr->rchild=insertion(ptr->rchild,value);
	if(BF(ptr)==-2)
	{
	    if(value<ptr->rchild->data)
	    {
		printf("\nRL insertion");
		ptr=rotation_RL(ptr);
	    }
	    else if(value>ptr->rchild->data)
	    {
		printf("\nRR insertion");
		ptr=rotation_RR(ptr);
	    }
	}
    }
    ptr->height=compute_height(ptr);
    return ptr;
}
struct node *rotation_LL(struct node *pptr)
{
    aptr=pptr->lchild;
    pptr->lchild=aptr->rchild;
    aptr->rchild=pptr;
    pptr->height=compute_height(pptr);
    aptr->height=compute_height(aptr);
    pptr=aptr;
    return pptr;
}

struct node *rotation_RR(struct node *pptr)
{
    bptr=pptr->rchild;
    pptr->rchild=bptr->lchild;
    bptr->lchild=pptr;
    pptr->height=compute_height(pptr);
    bptr->height=compute_height(bptr);
    pptr=bptr;
    return pptr;
}
struct node* rotation_LR(struct node *ptr1)
{
    aptr=ptr1->lchild;
    ptr1->lchild=rotation_RR(aptr);
    ptr1=rotation_LL(ptr1);
    return ptr1;
}

struct node* rotation_RL(struct node *ptr1)
{
    bptr=ptr1->rchild;
    ptr1->rchild=rotation_LL(bptr);
    ptr1=rotation_RR(ptr1);
    return ptr1;
}
int compute_height(struct node*ptr5)
{
    int hl,hr;
    if(ptr5==NULL)
    {
	return 0;
    }
    if(ptr5->lchild==NULL)
    {
	hl=0;
    }
    else
    {
	hl=1+compute_height(ptr5->lchild);
    }
    if(ptr5->rchild==NULL)
    {
	hr=0;
    }
    else
    {
	hr=1+compute_height(ptr5->rchild);
    }
    if(hl>hr)
    {
	return hl;
    }
    else
    {
	return hr;
    }
}
int BF(struct node *ptr6)
{
    int hr,hl;
    if(ptr6==NULL)
    {
	return 0;
    }
    if(ptr6->lchild==NULL)
    {
	hl=0;
    }
    else
    {
	hl=1+compute_height(ptr6->lchild);
    }
    if(ptr6->rchild==NULL)
    {
	hr=0;
    }
    else
    {
	hr=1+compute_height(ptr6->rchild);
    }
    return (hl-hr);
}
void inorder(struct node *ptr7)
{
    if(ptr7!=NULL)
    {
	inorder(ptr7->lchild);
	printf("\t%d BF(%d)",ptr7->data,BF(ptr7));
	inorder(ptr7->rchild);
    }
}
//deletion
struct node* deletion(struct node*ptr2,int x)
{
    if(ptr2==NULL)
    {
	printf("Required node is not available\n");
	return NULL;
    }
    else if(ptr2->data>x)//left subtree
    {
	ptr2->lchild=deletion(ptr2->lchild,x);
	if(BF(ptr2)==-2)
	{
	    if(BF(ptr2->rchild)==0)
	    {
	       printf("L0 imbalance\n");
	       ptr2=rotation_RR(ptr2);
	    }
	    else if(BF(ptr2->rchild)==-1)
	    {
	       printf("L-1 imbalance\n");
	       ptr2=rotation_RR(ptr2);
	    }
	    else if(BF(ptr2->rchild)==1)
	    {
	       printf("L1 imbalance\n");
	       ptr2=rotation_RL(ptr2);
	    }
	}
    }
    else if(ptr2->data<x)//right subtree
    {
	ptr2->rchild=deletion(ptr2->rchild,x);
	if(BF(ptr2)==2)
	{
	   if(BF(ptr2->lchild)==0)
	   {
	       printf("R0 imbalance");
	       ptr2=rotation_LL(ptr2);
	   }
	   else if(BF(ptr2->lchild)==1)
	   {
	       printf("R1 imbalance");
	       ptr2=rotation_LL(ptr2);
	   }
	   else if(BF(ptr2->lchild)==-1)
	   {
	       printf("R-1 imbalance");
	       ptr2=rotation_LR(ptr2);
	   }
	}
    }
    else
    {
	if(ptr2->lchild==NULL && ptr2->rchild==NULL)
	{
	   ptr2=NULL;
	   return NULL;
	}
	else if(ptr2->rchild==NULL)
	{
	   ptr2=ptr2->lchild;
	   ptr2->lchild=NULL;
	   printf("Node is deleted");
	   return ptr2;
	}
	else if(ptr2->lchild==NULL)
	{
	   ptr2=ptr2->rchild;
	   ptr2->rchild=NULL;
	   printf("Node is deleted");
	   return ptr2;
	}
	else if(ptr2->rchild!=NULL && ptr2->lchild!=NULL)
	{
	   ptr3=ptr2->rchild;
	   if(ptr3->lchild==NULL)
	   {
	      ptr2=ptr2->rchild;
	   }
	   else
	   {
	      while(ptr3->lchild!=NULL)
	     {
	       ptr3=ptr3->lchild;
	     }
	     ptr2->data=ptr3->data;//replaced data
	     ptr2->rchild=deletion(ptr2->rchild,ptr3->data);//deleted last node in left
	     printf("Required node is deleted");
	     if(BF(ptr2)==2)
	     {
	       if(BF(ptr2->lchild)==0)
	       {
		  printf("R0 imbalance");
		  ptr2=rotation_LL(ptr2);
	       }
	       else if(BF(ptr2->lchild)==1)
	       {
		  printf("R1 imbalance");
		  ptr2=rotation_LL(ptr2);
	       }
	       else if(BF(ptr2->lchild)==-1)
	       {
		  printf("R-1 imbalance");
		  ptr2=rotation_LR(ptr2);
	       }
	     }//end if
	   }//else
	}

     /*	if(ptr2->rchild!=NULL)
	{
	   ptr3=ptr2->rchild;
	   while(ptr3->lchild!=NULL)
	   {
	       ptr3=ptr3->lchild;
	   }
	   ptr2->data=ptr3->data;//replaced data
	   ptr2=deletion(ptr2->rchild,ptr3->data);//deleted last node in left
	   printf("Required node is deleted");
	   if(BF(ptr2)==2)
	   {
	       if(BF(ptr2->lchild)==0)
	       {
		  printf("R0 imbalance");
		  ptr2=rotation_LL(ptr2);
	       }
	       else if(BF(ptr2->lchild)==1)
	       {
		  printf("R1 imbalance");
		  ptr2=rotation_LL(ptr2);
	       }
	       else if(BF(ptr2->lchild)==-1)
	       {
		  printf("R-1 imbalance");
		  ptr2=rotation_LR(ptr2);
	       }
	   }//end if
	}  */
	else
	{
	   ptr2=ptr2->lchild;
	   return(ptr2->lchild);
	}
     }//end if
     ptr2->height=compute_height(ptr2);
     return ptr2;
}//end deletion