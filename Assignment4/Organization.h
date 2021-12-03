
#ifndef ORGANIZATION_H
#define ORGANIZATION_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
template <typename T>
class Plist;

class Organization {

protected:
    string name; // name of the org
    Plist<Person> members = Plist<Person>(dim); // list of members
    int size=0;  // actual size of the org
    int dim = 20;  // max size of the org
public:
    Organization() : name(""),size(0),dim(20){ //base constructor
        
    }
    Organization(string arg) : name(arg), size(0), dim(20){ //constructor with string parameter
        
    }
    
    Organization(const Organization& organization) : 
        name(organization.name), size(organization.size), dim(organization.dim)
    {
       // members = new Person[dim];
        // for (int i = 0; i < size; i++) {

           // members = organization.members[i];
        // }

    }
    virtual ~Organization()
    {
        //delete[] members; how to delete
    }
    
    // Organization(const Organization& objInit) { //one of the three muskateers / copy constructor "with deep copy"
    //     name = objInit.name; 
    //     size = objInit.size;
    //     delete[] members;//delete current members from memory
    //     if(objInit.members){//if copied object  has members
    //         members = new Person[size];//set members to size

    //         for (int i = 0; i< size; i++){//add members to 
    //             members[i] = objInit.members[i];//copy the members 
    //         }
    //     }
    //     else{//if not then just assign the copied members pointer to null
    //         members = nullptr;
    //     }
        
    // }
    // Organization& operator=(const Organization& rhs){ // second of the three muskateers / copy-assignment operator
    //     if(this != &rhs){//if rhs isn't the same as the lhs
    //         delete[] members; //same process as copy constrcutor
    //         if(rhs.members){
    //             members = new Person[size]; //initializing array
    //             for (int i = 0; i< size; i++){
    //                 members[i] = rhs.members[i];
    //             }
    //         }
    //         else{
    //             members = nullptr;
    //         }
    //     }
    //     return *this;

    // }
    // virtual ~Organization(){//last of the three muskateers / destructor
    //     delete members; members = nullptr;
    // } 

    //return the name of all members entolled in the organization 
    //all members written in one string separated by semi-colons
    //returns empty string if no memeber is enrolled in the organization 
    string getMemberNames(){
        string names = "";//base name
        if (members.getSize() != 0){
            //members.
            // while(){ //loop through members to get and add names to string to return
                
            // }
            //names = names + members[i].getItem().getName() + " ";
            return names;
        }
        else{
            return names;//if members = null return ""
        }
    }
    void addPerson(Person* person){ //adds a person to the members array of the organization and should double the memebrs array size if array is full
        try{ //adding a try and catch to throw an error if trying to add a person when array is full
            if((*person).getSize()==5){
                throw out_of_range("Out of range (Persons' Organization list is full) cannot add Person to Org");

            }
            else{
                if (size == dim){  //if size is the same as dim we double it
                    dim = dim *2;
                    cout<<"Array has been doubled"<<endl;
                }
                members.add(*person);
                size++;
            }
        }
        catch(const out_of_range& oor){
            cerr<<"Error: "<<oor.what()<<endl;
        }
    }

    virtual string getName(){ //make get name virtual to make it polymorphic so I can use dynamic_cast and get University name
        return name;
    }
    int getSize(){
        return size; //return size of organization
    }



};

#endif
