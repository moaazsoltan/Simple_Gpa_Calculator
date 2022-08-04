#pragma once

// include Guard
#ifndef RECORDS_H
#define RECORDS_H
#include <string>
#include <vector>

class Student {
private:
    int id;
    std::string name;

public:
    Student(int id_i, std::string name_i);
    int get_id();
    std::string get_name();

};

class Course {
private:
    int id;
    std::string name;
    int credits;

public:
    Course(int id_i, std::string name_i, int crdts_i);
    int get_id();
    std::string get_name();
    int get_credit();

};

class Grade {
private:
    int student_id;
    int course_id;
    char grade;

public:
    Grade(int sid, int cid, char grd);
    int get_student_id();
    int get_course_id();
    char get_grade();
};

class ReportCard {
private:
    int id;
    std::string name;
    int number_of_courses = 0;
    std::vector<int> course_id;
    std::vector<std::string> course_name;
    std::vector<int> course_credit;
    std::vector<float> course_grade;
    float GPA;


public:
    ReportCard(int id_i, std::string name_i);
    void add_course(int course_id, std::string course_name, int course_credit, float course_grade);
    int get_number_of_courses();
    int get_course_id(int number);
    std::string get_course_name(int number);
    int get_course_credit(int number);
    int get_student_id();
    std::string get_student_name();
    float get_course_grade(int number);
    void compute_gpa();
    float get_gpa();
  
   



};

float convert_letter_grade(char g);
#endif // RECORDS_H