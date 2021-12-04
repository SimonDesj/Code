
#include "Person.h"
#include "Organization.h"
#include "university.h"
#include "Plist.h"


//add a person to an organization and an organization to a person 
void registering(Organization* o, Person* p) {
    o->addPerson(p);
    p->addOrganization(o);
}

//prints the name of the person, the number of organizations of the person and the name list of the organizations of the person 
void printMembers(Person& person)
{

    cout << person.getName() << " is part of " << person.getSize() << " organisations: " << endl;
    cout << person.getOrgNames() << endl;

}

void withdraw(Organization* o, Person* p)
{
    //to be completed
}




//main: to test program 
int main() {
    Organization* o0 = new Organization("SAMSUNG");
    Organization* o1 = new Organization("Test");
    Organization* o2 = new Organization("Subway");
    Organization* o3 = new Organization("Metro");
    Organization* o4 = new Organization("Microsoft");
    Organization* o5 = new Organization("Google");


    University* o6 = new University("UofO");
    University* o7 = new University("UofT");
    o6->setTuition(10);
    o7->setTuition(30);

    Person* p1 = new Person("Tom");
    Person* p2 = new Person("John");

    registering(o0, p1);
    cout<<p1->getOrgNames()<<endl;
    cout<<o0->getMemberNames()<<endl;
    registering(o1, p1);
    registering(o6, p1);
    registering(o3, p1);
    registering(o7, p1);
    registering(o5, p1); //throws error : Should be caught and handled by Person

    registering(o1, p2);
    registering(o6, p2);
    registering(o5, p2);


    printMembers(*p1);
    cout << "University Organization: \n" << p1->printSchools() << endl;
    cout << "With Total tuition fees of " << p1->getTotalTuition() << " $" << endl << endl;
    //withdraw(o3,p1);
    
    //withdraw(o2,p1); // This should output an error message as p1 is not a member of o2

    cout << "----------------------------------------------------------------" << endl;
	  printMembers(*p1);
    cout << "University Organization: \n" << p1->printSchools() << endl;
    cout << "With Total tuition fees of " << p1->getTotalTuition() << " $" << endl << endl;
	  cout << "----------------------------------------------------------------" << endl;
   
    printMembers(*p2);
    cout << "University Organization: \n" << p2->printSchools() << endl;
    cout << "With Total tuition of " << p2->getTotalTuition() << " $" << endl << endl;

  


    return 0;

}