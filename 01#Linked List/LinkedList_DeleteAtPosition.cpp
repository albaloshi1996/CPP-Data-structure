#include <iostream>
#include <string>
using namespace std;

struct Node {
  int num;
   Node *next;
};
struct Node *head=NULL;



///////////////////
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
  cout<<node->num<<"  ";
  print(node->next);
}
///////////////////
struct Node *deleteAtPosition(int position, Node *node){
  if(position<0){
    cout<<"\nNot a valid position";
    return node;
  }

  if(node==NULL && position>1){
    cout<<"\nNot Valid position";
    return node;
  }
  if(position == 1)
    return node->next;

    node->next = deleteAtPosition(position-1, node->next);
    return node;

}
//////////////////
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
cout<<"\n";
head=deleteAtPosition(3,head);

print(head);
//display();
/*
insertBackward();
deleteNode(); deleteNode(); deleteNode(); deleteNode();
deleteNode(); deleteNode();
display();
*/



  return 0;
}
