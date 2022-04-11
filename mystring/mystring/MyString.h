#pragma once

#include <iostream>

namespace my
{
	class string
	{
	private:
		char* str;
	public:
		string();
		string(const char* _str);
		string(const string& _refstr);
		~string();
				
		friend string operator+(const string& l_refstr, const string& r_refstr);
		string operator=(const string& _refstr);
		string& operator+=(const string& _refstr);
		bool operator==(const string& _refstr);

		friend std::ostream& operator<<(std::ostream& _os, const string& _refstr);
		friend std::istream& operator>>(std::istream& _is, string& _refstr);
	};
	string operator+(const string& l_refstr, const string& r_refstr);

	std::ostream& operator<<(std::ostream& _os, const string& _refstr);
	std::istream& operator>>(std::istream& _is, string& _refstr);
	// Out Stream
	/*class ostream
	{
	public:
		ostream& operator<< (char* str)
		{
			printf("%s", str);
			return *this;
		}
		ostream& operator<< (char str)
		{
			printf("%c", str);
			return *this;
		}
		ostream& operator<< (ostream& (*fp)(ostream& ostm))
		{
			return fp(*this);
		}
		ostream& operator<< (string& str)
		{
			printf("%s", str.str);
			return *this;
		}
	};

	ostream& endl(ostream& ostm)
	{
		ostm << '\n';
		fflush(stdout);
		return ostm;
	}
	ostream cout;

	class istream
	{
	public:
		istream& operator>> (char* str)
		{
			scanf_s("%s", str);
			return *this;
		}
		istream& operator>> (char str)
		{
			scanf_s("%c", str);
			return *this;
		}
	};
	istream cin;*/
}


