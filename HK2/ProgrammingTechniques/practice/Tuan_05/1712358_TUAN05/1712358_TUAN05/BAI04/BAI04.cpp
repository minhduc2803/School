#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* p = fopen("file.bin", "wb");
	char* c = "abcdefghijklmnopqrstuwxyz";
	if (p != NULL) { 
		fwrite(c, sizeof(char), sizeof(c), p);
		fclose(p);
	}
}