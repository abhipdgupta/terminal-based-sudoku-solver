#include <iostream>
#include <string.h>
#include<conio.h>
using namespace std;

class SudokuSolver
{

public:
    void print_board(int **board, string unsolved);
    int **get_board();
    bool checker(int **board, int i, int j, int place);
    bool solver(int **board);
    bool alreadysolved(int **board);
};

int main()
{
    SudokuSolver ss;

    printf("\n...Enter your Unsolved Sudoku....\nInitialize empty spaces with 0 \n");
    int **board = ss.get_board();
    ss.print_board(board, "UNSOLVED SUDOKU");

    if (ss.alreadysolved(board))
        printf("\n\nNO VALID SOLUTION FOUND RECHECK YOUR SUDOKU\n\n");
    else
    {
        ss.solver(board);
        ss.print_board(board, "SOLVED SUDOKU");
    }

	getch();

    return 0;
}

bool SudokuSolver::alreadysolved(int **board)
{

    for (int i = 0; i < 9; i++)
    {

        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] == 0)
            {
                return false;
            }
        }
    }

    return true;
}

void SudokuSolver::print_board(int **board, string sudo)
{

    cout << "\n\n";
    cout << "........" << sudo << "........\n\n"
         << endl;
    for (int i = 0; i < 9; i++)
    {

        if (i % 3 == 0 && i != 0)
        {
            for (int x = 0; x < 3; x++)
            {
                cout << " -  -  -  ";
            }
            cout << endl;
        }
        for (int j = 0; j < 9; j++)
        {

            cout << " " << board[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "|";

            if (j == 8)
                cout << endl;
        }
    }

    cout << "\n\n"
         << endl;
}
// dynamically allocated memory and initialize board
int **SudokuSolver::get_board()
{
    int **board = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        board[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            int x;
            cin >> x;

            board[i][j] = x;
        }
    }

    return board;
}

bool SudokuSolver::checker(int **board, int i, int j, int place)
{
    // check in jumn
    for (int co = 0; co < 9; co++)
    {
        if (board[co][j] == place)
            return false;
    }

    // check in i
    for (int ro = 0; ro < 9; ro++)
    {
        if (board[i][ro] == place)
            return false;
    }

    // check in grid 3*3
    if (i >= 0 && i <= 2)
    {
        if (j >= 0 && j <= 2)
        {
            for (int y = 0; y <= 2; y++)
            {
                for (int z = 0; z <= 2; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }

        if (j >= 3 && j <= 5)
        {
            for (int y = 0; y <= 2; y++)
            {
                for (int z = 3; z <= 5; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }

        if (j >= 6 && j <= 8)
        {
            for (int y = 0; y <= 2; y++)
            {
                for (int z = 6; z <= 8; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }
    }
    if (i > 3 && i <= 5)
    {
        if (j >= 0 && j <= 2)
        {
            for (int y = 3; y <= 5; y++)
            {
                for (int z = 0; z <= 2; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }

        if (j >= 3 && j <= 5)
        {
            for (int y = 3; y <= 5; y++)
            {
                for (int z = 3; z <= 5; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }

        if (j >= 6 && j <= 8)
        {
            for (int y = 3; y <= 5; y++)
            {
                for (int z = 6; z <= 8; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }
    }
    if (i >= 6 && i <= 8)
    {
        if (j >= 0 && j <= 2)
        {
            for (int y = 6; y <= 8; y++)
            {
                for (int z = 0; z <= 2; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }

        if (j >= 3 && j <= 5)
        {
            for (int y = 6; y <= 8; y++)
            {
                for (int z = 3; z <= 5; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }

        if (j >= 6 && j <= 8)
        {
            for (int y = 6; y <= 8; y++)
            {
                for (int z = 6; z <= 8; z++)
                {
                    if (board[y][z] == place)
                        return false;
                }
            }
        }
    }

    return true;
}

bool SudokuSolver::solver(int **board)
{
    bool solved = true;

    for (int i = 0; i < 9; i++)
    {
        int place = 1;
        for (int j = 0; j < 9; j++)
        {

            if (board[i][j] == 0)
            {

                solved = false;

                for (place = 1; place <= 9; place++)
                {
                    if (checker(board, i, j, place))
                    {
                        board[i][j] = place;
                        if (solver(board))
                            return true;

                        board[i][j] = 0;
                    }
                }

                if (place == 9 + 1)
                    break;
            }
        }

        if (place == 9 + 1)
            break;
    }
    if (solved)
        return true;
    else
        return false;
}
