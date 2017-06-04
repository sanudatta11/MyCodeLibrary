#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *right;
    node *left;
};

node* minvaluenode(node *root)
{
    if(!root->left)
        return root;
    else
        minvaluenode(root->left);
}

void insert_bst(node *root,int data)
{
    if(data < root->data)
    {
        if(!root->left)
        {
            node *ptr = new node;
            ptr->data = data;
            ptr->left = ptr->right = NULL;
            root->left = ptr;
        }
        else
            insert_bst(root->left,data);
    }
    else if(data > root->data){
                if(!root->right)
                {
                    node *ptr = new node;
                    ptr->data = data;
                    ptr->right = ptr->left = NULL;
                    root->right = ptr;
                }
                else
                    insert_bst(root->right,data);
            }
}

bool find_bst(node *root,int data)
{
    if(!root)
        return false;
    if(root->data == data)
        return true;
    if(data<root->data)
        find_bst(root->left,data);
    else
        find_bst(root->right,data);
}

void delete_bst(node *root)
{
    if(!root->left&& !root->right)
        delete root;
    else if(!root->right)
    {
        delete root->left;
    }
    else if(!root->left)
    {
        delete root->right;
    }
    else
    {
        delete_bst(root->left);
        delete_bst(root->right);
    }
}

node* delete_node(node *root,int data)
{
    if(!root)
        return NULL;
    if(data < root->data)
        root->left = delete_node(root->left,data);
    else if(data > root->data)
        root->right = delete_node(root->right,data);
    else{
        if(root->right == NULL && root->left == NULL)
        {
            //No child node
            delete root;
            return NULL;
        }
        else if(!root->right)
        {
            //Single child case
            delete root;
            return root->left;
        }else if(!root->left)
        {
            delete root;
            return root->right;
        }
        else{
            //Has both childs
            node *temp1 ;
            temp1 = minvaluenode(root->right);
            root->data = temp1->data;
            root->right = delete_node(root->right,temp1->data);
        }
    }
    return root;
}

int main()
{
    cout<<"Enter number of nodes to make=";
    int n;
    cin>>n;
    node *root = new node;
    root->left=root->right = NULL;
    for(int i=0;i<n;++i)
    {
        int temp;
        cin>>temp;
        if(i==0)
            root->data = temp;
        else
            insert_bst(root,temp);
    }
    cout<<"\nEnter queries to make=";
    int qu;
    cin>>qu;
    for(int i=0;i<qu;++i)
    {
        cout<<"Enter digit to search=";
        int temp;
        cin>>temp;
        if(find_bst(root,temp))
            cout<<"Element Present\n";
        else
            cout<<"Element not present\n";
    }

    cout<<"Enter element to delete =";
    cin>>qu;
    int temp;
    delete_node(root,qu);
    cout<<"Enter element to search=";
    cin>>temp;
    if(find_bst(root,temp))
            cout<<"Element Present\n";
        else
            cout<<"Element not present\n";

    delete_bst(root);
    return 0;
}

