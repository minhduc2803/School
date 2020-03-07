#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream InPut("input.txt");
	ifstream MyOutPut("project1_output.txt");
	ifstream OutPut("output.txt");
	ifstream Grade("project1_grade.txt");
	ofstream Answer("wrong_answer.txt");

	string line;
	string in, out, myout;
	int i = 1;
	while (getline(InPut,in),getline(OutPut,out),getline(MyOutPut,myout),getline(Grade, line))
	{
		if (line[0] == '0')
		{
			Answer << "input: " << in << "\n" << "output: " << out << "\n" << "myout: " << myout << "\n" << "line: " << i <<"\n" << "\n";
		}
		i++;
	}
	return 0;
}