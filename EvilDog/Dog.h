//
// Created by Deb on 9/2/2025.
//

#ifndef DOG_H
#define DOG_H
#include <iostream>
#include <cstdlib>
using std::string;


class Dog {
    friend class Board;//by making the Board a friend of this class, the
    //Dog class is allowing the board class and objects
    //to access all of the dog class' private fields
//public:
    string name; // for the dog's name
    int strength;  //for the dog's current strength
    int x;  // the x coordinate of where the dog is currently on the board
    int y;  // the y coordinate of where the dog is currently on the board
public:
    Dog(string n); // (2 pts)
 /* constructor, sets the name to be whatever name gets passed in, the
  * strength to be 50 (I just picked 50 - you want another number, go for it!) and I made
  * the original coordinates be -1 and -1 because the compiler yells at me a tiny little yell
  * if I don't initialize all my fields in the constructor
  */
    Dog();  // (2 pts)
    /* constructor, I made the default be fluffy, but you can make it anything you like!!
     * I set the strength to be 50 (again, I just picked 50), and I made the original
     * coordinates be -1 and -1 because...
     */
    bool changeStrength(int amt);  //(5 pts)changes dog’s strength field
    // by adding amt (so if the strength is going down, send in a negative
    // number.
    // It then calls printDog method to print out current information about the dog.
    // It also checks to make sure that the dog object's strength is >0.
    // If the dog object's strength is 0 or less, it calls the die method.
    // It returns true if the strength is still >0 and false otherwise.
    void die();  //(2 pts)
    /* This method just prints out a sad pathetic death of a dog message, letting everyone
     * know of the demise of the dog object.  My message has ACK!!! and judgmental statements
     * about how the user is a cruel, heartless person for letting a puppy dog die, but
     * yours can be whatever you like.
     */
    void printDog();  // (2 pts)
    /* this method just prints out the basic information about the dog - its
     *name and its current strength.
     */
    void won(); //(2 pts)
    /* again, just a message about the user's incredible prowess in successfully navigating the
     * sweet little puppy dog through the evil forest to the other side.  You can make it whatever
     * you like.
*/
    void reset();  //(2 pts)
    /* this method just resets the strength (for me it was 50) and the x and y to -1 and -1
     *
     */
};



#endif //DOG_H
