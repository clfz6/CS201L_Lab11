// Cristian Lopez
// 7-18-2020
// Lab 11

#include <string>
#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee(int id, string myName)
{
	employeeID = id;
	name = myName;
	payRate = 10;
	balance = 0;
}

// Getter to return the employee ID
int Employee::getEmployeeID()
{
	return employeeID;
}

// Getter to return the current pay rate
double Employee::getPayRate()
{
	return payRate;
}

// Getter to return the current amount of pay earned
double Employee::getBalance()
{
	return balance;
}

// Getter to get Employee's name
string Employee::getName()
{
	return name;
}

// Function to give the raise. It takes in a percent in whole numbers 
// (ex: 5 for 5%)
void Employee::giveRaise(int rate)
{
	double inc;
	double percentage = static_cast<double>(rate) / 100;
	inc = payRate * percentage;
	payRate += inc;
}

// Pays the employee
void Employee::pay()
{
	balance += payRate;
}

// Fires the Employee
void Employee::fire()
{
	employed = false;
}

// Returns if the Employee is currently employed
bool Employee::isEmployed()
{
	return employed;
}