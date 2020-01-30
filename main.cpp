#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

		        //   Rh-Hr	           	Kell		      Duffy	 Kidd      Lewis    P       MN               Luth    Xg
char Donors[11][26] = { {'+','+','0','0','+','0',  '+','+','0','+','0','+',  '+','+',  '+','+',  '0','+',  '+',  '+','0','+','0',  '+','+',  '+'}, //1
		        {'+','+','0','0','+','+',  '0','+','0','+','0','+',  '0','+',  '0','+',  '+','0',  '+',  '+','+','+','+',  '0','+',  '+'}, //2
		        {'+','0','+','+','0','0',  '0','+','0','+','0','+',  '0','0',  '0','+',  '0','+',  '+',  '+','+','+','+',  '+','+',  '0'}, //3
	 	        {'+','0','+','0','+','0',  '0','+','0','+','+','+',  '0','0',  '+','0',  '0','0',  '+',  '0','+','+','+',  '0','+',  '0'}, //4
		        {'0','+','+','0','+','0',  '0','+','0','+','0','+',  '+','0',  '+','0',  '+','0',  '+',  '+','+','+','+',  '0','+',  '0'}, //5
		        {'0','0','+','+','+','0',  '0','+','0','+','0','+',  '+','+',  '0','+',  '0','+',  '0',  '0','+','0','+',  '0','+',  '+'}, //6
		        {'0','0','+','0','+','0',  '+','+','0','+','0','+',  '0','+',  '+','0',  '0','+',  '0',  '0','+','+','+',  '0','+',  '+'}, //7
		        {'0','0','+','0','+','0',  '0','+','0','+','0','+',  '+','0',  '+','+',  '0','+',  '+',  '+','0','0','+',  '0','+',  '+'}, //8
		        {'0','0','+','0','+','0',  '0','+','+','+','0','+',  '+','+',  '+','+',  '+','0',  '+',  '+','+','+','+',  '0','+',  '+'}, //9
	                {'+','+','0','0','+','0',  '0','+','0','+','0','+',  '0','+',  '0','+',  '0','+',  '+',  '+','0','0','+',  '0','+',  '+'}, //10
		        {'+','0','+','0','+','0',  '0','+','0','+','+','0',  '0','0',  '+','0',  '0','+',  '+',  '0','+','0','0',  '0','+',  '+'} //11
		      };

int arrInputs[11];
int* pInputs = arrInputs;
int input;

void horizontalBorder(){cout << setw(133) << setfill('=') << "=" << endl;}
void clearScreen(){cout << "\033[2J" << "\033[0;0H";};

void drawTable(int iCounter){

	int cursorPos = iCounter;

	clearScreen();
	horizontalBorder();

	cout << "|               ";
	cout << "|  Rh-Hr                |  Kell                 | Duffy | Kidd  |  Lewis| P |   MN          |Luthera|Xg |           |" << endl;
	cout << "|___|";

	for (int i=1; i<=31; ++i){
	cout << "___|";
	}
	cout << "___|" << endl;
	cout << "|               ";
	cout << "| D | C | c | E | e | Cw| K | k |Kpa|Kpb|JSa|Jsb|Fya|Fyb|JKa|Jkb|Lea|Leb| P1| M | N | S | s |Lua|Lub|Xga|           |" << endl; 	

	for (int i = 0; i<=10; ++i){
		cout << "|_______________|";

		for (int j=0; j<=27; ++j){
			cout << "___|";
		}
		cout << "___|" << endl;

		if ((i + 1) < 10){cout << "|   Donor " << i + 1 << "     |";}
		else {cout << "|   Donor " << i + 1 << "    |";}

		for (int k=0; k<=25; ++k){
			cout << " " << Donors[i][k] << " |";

		}	 
		cout << "           |" << endl;
	}
		cout << "|___|";

	for (int l=0; l<=30; ++l){
		cout << "___|";
	}
	cout << "___|" << endl;
	cout << "Enter Test Results for Each Cell";

	if (cursorPos == 0){cout << "\033[6;123H";}
	else{
	cout << "\033[" << (6+(cursorPos*2)) << ";123H";
	
	}
}
int main (){
	int counter;
	counter = 0;
	drawTable(counter);

	do {

		do{
			if (!(cin >> input) || input >= 4){
				cin.clear();
				cin.ignore(1000,'\n');	
			}
			else {
				*pInputs = input;
				pInputs+=1;
				counter+=1;
				drawTable(counter);
				cin.clear();
				cin.ignore(1000,'\n');		
			}	
		}
		while (counter <=10);
	
	cout << "\033[30;0H";
	cout << "Input Array: ";

	for (int i = 0; i<11; ++i){
		if (i < 10){
			cout << arrInputs[i] << ", ";	
		}
		else {
			cout << arrInputs[i] << endl;
		}
	}
	cout << endl;
	cout << "Program is unfinished: Input '9' to Exit." << endl;
	}
 	while (input != 9); 
	clearScreen();
	
	return 0;

}
