#include <iostream>
#include "Organizer.h"
using namespace std;
int main (int argc, char** argv) {
	Organizer o;
	// this program will assume that all the inputs will be correct
	if(argc > 1){
		o.organizeFile(argv[1]);
	}
	// if the user wants to enter manually
	/*
	 * STILL NOT WORKING, TO BE DONE IN THE FUTURE
	 */
	else {
		o.organizeManual();
	}
	return 0;
}
