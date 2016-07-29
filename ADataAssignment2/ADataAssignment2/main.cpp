#include <iostream>
#include <istream>
#include <fstream>
#include <string>
#include "Cards.h"
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ofstream;
using std::stoi;
using std::vector;

//File To Read//
std::ifstream FileToRead;
std::ifstream FileSize;

int size = 0;
bool running = true;

CCards *cardArray;
vector<CCards> searchResult;

//Flush cin buffer
void FlushBuffer()
{
	cin.clear();
	fflush(stdin);
}

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

//Render Menu
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

	cout << "Enter Choice: ";

}

//Display Cards
void DisplayAll( int _displayChoice )
{
	cout << endl;

	if (_displayChoice == 1)
	{
		for (int i = 0; i < size; i++)
		{
			cout << "[" << i + 1 << "] " << cardArray[i] << endl;
		}
	}
	else if (_displayChoice == 2)
	{
		for (int i = size; i > 0; i--)
		{
			cout << "[" << i  << "] " << cardArray[i - 1] << endl;
		}
	}

	cout << endl;
	cout << endl;
	
	system("pause");
}

//Sort Cards
void Sort(int _choice)
{
	//Sort By Card Name
	if (_choice == 1)
	{
		for (int i = 0; i < size; i++)
		{
			for (int index = 0; index + 1 < size - i; index++)
			{

				if (cardArray[index].getName() > cardArray[index + 1].getName())
				{
					//Big Swap
					CCards temp = cardArray[index];
					cardArray[index] = cardArray[index + 1];
					cardArray[index + 1] = temp;
				}
			}
		}
	}
	//Sort by Elixir Cost
	else if (_choice == 2)
	{
		for (int i = 0; i < size; i++)
		{
			for (int index = 0; index + 1 < size - i; index++)
			{

				if (cardArray[index].getCost() > cardArray[index + 1].getCost())
				{
					//Big Swap
					CCards temp = cardArray[index];
					cardArray[index] = cardArray[index + 1];
					cardArray[index + 1] = temp;
				}
			}
		}
	}
	//Sort by Rarity
	else if (_choice == 3)
	{
		for (int i = 0; i < size; i++)
		{
			for (int index = 0; index + 1 < size - i; index++)
			{

				if (cardArray[index].getRARITY() > cardArray[index + 1].getRARITY())
				{
					//Big Swap
					CCards temp = cardArray[index];
					cardArray[index] = cardArray[index + 1];
					cardArray[index + 1] = temp;
				}
			}
		}
	}
	//Sort by Type
	else if (_choice == 4)
	{
		for (int i = 0; i < size; i++)
		{
			for (int index = 0; index + 1 < size - i; index++)
			{

				if (cardArray[index].getTYPE() > cardArray[index + 1].getTYPE())
				{
					//Big Swap
					CCards temp = cardArray[index];
					cardArray[index] = cardArray[index + 1];
					cardArray[index + 1] = temp;
				}
			}
		}
	}
	//Sort by Targets
	else if (_choice == 5)
	{
		for (int i = 0; i < size; i++)
		{
			for (int index = 0; index + 1 < size - i; index++)
			{

				if (cardArray[index].getTARGETS() > cardArray[index + 1].getTARGETS())
				{
					//Big Swap
					CCards temp = cardArray[index];
					cardArray[index] = cardArray[index + 1];
					cardArray[index + 1] = temp;
				}
			}
		}
	}
	//Sort by Hitpoints
	else if (_choice == 6)
	{
		for (int i = 0; i < size; i++)
		{
			for (int index = 0; index + 1 < size - i; index++)
			{

				if (cardArray[index].getHealth() > cardArray[index + 1].getHealth())
				{
					//Big Swap
					CCards temp = cardArray[index];
					cardArray[index] = cardArray[index + 1];
					cardArray[index + 1] = temp;
				}
			}
		}
	}
	//Sort by Damage
	else if (_choice == 7)
	{
		for (int i = 0; i < size; i++)
		{
			for (int index = 0; index + 1 < size - i; index++)
			{

				if (cardArray[index].getDamage() > cardArray[index + 1].getDamage())
				{
					//Big Swap
					CCards temp = cardArray[index];
					cardArray[index] = cardArray[index + 1];
					cardArray[index + 1] = temp;
				}
			}
		}
	}

}

