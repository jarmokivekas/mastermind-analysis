#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#include "master_code.h"

int value_compar(const void *a, const void *b);
void test_evaluate();
void test_increment_code();

int main(int argc, char const *argv[]) {
    int ref[] = {0,0,0,0,0};
    int i = 0;
    int values_len = (int)pow(CODE_MAX_SYMBOL + 1, CODE_LEN) + 1;
    double values[values_len];
    double min_value = 20000;
    while(increment_code(ref)){
        int table[(CODE_LEN + 1)*(CODE_LEN + 1)];
        make_table(ref, table);
        //dump_table(table);
        values[i] = table_value(table);
        if(values[i]<min_value){
            min_value = values[i];
            fprintf(stderr, "%10f:  %d %d %d %d %d\n", min_value, ref[0], ref[1], ref[2], ref[3], ref[4]);
        }
        i++;
    }
    qsort((void*)values, values_len, sizeof(double), value_compar);
    
    for (i = 0; i < values_len; i++) {
        printf("%d %f\n", i, values[i]);
    }
    
    return 0;
}

int value_compar(const void *a_p, const void *b_p){
    double a = *((double*)a_p);
    double b = *((double*)b_p);
    if (a-b < 0) {
        return -1;
    } else {
        return 1;
    }
}






/*
void test_evaluate(){
    int code[CODE_LEN] = {0,1,2,3,4};
    int test[CODE_LEN] = {0,0,4,1,1};
    printf("%d\t%d\t%d\t%d\t%d\n", test[0], test[1], test[2], test[3], test[4]);
    printf("%d\t%d\t%d\t%d\t%d\n", code[0], code[1], code[2], code[3], code[4]);
    printf("\n");
    
    int result[3] = {0,0,0};
    evaluate(code, test, result);
    printf("---\n%d\t%d\t%d\n" , result[BLACK], result[WHITE], result[EMPTY]);
    return;
    
}

void test_increment_code(){
    int code[CODE_LEN] = {0,0,0,0,0};
    while (increment_code(code)) {
        printf("%d\t%d\t%d\t%d\t%d\n", code[0], code[1], code[2], code[3], code[4]);
    }
    
}*/