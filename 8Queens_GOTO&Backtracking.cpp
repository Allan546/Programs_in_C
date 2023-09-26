//8 Queens - 2 Dimensional Array Program with Backtracking, GOTO

#include <iostream>
using namespace std;

int main(){
	//Initialize Variables
	int b[8][8]{0};
	b[0][0] = 1;
	int c=0;
	int r = 0;
	int number = 0;
	cout << "2 Dimensional Array Program with Backtracking, GOTO";
	
	//New Column
NC:	c++;
	if(c == 8){
		goto P;
	}
	r=-1;
	//New Row
NR:  r++;
	if(r == 8){
		goto B;
	}
	//Checks Row
	for(int i = 0; i < c; i++){
		if(b[r][i] == 1){
			goto NR;
		}
	}
	//Check Upper Diagonal
	for(int i = 1; (r-i) >= 0 and (c-i) >= 0; i++){
		if(b[r-i][c-i] == 1){
			goto NR;
		}
	}
	//Check Lower Diagonal
	for(int i = 1; (r+i) < 8 and (c-i) >= 0; i++){
		if(b[r+i][c-i] == 1){
			goto NR;
		}
	}
	//Place number
	b[r][c] = 1;
	goto NC;
	
	//Backtracking
B:	c--;
	if(b[7][c] == 1){//Backtrack if queen is in last row
		b[7][c] = 0;
		goto B;
	}
	for(int r1 = 0; r1 < 8; r1++){
		if(b[r1][c] == 1){
			b[r1][c] = 0;
			r=r1;
			goto NR;
		}
	}

	//Print
P: 	cout << endl << "Solution " << ++number << endl;
	for(int r = 0; r < 8; r++){
		for(int c = 0; c < 8; c++){
			cout << b[r][c] << " ";
		}		
		cout << endl;
	}
	if(number < 92){
		goto B;
	}
}
