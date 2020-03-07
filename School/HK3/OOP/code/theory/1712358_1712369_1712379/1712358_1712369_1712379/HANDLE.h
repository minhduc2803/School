
#ifndef _HANDLE_H_
#define _HANDLE_H_
#include <stdio.h>

typedef struct Array {
	int a[1000];
	int size;
}ARRAY;

void input(ARRAY& P);
void output(ARRAY P);
int get_size(ARRAY P);
int get_value(ARRAY P, int position);
bool find_x(ARRAY P, int x, int& position);
void sort_up_ascending(ARRAY& P);
void sort_descending(ARRAY& P);

#endif
