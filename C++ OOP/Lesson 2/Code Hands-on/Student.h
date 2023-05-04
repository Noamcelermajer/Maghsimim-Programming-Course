#pragma once
#include <string>

// grades array access
#define NUM_OF_GRADES 4
#define HISTORY_GRADE_IDX 0
#define MATH_GRADE_IDX 1
#define LITERATURE_GRADE_IDX 2
#define ENGLISH_GRADE_IDX 3

// initial grade value
#define EMPTY_GRADE -1

class Student 
{
public:
	// methods
	double getAverage() const;
	void print() const;

	// getters
	int getId() const;
	std::string getFirstName() const;
	std::string getLastName() const;

	unsigned int getGrade(const int grade_idx) const;

	// setters
	void setId(const int newId);
	void setFirstName(const std::string newFirstName);
	void setLastName(const std::string newLastName);
	void setGrade(const int grade_idx, const unsigned int new_grade);

private:
	// fields
	int _id;
	std::string _firstName;
	std::string _lastName;
	unsigned int _grades[NUM_OF_GRADES];

	//methods
	std::string getGradeString(const int gradeIndex) const;	// helper method

};