
#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Plist.h"
using namespace std;


class Organization {

protected:
    string name; // name of the org
    int dim;  // max size of the org
    Plist<Person*> members; // list of members with Plist template class
    int size;  // actual size of the org
    


public:

    Organization(std::string n = "default") : name(n), size(0), dim(20)
    {
        
    };


    Organization(const Organization& organization) : 
        name(organization.name), size(organization.size), dim(organization.dim)
    {
        Plist<Person*> members (dim); //setting a new members with a size capacity by the Plist template constructor
        

    }

    virtual ~Organization()
    {
        members.~Plist(); //destructor
    }

    // return the name of all members enrolled in the organization
    // all members written in one string separated by semi-colons
    // returns empty string if no member is enrolled in the organization
    std::string getMemberNames()
    {
        std::string name = "";
        for (int i = 0; i < size; i++)
        {
            name = name + (*members.getItem(i)).getName() + ":" + std::to_string((*members.getItem(i)).getAge()) + "; "; //using the get item from Plist class to get the Person and then get his name and age through the Person class
        }
        return name;
    }
    virtual int paytuition() { cout << "no tuition for organization class"; return 0; }
    // adds a Person to the members array of the organization
    // Should double the members array size if array is full
    void addPerson(Person* person)
    {
        
        if (size >= dim)
        {
            Plist<Person*> tmp (dim * 2); // setting a new pointer array with a bigger capacity to add more members 
            for (int i = 0; i < size; i++)
            {
                tmp.add(members.getItem(i)); //copy members items to the temp 
            }
            members.~Plist(); //destructor call to remove members and free memory
            members = tmp; //set members to tmp
            dim *= 2; //multiply the dim by 2
        }

        members.add(person); //add the person through Plist method add
        size++; //add to size in this class
    }
    void removePerson(Person* person){
        try{ //try to see if we actually remove person or not
            if(members.remove(person)){ //since remove returns a bool we can see if it was removed or not
                size--; //if removed sub from size
            }
            else if(!members.remove(person)){ //if didn't remove throw -1 to catch and throw that we didn't remove
                throw -1;
            }
        }
        catch(...){ //catch anything then cerr 
            cerr<<"Error Organization::removeOrganization: Cannot withdraw " +name +" from "+person->getName() +". "+person->getName()+" doesn't have a member "+ name <<endl;
        }
    }

    string getName() {
        return name;
    }

    //add getters or setters if necessary 
};

#endif
