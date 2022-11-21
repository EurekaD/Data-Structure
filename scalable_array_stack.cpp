#include<iostream>

using namespace std;

class ScalableArrayStack{
private:
    int array_length;
    char *data;
    int count;

public:
    ScalableArrayStack(){
        array_length = 5;
        this->data = new char[array_length];
        count = 0;
    }
    ~ScalableArrayStack(){
        delete data;
    }

    void push(char str);
    char pop();
    void scalable();

};

void ScalableArrayStack::scalable(){
    char *data_ = new char[2*array_length];
    for(int i=0;i<count;i++){
        *(data_+i) = *(data+i);
    }
    delete data;
    data = data_;
    array_length = 2*array_length;
    //cout<<"scalable!!!!"<<endl;
    //cout<<"array_length:"<<array_length<<endl;
}




void ScalableArrayStack::push(char str){
    if(count == array_length){
        //full
        this->scalable();
    }

    *(data+count) = str;
    count++;
}

char ScalableArrayStack::pop(){
    if(count == 0){
        return NULL;
    }
    else{
        char c = *(data+count-1);
        data[count-1] = NULL;
        count--;
        return c;

    }
}





int main(){
    ScalableArrayStack test;
    test.push('a');
    test.push('b');
    test.push('c');
    test.push('d');
    test.push('e');
    test.push('f');
    for(int i=0; i<6; i++){
        cout<<test.pop()<<endl;
    }

    return 0;
}
