// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include<vector>
using namespace std;

//array to store the taken positions
char board[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' };

///////////////////////////////////////////
//function to print the tic tac toe board//
///////////////////////////////////////////
void printBoard()
{
	system("CLS");
	cout << "-+-+-+-+-TicTacToe-+-+-+-+-\n\n";
	cout <<"\t"<< board[1] << " | " << board[2] << " | " <<board[3] << "\n";
	cout << "\t- + - + -\n";
	cout << "\t" << board[4] << " | " << board[5] << " | " << board[6] << "\n";
	cout <<  "\t- + - + -\n";
	cout << "\t" << board[7] << " | " << board[8] << " | " << board[9] << "\n";
}

//////////////////////////////////////////////////////////////////////
//inputplayer function                                              //    
//to take input from player and repeat untill a empty place is found//
//////////////////////////////////////////////////////////////////////
void inputplayer()
{
	cout << "enter your position to place your mark (1-9)(you are X)";
	int p;
	cin >> p;
	if (board[p] == 'X' || board[p] == 'O')
	{
		cout << "position is already taken by"<< (board[p]=='O'?"cpu\n":"you\n") <<"Please enter a empty position\n";
		inputplayer();
	}
	else
		board[p] = 'X';

}
/////////////////////////////////////////////////////////////////////////////////////////
//iswinner finction to check if we have a winner and returns values according to winner//
/////////////////////////////////////////////////////////////////////////////////////////
int iswinner(char board[])
{
	
	if (board[1] == 'X' && board[2] == 'X' && board[3] == 'X' || 
		board[4] == 'X' && board[5] == 'X' && board[6] == 'X' ||
		board[7] == 'X' && board[8] == 'X' && board[9] == 'X' ||
		board[1] == 'X' && board[4] == 'X' && board[7] == 'X' ||
		board[2] == 'X' && board[5] == 'X' && board[8] == 'X' ||
		board[3] == 'X' && board[6] == 'X' && board[9] == 'X' ||
		board[1] == 'X' && board[5] == 'X' && board[9] == 'X' ||
		board[3] == 'X' && board[5] == 'X' && board[7] == 'X')
		return 1;
	else if (board[1] == 'O' && board[2] == 'O' && board[3] == 'O' ||
		board[4] == 'O' && board[5] == 'O' && board[6] == 'O' ||
		board[7] == 'O' && board[8] == 'O' && board[9] == 'O' ||
		board[1] == 'O' && board[4] == 'O' && board[7] == 'O' ||
		board[2] == 'O' && board[5] == 'O' && board[8] == 'O' ||
		board[3] == 'O' && board[6] == 'O' && board[9] == 'O' ||
		board[1] == 'O' && board[5] == 'O' && board[9] == 'O' ||
		board[3] == 'O' && board[5] == 'O' && board[7] == 'O')
		return 2;
	else
		return 0;
}

void cpuTurn()
{
	char tempboard[10];
	for (int i = 1;i <= 9;i++)
	{
		copy(begin(board), end(board), begin(tempboard));
		if (tempboard[i] ==' ')
		{
			tempboard[i] = 'O';
			if (iswinner(tempboard) == 2)
			{
				board[i] = 'O';
				return;
			}

		}
	}
	for (int i = 1;i <= 9;i++)
	{
		copy(begin(board), end(board), begin(tempboard));
		if (tempboard[i] == ' ')
		{
			tempboard[i] = 'X';
			if (iswinner(tempboard) == 1)
			{
				board[i] = 'O';
				return;
			}

		}
	}
	
	while(1)
	{
		if (board[rand()%9 +1] == ' ')
		{
			board[rand() % 9 + 1] = 'O';
			return;
		}
	}
	

}




int main()
{
	bool turn=rand()%2; //1 for player and 0 for cpu
	printBoard();
	int turncnt = 0;
	while (!iswinner(board) && turncnt<9)
	{
		if (turn == 0) //checking turn and changing turn
		{
			cpuTurn(); 
			turn = 1;
			turncnt++;
		}
		else
		{
			inputplayer();
			turn = 0;
			turncnt++;
		}
		printBoard();
		if (iswinner(board) == 1) cout << "\n\tYOU WIN :)\n";
		else if(iswinner(board)) cout << "\n\tYOU LOSE! :(\n\t\tCPU WINS \n";
		
	}
	if (turncnt == 9 && iswinner(board) == 0)
	{
		cout << "\n\t-+-+-+-+-+-+-+DRAW+-+-+-+-+-+-+-+-";
	}
	

    
}

