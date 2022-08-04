#include "GpaCalculatorClasses.h"


// Student Class
Student::Student(int the_id, std::string the_name) {
    id = the_id;
    name = the_name;
}
int Student::get_id() { return id; }
std::string Student::get_name() { return name; }


// Course Class
Course::Course(int id_i, std::string name_i, int crdts_i) {
    id = id_i;
    name = name_i;
    credits = crdts_i;
}
int Course::get_id() { return id; }
std::string Course::get_name() { return name; };
int Course::get_credit() { return credits; }


// Grade Class
Grade::Grade(int sid, int cid, char grd) {
    student_id = sid;
    course_id = cid;
    grade = grd;
}
int Grade::get_student_id() { return student_id; }
int Grade::get_course_id() { return course_id; }
char Grade::get_grade() { return grade; }


// Report Card Class
ReportCard::ReportCard(int id_i, std::string name_i) {
    id = id_i;
    name = name_i;
}

void ReportCard::add_course(int course_id, std::string course_name, int course_credit, float course_grade) {

    this->course_id.push_back(course_id);
    this->course_name.push_back(course_name);
    this->course_credit.push_back(course_credit);
    this->course_grade.push_back(course_grade);
    this->number_of_courses += 1;
}

int ReportCard::get_number_of_courses()
{
    return number_of_courses;
}

int ReportCard::get_course_id(int number)
{
    return course_id[number];
}

std::string ReportCard::get_course_name(int number)
{
    return course_name[number];
}

int ReportCard::get_course_credit(int number)
{
    return course_credit[number];
}

int ReportCard::get_student_id()
{
    return id;
}

std::string ReportCard::get_student_name()
{
    return name;
}

float ReportCard::get_course_grade(int number)
{
    return course_grade[number];
}

void ReportCard::compute_gpa()
{
    int numerator = 0;
    float denominator = 0.0f;
        for (int i = 0; i < this->number_of_courses; i++) {
            numerator = this->get_course_credit(i) * this->get_course_grade(i);
            denominator = this->get_course_credit(i);
    }
        this->GPA = (float) numerator / denominator;
}

float ReportCard::get_gpa()
{
    return GPA;
}


float convert_letter_grade(char g) {
    switch (g) {
    case 'A': 
        return 4.0f;
    case 'B':
        return 3.0f;
    case 'C':
        return 2.0f;
    default:
        return 0.0f;
    }
}
