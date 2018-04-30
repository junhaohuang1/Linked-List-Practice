#include "DoublyLinkedList.h"
#include "Employee.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void openFile(ifstream& inFile);


int main()
{
	int employeeID;
	double hourlyRate;
	string employeeName;
	ifstream inFile;
	openFile(inFile);
	DoublyLinkedList<Employee> list;

	while (inFile >> employeeID) {
		inFile >> hourlyRate;
		getline(inFile, employeeName);
		Employee* newEmployee = new Employee(employeeID, hourlyRate, employeeName);
		//list.insertAtHead(newEmployee);
		cout << newEmployee->getEmployeeName() << endl;
		delete newEmployee;
	}
	
    return 0;
}

void openFile(ifstream& inFile) {
	string fileName;
	cout << "Please enter the file name.\n";
	cin >> fileName;
	inFile.open(fileName);
	while (!inFile) {
		cout << "Error opening the file.\n Please enter the file name and try again.\n";
		cin >> fileName;
		inFile.clear();
		inFile.open(fileName);
	}
}