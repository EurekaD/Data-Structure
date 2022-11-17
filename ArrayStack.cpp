#include<iostream>
using namespace std;

class ArrayStack{
private:
    char data[10];
    int count;//Number of elements in the stack

public:
    ArrayStack(){
        data[10]={0};
        this->count = 0;
    }
    bool push(char str);
    char pop();
    void test();
};
void ArrayStack::test(){
    for(int i=0;i<=count;i++){
        cout<<i<<" "<<data[i]<<endl;
    }
}

bool ArrayStack::push(char str){
    if(count == 10){
        //full
        return false;
    }
    else{
        this->data[count] = str;
        count++;
        return true;
    }
}

char ArrayStack::pop(){
    if(count == 0){
        return NULL;
    }
    else{
        char c = this->data[count-1];
        data[count-1] = NULL;
        count--;
        return c;

    }
}


int main(){
    ArrayStack test;
    test.push('a');
    test.push('b');
    test.push('c');
    test.push('d');
    test.push('e');
    test.test();
    for(int i=0; i<5; i++){
        cout<<test.pop()<<endl;
    }

    return 0;
}
