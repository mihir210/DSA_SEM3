#include <iostream>
#include <queue>
using namespace std;

class node
{

public:
   int data;
   node *left;
   node *right;
};

void insert(node *root, node *n)
{
   if (n->data > root->data)
   {
      if (root->right == NULL)
         root->right = n;
      else
         insert(root->right, n);
   }
   if (n->data < root->data)
   {
      if (root->left == NULL)
         root->left = n;
      else
         insert(root->left, n);
   }
}

node *get_node()
{
   node *temp;
   temp = new node;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
}

void preorder(node *root)
{
   if (root == NULL)
      return;
   cout << root->data << '\t';
   preorder(root->left);
   preorder(root->right);
}

void inorder(node *root)
{
   if (root == NULL)
      return;

   inorder(root->left);
   cout << root->data << '\t';
   inorder(root->right);
}

void levelorder(node *root)
{
   if (root == NULL)
      return;
   queue<node *> q1;
   q1.push(root);
   while (!q1.empty())
   {
      node *current = q1.front();
      cout << current->data<<"\t";
      if (current->left != NULL)
         q1.push(current->left);

      if (current->right != NULL)
         q1.push(current->right);

      q1.pop();
   }
}

void postorder(node *root)
{
   if (root == NULL)
      return;

   postorder(root->left);
   postorder(root->right);
   cout << root->data << '\t';
}


node * search(node *root, int k){
   
   node *t = root;
   
   while (t)
   {
      if (k==t->data)
      {
         cout<<"element found \n";
         return t;
      }
      else if (k>t->data)
      {
         t = t->right;
      }
      else{
         t = t->left;
      }
   
   }
   
   return NULL;
   
   
}

int main()
{

   node *New, *root;
   root = NULL;
   int ans;
   do
   {
      New = get_node();
      cin >> New->data;
      if (root == NULL)
         root = New;
      else
         insert(root, New);
      cout << "do you want to enter more elements ? \npress 1 for yes\npress 0 for no\n";

      cin >> ans;
      // char temp =  getchar();
   } while (ans == 1);

   cout << "preoder";
   preorder(root);
   cout << endl;

   cout << "inorder";
   inorder(root);
   cout << endl;

   cout << "postorder";
   postorder(root);
   cout << endl;

   cout << "level order";
   levelorder(root);
   
   
   
   cout<<"Enter the number you want to search :";
   int m;
   cin>>m;
   
   node *se;
   
   se = search(root,m);
   
   cout<<se->data;

   return 0;
}
