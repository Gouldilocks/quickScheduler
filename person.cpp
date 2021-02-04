//
// Created by loggityloglog on 2/2/21.
//

#include "person.h"
#define debugpers false

person::person () {
for(int i = 0; i < 7; ++i){
	avail.push_back(vector<bool>());
	for(int x = 0; x < 48; x++){
		avail.at(i).push_back(false);
	}
}
name = "";
}

void person::calcAvail (double begin, double end, int day) {
	if(debugpers)cout << "for person: " << name << endl;
	if(debugpers)cout << "double first is: " << begin << endl;
	if(debugpers)cout << "double end is: " << end << endl;
int first =(int) (2*begin);
int last = (int) (2*end);
	if(debugpers)cout << "first is: " << first << endl;
	if(debugpers)cout << "last is: " << last << endl;
for(int i = first; i < last; ++i){
	avail.at(day).at(i) = true;
}
}

person::person (string name) {
	for(int i = 0; i < 7; ++i){
		avail.push_back(vector<bool>());
		for(int x = 0; x < 48; x++){
			avail.at(i).push_back(false);
		}
	}
this->name = name;
}

bool person::checkAvail (int day, int halfHour) {
	return avail.at(day).at(halfHour);
}
