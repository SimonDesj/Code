
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Plist.h"
using namespace std;

class Organization;
 
/**
Class Person:  Create  Person, used to add organizations to a person
Private variable: name, age and others to define

*/
class Person {
    int dim;
    string name;
    int age;
    int size = 0;
    Plist<Organization*> organizations; //initialize organizations as a Plist template class pointer

public:

    Person(std::string n = "default", int a = rand() % 30 + 16);
    Person(const Person& p_rhs);
    void addOrganization(Organization* organization);
    float getTotalTuition();
    string printSchools();
    string getOrgNames();
    int getAge() { return age; }
    std::string getName() { return name; }
    int getSize() { return size; }
	~Person() { organizations.~Plist();} //Person destructor initialized by destructing the organizations through the PList destructor
    void removeOrganization(Organization* organization);
};

#endif