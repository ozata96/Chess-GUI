#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP

#include <iostream>


enum Color {White, Black};
// Used to differentiate between white and black pieces, as well as player turns

//============================================================================//
//============================== Main Piece Class ============================//
//============================================================================//

class ChessPiece {
public:
    ChessPiece(Color chosenColor, std::string chosenType, std::string chosenSymbol);
    // General constructor for a chess piece
    
    ChessPiece();
    
    ~ChessPiece();
    // General destructor for a chess piece
    
    virtual std::string getType()const;
    // Returns the type of a designated piece identified by board coordinates
    // For example: King, Queen, Bishop, Knight, Rook, Pawn
    
    virtual bool isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo);
    // Function that checks move legality, is overwritten by all other piece functions
    
    Color getColor();
    // Returns the color of a designated piece identified by board coordinates
    // Either White (enum 0) or Black (enum 1)
    
    bool areParametersValid(int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if the coordinates are limited to 8x8 coordinates

    virtual std::string getSymbol()const;
    // Returns the symbol of the chess piece

protected:
    // Board pointer class member
    class ChessBoard* board;
    
    // Piece type class member
    std::string type;
    
    // Piece color class member
    Color color;

    //Symbol
    std::string symbol;
};

//============================================================================//
//============================= Piece Sub-Classes ============================//
//============================================================================//

//============ King Class ============//
class King: public ChessPiece {
public:
    King(Color color, std::string type, std::string chosenSymbol);
    // Constructor for a King piece

    ~King();
    // Destructor for a King piece

    bool isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if the given coordinates for the current position and destination
    // abide by the rules of a King piece in chess, else it returns false
};
    
//============ Queen Class ============//
class Queen: public ChessPiece {
public:
    Queen(Color color, std::string type, std::string chosenSymbol);
    // Constructor for a Queen piece

    ~Queen();
    // Destructor for a Queen piece

    bool isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if the given coordinates for the current position and destination
    // abide by the rules of a Queen piece in chess, else it returns false
};
    
//============ Bishop Class ============//
class Bishop: public ChessPiece {
public:
    Bishop(Color color, std::string type, std::string chosenSymbol);
    // Constructor for a Bishop piece

    ~Bishop();
    // Destructor for a Bishop piece

    bool isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if the given coordinates for the current position and destination
    // abide by the rules of a Bishop piece in chess, else it returns false
};
    
//============ Rook Class ============//
class Rook: public ChessPiece {
public:
    Rook(Color color, std::string type, std::string chosenSymbol);
    // Constructor for a Rook piece

    ~Rook();
    // Destructor for a Rook piece

    bool isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if the given coordinates for the current position and destination
    // abide by the rules of a Rook piece in chess, else it returns false
};


//============ Knight Class ============//
class Knight: public ChessPiece {
public:
    Knight(Color color, std::string type, std::string chosenSymbol);
    // Constructor for a Knight piece

    ~Knight();
    // Destructor for a Knight piece

    bool isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if the given coordinates for the current position and destination
    // abide by the rules of a Knight piece in chess, else it returns false
};
    
    
//============ Pawn Class ============//
class Pawn: public ChessPiece {
public:
    Pawn(Color color, std::string type, std::string chosenSymbol);
    // Constructor for a Pawn piece
    
    ~Pawn();
    // Destructor for a Pawn piece

    bool isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo);
    // Returns true if the given coordinates for the current position and destination
    // abide by the rules of a Pawn piece in chess, else it returns false
};


#endif









