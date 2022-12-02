// Lab08_1_rec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str, int i)
{
	if (i<strlen(str))
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
			return 1 + Count(str, i + 1);
		else
			return Count(str, i + 1);
	else
		return 0;
}
char* Change(char* dest, const char* str, char* t,size_t len, int i)
{
	if (i<len)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '=')
		{
			strcat_s(t,101, "**");
			return Change(dest, str, t + 2,len, i + 1);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, len, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';

		return dest;
	}
}

int main()
{
	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	cout << "String contained " << Count(str, 1) << " groups of '+ - ='" << endl;

	char* dest1 = new char[151];
	dest1[0] = '\0';

	char* dest2;
	size_t len = strlen(str);
	dest2 = Change(dest1, str, dest1, len, 0);

	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;

	return 0;
}

