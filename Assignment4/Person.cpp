
#include "Person.h"
#include "Organization.h"
#include "University.h"
#include "Plist.h"


    
Person::Person() : name(""), age(0) { //default constructor
    
}
Person::Person(string arg) : name(arg), age(0){// constructor with string parameter
    
}

Person::Person(const string& nameInit,const int& ageInit) :name(nameInit), age(ageInit){ //copy constructor with deep copy
    
}
Person& Person::operator=(const Person& rhs){ //copy assignment constructor
    // if (this!= &rhs){
    //     name = rhs.name; 
    //     age = rhs.age;
    //     if(size!= 0){
    //         for(int i = 0; i<size; i++){ //goes through organizations to copy 
    //                 delete organizations[i];
    //         }
    //     }
    //     delete[] organizations; //delete org to copy 
    //     if(rhs.organizations && size!= 0){
    //         organizations = new Organization*[5]; 
    //         for (int i = 0; i < size; i++){
    //             organizations[i] = rhs.organizations[i];
    //         }
    //     }
    //     else{
    //         organizations = nullptr;
    //     }
        

    // }
     return *this;
}

int Person::getAge(){
    return age; //return age
}
int Person::getSize(){
    return size; //return size of double pointer array
}
string Person::getName(){
    return name; //get name
}
void Person::addOrganization(Organization* organization){
    try{ //throw a try and catch
        if(size == 5){
            throw out_of_range("Out of range (Organizations list of 5 is full) cannot add Organiztion");
            //throw out of range error when trying to add to a full list
        }
        else{
            organizations.add(organization);
            // Organization** newOrgz = new Organization*[5]; //setting a temp org aray
            
            // for (int i =0; i < size; i++){ //copy elements from organizations to temp array
                
            //     newOrgz[i] = new Organization(); //setting new orgz
            //     newOrgz[i] = organizations[i];
            // }
            // newOrgz[size] = new Organization(); //setting the index of size to be the new added person
            // newOrgz[size] = organization;
            
            
            // delete[] organizations; //delete original to copy to new one
            // organizations = newOrgz;
            // newOrgz = nullptr; //set the temp to nullptr so we can create it again later
            size++; 
        }

    }
    catch(const out_of_range& oor){
        cerr<<"Error: "<< oor.what() <<endl;
    }
}

string Person::getOrgNames(){
    string names = "";
    if (organizations.getSize() != 0){ 
        for(int i = 0; i< organizations.getSize(); i++){
            names = names + (*organizations.getItem(i)).getName() + " "; //gets all the names of org by traversing with loop
        }
        return names;
    }
    else{
        return names;
    }
    return names;

}


float Person::getTotalTuition(){
    float total = 0; //set total to 0 for now
    if (organizations.getSize() != 0){ //if organizations isn't a nullptr
        //dynamic casting to down cast to set the ptrUni to only point to University organizations 
        for(int i = 0; i< size; i++){
            University* ptrUni = dynamic_cast<University*>((organizations.getItem(i)));
            if(ptrUni != nullptr){
                total = total + (*ptrUni).getTuition(); //add the tuition to total tuition of universities
            }
        }
        return total;
    }
    else {
        return total;
    }
    return total;
}
string Person::printSchools(){
    string names = ""; //base name is empty
    
    if (organizations.getSize() !=0){
        //same concept as totalTuition - dynamic casting to get ptrUni to point to only University objects 
        University *ptrUni;
        for(int i = 0; i< size; i++){
            ptrUni = dynamic_cast<University*>((organizations.getItem(i)));
            if(ptrUni!= nullptr){
                //get name of university and tuition
                names = names + (*ptrUni).getName() + ": " + to_string((*ptrUni).getTuition()) + "$ "; 
                
            }
        }
    
        return names;
    }
    else{
        return names+"No Schools";
    }
    return names;
} 


Person::~Person(){} //detructor and also delete organizations dynamic pointer





