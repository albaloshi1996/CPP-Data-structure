#include <iostream>
#include <string>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* previous;
};
struct Node *head;
///////////////
struct Node * getNewNode(int n){

  Node *newNode = new Node;
  newNode->data=n;
  newNode->next=NULL;
  newNode->previous=NULL;
  return newNode;
}
//////////////
struct Node * insert(int n, Node * node){
  if(node == NULL){

  return getNewNode(n);
}

Node * head1 =new Node;
head1=node;
//cout<<head1->data;

  while (node->next != NULL) {

//cout<<" "<<node->data;
    node = node->next;
//cout<<" "<<node->data;
}

  Node * newNode= getNewNode(n);
  //cout<<newNode->data;
  newNode->previous= node;
  node->next =newNode ;

return head1;
}
////////////////
void printFW(Node* node){
  if(node == NULL)
  return;
cout<<"Node Forward printed :";
  while (node != NULL) {
  cout<<node->data<<" ";
  node = node->next;
  }
  cout<<endl;
}
////////////////
void printBW(Node* node){
  if(node == NULL)
  return;
  while (node->next != NULL) {
    node = node->next;
  }
cout<<"Node Backward printed :";

  while (node != NULL) {
  cout<<node->data<<" ";
   node = node ->previous;
 }
 cout<<endl;
}
////////////////////
Node * insertStart(int n, Node* node){
  if(node==NULL)
  return getNewNode(n);

  Node *t =getNewNode(n);
  node->previous = t;
  t->next = node;
  return t;
}
///////////////////
Node * insertPosition(int n, Node* node, int position){
  if(node==NULL){
      if(position==1)
        return getNewNode(n);
      else
        return NULL;
  }
  if(position==1){
    Node *t =getNewNode(n);
    node->previous=t;
    t->next = node;
    return t;
  }
  Node *node2 = node;

  while (node2 != NULL && position>2) {
    node2 = node2->next;
    position--;
  }
  if(node2==NULL){
    cout<<"\nInvalid position try again !\n";
    return node;
  }
  Node *t = getNewNode(n);
  t->next = node2->next;
  t->previous = node2;
  if(node2->next != NULL){
    node2->next->previous =t;
  }
  node2->next = t;
  return node;
}
//////////////////
int main() {
  head=NULL;
  head = insert(12, head);
  head = insert(99, head);
  head = insert(37, head);
  head = insert(5, head);
  head = insert(25, head);
  printFW(head);
  printBW(head);
  //head = insertStart(50, head);
  head = insertPosition(60, head,6);
  printFW(head);
  printBW(head);
  return 0;
}
