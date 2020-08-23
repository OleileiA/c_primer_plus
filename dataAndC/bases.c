//
// Created by 陈彦文 on 2020/8/23.
//


#include <stdio.h>

void tooBig();
void print2();
int charType();
void intType();
void floatNum();

// 打印八进制，十六进制
int main() {

//    int x = 100;
//    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);
//    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);

//    tooBig();
//    print2();
//    charType();
//    intType();
    floatNum();
    return 0;
}

// 演示整数溢出的效果
// 但是溢出的行为是未定义的，不要去利用这些特点
void tooBig() {

    int i = 2147483647;
    unsigned int j = 4294967295;

    // 就像一个里程表，转了一圈又回来
    // 2147483647 -2147483648 -2147483647
    printf("%d %d %d \n", i, i + 1, i + 2);

    // 4294967295 0 1
    printf("%u %u %u", j, j + 1, j + 2);
}

// 打印shor long longlong unsigned
void print2() {

    unsigned int un = 3000000000;
    short end = 200;
    long big = 65537;
    long long veryBig = 12345678908642;

    printf("un = %u and not %d\n", un, un);
    printf("end = %hd and %d\n", end, end);
    printf("big = %ld and not %hd\n", big, big);
    printf("veryBig = %lld and not %ld\n", veryBig, veryBig);
}

// char类型
int charType() {

    char ch = 7; // beep
    printf("please enter a character. \n");
    printf("%c", ch);
    return 0;
}

// 为了提高c语言的可移植性，新增了一个特殊的头文件
// 确保c语言在各个系统中功能相同
#include <inttypes.h>
void intType() {

    int32_t me32 = 45933945;
    printf("me32: %d", me32);
}


// c语言的浮点数
void floatNum() {
    // 浮点数常量, 默认double类型，后面接f表示float
    // -1.56E+12
    // 2.87e-3
    // 3.1415
    // .2
    // 4e16
    // .8e-5
    // 100.

    // 打印浮点
    float aboat = 3200.0;
    double abet = 2.14e9;
    long double dip = 5.32e-5;

    printf("%f can be written %e\n", aboat, aboat);
    printf("%a\n", aboat); // 16进制格式的浮点数
    printf("%f can be written %e\n", abet, abet);
    printf("%LF can be written %Le\n", dip, dip); // 注意大小写


    /*
     * 浮点数的上溢和下溢：
     * float的指数位8位，所以最大的值为2^128
     * */
    float tooBig = 3.4e38 * 2; // 这个计算导致上溢
    printf("%e", tooBig); // c语言规定上溢显示inf
}

