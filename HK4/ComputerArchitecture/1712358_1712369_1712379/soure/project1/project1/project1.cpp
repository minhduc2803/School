#include <iostream>
#include<fstream>
#include<string>

#include"io.h"
#include "qint.h"

using namespace std;

int main(int argc, char** argv)
{
	if (argc > 2)
	{
		//mở file
		ifstream InFile(argv[1]);
		ofstream OutFile(argv[2]);
		if (!(InFile.is_open() && OutFile.is_open()))
			return 1;

		string line;
		
		//đọc từng line từ input, split() rồi đưa kết quả cho hàm execute() xử lý
		//nếu xử lý thành công -> trả về 1 string, nếu ko thì in ra 1 dòng trống
		while (getline(InFile, line))
		{
			vector<string> data;
			data.clear();
			split(line, data);
			string result = execute_data(data);
			if (result.size() != 0)
				OutFile << result;
			else
				OutFile << "\n";
		}
		InFile.close();
		OutFile.close();
	}
	return 0;
}