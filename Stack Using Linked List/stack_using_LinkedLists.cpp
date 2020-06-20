#include <iostream>
#include <string>
using namespace std;
struct Node{
  int data;
  Node * next;
};
Node * front =NULL;
/////////
Node *getNewNode(int n){
  Node * newNode = new Node;
  newNode->data= n;
  newNode->next = NULL;
  return newNode;
}
/////////
void puash (int n){
  if(front == NULL){
  front = getNewNode(n);
  return;
}
Node * t = getNewNode(n);
t->next = front;
front=t;
}
////////
int pop(){
  if(front == NULL){
    cout<<"\nStack is emepty\n";
    return 0;
  }
  int t = front-> data;
  front =front ->next;
  return t;
}
//////////
int top(){
  if(front ==NULL){
    cout<<"\nEmpty stack";
    return 0;
  }
  return front->data;
}


int main() {
puash(12);
puash(5);
puash(34);
puash(42);
puash(91);
puash(9);
cout<<"\n"<<pop()<<" "<<pop()<<" "<<pop();
cout<<"\n"<<top();
  return 0;
}
