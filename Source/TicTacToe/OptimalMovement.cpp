#pragma once

#include "UI/CustomButton.h"

struct Position
{
    int row, col;
};

struct OptimalMovement
{

    // This function returns true if there are moves
    // remaining on the board. It returns false if
    // there are no moves left to play.

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

    
    int Minimax(UCustomButton* Board[3][3], int depth, bool isMax)
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
                        best = std::max(best, Minimax(Board, depth + 1, !isMax));

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
                        best = std::min(best, Minimax(Board, depth + 1, !isMax));

                        // Undo the move
                        Board[i][j]->State = UCustomButton::ButtonState::NONE;
                    }
                }
            }
            return best;
        }
    }

    Position FindBestMove(UCustomButton* Board[3][3])
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
                    int moveVal = Minimax(Board, 0, false);

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

        // UE_LOG(LogTemp, Display, TEXT("%i   %i"), bestMove.col, bestMove.row);

        return bestMove;
    }
};