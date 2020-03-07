#include "Header.h"

int countWord(string path)
{
	ifstream ifs(path);
	if (!ifs)
		return 0;

	string tmp;
	int n = 0;
	while (ifs >> tmp)
		++n;

	return n;
}

hash_table* createTable(int type, string path)
{
	int n = countWord(path);
	if (!n)
		return nullptr;

	hash_table* table;

	switch (type)
	{
	case 1:
		table = new chaining(26);
		break;
	case 2:
		table = new linear(n);
		break;
	case 3:
		table = new quadratic(n);
		break;
	case 4:
		table = new doublehash(n);
		break;
	default:
		return nullptr;
		break;
	}

	ifstream ifs(path);
	string tmp;

	while (ifs >> tmp)
	{
		table->put(tmp);
	}

	return table;
}

int main()
{
	int n = 0;
	while (n < 1 || n > 4)
	{
		cout << "\n1. chainning\n";
		cout << "2. linear\n";
		cout << "3. quadratic\n";
		cout << "4. doublehash\n";
		cin >> n;
	}

	hash_table* table = createTable(n, "words_alpha.txt");
	
	string word = "";
	while (word != "exit")
	{
		cout << "\nNhap tu(exit de thoat): ";
		cin >> word;

		clock_t begin = clock();
		int ck = table->check(word);
		clock_t end = clock();

		if (ck)
			cout << "S la tu tieng Anh";
		else
			cout << "S khong phai la tu tieng Anh";

		int elapsed = (end - begin) / CLOCKS_PER_SEC;
		cout << "Elapsed time: " << elapsed << '\n';
	}

	delete table;

	return 0;
}