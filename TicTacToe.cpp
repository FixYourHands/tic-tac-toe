#include <iostream>

constexpr size_t BOARD_SIZE = 9;

bool gameState(const char* board)
{
	if (board[0] == board[1] && board[1] == board[2] && board[0] == board[2]) // three in a row horizontally
	{
		if (board[0] == 'x')
		{
			std::cout << "The human player wins!\n";
			return false;
		}
		else if (board[0] == 'o')
		{
			std::cout << "The computer wins!\n";
			return false;
		}
	}

	if (board[3] == board[4] && board[4] == board[5] && board[3] == board[5]) // three in a row horizontally
	{
		if (board[3] == 'x')
		{
			std::cout << "The human player wins!\n";
			return false;
		}
		else if (board[3] == 'o')
		{
			std::cout << "The computer wins!\n";
			return false;
		}
	}

	if (board[6] == board[7] && board[7] == board[8] && board[6] == board[8] ) // three in a row horizontally
	{
		if (board[6] == 'x')
		{
			std::cout << "The human player wins!\n";
			return false;
		}
		else if (board[6] == 'o')
		{
			std::cout << "The computer wins!\n";
			return false;
		}
	}

	if (board[0] == board[3] && board[3] == board[6] && board[0] == board[6]) // three in a row vertically
	{
		if (board[0] == 'x')
		{
			std::cout << "The human player wins!\n";
			return false;
		}
		else if (board[0] == 'o')
		{
			std::cout << "The computer wins!\n";
			return false;
		}
	}

	if (board[1] == board[4] && board[4] == board[7] && board[1] == board[7]) // three in a row vertically
	{
		if (board[1] == 'x')
		{
			std::cout << "The human player wins!\n";
			return false;
		}
		else if (board[1] == 'o')
		{
			std::cout << "The computer wins!\n";
			return false;
		}
	}

	if (board[2] == board[5] && board[5] == board[8] && board[2] == board[8]) // three in a row vertically
	{
		if (board[8] == 'x')
		{
			std::cout << "The human player wins!\n";
			return false;
		}
		else if (board[8] == 'o')
		{
			std::cout << "The computer wins!\n";
			return false;
		}
	}
	return true;
}
void drawBoard(const char* board)
{
	std::cout << "The board now looks like: \n";
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (i != 0 && i % 3 == 0)
		{
			std::cout << '\n';
		}
		std::cout << board[i] << ' ';
		
	}
	
	std::cout << '\n' << '\n';
	gameState(board);
	system("PAUSE");
	system("cls");
}

void initializeBoard(char* board)
{
	const size_t BOARD_SIZE = 9;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		board[i] = '.';
	}
}
bool isEmpty(char tile)
{
	if (tile == '.')
	{
		return true;
	}
	return false;
}

bool isOccupied(char tile)
{
	if (tile == 'x' || tile == 'o')
	{
		return true;
	}
	return false;
}

void turn(char* board)
{

	int select;
	std::cout << "Where would you like to move? ";
	std::cin >> select;
	switch (select)
	{
	case 7:
		if (isEmpty(board[0]))
		{
			board[0] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[0]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 8:
		if (isEmpty(board[1]))
		{
			board[1] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[1]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 9:
		if (isEmpty(board[2]))
		{
			board[2] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[2]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 4:
		if (isEmpty(board[3]))
		{
			board[3] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[3]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 5:
		if (isEmpty(board[4]))
		{
			board[4] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[4]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 6:
		if (isEmpty(board[5]))
		{
			board[5] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[5]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 1:
		if (isEmpty(board[6]))
		{
			board[6] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[6]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 2:
		if (isEmpty(board[7]))
		{
			board[7] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[7]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	case 3:
		if (isEmpty(board[8]))
		{
			board[8] = 'x';
			drawBoard(board);
			break;
		}
		if (isOccupied(board[8]))
		{
			std::cout << "That tile is occupied!\n";
			turn(board);
			break;
		}
	default:
		std::cout << "Please choose a valid move!\n";
		turn(board);
		break;
	}
}

void cpuTurn(char* board)
{
	bool turn = true;
	while (turn)
	{
		int chance = rand() % 9;
		if (isEmpty(board[chance]))
		{
			board[chance] = 'o';
			drawBoard(board);
			turn = false;
			
		}
		else if (isOccupied(board[chance]))
		{
			cpuTurn(board);
			turn = false;
		}
		
	}
}

int main()
{
	srand(time(0));
	char board[9];
	initializeBoard(board);
	while (gameState(board))
	{
		turn(board);
		if (gameState(board))
		cpuTurn(board);
	}
}