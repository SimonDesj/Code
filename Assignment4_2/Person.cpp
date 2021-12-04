
#include "Person.h"
#include "Organization.h"
#include "University.h"
#include "Plist.h"


Person::Person(std::string n, int a) {
    name = n;
    age = a;
    size = 0;
    dim = 5;
    Plist<Organization*> organizations (dim); //organization pointer initializing with the Plist template class for a capacity of dim
};


Person::Person(const Person& registered) {
    size = 0;
    name = registered.name;
    age = registered.age;
    dim = registered.dim;
    Plist<Organization*> organizations (dim);//organization pointer initializing with the Plist template class for a capacity of dim

    
}


float Person::getTotalTuition() {
    float total = 0;
    for (int i = 0; i < size; i++) {
        Organization* ptr = organizations.getItem(i); //get the pointer Item that's in the organizations array through the Plist class - Using this ptr to dynamic cast to university organizations
       University* op = dynamic_cast<University*>(ptr); //A3 stuff

        if (op != nullptr) {
            total += op->getTuition();
        }
    }
    return total;
}


std::string Person::printSchools() {
    string name = "";

    for (int i = 0; i < size; i++) {

        Organization* ptr = organizations.getItem(i);//get the pointer Item that's in the organizations array through the Plist class - Using this ptr to dynamic cast to university organizations
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
        name = name + (*organizations.getItem(i)).getName() + ", "; //getting the names by dereferencing organizations' pointer that we got from get Item and then get its name
    }
    return name;
}

 void Person::addOrganization(Organization* organization) {
    try{ 
        if (size == dim) {
            throw std::out_of_range(getName() + " has already 5 organization - Did not add "+name+" to " +organization->getName()); //throw if the size is at its capacity
        }
        else {
            organizations.add(organization); //if not add organization by the method in Plist 
            size++;
        }
    }
    catch(const out_of_range& oor){
        cerr<<"Error: "<< oor.what() <<endl; //throws out of range error
    }
}

void Person::removeOrganization(Organization* organization){
    try{ //try to see if we actually remove org or not
        if(organizations.remove(organization)){ //same concept as the remove person
            size--;
        }
        else if(!organizations.remove(organization)){ //same concept as the remove person
            throw -1; //same concept as the remove person
        }
    }
    catch(...){ //same concept as the remove person
        cerr<<"Error Person::removeOrganization: Cannot withdraw " +name +" from "+organization->getName() +". "+ name + " is not a member of the organization"<<endl;

    }
}