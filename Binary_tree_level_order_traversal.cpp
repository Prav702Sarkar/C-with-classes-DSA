#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
    int data;
    node *right;
    node *left;
    node(int data)
    {
        this->data=data;
        this-> right=NULL;
        this->left=NULL;
    }
};

class Tree
{
    public:
    node *root;
    Tree()
    {
        root=NULL;
    }
    void preorder(node *root)
    {
        if(root==NULL)return;
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
     void postorder(node *root)
    {
        if(root==NULL)return;
      
        postorder(root->left);
        postorder(root->right);
          cout<<root->data<<" ";
    }
    
     void inorder(node *root)
    {
        if(root==NULL)return;
      
        inorder(root->left);
         cout<<root->data<<" ";
        inorder(root->right);
         
    }
    void LOT(node *root)
    {
        if(root==NULL)return;
        queue<node*>q;
        q.push(root);
        while(!q.empty())
        {
            node *temp=q.front();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            q.pop();
        }
        
    }
    
};

int main()
{
    //printf("Hello World");
    node * n1=new node(10);
    node * n2=new node(20);
    node * n3=new node(30);
    node * n4=new node(40);
    node * n5=new node(50);
    node * n6=new node(60);
    node * n7=new node(70);
    node * n8=new node(80);
    node * n9=new node(90);
    n1->right=n3;n1->left=n2;
    n2->right=n5;n2->left=n4;
    n3->right=n7;n3->left=n6;
    n4->right=n9;n4->left=n8;
    Tree *tree=new Tree();
    tree->root=n1;
    tree->LOT(tree->root);
       delete tree;
    

    return 0;
}