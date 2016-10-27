/*	
Htin Linn Aung
CSCI 211: OOP in C++, Queens College 
Project : Using dynamically initiated 1D array(and delete the 
unused array with 'delete []q' for manual garbage collection
in the heap memory), indefinite loops with 'break;' code, 
functions(instead of goto) and backtrack concept to find all
92 solutions of putting 8 queens in 8 by 8 chess-board without
clashing each other on the same column, row and diagonals. 
Placing queens on the board goes from left to right. All three 
tests go from right to left. Then print just the number of 
solutions out for each type of nxn chessboard without 
chessboard board display.
*/

#include<iostream>
#include<stdlib.h>
#include<cmath>

using namespace std;

// Funtion to conduct row test, up-diagonal test & down-diagonal test. Returns true or false.
bool check(int q[], int k)
{	
	// Loop for comparing the slots on the board
	for(int i=0; i<k; i++)
	{	
		// Flow-control condition for three tests
		if  ( q[i]==q[k] || (k-i)==abs(q[i]-q[k]) )
		{	return false;	}		// return false when it fails the tests
	}
	return true;					// return true when it passes the tests
}

// Function to return the number of solutions for the given board size.
int nqueens(int n) 
{	
	/*
	Array q for row
	c for column
	*/
	
	int* q = new int[n];	// Array(size n) declared(with pointer) dynamically with 'new' constructor
	// Initiate all the elements, especially the first element to 0
	for(int a=0; a<n; a++)
		q[a]=0;
	int c=0;				// Initiate c=0 for column 
	int sol_count=0;			// Variable for counting # of solutions
	int loop1=0, loop2=0;		// Variables for 2 infinite loops		
	q[c]=-1;					// row=-1 in column 0
	
	while(loop1==0)				// Will break out of this while loop with 'break;'
	{	while(loop2==0)			// Will break out of this while loop with 'break;'
		{	while(q[c]<n)		// While row<n in the current column
			{	q[c]++;					// row++
				
				if(q[c]==n)			// If row=n
				{	c--;				// Back-track
					if (c==-1)				// If out of column on the left side of the board	
					{	delete []q;			// Delete q array
						return sol_count;	// Will leave nqueens function by returning sol_count
					}									
					continue;			// Go to next line of code, "continue;"	
				}							
				if(check(q,c))			// Row Test,Up-Diagonal Test & Down-Diagonal Test
					break;				// Go to next column by breaking out of the while(q[c]<n){}		 
			}			
			c++;				// Next column
			if(c==n)			// If out of column	on the right side of the board			
				break;			// Go to 'sol_count++;' by breaking out of the while(loop2==0){}	
			q[c]=-1;			// row=-1, preparing to go back to row 0
		}
		sol_count++;		// Add 1 to sol_count;
		c--;				// Back-track one column to find another solution
		if(c==-1)		// If out of column on the left side of the board
		{	break;	}	// Breaking out of the while(loop1==0){}
	}
	// Does not print solutions, but return the number of possible solutions to main program
   
   // Delete the array.
   delete []q;
   
   // Return the number of solutions.
   return sol_count;
}

int main() 
{
   int n=12;		// initializing int n with value 12
   
   /* 
   Loop to find, test and print the number(from the return 
   value of 'nqueens()' function) of possible solutions, Repeated 12 times
   */
   for(int i=1; i<=n; ++i)		
      cout<< "There are "<< nqueens(i)<< " solutions to the "<< i<< " queens problem.\n";
   return 0;			// Go to the end of the program
   system("PAUSE");		// Screen is paused to display, but will quit if the user enters anything
}
   
