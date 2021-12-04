
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
    Plist<Person*> members; // list of members
    int size;  // actual size of the org
    


public:

    Organization(std::string n = "default") : name(n), size(0), dim(20)
    {
        //members = nullptr;
    };


    Organization(const Organization& organization) : 
        name(organization.name), size(organization.size), dim(organization.dim)
    {
        Plist<Person*> members (dim);
        for (int i = 0; i < size; i++) {

            //members[i] = organization.members[i];
        }

    }

    virtual ~Organization()
    {
        members.~Plist();
    }

    // return the name of all members enrolled in the organization
    // all members written in one string separated by semi-colons
    // returns empty string if no member is enrolled in the organization
    std::string getMemberNames()
    {
        std::string name = "";
        for (int i = 0; i < size; i++)
        {
            //name = name + members[i].getItem().getName() + ":" + std::to_string(members[i].getItem().getAge()) + "; ";
        }
        return name;
    }
    virtual int paytuition() { cout << "no tuition for organization class"; return 0; }
    // adds a Person to the members array of the organization
    // Should double the members array size if array is full
    void addPerson(Person person)
    {
        //if(members.getSize() ==0)members (dim); = new Plist<Person*> (dim); change
        if (size >= dim)
        {
            Plist<Person*> tmp (dim * 2);
            for (int i = 0; i < size; i++)
            {
                tmp.add(members.getItem(i));
            }
            members.~Plist();
            members = tmp;
            dim *= 2;
        }

        members.add(&person);
        size++;
    }

    string getName() {
        return name;
    }

    //add getters or setters if necessary 
};

#endif
