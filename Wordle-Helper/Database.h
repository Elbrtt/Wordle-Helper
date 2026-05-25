#pragma once
#include <vector>
#include <string>
using namespace std;

struct word {
	string chara = "DEFAULT";
	int matching = 0;
	word() {}
	word(const string& s):chara(s){}


	void print();

};


class Database {
private:
	vector<word> db;
public:
	Database();
	void traverseWord();
	void searchWord(const string& word);
	void print();
	void sortDB();
	void processData(const string& filename);
	void addData(const string& s);
};