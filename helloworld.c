#include <stdio.h>
#include <float.h>
#include <string.h>


typedef struct Books // 由typedef编译器进行解释
{
    int id;
    char title[50];
    char author[50];
    char subject[100];
} Book;

// 共用体，允许在相同的内存位置存储不同的数据类型，同时只能用到一个成员
union Data
{
    int i;
    float f;
    char str[20];
};
/* 函数声明 */
void printBook(struct Books book);

static int num = 10; // 全局静态变量

#define TRUE 1 // C语言指令，预编译器进行处理

int main(int argc, char const *argv[])
{
    /* code */
    // comments
    int a = 2;
    int b = 3;
    float c = 2.5f;
    int *ptr;
    char d = 'x';
    char str[] = "string";
    int len = strlen(str);
    
    FILE *fp;
    fp = fopen("file.txt", "w+");
    fprintf(fp, "This is testing for fprintf...\n");
    fputs("This is testing for fputs...\n", fp);
    fclose(fp);

    int *ptr1 = NULL;
    char *ptr2 = 0; // 地址为0或者NULL都代表不指向一个可用的内存地址
    printf("ptr1: %p\n", ptr1); // 0x0
    printf("ptr2: %p\n", ptr2); // 0x0
    printf("ptr1大小: %lu\n", sizeof(ptr1)); // 8位32字节16进制数
    printf("ptr1的地址: %p\n", &ptr);

    printf("Value of TRUE: %d\n", TRUE);
    
    struct Books book1;
    struct Books books[10];
    book1.id = 1;
    strcpy(book1.author, "William Jing");
    strcpy(book1.subject, "Six Six Six");
    strcpy(book1.title, "快乐风男");

    union Data data;
    data.i = 10;
    data.f = 11.1f;
    printf("data.i: %d\n", data.i); // data.i: 1093769626 因为最后赋值给变量的值占用了内存位置
    printf("data.f: %f\n", data.f); // data.f: 11.100000 所以data.f能正确输出
    printf("a的地址是：%p\n", &a);
    ptr = &a;
    printf("a的值是：%d\n", *ptr);
    printf("b的地址是：%p\n", &b);
    printf("c的地址是：%p\n", &c);
    printf("hello, world\n");
    printf("char 存储大小：%lu\n", sizeof(char)); // 1
    printf("short 存储大小：%lu\n", sizeof(short)); // 2
    printf("signed 存储大小：%lu\n", sizeof(signed)); // 4
    printf("int 存储大小：%lu\n", sizeof(int)); // 4
    printf("float 存储大小：%lu\n", sizeof(float)); // 4
    printf("float 最值和精度：%E - %E - %d\n", FLT_MIN, FLT_MAX, FLT_DIG);
    printf("double 存储大小：%lu\n", sizeof(double)); // 8
    printf("long 存储大小：%lu\n", sizeof(long)); // 8
    num++;
    printf("global num: %d\n", num); // 11
    printBook(book1); // 快乐风男
    switch (d)
    {
        case 'x':
            printf("%s %d\n",str,len); // string 6
            /* code */
            break;
        default:
            break;
    }
    return 0;
}

void printBook(struct Books book)
{
    printf("book title: %s\n", book.title);
}