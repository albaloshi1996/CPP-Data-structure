#include <iostream>
#include <string>
using namespace std;

struct Node {
  int num;
   Node *next;
};
struct Node *head=NULL;



struct Node *getNew(int n){

   Node *newNode1 =new Node;
  newNode1->num = n;

  newNode1-> next = NULL;

return newNode1;
}

struct Node  *insertForward(int n, Node *node ){

  if(node == NULL){
    return getNew(n);

  }
  else

    node->next = insertForward(n, node->next);

return node;
}
//////////////////
struct Node *insertAtPosition(int n, int position, Node *node){
  if(position<0)
  cout<<"\nPosition can't be less than 1";
  if(node==NULL && position>1){
    cout<<"\nPosition is greater than element exists";
    return node;
  }
  if(node == NULL && position==1){
    return getNew(n);
  }
  if(position==1){
    Node *newNode = new Node;
    newNode= getNew(n);
    newNode->next = node;
    return newNode;
  }
  node->next = insertAtPosition(n, position-1, node->next);
  return node;
}

/////////////////

void deleteNode(){
  if (head == NULL)
  {
    cout <<"LIst is Empty !!!\n";
    return;
  }
  cout<<head->num <<" is removed."<<endl;
  head=head->next;
}

void display(){

  if(head ==NULL)
  {
    cout<<"List is empty !\n";
    return;
  }
  struct Node *temp =head;
  while(temp!=NULL){
    cout<<temp->num<<", ";
    temp= temp->next;
  }
  cout<<"\n";
}
////////////////////
void print(struct Node *node){
  if(node==NULL){
    // cout<<"new print empty";
    return;
  }
  cout<<node->num<<", ";
  print(node->next);
}
///////////////////
int main() {
  /*
  struct Node *Root =new Node;
  Root->next =NULL;
  */

head=insertForward(10, head);
head=insertForward(20, head);
head=insertForward(30, head);
head=insertForward(40, head);
head=insertForward(50, head);
head=insertForward(600, head);
print(head);
//deleteNode();
head=insertAtPosition(700,7,head);
cout<<endl;
print(head);





  return 0;
}
