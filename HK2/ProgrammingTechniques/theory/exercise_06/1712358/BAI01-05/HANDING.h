#ifndef _HANDING_H_
#define _HANDING_H_
#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<string.h>

// Ham mo file, tra ve true neu mo thanh cong, false neu that bai
bool OpenFile(FILE** fp, char filepatch[], char mode[]);

//Ham dong file
void CloseFile(FILE* fp);

//Cac ham phu cua ham void Copy(FILE* fp, char filefp[], FILE** copyfp, char newfile[]);
bool TestFileName(char S[]);
void InputFileName(char newname[], char filefp[]);
void InputLink(char link[]);

void Input(char S[], int N);
void Input(char& S);
#endif
