#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "Cards.h"
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ofstream;

//File To Read//
std::ifstream FileToRead;


void ReadCSV()
{
	FileToRead.open("CR_Cards.csv");
	string line;
	int size = 0;

	if (FileToRead.is_open())
	{
		while (getline(FileToRead, line))
		{
			size++;
		}
		CCards *cardArray = new CCards[size];

		while (getline(FileToRead, line))
		{
			int index = 0;

			CCards card;

			//Read each string to ","
			//how to check for the end though?

			for (int i = 0; i < line.size(); i++)
			{
				
			}

			cardArray[index] = card;
			index++;

		}
		FileToRead.close();
	}
}
void main()
{
	ReadCSV();

	system("pause");
}