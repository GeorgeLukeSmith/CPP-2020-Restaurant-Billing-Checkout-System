/***********************************************************************
 * Program 1.cpp
 * Program for creating Menu file
 * 09/04/2020
 * 215730
 * Version 3
***********************************************************************/

#include <iostream>
#include "interface.h"
#include "item.h"
#include "menu.h"

int main(void) {
	int choice;
	Menu currentMenu;
	Input userInput;
	Display userDisp("R.M.C. (Restaurant Menu Creation)");
	userDisp.printIntro();
	int running = 1;
	while(running == 1) {
			userDisp.printMainMenu("Please select an option\n\n");
			cout << "1. Create Menu\n2. Update Menu\n";
			choice = userDisp.printOption("3. Quit");
			switch(choice){
					case 1:
							currentMenu.updateMenu(20);
							currentMenu.printMenu();
							currentMenu.saveToFile();
							break;	
					case 2: currentMenu.openFile();
							currentMenu.updateMenu(20);
							currentMenu.saveToFile();
							break;						
					case 3: 
							running = 0;
							break;
					default:
							cout << "Invalid choice.\n"
							<< "Press ENTER to continue";
							getchar();
							break;
			}
	}
	return 0;	
}
