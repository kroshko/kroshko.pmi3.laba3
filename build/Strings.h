#pragma once 
#include <iostream> 
class TString
{
protected:
	char* str;
	int len;

public:
	TString();
	TString(char h, int l);
	TString(char* p);
	TString(const TString& p);
	~TString();
	void Print();
	char& operator [](int i);

	TString& operator=(const TString& p);
	TString operator+(const TString& p);
	bool operator==(const TString& p);
	bool operator<(const TString& p);
	bool operator>(const TString& p);
	friend std::ostream& operator<<(std::ostream& out, const TString& p);
	friend std::istream& operator>>(std::istream& input, TString& p);
	int FindWord(char* s);
	int FindLetter(char s);
	TString Dop(int k);

};