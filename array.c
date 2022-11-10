#include<stdio.h>
int main(){

//因为数组越界二无限循环输出
//如果把 i<3 错误的写成了 i<=3 .
    int i = 0;
    int a[3] = {0};
    for(; i<3; i++){
        a[i]=0;
        printf("Hello world\n");
    }
//对于C语言，这种错误编译器并不会处理


//可以看到i 的地址就是 a[3]的地址
    for(i=0;i<=3;i++){
        printf("%x ",&a[i]);
    }
    printf("\n");

    printf("i address: %x ",&i);

//数组是连续的内存空间，因此优点是可以通过很简单的方法
//a[i]_address = base_address + i x data_type_size 一维数组
//直接计算得出，所以数组根据下标访问元素的时间复杂度是O(1).

    return 0;
//缺点是插入和删除操作的低效，需要做很多数据搬移的操作，还有大小固定的问题，
//即使动态扩容，申请更大的内存空间后也要进行数据搬移
}
