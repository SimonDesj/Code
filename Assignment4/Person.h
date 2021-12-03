
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Organization; //add access to organization and university classes 
class University;
template <typename T>
class Plist;
/**
Class Person:  Create  Person, used to add organizations to a person
Private variable: name, age and others to define


Add all missing methods
*/
class Person {
    Plist<Organization*> organizations; //double pointer of size 5 for organizations
                //private elements
    string name; 
    int test = 0;
    int age;
    int size = 0;
    public:
    Person(); //default constructor
    Person(string arg);//constructor with string
    Person(const string& nameInit,const int& ageInit); //copy constructor with deep copy
    Person& operator=(const Person& rhs);//copy assignment constructor

    int getAge();
    int getSize();
    string getName();
    void addOrganization(Organization* organization);
    string getOrgNames();
    float getTotalTuition();
    string printSchools();
    virtual ~Person(); //virtual destructor
};

#endif