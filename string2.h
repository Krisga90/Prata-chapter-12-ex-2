#pragma once
#include <iostream>
using std::ostream;
using std::istream;

class String
{
private:
	char * str;
	int len;
	static int num_string;	//liczba obiektow;
	static const int CLIM = 80;	//limit d³ugoœci ci¹gu na wejœciu
public:
	String(const char * s);
	String();
	String(const String & st);
	~String();
	int lenght()const { return len; }

	String & operator=(const String & st);
	String & operator=(const char*);
	char & operator[](int i);
	const char & operator[](int i)const;
	String operator+( String & st)const;
	String operator+(const char *s)const;
	void stringup();
	void stringlow();
	int has(char ch);


	//funkcje zaprzyjaznione
	friend bool operator<(const String &st1, const String &st2);
	friend bool operator>(const String &st1, const String &st2);
	friend bool operator==(const String &st1, const String &st2);
	friend ostream & operator<<(ostream & os, const String & st);
	friend istream & operator>>(istream & is, String & st);
	
	friend String operator+(const char * s, const String & st);

	static int HowMany();
};


