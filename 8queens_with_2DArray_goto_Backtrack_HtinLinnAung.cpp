/*	
Htin Linn Aung
CSCI 211: OOP in C++, Queens College 
Project : Using 2D array, 'goto' statement and backtrack concept 
to find all 92 solutions of putting 8 queens in 8 by 8 chess-board
without clashing each other on the same column, row and diagonals. 
Then to print all solutions out by using 1(to present queen)
and 0(to present no queen) in all squares of the chess-board.
*/

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int cb[8][8] = {0};			// 2D Array of size 8 by 8 declared
	int row, col=0, ans=1;		// Initiating row, col=0, ans=-1
	
	cb[0][0] = 1;				// Placing one queen in [0,0]
	
	NC: col++;					// Next column
		// Condition test for out of column 
		if(col == 8)			
		{	goto PRINT; }		// goto PRINT if out of column
		
	row = -1;					// Setting row to -1 to prepare to start from the top row again
		
	NR: row++;					// Next row
		// Condition test for out of row
		if(row == 8)
		{	goto BACKTRACK; }	// Go to BACKTRACK if out of row
			
	// Row Test
	for(int i=0; i<col; i++)
	{	if(cb[row][i]==1)		// If there is another queen in the same row
		{	goto NR; }			// Go to NR	
	}
			
	// Up-Diagonal Test
	for(int j=1; (row-j)>=0 && (col-j)>=0; j++)
	{	if(cb[row-j][col-j]== 1) // If there is another queen in the same up-diagonal line
		{	goto NR; }			 // Go to NR
	}
			
	// Down-Diagonal Test
	{	for(int k=1; (row+k)<8 && (col-k)>=0; k++)
		{	if(cb[row+k][col-k]==1)	// If there is another queen in the same down-diagonal line
			{ goto NR; }			// Go to NR
		}
	}
			
	// Putting the Queen in the current slot
	cb[row][col] = 1;				
		goto NC;				// Go to NC
			
	BACKTRACK:	col--;						// Last column
				if(col==-1)					// If out of column	
				{	return 0; }				// Go to the end of the program
						
				row=0;						// Going to the top of the current column by setting row to 0
				while(cb[row][col] != 1)	// Loop for finding the queens' location in the current slot
				{		row++;	}			// Keep going to the next row
				
				cb[row][col] = 0;    		// Removing the queen from the current slot
				goto NR;					// Go to NR
					
						
	PRINT:	cout<< " Solution "<< ans<< " : "<< endl;	 	// Printing out the current solution number
			cout<< " All 8 queens on the chessboard are described as 1. "<< endl;
	
			// Nested loop for printing out the 8 by 8 board with queens in the specific slots
			for(int r=0; r<8; r++)
			{	for(int c=0; c<8; c++)
				{	cout<< cb[r][c] << " | ";	}	// Use | to draw a line between column
				cout<< endl;						// Go to the next line after last column(c=7)
			}
			cout<< endl;							// Line spacing between two solutions
			
			ans++;									// Next solution
			goto BACKTRACK;							// Go to BACKTRACK to find another possible solution
		 
	return 0;				// Going to end the program
	system("PAUSE");		// Holding the screen and waiting for the user's reponse to quit the program
}
