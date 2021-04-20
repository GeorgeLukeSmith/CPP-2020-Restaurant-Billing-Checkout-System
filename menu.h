/***********************************************************************
 * menu.h
 * Header file containing Menu class
 * 02/04/2020
 * 215730
 * Version 1
***********************************************************************/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "item.h"
#include "interface.h"

#define MENU_MAX 20

using std::cout;
using std::ifstream;
using std::to_string;

class Menu {
private:
		Item _itemList[MENU_MAX];
		string _fileName;
		string _fileExt = ".menu";
		int _numOfItems = 0;
public:
		//Create/update a Menu to be saved to a file
		updateMenu(int maxItems) {
				string objItemName;
				Display menuDisplay;
				int hold = 1;
				while(hold == 1) {					
						system("CLS");
						objItemName = "item" + to_string(_numOfItems);
						Item objItemName(_numOfItems);
						_itemList[_numOfItems] = objItemName;
						_numOfItems ++;
						system("CLS");
						if(_numOfItems == maxItems) { hold = 0; }
						else if(menuDisplay.printConfirm
						("Add another Item?") == 2) { hold = 0; }
				}
		}
		//Print the entire menu to the console				
		void printMenu() {
				system("CLS");
				int i;
				for(i = 0; i <_numOfItems; i++) {
						cout << "Item Number:\t" 
							<< _itemList[i].getNum() << "\nItem Name:\t"
							<< _itemList[i].getName() << "\nCategory:\t"
							<< _itemList[i].getCategory()
							<< "\nDescription:\t" 
							<< _itemList[i].getDescription() 
							<< "\nPrice:\t\t\x9C";
						printf("%.2f", _itemList[i].getPrice());
						cout << std::endl << std::endl;
				}
		}
		//Save menu to a file
		void saveToFile() {
				int i;
				std::ofstream mOutFile;
				Input fileInput;
				string fileFullName;
				cout << "Enter Menu File Name\nName: ";
				fileInput.valid(20);
				_fileName = fileInput.get_inString();
				fileFullName = _fileName + _fileExt;
				mOutFile.open(fileFullName);
				for(i = 0; i <_numOfItems; i++) {
						mOutFile << _itemList[i].getNum()
							<< _itemList[i].getName() << ":"
							<< _itemList[i].getCategory() << ":"
							<< _itemList[i].getDescription() << ":"
							<< _itemList[i].getPrice() << std::endl;
				}
				mOutFile.close();
		}
		//Open menu file
		void openFile() {
				int i;
				int intHold;
				float floatHold;
				_numOfItems = 0;
				string stringHold;
				string fileFullName;
				Input fileInput;
				cout << "Enter Menu File Name\nName: ";
				fileInput.valid(20);
				_fileName = fileInput.get_inString();
				fileFullName = _fileName + _fileExt;
				std::ifstream mInFile(fileFullName);
				for(i = 0; i < MENU_MAX; i++) {
						stringHold.clear();
						mInFile >> intHold;
						_itemList[i].setNum(intHold);
						getline(mInFile, stringHold, ':');
						_itemList[i].setName(stringHold);
						stringHold.clear();
						getline(mInFile, stringHold, ':');
						_itemList[i].setCategory(stringHold);
						stringHold.clear();
						getline(mInFile, stringHold, ':');
						_itemList[i].setDescription(stringHold);
						mInFile >> floatHold;
						_itemList[i].setPrice(floatHold);						
						if(stringHold.length() > 0) { _numOfItems++; }
				}
		}
		//Prints the amount sold of every item on the menu
		printAmountsSold() {
				int i, j;
				system("CLS");
				cout << "Item Name";
				for(i = 0; i < 41; i++) {
						cout << " ";
				}
				cout << "Amount Sold\n\n";
				for(i = 0; i < getNumOfItems(); i++) {
						cout << getMenuItemName(i);
						for(j = 0; j < 50 
							- getMenuItemName(i).length(); j++) {
								cout << " ";
						}
						cout << getMenuItemAmountSold(i) << "\n";
				}
		}
		//returns name of requested item from the menu
		string getMenuItemName(int itemNum) {
				return _itemList[itemNum].getName();
		}
		//returns category of requested item from the menu
		string getMenuItemCategory(int itemNum) {
				return _itemList[itemNum].getCategory();
		}
		//returns description of requested item from the menu
		string getMenuItemDescription(int itemNum) {
				return _itemList[itemNum].getDescription();
		}
		//returns price of requested item from the menu
		float getMenuItemPrice(int itemNum) {
				return _itemList[itemNum].getPrice();
		}
		//returns amount sold of requested item from the menu
		int getMenuItemAmountSold(int itemNum) {
				return _itemList[itemNum].getAmountSold();
		}
		//returns the number of items that are on the menu
		int getNumOfItems() { return _numOfItems; }
		//returns an item from the menu
		Item getItem(int itemNum) { return _itemList[itemNum]; }
		//Increments amount sold of item on the menu by one
		void incrementAmountSold(int itemNum) {
				_itemList[itemNum].incrementAmountSold();
		}									
};

#endif
