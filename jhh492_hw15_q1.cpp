#include "Employee.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void openFile(ifstream& inFile);

int main()
{
	DoublyLinkedList<Employee> list;
	int employeeID, hoursWorked, listSize;
	Employee maxPayEmployee;
	string employeeName;
	double hourlyPayRate, maxCompensation, secondMaxCompensation;
	ifstream employeeInfoFile, workedHoursFile;
	openFile(employeeInfoFile);
	while (employeeInfoFile >> employeeID) {
		employeeInfoFile >> hourlyPayRate;
		employeeInfoFile.ignore(9999, ' ');
		getline(employeeInfoFile, employeeName);
		Employee newEmployee(employeeID, hourlyPayRate, employeeName);
		list.insertAtHead(newEmployee);
	}
	listSize = list.size();
	if (listSize <= 0) {
		cout << "No employee information found!\n";
	}
	else {
		openFile(workedHoursFile);
		while (workedHoursFile >> employeeID) {
			workedHoursFile >> hoursWorked;
			for (DoublyLinkedList<Employee>::Iterator iterator = list.getHead(); !iterator.end(); iterator++) {
				if ((*iterator).getId() == employeeID) {
					(*iterator).addHoursWorked(hoursWorked);
					(*iterator).calculateTotalCompensation();
				}
			}
		}
		cout << "*********Payroll Information********\n";
			while (listSize > 0) {
				maxCompensation = list.getHead()->data.getTotalCompensation();
				for (DoublyLinkedList<Employee>::Iterator iterator = list.getHead(); !iterator.end(); iterator++) {
					if ((*iterator).getTotalCompensation() > maxCompensation) {
						maxCompensation = (*iterator).getTotalCompensation();
						maxPayEmployee = (*iterator);

					}
				}
				cout << maxPayEmployee << endl;
				listSize--;
			}
		
		}
		cout << "*********End payroll**************\n";
    return 0;
}

void openFile(ifstream& inFile){
	string fileName;
	cout << "Please enter the file name.\n";
	cin >> fileName;
	inFile.open(fileName);
	while (!inFile) {
		cout << "Error opening the file! Please enter the file name and try again.\n";
		cin >> fileName;
		fileName.clear();
		inFile.open(fileName);
	}
}

