#include <iostream>
#include "Strings.h"

int main()
{
	TString str("probnoe");
	TString str4('k', 4);
	TString str1(str);
	TString str2;
	TString str5("string");
	TString str6("hello world");
	str4.Print();
	str.Print();
	str1.Print();
	str2 = str + str1;
	str2.Print();
	if (str == str2)
		std::cout << "Compare!" << std::endl;
	else
		std::cout << "NOT Compare!" << std::endl;
	char q;
	q = str1[2];
	std::cout << q << std::endl;
	std::cout << str2;
	str5.FindWord("tr");
	str.FindLetter('s');
	str5.Dop(8);
	str6.Division(' ');
	return 0;
}
