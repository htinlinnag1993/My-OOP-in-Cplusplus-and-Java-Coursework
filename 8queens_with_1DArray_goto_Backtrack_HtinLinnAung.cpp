/*	
Htin Linn Aung
CSCI 211: OOP in C++, Queens College 
Project : Using 1D array, 'goto' and backtrack 
concept to find all 92 solutions of putting 8 queens in 
8 by 8 chess-board without clashing each other on the 
same column, row and diagonals. Placing queens on the board goes 
from left to right. All three tests go from right to left. 
Then to print all solutions out by using 1(to present queen) and 
0(to present no queen) in all squares of the chess-board.
*/

#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

int main()
{
	int q[8];	// Initiating 1D array(int q[8]) for row 	
	int c=0;	// Initiating column with 0	
	int ans=1;	// Initiating ans with 1
	q[0] = 0; 	// r=0
	
	/*
	q[c] is row
	c is column
	*/
		
	// Next Column
	NC: c++;
		if(c==8)
		{	goto Print;}
		q[c] = -1;		// r=-1
	
	// Next Row
	NR:	q[c]++;			// r++
		if(q[c]==8)
		{	goto BackTrack;}

		// All 3 Tests(Row, Up-Diagonal, Down-Diagonal)
		for(int h=0; h<c; h++)
		{	if(q[c]==q[h] || (c-h)==abs(q[c]-q[h]))
			{	goto NR;	}	// Go to Next Row if any of the tests fails
		}
		goto NC;	// Go to Next Column after the Current Row of the Last Column
			
	// Back Track
	BackTrack:	c--;			// Go one Column back to find another possible solution
				if(c == -1)		// If out of column on the left side of the chessboar 
				{	return 0; }	// Go to the end of the program
				goto NR;		// Go to Next Row		
			
	// Print		
	Print:	cout<< " Solution "<< ans<< " : "<< endl;		// Print the current solution value
			cout<< " All 8 queens on the chessboard are described as 1. "<< endl;
	
			for(int row=0; row<8 ;row++)
			{	for(int col=0; col<8; col++)
				{	if(q[col]==row)				// If there is a queen placed in the slot
						cout << "1" << " ";		// Present it with 1
					else						// If there is no queen in the slot
						cout << "0" << " ";		// Present it with 0
				}
				cout << endl;		// After 1 whole row of 8 columns, go to another line 
			}
			cout<< endl;		// After all 8 rows of 8 columns, go to another line
			ans++;				// Add 1 to ans
			goto BackTrack;		// Go to Back-Track to find another possible solution 

	return 0;			// Go to the end of the program
	system("PAUSE");	// Screen is paused to display, but will quit if user enters anything
}

