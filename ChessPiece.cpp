#include <iostream>

#include "ChessPiece.hpp"
#include "ChessBoard.hpp"

using namespace std;

//============================================================================//
//============================== Main Piece Class ============================//
//============================================================================//

// The general constructor for a chess piece
ChessPiece::ChessPiece(Color chosenColor, string chosenType, string chosenSymbol){
    type = chosenType;
    color = chosenColor;
    symbol = chosenSymbol;
};

ChessPiece::ChessPiece(){};

// The general destructor for a chesspiece
ChessPiece::~ChessPiece(){};

// Function that gets the type of piece at specific coordinates
string ChessPiece::getType()const{return type;};

// Function that returns the color of a piece at specific coordinates
Color ChessPiece::getColor(){return color;};

// Function that returns the symbol of a chess piece
string ChessPiece::getSymbol()const{return symbol;};

// All other piece functions will override this function, general function that checks if a move is legal
bool ChessPiece::isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo){
        if (rowFrom == rowTo && colFrom == colTo)
            return false;
    return false;
};

//============================================================================//
//============================= Piece Sub-Classes ============================//
//============================================================================//

//============ King Class ============//

// Constructor for a King piece
King::King(Color chosenColor, string chosenType, string chosenSymbol){
    type = chosenType;
    color = chosenColor;
    symbol = chosenSymbol;
};

// Destructor for a King piece
King::~King(){};

// The valid moves for a King piece
bool King::isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo){
    ChessPiece* current = board[rowFrom][colFrom];
    ChessPiece* destination = board[rowTo][colTo];

    if (rowFrom == rowTo){
        if (colFrom + 1 == colTo || colFrom - 1 == colTo)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
        
    } else if (rowFrom + 1 == rowTo){
        if (colFrom <= colTo + 1 && colFrom >= colTo - 1){
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
        }

    } else if (rowFrom - 1 == rowTo){
        if (colFrom <= colTo + 1 && colFrom >= colTo -1){
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
        }
    }
    return false;
};

    
//============ Queen Class ============//

// Constructor for a Queen piece
Queen::Queen(Color chosenColor, string chosenType, string chosenSymbol){
    type = chosenType;
    color = chosenColor;
    symbol = chosenSymbol;

};

// Destructor for a Queen piece
Queen::~Queen(){};

// The valid moves for a Queen piece
bool Queen::isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo){
    ChessPiece* current = board[rowFrom][colFrom];
    ChessPiece* destination = board[rowTo][colTo];
    
    if (abs(rowTo - rowFrom) == abs(colTo - colFrom)){
        if (destination == nullptr || destination->getColor() != current->getColor()){
            int rowSkip;
            if ((rowTo - rowFrom) > 0)
                rowSkip = 1;
            else
                rowSkip = -1;
            int colSkip;
            if ((colTo - colFrom) > 0)
                colSkip = 1;
            else
                colSkip = -1;
            
            int rowChecks = rowFrom + rowSkip;
            int colChecks = colFrom + colSkip;
            while (colChecks != colTo){
                if (board[rowChecks][colChecks] != nullptr)
                    return false;
                rowChecks = rowChecks + rowSkip;
                colChecks = colChecks + colSkip;
            }
            return true;
        }
    }
    else if (rowFrom == rowTo){
        if (colTo <= 7 && colTo >= 0)
            if (destination == nullptr || destination->getColor() != current->getColor()){
                int colSkip;
                if ((colTo - colFrom) > 0)
                    colSkip = 1;
                else
                    colSkip = -1;
                int colChecks = colFrom + colSkip;
                while (colChecks != colTo){
                    if (board[rowFrom][colChecks] != nullptr)
                        return false;
                    colChecks = colChecks + colSkip;
                }
                return true;
            }
    }
    
    else if (colFrom == colTo){
        if (rowTo <= 7 && rowTo >= 0)
            if (destination == nullptr || destination->getColor() != current->getColor()){
                int rowSkip;
                if ((rowTo - rowFrom) > 0)
                    rowSkip = 1;
                else
                    rowSkip = -1;
    
                int rowChecks = rowFrom + rowSkip;
                while (rowChecks != rowTo){
                    if (board[rowChecks][colFrom] != nullptr)
                        return false;
                    rowChecks = rowChecks + rowSkip;
                }
                return true;
            }
    }
    return false;
};

//============ Bishop Class ============//

// Constructor for a Bishop piece
Bishop::Bishop(Color chosenColor, string chosenType, string chosenSymbol){
    type = chosenType;
    color = chosenColor;
    symbol = chosenSymbol;

};

// Destructor for a Bishop piece
Bishop::~Bishop(){};

// The valid moves for a Bishop piece
bool Bishop::isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo){
    ChessPiece* current = board[rowFrom][colFrom];
    ChessPiece* destination = board[rowTo][colTo];

    if (abs(rowTo - rowFrom) == abs(colTo - colFrom))
        if (destination == nullptr || destination->getColor() != current->getColor()){
            int rowSkip;
            if ((rowTo - rowFrom) > 0)
                rowSkip = 1;
            else
                rowSkip = -1;
            int colSkip;
            if ((colTo - colFrom) > 0)
                colSkip = 1;
            else
                colSkip = -1;
            
            int rowChecks = rowFrom + rowSkip;
            int colChecks = colFrom + colSkip;
            while (colChecks != colTo){
                if (board[rowChecks][colChecks] != nullptr)
                    return false;
                rowChecks = rowChecks + rowSkip;
                colChecks = colChecks + colSkip;
            }
            return true;
        }
    return false;
};
    

