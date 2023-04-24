/*
#include "profile.h"
#include <iostream> 
#include <vector>
#include <map>

//Normally dont use explicit namespacing
//but dont wanna type std:: a hundred times
using namespace std;

struct profile::student
{
    string name;
    int age;
    double gpa;
};

struct profile::course
{
    string name;
    int credits;
    map<string, vector<student>> enrollment;  // Map of string (section name) to vector of students enrolled
};

profile::profile()
{
    // Simple data structure example
    student john;
    john.name = "John Smith";
    john.age = 20;
    john.gpa = 3.5;

    cout << "Name: " << john.name << endl;
    cout << "Age: " << john.age << endl;
    cout << "GPA: " << john.gpa << endl;

    // Complex data structure example
    course cs101;
    cs101.name = "Introduction to Computer Science";
    cs101.credits = 3;

    // Add students to enrollment
    vector<student> section_a = { { "John Smith", 20, 3.5 }, { "Jane Doe", 19, 3.7 } };//using this it may be possible to have multiple characters per profile
    vector<student> section_b = { { "Bob Johnson", 21, 3.2 }, { "Sara Lee", 18, 3.9 } };

    cs101.enrollment["Section A"] = section_a;
    cs101.enrollment["Section B"] = section_b;

    // Print course information
    cout << "course Name: " << cs101.name << endl;
    cout << "Credits: " << cs101.credits << endl;

    // Print enrollment information
    for (const auto& section : cs101.enrollment) {
        cout << "Section: " << section.first << endl;
        for (const auto& student : section.second) {
            cout << "Name: " << student.name << ", Age: " << student.age << ", GPA: " << student.gpa << endl;
        }
        cout << endl;
    }
};

profile::~profile()
{

};
*/

