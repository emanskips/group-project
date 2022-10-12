#pragma once
#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
	using namespace std;
	class client
	{
	public:
		void Initialize(string f, string l, double b, int i);
		//returns the corrisponding variable
		string getFullName() const;
		double getBalance() const;
		int getID() const;

	private:
		string firstName;
		string lastName;
		int ID;
		double balance;
	};

	void client::Initialize(string f, string l, double b, int i) {
		firstName = f;
		lastName = l;
		balance = b;
		ID = i;
	}
	//returns both names and a space between them
	string client::getFullName() const {
		return firstName + " " + lastName;
	}
	
	int client::getID() const {
		return ID;
	}

	double client::getBalance() const {
		return balance;
	}

#endif
	//Mehri, A. (2022). In list Class example, Payload.h. 
	//Retrieved from https://capitol.instructure.com/courses/10268/files/folder/Intro_to_Lists/list%20Class%20example 

};

