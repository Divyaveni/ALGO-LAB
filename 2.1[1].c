#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node* left;
	int data;
	struct Node* right;
};
struct Node*root=NULL;

struct Node* insert(struct Node* root,int key)
{
	struct Node*ptr,*new,*save;
	new=(struct Node*)malloc(sizeof(struct Node));
	new->left=NULL;
	new->right=NULL;
	new->data=key;

	if(root==NULL)
	{
		root=new;
	}
	else
	{
		save=root;
		ptr=root;
		while(ptr!=NULL)
		{
		    save=ptr;
			if(ptr->data >key) ptr=ptr->left;
			else ptr=ptr->right;
		}
		if(key<save->data)
			save->left = new;
		else
			save->right = new;
	}
	return root;
}


struct Node* search(int key)
{
	int f=0;
	struct Node*ptr;
	if(root==NULL)
	{
		printf("Empty");
		return root;
	}
	else
	{
		ptr=root;
		while(ptr!=NULL)
		{
		    if(ptr->data==key)
		    {
		       f=1;
		       break;
		    }
		    else if(key>ptr->data)
		       ptr=ptr->right;
		    else
		       ptr=ptr->left;
		 }
	}
	f==1?printf("Element %d Is Found",key):printf(" Element %d Is Not Found",key);
}

int main()
{

	int d;
	printf("press -1 to stop");
	printf("\nEnter the elements>>");
	scanf("%d",&d);
	while(d!=-1)
	{

		root=insert(root,d);
		printf("\nEnter the elements>>");
		scanf("%d",&d);
	}

	printf("\nEnter to search>>");
	scanf("%d",&d);
	search(d);
	return 0;
}
