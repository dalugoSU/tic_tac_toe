#include <iostream>
#include <ctime>
#include <random>
#include <string>

using namespace std;

// Create Board 3 X 3 array empty
// get input for row and column to place marks
// Create const for X and O marks

bool updateBoard(int row, int col, char player);
void printBoard();
bool checkBoardComp();
bool checkWin();

// Game Mode
int twoPlayerGame();
int computerGame();

// Constants
const char X_CHAR = 'X';
const char O_CHAR = 'O';

/*
Winning combinatinons
straight horizontal
straight vertical
diagonal
*/

// Game Board
char board[3][3]{
	{' ', ' ', ' '},
	{' ', ' ', ' '},
	{' ', ' ', ' '}
};

// Player won
// Counter for win
bool playerWon = false;

// Game type
char gameType;

int main()
{
	cout << "Welcome to Tic Tac Toe" << endl << endl;

	cout << "Would you like to play a two player game (1) or against the computer(2) [1 or 2]: ";
	cin >> gameType;
	
	while (true)
	{
		if (gameType == '1')
		{
			int complete = twoPlayerGame();
			if (complete == 0)
			{
				break;
			}
		}
		else if (gameType == '2')
		{
			int complete = computerGame();
			if (complete == 0)
			{
				break;
			}
		}
		else
		{
			cout << "Invalid type, enter again" << endl;
			cout << "Would you like to play a two player game (1) or against the computer(2) [1 or 2]: ";
			cin >> gameType;
		}
	}

	cout << endl << endl;
	cout << "Thank you for playing :D" << endl;

	return 0;
}