//============ Rook Class ============//

// Constructor for a Rook piece
Rook::Rook(Color chosenColor, string chosenType, string chosenSymbol){
    type = chosenType;
    color = chosenColor;
    symbol = chosenSymbol;

};

// Destructor for a Rook piece
Rook::~Rook(){};

// The valid moves for a Rook piece
bool Rook::isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo){
    ChessPiece* current = board[rowFrom][colFrom];
    ChessPiece* destination = board[rowTo][colTo];
    
    if (rowFrom == rowTo){
        if (colTo <= 7 && colTo >= 0)
            if (destination == nullptr || destination->getColor() != current->getColor()){
                int colSkip;
                if ((colTo - colFrom) > 0)
                    colSkip = 1;
                else
                    colSkip = -1;
                
                int colChecks = colFrom + colSkip;
                while (colChecks != colTo){
                    if (board[rowFrom][colChecks] != nullptr)
                        return false;
                    colChecks = colChecks + colSkip;
                }
                return true;
            }
    }
    else if (colFrom == colTo){
        if (rowTo <= 7 && rowTo >= 0)
            if (destination == nullptr || destination->getColor() != current->getColor()){
                int rowSkip;
                if ((rowTo - rowFrom) > 0)
                    rowSkip = 1;
                else
                    rowSkip = -1;
                
                int rowChecks = rowFrom + rowSkip;
                while (rowChecks != rowTo){
                    if (board[rowChecks][colFrom] != nullptr)
                        return false;
                    rowChecks = rowChecks + rowSkip;
                }
                return true;
            }
    }
    return false;
};

//============ Knight Class ============//

// Constructor for a Knight piece
Knight::Knight(Color chosenColor, string chosenType, string chosenSymbol){
    type = chosenType;
    color = chosenColor;
    symbol = chosenSymbol;

};

// Destructor for a Knight piece
Knight::~Knight(){};

// The valid moves for a Knight piece
bool Knight::isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo){
    ChessPiece* current = board[rowFrom][colFrom];
    ChessPiece* destination = board[rowTo][colTo];
            
    if (colFrom == colTo - 1){
        if (rowFrom == rowTo + 2)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
        if (rowFrom == rowTo - 2)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
    }
    if (colFrom == colTo - 2){
        if (rowFrom == rowTo - 1)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
        if (rowFrom == rowTo + 1)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
    }
    
    if (colFrom == colTo + 1){
        if (rowFrom == rowTo + 2)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
        if (rowFrom == rowTo - 2)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
    }
    if (colFrom == colTo + 2){
        if (rowFrom == rowTo + 1)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
        if (rowFrom == rowTo - 1)
            if (destination == nullptr || destination->getColor() != current->getColor())
                return true;
    }
    return false;
};


//============ Pawn Class ============//

// Constructor for a Pawn piece
Pawn::Pawn(Color chosenColor, string chosenType, string chosenSymbol){
    type = chosenType;
    color = chosenColor;
    symbol = chosenSymbol;

};

// Destructor for a Pawn piece
Pawn::~Pawn(){};

// The valid moves for a Pawn piece
bool Pawn::isMoveLegal(ChessPiece *board[8][8], int rowFrom, int colFrom, int rowTo, int colTo){
    ChessPiece* current = board[rowFrom][colFrom];
    ChessPiece* destination = board[rowTo][colTo];

    if (current->getColor() == White){
        if (colFrom == colTo)
            if (destination == nullptr){
                if ((rowFrom == 6) && ((rowFrom - rowTo == 1)))
                    return true;
                if (rowFrom == 6 && (rowFrom - rowTo == 2))
                    if (board[rowFrom - 1][colTo] == nullptr)
                        return true;
                if (rowFrom != 6 && rowFrom - rowTo == 1)
                    return true;
            }
        
        if (colFrom != colTo)
            if (destination != nullptr && destination->getColor() == Black)
                if (rowFrom - 1 == rowTo){
                    if ((colFrom - 1 == colTo) || (colFrom + 1 == colTo))
                        return true;
        }
    }

    if (current->getColor() == Black){
        if (colFrom == colTo)
            if (destination == nullptr){
                if ((rowFrom == 1) && ((rowTo - rowFrom == 1)))
                    return true;
                if (rowFrom == 1 && rowTo - rowFrom == 2)
                    if (board[rowTo - 1][colTo] == nullptr)
                        return true;
                if (rowFrom != 1 && (rowTo - rowFrom == 1))
                    return true;
            }

        if (colFrom != colTo)
            if (destination != nullptr && destination->getColor() == White)
                if (rowTo - 1 == rowFrom){
                    if ((colFrom - 1 == colTo) || (colFrom + 1 == colTo))
                        return true;
        }
    }
    return false;
};
    
