//
// •	(2 pts) Dog(string n); //constructor
// •	(2 pts) Dog();  //constructor
// •	(5pts) bool changeStrength(int amt);  //changes dog’s strength field
// •	(2 pts) void die();  //die message when strength at or below 0
// •	(2 pts) void printDog();  // prints out info about dog
// •	(2 pts) void won(); //won message for when dog is at end of evil forest
// •	(2 pts) void reset();  //resets dog for restarting a new game
// 17 pts total


#include "Dog.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
using std::cout;
using std::endl;
using std::string;

Dog::Dog(string n) {
    /* (2 pts) constructor, sets the name to be whatever name gets passed in, the
     * strength to be 50 (I just picked 50 - you want another number, go for it!) and I made
     * the original coordinates be -1 and -1 because the compiler yells at me a tiny little yell
     * if I don't initialize all my fields in the constructor
     */
/** code here **/
    name = n;
    strength = 50;
    x = 0;
    y = 0;
}
Dog::Dog(){
    /* (2 pts) constructor, I made the default be fluffy, but you can make it anything you like!!
     * I set the strength to be 50 (again, I just picked 50), and I made the original
     * coordinates be -1 and -1 because...
     */
    /** code here **/
    name = "Fluffy";
    strength = 50;
    x = 0;
    y = 0;
    }
bool Dog::changeStrength(int amt) {
    /* (5 pts) changeStrength modifies the strength property by whatever amt is (basically adding here)
     * It then calls printDog method to print out current information about the dog.
     * It also checks to make sure that the dog object's strength is >0.
     * If the dog object's strength is 0 or less, it calls the die method.
     * It returns true if the strength is still >0 and false otherwise.
     */
    /** code here **/
    strength += amt;
    printDog();
    if (strength <= 0) {
        die();
        return false;
    }

    return true;

}

void Dog::die() {
    //(2 pts)
    /* This method just prints out a sad pathetic death of a dog message, letting everyone
     * know of the demise of the dog object.  My message has ACK!!! and judgmental statements
     * about how the user is a cruel, heartless person for letting a puppy dog die, but
     * yours can be whatever you like.
     */
    /** code here **/
    cout << "You have let your best friend die. There are only negative consequences in your future." << endl;
}

void Dog::printDog() {
    // (2 pts)
    /* this method just prints out the basic information about the dog - its
     *name and its current strength.
     */
    /** code here **/
    cout << name << ", strength = " << strength << " " <<endl << x << ", " << y << endl;
}

void Dog::won() {
    //(2 pts)
    /* again, just a message about the user's incredible prowess in successfully navigating the
     * sweet little puppy dog through the evil forest to the other side.  You can make it whatever
     * you like.
*/
 /** code here **/
    cout << "Your best friend " << name << " has made it through alive! Congratulations!" << endl;
}

void Dog::reset() {
    //(2 pts)
    /* this method just resets the strength (for me it was 50) and the x and y to -1 and -1
     *
     */
    /** code here **/
    strength = 50;
    x = 0;
    y = 0;
}
