#include "master_code.h"

void make_table(int *refCode, int *table) {
    int result[] = {0,0,0};
    
    memset(table, 0, (CODE_LEN+1)*(CODE_LEN+1)*sizeof(int));    
    
    int code[CODE_LEN];
    memset(code, 0, CODE_LEN*sizeof(int));
    
    while (increment_code(code)) {
        evaluate(refCode, code, result);
        //printf("refs: %d %d %d\n", refCode[0], refCode[1], refCode[2]);
        //printf("code: %d %d %d\n", code[0], code[1], code[2]);
        //printf("resu: %d %d %d\n\n", result[0], result[1], result[2]);
        table[result[BLACK] * (CODE_LEN+1) + result[WHITE]]++;
    }
}

void dump_table(int *table) {
    FILE *fout = fopen(TABLE_DAT_FILE, "w");
    int i,j;
    for (i=0; i<(CODE_LEN+1); i++){
        for (j=0; j<(CODE_LEN+1); j++){
            fprintf(fout, "%d\t", table[i*(CODE_LEN+1) + j]);
        }
        fprintf(fout, "\n");
    }
    fclose(fout);
}

double table_value(int *table){
    int i,j;
    double sum = 0;
    for (i=0; i<(CODE_LEN+1); i++){
        for (j=0; j<(CODE_LEN+1); j++){
            sum += pow((double)table[i*(CODE_LEN+1) + j],2.0);
        }
    }
    sum = pow(sum, 0.5);
    return sum;
}

int *evaluate(int *a, int *b, int *result){
    int used_a[CODE_LEN];
    int used_b[CODE_LEN];
    memset(used_a, 0x00, CODE_LEN*sizeof(int));
    memset(used_b, 0x00, CODE_LEN*sizeof(int));
    memset(result, 0x00, 3 * sizeof(int));
    int i,j;
    
    //printf("---\n");
    
    //blacks
    for (i = 0; i < CODE_LEN; i++) {
        if (a[i] == b[i]) {
            used_a[i] = 1;
            used_b[i] = 1;
            result[BLACK]++;
            //printf("bf: %d\t%d\n", i,i);
        }
    }
    
    //printf("---\n");
    // whites
    for (i = 0; i < CODE_LEN; i++) {
        //printf("%d\n", i);
        if (used_a[i] == 1) {
            continue;
        }
        for (j = 0; j < CODE_LEN; j++) {
            //printf("\t%d\n", j);
            if (used_b[j] == 1) {
                continue;
            }
            if (a[i] == b[j]) {
                used_a[i] = 1;
                used_b[j] = 1;
                result[WHITE]++;
                //printf("wf: %d\t%d\n", i,j);
                break;
                
            }
        }
    }
    
    //empties
    result[EMPTY] = CODE_LEN - result[WHITE] - result[BLACK];
    
    return result;
}



int increment_code(int *code){
    int i = 0;
    for(i = 0; i < CODE_LEN; i++) {
        code[i]++;
        if (code[i] <= CODE_MAX_SYMBOL) {
            return 1;
        }
        code[i] = 0;
    }
    return 0;
}