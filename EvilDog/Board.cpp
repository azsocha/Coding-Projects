//
// You may approach writing code any way you want.
// However, I've included my approach.  If you want to follow my approach,
// I'd start with this file and write the Dog.cpp later.  That means you'll
// need to comment in code related to the Dog class later.

// The instructions start in the InitAll method. Go there.
//
// Point values are as follows:
// •	The printBoard  (7 pts) method
// •	The boardConfig  (8 pts) method
// •	The makeOneWall(7 pts) method
// •	The addFood (5 pts) method
// •	The addTraps (4 pts) method
// •	The moveDog (12 pts) method
// (43 pts for each method, 10 pts for everything running together!)

#include "Board.h"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::cin;

Board::Board(const char diff, const bool d){
	level = diff;
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(const bool d){
	level = 'e';
	debug = d;
	wallStrength = 6;
	InitAll();
}
Board::Board(const char diff, const string name, const bool d) {
	level = diff;
	debug = d;
	mydog.name = name;
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//COMMENT the above line BACK IN AFTER YOU WRITE YOUR DOG CLASS
	//mydog.reset();
	wallStrength = 6;
	InitAll();
}
void Board::InitAll() {
	bool keepPlaying = true;
	/*********************************************************************/
	//FOR TESTING!!!
	// Here's where there's code for getting your initial methods working
	// Once you've got this part working, you can comment it out and then
	// just play the game.
	//******************************************************************
	// STEP 1
	// Write and test printBoard following the instructions inside of
	// the printBoard Method below.  Then test it to make sure it's working
	// properly.  When you've written printBoard, uncomment the printBoard()
	// line below.
	//
	//printBoard();
	//
	// Your output should be this:
	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
	//		| 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 |
	//		| 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 |
	//		| 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 |
	//		| 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 |
	//		| 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 |
	//		| 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 |
	//		| 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 |
	//		| 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 |
	//		| 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 |
	//		| 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 |
	//		 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
	//
	//
	//*******************************************************************/
	// STEP 2:
	// When you have the printBoard method working, write the boardConfig method
	// (Instructions by boardConfig) and comment out the code below:
	//
	//startx = 1;
	//starty = 0;
	//endx = 1;
	//endy = size-1;
	//level = 'e';
	 //boardConfig();
	 //printBoard();
	// Your results should look something like the following (walls are random, so
	// yours will be unique:
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// |   |                                   | |
// ->D                     |               ->E
// |           |           |               | |
// |   |     _ | _ _   _ _ |   _   | _ _ _   |
// |                               |         |
// | _ |       _ _ _         _ _ _ _     _ | |
// |                       |               | |
// |   _   _ _ | _ _   _   _       _   _   | |
// |   |                   |       |       | |
// |   |       |           |       |       | |
// |                                         |
// |                                         |
// |                               |         |
// | _     _ _ |     _       _     |   _ _   |
// |                       |                 |
// |   |   _ _ |   _   _ _   _ _   |       _ |
// |   |       |                   |         |
// |           |           |               | |
// |   |       |           |                 |
// |   |                           |         |
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _


	//  Testing boardConfig different difficulty levels
	// level = 'm';
	// boardConfig();
	// printBoard();
	// What my board with medium difficulty walls looked like

	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 //  |           |       |                     |
 //  ->D _     _ | _   _ _ _ _     _     _ _ ->E
 //  |           |       |   |           |     |
 //  | _ _ _ _         _ | _ _   _     _ _ _ _ |
 //  |   |               |   |           |     |
 //  | _ | _   _   _ _ _ _ _ _ _   _     _     |
 //  |                                   |     |
 //  |   |       |       |                     |
 //  |   |       |       |                     |
 //  | _ |     _ |   _ _ |   _ _ _   _ _       |
 //  |   |       |       |               |     |
 //  | _ |   _   | _ _   | _ _   _   _   _ _ _ |
 //  |   |                   |           |     |
 //  | _ _ _ _ _ | _   _   _ |   _ _   _ |   _ |
 //  |   |       |       |   |           |     |
 //  | _ |   _ _ _ _       _ | _   _     _ _ _ |
 //  |           |       |   |           |     |
 //  |           |           |           |     |
 //  |   |               |   |           |     |
 //  |   |                               |     |
	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _

 //
 //

	//  Testing boardConfig different difficulty levels
	 //level = 'h';
	 //boardConfig();
	 //printBoard();
	// what my board with hard level walls looked like
	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 //  |       |   |       |   |       |   |     |
 //  ->D   _ | _ _ _ _   | _ _ _ _ _ | _   _ ->E
 //  |       |   |       |   |           |     |
 //  | _ _ _ _ _ _ _   _ _ _ _   _ _ _     _   |
 //  |           |       |   |       |   |     |
 //  |       |   |           |       |   |     |
 //  |       |   |           |       |   |     |
 //  | _ _ _ _ _ _     _ _ _ _ _ _   |   | _ _ |
 //  |       |   |       |   |           |     |
 //  | _ _ _ _ _     _ _ | _ _ _ _ _   _ _ _   |
 //  |       |   |       |           |   |     |
 //  |   _   _ _ _ _ _   _ _ _ _ _ _ _ _ | _   |
 //  |                   |   |       |         |
 //  |       |   |       |   |       |   |     |
 //  |       |           |   |       |   |     |
 //  |   _ _ | _ _ _ _ _ | _ _ _ _   | _ _ _ _ |
 //  |           |           |       |   |     |
 //  | _ _   | _ _ _ _ _ | _ _ _   _   _ | _ _ |
 //  |       |   |                       |     |
 //  | _ _ _ |   _   _   _ _ |   _ _ | _ _ _ _ |
	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _


	/*************************************************************************/
	// STEP 3:
	// Next, write the addFood method to add food and print the board.  I tested
	// with all three levels:
	 //level = 'e';
	 //boardConfig();
	// addFood();
	// printBoard();
	// cout << "***************************************" << endl;
	// To test medium, comment out below (boardConfig should re-initialize
	// level = 'm';
	// boardConfig();
	// addFood();
	// printBoard();
	// cout << "***************************************" << endl;
	//Mine:
	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 //  |                               |         |
 //  ->D           F               F |         |
 //  |               |       |                 |
 //  | F |   | F   F |       | F     |         |
 //  |   |           |       |     F           |
 //  | _ _ _ _ _ _   _ _ _   | _ _   F _   F   |
 //  |   |           F   F   |       |         |
 //  |   |   |       |               |         |
 //  |   |   |       |               F         |
 //  |   |   |       |       F       |         |
 //  |   F   |               |       |     F   |
 //  |   _ _ _   _ _ _     _   _       _ _ _ _ |
 //  |   |   |       |               |       F |
 //  | _ | _ | _     _ _ _ _ _ _   _     _ _   |
 //  |   |   |       |       |       |         |
 //  |     _ _ _   F _       _ _ _ _ _ _   _ _ |
 //  |   |           |       |                 |
 //  |     _ _   _ _ | _   _ | _ _ _     _ _ _ |
 //  |   |   |       |       |       |       F |
 //  |   |   |       |       |       |         |
	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _



// To test the addFood method with the hard level, comment out the code below:

	//  level = 'h';
	//  boardConfig();
	//  addFood();
	//  printBoard();
	// cout << "***************************************" << endl;
	// OUTPUT (I've shown you mine with all three levels below.  Yours
	// will be different because... randomness is a thing.

// 	EASY LEVEL OUTPUT:
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// | F         |   |           |   |         |
// ->D     |   |   |           |           ->E
// |   |       | F |           |   |         |
// |       _   _       _   _ F | _ _ _   _ _ |
// |   |       |   F                         |
// | _ _ _ _ _ _ _ |         _ _   F         |
// |           F                   |         |
// |   |   |       |               F         |
// |     F |   |               |             |
// |   |   |   F       F   F       |       F |
// |                   F           |         |
// |   |           |                         |
// |   |   |   |   |           |   |         |
// | _ _ _ _   _     _   _ F       _   F   _ |
// |                     F     |             |
// |   |                       |   |         |
// |                     F       F |         |
// |               |       F                 |
// |   |   |   |                       F     |
// |   _   | _ | _ _   _   _   _ _ | _       |
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//
// ***************************************
	// MEDIUM LEVEL OUTPUT
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// |               |   |           |   |     |
// ->D |           |   |       |   |       ->E
// |           F   |   |       | F         | |
// | _ |     _ F   _ _ _ _ _ _ | F _ F _   _ |
// |   |           |   |       |   F   |     |
// | _ _ _ _     _ | _     _   _ _ | _ _   _ |
// |   |               |   F   |       |   | |
// |   |                     F     |       | |
// |   |                       |   |   |   | |
// | _ _ F _ _ _   _ _ | F     _ _ _   _ _   |
// |         F         |       |   |         |
// | _ _ _     F _ F   _   _ _ |   _ _ _ _ | |
// |                   |           |       | |
// |   |           |   |           |   | F F |
// |               |           |   |   |     |
// |   _ _ _ _   _ _ _ |       _ _ _ _ |   | |
// | F |           |                   |   | |
// |               |   |       |   |   |     |
// |   |       F   |                       | |
// |   | F                     |       |   | |
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//
// ***************************************
	// HARD LEVEL OUTPU
	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 //  | F |   |   |   |   |   F               | |
 //  ->D |   |   |   |   |   |   |       |   ->E
 //  |   |   |           |   |   |           | |
 //  | _ |   _ _ _ _ | _ _ _ _ _ _       | _ | |
 //  |   |   |   |       |   |         F |   | |
 //  |   |   |   F   |   |       |       F     |
 //  |               |   |   |   |       | F   |
 //  | _   _ | _ _ _ _   _ _ | _ _ _   _ _ _ _ |
 //  |       |   |   |   |   |   |       |   | |
 //  | _ | _   _ | _ | _ _ _ | _ _   _ _ | _ | |
 //  |   |   |       |       |   |       |   F |
 //  |   |   | F | F |           |       |   | |
 //  |   |   |   | F |   |   |   |       |   | |
 //  | _ _ _ _ _ _ _ _ _ |   _ _ | _   _ | _ | |
 //  |       |   | F         |   |       |   | |
 //  |   |   |   |   |   |   |   |         F | |
 //  |   |       |   |       |   |   F   |   | |
 //  |     F |   |       |   |           |     |
 //  | F |   |   |   |           |   F   |   | |
 //  | _ | _ _     _ | _ | _ | _ |   _ _ | _ _ |
	// _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
 //
 //  ***************************************

	/*************************************************************************/
	// STEP 4:
	// Next, write the addTraps method to add traps and print the board.  I tested
	// with all three levels and showed my output below:

	//   level = 'e';
	//   boardConfig();
	//   addFood();
	//   addTraps();
	//   printBoard();
	//   cout << "***************************************" << endl;
	//
  	//boardConfig();
  	//level = 'm';
  	//addFood();
  	//addTraps();
  	//printBoard();cout << "***************************************" << endl;

	//
	//level = 'h';
	//boardConfig();
	//addFood();
	//addTraps();
	//printBoard();
	// cout << "***************************************" << endl;
// My output looked like this:
//
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// |             F                 | F       |
// ->D | _       _         _ _ _ _       _ ->E
// |   |     F         F F |   F           T |
// |   | _     T _   _ F   _ _ _ _ |     _ | |
// |                   F           |       | |
// |   | _   _ _         _ | _   _   _ F _ _ |
// |   |                             F       |
// | _ _ _   _ _   _     _             _ _ | |
// |   |                   |       |   T     |
// |   |   F               |               | |
// |             T         |       |       | |
// |     T     F                 T     F     |
// |       F               |       |         |
// | _ _ _ _   T _ F   _   _   _     _     | |
// |                               |       | |
// |   |     F             |   F             |
// | F T                           |         |
// |             F                     T     |
// |                       |       |   F T | |
// |     _   _     _   _ _ | _     _     _ _ |
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//
// ***************************************
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// |   |           |               |   |     |
// ->D _     _ |     _ _ _ | _ F _ |   |   ->E
// |   |           F             F     |     |
// |   |           |         F     |         |
// |       |   |     T     |       |   |     |
// |     T |           |   |       |   |     |
// |       |           |               |     |
// |   F   |   |   | F F           |         |
// |       |   F   |   |       T             |
// |   | F |   |   |   |   |   T   |         |
// |   |       |   T       |           |     |
// |   _   | _ _   _   _ _ _   T   F   | _ _ |
// |   |           |   |     F               |
// |   |     F |           |     F           |
// |       |   |       |                     |
// |       |     F     |                   T |
// |     T         |   | F                 F |
// | F |                       F   |         |
// | T         |   |   | T |       |         |
// |   T           |       |     T     |     |
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//
// ***************************************
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
// |   |   | F |               | T |       | |
// ->D |   | _ | _ _ _ | _ _ _ |     _ _ _ ->E
// |                   | T F       |       | |
// | _ |   | _ | _ _ _ _ _ _ _ | _ | _ _ _ | |
// |       |   |   T F         |   |   T     |
// |       |   |       |       |   |       | |
// |       | F |   F   | F     |     T       |
// |   | _ _ _ | _ _ _ | _ _ _ | _ _       _ |
// | T |   |           |       | F |   F   | |
// |   | _ | _ |     _ | _ _ _ _ T _ _ _ _ _ |
// |   |   |           | F T   |   |   T     |
// | _ _     _ | _ _ _ | _ _ _ _ _ _ _ F _ _ |
// |   |       | F     |       |   F     T | |
// |       |   |       |       |   |       | |
// | T |   |   |                   |       | |
// |   |     T         |   F       |       | |
// |   |   | F |       |       |   | T     | |
// | _ | _ | _ | _ _ _ | F _   _   _ _   _ _ |
// |   |   |       F       T   |           | |
// | _ | _ | _ |   _   | _ _ _ |   _ _ _ _ | |
//   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
//
// ***************************************

// ****************************************************************************
//  Part 2:
//  Dog.hpp and Dog.cpp
// *****************************************************************************
//	Now you'll have to write the Dog.cpp methods before you can write'
//	and test the moveDog method.
//
//  The instructions for the dog methods are in the Dog.h file
//
//
//	Once you are done writing the Dog class, you'll need to do the '
//	uncomment out (comment in?) the following
//	 * 1) in the Board.h class, you'll have to comment in the Dog myDog line Board.hpp
//	 * (it's around line 46)
//	 * 2) In the 3rd Board Constructor, you'll need to comment in the mydog.name line
//	 *  (it's around line 33 in this file)
//	 * 3) And you'll have to add to your printBoard() method a line for printing out
//	 *    the dog object's name and the dog object's strength.
//
// And now write moveDog() as described inside the  moveDog method, below.
// Once done, uncomment out the following 4 lines and test with the following code:
	//moveDog('d');
	//moveDog('u');
	//moveDog('r');
	//moveDog('l');
	// your dog should move down, up, right, and then left.  If you hit a food
	// or a trap, you should get a message as described in the moveDog method, below.
	//

	/*********************************************************************/
	//End of Testing.  Now comment out the above testing stuff, and
	// comment in the rest of the init method, below
	/*********************************************************************/


	/**********************************************************************/
	/* PART THREE
	 * COMMENT OUT THE ABOVE TESTING CODE AND COMMENT IN THE BELOW CODE TO RUN
	 * THE GAME.
  	 * Note that I've included a video of the playing game in week 2 module.
	 */
	//
	 while (keepPlaying) {
	 	cout << "What level of difficulty do you want (e, m, or h)?" << endl;
	 	char c;
	 	cin >> c;
	 	cout << "Debug mode on? (y or n)?" << endl;
	 	cin >> c;
	 	if (c == 'y') debug = true;
	 	else debug = false;
	 	startx = rand() % size;
	 	starty = 0;
	 	endx = rand() % size;
	 	endy = size-1;

	 	mydog.x = startx;
	 	mydog.y = starty;
	 	// cout << "I'm here happily" << endl;
	 	// mydog.printDog();
	 	boardConfig();
	 	// cout << "I'm here still happy" << endl;
	 	// mydog.printDog();
	 	addFood();
	 	// cout << "I'm here still doing good" << endl;
	 	// mydog.printDog();
	 	addTraps();
	 	// cout << "I'm here still not sad" << endl;
	 	// mydog.printDog();
	 	printBoard();
	 	// cout << "I'm here still functioning" << endl;
	 	// mydog.printDog();
	 	playGame();

	 	cout << "Play again? " << endl;
	 	string s = "no";
	 	cin>>s;
	 	if (s == "yes" || s == "Yes" || s == "Y" || s == "y") {
	 		keepPlaying = true;
	 		mydog.reset();
	 	}
	 	else {
	 		cout <<"Thanks for playing!" << endl;
	 		keepPlaying = false;
	 	}
	 }

}


/***********************************************************************/
/* HERE'S WHERE THE CODE GOES!                                         */
/***********************************************************************/

void Board::printBoard() {
	//(7 pts)
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

/** code goes here **/
	mydog.printDog();

	cout << ' ';
	for (int i = 0; i < size + 1; i++) {
		cout << "_ ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "| ";
		for (int j = 0; j < size; j++) {
			cout << board[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << " ";
	for (int i = 0; i < size + 1; i++) {
		cout << "_ ";
	}
	cout << endl;
}

void Board::boardConfig() {
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

	/*** code goes here **/

	// part 1 - replace dummy value
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = ' ';
		}
	}


	//dog
	//mydog.x = startx;
	//e
	//mydog.y = starty;
	// cout << "Now at " << endl;
	// mydog.printDog();
	board[mydog.x][mydog.y] = 'D';
	//end
	//board[size - 1][size - 1] = 'E';
	board[endx][endy] = 'E';




	// level dependence
	int numwalls = 0;
	if (level == 'e') {
		numwalls = 10;
	}
	else if (level == 'm') {
		numwalls = 12;
	}
	else if (level == 'h') {
		numwalls = 14;
	}

	for (int i = 0; i < numwalls; i++) {
		int random = rand() % size;
		//row
		if (random % 2 == 0) {
			makeOneWall(random,false);
		}
		//column
		else {
			makeOneWall(random,true);
		}
	}

}


/*******************************************************************************/
/* void makeOneWall(const int xy, const bool col) (7 pts)
 * xy is the random row or column where the wall will go, and col is a boolean value
 * indicating whether the wall will be a row (col is false) or a column (col is true
 *
 * I first determined how many "bricks" in the wall (yes, I'm that old) aka how many
 * squares make up the wall in one row or column.
 * I set the easy version to have at most 9 bricks (aka squares) per wall, the
 * medium to have at most 12 bricks per wall, and the hard version to
 * have at most 15 bricks per.(but you can play with this because sometimes
 * the hard version was seriously hard!!!
 *
 * I randomly chose k random squares squares in in the row or column to be a wall..
 * NOTE that if the square already had a wall in it, I overwrote it.
 */

void Board::makeOneWall(const int xy, const bool col) {
/*** code goes here ***/
	// level dependence
	int numwalls = 0;
	if (level == 'e') {
		numwalls = 9;
	}
	else if (level == 'm') {
		numwalls = 12;
	}
	else if (level == 'h') {
		numwalls = 15;
	}

	int randomW = (rand() % (numwalls/2)) *2;
	int randomH = rand() % (size-1);
	if (col) {
		for (int i = 0; i < randomW; i++) {
			if (board[randomH][xy] != 'E') {
				board[randomH][xy] = '|';
				randomH += 1;
				if (randomH > size - 1) {
					randomH = 0;
				}
			}
		}
	}
	else {
		for (int i = 0; i < randomW; i++) {
			if (board[xy][randomH] != 'E') {
				board[xy][randomH] = '_';
				randomH += 1;
			}
		}
	}

}

void Board::addFood() {
	// (5 pts)
	/* Instructions for writing addFood: */
	/* this method randomly adds food around the board.  For easy, I added the field size
	 * number of foods randomly around the board.  For medium, I added size-2 foods, and for
	 * hard I added size-4 foods.  The amount of strength the dog gets when they eat (aka
	 * move onto) the food is determined in the moveDog method.
	 */
	/***** code goes here ****/

	// level dependence
	int numFood = 0;
	if (level == 'e') {
		numFood = size;
	}
	else if (level == 'm') {
		numFood = size - 2;
	}
	else if (level == 'h') {
		numFood = size - 4;
	}


	for (int i = 0; i < numFood; i++) {
		int randomx = rand() % size;
		int randomy = rand() % size;
		if (board[randomx][randomy] == ' ') {
			board[randomx][randomy] = 'F';
		}
		else {
			i = i - 1;
		}
	}
}

void Board::addTraps() {
	// (4 pts)
	//Instructions for addTraps
	/* this method randomly adds traps around the board.  For easy I added size - 10 traps,
	 * for medium, I added size - 8 traps, and for hard I added size - 6 traps.  Note: Traps are
	 * only printed on the board when the game is in debug mode.  The amount of strength each trap
	 * saps from the dog is determined in the moveDog method when the dog moves on a Trap.
	 */
	/****** code goes here ****/

	// level dependence
	int numTraps = 0;
	if (level == 'e') {
		numTraps = size - 10;
	}
	else if (level == 'm') {
		numTraps = size - 8;
	}
	else if (level == 'h') {
		numTraps = size - 6;
	}

	for (int i = 0; i < numTraps; i++) {
		int randomx = rand() % size;
		int randomy = rand() % size;
		if (debug) {
			board[randomx][randomy] = 'T';
		}
		else {
			board[randomx][randomy] = ' ';
		}
	}
}


bool Board::moveDog(const char c) {
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
	/***** code goes here ****/
	int realx = mydog.x;
	int realy = mydog.y;
	char symbol;
	//move
	if ( c == 'u' && mydog.x != 0 ){
		board[mydog.x][mydog.y] = ' ';
		mydog.x -= 1;
		symbol = board[mydog.x][mydog.y];
		board[mydog.x][mydog.y] = 'D';
	}
	else if ( c == 'd' && mydog.x != size-1 ) {
		board[mydog.x][mydog.y] = ' ';
		mydog.x += 1;
		symbol = board[mydog.x][mydog.y];
		board[mydog.x][mydog.y] = 'D';
	}
	else if( c == 'l' && mydog.y != 0 ) {
		board[mydog.x][mydog.y] = ' ';
		mydog.y -= 1;
		symbol = board[mydog.x][mydog.y];
		board[mydog.x][mydog.y] = 'D';
	}
	else if (c == 'r' && mydog.y != size-1) {
		board[mydog.x][mydog.y] = ' ';
		mydog.y += 1;
		symbol = board[mydog.x][mydog.y];
		board[mydog.x][mydog.y] = 'D';
	}

	//end
	if (symbol == 'E') {
		mydog.won();
		return false;
	}

	//food
	if (symbol == 'F') {
		int randomF = rand() % 17 + 2;
		//board[mydog.x][mydog.y] = ' ';
		cout << mydog.name << " reached food and its strength increased by " << randomF << endl;
		return mydog.changeStrength(randomF);
	}

	//trap
	bool a = debug;
	debug = true;
	if (symbol == 'T') {
		int randomT = rand() % 17 + 2;
		randomT = 0 - randomT;
		//board[mydog.x][mydog.y] = ' ';
		cout << mydog.name << " hit a trap! It's strength decreased by " << randomT << endl;
		return mydog.changeStrength(randomT);
	}
	debug = a;

	//wall
	if (symbol == '|' || symbol == '_') {
		if (mydog.strength >= wallStrength) {
			cout << "Do you want to knock down that wall? (y or n)?" << endl;
			char a;
			cin >> a;
			if (a == 'y') {
				int s = 0 - wallStrength;
				return mydog.changeStrength(s);
			}
			else {
				int no = -1;
				board[mydog.x][mydog.y] = symbol;
				mydog.x = realx;
				mydog.y = realy;
				board[mydog.x][mydog.y] = 'D';
				return mydog.changeStrength(no);
			}
		}
		else {
			int no = -1;
			cout << "You do not have enough strength to knock down that wall." << endl;
			mydog.x = realx;
			mydog.y = realy;
			return mydog.changeStrength(no);
		}
	}

	//empty space
	if (symbol == ' ') {
		int z = -2;
		return mydog.changeStrength(z);
	}

	return mydog.changeStrength(0);
}


void Board::playGame() {
	bool play = true;
	while (play) {
		cout << "Move (u, d, l, r) "<<endl;
		char c;
		cin >> c;
		play = moveDog(c);
		printBoard();
	}


}