//
//  struct.c
//  DSA
//
//  Created by Veerendra Babu Bommakanti on 5/9/26.
//
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct rectuangler{
    int length;
    int breth;
} rectanguler_t;
int main(void){
    rectanguler_t rec = {4,5};
    printf("rectanguler length : %d  breath  ; %d\n",rec.length,rec.breth);
    rec.length = 10;
    rec.breth = 123;
    printf("Modified rectanguler length : %d  breath  ; %d\n",rec.length,rec.breth);
    //pointer to a strcutre
    rectanguler_t *p = NULL;
    p = &rec;
    
    p->length = 21;
    p->breth = 10;
    printf("Modified through pointer rectanguler length : %d  breath  ; %d\n",p->length,p->breth);
   
    rectanguler_t *dynamic_ptr = (rectanguler_t *)malloc(3*sizeof(rectanguler_t));
    dynamic_ptr[1].length = 124;
    dynamic_ptr[1].breth = 213;
    dynamic_ptr[0].length = 43;
    dynamic_ptr[0].breth =45;
    dynamic_ptr[2].length = 1;
    dynamic_ptr[2].breth =0;
    printf("size of dynamic Ptr :%d\n",sizeof(dynamic_ptr));
    for (int i = 0; i < 3; i++) {
        printf("Rect %d - Length: %d, Breadth: %d\n", i, dynamic_ptr[i].length, dynamic_ptr[i].breth);
    }
}
