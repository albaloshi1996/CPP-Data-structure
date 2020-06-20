#include <iostream>
#include <string>
using namespace std;

struct Node {
  Node * left;
  Node * right;
  int data;
};
Node * createNewNode(int k);
Node *insertNode(Node *node, int n);
Node *deleteNode(Node* node, int n);
Node * getSuccessor(Node *node);
///////////
 Node * createNewNode(int k){
  Node *newNode = new Node;
  newNode->data = k;
  newNode->left =NULL;
  newNode->right=NULL;
  return newNode;
}
////////////
 Node *insertNode(Node *node, int n){
  if(node==NULL){
  return createNewNode(n);}

  if(n< node->data){
    node->left = insertNode(node->left, n);
  } else if (n > node->data){
    node->right = insertNode(node->right, n);
  }
  return node;
}
////////////
Node *deleteNode(Node* node, int n){
  if(node==NULL)
    return node;
  if(n < node->data){
    node->left = deleteNode(node->left, n);
  }else if(n > node ->data){
    node->right = deleteNode(node->right, n);
  }else {
    if(node->left == NULL || node->right == NULL){
      Node *temp =node->left;
          if(node->left != NULL)
          temp = node->left;
          if(node->right !=NULL)
          temp = node->right;
      if(temp == NULL)
      return NULL;
      else
      return temp;
    }else{
      Node *successor = getSuccessor(node);
      node-> data = successor->data;
      node->right = deleteNode(node->right, successor->data);
      return node;
    }
  }
  return node;
}
///////
Node * getSuccessor(Node *node){
  if(node == NULL)
  return NULL;

  Node * temp = node->right;
  while (temp->left != NULL) {
    temp = temp ->left;
  }
  return temp;
}
///////////////
void inOrder(Node* node){
  if(node == NULL)
  return;
  inOrder(node->left);
  cout<<"\n"<<node->data<<" ";
  inOrder(node->right);
}
int main() {
  Node * root = NULL;
  root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 6);
    root = insertNode(root, 10);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 1);
    root = insertNode(root, 14);
    root = insertNode(root, 13);
    //root = deleteNode(root, 8);
    inOrder(root);
  return 0;
}
