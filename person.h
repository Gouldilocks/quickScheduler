//
// Created by loggityloglog on 2/2/21.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include <iostream>
#include <vector>
using namespace std;
class person {
public:
	person();
	person(string name);
	string getName(){
		return this->name;
	}
	void calcAvail(double begin, double end, int day);
	bool checkAvail(int day, int halfHour);
private:
	vector<vector<bool>> avail;
	string name;
};


#endif //UNTITLED_PERSON_H
