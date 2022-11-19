#include<iostream>

using namespace std;

struct Node{
    char data;
    Node *next;
};

class LinkListStack{
private:
    int count;
    Node *first = new Node();
    Node *tail;// tail is top of stack
public:
    LinkListStack(){
        count = 0;
        tail = first;
        first->next = nullptr;
        tail->next = nullptr;
    }
    void push(char str);
    char pop();
    Node* getPreviousNode();
};

Node* LinkListStack::getPreviousNode(){
    //return previous node of tail node
    if(first==tail){
        return nullptr;
    }
    else{
        Node *s = first;
        do{
            if(s->next==tail){
                return s;
            }
            s = s->next;
        }while(s->next!=nullptr);
        //return s;
    }
}


void LinkListStack::push(char str){
    if(count==0){
        first->data = str;
        //first->next = nullptr;
        tail = first;
        count++;
    }
    else{
        Node *s = new Node;
        s->data = str;
        s->next = nullptr;
        tail->next = s;
        tail = s;
        count++;
    }
}

char LinkListStack::pop(){
    if(count==0){
        cout<<"stack is empty"<<endl;
        return NULL;
    }
    else{
        char str = tail->data;
        //For a single linked list, it is difficult to find the previous node
        if(getPreviousNode()==nullptr){
            count--;
            first->data = NULL;
            first->next = nullptr;
            tail->next = nullptr;
        }
        else{
            count--;
            delete tail;
            tail = getPreviousNode();
        }
        return str;
    }
}


int main(){
    LinkListStack test;
    test.push('a');
    test.push('b');
    test.push('c');
    test.push('d');
    test.push('e');
    for(int i= 0;i<6;i++){
        cout<<test.pop()<<endl;
    }
    return 0;
}
