#include <iostream>
#include <string>
using namespace std;

struct Node {
  int data;
  Node * next;
};

Node *first, *last;

int size;
///////////

Node * getNewNode(int n){
  Node * newNode = new Node;
  newNode->data = n;
  newNode->next = NULL;
  return newNode;
}
////////////
void insert(int n){
  if(last == NULL){
    first = last =getNewNode(n);
    size++;
    return;
  }
  size ++;
  last->next = getNewNode(n);
  last = last ->next;
}
//////////////
bool ifEmpty(){
  if(last == NULL)
  return true;
return false;
}
////////////
int remove(){
  if(ifEmpty()){
    cout<<"\nQueue is empty\n";
    return 0;
  }
  size --;
  int t = first->data;
  first = first->next;

  if(first == NULL)
  last = NULL;

  return t;
}
///////////
int getFront(){
  if(ifEmpty()){
    cout<<"\nQueue is empty\n";
    return 0;
  }
  return first->data;
}
/////////////
int getRear(){
  if(ifEmpty()){
    cout<<"\nQueue is empty\n";
    return 0;
  }
  return last->data;
}

int main() {

  insert(12);
    insert(2);
    insert(7);
    insert(27);
    insert(18);
    insert(80);
    cout<<"\nSize: "<<size<<endl;
    cout<<"\nFront: "<<getFront()<<endl;
    cout<<"\nRear: "<<getRear()<<endl;
    cout<<"\nRemoved element: "<<remove()<<endl;
    insert(85);
    cout<<"\nSize: "<<size<<endl;
    cout<<"\nFront: "<<getFront()<<endl;
    cout<<"\nRear: "<<getRear()<<endl;
    cout<<"\nRemoved element: "<<remove()<<endl;
    cout<<"\nRemoved element: "<<remove()<<endl;
    cout<<"\nRemoved element: "<<remove()<<endl;
    cout<<"\nRemoved element: "<<remove()<<endl;
    cout<<"\nRemoved element: "<<remove()<<endl;
    cout<<"\nRemoved element: "<<remove()<<endl;
    cout<<"\nSize: "<<size<<endl;
    cout<<"\nFront: "<<getFront()<<endl;
    cout<<"\nRear: "<<getRear()<<endl;
  return 0;
}
