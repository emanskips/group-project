#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
using namespace std;

	class client
	{
	private:
		string firstName;
		string lastName;
		int ID;
		double balance;
        
	public:

	void Initialize(string f, string l, double b, int i) {
		firstName = f;
		lastName = l;
		balance = b;
		ID = i;
	}
	//returns both names and a space between them
	string getFullName() const {
		return firstName + " " + lastName;
	}
	
	int getID() const {
		return ID;
	}

	double getBalance() const {
		return balance;
	}

    void setBalance(double b) {
        balance = b;
    }
};
#endif
	//Mehri, A. (2022). In list Class example, Payload.h. 
	//Retrieved from https://capitol.instructure.com/courses/10268/files/folder/Intro_to_Lists/list%20Class%20example
