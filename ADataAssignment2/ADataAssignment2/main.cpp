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
ofstream FileToRead;

void ReadCSV(ofstream FileToRead)
{
	FileToRead.open("Cards.csv");
}
void main()
{

}