#include<iostream>
using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};

treeNode *findmin(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->left)
    {
        return findmin(node->left);
    }
    else
    {
        return node;
    }
}

treeNode *findmax(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    else if(node->right)
    {
        return findmax(node->right);
    }
    else
    {
        return node;
    }
}
treeNode *insert(treeNode *node,int data)
{
    
    if(node==NULL)
    {
        treeNode *temp;
        temp= new treeNode;
        temp=(treeNode *)malloc(sizeof(treeNode));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    else if(data>node->data)
    {
        node->right=insert(node->right,data);
    }
    else if(data < node->data)
    {
        node->left = insert(node->left,data);
    }
    return node;
}
void inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    inorder(node->left);
    cout <<node->data<<" ";
    inorder(node->right);
}
void postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}
void preorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    treeNode *root = NULL,*temp;
    int ch1,data1;
    cout << "Enter the number of element to be inserted:";
    cin>>ch1;
    for(int i=0;i<ch1;i++)
    {
        cout<<"Enter the" <<i+1<<" element:";
        cin>>data1;
        root = insert(root,data1);
    }
    cout<<"\nElements in BST are:";
    inorder(root);

    cout<< "\nPostorder traversal is:";
    postorder(root);

    cout<<"\n preorder traveral is:";
    preorder(root);

    temp=findmin(root);
    cout<<"The smallest element in BST is:"<<temp->data;

}
