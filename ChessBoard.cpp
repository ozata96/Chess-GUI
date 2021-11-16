#include "ChessBoard.hpp"
using namespace std;

// Constructor for chessboard
ChessBoard::ChessBoard()
{
    resetBoard();
};

// Destructor for chessboard
ChessBoard::~ChessBoard()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            board[row][col] = nullptr;
        }
    }
};

// Function that clears the chess board and places pieces in their initial positions
void ChessBoard::resetBoard()
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            board[row][col] = nullptr;
        }
    }
    // Initialize Black Side:
    board[0][0] = new Rook(Black, "Rook", "♖");
    board[0][1] = new Knight(Black, "Knight", "♘");
    board[0][2] = new Bishop(Black, "Bishop", "♗");
    board[0][3] = new Queen(Black, "Queen", "♕");
    board[0][4] = new King(Black, "King", "♔");
    board[0][5] = new Bishop(Black, "Bishop", "♗");
    board[0][6] = new Knight(Black, "Knight", "♘");
    board[0][7] = new Rook(Black, "Rook", "♖");
    for (int col = 0; col < 8; col++)
    {
        board[1][col] = new Pawn(Black, "Pawn", "♙");
    }
    // Initialize White Side:
    board[7][0] = new Rook(White, "Rook", "♜");
    board[7][1] = new Knight(White, "Knight", "♞");
    board[7][2] = new Bishop(White, "Bishop", "♝");
    board[7][3] = new Queen(White, "Queen", "♛");
    board[7][4] = new King(White, "King", "♚");
    board[7][5] = new Bishop(White, "Bishop", "♝");
    board[7][6] = new Knight(White, "Knight", "♞");
    board[7][7] = new Rook(White, "Rook", "♜");
    for (int col = 0; col < 8; col++)
    {
        board[6][col] = new Pawn(White, "Pawn", "♟");
    }
    playerTurn = White;
    cout << "A new chess game has started!" << endl;
    printBoard(board);
};

void ChessBoard::printBoard(ChessPiece *board[8][8])
{
    cout << endl
         << " A B C D E F G H";
    for (int i = 0; i < 8; i++)
    {
        cout << endl
             << "|";
        for (int j = 0; j < 8; j++)
        {
            if ((board[i][j]) == nullptr)
                cout << " |";
            if ((board[i][j]) != nullptr)
                cout << (board[i][j])->getSymbol() << "|";
        }
        cout << " ";

        switch (i)
        {
        case 0:
            cout << "8";
            break;
        case 1:
            cout << "7";
            break;
        case 2:
            cout << "6";
            break;
        case 3:
            cout << "5";
            break;
        case 4:
            cout << "4";
            break;
        case 5:
            cout << "3";
            break;
        case 6:
            cout << "2";
            break;
        case 7:
            cout << "1";
            break;
        }
    }
}

/*
    Chessboard visualization:
        |COL|                       |COL|
    __________________BLACK__________________
       A    B   C     D   E    F    G    H
    +----+----+----+----+----+----+----+----+
    | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 8
    +----+----+----+----+----+----+----+----+
    | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 7     |ROW|
    +----+----+----+----+----+----+----+----+
    | 20 | 21 | 22 | 23 | 24 | 25 | 26 | 27 | 6
    +----+----+----+----+----+----+----+----+
    | 30 | 31 | 32 | 33 | 34 | 35 | 36 | 37 | 5
    +----+----+----+----+----+----+----+----+
    | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 | 4
    +----+----+----+----+----+----+----+----+
    | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 | 3
    +----+----+----+----+----+----+----+----+
    | 60 | 61 | 62 | 63 | 64 | 65 | 66 | 67 | 2     |ROW|
    +----+----+----+----+----+----+----+----+
    | 70 | 71 | 72 | 73 | 74 | 75 | 76 | 77 | 1
    +----+----+----+----+----+----+----+----+
    __________________WHITE__________________
*/

// Check if given coordinates are within range of an 8x8 chessboard
bool ChessBoard::areParametersValid(int rowFrom, int colFrom, int rowTo, int colTo)
{
    if (rowFrom < 0 || rowFrom > 8)
    {
        cerr << "Error: invalid parameter range given." << endl;
        return false;
    }
    else if (colFrom < 0 || colFrom > 8)
    {
        cerr << "Error: invalid parameter range given." << endl;
        return false;
    }
    else if (rowTo < 0 || rowTo > 8)
    {
        cerr << "Error: invalid parameter range given." << endl;
        return false;
    }
    else if (colTo < 0 || colTo > 8)
    {
        cerr << "Error: invalid parameter range given." << endl;
        return false;
    }
    return true;
};

