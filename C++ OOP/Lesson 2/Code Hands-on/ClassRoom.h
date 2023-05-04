#pragma once

#include "Student.h"

#define MAX_STUDENTS_IN_CLASS 10

class ClassRoom
{
public: 
	void init();
	void printStudents() const;
	void addStudent(const Student stud);
private:
	Student _studentsInClass[MAX_STUDENTS_IN_CLASS];
};