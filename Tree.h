#include <unordered_set>
#include <queue>
#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        //cout<<"Tree Deleted!"<<endl;
        for (int i = 1; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
void printDFS(TreeNode<int> *root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty!" << endl;
        return;
    }
    cout << root->data << ":";
    if (root->children.empty())
    {
        cout << "Leaf Node";
    }
    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data << ",";
        }
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printDFS(root->children[i]);
    }
}
void printBFS(TreeNode<int> *root)
{
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *f=q.front();
        q.pop();
        cout<<f->data<<":";
        if(f->children.empty())
        {
            cout<<"Leaf Node";
        }
        else
        {
            for(int i=0;i<f->children.size();i++)
            {
               cout<<f->children[i]->data<<",";
               q.push(f->children[i]);
            }
        }
        cout<<endl;
     }
}
TreeNode<int>* takeinputDFS()
{
    int Rootdata;
    cout<<"Enter data:"<<endl;
    cin>>Rootdata;
    TreeNode<int> *root=new TreeNode<int>(Rootdata);
    int n;
    cout<<"Enter the number of children of"<<" "<<Rootdata<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        TreeNode<int> *child=takeinputDFS();
        root->children.push_back(child);
    }
    return root;
}
TreeNode<int>* takeinputBFS()
{
    int RootData;
    cout<<"Enter Data:"<<endl;
    cin>>RootData;
    TreeNode<int> *root=new TreeNode<int>(RootData);
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *f=q.front();
        q.pop();
        cout<<"Enter number of children of"<<" "<<f->data<<endl;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int childData;
            cout<<"Enter"<<" "<<i<<"th"<<" "<<"child of"<<" "<<f->data<<endl;
            cin>>childData;
            TreeNode<int> *Child=new TreeNode<int>(childData);
            q.push(Child);
            f->children.push_back(Child);
        }
    }
    return root;
}
int Size(TreeNode<int> *root)
{
    if(root==NULL)
    {
        cout<<"Empty Tree!"<<endl;
        return -1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=Size(root->children[i]);
    }
    return 1+ans;
}
int height(TreeNode<int> *root)
{
    int mh=0;
    if(root==NULL)
    {
        cout<<"Empty Tree!"<<endl;
        return -1;
    }
    for(int i=0;i<root->children.size();i++)
    {
        //int h=height(root->children[i]);
        //if(h>mh)
        //{
            //mh=h;
        //}
        mh=max(mh,height(root->children[i]));
    }
    return 1+mh;
}
int countleafnodes(TreeNode<int> *root)
{
    if(root==NULL)
    {
        cout<<"Empty Tree:"<<endl;
        return -1;
    }
    if(root->children.size()==0)return 1;
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countleafnodes(root->children[i]);
    }
    return ans;
}
void PreOrder(TreeNode<int> *root)
{
    if(root==NULL)
    {
        cout<<"Tree is Empty!"<<endl;
        return;
    }
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        PreOrder(root->children[i]);
    }
}
void PostOrder(TreeNode<int> *root)
{
    if(root==NULL)
    {
        cout<<"Tree is Empty!"<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        PostOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}
void DeleteTree(TreeNode<int> *root)
{
    if(root==NULL)
    {
        cout<<"Tree is Empty!"<<endl;
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        DeleteTree(root->children[i]);
    }
    delete root;
}
