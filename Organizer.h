//
// Created by loggityloglog on 2/1/21.
//

#ifndef UNTITLED_ORGANIZER_H
#define UNTITLED_ORGANIZER_H
using namespace std;
#include <vector>
#include "person.h"
class Organizer {
public:
Organizer();
Organizer(int peeps);
~Organizer() = default;
/*
 * Functions
 */
void organizeManual();
void organizeFile(const char* fileName);
void setCalendar();
void displayCalendar();
double toMilitary(string timer);
private:
	int numPeople;
	vector<vector<bool>> calendar;
	vector<person> people;
};


#endif //UNTITLED_ORGANIZER_H
