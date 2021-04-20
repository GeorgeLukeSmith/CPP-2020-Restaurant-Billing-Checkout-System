/***********************************************************************
 * Program 2.cpp
 * Program for creating bills and transaction file
 * 07/04/2020
 * 215730
 * Version 2
***********************************************************************/

#include <iostream>
#include "interface.h"
#include "item.h"
#include "bill.h"
#include "tfile.h"

int main(void) {
	int choice;
	Menu currentMenu;
	TFile currentTFile;
	Input userInput;
	Display userDisp("B.T.S (Bill and Transaction System)");
	userDisp.printIntro();
	system("CLS");
	currentMenu.openFile();
	int running = 1;
	while(running == 1) {
			userDisp.printMainMenu("Please select an option\n\n");
			choice =
				userDisp.printOption("1. New Bill\n2. Save and Quit");
			switch(choice) {
					case 1:
							currentTFile.addBill(currentMenu);
							break;
					case 2: 
							currentTFile.saveToFile();
							running = 0;
							break;
					default:cout << "Invalid choice.\n"
							<< "Press ENTER to continue";
							getchar();
							break;
			}
	}
	return 0;	
}
