//
// Created by Deb on 9/2/2025.
//

#ifndef BOARD_H
#define BOARD_H

#include "Dog.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::string;

class Board {
	int size = 20;  //the square board's size
	char board[20][20]= {{'0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9'},
			{'1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0'},
			{'2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1'},
			{'3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2'},
			{'4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3'},
			{'5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4'},
			{'6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5'},
			{'7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6'},
			{'8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7'},
			{'9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8'},
			{'0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9'},
			{'1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0'},
			{'2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1'},
			{'3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2'},
			{'4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3'},
			{'5','6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4'},
			{'6','7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5'},
			{'7','8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6'},
			{'8','9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7'},
			{'9','0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8'}};
	//Note:  I gave the board initial values so you can test your printBoard method.  Normally you
	// wouldn't need to do this.

	int wallStrength;  //the amount of strenght needed to take down part of the wall (6)
	int startx;  //Where the dog enters the board (randomly along the left side)
	int starty;  //again, the dog's y entrance to the board (0)
	int endx;  // THe goal location on the right side (random x value)
	int endy;  // will be size -1
	char level; //'e' for easy, 'm' for medium, 'h' for hard (user can input in the initAll() method)
	Dog mydog;  //the dog object that's moving through
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//comment the above line in when you write your dog class!!!
	bool debug;
	//this is a boolean value that I used for debugging - so if it was true, and
	//I was in debug mode, I'd include a lot more print statements in each method
	//so I could see where I was and what was happening.  Then I could just switch
	//this to false and all the print statements would become invisible, but if I
	//moved on, I could always switch the debug print statemetns back on to see
	//what was happening in m code.
public:
	Board(const char diff, const string name, const bool d);
	/* constructor - has as a parameter the level of difficulty, the name I'll give
	 * to my dog object, and whether debug mode is on or off
	 * This method calls the initAll method.
	 */
	Board(const char diff, const bool d);
	/* constructor - sets level of difficulty and the debug mode.  With this the
	 * dog constructor that doesn't require a name is called, so the default dog's
	 * name is fluffy (which is set in the dog's constructor)
	 * This method calls the initAll method.
	 */
	Board(const bool d);
	/* for this constructor the level is set to be 'e' (which is the default), it calls
	 * the default dog constructor, and it calls the initAll method.
	 */
	void InitAll();
	/* (I'm giving you this one. )
	 * It loops for each playing of the game, continuing
	 * as long as the user enters "yes", "Yes","y", or "Y".  It asks the user and
	 * sets the level of difficulty.  It finds the start and end square that the
	 * dog must traverse, it calls boardConfig to configure the board, it calls
	 * printBoard to see the board, it calls addFood and addTraps. And then it calls
	 * the playGame method to start the game.  It loops to continuously reset everything
	 * and play another round of hte game for every time the user says they want to
	 * continue playing another round.
	 */
	void makeOneWall(const int xy, const bool col);
	// (7 pts)
 // xy is the random row or column where the wall will go, and col is a boolean value
 // indicating whether the wall will be a row (col is false) or a column (col is true
 //
 // I first determined how many "bricks" in the wall (yes, I'm that old) aka how many
 // squares make up the wall in one row or column.
 // I set the easy version to have at most 9 bricks (aka squares) per wall, the
 // medium to have at most 12 bricks per wall, and the hard version to
 // have at most 15 bricks per.(but you can play with this because sometimes
 // the hard version was seriously hard!!!
 //
 // I randomly chose k random squares squares in in the row or column to be a wall..
 // NOTE that if the square already had a wall in it, I overwrote it.
 //
	void boardConfig();
	//(8 pts)
	//Instructions for writing boardConfig:
	/* this method and the moveDog method are probably the longest methods.
	 * This method:
	 * 1)puts dummy values in every square (I used '+' because I just
	 * didn't want every square to have gibberish, so I chose a character I wasn't
	 * using for any other purpose and initialized every square to have that value).
	 *
	 * 2) Then adds random horizontal and vertical walls.
	 *
	 * Here's how I did it the walls:
	 * I randomly chose whether I'd be putting a row or a column in.
	 *
	 * I then randomly chose the row or column where I'd put the wall.
	 * Note that I only placed walls in the odd numbered rows and columns (in other
	 * words, rows 1,3, 5, 7, etc. could have a wall, but rows 0,2,4,6.. could not
	 *
	 * I checked to make sure that the row or column chosen didn't already have a wall.
	 *
	 * I generated a total of 10 (12, 14) walls in total (depending on e, m, or h level).

	 * For each wall, I called the method makeOneWall with the random xy (the random row
	 * or column where I was going to place the wall, a boolean value indicating whether the
	 * function should create a row (false) or a column (true).
	 *
	 * So that's the walls.
	 *
	 * The only other thing in this method is to place the Dog (just a capital 'D' character) at the
	 * dog's x and y coordinates in the board matrix.
	 *
	 */
	void printBoard();
	//(8 pts)
	//Instructions for this method:
	//	 this method first uses the dog's printDog method to print out info
	//	 about the dog, and then it prints out the board as follows:
	//	 *
	//	 This method prints out hte board such that it looks like a board.  It
	//	 prints a blank space for any square (for squares that do not have
	//	 food, traps, walls, the dog, and aren't the beginning or the ending.
	//   (at first, there will be no food or traps, or even walls or dog, but we
	//   will be adding food as 'F' character, traps as 'T' character, walls as
	//   '|' or '_' characters, and the dog 'D' character to the board, so you want
	//   to print a space for everything that isn't a 'T','F','|','_',or'D'.
	//
	// NOTE: I used the debug field in Board.h here.  If the debug flag was true,
	// I printed the T (aka made the traps visible) for testing purposes.  If
	// the debug flag was false, I printed a ' ' where the 'T' characters were
	// located on the board so you couldn't see them and avoid them.
	//
	// All examples except the final playgame will be with debug set to true.
	//
	//	 Otherwise it prints out the character in the square.
	//	 Note that I printed a border around the entire board so it was easier to look
	//	 at, and, equally, I placed an -> arrow (thats a minus and a greater than sign)
	//	 in the border for where the beginning of the game was and where the end of the
	//	 game was.   I thought that looked nice.