//Search Cards
void Search(int _choice, int _choiceValue, int _choice2, int _choiceValue2, string _enumString, string _enumString2)
{
	//==SEARCH FOR FIRST CONDITION AND ADD THEM TO THE VECTOR==//
	
	//Clear Vector
	searchResult.clear();

	//Search By Elixir Cost
	if (_choice == 1)
	{
		for (int i = 0; i < size; i++)
		{
			if (cardArray[i].getCost() == _choiceValue)
			{
				searchResult.push_back(cardArray[i]);
			}
		}
	}
	//Search by Rarity
	else if (_choice == 2)
	{
		for (int i = 0; i < size; i++)
		{
			if (cardArray[i].getRARITY() == _enumString)
			{
				searchResult.push_back(cardArray[i]);
			}
		}
	}
	//Search by Type
	else if (_choice == 3)
	{
		for (int i = 0; i < size; i++)
		{
			if (cardArray[i].getTYPE() == _enumString)
			{
				searchResult.push_back(cardArray[i]);
			}
		}
	}
	//Search by Target
	else if (_choice == 4)
	{
		for (int i = 0; i < size; i++)
		{
			if (cardArray[i].getTARGETS() == _enumString)
			{
				searchResult.push_back(cardArray[i]);
			}
		}
	}
	//Search by HP
	else if (_choice == 5)
	{
		for (int i = 0; i < size; i++)
		{
			if (cardArray[i].getHealth() == _choiceValue)
			{
				searchResult.push_back(cardArray[i]);
			}
		}
	}
	//Search by Damage
	else if (_choice == 6)
	{
		for (int i = 0; i < size; i++)
		{
			if (cardArray[i].getDamage() == _choiceValue)
			{
				searchResult.push_back(cardArray[i]);
			}
		}
	}

	if (_choice2 < 7 && _choice2 > 0)
	{
		//==GO THROUGH THE VECTOR AND REMOVE THOSE WHO DO NOT MEET THE SECOND CONDITION==//
		for (int i = 0; i < searchResult.size(); i++)
		{
			//Search Cost (Condition 2)
			if (_choice2 == 1)
			{
				if (searchResult[i].getCost() != _choiceValue2)
				{
					searchResult.erase(searchResult.begin() + i);
					i -= 1;
				}
			}
			else if (_choice2 == 2)
			{
				if (searchResult[i].getRARITY() != _enumString2)
				{
					searchResult.erase(searchResult.begin() + i);
					i -= 1;
				}
			}
			else if (_choice2 == 3)
			{
				if (searchResult[i].getTYPE() != _enumString2)
				{
					searchResult.erase(searchResult.begin() + i);
					i -= 1;
				}
			}
			else if (_choice2 == 4)
			{
				if (searchResult[i].getTARGETS() != _enumString2)
				{
					searchResult.erase(searchResult.begin() + i);
					i -= 1;
				}
			}
			else if (_choice2 == 5)
			{
				if (searchResult[i].getHealth() != _choiceValue2)
				{
					searchResult.erase(searchResult.begin() + i);
					i -= 1;
				}
			}
			else if (_choice2 == 6)
			{
				if (searchResult[i].getDamage() != _choiceValue2)
				{
					searchResult.erase(searchResult.begin() + i);
					i -= 1;
				}
			}
		}
	}

}

//Render Sorting Menu
void RenderSortMenu()
{
	cout << endl;

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

	Sort(_choice);
	DisplayAll(_displayChoice);

	cout << endl;
	cout << endl;


}

//Render Searching Menu
void RenderSearchMenu()
{
	cout << endl;

	cout << "< Search >" << endl;
	cout << "< Add First Condition >" << endl;
	cout << "(1) Elixir Cost" << endl;
	cout << "(2) Rarity" << endl;
	cout << "(3) Type" << endl;
	cout << "(4) Targets" << endl;
	cout << "(5) Hitpoints" << endl;
	cout << "(6) Damage" << endl;

	int _choice = 0;
	int _choiceValue = 0;
	int _choiceValue2 = 0;
	int _displayChoice = 0;
	int _displayValue = 0;
	string _enumString = "";
	string _enumString2 = "";

	cout << "Condition 1: ";
	cin >> _choice;
	cout << "Condition Value: ";
	if (_choice == 1 || _choice == 5 || _choice == 6)
	{
		cin >> _choiceValue;
	}
	else if (_choice > 1 && _choice < 5)
	{
		cin >> _enumString;
	}
	else
	{
		cout << "Condition Not Found" << endl;
	}


	cout << "Add Second Condition" << endl;
	cout << "(1) Elixir Cost" << endl;
	cout << "(2) Rarity" << endl;
	cout << "(3) Type" << endl;
	cout << "(4) Targets" << endl;
	cout << "(5) Hitpoints" << endl;
	cout << "(6) Damage" << endl;
	cout << "(7) None" << endl;

	cout << "Condition 2: ";
	int _choice2 = 0;
	cin >> _choice2;

	cout << "Condition Value: ";

	if (_choice2 == 1 || _choice2 == 5 || _choice2 == 6)
	{
		cin >> _choiceValue2;
	}
	else if (_choice2 > 1 && _choice2 < 5)
	{
		cin >> _enumString2;
	}
	else
	{
		cout << "No Condition" << endl;
	}
	

	Search( _choice, _choiceValue, _choice2, _choiceValue2, _enumString, _enumString2);
	for (int i = 0; i < searchResult.size(); i++)
	{
		cout << searchResult[i] << endl;
	}

	system("pause");
}

//Render UserInput
void UserInput()
{
	FlushBuffer();
	int choice = 0;
	cin >> choice;

	switch (choice)
	{
	case 1:
		DisplayAll(1);
		break;
	case 2:
		RenderSortMenu();
		break;
	case 3:
		RenderSearchMenu();
		break;
	case 4:
		running = false;
	}
}

void main()
{
	ReadCSV();
	while (running)
	{
		RenderMenu();
		UserInput();
	}
	
	cout << "Application Closing" << endl;
	delete[] cardArray;
	system("pause");
}