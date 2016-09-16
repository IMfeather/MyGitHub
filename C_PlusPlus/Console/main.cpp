#include <iostream>
#include "stdio.h"
#include "stdint.h"
#include "vector"
#include "time.h"
#include "get100.h"
#include <cmath>
#include "string.h"
#include "stdlib.h"
#include "StringWithMySplitFunc.h"
#include "charReader.h"

#pragma warning(push)
#pragma warning(disable: 4996)
#pragma warning(disable: 4305) // (33)  ����ʼ����: �ӡ�int������char���ض�
#pragma warning(disable: 4309) // (33)  ����ʼ����: �ضϳ���ֵ
#pragma warning(disable: 4018) // (240) ��<��: �з���/�޷��Ų�ƥ�� 
#pragma warning(disable: 4477) // (67)  ��printf��: ��ʽ�ַ�����%x����Ҫ���͡�unsigned int���Ĳ��������ɱ���� 2 ӵ�������͡�int *��


using namespace std;

void func_1()
{
    // С�ֽ���0  44  ���ֽ���1023  44
    int a[10];
    int  i = 0;
    
    for (i; i < 10; i++)
    {
        *(a + i) = i + 1014;
    }
    
    short *p = (short*)(&a + 1);//�˴���������������a  //a+1���ڴ��ַ��[����Ԫ�صĳ���]��һ�� &a+1���ڴ��ַ[����������ĳ���]��һ
    short *q = p - 1;
    char c = 300;
    char* d = &c - 1;
    printf("%d %d\n", *q, c);   //���ֽ���24,_      С�ֽ���10,_(0, 44)
    return;
}


void func_2()
{
    int a[3][3]    = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    int (*x)[3]    = a;
    int *k         = a[0];
    int (*y)[3][3] = &a;
    int (*q)[3]    = &a[0];
    int *z         = &a[0][0];
    printf("%d\n", (*(x + 1))[0]);    // 4
    printf("%d\n", *(k + 1));         // 2
    printf("%d\n", (*(*(y + 1)))[0]); // _____?
    printf("%d\n", (*(q + 1))[0]);    // 4
    printf("%d\n", *(z + 1));         // 2
    int *p = (int *)(y + 1);
    printf("%d\n", *(p - 1));         // 9
    return;                           // good, answer is right!
}

void test_func_1()
{
    short a[5] = { 0, 1, 2, 3, 4 };
    int   b[5] = { 0, 1, 2, 3, 4 };
    int* p = (int*)a;
    p++;
    printf("&a=%x\n&p=%x\n", &a, p);
    printf("a[0] = %d\n", a[0]);
    printf("  *p = %d\n", *p);
    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(short)=%d\nsizeof(int)=%d\n", sizeof(short), sizeof(int));
    return;
}

void TrueSwamp(int& a, int& b)
{
    int c = a;
    a = b;
    b = c;
    return;
}

typedef uint32_t uint_32_t;

//ͨ��λ�ƣ����ٵļ��㿪���Ų����������������ȷ
float fast_sqrt(float x)
{
    uint_32_t x_bits = 0;
    x_bits = *((uint_32_t*) &x);
    x_bits = (x_bits >> 1) + 532369198;
    return *((float*)&x_bits);
}


//��splite�����޷�����һ���������, �ַ���Ϊ "�||��ð�|123|�|�|�||abc" ���� "|" Ϊ�ָ���ʱ �����ԭ���� ���� "�|" ��ָ��� "|" ����ͬ��ACSII��
//C++��string �� find�Լ�C ���Ա���� strtok�������޷����������������
int strsplit(const char *str, char *parts[], const char *delimiter)
{
    char *pch;
    int i = 0;
    char *copy = NULL, *tmp = NULL;
    copy = strdup(str);
    
    if (!copy)
    {
        goto bad;
    }
    
    pch = strtok(copy, delimiter);
    tmp = strdup(pch);
    
    if (!tmp)
    {
        goto bad;
    }
    
    parts[i++] = tmp;
    
    while (pch)
    {
        pch = strtok(NULL, delimiter);
        
        if (NULL == pch) { break; }
        
        tmp = strdup(pch);
        
        if (!tmp)
        { goto bad; }
        
        parts[i++] = tmp;
    }
    
    free(copy);
    return i;
bad:
    free(copy);
    
    for (int j = 0; j < i; j++)
    {
        free(parts[j]);
    }
    
    return -1;
}
//����splite������ �ܹ����պ���Ϊ�ָ������зָ�����ֲ��˺��� "�|" ��ָ��� "|"
void test004()
{
    char str[] = "123�|�����|abc�|";//"�||��ð�|123|�|�|�||abc"
    char *parts[8];
    size_t size = strsplit(str, parts, "�|"); //"|"
    int i = 0;
    
    for (; i < size; ++i)
    {
        printf("%s\n", parts[i]);
    }
    
    return;
}

//��ɽ�������⣬�ݹ�+ѭ��
int cc(int i)
{
    for (;  i < 4; )
    {
        std::cout << cc(++i);
    }
    return i;
}
void testcc()
{
    cc(1);
    return;
}


void main(void)
{
	StringWithMySplit("��a|�|һ���һ��һ|123|һ�|�|�||һabc").MysplitString('|');
	//StringWithMySplit().MysplitString('|');

// 	StringWithMySplit a = StringWithMySplit("a|�|һ���һ��һ|123|һ�|�|�||һabc");
// 
// 	//cout << a.m_str << endl;
// 
//     char* pSrc = "a|�|һ���һ��һ|123|һ�|�|�||һabc";
// 
// 	char* pDest = new char[strlen(pSrc)];
// 
// 	a.g2u(pSrc, strlen(pSrc), pDest, strlen(pSrc));
// 
// 	cout << pDest << endl;

	
    return;
}