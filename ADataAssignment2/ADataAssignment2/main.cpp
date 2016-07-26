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

void RenderMenu()
{
	system("cls");

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "~ Clash Royale Card Sort System ~" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "(1) Display ALL!" << endl;
	cout << "(2) Sort Cards!" << endl;
	cout << "(3) Search for Cards!" << endl;
	cout << "(4) Quit" << endl;

}

void DisplayAll()
{
	for (int i = 0; i < size; i++)
	{
		cout << cardArray[i] << endl;
	}
}

void Sort(int _choice, int _displayChoice)
{
	if (_choice == 1)
	{

	}
	else if (_choice == 2)
	{

	}
}
void RenderSortMenu()
{
	
	cout << "< Sort Display >" << endl;


	cout << "(1) Card Name" << endl;
	cout << "(2) Elixir Cost" << endl;
	cout << "(3) Rarity" << endl;
	cout << "(4) Type" << endl;
	cout << "(5) Targets" << endl;
	cout << "(6) Hitpoints" << endl;
	cout << "(7) Damage" << endl;
	
	int _choice = 0;
	int _displayChoice = 0;

	cout << "Enter Choice: ";
	cin >> _choice;
	cout << "Ascending(1) or Descending(2)";
	cin >> _displayChoice;

	Sort(_choice, _displayChoice);

}
void RenderSearchMenu()
{

}
void UserInput()
{
	int choice = 0;
	cin >> choice;

	switch (choice)
	{
	case 1:
		DisplayAll();
		break;
	case 2:
		RenderSortMenu();
		break;
	case 3:
		RenderSearchMenu();
	case 4:
		exit(0);
	}
}

void main()
{
	ReadCSV();
	RenderMenu();
	UserInput();

	system("pause");
}