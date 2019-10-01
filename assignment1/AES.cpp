#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include"fstream"
#include"../assignment1/key.h"
#include"../assignment1/byte.h"
using namespace std;
int hexToDec(char x)
{
	switch (x)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	case 'A':
		return 10;
	case 'B':
		return 11;
	case 'C':
		return 12;
	case 'D':
		return 13;
	case 'E':
		return 14;
	case 'F':
		return 15;
	}

}
void byteSub(byte subBox[16][16], byte sub[4][4], int row)
{
	
	for (int i = 0; i < 4; i++)
	{
	
		int y = hexToDec(sub[row][i].getY());
		int x = hexToDec(sub[row][i].getX());
		//cout << x << " "<<y<<endl;
		sub[row][i].setX(subBox[x][y].getX());
		sub[row][i].setY(subBox[x][y].getY());
	}
}
void helpShiftRows(byte ptr[4][4], int size, int row)
{
	//second row row
	byte temp = ptr[row][0];
	for (int i = 1; i <size; i++)
	{
		ptr[row][i - 1] = ptr[row][i];
	}
	ptr[row][size - 1] = temp;
}
void shiftRows(byte ptr[4][4], int size)
{
	helpShiftRows(ptr, 4, 1);
	helpShiftRows(ptr, 4, 2);
	helpShiftRows(ptr, 4, 2);
	helpShiftRows(ptr, 4, 3);
	helpShiftRows(ptr, 4, 3);
	helpShiftRows(ptr, 4, 3);

}
byte subBox[16][16];
int matrix[4][4] = {{2,3,1,1},{1,2,3,1},{1,1,2,3}, {3,1,1,2}};
key roundKeys[11];
void subBoxGenerate()
{
	int s[256]=
	{ 0x63 ,0x7c ,0x77 ,0x7b ,0xf2 ,0x6b ,0x6f ,0xc5 ,0x30 ,0x01 ,0x67 ,0x2b ,0xfe ,0xd7 ,0xab ,0x76
	,0xca ,0x82 ,0xc9 ,0x7d ,0xfa ,0x59 ,0x47 ,0xf0 ,0xad ,0xd4 ,0xa2 ,0xaf ,0x9c ,0xa4 ,0x72 ,0xc0
	,0xb7 ,0xfd ,0x93 ,0x26 ,0x36 ,0x3f ,0xf7 ,0xcc ,0x34 ,0xa5 ,0xe5 ,0xf1 ,0x71 ,0xd8 ,0x31 ,0x15
	,0x04 ,0xc7 ,0x23 ,0xc3 ,0x18 ,0x96 ,0x05 ,0x9a ,0x07 ,0x12 ,0x80 ,0xe2 ,0xeb ,0x27 ,0xb2 ,0x75
	,0x09 ,0x83 ,0x2c ,0x1a ,0x1b ,0x6e ,0x5a ,0xa0 ,0x52 ,0x3b ,0xd6 ,0xb3 ,0x29 ,0xe3 ,0x2f ,0x84
	,0x53 ,0xd1 ,0x00 ,0xed ,0x20 ,0xfc ,0xb1 ,0x5b ,0x6a ,0xcb ,0xbe ,0x39 ,0x4a ,0x4c ,0x58 ,0xcf
	,0xd0 ,0xef ,0xaa ,0xfb ,0x43 ,0x4d ,0x33 ,0x85 ,0x45 ,0xf9 ,0x02 ,0x7f ,0x50 ,0x3c ,0x9f ,0xa8
	,0x51 ,0xa3 ,0x40 ,0x8f ,0x92 ,0x9d ,0x38 ,0xf5 ,0xbc ,0xb6 ,0xda ,0x21 ,0x10 ,0xff ,0xf3 ,0xd2
	,0xcd ,0x0c ,0x13 ,0xec ,0x5f ,0x97 ,0x44 ,0x17 ,0xc4 ,0xa7 ,0x7e ,0x3d ,0x64 ,0x5d ,0x19 ,0x73
	,0x60 ,0x81 ,0x4f ,0xdc ,0x22 ,0x2a ,0x90 ,0x88 ,0x46 ,0xee ,0xb8 ,0x14 ,0xde ,0x5e ,0x0b ,0xdb
	,0xe0 ,0x32 ,0x3a ,0x0a ,0x49 ,0x06 ,0x24 ,0x5c ,0xc2 ,0xd3 ,0xac ,0x62 ,0x91 ,0x95 ,0xe4 ,0x79
	,0xe7 ,0xc8 ,0x37 ,0x6d ,0x8d ,0xd5 ,0x4e ,0xa9 ,0x6c ,0x56 ,0xf4 ,0xea ,0x65 ,0x7a ,0xae ,0x08
	,0xba ,0x78 ,0x25 ,0x2e ,0x1c ,0xa6 ,0xb4 ,0xc6 ,0xe8 ,0xdd ,0x74 ,0x1f ,0x4b ,0xbd ,0x8b ,0x8a
	,0x70 ,0x3e ,0xb5 ,0x66 ,0x48 ,0x03 ,0xf6 ,0x0e ,0x61 ,0x35 ,0x57 ,0xb9 ,0x86 ,0xc1 ,0x1d ,0x9e
	,0xe1 ,0xf8 ,0x98 ,0x11 ,0x69 ,0xd9 ,0x8e ,0x94 ,0x9b ,0x1e ,0x87 ,0xe9 ,0xce ,0x55 ,0x28 ,0xdf
	,0x8c ,0xa1 ,0x89 ,0x0d ,0xbf ,0xe6 ,0x42 ,0x68 ,0x41 ,0x99 ,0x2d ,0x0f ,0xb0 ,0x54 ,0xbb ,0x16 };
	char x;
	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			stringstream xx;
			xx << hex << s[(i * 16) + j];
			
			subBox[i][j].setX(xx.str()[0]);
			if (s[(i * 16) + j] < 16) {
				subBox[i][j].setX('0');
				subBox[i][j].setY(xx.str()[0]);
			}
			else
			subBox[i][j].setY(xx.str()[1]);
		}
	}
}
key roundKeyGenerator(key _key)
{
	roundKeys[0] = _key;
	key gw3(_key);
	helpShiftRows(gw3.arr, 4, 3);
	byteSub(subBox, gw3.arr, 3);
	gw3.arr[3][0].setY(gw3.arr[3][0].getX() ^ '1');
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << gw3.arr[i][j].getX() << gw3.arr[i][j].getY() << " ";
		}
		cout << endl;
	}
	

	return _key;
}
int main()
{
	key _plaintext("Two One Nine Two");
	key _key("Thats my Kung Fu");
	subBoxGenerate();
	roundKeyGenerator(_key);
}