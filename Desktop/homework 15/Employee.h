#pragma once
#include <iostream>
#include <string>
using namespace std;


class Employee
{
public:
	Employee(int id, double hourlyPayRate, string employeeName);
	int getId() const;
	double getHourlyPayRate() const;
	string getEmployeeName() const;
	int getHoursWorked() const;
	double getTotalCompensation() const;
	void setID(int id);
	void setEmployeeName(string employeeName);
	void setHoursWorked(int hoursWorked);
	void setTotalCompensation(double totalCompensation);
	friend ostream& operator << (ostream& cout, Employee employee);

	~Employee();

private:
	int id;
	double hourlyPayRate;
	string employeeName;
	int hoursWorked;
	double totalCompensation;
};

