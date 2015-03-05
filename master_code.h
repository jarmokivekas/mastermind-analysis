#ifndef master_code_h
#define master_code_h

#define TABLE_DAT_FILE "./table.dat"
#define CODE_MAX_SYMBOL 4
#define CODE_LEN 5
#define BLACK 0
#define WHITE 1
#define EMPTY 2

int *evaluate(int *a, int *b, int *result);
int increment_code(int *code);
void make_table(int* refCode, int *table);
void dump_table(int *table);
double table_value(int *table);

#endif /*master_code_h*/
