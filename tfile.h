/***********************************************************************
 * tfile.h
 * Header file containing transaction file class
 * 07/04/2020
 * 215730
 * Version 1
***********************************************************************/

#ifndef TFILE_H
#define TFILE_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "interface.h"
#include "menu.h"
#include "item.h"

#define MAX_BILLS 50

using std::string;
using std::to_string;

class TFile{
private:
		Bill _data[MAX_BILLS];
		string _fileName;
		string _fileExt = ".tf";
		int _numOfBills = 0;
		float _totalProfit;
public:
		//Add a new bill to the transaction file
		void addBill(Menu menu) {
				if(_numOfBills < MAX_BILLS) {
						Bill newBill(menu);						
						_data[_numOfBills] = newBill;
						_data[_numOfBills].printBill(1);
						_data[_numOfBills].setOrderNum(_numOfBills);
						_numOfBills++;
				}
				else {
					Display TFileDisp;
					system("CLS");
					cout << "Maximum Bill limit reached";
					TFileDisp.waitForInput();
				}
		}
		//save the transaction file
		void saveToFile() {
				int i, j, numOfItems;
				std::ofstream TOutFile;
				Input fileInput;
				string fileFullName;
				cout << "Enter Transaction File Name\nName: ";
				fileInput.valid(20);
				_fileName = fileInput.get_inString();
				fileFullName = _fileName + _fileExt;
				std::ofstream tOutFile(fileFullName);
				for(i = 0; i < _numOfBills; i++) {
						tOutFile << _data[i].getOrderNum() << " "
							<< _data[i].getNumOfItems();
						numOfItems = _data[i].getNumOfItems();						
						for(j = 0; j < numOfItems; j++) {
								tOutFile << _data[i].getIName(j)
									 << ":";
						}
						tOutFile << std::endl;
				}						
					tOutFile.close();
		}
		//Open a transaction file
		void openFile(Menu &menu) {
				int i, j, k;
				int intHold;
				float floatHold;
				string stringHoldA;
				string stringHoldB;
				string fileFullName;
				Input fileInput;
				cout << "Enter Transaction File Name\nName: ";
				fileInput.valid(20);
				_fileName = fileInput.get_inString();
				fileFullName = _fileName + _fileExt;
				std::ifstream tInFile(fileFullName);
				for(i = _numOfBills; i < MAX_BILLS; i++) {
						if(tInFile >> intHold){ _numOfBills++; }
						_data[i].setOrderNum(i);
						tInFile >> intHold;
						_data[i].setNumOfItems(intHold);
						for(j = 0; j < _data[i].getNumOfItems(); j++) {
								getline(tInFile, stringHoldA, ':');
								if(stringHoldA.length() > 0)
								for(k = 0; k < menu.getNumOfItems();
									 k++) {
										stringHoldB 
											= menu.getMenuItemName(k);										
										if(stringHoldB.compare
											(stringHoldA) == 0) {												
												_data[i].setItem
													(menu, j, k);
												menu.incrementAmountSold
													(k);
												stringHoldA.clear();
												stringHoldB.clear();
												_data[i].calcCost(j);
												_data[i].calcVat();
												_data[i].calcTotalCost
												    ();
												break;
											}
								}
					  	}
				}
				tInFile.close();
		}
		//Print all bills on the transaction file
		void printAllBills() {
				int i;
				for(i = 0; i < _numOfBills; i++) {
						_data[i].printBill(0);
				}
		}
		//returns the total profit of all bills on the transaction file
		float getSumProfit() {
				int i;
				_totalProfit = 0;
				for(i = 0; i < _numOfBills; i++){ 
						_totalProfit 
							= _totalProfit + _data[i].getTotalCost();
				}
				return _totalProfit;
		}
};

#endif


