
#include "Person.h"
#include "Organization.h"
#include "University.h"
#include "Plist.h"


Person::Person(std::string n, int a) {
    name = n;
    age = a;
    size = 0;
    dim = 5;
    Plist<Organization*> organizations (dim);
};


Person::Person(const Person& registered) {
    size = 0;
    name = registered.name;
    age = registered.age;
    dim = registered.dim;
    Plist<Organization*> organizations (dim);

    for (int i = 0; i < size; i++) {
        //organizations[i] = registered.organizations[i];
    }
}


float Person::getTotalTuition() {
    float total = 0;
    for (int i = 0; i < size; i++) {
        Organization* ptr = organizations.getItem(i);
       University* op = dynamic_cast<University*>(ptr);

        if (op != nullptr) {
            total += op->getTuition();
        }
    }
    return total;
}


std::string Person::printSchools() {
    string name = "";

    for (int i = 0; i < size; i++) {

        Organization* ptr = organizations.getItem(i);
        University* op = dynamic_cast<University*>(ptr);
        if (op != nullptr) {
            name = name + op->getName() + ": " + to_string(op->getTuition()) + "; ";

        }
    }
    return name;
}


std::string Person::getOrgNames() {
    std::string name = "";
    for (int i = 0; i < size; i++)
    {
        name = name + (*organizations.getItem(i)).getName() + ", ";
    }
    return name;
}

 void Person::addOrganization(Organization* organization) {
    try{
        if (size == dim) {
            throw std::out_of_range(getName() + " has already 5 organization - Did not add "+organization->getName());
        }
        else {
            organizations.add(organization);
            size++;
        }
    }
    catch(const out_of_range& oor){
        cerr<<"Error: "<< oor.what() <<endl;
    }
}

void Person::removeOrganization(Organization* organization){
    organizations.remove(organization);
}