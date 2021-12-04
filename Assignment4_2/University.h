
#ifndef UNIVERSITY_H 
#define UNIVERSITY_H 

#include "Organization.h"



class University : public Organization {
    float tuition;

public:
    University(std::string name) : Organization(name),tuition (1000) {}



    University(const University& t): Organization(t) {
       
        tuition = t.tuition;
    }

    int getTuition() {
        return tuition;
    }

    void setTuition(int t) {
        tuition = t;
    }
    virtual int paytuition() override { return getTuition(); }

   
};

#endif

