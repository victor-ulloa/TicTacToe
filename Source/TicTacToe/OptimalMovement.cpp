#pragma once

#include "UI/CustomButton.h"

struct Position
{
    int row, col;
};

struct OptimalMovement
{

    char player = 'x', opponent = 'o';

    // This function returns true if there are moves
    // remaining on the board. It returns false if
    // there are no moves left to play.
    bool isMovesLeft(char board[3][3])
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == '_')
                    return true;
        return false;
    }

    bool hasMovesLeft(UCustomButton *Board[3][3])
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                return Board[i][j]->State == UCustomButton::ButtonState::NONE;
        return false;
    }

    int EvaluateBoard(UCustomButton *Board[3][3])
    {
        // Checking for Rows for X or O victory.
        for (int row = 0; row < 3; row++)
        {
            if (Board[row][0]->State == Board[row][1]->State &&
                Board[row][1]->State == Board[row][2]->State)
            {
                if (Board[row][0]->State == UCustomButton::ButtonState::X)
                    return +10;
                else if (Board[row][0]->State == UCustomButton::ButtonState::O)
                    return -10;
            }
        }

        // Checking for Columns for X or O victory.
        for (int col = 0; col < 3; col++)
        {
            if (Board[0][col]->State == Board[1][col]->State &&
                Board[1][col]->State == Board[2][col]->State)
            {
                if (Board[0][col]->State == UCustomButton::ButtonState::X)
                    return +10;

                else if (Board[0][col]->State == UCustomButton::ButtonState::O)
                    return -10;
            }
        }

        // Checking for Diagonals for X or O victory.
        if (Board[0][0]->State == Board[1][1]->State && Board[1][1]->State == Board[2][2]->State)
        {
            if (Board[0][0]->State == UCustomButton::ButtonState::X)
                return +10;
            else if (Board[0][0]->State == UCustomButton::ButtonState::O)
                return -10;
        }

        if (Board[0][2]->State == Board[1][1]->State && Board[1][1]->State == Board[2][0]->State)
        {
            if (Board[0][2]->State == UCustomButton::ButtonState::X)
                return +10;
            else if (Board[0][2]->State == UCustomButton::ButtonState::O)
                return -10;
        }

        // Else if none of them have won then return 0
        return 0;
    }

    int evaluate(char b[3][3])
    {
        // Checking for Rows for X or O victory.
        for (int row = 0; row < 3; row++)
        {
            if (b[row][0] == b[row][1] &&
                b[row][1] == b[row][2])
            {
                if (b[row][0] == player)
                    return +10;
                else if (b[row][0] == opponent)
                    return -10;
            }
        }

        // Checking for Columns for X or O victory.
        for (int col = 0; col < 3; col++)
        {
            if (b[0][col] == b[1][col] &&
                b[1][col] == b[2][col])
            {
                if (b[0][col] == player)
                    return +10;

                else if (b[0][col] == opponent)
                    return -10;
            }
        }

        // Checking for Diagonals for X or O victory.
        if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
        {
            if (b[0][0] == player)
                return +10;
            else if (b[0][0] == opponent)
                return -10;
        }

        if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
        {
            if (b[0][2] == player)
                return +10;
            else if (b[0][2] == opponent)
                return -10;
        }

        // Else if none of them have won then return 0
        return 0;
    }

    int Minimax_(UCustomButton* Board[3][3], int depth, bool isMax)
    {
        int score = EvaluateBoard(Board);

        // If Maximizer has won the game return his/her
        // evaluated score
        if (score == 10)
            return score;

        // If Minimizer has won the game return his/her
        // evaluated score
        if (score == -10)
            return score;

        // If there are no more moves and no winner then
        // it is a tie
        if (!hasMovesLeft(Board))
            return 0;

        // If this maximizer's move
        if (isMax)
        {
            int best = -1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (Board[i][j]->State == UCustomButton::ButtonState::NONE)
                    {
                        // Make the move
                        Board[i][j]->State = UCustomButton::ButtonState::X;

                        // Call minimax recursively and choose
                        // the maximum value
                        best = std::max(best, Minimax_(Board, depth + 1, !isMax));

                        // Undo the move
                        Board[i][j]->State = UCustomButton::ButtonState::NONE;
                    }
                }
            }
            return best;
        }

        // If this minimizer's move
        else
        {
            int best = 1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (Board[i][j]->State == UCustomButton::ButtonState::NONE)
                    {
                        // Make the move
                        Board[i][j]->State = UCustomButton::ButtonState::O;

                        // Call minimax recursively and choose
                        // the minimum value
                        best = std::min(best, Minimax_(Board, depth + 1, !isMax));

                        // Undo the move
                        Board[i][j]->State = UCustomButton::ButtonState::NONE;
                    }
                }
            }
            return best;
        }
    }

    int minimax(char board[3][3], int depth, bool isMax)
    {
        int score = evaluate(board);

        // If Maximizer has won the game return his/her
        // evaluated score
        if (score == 10)
            return score;

        // If Minimizer has won the game return his/her
        // evaluated score
        if (score == -10)
            return score;

        // If there are no more moves and no winner then
        // it is a tie
        if (isMovesLeft(board) == false)
            return 0;

        // If this maximizer's move
        if (isMax)
        {
            int best = -1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (board[i][j] == '_')
                    {
                        // Make the move
                        board[i][j] = player;

                        // Call minimax recursively and choose
                        // the maximum value
                        best = std::max(best, minimax(board, depth + 1, !isMax));

                        // Undo the move
                        board[i][j] = '_';
                    }
                }
            }
            return best;
        }

        // If this minimizer's move
        else
        {
            int best = 1000;

            // Traverse all cells
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    // Check if cell is empty
                    if (board[i][j] == '_')
                    {
                        // Make the move
                        board[i][j] = opponent;

                        // Call minimax recursively and choose
                        // the minimum value
                        best = std::min(best, minimax(board, depth + 1, !isMax));

                        // Undo the move
                        board[i][j] = '_';
                    }
                }
            }
            return best;
        }
    }

    // This will return the best possible move for the player
    Position findBestMove(char board[3][3])
    {
        int bestVal = -1000;
        Position bestMove;
        bestMove.row = -1;
        bestMove.col = -1;

        // Traverse all cells, evaluate minimax function for
        // all empty cells. And return the cell with optimal
        // value.
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == '_')
                {
                    // Make the move
                    board[i][j] = player;

                    // compute evaluation function for this
                    // move.
                    int moveVal = minimax(board, 0, false);

                    // Undo the move
                    board[i][j] = '_';

                    // If the value of the current move is
                    // more than the best value, then update
                    // best/
                    if (moveVal > bestVal)
                    {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }

        // printf("The value of the best Move is : %d\n\n",
        //        bestVal);

        return bestMove;
    }


    Position FindBestMove_(UCustomButton* Board[3][3])
    {
        int bestVal = -1000;
        Position bestMove;
        bestMove.row = -1;
        bestMove.col = -1;

        // Traverse all cells, evaluate minimax function for
        // all empty cells. And return the cell with optimal
        // value.
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                // Check if cell is empty
                if (Board[i][j]->State == UCustomButton::ButtonState::NONE)
                {
                    // Make the move
                    Board[i][j]->State = UCustomButton::ButtonState::X;

                    // compute evaluation function for this
                    // move.
                    int moveVal = Minimax_(Board, 0, false);

                    // Undo the move
                    Board[i][j]->State = UCustomButton::ButtonState::NONE;

                    // If the value of the current move is
                    // more than the best value, then update
                    // best/
                    if (moveVal > bestVal)
                    {
                        bestMove.row = i;
                        bestMove.col = j;
                        bestVal = moveVal;
                    }
                }
            }
        }

        // printf("The value of the best Move is : %d\n\n",
        //        bestVal);

        UE_LOG(LogTemp, Display, TEXT("%i   %i"), bestMove.col, bestMove.row);

        return bestMove;
    }
};