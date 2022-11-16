#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList{
private:
    Node *head;
public:
    DoublyLinkedList(){
        //first set head Node
        head->data = -1;
        head->next = NULL;
        head->prev = NULL;
    }
    ~DoublyLinkedList(){
        delete head;
    }

    void insert(Node b, Node x);
    void remove(Node x);
};
void DoublyLinkedList::insert(Node b,Node x){
//Insert x after node B
if(b == NULL){// on link list head
    head = x;
}
else{
    x->next = b->next;
    x->prev = b;
    b->next = x;
}
}
void DoublyLinkedList::remove(Node x){
    x->prev->next = x->next;
    delete x;
}
