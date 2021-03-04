#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *left;
    int data;
    struct node *right;
};


struct node* newNode (int key)
{
    struct node* new = (struct node *) malloc( sizeof(struct node) );
    new->data = key;
    new->left =NULL;
    new->right = NULL;
    return new;
}


struct node* constructTreeUtil (int pre[], int post[], int* preIndex, int l, int h, int size )
{

    if (*preIndex >= size || l > h)
        return NULL;
    struct node* root = newNode ( pre[*preIndex] );
    ++*preIndex;
    if (l == h)
        return root;
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;
    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil (pre, post, preIndex, i + 1, h, size);
    }
    return root;
}


struct node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}


void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}


int main ()
{
	int d,k=0;
	int pre_order[20],post_order[20];
    printf("Enter PreOrder[Press -1 to exit]:\nEnter the elements>>");
    scanf("%d",&d);
    while(d!=-1)
    {
    	pre_order[k++]=d;
    	printf("\nEnter the elements>>");
    	scanf("%d",&d);
    }
    printf("Enter PostOrder[Press -1 to exit]:\nEnter>>");
    scanf("%d",&d);
    while(d!=-1)
    {
    	post_order[k++]=d;
    	printf("\nEnter the elements>>");
    	scanf("%d",&d);
    }

    int size1 = sizeof( pre_order ) / sizeof( pre_order[0] );
    int size2 = sizeof( post_order ) / sizeof( post_order[0] );
    if(size1!=size2) printf("Invalid Traversal");
    else
    {
    	struct node *root = constructTree(pre_order, post_order, size1);
    	printf("Inorder traversal of the constructed tree: \n");
    	printInorder(root);
    }
    return 0;
}
