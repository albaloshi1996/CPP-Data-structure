//Lab 5 Homework
//(114860) Muslim AlBalushi

#include <iostream>
#include <string>
using namespace std;

  // Declaration of Node for binary tree
  struct Node {
     Node* left;
     Node* right;
    int data;
  };

/* */
//Function to get numbers of each node and its childs recusively
int getNumberOfNodes( Node* node){
  if (node == NULL) {
    return 0;
  }
  return 1+ (getNumberOfNodes(node->left) + getNumberOfNodes(node->right));
}
/* */
// function to find hieght of binary tree recursivly
int getHeightOfTree(Node* node){
  if (node == NULL){ //incase
  return 0;
}

  return max(getHeightOfTree(node->left),getHeightOfTree(node->right))+1;
}
/* */
//function compare left and right and return higher as hieght/depth
int max (int a , int b){
  return a>b ? a:b;
}
/* */
//Function used to insert and create new nodes
struct Node* createNewNode(int val, Node *node){
  if(node == NULL){
   Node *node1 =new Node ;
  node1->data= val;
  node1->left = NULL;
  node1->right = NULL;
   node= node1;
  }
  // conditionds automatically place numbers to left or right based
  // on binary trees difinition
  else if(val < node->data)
    node->left = createNewNode(val, node->left);
  else if(val > node->data)
    node->right = createNewNode(val, node->right);
  return node;
}

int main() {
  //Declaration of Root Node and assigning it as NULL
      Node* root=new Node;
      root=NULL;

  root=  createNewNode(20, root);
  root=  createNewNode(25, root);
  root=  createNewNode(15, root);
  root=  createNewNode(10, root);
  root=  createNewNode(30, root);
  root=  createNewNode(11, root);
  root=  createNewNode(12, root);
  root=  createNewNode(21, root);
  root=  createNewNode(13, root);
    cout << "Number of total node = " << getNumberOfNodes(root)<<endl;
    cout << "The higth /depth of the Binary Tree is = " << getHeightOfTree(root);
  return 0;
}