int twoPlayerGame()
{
	// Player names
	string playerOne;
	string playerTwo;

	// Choices made by players
	int playerOneChoiceRow;
	int playerOneChoiceCol;
	int playerTwoChoiceRow;
	int playerTwoChoiceCol;

	cout << "You entered a two player game!" << endl << endl;

	cout << "Player one, enter your name: ";
	cin >> playerOne;
	cout << "You are the X" << endl;

	cout << endl;

	cout << "Player two, enter name: ";
	cin >> playerTwo;
	cout << "You are the O" << endl;

	cout << endl;
	cout << "This will work by giving the row and column number to place your mark" << endl << endl;

	printBoard();

	while (true)
	{
		bool boardFull = checkBoardComp();

		if (playerWon)
		{
			break;
		}

		if (boardFull)
		{
			cout << "The board is filled!" << endl;
			cout << "Game has finished - no Winner!" << endl;
			break;
		}

		while (true)
		{
			cout << playerOne << ", " << "Enter row and col of where you want to place your X: ";
			cin >> playerOneChoiceRow;
			cin >> playerOneChoiceCol;
			bool trial = updateBoard(playerOneChoiceRow, playerOneChoiceCol, '1');
			if (trial == false)
			{
				continue;
			}
			else
			{
				playerWon = checkWin();
				printBoard();
				if (playerWon == true)
				{
					cout << endl << endl << "CONGRATULATIONS! " << playerOne << " WINS!" << endl;
					break;
				}
				else
				{
					break;
				}
			}
		}

		if (playerWon)
		{
			break;
		}

		boardFull = checkBoardComp();
		if (boardFull)
		{
			cout << "The board is filled!" << endl;
			cout << "Game has finished - no Winner!" << endl;
			break;
		}

		while (true)
		{
			cout << playerTwo << ", " << "Enter row and col of where you want to place your 0: ";
			cin >> playerTwoChoiceRow;
			cin >> playerTwoChoiceCol;
			bool twoTrial = updateBoard(playerTwoChoiceRow, playerTwoChoiceCol, '2');
			if (twoTrial == false)
			{
				continue;
			}
			else
			{
				playerWon = checkWin();
				printBoard();
				if (playerWon == true)
				{
					cout << endl << endl << "CONGRATULATIONS! " << playerTwo << " WINS!" << endl;
					break;
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}

int computerGame()
{
	// Random num for computer
	srand(time(nullptr));

	// Player names
	string playerOne;

	// Choices made by players
	int playerOneChoiceRow;
	int playerOneChoiceCol;
	int computerChoiceRow;
	int computerChoiceCol;

	cout << endl << "You are against the computer!" << endl << endl;

	cout << "Player one, enter your name: ";
	cin >> playerOne;
	cout << "You are the X" << endl;

	cout << endl;

	cout << "Computer is the O" << endl;

	cout << endl;
	cout << "This will work by giving the row and column number to place your mark" << endl << endl;

	printBoard();

	while (true)
	{
		bool boardFull = checkBoardComp();

		if (playerWon)
		{
			break;
		}

		if (boardFull)
		{
			cout << "The board is filled!" << endl;
			cout << "Game has finished - no Winner!" << endl;
			break;
		}

		while (true)
		{
			cout << playerOne << ", " << "Enter row and col of where you want to place your X: ";
			cin >> playerOneChoiceRow;
			cin >> playerOneChoiceCol;
			bool trial = updateBoard(playerOneChoiceRow, playerOneChoiceCol, '1');
			if (trial == false)
			{
				continue;
			}
			else
			{
				playerWon = checkWin();
				printBoard();
				if (playerWon == true)
				{
					cout << endl << endl << "CONGRATULATIONS! " << playerOne << " WINS!" << endl;
					break;
				}
				else
				{
					break;
				}
			}
		}

		if (playerWon)
		{
			break;
		}

		boardFull = checkBoardComp();
		if (boardFull)
		{
			cout << "The board is filled!" << endl;
			cout << "Game has finished - no Winner!" << endl;
			break;
		}

		cout << endl << endl << "Computer picked!" << endl;

		while (true)
		{
			// Computer choice
			int randomNumRow = rand() % 3 + 1; // random between 1 - 3
			computerChoiceRow = randomNumRow;

			int randomNumCol = rand() % 3 + 1; // random between 1 - 3
			computerChoiceCol = randomNumCol;

			bool twoTrial = updateBoard(computerChoiceRow, computerChoiceCol, '2');
			if (twoTrial == false)
			{
				continue;
			}
			else
			{
				playerWon = checkWin();
				printBoard();
				if (playerWon == true)
				{
					cout << endl << endl << "COMPUTER WINS! You lost..." << endl;
					break;
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;

}

bool updateBoard(int row, int col, char player)
{

	if (row < 0 || row > 3 || col < 0 || col > 3)
	{
		cout << "Invalid range" << endl;
		return false;
	}

	row--;
	col--;

	if (player == '1')
	{
		if (board[row][col] != ' ')
		{
			cout << "This spot is taken" << endl;
			return false;
		}
		else
		{
			board[row][col] = X_CHAR;
			return true;
		}
	}
	else if (player == '2')
	{
		if (board[row][col] != ' ')
		{
			cout << "This spot is taken" << endl;
			return false;
		}
		else
		{
			board[row][col] = O_CHAR;
			return true;
		}
	}
	else
	{
		cout << "Error updating board, wrong player number" << endl;
		return false;
	}
}

void printBoard()
{
	cout << endl << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 2)
			{
				cout << " " << board[i][j];
			}
			else
			{
				cout << " " << board[i][j] << " | ";
			}
		}
		cout << endl;
		cout << " " <<" --- " << " --- ";
		cout << endl;
	}
	cout << endl;
}

bool checkBoardComp()
{
	int summ = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == X_CHAR || board[i][j] == O_CHAR)
			{
				summ++;
			}
		}
	}
	if (summ == 9)
	{
		return true;
	}
	return false;
}

bool checkWin()
{
	int checkX = 0;
	int checkO = 0;

	// Check rows
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == X_CHAR)
			{
				checkX += 1;
			}
			if (board[i][j] == O_CHAR)
			{
				checkO += 1;
			}
		}
		if (checkX == 3)
		{
			return true;
		}
		if (checkO == 3)
		{
			return true;
		}
		checkX = 0;
		checkO = 0;
	}

	checkX = 0;
	checkO = 0;

	// Check cols
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[j][i] == X_CHAR)
			{
				checkX++;
			}
			if (board[j][i] == O_CHAR)
			{
				checkO++;
			}
		}
		if (checkX == 3)
		{
			return true;
		}
		if (checkO == 3)
		{
			return true;
		}
		checkX = 0;
		checkO = 0;
	}

	// Check for diagonals
	// [00][11][22]
	// [02][11][20]
	if (board[0][0] == X_CHAR && board[1][1] == X_CHAR && board[2][2] == X_CHAR)
	{
		return true;
	}
	else if (board[0][2] == X_CHAR && board[1][1] == X_CHAR && board[2][0] == X_CHAR)
	{
		return true;
	}
	else if (board[0][0] == O_CHAR && board[1][1] == O_CHAR && board[2][2] == O_CHAR)
	{
		return true;
	}
	else if (board[0][2] == O_CHAR && board[1][1] == O_CHAR && board[2][0] == O_CHAR)
	{
		return true;
	}
	else
	{
		return false;
	}
}
