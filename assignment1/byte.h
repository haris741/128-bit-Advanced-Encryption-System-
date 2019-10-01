#pragma once
#include<string>
using namespace std;
//#include<cstring>
class byte
{
	char x;
	char y;
public:
	byte()
	{
		x = '0';
		y = '0';
	}
	char getX()
	{
		return x;
	}
	char getY()
	{
		return y;
	}
	void setX(char xx)
	{
		x = xx;
	}
	void setY(char yy)
	{
		y = yy;
	}
	string str()
	{
		string ret;
		ret = x;
		ret += y;
		return ret;


	}
};

