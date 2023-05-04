#include "ClassRoom.h"
#include <iostream>

using std::cout;
using std::endl;

#define INITIAL_ID_VALUE 0

void ClassRoom::init()
{
	for (int i = 0; i < MAX_STUDENTS_IN_CLASS; i++)
	{
		this->_studentsInClass[i].setId(INITIAL_ID_VALUE);	// resets all student id to zero
	}
}

void ClassRoom::addStudent(const Student stud)
{
	for (int i = 0; i < MAX_STUDENTS_IN_CLASS; i++)
	{
		if (this->_studentsInClass[i].getId() == 0)			// finds the first empty place for new student
		{
			this->_studentsInClass[i] = stud;
			break;
		}
	}
}

void ClassRoom::printStudents() const
{
	for (int i = 0; i < MAX_STUDENTS_IN_CLASS; i++)
	{
		if (this->_studentsInClass[i].getId() != 0)		// print only real students
		{
			cout << "Student number " << i << "info:" << endl;
			this->_studentsInClass[i].print();	// calls the print method in Student class
			cout << endl;
		}
	}
}




