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


void ReadCSV()
{
	FileToRead.open("CR_Cards.csv");
	FileSize.open("CR_Cards.csv");
	
	string line;
	int size = 0;

	while (getline(FileSize, line))
	{
		size++;
	}

	if (FileToRead.is_open())
	{
		CCards *cardArray = new CCards[size];

		while (getline(FileToRead, line))
		{
			int index = 0;

			CCards *card = new CCards();

			//Read each string to ","
			//how to check for the end though?

			//Get Card Name
			for (int i = 0; i <= line.size(); i++)
			{
				string dataString = "";
				if (line[i] == ',' || line[i] == '\0')
				{
					dataString = line.substr(0, i);
					line.erase(0, i + 1);

					if (card->getName() == "")
					{
						card->setName(dataString);
					}
					else if (card->getCost() == NULL)
					{
						card->setCost(stoi(dataString, nullptr, 10));
					}
					else if (card->getRARITY() == NULL)
					{
						card->setRARITY(dataString);
					}
					else if (card->getTYPE() == NULL)
					{
						card->setTYPE(dataString);
					}
					else if (card->getTARGETS() == NULL)
					{
						card->setTARGETS(dataString);
					}
					else if (card->getHealth() == NULL)
					{
						card->setHealth(stoi(dataString, nullptr, 10));
					}
				}
			}

			cardArray[index] = *card;
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