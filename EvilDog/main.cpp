#include "Board.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;


int main() {
	srand(time(NULL));
	Board board('m', "fido", true);
	return 0;
}