#include <cstring>
#include "string2.h"
#include <cctype>

using std::cout;
int String::num_string = 0;
int String::HowMany()
{
	return num_string;
}

String::String(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	num_string++;
}

String::String()
{
	len = 1;
	str = new char[1];
	str[0] = '\0';
	num_string++;
}

String::String(const String & st)
{
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	num_string++;
}


String::~String()
{
	--num_string;
	delete[] str;
}



String & String::operator=(const String & st)

{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}



String & String::operator=(const char* s)
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;

}
char & String::operator[](int i)
{
	return str[i];
}
const char & String::operator[](int i)const
{
	return str[i];
}

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String &st1, const String &st2)
{
	return st2 < st1;
}
bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}

istream & operator>>(istream & is, String & st)
{
	char temp[String::CLIM];
	is.get(temp, String::CLIM);
	if (is)
		st = temp;
	while (is&&is.get() != '\n')
		continue;
	return is;
}

String String::operator+(String & st)const
{
	String temp;
	temp.len = len + st.len;
	delete[] temp.str;
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, size_t(temp.len + 1), str);
	strcat_s(temp.str, size_t(temp.len + 1), st.str);
	return temp;
}
String  String::operator+(const char *s)const
{
	String temp;
	temp.len = len + strlen(s);
	delete[] temp.str;
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, size_t(temp.len + 1), str);
	strcat_s(temp.str, size_t(temp.len+1), s);
	return temp;

}
void String::stringup()
{
	int i = 0;
	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}
void String::stringlow()
{
	int i = 0;
	while (str[i])
	{
		str[i] = tolower(str[i]);
		i++;
	}
}
int String::has(char ch)
{
	int count_t=0,i=0;
	while (str[i])
	{
		if (str[i] == ch)
			count_t++;
		i++;
	}
	return count_t;
}

String operator+(const char * s, const String & st)
{
	String temp;
	temp.len = st.len + strlen(s);
	delete[] temp.str;
	temp.str = new char[temp.len + 1];
	strcpy_s(temp.str, size_t(temp.len + 1), s);
	strcat_s(temp.str, size_t(temp.len + 1), st.str);
	return temp;
}
