
#include<iostream>
#include<string>
#include<sstream>
#include "../assignment1/byte.h"
using namespace std;
class key
{
public:
	byte arr[4][4];
	key()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				
				arr[i][j].setX('0');
				arr[i][j].setY('0');
			}
		}
	}
	key (string _key)
	{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					stringstream ss;
					ss << hex << (int)_key[4 * i + j];
					arr[i][j].setX(ss.str()[0]);
					arr[i][j].setY(ss.str()[1]);
				}
			}

	}
	key( key& copy)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				this->arr[i][j].setX(copy.arr[i][j].getX());
				this->arr[i][j].setY(copy.arr[i][j].getY());

			}
		}
	}
	
};

