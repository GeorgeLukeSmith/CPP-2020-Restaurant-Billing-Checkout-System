/***********************************************************************
 * bill.h
 * Header file containing Bill class
 * 06/04/2020
 * 215730
 * Version 1
***********************************************************************/

#ifndef BILL_H
#define BILL_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "interface.h"
#include "menu.h"
#include "item.h"

#define MAX_ITEMS 51
#define VAT_M 0.2

using std::string;

class Bill {
private:
		int _orderNum;
		string _timeStamp;
		int _numOfItems;
		Item _order[MAX_ITEMS];
		float _cost;
		float _vat;
		float _totalCost;
public:
		//Constructor for Bill class without parameters
		Bill(){ ; }
		//Constructor for Bill class when passed a menu object
		Bill(Menu menu) {
				_numOfItems = 0;
				int amount;
				int i, j, choice;
				Display billDisp;
				Input billIn;
				for(i = 0; i < MAX_ITEMS;) {
						amount = 0;
						menu.printMenu();
						cout << "\n\nType Item Number and press ENTER"
						<< "\n\nItem Number: ";
						billIn.valid(0, menu.getNumOfItems());
						choice = billIn.get_inInt();						
						cout << "\nEnter Quantity and press ENTER"
						<< "\n\nQuantity: ";
						billIn.valid(0, MAX_ITEMS - i);
						amount = billIn.get_inInt();
						for(j = 0; j < amount; j++) {
								_order[i] = menu.getItem(choice);
								i++;
								_numOfItems ++;
						}						
						system("CLS");
						if(billDisp.printConfirm("Add another Item?") 
							== 2){ i = MAX_ITEMS + 5; }
				}
				setTime();
				calcVat();
				calcTotalCost();
		}
		//Creates a time stamp for the Bill
		setTime() {
				time_t rawtime;
  				struct tm * timeinfo;
				time (&rawtime);
				timeinfo = localtime (&rawtime);
				_timeStamp = asctime(timeinfo);
		}
		//Prints the Bill to the console
		printBill(bool clear) {
				if(clear = true){system("CLS");}
				Display billDisp;
				int i;
				_cost = 0;
				cout << "Order #" << _orderNum << "\n\n";
				for(i = 0; i < _numOfItems; i++) {
						cout << "Item " << i + 1 << "\t\t"
							<< _order[i].getName()
							<< "\nPrice:\t\t\x9C";
						printf("%.2f", _order[i].getPrice());
						calcCost(i);
						cout << std::endl << std::endl;
				}
				calcVat();
				calcTotalCost();
				cout << "Total:\t\t\x9C";
				printf("%.2f", _cost);
				cout << "\nVAT:\t\t\x9C";
				printf("%.2f", _vat);
				cout << "\nTotal with VAT:\t\x9C";
				printf("%.2f", _totalCost);
				cout << "\n\n" << _timeStamp;
				billDisp.waitForInput();
		}
		void calcCost(int i) { _cost =  _cost + _order[i].getPrice(); }
		//Calculates the total cost of the bill
		void calcTotalCost() { _totalCost = _cost + _vat; }
		//Calculates VAT for the bill
		void calcVat(){
				_vat = _cost * VAT_M;
		}
		//Returns the order number
		int getOrderNum() { return _orderNum;}
		//Returns the number of items
		int getNumOfItems() { return _numOfItems; }
		//Returns the sum cost of all items ont the bill
		float getCost() { return _cost; }
		//returns the name of a specific item on the bill
		string getIName(int itemNum) {
				return _order[itemNum].getName();
		}
		//returns the price of a specific item on the bill
		float getIPrice(int itemNum) {
				return _order[itemNum].getPrice();
		}
		//Returns the VAT of the bill
		float getVAT() { return _vat; }
		//Returns the total cost of the bill
		float getTotalCost() { return _totalCost; }
		//Sets the order number of the bill to the value of num
		void setOrderNum(int num) { _orderNum = num; }
		//Sets the number of items on the bill to the value of num
		void setNumOfItems(int num) { _numOfItems = num; }
		//Sets the cost of the bill to the value of num
		void setCost(float num) { _cost = num; }
		//sets an item on the bill to that of an item on the menu
		void setItem(Menu menu, int i, int itemNum) {
				_order[i] = menu.getItem(itemNum);
		}		
};

#endif
