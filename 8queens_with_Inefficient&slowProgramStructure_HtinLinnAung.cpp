/*	
Htin Linn Aung
CSCI 211: OOP in C++, Queens College 
Project : Time-consuming and data-consuming programming algorithm 
for 8 queens problem. Using mainly several iteration-nested loops to
go to all squares on the ches-board without eliminating unneceesary 
squares. Not efficient data representation, algorithm and program structure.
Using 2D array, functions(instead of goto) and backtrack 
concept to find all 92 solutions of putting 8 queens in 
8 by 8 chess-board without clashing each other on the 
same column, row and diagonals. Placing queens on the board goes 
from left to right. All three tests go from right to left. 
Then to print all solutions out by using 1(to present queen) and 
0(to present no queen) in all squares of the chess-board.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;


//Returns true if the board configuration is ok. Must check all of the queens, not just one.
 // For each queen on the chessboard
      // Figure out the position of the queen in that column
      // Perform the 3 tests (row, up-diagonal, down-diagonal), and if any of the tests fail, return false
   // Return true after all of the tests pass for every queen
bool ok(int q[][8])
{	
	int samerow=-1;		//counter for finding queens in the same row
	
	/*Comparing slots and checking repititions(using 3 tests) 
	by moving from the left(0,0) to the right of the board(7,7) row-by-row-horizontally*/  
	for(int r=0; r<8; r++)
	{	for(int c=0; c<8; c++)
		{	
			//Getting the current queen location by checking the current slot in 2D array(double loop)
			if(q[r][c]==1)
			{	samerow++;			//If another queen found on the same row, samerow++
			
				//Horizontal Test
				if(samerow>=1)		
				{	return false;	}
				/*The first queen found in the current row ---> samerow becomes 0
				  The second queen found in the current row --->samerow becomes 1
				  ...
				*/
									
				//Up-Diagonal Test
				//testing go from the current location to the leftmost side of the board
				for(int ud=1; ((r-ud)>=0)&&((c-ud)>=0); ud++)	//(row,column) goes toward the Up-Diagonal edge of the board		
				{	if(q[r-ud][c-ud]==1) {	return false;	}	}

				//Down-Diagonal Test
				//testing go from the current location to the leftmost side of the board
				for(int dd=1; ((r+dd)<8)&&((c-dd)>=0); dd++)	//(row,column) goes toward the Down-Diagonal edge of the board
				{	if(q[r+dd][c-dd]==1) {	return false;	}	}
			}
							
		}
		samerow=-1;
	}
	return true;
}

void print(int q[][8]) 
{	/*Declaring solution as static int type to keep 
	the solution value left from last time the function was called
	*/
	static int solution = 0;
	
	cout<< "Solution #"<< ++solution<< ":\n"<< "\n";
	for (int i = 0; i < 8; ++i)
    {	for (int j = 0; j < 8; ++j)
		{	cout<< q[i][j]<< " | ";	}
		cout<< "\n";
	}
	cout<< "-------------------------------"<< endl;
}

int main()
{
	int q[8][8]={0};
	
	for(int i0=0; i0<8; i0++)
	{	for(int i1=0; i1<8; i1++)
		{	for(int i2=0; i2<8; i2++)
			{	for(int i3=0; i3<8; i3++)
				{	for(int i4=0; i4<8; i4++)
					{	for(int i5=0; i5<8; i5++)
						{	for(int i6=0; i6<8; i6++)
							{	for(int i7=0; i7<8; i7++)
								{	//Placing all 8 queens on the chessboard:
                           			q[i0][0] = 1; 	//1st queen in i0 of column 0
                                    q[i1][1] = 1; 	//2nd queen in i1 of column 1
                                	q[i2][2] = 1; 	//3rd queen in i2 of column 2
                                	q[i3][3] = 1; 	//4th queen in i3 of column 3
									q[i4][4] = 1; 	//5th queen in i4 of column 4                           
                           			q[i5][5] = 1; 	//6th queen in i5 of column 5
									q[i6][6] = 1; 	//7th queen in i6 of column 6
									q[i7][7] = 1; 	//8th queen in i7 of column 7
									
									if (ok(q)){	print(q);	}

									//Removing all 8 queens from the chessboard:
                                    q[i0][0] = 0;   //remove 1st queen from i0 of column 0
                                	q[i1][1] = 0;	//remove 2nd queen from i1 of column 1
                                	q[i2][2] = 0;	//remove 3rd queen from i2 of column 2
                                    q[i3][3] = 0;   //remove 4th queen from i3 of column 3
                                	q[i4][4] = 0;	//remove 5th queen from i4 of column 4
                                    q[i5][5] = 0;   //remove 6th queen from i5 of column 5
                                    q[i6][6] = 0;   //remove 7th queen from i6 of column 6
                                    q[i7][7] = 0;   //remove 8th queen from i7 of column 7
								}
							}
						}
					
					}	
				}
			}
		}		
	}
	
	system("PAUSE");	
	return 0;	
}

