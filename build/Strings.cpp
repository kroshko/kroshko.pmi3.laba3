#include "Strings.h"

TString::TString()
{
	str = nullptr;
	len = 0;
}


TString::TString(char h, int l)
{
	str = new char[l + 1];
	for (int i = 0; i < l; i++)
		str[i] = h;
	str[l] = '\0';
}

TString::TString(char* p)
{
	int len;
	len = strlen(p);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		str[i] = p[i];
	}
	str[len] = '\0';
}

TString::TString(const TString& p)
{
	int len;
	len = strlen(p.str);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = p.str[i];
	}
	this->str[len] = '\0';

}

TString::~TString()
{
	if (str != 0)
	{
		delete[]str;
		str = 0;
	}
}

void TString::Print()
{
	std::cout << this->str << std::endl;
}


char &TString::operator[](int i)
{
	int len;
	char q;
	len = strlen(this->str);
	if (i < len)
		q = this->str[i];
	return q;
}

TString TString::operator +(const TString& p)
{
	int len,i ;
	TString temp(p);
	TString res(*this);
	res.len += p.len;
	for (int i = 0; i < p.len; i++)
	{
		temp[i] = p[i];
	}
	if (len == 0)
		return temp;
}

TString& TString::operator=(const TString& p)
{
	if (this->str != nullptr)
		delete[] this->str;
	int len;
	len = strlen(p.str);
	str = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		this->str[i] = p.str[i];
	}
	this->str[len] = '\0';
	return *this;
}

bool TString::operator==(const TString& p)
{
	int len1, len2;
	len1 = strlen(this->str);
	len2 = strlen(p.str);
	if (len1 = len2)
		for (int i = 0; i < len2; i++)
			if (this->str[i] != p.str[i])
				return false;
	return true;
}

bool TString::operator<(const TString& p)
{
	int len1, len2;
	len1 = strlen(this->str);
	len2 = strlen(p.str);
	if (len1 < len2)
		return true;
	return false;
}

bool TString::operator>(const TString& p)
{
	int len1, len2;
	len1 = strlen(this->str);
	len2 = strlen(p.str);
	if (len1 > len2)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& out, const TString& p)
{
	if (p.str != nullptr)
		out << "string = " << p.str << std::endl;
	return out;
}

std::istream& operator>>(std::istream& input, TString& p)
{
	input >> p.str;
	return input;
}

int TString::FindWord(char* s)
{
	int f = 0;
	if (s == 0)
		throw" ошибка ";
	int len = strlen(this->str);
	for (int i = 0; i < len; i++)
	{
		if (this->str[i] == s[0])
		{
			for (int j = 0; j < len; j++)
				if (this->str[i + j] == s[j])
					f = i;
		}
	}
	std::cout << f << std::endl;
	return f;
}

int TString::FindLetter(char s)
{
	int f = 0;
	int len = strlen(this->str);
	for (int i = 0; i < len; i++)
		if (this->str[i] == s)
		{
			f = i + 1;
			std::cout << f << std::endl;
			break;
		}
	if (f == 0)
		std::cout << "Эта буква отсутсвует " << std::endl;
	return f;
}

//одно дополнительное задание

TString TString::Dop(int k) 
{
	if (k <= 0)
		throw " ошибка ";

	TString temp(*this);

	if (k == 1)
		return *this;

	for (int i = 0; i < k - 1; i++) {
		temp = temp + *this;
	}
	return temp;

}