// Function to convert ROW for "XY" notation into [Y][X] notation for board coordinates
int ChessBoard::convertToRow(std::string coordinate)
{
    int row;

    string fromPosition = coordinate;
    char fromFile = fromPosition[1];
    int fromFileInt = static_cast<int>(fromFile) - 48;

    switch (fromFileInt)
    {
    case 1:
        fromFileInt = 7;
        break;
    case 2:
        fromFileInt = 6;
        break;
    case 3:
        fromFileInt = 5;
        break;
    case 4:
        fromFileInt = 4;
        break;
    case 5:
        fromFileInt = 3;
        break;
    case 6:
        fromFileInt = 2;
        break;
    case 7:
        fromFileInt = 1;
        break;
    case 8:
        fromFileInt = 0;
        break;
    default:
        cerr << endl
             << endl
             << "Please enter coordinates in this format: " << endl;
        cerr << "(XY, XY) with X = A-H, and Y = 1 - 8. " << endl;
        break;
    }
    row = fromFileInt;
    return row;
};

// Function to convert COLUMN for "XY" notation into [Y][X] notation for board coordinates
int ChessBoard::convertToCol(std::string coordinate)
{
    int col;
    string fromPosition = coordinate;
    char fromRank = fromPosition[0];
    int fromRankInt = static_cast<int>(fromRank) - 65;
    col = fromRankInt;
    return col;
};

void ChessBoard::intakeMove(std::string input)
{
    string param1 = "";
    string param2 = "";

    if (input.length() != 4)
        cerr << "Parameters are not valid" << endl;

    else if (input == "EXIT")
    {
        return;
    }

    else
    {
        param1.push_back(input[0]);
        param1.push_back(input[1]);
        param2.push_back(input[2]);
        param2.push_back(input[3]);

        submitMove(param1, param2);
    }
}

// Function that moves a chesspiece from given position to another position
bool ChessBoard::submitMove(std::string fromPosition, std::string toPosition)
{
    int rowFrom = convertToRow(fromPosition);
    int colFrom = convertToCol(fromPosition);
    int rowTo = convertToRow(toPosition);
    int colTo = convertToCol(toPosition);

    if (!areParametersValid(rowFrom, colFrom, rowTo, colTo))
    {
        cerr << "Parameters are not valid" << endl;
        return false;
    }

    if (board[rowFrom][colFrom] == nullptr)
        cerr << "There is no piece at position " << fromPosition << "!" << endl;

    if (board[rowFrom][colFrom] != nullptr)
        if (makeMove(board, fromPosition, toPosition))
            cout << endl;
    printBoard(board);
    cout << endl;
    return true;
    return false;
};

// Function that checks for errors and if the given move abides by the rules of chess
bool ChessBoard::makeMove(ChessPiece *board[8][8], std::string fromPosition, std::string toPosition)
{
    int rowFrom = convertToRow(fromPosition);
    int colFrom = convertToCol(fromPosition);
    int rowTo = convertToRow(toPosition);
    int colTo = convertToCol(toPosition);

    if (rowFrom == rowTo && colFrom == colTo)
    {
        cerr << "Error: destination coordinates are the same as origin." << endl;
        cerr << "The piece must move." << endl;
        return false;
    }

    ChessPiece *current = board[rowFrom][colFrom];
    if (current->getColor() != playerTurn)
    {
        if (current->getColor() == White)
        {
            cerr << "It is not White's turn to move." << endl;
            return false;
        }
        else if (current->getColor() == Black)
        {
            cerr << "It is not Black's turn to move." << endl;
            return false;
        }
    }

    if (current->isMoveLegal(board, rowFrom, colFrom, rowTo, colTo))
    {
        if (isKingChecked(current->getColor()))
        {
            if (current->getColor() == White)
            {
                if (whiteMoves(board, rowFrom, colFrom, rowTo, colTo, fromPosition, toPosition))
                    return true;
            }
            if (current->getColor() == Black)
            {
                if (blackMoves(board, rowFrom, colFrom, rowTo, colTo, fromPosition, toPosition))
                    return true;
            }
        }

        if (!isKingChecked(current->getColor()))
        {
            if (current->getColor() == White)
            {
                if (whiteMoves(board, rowFrom, colFrom, rowTo, colTo, fromPosition, toPosition))
                    return true;
            }

            if (current->getColor() == Black)
            {
                if (blackMoves(board, rowFrom, colFrom, rowTo, colTo, fromPosition, toPosition))
                    return true;
            }
        }
    }
    else
    {
        if (board[rowFrom][colFrom]->getColor() == White)
        {
            cout << endl
                 << "White's " << board[rowFrom][colFrom]->getType() << " cannot move from ";
            cout << fromPosition << " to " << toPosition << endl;
            return false;
        }
        if (board[rowFrom][colFrom]->getColor() == Black)
        {
            cout << endl
                 << "Black's " << board[rowFrom][colFrom]->getType() << " cannot move from ";
            cout << fromPosition << " to " << toPosition << endl;
            return false;
        }
    }
    return false;
};

