#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	char w[20];
	GetWindowsDirectory(w, 18);
	cout << "thellouy" << w << "billgates..2006" << endl;
	system("pause");
	return 0;
}