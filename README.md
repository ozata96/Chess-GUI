# Chess with GUI

A C++ project that has a fully functional two-player chess engine built from scratch. The chess engine keeps track of:
* Which player's turn it is
* Valid and invalid moves
* A narration that describes which player moved which piece (ie. Black's Bishop moves from B3 to D5 and captures White's Pawn)
* If a player is in check
* If there is a stalemate
* If a player has been checkmated
* A GUI board that displays player moves within the terminal

## Table of Contents
* Part 1: The Board
* Part 2: A Game in Action
* Part 3: How to Download and Play


# The Board

The board is a 9x9 terminal grid that is meant to give a visual display of player moves.

  .| **A** | B | C | D | E | F | G | H    
-- | -- | -- | -- | -- | -- | -- | -- | --
**8** | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ | 
**7** | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | 
**6** |   |   |   |   |   |   |   |   | 
**5** |   |   |   |   |   |   |   |   |
**4** |   |   |   |   |   |   |   |   |
**3** |   |   |   |   |   |   |   |   |
**2** | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | 
**1** | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |



# A Game in Action

To demonstrate how a game would work, players would first be presented with the game board:

  .| **A** | B | C | D | E | F | G | H    
-- | -- | -- | -- | -- | -- | -- | -- | --
**8** | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ | 
**7** | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | 
**6** |   |   |   |   |   |   |   |   | 
**5** |   |   |   |   |   |   |   |   |
**4** |   |   |   |   |   |   |   |   |
**3** |   |   |   |   |   |   |   |   |
**2** | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | ♟︎ | 
**1** | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |

as well as a text below that states:
<br />Please enter a move:

A player would then type in:
<br />D2D4

The board would then update to:

  .| **A** | B | C | D | E | F | G | H    
-- | -- | -- | -- | -- | -- | -- | -- | --
**8** | ♖ | ♘ | ♗ | ♕ | ♔ | ♗ | ♘ | ♖ | 
**7** | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | ♙ | 
**6** |   |   |   |   |   |   |   |   | 
**5** |   |   |   |   |   |   |   |   |
**4** |   |   |   | ♟︎ |   |   |   |   |
**3** |   |   |   |   |   |   |   |   |
**2** | ♟︎ | ♟︎ | ♟︎ |   | ♟︎ | ♟︎ | ♟︎ | ♟︎ | 
**1** | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |

<br /> White must move first. If black attempts to move first then an error message will appear.

<br />And so the game continues in this way. The chess engine keeps track of illegal moves made by players as well as win conditions.
For example, if a player attempted to move a pawn across the board, or made a move that was out of turn, then the chess engine would prevent this from occurring.
A limitation of this program is that the chess engine cannot control any pieces, as a result, the player cannot play against a bot. Instead, the program was designed 
to demonstrate implementing the logic of the rules of chess into a program. A future improvement would be to implement a chess bot that can actually play against the player.

<br />The following are some of the conditions that the chess engine recognizes:

### White is in CHECK
  .| **A** | B | C | D | E | F | G | H    
-- | -- | -- | -- | -- | -- | -- | -- | --
**8**   | ♖ | ♘ | ♗ | ♕ | ♔ |   | ♘ | ♖ | 
**7**   | ♙ | ♙ | ♙ |   |   | ♙ | ♙ | ♙ | 
**6**   |   |   |   |   |   |   |   |   | 
**5**   |   |   |   | ♙ | ♟︎ |   |   |   |
**4**   |   | ♗ |   |   | ♟︎ |   |   |   |
**3**   |   |   |   |   |   |   |   |   |
**2**   | ♟︎ | ♟︎ | ♟︎ |   |   | ♟︎ | ♟︎ | ♟︎ | 
**1**   | ♜ | ♞ | ♝ | ♛ | ♚ | ♝ | ♞ | ♜ |

### STALEMATE (White's Turn to Move)

  .| **A** | B | C | D | E | F | G | H    
-- | -- | -- | -- | -- | -- | -- | -- | --
**8**   |   |   | ♗ |   |   | ♔ |   |   | 
**7**   |   |   |   |   |   |   |   |   | 
**6**   |   |   |   |   |   |   | ♙ |   | 
**5**   |   |   | ♗ |   |   |   | ♟︎ |   |
**4**   |   |   |   |   |   |   |   |   |
**3**   |   |   |   |   | ♘ |   |   |   |
**2**   |   | ♕ |   |   |   |   |   |   | 
**1**   |   |   |   |   | ♚ |   |   |   |

### CHECKMATE (Black is in CHECKMATE)
  .| **A** | B | C | D | E | F | G | H    
-- | -- | -- | -- | -- | -- | -- | -- | --
**8**   | ♖ |   |   |   |   |   | ♔ |   | 
**7**   |   | ♗ | ♙ |   |   |   | ♛ |   | 
**6**   |   | ♙ |   |   |   | ♜ |   | ♝ | 
**5**   |   |   |   |   |   |   |   | ♙ |
**4**   |   |   | ♝ | ♘ | ♟︎ |   | ♙ | ♟︎ |
**3**   | ♙ |   |   |   |   |   | ♟︎ |   |
**2**   |   |   | ♟︎ |   |   |   |   |   | 
**1**   |   |   |   |   | ♚ |   | ♞ |   |

# How to Download and Play

In order to try this out yourself, please download the github repositry and run it in a C++ environment. The game should immediately begin within the terminal.
<br />Type in commands in the following format:
* D2D3 (moves white's pawn from square D2 to square D3).
* E7E6 (moves black's pawn from square E7 to square E6).
<br /> The first coordinate selects the piece on that square, and moves it to the second coordinate typed in. There are error checks to
ensure that the piece can legally be moved from one coordinate to another.
