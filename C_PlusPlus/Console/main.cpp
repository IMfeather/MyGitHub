#include <iostream>
#include "stdio.h"
#include "stdint.h"
#include "vector"
#include "time.h"
#include <cmath>
#include "string.h"
#include "stdlib.h"

#include "get100.h"                 //����1, 2, ..., 9������Ͻ������ 100
#include "StringWithMySplitFunc.h"  //split����������Ƨ����
#include "charReader.h"             //û��ʵ�ֵ�json������
#include "reserve_resize.h"         //����STL��reserve & resize ����
#include "knapstack.h"              //0-1 ��������

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


//lept_json �̳��� strtod��˵������֤
/* http://en.cppreference.com/w/c/string/byte/strtof */
#include <errno.h>
void test_strtod()
{
    const char *p = "111.11 -2.22 0X1.BC70A3D70A3D7P+6  1.18973e+309";
    printf("Parsing '%s':\n", p);
    char *end;
    for (double f = strtod(p, &end); p != end; f = strtod(p, &end))
    {
        printf("'%.*s' -> ", (int)(end - p), p);
        p = end;
        if (errno == ERANGE) {
            printf("range error, got ");
            errno = 0;
        }
        printf("%f\n", f);
    }
}


int main(void)
{
    test_knapstack();
    return 0;
}