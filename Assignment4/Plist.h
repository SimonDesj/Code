#ifndef PLIST_H
#define PLIST_H
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

template <typename T>
class Plist{
    int capacity;
    int size = 0;
    int current = -1;
    T* myArray;

    T get(){
        if(myArray[current] != nullptr){
            return myArray[current];
        }
        else{
            return -1;
        }
        
    }
    void start(){
        if(size != 0){
            current = 0;
        }
        else{
            cout<<"No elements in array"<<endl;
        }
    }
    void next(){
        if(current+1 != capacity){
            current++;
        }
        else{
            cout<<"End of the array"<<endl;
        }
    }
    bool isLast(){
        if(current+1 == capacity){
            return true;
        }
        else{
            return false;
        }
    }
    int getCurrent(){return current;}

public:
    Plist(): capacity(5), size(0),current(-1){
        
    };
    Plist(int cap): capacity(cap), size(0),current(-1){
        myArray = new T(5);
    };
    Plist(const T& obj);
    ~Plist(){
        delete[] myArray;
    }
    void add(T item){
        try{
            if(myArray.isLast()){ //check later to see if we only have to put isLast()
                throw out_of_range("Out of range - List is full, cannot add");
            }
            else{
                myArray.start();
                while(!myArray.isLast()){
                    if(myArray[myArray.getCurrent()]= -1 || current >=size){
                        int temp;
                        temp = myArray.getCurrent();
                        myArray[temp] = item;
                        size++;
                        break;
                    }
                    else{
                        myArray.next();
                    }
                }
                if(myArray.isLast()){ 
                //display a message if it was added or not
                    cout<<"added"<<endl;
                }
                else{
                    cout<<"idek bro change this shit"<<endl;
                }
            }
        }
        catch(const out_of_range& oor){
            cerr<<"Error: "<<oor.what()<<endl;
        }
    }
    bool remove(T item){
        myArray.start();
        while(!myArray.isLast()){
            if(myArray[myArray.getCurrent()] == item){
                myArray[myArray.getCurrent()] = -1;
                return true;
                //break;
            }
            else{
                myArray.next();
            }
        }
        if(myArray.isLast()&& size <= current){
            cout<<"Parameter was not found and was not removed ... change this"<<endl;
            return false;
        }
    }
    T getItem(int i){
        if(myArray[i] != nullptr){//if item is there and not null or smt
            return myArray[i];
        }
        else{ //if not found
            return -1;
        }
    }
    bool isFull(){
        if(myArray.isLast()){
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
        return size;
    }
    int getCapacity(){
        return capacity;
    }
};

// template<>
// class Plist<Person*>{
//     Person* myArray;
// public:
//     Plist(int cap) : 
    
//     Plist(Person obj){
//         myArray = new Person(obj);
//     }
// };

// template<>
// class Plist<Organization*>{
//     Organization* myArray;
// public:
    
//     Plist(Organization obj){
//         myArray = new Organization(obj);
//     }
// };


#endif