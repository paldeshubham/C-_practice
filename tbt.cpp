#include<iostream>

struct Node{
    int data;
    Node*left;
    Node*right;
    bool isThreaded;

};

Node* createnode(int data)
{
    Node* newNode=new Node;
    newNode->data=data;
    newNode->left=nullptr;
    newNode->left=nullptr;
    newNode->isThreaded=false;
    return newNode;
}

Node* insert(Node* root, int data)
{
    if(root==nullptr)
    {
        return createnode(data);
    }

    if(data<root->data)
    {
        root->left=insert(root->left,data);
        root->right=insert(root->right,data);
        root->isThreaded=true;
        
    }
    else
    {
        if(root->isThreaded)
        {
            Node* temp = root->right;
            root->right=createnode(data);
            root->right->right=temp;
            root->isThreaded=false;
        }  
        else
        {
            root->right=insert(root->right,data);

        }

    }
    return root;
}

void inOrderTraversal(Node* root)
{
    if(root==nullptr)
    {
        return;
    }
    inOrderTraversal(root->left);
    std::cout<<root->data<<"";
    inOrderTraversal(root->right);
}
int main()
{
    Node* root=nullptr;
    root=insert(root,10);
    root=insert(root,23);
    root=insert(root,67);
    root=insert(root,98);
    root=insert(root,23);
    root=insert(root,35);
    root=insert(root,57);

    std::cout<<"In-order traversal:\n";
    inOrderTraversal(root);

    return 0;


}