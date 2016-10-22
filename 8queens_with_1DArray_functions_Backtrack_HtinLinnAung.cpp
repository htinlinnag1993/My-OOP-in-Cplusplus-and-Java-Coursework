/*	
Htin Linn Aung
CSCI 211: OOP in C++, Queens College 
Project : Using 1D array, functions(instead of goto) and backtrack 
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

// Function to do row test and diagonal tests(up & down) 
bool Ok(int q[], int k)	
{	for (int i=0; i<k; i++)
	{	if ( q[k]==q[i] || (k-i) == abs(q[k]-q[i]) )	// Row test & Diagonal Tests
		{	return false;	}		// Return false if another queens is found on same row or diagonal
									// Do nothing if not found
	}
	// After testing all slots on the same left row, left up-diagonal and left down-diagonal
	return true;		 			// If nothing is found, return true
}

// Function to print out one solution board filled with 8 queens
void Print(int q[], int sol)
{	cout<< "Solution "<< sol<< ": "<< endl;		// With current solution number
	for (int r=0; r<8 ;r++)				
	{	for (int c=0; c<8; c++)
		{	if(q[c]==r)							// If there is a queen in the slot
			{	cout<< "1"<< " | ";		}
			else								// If not
			{	cout<< "0"<< " | ";		}
		}
		cout<< endl;							// Next line
	}
}

int main ()
{
	/*
	q[c] is row
	c is column
	*/
	
	int sol=1;					// Initializing sol with value 1 for first solution 
	int q[8]={0}, c=0;			// Initializing 1D Array filled with 0 & column starts from 0
	int loop1=0, loop2=0;		// Variables for 2 infinite loops		
	q[c]=-1;					// row=-1 in column 0
	
	
	while(loop1==0)				//
	{	while(loop2==0)			//
		{	while(q[c]<8)		// While row<8 in the current column
			{	q[c]++;					// row++
				
				if (q[c]==8)			// If row=8
				{	c--;					// Back-track
					if (c==-1)				// If out of column on the left side of the board	
					{	return 0;	}		// Go to the end of the program										
					continue;				
				}							// Go to next row, "continue;"
				
				if(Ok(q,c))			// Row Test,Up-Diagonal Test & Down-Diagonal Test
				{	break;	}		// Go to next column by breaking out of the while(q[c]<8){} 
			}			
			c++;				// Next column
			
			if (c==8)			// If out of column	on the right side of the board			
			{	break;	}		// Go to Print function by breaking out of the while(loop2==0){}
			
			q[c]=-1;			// row=-1, preparing to go back to row 0
		}
		Print(q,sol);		// Printing the current solution
		
		sol++;				// Next possible solution
		cout<< endl;		// Next line
		c--;				// Back-track to find all other solutions
		
		if (c==-1)			// If out of column on the left side of the board
		{	return 0;	}	// Breaking out of the while(loop1==0){}
	}
	return 0;
	system("PAUSE");
}
