#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<sstream>
class node
{
    public:
    int data;
    node *left;
    node *right;
};

int A[1000],r=0;
node* newNode (int data)
{
    node* temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node* constructTreeUtil (int pre[], int post[], int* preIndex,
                                int l, int h, int size)
{

    if (*preIndex >= size || l > h)
        return NULL;


    node* root = newNode ( pre[*preIndex] );
    ++*preIndex;


    if (l == h)
        return root;


    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;


    if (i <= h)
    {
        root->left = constructTreeUtil (pre, post, preIndex,
                                                l, i, size);
        root->right = constructTreeUtil (pre, post, preIndex,
                                                 i + 1, h, size);

     }

    return root;
}


node *constructTree (int pre[], int post[], int size)
{
    int preIndex = 0;
    return constructTreeUtil (pre, post, &preIndex, 0, size - 1, size);
}


void printInorder (node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    A[r]=node->data;r++;
    printInorder(node->right);
}


int main ()
{
   int pre1,post1,post[1000];
   int pre[1000],x=0,y=0;
      ifstream myfile1,myfile2;
      myfile1.open("input1.txt");
      myfile2.open("input2.txt");
while(myfile2>>post1){post[y]=post1;y++;}
      while(myfile1>>pre1){pre[x]=pre1;x++;}
  cout<<"The given preorder is  ";
   for(int i=0;i<x;i++)
{ cout<<pre[i]<<"  ";
}cout<<endl;
cout<<"he given postorder is  ";
for(int i=0;i<y;i++){
cout<<post[i]<<"  ";}









    node *root = constructTree(pre, post, x);

    cout<<"\n\nInorder traversal of the constructed tree: \n";
     cout<<"output is in output file\n";;
    printInorder(root);
  ofstream outfile;
      outfile.open("output1.txt");
      for(int i=0;i<r;i++)
         {
           outfile<<A[i]<<" ";

          }

    return 0;
}
