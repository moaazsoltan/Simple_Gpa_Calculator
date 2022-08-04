#include "GpaCalculatorClasses.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#define DEBUG

std::vector<Grade> gradebook;
std::vector<Student> students;
std::vector<Course> courses;
std::vector<ReportCard> reportCards;
std::ifstream inFile;
std::ofstream outFile;
std::string strBuffer;

int main() {


	// Student Classes
	inFile.open("students.txt");
	if (inFile.fail())
		std::cout << std::endl << "File not found!" << std::endl;
	else {
		while (!inFile.eof())
		{
			getline(inFile, strBuffer);   // Gets id
#ifdef DEBUG
			std::cout << strBuffer << std::endl;
#endif
			int student_id = stoi(strBuffer);
			getline(inFile, strBuffer);   // Gets Name
			std::string student_name = strBuffer;
			students.push_back(Student(student_id, student_name));
		}
	}
	inFile.close();

#ifdef Debug
	std::cout << students[0].get_id() << std::endl;
#endif

	// Constructing gradebook
	inFile.open("grades.txt");

	if (inFile.fail())
		std::cout << std::endl << "File not found!" << std::endl;
	else {
		while (!inFile.eof())
		{
			getline(inFile, strBuffer);   // Gets student_id
			int student_id = stoi(strBuffer);
			getline(inFile, strBuffer);   // Gets course_id
			int course_id = stoi(strBuffer);
			getline(inFile, strBuffer);   // Gets letter grade
			std::string letter_grade = strBuffer;
			gradebook.push_back(Grade(student_id, course_id, (char)letter_grade[0]));
		}
	}
	inFile.close();

	// Courses
	inFile.open("courses.txt");

	if (inFile.fail())
		std::cout << std::endl << "File not found!" << std::endl;
	else {
		while (!inFile.eof())
		{
			getline(inFile, strBuffer);   // Gets course_Id
			int course_id = stoi(strBuffer);
			getline(inFile, strBuffer);   // Gets course_name
			std::string course_name = strBuffer;
			getline(inFile, strBuffer);   // Gets course credit
			int course_credit = stoi(strBuffer);
			courses.push_back(Course(course_id, course_name, course_credit));
		}
	}
	inFile.close();


	// Cards
	for (auto& item : students) {
#ifdef DEBUG
		std::cout << typeid(item).name() << std::endl;
#endif
		reportCards.push_back(ReportCard(item.get_id(), item.get_name()));
	}

	int numbers_of_students = (int) students.size();

	for (auto& grade_record : gradebook) {

		// Find student, course
		Student student = students[grade_record.get_student_id()-1];
		auto course_id = grade_record.get_course_id();
		float number_grade = convert_letter_grade(grade_record.get_grade());

		// Find the course credits
		int course_credits = courses[static_cast<size_t>(course_id - 1)].get_credit();

		// add correct data to ReportCard
		ReportCard& reportcard = reportCards[static_cast<size_t>(grade_record.get_student_id() - 1)];
		reportcard.add_course(course_id, courses[static_cast<size_t>(course_id - 1)].get_name(), course_credits, number_grade);

	}

#ifdef DEBUG
	for (ReportCard& student_record : reportCards) {
		std::cout << "Name: " << student_record.get_student_name() << std::endl;
		std::cout << "  ID: " << student_record.get_student_id() << std::endl;
		for (int i = 0; i < student_record.get_number_of_courses(); i++) {

			std::cout<< "    Course ID:    " << student_record.get_course_id(i) << std::endl;
			std::cout<< "  Course Name:    " << student_record.get_course_name(i) << std::endl;
			std::cout <<"Course Credit:    " << student_record.get_course_credit(i) << std::endl;
			std::cout<< "        Grade:    " << std::fixed << std::setprecision(2) << student_record.get_course_grade(i) << std::endl;
		}
	}
#endif


	// Write Report to new text file

	if (outFile.fail())
		std::cout << std::endl << "Couldn't open the file!" << std::endl;
	else {

		for (ReportCard& student_record : reportCards) {
			std::string filename = student_record.get_student_name() + ".txt";
			outFile.open(filename);
			outFile << "Name: " << student_record.get_student_name() << std::endl;
			outFile << "  ID: " << student_record.get_student_id() << std::endl;
			for (int i = 0; i < student_record.get_number_of_courses(); i++) {
				student_record.compute_gpa();
				outFile << "    Course ID:    " << student_record.get_course_id(i) << std::endl;
				outFile << "  Course Name:    " << student_record.get_course_name(i) << std::endl;
				outFile << "Course Credit:    " << student_record.get_course_credit(i) << std::endl;
				outFile << "        Grade:    " << student_record.get_course_grade(i) << std::endl;
				outFile << "          GPA:    " << (float) student_record.get_gpa() << std::endl;

				// Calculator Total GPA
			}
			outFile.close();
		}
		std::cout << "File written successfully!" << std::endl;
	}
	return (0);



	std::cin.get();

}