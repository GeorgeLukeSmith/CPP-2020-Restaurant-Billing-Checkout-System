/***********************************************************************
 * item.h
 * Header file containing Item class
 * 02/04/2020
 * 215730
 * Version 1
***********************************************************************/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "interface.h"

using std::string;
using std::cout;

class Item {
private:
		int _itemNum;
		string _itemName;
		string _itemCategory;
		string _itemDescription;
		float _itemPrice;
		int _itemAmountSold = 0;
public:
		//Constructor for Item without parameters		
		Item() { ; };
		//Constructor with itemNum parameter
		Item(int itemNum) {
				_itemNum = itemNum;
				int hold = 1;
				Input itemIn;
				Display itemDsp;
				while(hold == 1) {
						cout << "item " << _itemNum << "\n\n";
						cout << "Please enter item Name\nName:\t\t";
						itemIn.valid(50);
						_itemName = itemIn.get_inString();
						cout << "\n\nPlease enter item Category\n"
							<< "Category:\t";
						itemIn.valid(100);
						_itemCategory = itemIn.get_inString();
						cout << "\n\nPlease enter item Description\n"
							<< "Description:\t";
						itemIn.valid(100);
						_itemDescription = itemIn.get_inString();
						cout << "\n\nPlease enter "
							"item Price\nPrice:\t\t";
						itemIn.valid(0.0f, 500.0f);
						_itemPrice = itemIn.get_inFloat();
						system("CLS");
						cout << "Item Number:\t\t" << _itemNum;
						cout << "\nItem Name:\t\t" << _itemName;
						cout << "\nItem Category:\t\t" 
							<< _itemCategory;
						cout << "\nItem Description:\t" 
							<< _itemDescription;
						cout << "\n\nItem Price:\t\t" << "\x9C"
							<< _itemPrice << "\n\n";
						if(itemDsp.printConfirm("Is this item correct?")
							== 1) { hold = 0; } 
				}
		}
		//Returns value of _itemNum
		int getNum() { return _itemNum; }
		//Returns value of _itemName
		string getName() { return _itemName; }
		//Returns string stored in _itemCategory
		string getCategory() { return _itemCategory; }
		//Returns string stored in _itemDescription
		string getDescription() { return _itemDescription; }
		//Returns value of _itemPrice
		float getPrice() { return _itemPrice; }
		//Returns value of _itemAmountSold
		int getAmountSold() { return _itemAmountSold; }
		//Sets _itemNum to the number passed in value
		void setNum(int value) { _itemNum = value; }
		//Sets _itemName to the string passed in value
		void setName(string value) { _itemName = value; }
		//Sets _itemCategory to the string passed in value
		void setCategory(string value) { _itemCategory = value; }
		//Sets _itemDescription to the string passed in value
		void setDescription(string value) { _itemDescription = value; }
		//Sets _itemPrice to the number passed in value
		void setPrice(float value) { _itemPrice = value; }
		//Increments _itemAmountSold by 1
		void incrementAmountSold() {				
				_itemAmountSold = _itemAmountSold + 1;
		}
};

#endif
