#include <stdio.h>

typedef unsigned char              u8;  
typedef signed char                s8;

typedef unsigned short             u16;
typedef signed short               s16;

typedef unsigned int               u32;
typedef signed int                 s32;

typedef signed long long int       u64;
typedef unsigned long long int     s64;

typedef float                      f32;
typedef double                     f64;

typedef long double                f128;

void main(void)
{
    printf("the size of u8 : %u\n",sizeof(u8));
    printf("the size of s8 : %u\n",sizeof(s8));

    printf("the size of u16 : %u\n",sizeof(u16));
    printf("the size of s16 : %u\n",sizeof(s16));

    printf("the size of u32 : %u\n",sizeof(u32));
    printf("the size of s32 : %u\n",sizeof(s32));

    printf("the size of u64 : %u\n",sizeof(u32));
    printf("the size of s64 : %u\n",sizeof(s32));

    printf("the size of f32 : %u\n",sizeof(f32));
    printf("the size of f64 : %u\n",sizeof(f64));
    
    printf("the size of f128 : %u\n",sizeof(f128));
}