	void addFood();
	// (5 pts)
	/* Instructions for writing addFood: */
	/* this method randomly adds food around the board.  For easy, I added the field size
	 * number of foods randomly around the board.  For medium, I added size-2 foods, and for
	 * hard I added size-4 foods.  The amount of strength the dog gets when they eat (aka
	 * move onto) the food is determined in the moveDog method.
	 */
	void addTraps();
	// (5 pts)
	//Instructions for addTraps
	/* this method randomly adds traps around the board.  For easy I added size - 10 traps,
	 * for medium, I added size - 8 traps, and for hard I added size - 6 traps.  Note: Traps are
	 * only printed on the board when the game is in debug mode.  The amount of strength each trap
	 * saps from the dog is determined in the moveDog method when the dog moves on a Trap.
	 */
	void playGame();
	/* (I'm giving you this one)
	 * this method loops for every move the dog makes.  It asks whether the user wants to move up,
	 * down, left, or right.  It then calls the moveDog method with the character indicating which
	 * way the dog should move, and then it calls the printBoard method.
	 */
	bool moveDog(const char c);
	// (12 pts)
	//Instructions for moveDog
	/* This is a somewhat long method.
		 * First, it determines the new coordinates of the dog, based on the direction in which the
		 * dog wants to move (based on what c holds - u is up, d is down, l is left, r is right).
		 *
		 * If the dog is at the edge of the board, the dog should not move
		 *
		 * If the dog moves over food, a random number between 2 and 17 is generated, and the
		 * dog's changeStrength method is used to increase the dog's strength by the random amount.
		 *
		 * If the dog moves over the end of the board, the dog's won method is called and false is
		 * returned from this method.
		 *
		 * If the dog moves over a Trap, a random number between 2 and 17 is generated and the dog's
		 * changeStrength method is called with that negative number.  (Note that the changeStrength
		 * method returns a boolean indicating whether the dog's strength has gone to 0 or less, and
		 * thus the dog has died and the game is over. That boolean value is returned from this method).
		 *
		 * If the dog moves over a wall, the method checks to see if the dog has enough strength to
		 * knock down the wall (I made it cost 6 strength points to knock down a wall).  If the dog
		 * has enough strength, the user is asked, "Do you want to knock down that wall?"  If the user
		 * responds "yes", then the wall is knocked down, the dog moves into that square, adn the dog's
		 * strength decreases by 6.  If the answer is "no", the dog loses 1 strength point, just because.
		 *
		 * If the dog moves into a blank square, the dog loses 2 strength points using the changeStrength
		 * method (which, again, will return false if the dog has lost all their strength and died.
		 *
		 * NOTE: I am not concerned with the precise rules here.  If you want to change the range of
		 * random numbers for food, if you are worried about whether you still lose 2 strength points for
		 * moving even though you gained points for moving over food - I'm leaving all that to your preference.
		 * I am concerned that you are using classes, objects, and object methods and accessing object
		 * fields correctly!
		 *
		 */
};




#endif //BOARD_H
