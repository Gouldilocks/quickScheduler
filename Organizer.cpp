//
// Created by loggityloglog on 2/1/21.
//
#include <iostream>
#include "Organizer.h"
#include <fstream>
#include <sstream>
#define debugorg false
using namespace std;
void Organizer::organizeFile (const char *fileName) {
	if(debugorg)cout << "organizing file" << endl;
ifstream input;
input.open(fileName);
string current;
int counter = 0;
// this will pull a whole line
while(getline(input,current)){
	if(debugorg)cout << "full line: " << current << endl;
	if(debugorg)cout << "counter: " << counter << endl;
	// get the first line with the person's name, and make a person obj.
	if(counter == 0){
	people.push_back(person(current));
	counter++;
	continue;
	}
	// if it is an availability day thing
	else{
		double start, end;
		stringstream ss(current);
		while(getline(ss,current,'|')) {
			if(debugorg)cout << "one full entry: " << current << endl;
			stringstream strstr(current);
			int count = 0;
			while(getline(strstr,current,'-')) {
				if(debugorg)cout << "individual entry: "<< current << endl;
				if (count == 0){
					start = toMilitary(current);
					count++;
				}
				else {
					end = toMilitary(current);
					count = 0;
				}
			}
			people.at (people.size () - 1).calcAvail (start,end, counter - 1);
		}
	}
	if (counter == 7){
		counter = 0;
		continue;
	}
	counter++;
}
setCalendar();
displayCalendar();
}

Organizer::Organizer () {
	// fill the whole calendar with true values, because all slots are open
for(int i = 0; i < 7; i++){
	calendar.push_back(vector<bool>());
	// there are 48 half hours in a day
	for(int x = 0; x < 48; x++){
		calendar.at(i).push_back(false);
	}
}
}

Organizer::Organizer (int peeps) {
numPeople = peeps;
}

void Organizer::setCalendar () {
	for(int x = 0; x < calendar.size(); x++){
		for(int p = 0; p < calendar.at(x).size(); p++){
			int available = 0;
			for(person& i : people){
				if(x == 0 && p > 19 && p < 41) {
					if(debugorg)cout << "for person: " << i.getName () << endl;
					if(debugorg)cout << "for x = " << x << " and p = " << p << endl;
					if(debugorg)cout << "checkavail = " <<
					i.checkAvail(x,p) << endl;
				}
				if(i.checkAvail(x,p))
					available++;
			}
			if(available == people.size()) {
				calendar.at (x).at (p) = true;
			}
	}
}
}

void Organizer::organizeManual () {

	cout << "How many people will be scheduled?" << endl;
	int peeeep;
	cin >> peeeep;
	for (int i = 0; i < peeeep; i++) {
		string day;
		for (int x = 0; x < 7; x++) {
			switch (x) {
				case 0: {
					day = "Sunday";
					break;
				}
				case 1: {
					day = "Monday";
					break;
				}
				case 2: {
					day = "Tuesday";
				}
				case 3: {
					day = "Wednesday";
					break;
				}
				case 4: {
					day = "Thursday";
					break;
				}
				case 5: {
					day = "Friday";
					break;
				}
				case 6: {
					day = "Saturday";
					break;
				}
				default: {
					cout << "error in switch" << endl;
				}
			}
		}
	}
}

void Organizer::displayCalendar () {
ofstream outPutFile("Results");
	outPutFile << "Common times: " << endl;
for (int d = 0; d < 7; d++) {
	outPutFile << endl;
	switch (d) {
		case 0: {
			outPutFile << "Sunday: ";
			break;
		}
		case 1: {
			 outPutFile <<  "Monday: ";
			break;
		}
		case 2: {
			outPutFile << "Tuesday: ";
			break;
		}
		case 3: {
			outPutFile << "Wednesday: ";
			break;
		}
		case 4: {
			outPutFile << "Thursday: ";
			break;
		}
		case 5: {
			outPutFile <<  "Friday: ";
			break;
		}
		case 6: {
			outPutFile << "Saturday: ";
			break;
		}
		default: {
			cout << "error in switch: " << endl;
			break;
		}
	}
	for (int i = 0; i < calendar.at (d).size (); i++) {
		if (calendar.at (d).at (i)) {
			if(debugorg) cout << "i is: " << i << endl;
			double outdub;
			if (i % 2 == 0) {
				outdub = (double) (i / 2);
				if(debugorg)cout << "outdub first: " << outdub << "am" << endl;
			}
			else {
				outdub = ((double) (i / 2)) + 0.5;
				if(debugorg)cout << "other outdub first: " << outdub << endl;
			}
			if(outdub < 12)
			outPutFile << (double)outdub << "am";
			else
				outPutFile << ((outdub == 12)? 12 : (double)outdub-12) << "pm";
			while (calendar.at (d).at (i))
				i++;
			if(debugorg)cout << "i ends at: " << i << endl;
			if (i % 2 == 0)
				outdub = (double)(i / 2);
			else
				outdub = ((double)(i / 2)) + 0.5;
			if(outdub < 12)
			outPutFile << "-" << (double)outdub << "am ";
			else
				outPutFile << "-" << ((outdub == 12)? 12 : (double)outdub-12) << "pm ";
		} else {
			continue;
		}
	}
}
}

// takes a number with am/pm to a military time
double Organizer::toMilitary (string timer) {
	if(debugorg)cout << "input: " << timer << endl;
	double todub;
	// if it is am
	if(debugorg)cout << "the third: " << timer[timer.size()-2] << endl;
	if(timer[timer.size()-2] == 'a'){
		todub = stod(timer.substr(0,timer.size()-2));
	}
	// if it is pm
	else{
		todub = stod(timer.substr(0,timer.size()-2)) + 12;
	}
	if(debugorg)cout << "output: " << todub << endl;
	return todub;
}
