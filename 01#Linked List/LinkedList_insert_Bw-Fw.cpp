#include <iostream>
#include <string>
using namespace std;

struct Node {
  int num;
   Node *next;
};
struct Node *head;


void insertBackward(int n){
  struct Node *newNode =new Node;
  newNode->num = n;
  newNode->next = head;
  head = newNode;
}
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




  // cout<<head->num<<" ";
  // cout<<head->next;
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
  cout<<node->num<<", ";
  print(node->next);
}
///////////////////
int main() {
  /*
  struct Node *Root =new Node;
  Root->next =NULL;
  */
head =NULL;
head=insertForward(10, head);
head=insertForward(20, head);
head=insertForward(30, head);
head=insertForward(40, head);
head=insertForward(50, head);
head=insertForward(600, head);
print(head);
deleteNode();

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


/*
///////////////////
struct Node *getNew(int n){

   Node *newNode1 =new Node;
  newNode1->num = n;

  newNode1-> next = head;

return newNode1;
}

struct Node  *insertForward(int n ){

  if(head == NULL){

    cout<<" here ";
    head= getNew(n);

  }
  else{

    head->next = insertForward(n );
    cout<<" here2 ";
  }

  cout<<head->num<<" ";
  cout<<head->next;
return head;
}

//////////////////
*/
