#include<iostream>
using namespace std;

//��������Ҫ��ϰʹ��ָ��
template <class NodeType>
struct Node{
    NodeType data;
    Node<NodeType> *next;
};

template <class NodeType>
class LinkList{
private:
    Node<NodeType> *head = new Node<NodeType>;
    //head��next�ǵ�һ���ڵ�
public:
    //����
    void insert(Node<NodeType> *b, Node<NodeType> *x);

    //ɾ��
    void remove(Node<NodeType> *b);
    Node<NodeType>* get_before_node(Node<NodeType> *b);

    //���ң����ݽڵ�����������)
    Node<NodeType>* search(NodeType data);

    //ĩβ����
    void tail_insert(Node<NodeType> *x);

    void PrintList();

    //���캯��
    LinkList(){
        head->next = NULL;
    }
    ~LinkList(){
        delete head;
    }
};

template <class NodeType>
void LinkList<NodeType>::tail_insert(Node<NodeType> *x){
    if(head->next == NULL){
        head->next = x;
        x->next = NULL;
    }
    else{
        Node<NodeType> *s = head->next;
        while(s->next!=NULL){
            s = s->next;
        }
        s->next = x;
        x->next = NULL;
    }

}
template <class NodeType>
void LinkList<NodeType>::PrintList(){
    Node<NodeType> *s = head->next;
    while(s != NULL){
        cout<<s->data<<" ";
        s = s->next;
    }
    cout<<endl;
}

template <class NodeType>
void LinkList<NodeType>::remove(Node<NodeType> *b){
//ɾ���������һ���ڵ������֪���������ǰ���ڵ㣬�����������װΪget_before_node�����÷�����ȡǰ���ڵ�
    Node<NodeType> *s = get_before_node(b);
    if(s == NULL && b==head->next){
        //�ڵ�b�ǵ�һ���ڵ�
        head->next=b->next;
        delete b;
    }
    else if (s != NULL && b!=head->next){
        s->next = b->next;
        delete b;
    }
    else{
        //�ڵ�b����������
        cout<<"�ڵ㲻��������"<<endl;
    }

}
template <class NodeType>
Node<NodeType>* LinkList<NodeType>::get_before_node(Node<NodeType> *b){
//��ýڵ�b��ǰ���ڵ㣬���ڵ�������˵��Ҫ��������
    //����ڵ�b����ͷ�ڵ㣬û��ǰ���ڵ㣬 ����NULL
    if(b == head->next){
        return NULL;
    }
    Node<NodeType> *s = head->next;
    while(s->next != b && s != NULL){
        s = s->next;
    }
    //��s�Ѿ�����������ĩβ��˵��û�иýڵ�b
    return s;
}

//��������ڽڵ�ǰ����Ҳ�����ڽڵ����룬���ڵ�������˵�����ڽڵ�ǰ�鷳һ��
template <class NodeType>
void LinkList<NodeType>::insert(Node<NodeType> *b, Node<NodeType> *x){
//�ڽڵ�b�������x,
//������ͷ�ڵ㣬���β�bӦ�ô���NULL����x���ͷ�ڵ�
    if(b == NULL){
        x->next = head->next;
        head->next = x;
    }
    else{
        x->next = b->next;
        b->next = x;
        //˳�����Ҫ
    }
}

template <class NodeType>
Node<NodeType>* LinkList<NodeType>::search(NodeType data){
    //�ҵ�  ��һ�� �������ݵĽڵ�
    Node<NodeType> *s = head->next;
    while(s != NULL && s->data != data){
        s = s->next;
    }
    return s;
}

int main(){
    LinkList<int> test;
    //���԰�����
    //���� ����10���ڵ㣬data������0-9��                            0 1 2 3 4 5 6 7 8 9
    //�����������ڵ㣨data=5����ɾ���ýڵ㣬                        0 1 2 3 4 6 7 8 9
    //�������߸��ڵ㣨data=6����������ڵ�����data=5���½ڵ�    0 1 2 3 4 6 5 7 8 9
    //ѭ��������ͨ��search��ɾ��data=8�Ľڵ�                      0 1 2 3 4 6 5 7 9
    for(int i = 0; i<10; i++ ){
        Node<int>* x = new Node<int>;
        x->data = i;
        test.tail_insert(x);
        if(i==5){
            test.remove(x);
            test.PrintList();
        }
        if(i==6){
            Node<int>* y = new Node<int>;
            y->data = 5;
            test.insert(x,y);
            test.PrintList();
        }

    }

    test.remove(test.search(8));
    test.PrintList();
    return 0;
}
