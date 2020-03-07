#ifndef _INOUT_H_
#define _INOUT_H_

#include <string.h>
#include "INFO.h"

void input(char s[], int n);
void input(int &n);
void input(mp3 list[], int n);
void input(mp3& song);
void writefile(FILE** fp, char filename[], mp3 list[], int n);
#endif
