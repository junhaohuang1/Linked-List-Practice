CC=g++

CFLAGS=-c -Wall


all: jhh492_hw15_q1

jhh492_hw15_q1: jhh492_hw15_q1.o DoublyLinkedList.o Employee.o
	$(CC) jhh492_hw15_q1.o DoublyLinkedList.o Employee.o -o jhh492_hw15_q1

jhh492_hw15_q1.o: jhh492_hw15_q1.cpp
	$(CC) $(CFLAGS) jhh492_hw15_q1.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp
	$(CC) $(CFLAGS) DoublyLinkedList.cpp

Employee.o:Employee.cpp
	$(CC) $(CFLAGS) Employee.cpp

clean:
	rm *.o jhh492_hw15_q1
