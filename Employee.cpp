#include "Employee.h"


Employee::Employee(int id, double hourlyPayRate, string employeeName) :id(id), hourlyPayRate(hourlyPayRate), employeeName(employeeName)
{
	hoursWorked = 0;
	totalCompensation = 0.00;
}

Employee::Employee()
{
	id = 0;
	hourlyPayRate = 0;
	employeeName = "";
	hoursWorked = 0;
	totalCompensation = 0;
}

int Employee::getId() const
{
	return this->id;
}

double Employee::getHourlyPayRate() const
{
	return this->hourlyPayRate;
}

string Employee::getEmployeeName() const
{
	return this->employeeName;
}

int Employee::getHoursWorked() const
{
	return this->hoursWorked;
}

double Employee::getTotalCompensation() const
{
	return this->totalCompensation;
}

void Employee::setID(int id)
{
	this->id = id;
}

void Employee::setEmployeeName(string employeeName)
{
	this->employeeName = employeeName;
}

void Employee::setHoursWorked(int hoursWorked)
{
	this->hoursWorked = hoursWorked;
}

void Employee::setTotalCompensation(double totalCompensation)
{
	this->totalCompensation = totalCompensation;
}

void Employee::addHoursWorked(int hours)
{
	this->hoursWorked += hours;
}

void Employee::calculateTotalCompensation()
{
	this->totalCompensation += (this->hoursWorked * hourlyPayRate);
	this->hoursWorked = 0;
}


Employee::~Employee()
{
}

ostream & operator<<(ostream & cout, const Employee& employee)
{
	cout << employee.employeeName << ", $" << employee.totalCompensation;
	return cout;
}