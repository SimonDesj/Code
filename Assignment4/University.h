
#ifndef UNIVERSITY_H 
#define UNIVERSITY_H 

#include "Organization.h"



class University : public Organization { //University inherits from Organization
    string name; //name of university
    float tuition; //tuition
    
    
    public:
    University() : name(""), tuition(0){ //default constructor

    } 
    University(string arg) : Organization{arg}, name(arg), tuition(0){ //constructor with string parameter

    }
    University(const University& rhs) : Organization(rhs){ //copy assignment
        name = rhs.name;
        tuition = rhs.tuition;
    }
    float getTuition(){ //return tuition
        return tuition;
    }
    void setTuition(float set){ //set the tuition
        tuition = set;
    }
    
    
    string getName(){  //get name 
        
        return name;
    }
    
    virtual ~University(){} //destructor
   
};

#endif

