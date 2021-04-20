/***********************************************************************
 * interface.h
 * Header file containing Interface classes
 * 02/04/2020
 * 215730
 * Version 1
***********************************************************************/

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <string>
#include <stdlib.h>

using std::string;
using std::cin;
using std::cout;

class Input {
private:
		string _inString;
		int _inInt;
		float _inFloat;
public:
		//Validates text input from the user
		void valid(int length) {				
				string input;				
				while(!(std::getline(cin, input)) 
					or input.length() > length){						
						cin.clear();						
						cin.ignore(10000,'\n');						
						cout << "\nError: input must be shorter than "
							<< length << " characters\n\n";
					}				
				_inString = input;
		}
		//Validates integer input from the user				
		void valid(int rangeL, int rangeH) {
				int input;
				while(!(cin >> input) 
					or input <= rangeL - 1 or input >= rangeH + 1) {
						cin.clear();
						cin.ignore(10000,'\n');
						cout << "\nError: input must be a whole number "
							<< "between " << rangeL << " and " 
							<< rangeH << "\n\n";
					}
				emptyBuffer();
				_inInt = input;
		}
		//Validates float input from the user
		void valid(float rangeL, float rangeH) {
				float input;
				while(!(cin >> input) 
					or input <= rangeL or input >= rangeH) {
						cin.clear();
						cin.ignore(10000,'\n');
						cout << "\nError: input must be a number "
							<< "between " << rangeL << " and " 
							<< rangeH << " (decimal accepted)\n\n";
					}
				emptyBuffer();
				_inFloat = input;
		}
		//Returns value of _inString
		string get_inString() { return _inString; }
		//Returns value of _inInt
		int get_inInt() { return _inInt; }
		//Returns value of _inFloat
		float get_inFloat() { return _inFloat; }
		//Empties the input buffer
		void emptyBuffer() { while ((getchar()) != '\n'); }
};

class Display{
	private:
		string _progName;
		string _mainMenuText;		
		string _optionText;
				
	public:
		//Constructor for Display without parameters
		Display() { }
		//Constructor for Display taking the program name
		Display(string name) {_progName = name; }
		//Print intro screen to console
		void printIntro() {
				cout << "welcome to " << _progName << "\n\npress any "
				<< "key to continue";
				getchar();
				emptyBuffer();
		}
		//Print main menu text to console
		void printMainMenu(string mainMenuText) {
				_mainMenuText = mainMenuText;
				system("CLS");
				cout << _mainMenuText;
		}
		//Print option text to console and return choice
		int printOption(string optionText) {
				int option;
				Input optionIn;	
				cout << optionText << "\n\nOption: ";
				optionIn.valid(1, 5);
				option = optionIn.get_inInt();
				return option;
		}
		//Print confirm screen to console and return choice
		int printConfirm(string confirmWhat) {
				Input confirm;
				cout << confirmWhat << " (type option and press "
				<< "enter)\n\n\t1. Yes\n\n\t2. No\n\nOption: ";
				confirm.valid(1, 2);
				return confirm.get_inInt();
		}
		//Waits for input from the user to continue
		void waitForInput() {
				cout << "\n\nPress ENTER to continue";
				getchar();
		}
		//Empties the input buffer
		void emptyBuffer() { while ((getchar()) != '\n'); }		
};

#endif

