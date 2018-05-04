// jhh492_hw15_q1.cpp : Defines the entry point for the console application.
//
#include "Employee.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

void openFile(ifstream& inFile);

int main()
{
	DoublyLinkedList<Employee> list1, list2;
	int employeeID, hoursWorked, list1Size;
	Employee minPayEmployee;
	string employeeName;
	double hourlyPayRate, minCompensation;
	ifstream employeeInfoFile, workedHoursFile;
	cout << "Looking for employee information!\n";
	openFile(employeeInfoFile);
	while (employeeInfoFile >> employeeID) {
		employeeInfoFile >> hourlyPayRate;
		employeeInfoFile.ignore(9999, ' ');
		getline(employeeInfoFile, employeeName);
		Employee newEmployee(employeeID, hourlyPayRate, employeeName);
		list1.insertAtHead(newEmployee);
	}
	list1Size = list1.size();
	if (list1Size <= 0) {
		std::cout << "No employee information found!\n";
	}
	else {
		cout << "Looking for worked hours information!\n";
		openFile(workedHoursFile);
		while (workedHoursFile >> employeeID) {
			workedHoursFile >> hoursWorked;
			for (DoublyLinkedList<Employee>::Iterator iterator = list1.getHead(); !iterator.end(); iterator++) {
				if ((*iterator).getId() == employeeID) {
					(*iterator).addHoursWorked(hoursWorked);
					(*iterator).calculateTotalCompensation();
				}
			}
		}
			while (list1Size > 0) {
				minCompensation = list1.getHead()->data.getTotalCompensation();
				minPayEmployee = list1.getHead()->data;
				for (DoublyLinkedList<Employee>::Iterator iterator = list1.getHead(); !iterator.end(); iterator++) {
					if ((*iterator).getTotalCompensation() < minCompensation) {
						minCompensation = (*iterator).getTotalCompensation();
						minPayEmployee = (*iterator);
					}
				}
				list2.insertAtHead(minPayEmployee);
				list1.remove(minPayEmployee);
				list1Size--;
			}
			cout << "*********Payroll Information********\n";
			for (DoublyLinkedList<Employee>::Iterator iterator = list2.getHead(); !iterator.end(); iterator++) {
				cout << (*iterator) << std::endl;
			}
			cout << "***********End payroll**************\n";
		}
    return 0;
}

void openFile(ifstream& inFile) {
	string filename;
	cout << "What file would you like to open? ";
	cin >> filename;
	inFile.open(filename);
	while (!inFile) {
		cout << "Bad filename!" << endl;
		cout << "What file would you like to open? ";
		cin >> filename;
		inFile.clear();
		inFile.open(filename);
	}
}