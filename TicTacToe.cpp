// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include<vector>
#include <conio.h>
using namespace std;

//array to store the taken positions
char board[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ' };


void PrintGameTitle()
{
	system("CLS");
	cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOX\n";
	cout << "OXO   TICTACTOE USING C++   OXO\n";
	cout << "XOXOXOXOXOXOXOXOXOXOXOXOXOXOXOX\n\n";
}

void PrintModeMenu(int x)
{
	if (x == 0)
	{
		cout << "### SINGLE PLAYER (v/s CPU) ###\n";
		cout << "          MULTIPLAYER\n";
	}
	else
	{
		cout << "    SINGLE PLAYER (v/s CPU)\n";
		cout << "###       MULTIPLAYER       ###\n";
	}
}

void PrintDifficultyMenu(int x)
{
	if (x == 0)
	{
		cout << "####  EASY  ####\n";
		cout << "     NORMAL\n";
		cout << "      HARD\n";
	}
	else if (x == 1)
	{
		cout << "      EASY\n";
		cout << "#### NORMAL ####\n";
		cout << "      HARD\n";
	}
	else
	{
		cout << "      EASY\n";
		cout << "     NORMAL\n";
		cout << "####  HARD  ####\n";
	}
}

void PrintNavigationInstructions()
{
	cout << "\n\n---------------------------------------\n";
	cout << "# navigate through up and down keys \n";
	cout << "# press enter to select\n";
}

vector<int> menu()
{
	vector<int> mode_difficulty;
	int key = 0;
	int pos = 0;
	PrintGameTitle();
	PrintModeMenu(pos % 2);
	PrintNavigationInstructions();
	while (key != 13)
	{
		key = _getch();
		key = toupper(key);
		if (key == 72) pos--;
		else if (key == 80) pos++;
		PrintGameTitle();
		PrintModeMenu(pos % 2);
		PrintNavigationInstructions();
	}
	mode_difficulty.push_back(pos % 2);

	if (pos % 2 == 1) return mode_difficulty;

	key = 0;
	pos = 0;
	PrintGameTitle();
	PrintDifficultyMenu(pos % 3);
	PrintNavigationInstructions();

	while (key != 13)
	{
		key = _getch();
		key = toupper(key);
		if (key == 72) pos--;
		else if (key == 80) pos++;
		system("CLS");
		PrintGameTitle();
		PrintDifficultyMenu(pos % 3);
	}
	mode_difficulty.push_back(pos % 3);



	return mode_difficulty;
}



///////////////////////////////////////////
//function to print the tic tac toe board//
///////////////////////////////////////////
void printBoard()
{
	PrintGameTitle();
	cout << "\t"<< board[1] << " | " << board[2] << " | " <<board[3] << "\n";
	cout << "\t- + - + -\n";
	cout << "\t" << board[4] << " | " << board[5] << " | " << board[6] << "\n";
	cout << "\t- + - + -\n";
	cout << "\t" << board[7] << " | " << board[8] << " | " << board[9] << "\n";
}

//////////////////////////////////////////////////////////////////////
//inputplayer function                                              //    
//to take input from player and repeat untill a empty place is found//
//////////////////////////////////////////////////////////////////////
void inputplayer1()
{
	cout << "enter your position to place your mark (1-9)(you are X)";
	int p;
	//cin >> p;
	p = _getch();
	p = toupper(p)-48;
	if (board[p] == 'X' || board[p] == 'O')
	{
		cout << "position is already taken by"<< (board[p]=='O'?"player 1\n":"you\n") <<"Please enter a empty position\n";
		inputplayer1();
	}
	else
		board[p] = 'X';

}
//////////////////////////////////////////////////////////////////////
//inputplayer function                                              //    
//to take input from player and repeat untill a empty place is found//
//////////////////////////////////////////////////////////////////////
void inputplayer2()
{
	cout << "enter your position to place your mark (1-9)(you are O)";
	int p;
	//cin >> p;
	p = _getch();
	p = toupper(p) - 48;
	if (board[p] == 'X' || board[p] == 'O')
	{
		cout << "position is already taken by" << (board[p] == 'O' ? "player 2\n" : "you\n") << "Please enter a empty position\n";
		inputplayer2();
	}
	else
		board[p] = 'O';

}

/////////////////////////////////////////////////////////////////////////////////////////
//iswinner function to check if we have a winner and returns values according to winner//
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
	vector<int> A;
	int choice=1;
	while (choice !=0 )
	{
		A = menu();
		if (A[0] == 0)                              //single player
		{
			printBoard();
			int turncnt = 0;
			int difficulty = 0;
			bool turn = rand() % 2; //1 for player and 0 for cpu

			while (!iswinner(board) && turncnt < 9)
			{
				if (turn == 0) //checking turn and changing turn
				{
					cpuTurn();
					turn = 1;
					turncnt++;
				}
				else
				{
					inputplayer1();
					turn = 0;
					turncnt++;
				}
				printBoard();
				if (iswinner(board) == 1) cout << "\n\tYOU WIN :)\n";
				else if (iswinner(board)) cout << "\n\tYOU LOSE! :(\n\t\tCPU WINS \n";

			}
			if (turncnt == 9 && iswinner(board) == 0)
			{
				cout << "\n\t-+-+-+-+-+-+-+DRAW+-+-+-+-+-+-+-+-";
			}

		}
		else //multiplayer
		{
			int turncnt = 0;
			printBoard();
			bool turn = 0;
			while (!iswinner(board) && turncnt != 9)
			{
				if (turn == 0)
				{
					turncnt++;
					inputplayer1();
					turn = 1;
				}
				else
				{
					turncnt++;
					inputplayer2();
					turn = 0;
				}
				printBoard();
				if (iswinner(board) == 1) cout << "\n\tPlayer1 WINS :)\n";
				else if (iswinner(board)) cout << "\n\tPlayer2 WINS :)\n";
			}
			if (turncnt == 9 && iswinner(board) == 0)
			{
				cout << "\n\t-+-+-+-+-+-+-+DRAW+-+-+-+-+-+-+-+-\n\t";
			}
		}


		cout << "DO YOU WANT TO PLAY AGAIN\n";
		cin >> choice;
	}
	
	
	

    
}

