#include "Database.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

void word::print()
{
	cout << "Word: [" << chara << "] Similarity: <" << matching <<">" << endl;
}
Database::Database()
{
	processData("DataFile/db.txt");
}

void Database::processData(const string& filename)
{
	ifstream filein(filename);
	string data;

	if (!filein.good())
	{
		cout << "{WARNING} Database not found!, this program won't work!"<<endl<<endl;
		return;
	}

	while (filein >> data)
	{
		addData(data);
	}
}

void Database::print()
{	
	cout << endl;
	bool mostLikely = true;
	bool Likely = true;
	bool Nope = true;
	int i = 0;
	for (auto& d : db)
	{	
		if (i >= 30)
		{
			break;
		}

		if (d.matching > 3 && mostLikely)
		{
			cout << "===========[MOST LIKELY]===========:\n\n";
			mostLikely = false;
		}
		if (d.matching == 3 && Likely)
		{
			cout << "\n=============[LIKELY]=============:\n\n";
			Likely = false;
		}
		if (d.matching < 3 && Nope)
		{
			cout << "\n==============[NOPE]==============:\n\n";
			Nope = false;
		}
		if((i + 1) < 10) 		cout << i + 1 << ")  ";
		else 		cout << i + 1 << ") ";
		d.print();
		i++;
	 }
	cout << endl;
}

void Database::searchWord(const string& word)
{
	for (auto& d : db)
	{
		for (int i = 0; i < d.chara.size(); i++) {
			if (word[i] == d.chara[i])
			{
				d.matching++;
			}

		}
	}
	sortDB();
	print();
}

void Database::sortDB() 
{
	sort(db.begin(), db.end(), [](const word& a, const word& b) {return a.matching > b.matching;});
}

void Database::addData(const string& s)
{
	db.push_back(word(s));
}

