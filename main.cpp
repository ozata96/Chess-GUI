#include "ChessBoard.hpp"
#include "ChessPiece.hpp"
#include <iostream>

using namespace std;

void ClearScreen()
{
  int n;
  for (n = 0; n < 10; n++)
    printf("\n\n\n\n\n\n\n\n\n\n");
}

int main()
{
  string move = "";
  ClearScreen();
  ChessBoard cb;
  while (move != "EXIT")
  {
    cout << endl
         << "Please enter a move:" << endl;
    cin >> move;
    ClearScreen();
    cb.intakeMove(move);
  }
  return 0;
}
