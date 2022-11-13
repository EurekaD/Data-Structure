#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
};

class CLinkList{
private:
    Node* head;
    //head���ǵ�һ���ڵ�
public:
    //���캯��
    CLinkList(){
        head->next = head;
        head->data = -1;
    }
    ~CLinkList(){
        delete head;
    }
    //ĩβ����
    void tail_insert(int x);

    void printList();

};

void CLinkList::tail_insert(int x){
    //������ĩβ�����½ڵ�

    //���head���ǵ�һ���ڵ㣬��ô����ж�����ڵ��Ƿ����
    if(head->next == head && head->data == -1){
        head->data = x;
    }
    else{
        Node *s = head;
        //������ĩβ
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
            cout<<"��"<<i<<"��:"<<s->data<<endl;
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
