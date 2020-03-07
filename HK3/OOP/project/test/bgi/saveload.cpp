#include "saveload.h"

void SaveAndLoad::check(int x, int y, int val)
{
	a[x][y] = val;
}

int SaveAndLoad::value(int x, int y)
{
	return a[x][y];
}

bool SaveAndLoad::load(int n, bool type)
{
	string file;
	file = (type) ? "1p.save" : "2p.save";

	ifstream ifs(file);
	if (!ifs) return 0;

	string line;
	while (n > 0 && getline(ifs, line))
	{
		--n;
		getline(ifs, line);
	}
	getline(ifs, line);
	getline(ifs, line);

	istringstream iss(line);
	iss >> sz;

	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
		{
			int k = 0;
			if (!(iss >> k))
			{
				cout << "ERROR!";
			}
			a[i][j] = k;
		}

	return 1;
}

bool SaveAndLoad::save(const char* text, bool type)
{
	string file;
	file = (type) ? "1p.save" : "2p.save";

	ifstream ifs(file);

	string line;
	int i = 0;

	while (getline(ifs, line))
	{
		++i;
		getline(ifs, line);
	}

	ifs.close();

	ofstream ofs(file, ios::app);
	if (!ofs) return 0;

	ofs << i << ". " << text << '\n' << sz;

	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			ofs << ' ' << a[i][j];
	ofs << '\n';

	return 1;
}

bool SaveAndLoad::read(bool type)
{
	string file;
	file = (type) ? "1p.save" : "2p.save";

	ifstream ifs(file);
	if (!ifs) return 0;

	string line;
	int i = 0;

	while (getline(ifs, line))
	{
		SC sc(line);
		cout << sc.c << '\n';

		++i;
		getline(ifs, line);
	}
	return 1;
}