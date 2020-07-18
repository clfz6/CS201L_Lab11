#include "Employee.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string input, f_name, l_name;
	vector<Employee> employees;
	int id, size, rate; \

		if (fin.fail())
		{
			cout << "Input file failed to open" << endl;
		}
	if (fout.fail())
	{
		cout << "Output file failed to open" << endl;
	}

	while (fin.good())
	{
		fin >> input;
		if (input == "NEW")
		{
			fin >> id;
			fin >> f_name >> l_name;
			Employee emp(id, f_name + " " + l_name);
			employees.push_back(emp);
		}
		else if (input == "RAISE")
		{
			fin >> id;
			size = employees.size();
			for (int i = 0; i < size; i++)
			{
				if (employees[i].getEmployeeID() == id)
				{
					fin >> rate;
					employees[i].giveRaise(rate);
				}
			}
		}
		else if (input == "PAY")
		{
			size = employees.size();
			for (int i = 0; i < size; i++)
			{
				if (employees[i].isEmployed() == true)
					employees[i].pay();
			}
		}
		else if (input == "FIRE")
		{
			fin >> id;
			size = employees.size();
			for (int i = 0; i < size; i++)
			{
				if (employees[i].getEmployeeID() == id)
					employees[i].fire();
			}
		}
		else
		{
			fout << "Error" << endl;
		}
	}

	size = employees.size();
	for (int i = 0; i < size; i++)
	{
		if (employees[i].isEmployed() == true)
		{
			fout << employees[i].getName() << ", ID Number " << employees[i].getEmployeeID() << ":" << endl;
			fout << "Current pay rate: $" << employees[i].getPayRate() << endl;
			fout << "Pay earned to date: $" << employees[i].getBalance() << endl << endl;
		}
		else if (employees[i].isEmployed() == false)
		{
			fout << employees[i].getName() << ", ID Number " << employees[i].getEmployeeID() << ":" << endl;
			fout << "Not employed with the company." << endl;
			fout << "Pay earned to date: $" << employees[i].getBalance() << endl << endl;
		}
		else
		{
			fout << "Error" << endl << endl;
		}

	}

	fin.close();
	fout.close();
	return 0;
}