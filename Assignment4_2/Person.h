
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
    Plist<Organization*> organizations; 

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
	~Person() { organizations.~Plist();
     }
};

#endif