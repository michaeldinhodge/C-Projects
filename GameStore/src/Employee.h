/*
 * Employee.h
 *
 *  Created on: Jun 5, 2017
 *      Author: aishwaryapai
 */

#include <iostream>
#include <string>
using namespace std;

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

class Employee {
private:
	string firstName;
	string lastName;
	unsigned IDnum;
	string password;

public:
	//Constructors
	Employee();
	Employee(string firstName, string lastName, unsigned IDnum, string password);

	//Destructor
	~Employee();

	//Accessors
	string getFirstName();
	string getLastName();
	unsigned getID();
	string getPass();

	//Mutators
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setID(unsigned number);
	void setPass(string password);

	//Additional Functions
	void printEmployeeinfo();
	//prints Employee information in the following format:
	//Employee: <first name> <last name>
	//ID: <id>
	//<blank line>
};

#endif /* EMPLOYEE_H_ */
