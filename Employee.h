#pragma once
#include <string>
#include <iostream>
using namespace std;

class Employee
{
public:
	Employee(int id, double hourlyPayRate, string employeeName);
	Employee();
	int getId() const;
	double getHourlyPayRate() const;
	string getEmployeeName() const;
	int getHoursWorked() const;
	double getTotalCompensation() const;
	void setID(int id);
	void setEmployeeName(string employeeName);
	void setHoursWorked(int hoursWorked);
	void setTotalCompensation(double totalCompensation);
	void addHoursWorked(int hours);
	void calculateTotalCompensation();
	friend ostream& operator << (ostream& cout, const Employee&);
	friend bool operator==(Employee& employee1, Employee& employee2);

	~Employee();

private:
	int id;
	double hourlyPayRate;
	string employeeName;
	int hoursWorked;
	double totalCompensation;
};
