#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};

class CLinkList{
private:
    Node* head;
    //head就是第一个节点
public:
    //构造函数
    CLinkList(){
        head->next = head;
        head->data = -1;
    }
    ~CLinkList(){
        delete head;
    }
    //末尾插入
    void tail_insert(int x);

    void printList();

};

void CLinkList::tail_insert(int x){
    //在链表末尾插入新节点

    //如果head就是第一个节点，那么如何判断这个节点是否存在
    if(head->next == head && head->data == -1){
        head->data = x;
    }
    else{
        Node *s = head;
        //遍历到末尾
        while(s->next!=head){
            s = s->next;
        }
        Node *newNode = new Node;
        s->next = newNode;
        newNode->data = x;
        newNode->next = head;
    }
}
void CLinkList::printList(){
    Node *s = head;
    for(int i = 0; i<20; i++){
            cout<<"第"<<i<<"个:"<<s->data<<endl;
            s = s->next;
    }
}

int main(){
    CLinkList test;
    for(int i = 0; i<3; i++ ){
        test.tail_insert(i);
    }
    test.printList();

    return 0;
}
