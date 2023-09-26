//8 Queens - 1 Dimensional Array Program with Backtracking, GOTO

#include <iostream>
using namespace std;

int main(){
  //Initialize Variables
	int q[8];
	int c = 0;
	q[0] = 0;
	int number = 0;
  cout << "8 Queens - 1 Dimensional Array Program with Backtracking, GOTO";

  //New Column
NC: c++;
	if(c == 8){
		goto P;
	}
	q[c] = -1;
  //New Row
NR:	q[c]++;
	if(q[c] == 8){
		goto B;
	}
  //Checks for horizontal and both diagonals
	for(int i = 0; i < c; i++){
		if((c-i == abs(q[c] - q[i])) or (q[i] == q[c])){
			goto NR;
		}
	}
	goto NC;

  //Backtracking 
B:	c--;
	if(q[c] == 7){//Backtracking if queen is in last row
		q[c] = -1;
		goto B;
	}
	goto NR;

  //Prints 
P: 	cout << endl << "Solution " << ++number << endl;
	for(int i = 0; i < 8; i++){
		cout << q[i] << " ";
	}
	cout << endl << endl;
	for(int r1 = 0; r1 < 8; r1++){
		for(int c1 = 0; c1 < 8; c1++){
			if(q[c1] == r1){
				cout << 1 << " ";
			}
			else{
				cout << 0 << " ";
			}
		}
		cout << endl;
	}
	if(number < 92){
		goto B;
	}
}
