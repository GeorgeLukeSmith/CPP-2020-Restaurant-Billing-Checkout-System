/***********************************************************************
 * TransactionStatistics.cpp
 * Program for creating statistics from menu and transaction files
 * 07/04/2020
 * 215730
 * Version 2
***********************************************************************/

#include <iostream>
#include <stdlib.h>
#include "interface.h"
#include "item.h"
#include "bill.h"
#include "tfile.h"

int main(void) {
		int choice;
		int running;
		Menu cMenu;
		TFile cTFile;
		Input userInput;
		Display userDisp("S.A.S (Statystical Analysis System)");
		userDisp.printIntro();
		system("CLS");
		cMenu.openFile();
		running = 1;
		while(running == 1){
				userDisp.printMainMenu("Please select an option\n\n");
				cout << "1. Load Transaction File\n";
				cout << "2. Statistics Menu\n";
				cout << "3. Quit";
				choice = userDisp.printOption("");
				switch(choice){
						case 1:	
								system("CLS");
								cTFile.openFile(cMenu);
								break;
						case 2: 
								userDisp.printMainMenu
								("Please select an option\n\n");
								cout << "1. Total Profits\n"
									<< "2. Item Statistics\n"
									<< "3. Return to Main Menu";
								choice = userDisp.printOption("");
								switch(choice) {
										case 1: 
												cout << "\n\n\x9C"; 
												cout <<
													cTFile.getSumProfit
														();
												userDisp.waitForInput();
											break;
										case 2:
												 cout << "\n";
												cMenu.printAmountsSold
													();
												userDisp.waitForInput();
												break;
										case 3:
												break;
										default:
												cout << "Invalid choice"
													<< "\nPress ENTER"
													<< " to continue";
												getchar();
												break;
								}													
								break;
						case 3: running = 0;
								break;
						default:cout << "Invalid choice.\n"
								<< "Press ENTER to continue";
								getchar();
								break;
				}
		}
		return 0;
}
				
		
