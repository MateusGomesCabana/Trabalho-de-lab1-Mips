#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <windows.h>
#include <string.h>

using namespace std;

float mips1, mips2;

//Function that make the Intro cool, maybe
void piffle()
{
	for(int i = 0; i <= 100; i++){
		system("cls");
		cout << "------------------------------------------------------\n\n";
		cout << "             CALCULATE MIPS OF PROCESSORS             \n\n";
		cout << "------------------------------------------------------\n";
		cout << "                          " << i << "%";
		if(i <= 40){
			Sleep(20);
		}else if (i < 60){
			Sleep(100);
		}else{
			Sleep(10);
		}
	}
	Sleep(1000);
}

//Function that allow input of only numbers
float input(){
	float option = 0;
	
	//Acept only number caracters
	while(!(cin >> option)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid option, please try again: ";
    }
    
    return option;
}

//Function that receive the values and calculate MIPS
void calculateMips(int save){
	//Variables declaration
	float time = 0, mips = 0, instructions = 0;
	
	//Alert the user, if is a comparison
	if(save == 2){
		system("cls");
		cout << "Now, for the second device...\n\n\n\n\n\n\n\n\n\n\n\n";
		system("pause");
	}
	
	//Receive the number of instructions
	do{
		system("cls");
		cout << "Type the number of instructions (x 10^6): ";
		instructions = input();
	}while(instructions < 0);
	
	//Receive the time passed
	do{
		system("cls");
		cout << "Type the processing time, in seconds, for that amount of instructions: ";
		time = input();
	}while(time < 0);
	
	//Calculate MIPS
	mips = instructions / time;
	
	switch(save){
		case 2:
			mips2 = mips;
			break;
		default:
			mips1 = mips;
		break;
	}
}

//MAIN FUNCTION ///////////////////////////////////////////////
int main(){
	//Intro
	piffle();
	
	mainMenu:
		
	int option = 1;
	float option2 = 1;
	char* best = "";
	
	do{
		system("cls");
		cout << "==================================================\n";
		cout << "\n                  Choose an Option\n";
		cout << "\n 1 - Calculate MIPS of a device";
		cout << "\n 2 - Compare MIPS between two devices";
		cout << "\n 3-  Exit \n";
		cout << "\n==================================================\n";
		
		//Acept only number caracters
		while(!(cin >> option)){
	        cin.clear();
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');
	        cout << "Invalid option, please try again: ";
	    }

	//Acept only 1, 2 and 3 as options
	}while(option < 1 || option > 3);
		
	switch(option){
		//Calculate MIPS of only one device
		case 1:
			oneMips:
			calculateMips(1);
			
			//Show result to the user
			system("cls");
			cout << "The MIPS of your device is =  " << setprecision(4) << mips1 << "\n\n";
			cout << "Press enter to continue...\n\n\n\n\n\n\n\n";
			system("pause");
			
			//Ask the user about the next step
			do{
				system("cls");
				cout << "Choose an option\n";
				cout << "\n 1 - Calculate again";
				cout << "\n 2 - Back to Menu \n\n";
				option2 = input();
			}while(option2 != 1 && option2 != 2);
			
			if(option2 == 1){
				goto oneMips;
			}else{
				goto mainMenu;
			}
			break;
		//Comparison of MIPS between two devices
		case 2:
			twoMips:
			calculateMips(1);
			calculateMips(2);
			
			system("cls");
			cout << "MIPS of first device: " << setprecision(2) << mips1 << "\n";
			cout << "MIPS of second device: " << setprecision(2) << mips2 << "\n\n";
			
			//Comparison
			if(mips1 < mips2){
				best = "SECOND";
			}else{
				best = "FIRST";
			}
			
			cout << "The best device was the " << best << "!\n\n";
			cout << "Press enter to continue...\n\n\n\n\n\n\n\n\n";
			system("pause");
			
			//Ask the user about the next step
			do{
				system("cls");
				cout << "Choose an option\n";
				cout << "\n 1 - Compare again";
				cout << "\n 2 - Back to Menu \n\n";
				option2 = input();
			}while(option2 != 1 && option2 != 2);
			
			if(option2 == 1){
				goto twoMips;
			}else{
				goto mainMenu;
			}
			break;
		//Exit
		case 3:
			return 0;
			break;
	}
}










