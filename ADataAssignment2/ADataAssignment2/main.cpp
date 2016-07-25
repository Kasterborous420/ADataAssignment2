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
using std::stoi;

//File To Read//
std::ifstream FileToRead;
std::ifstream FileSize;

int size = 0;

CCards *cardArray;

//Read CSV and parse into CCards object
void ReadCSV()
{
	FileToRead.open("CR_Cards.csv");
	FileSize.open("CR_Cards.csv");
	
	string line;

	while (getline(FileSize, line))
	{
		size++;
	}
	cardArray = new CCards[size];

	if (FileToRead.is_open())
	{
		
		
		int index = 0;

		while (getline(FileToRead, line))
		{

			CCards *card = new CCards();

			//Read each string to ","
			//how to check for the end though?

			//Get Card Name
			for (int i = 0; i <= line.length(); i++)
			{
				string dataString = "";
				if (line[i] == ',' || line[i] == '\0')
				{
					//Separate and Erase the line from file
					dataString = line.substr(0, i);
					line.erase(0, i + 1);
					i = 0;

					//Parse String into Variables
					if (cardArray[index].getName() == "")
					{
						cardArray[index].setName(dataString);
					}
					else if (cardArray[index].getCost() == 0)
					{
						cardArray[index].setCost(stoi(dataString, nullptr, 10));
					}
					else if (cardArray[index].getRARITY() == "")
					{
						cardArray[index].setRARITY(dataString);
					}
					else if (cardArray[index].getTYPE() == "")
					{
						cardArray[index].setTYPE(dataString);
					}
					else if (cardArray[index].getTARGETS() == "")
					{
						cardArray[index].setTARGETS(dataString);
					}
					else if (cardArray[index].getHealth() == 0)
					{
						cardArray[index].setHealth(stoi(dataString, nullptr, 10));
					}
					else if (cardArray[index].getDamage() == 0)
					{
						cardArray[index].setDamage(stoi(dataString, nullptr, 10));
					}
				}
			}

			//increment cardArray[index]
			index++;

		}
		FileToRead.close();
	}
}


void main()
{
	ReadCSV();
	for (int i = 0; i < size; i++)
	{
		cout << cardArray[i] << endl;
	}
	system("pause");
}