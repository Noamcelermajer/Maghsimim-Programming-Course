#include <string>
#include <iostream>

using std::cout;
using std::endl;

using std::string;

double getAverage(unsigned int* grades);
string getGradeString(unsigned int* grades, const int gradeIndex);
void print(const int id, const string fName, const string lName, unsigned int* grades);
void printStudentInClass(const int classNum);

// grades array access
#define NUM_OF_GRADES 4
#define HISTORY_GRADE_IDX 0
#define MATH_GRADE_IDX 1
#define LITERATURE_GRADE_IDX 2
#define ENGLISH_GRADE_IDX 3
#define EMPTY_GRADE 200


#define EMPTY 200
#define MAX_NUM_OF_STUDENTS 30

int studentIdsArray[MAX_NUM_OF_STUDENTS] = { EMPTY };
unsigned int studentGradesTable[MAX_NUM_OF_STUDENTS][NUM_OF_GRADES] = { EMPTY };
string studentFirstNamesArray[MAX_NUM_OF_STUDENTS] = { "" };
string studentLastNamesArray[MAX_NUM_OF_STUDENTS] = { "" };


int studentClassRoomsArray[MAX_NUM_OF_STUDENTS] = { EMPTY };


namespace first
{
	void myPrint()
	{
		std::cout << "first" << std::endl;
	}
}

namespace second
{
	void myPrint()
	{
		std::cout << "second" << std::endl;
	}
}

double getAverage(unsigned int* grades)
{
	double sum = 0;
	int numOfValidGrades = 0;
	for (int i = 0; i < NUM_OF_GRADES; i++)
	{
		if (grades[i] != EMPTY_GRADE)	// takes only valid grades
		{
			numOfValidGrades++;
			sum += grades[i];
		}
	}
	if (numOfValidGrades == 0)		// avoids devision by zero
		return -1;
	return sum / numOfValidGrades;	// the average of all valid grades
}

using first::myPrint;

string getGradeString(unsigned int* grades, const int gradeIndex)
{
	if (grades[gradeIndex] == EMPTY_GRADE)
	{
		return "Not Graded";
	}
	else
	{
		return std::to_string(grades[gradeIndex]);
	}
}


void print(const int id, const string fName, const string lName, unsigned int* grades)
{
	cout << "Student id: " << id << endl
		<< "Name: " << fName << " " << lName << endl
		<< "*** Grades ***" << endl;
	cout << "History: " << getGradeString(grades, HISTORY_GRADE_IDX) << endl
		<< "Math: " << getGradeString(grades, MATH_GRADE_IDX) << endl
		<< "Literature: " << getGradeString(grades, LITERATURE_GRADE_IDX) << endl
		<< "English: " << getGradeString(grades, ENGLISH_GRADE_IDX) << endl;
}

void printStudentInClass(const int classNum)
{
	cout << "Class room number " << classNum << " students info:" << endl;

	for (int studentIdx = 0; studentIdx < MAX_NUM_OF_STUDENTS; studentIdx++)
	{
		if (studentClassRoomsArray[studentIdx] == classNum)
		{
			print(studentIdsArray[studentIdx], 
				studentFirstNamesArray[studentIdx], 
				studentLastNamesArray[studentIdx], 
				studentGradesTable[studentIdx]);
		}
	}
}

//int main()
//{
//	// first student info
//	int student1Idx = 0;
//	studentIdsArray[student1Idx] = 123456789;
//	studentGradesTable[student1Idx][HISTORY_GRADE_IDX] = 78;
//	studentGradesTable[student1Idx][MATH_GRADE_IDX] = 81;
//	studentGradesTable[student1Idx][LITERATURE_GRADE_IDX] = 90;
//	studentGradesTable[student1Idx][ENGLISH_GRADE_IDX] = 65;
//	studentFirstNamesArray[student1Idx] = "Shahar";
//	studentLastNamesArray[student1Idx] = "Hasson";
//
//
//
//	// second student info
//	int student2Idx = 1;
//	studentIdsArray[student2Idx] = 111111111;
//	studentGradesTable[student2Idx][HISTORY_GRADE_IDX] = 78;
//	studentGradesTable[student2Idx][MATH_GRADE_IDX] = 81;
//	studentGradesTable[student2Idx][LITERATURE_GRADE_IDX] = 90;
//	studentGradesTable[student2Idx][ENGLISH_GRADE_IDX] = 65;
//	studentFirstNamesArray[student2Idx] = "Beyonce";
//	studentLastNamesArray[student2Idx] = "";
//
//	
//	studentClassRoomsArray[student1Idx] = 1;
//	studentClassRoomsArray[student2Idx] = 2;
//
//	printStudentInClass(0);
//
//	system("pause");
//	return 0;
//}