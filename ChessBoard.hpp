#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include <iostream>
#include <string>
#include "ChessPiece.hpp"

class ChessBoard {
private:
    ChessPiece* board[8][8];
    //2D array of chess pieces
    
    Color playerTurn;
    // Data member that designates player turn based on color

public:
    ChessBoard();
    // Constructor for Chessboard, includes the resetBoard function

    ~ChessBoard();
    //Destructor for Chessboard

    void resetBoard();
    // Clears the chess board and places chess pieces in their initial positions

    bool areParametersValid(int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if given coordinates are within range of a 8x8 chessboard
    // Returns false if not

    int convertToRow(std::string coordinate);
    // Function to convert ROW for "XY" notation into [Y][X] notation for board coordinates
    // Returns an integer to be used as the row coordinate in board[8][8]
    
    int convertToCol(std::string coordinate);
    // Function to convert COLUMN for "XY" notation into [Y][X] notation for board coordinates
    // Returns an integer to be used as the column coordinate in board[8][8]

    void intakeMove(std::string input);
    
    bool submitMove(std::string fromPosition, std::string toPosition);
    // Returns true if the move abides by all the rules of chess and places piece from given
    // position to given destination
    
    bool makeMove(ChessPiece *board[8][8], std::string fromPosition, std::string toPosition);
    // Returns true if the fromPosition/toPosition coordinates abide by the rules and the chess
    // piece was successfully moved

    void changeTurns();
    // Changes the player turn color to the other player turn color, either White or Black

    bool isKingChecked(Color color);
    // Returns true if the king is in check
    // Returns false if the king is not in check
    
    bool isKingThreatened(int row, int col, Color color);
    // Returns true if the king can be killed by an opponent's piece
    // Returns false if the king is safe
    
    bool whiteMoves(ChessPiece* board[8][8], int rowFrom, int colFrom, int rowTo, int colTo, std::string fromPosition, std::string toPosition);
    // Returns true if the movement of a white piece was successful
    // Returns false if it was not, along with error messages
    
    bool blackMoves(ChessPiece* board[8][8], int rowFrom, int colFrom, int rowTo, int colTo, std::string fromPosition, std::string toPosition);
    // Returns true if the movement of a black piece was successful
    // Returns false if it was not, along with error messages

    bool hasMoves(Color color);
    // Returns true if player has moves available
    // Returns false if player does not have moves available
    
    bool isMoveViable(ChessPiece* board[8][8], int row, int col, int rowAlt, int colAlt);
    // Returns true if a move can be made without the king being checked
    // Returns false if not

    void printBoard (ChessPiece* board[8][8]);
    
};


#endif
