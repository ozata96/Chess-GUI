#include "ChessBoard.hpp"
#include "ChessPiece.hpp"
#include<iostream>

using namespace std;


#ifdef __cplusplus__

  #include <iostream>
  #include <string>

  void ClearScreen()
    {
    cout << string( 100, '\n' );
    }

#else

  #include <stdio.h>

  void ClearScreen()
    {
    int n;
    for (n = 0; n < 10; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

#endif


int main() {
     string move = "";
     ClearScreen();
     ChessBoard cb;
     while (move != "EXIT")
     {
          cout << endl << "Please enter a move:" << endl;
          cin >> move;
          ClearScreen();
          cb.intakeMove(move);
     }
    return 0;
}
