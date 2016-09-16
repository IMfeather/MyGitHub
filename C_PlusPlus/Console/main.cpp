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
#include "reserve_resize.h"

#pragma warning(push)
#pragma warning(disable: 4996)
// #pragma warning(disable: 4305) // (33)  ����ʼ����: �ӡ�int������char���ض�
// #pragma warning(disable: 4309) // (33)  ����ʼ����: �ضϳ���ֵ
// #pragma warning(disable: 4018) // (240) ��<��: �з���/�޷��Ų�ƥ�� 
// #pragma warning(disable: 4477) // (67)  ��printf��: ��ʽ�ַ�����%x����Ҫ���͡�unsigned int���Ĳ��������ɱ���� 2 ӵ�������͡�int *��


using namespace std;


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
	//����STL��reserve��resize����
	test_Reserve_Resize_Main();

    return;
}