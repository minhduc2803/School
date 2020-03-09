#ifndef _INOUT_H_
#define _INOUT_H_
#include"INFO.h"
#include"SUPORT.h"
//------------------------------------
//--------in out from file------------
bool OpenFile(FILE** fp, char filepatch[], char mode[]);
void CloseFile(FILE* fp);
void Read(FILE** fp, char filepatch[], CUS LIST[], int& N);
void Write(FILE** fp, char filepatch[], CUS LIST[], int N);

//------------------------------------
//--------in out from the screen------
void Input(int& A);
void Input(char A[], int N);
void Input(float& A);

void InputID(char ID[], CUS LIST[], int N);
bool CompareID(char ID[], CUS LIST[], int N); //ham ho tro cho InputID
bool TestID(char ID[]); //ham ho tro cho InputID

void InputDay(char Day[], CUS LIST[], int N);
bool CompareDay(char Day[], CUS LIST[], int N); //ham so tro cho InputDay
bool TestDay(char Day[]); //ham so tro cho InputDay

void InputMAndY(char MAndY[]);
bool TestMAndY(char MAndY[]);//Ham ho tro cho InputMAndy

void InputType(int& type);

#endif

