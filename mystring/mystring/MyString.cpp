#include "MyString.h"

#include <cstring>
using namespace my;

my::string::string()
{
	str = { 0, };
}

my::string::string(const char* _str)
{
	str = new char[strlen(_str) + 1];
	strcpy_s(str, strlen(_str) + 1, _str);
}

my::string::string(const string& _refstr)
{
	str = new char[strlen(_refstr.str) + 1];
	strcpy_s(str, strlen(_refstr.str) + 1, _refstr.str);
}

my::string::~string()
{
	delete[]str;
}

string my::string::operator=(const string& _refstr)
{
	delete[]str;
	int len = strlen(_refstr.str) + 1;
	this->str = new char[len];
	strcpy_s(this->str, len, _refstr.str);

	return *this;
}

string& my::string::operator+=(const string& _refstr)
{
	*this = *this + _refstr;
	return *this;
}

bool my::string::operator==(const string& _refstr)
{
	return strcmp(this->str, _refstr.str) == 0;	
}

my::string my::operator+(const string& l_refstr, const string& r_refstr)
{
	int len = strlen(l_refstr.str) + strlen(r_refstr.str) + 1;
	char* temp = new char[len];
	strcpy_s(temp, len, l_refstr.str);
	strcat_s(temp, len, r_refstr.str);

	string stemp(temp);

	return stemp;
}

std::ostream& my::operator<<(std::ostream& _os, const string& _refstr)
{
	_os << _refstr.str;
	return _os;
}

std::istream& my::operator>>(std::istream& _is, string& _refstr)
{
	char* temp = new char[1024];
	_is >> temp;
	_refstr.str = temp;
	return _is;
}
