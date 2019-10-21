#include <iostream>
#include <iomanip>
#include <limits>
#include <locale.h>
#include <windows.h>

using namespace std;

//Função que calcula o mips
void calculateMips(){
	int numberOpration = 0,option =0;  
	float timeProcessing = 0; 
	do{
		system("cls");
		cout << "\n type the number of operations: ";
		cin>>numberOpration;
	}while(numberOpration<0);
	do{
		system("cls");
		cout << "\n type the Processing time: ";
		cin>>timeProcessing;
	}while(timeProcessing<0);
	cout << "\n Mips =  " << numberOpration/timeProcessing<<"\n\n";
	system("pause");
	do{	
		system("cls");
		cout << "\n select option";
		cout << "\n 1 - performance measurement of a computer(MIPS)";
		cout << "\n 2 - Exit \n";
		cin>>option;
		switch(option){
			case 1:
				calculateMips();
				break;
		}
	}while(option!=2);
}


int main(){
	int option =1;
	//Permite a utilização de caracteres UTF-8
	setlocale(LC_ALL,"PORTUGUESE");	
	do{
		system("cls");
		cout << "\n select option";
		cout << "\n 1 - performance measurement of a computer(MIPS)";
		cout << "\n 2 - Compare MIPS of two devices";
		cout << "\n 3- Exit \n";
		cin>>option;
		switch(option){
			case 1:
				calculateMips();
				break;
			case 2:
			//	comparePerformance()
				break;
		}
	}while(option!=3);
}