// Helper function used within the makeMove function that checks for further rules and makes the move, is used only for team White
bool ChessBoard::whiteMoves(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo, std::string fromPosition, std::string toPosition)
{
    ChessPiece *current = board[rowFrom][colFrom];
    ChessPiece *piece = board[rowTo][colTo];
    ChessPiece *capturedPiece = board[rowTo][colTo];
    board[rowTo][colTo] = board[rowFrom][colFrom];

    if (board[rowTo][colTo]->getColor() == White)
    {
        board[rowFrom][colFrom] = nullptr;

        if (isKingChecked(current->getColor()))
        {
            if (current->getColor() == White)
            {
                cout << endl
                     << "Moving White's " << board[rowTo][colTo]->getType() << " from ";
                cout << fromPosition << " to " << toPosition << " puts the White King";
                cout << " in check. Invalid move." << endl;
                board[rowFrom][colFrom] = board[rowTo][colTo];
                board[rowTo][colTo] = piece;
                return false;
            }
        }

        cout << endl
             << "White's " << board[rowTo][colTo]->getType() << " moves from ";
        cout << fromPosition << " to " << toPosition;
        changeTurns();
        if (piece != nullptr)
        {
            cout << " taking Black's " << capturedPiece->getType();
        }

        if (!hasMoves(Black) && !isKingChecked(Black))
            cout << endl
                 << "Game ends in stalemate - Black has no moves" << endl;

        if (isKingChecked(Black))
        {
            cout << endl
                 << "Black is in check";
            if (!hasMoves(Black))
            {
                cout << "mate" << endl;
            }
        }
        return true;
    }
    return false;
};

// Helper function used within the makeMove function that checks for further rules and makes the move, is used only for team Black
bool ChessBoard::blackMoves(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo, std::string fromPosition, std::string toPosition)
{
    ChessPiece *current = board[rowFrom][colFrom];
    ChessPiece *piece = board[rowTo][colTo];
    ChessPiece *capturedPiece = board[rowTo][colTo];
    board[rowTo][colTo] = board[rowFrom][colFrom];

    if (board[rowTo][colTo]->getColor() == Black)
    {
        board[rowFrom][colFrom] = nullptr;

        if (isKingChecked(current->getColor()))
        {
            if (current->getColor() == Black)
            {
                cout << endl
                     << "Moving Black's " << board[rowTo][colTo]->getType() << " from ";
                cout << fromPosition << " to " << toPosition << " puts the Black King";
                cout << " in check. Invalid move." << endl;
                board[rowFrom][colFrom] = board[rowTo][colTo];
                board[rowTo][colTo] = piece;
                return false;
            }
        }
        cout << endl
             << "Black's " << board[rowTo][colTo]->getType() << " moves from ";
        cout << fromPosition << " to " << toPosition;
        changeTurns();
        if (piece != nullptr)
        {
            cout << " taking White's " << capturedPiece->getType();
        }

        if (!hasMoves(White) && !isKingChecked(White))
            cout << endl
                 << "Game ends in stalemate - White has no moves" << endl;

        if (isKingChecked(White))
        {
            cout << endl
                 << "White is in check";
            if (!hasMoves(White))
            {
                cout << "mate" << endl;
            }
        }
        return true;
    }
    return false;
};

// Function to check if the given color has moves available in general
bool ChessBoard::hasMoves(Color color)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int m = 0; m < 8; m++)
            {
                for (int n = 0; n < 8; n++)
                {
                    if (board[i][j] != nullptr)
                    {
                        if (board[i][j]->getColor() == color)
                        {
                            if (board[i][j]->isMoveLegal(board, i, j, m, n))
                            {
                                if (isMoveViable(board, i, j, m, n))
                                {
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
};

// Function that checks to see if a move can be completed without the king being checked
bool ChessBoard::isMoveViable(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo)
{
    ChessPiece *current = board[rowFrom][colFrom];
    ChessPiece *piece = board[rowTo][colTo];
    board[rowTo][colTo] = board[rowFrom][colFrom];
    board[rowFrom][colFrom] = nullptr;

    if (!isKingChecked(current->getColor()))
    {
        board[rowFrom][colFrom] = board[rowTo][colTo];
        board[rowTo][colTo] = piece;
        return true;
    }
    else
    {
        board[rowFrom][colFrom] = board[rowTo][colTo];
        board[rowTo][colTo] = piece;
        return false;
    }
};

// Function that changes turns to the opposite team
void ChessBoard::changeTurns()
{
    if (playerTurn == White)
        playerTurn = Black;
    else
        playerTurn = White;
};

// Helper function to check and see if any of the opponent pieces have moves that can kill the king
bool ChessBoard::isKingThreatened(int rowKing, int colKing, Color color)
{
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((board[row][col] != nullptr) && (board[row][col]->getColor() != color))
            {
                if (board[row][col]->isMoveLegal(board, row, col, rowKing, colKing))
                {
                    return true;
                }
            }
        }
    }
    return false;
};

// Function that finds the coordinates of the king of the designated color, and then checks to see if that king is threatened
bool ChessBoard::isKingChecked(Color pieceColor)
{
    int rowKing, colKing;
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            if ((board[row][col] != nullptr) && (board[row][col]->getColor() == pieceColor) && (board[row][col]->getType() == "King"))
            {
                rowKing = row;
                colKing = col;
                if (isKingThreatened(rowKing, colKing, pieceColor))
                {
                    if (pieceColor == White)
                    {
                        return true;
                    }
                    if (pieceColor == Black)
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
};
