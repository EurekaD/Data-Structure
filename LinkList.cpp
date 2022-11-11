#include<iostream>
using namespace std;

//单链表，主要练习使用指针
template <class NodeType>
struct Node{
    NodeType data;
    Node<NodeType> *next;
};

template <class NodeType>
class LinkList{
private:
    Node<NodeType> *head = new Node<NodeType>;
    //head的next是第一个节点
public:
    //插入
    void insert(Node<NodeType> *b, Node<NodeType> *x);

    //删除
    void remove(Node<NodeType> *b);
    Node<NodeType>* get_before_node(Node<NodeType> *b);

    //查找（根据节点数据来查找)
    Node<NodeType>* search(NodeType data);

    //末尾插入
    void tail_insert(Node<NodeType> *x);

    void PrintList();

    //构造函数
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
//删除单链表的一个节点必须先知道该链表的前驱节点，将这个方法封装为get_before_node，调用方法获取前驱节点
    Node<NodeType> *s = get_before_node(b);
    if(s == NULL && b==head->next){
        //节点b是第一个节点
        head->next=b->next;
        delete b;
    }
    else if (s != NULL && b!=head->next){
        s->next = b->next;
        delete b;
    }
    else{
        //节点b不在链表中
        cout<<"节点不在链表中"<<endl;
    }

}
template <class NodeType>
Node<NodeType>* LinkList<NodeType>::get_before_node(Node<NodeType> *b){
//获得节点b的前驱节点，对于单链表来说，要遍历链表
    //如果节点b就是头节点，没有前驱节点， 返回NULL
    if(b == head->next){
        return NULL;
    }
    Node<NodeType> *s = head->next;
    while(s->next != b && s != NULL){
        s = s->next;
    }
    //当s已经遍历到链表末尾后，说明没有该节点b
    return s;
}

//插入可以在节点前插入也可以在节点后插入，对于单链表来说，插在节点前麻烦一点
template <class NodeType>
void LinkList<NodeType>::insert(Node<NodeType> *b, Node<NodeType> *x){
//在节点b后面插入x,
//插入在头节点，则形参b应该传入NULL，则x变成头节点
    if(b == NULL){
        x->next = head->next;
        head->next = x;
    }
    else{
        x->next = b->next;
        b->next = x;
        //顺序很重要
    }
}

template <class NodeType>
Node<NodeType>* LinkList<NodeType>::search(NodeType data){
    //找到  第一个 符合数据的节点
    Node<NodeType> *s = head->next;
    while(s != NULL && s->data != data){
        s = s->next;
    }
    return s;
}

int main(){
    LinkList<int> test;
    //测试案例：
    //测试 创建10个节点，data依次是0-9，                            0 1 2 3 4 5 6 7 8 9
    //创建第六个节点（data=5）后删除该节点，                        0 1 2 3 4 6 7 8 9
    //创建第七个节点（data=6）后，在这个节点后插入data=5的新节点    0 1 2 3 4 6 5 7 8 9
    //循环结束后，通过search再删除data=8的节点                      0 1 2 3 4 6 5 7 9
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
