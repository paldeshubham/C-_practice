#include<iostream>
using namespace std;
struct treeNode{
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
    if(node->right)
    {
        return findmax(node->right);
    }
    else
    {
        return node;

    }

}
treeNode *insert(treeNode *node, int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        temp=(treeNode *)malloc(sizeof(treeNode));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;

    }
    else if(data >(node->data))
    {
        node->right=insert(node->right,data);
    }
    else if(data <(node->data))
    {
        node->left=insert(node->left,data);

    }
    return node;
}
treeNode *del(treeNode *node,int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        return NULL;

    }
    if(data<(node->data))
    {
        return del(node->left,data);
    }
    if(data>(node->data))
    {
        return del(node->right,data);
    }
    else
    {
        if(node->right && node->left)
        {
            temp=findmin(node->right);
            node->data=temp->data;
            node->right=del(node->right,temp->data);
        }
        else
        {
            temp=node;
            if(node->left==NULL)
            {
                node=node->right;
            }
            else if( node->right=NULL)
            {
                node=node->left;
            }
            free(temp);
        }
    }
    return node;
}
treeNode *find(treeNode *node,int data)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(data>(node->data))
    {
        return find(node->right,data);
    }
    if(data < (node->data))
    {
        return find(node->left,data);
    }
    else
    {
        return node;
    }
}

void inorder(treeNode *node)
{
    if(node==NULL)
    {
        return ;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}
void preorder(treeNode *node)
{
    if(node==NULL)
    {
        return ;
    }
    cout<<node->data;
    preorder(node->left);
    preorder(node->right);
}
void postorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->data;
}
int main()
{
    treeNode *root=NULL,*temp;
    int ch1,data1;
    cout<<"Enter the number of elements you want to insert:";
    cin>>ch1;
    for(int i=0;i<ch1;i++)
    {
        cout<<"Enter the element:";
        cin>>data1;
        root=insert(root,data1);
    }
    cout<<"element inserted are:";
    inorder(root);

    cout<<"Enter elemet you want to delete:";
    int x;
    cin>>x;
    root=del(root,x);
    cout<<"after deletion the treee is:";
    inorder(root);

    postorder(root);
    preorder(root);
    temp=findmin(root);
    cout<<"minimum element is:"<<temp->data;

    temp=findmax(root);
    cout<<"MAximum element is:"<<temp->data;
}