#ifndef PLIST_H
#define PLIST_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stddef.h>
using namespace std;

template <typename T>
class Plist{
    int capacity;
    int size = 0;
    int current = -1;
    T* myArray;

    T get(){
        return myArray[current]; //returns the item at current index
    }
    void start(){//iterate start over
        if(size != 0){ //if size is not empty we return current to 0;
            current = 0;
        }
        
    }
    void next(){ //iterate next
        if(current+1 != capacity){ //if the current != to the capacity we add to the current and in theory makes us traverse the list by adding to the index
            current++;
        }
        else{
            cout<<"End of the array"<<endl; //end of the array
        }
    }
    bool isLast(){
        if(get() ==myArray[size]){ //if the last element of the array is equal to the current index of the array then return true
            return true;
        }
        else{
            return false; //if not return false
        }
    }
    int getCurrent(){return current;} //returns the current

public:
    Plist(): capacity(5), size(0),current(-1),myArray(new T[size]){} //constructor for Plist 
    Plist(int cap): capacity(cap), size(0),current(-1),myArray(new T[size]){} //constructor for Plist with a parameter for the capacity
    ~Plist(){ //Plist destructor
        delete[] myArray;
    }
    void add(T item){ //add method
        try{ //try to see if list is not out of range if not we throw an error 
            if(isFull()){ 
                throw out_of_range("Out of range - List is full, cannot add"); //catching out of range later
            }
            else{ //if not full
                if(size == 0 && size < capacity){ //if the first element to be added and the capacity is bigger then 0
                    size++; //add one to size and current
                    current++;
                    int temp; //current index
                    temp = getCurrent();
                    myArray[temp] = item; //add item to my Array
                }
                else{ //if not first element to be added
                    start(); //start at the first element
                    while(current<capacity){ //while the current is lower then capacity
                        if(current >=size){ //and if the current is higher then the size we find free space
                            int temp;
                            temp = getCurrent();
                            myArray[temp] = item; //add item to that free space
                            size++; //add to size
                            break; //exit loop
                        }
                        else{
                            next(); //if not bigger then size then we iterate through the array
                        }
                    }
                }

            }
        }
        catch(const out_of_range& oor){ //catches the error
            cerr<<"Error: "<<oor.what()<<endl;
        }
    }
    bool remove(T item){

        start(); //start to first index
        while(!isLast()){ //while index is not last
            if(get() ==item){ //if we get the item we want to remove then
                int temp,temp1; //set two variable for the past and current index
                temp = getCurrent(); //past index with item to remove
                next(); //current +1
                temp1 = getCurrent(); //current index
                myArray[temp] = myArray[temp1]; //we remove the item by replacing it with the next element in the array and we remove from size so that the element is not reachable since it is out of the array size 
                size--;
                return true; //return true that item has been removed
    
            }
            else{ //if not the same item iterate through the array to try and find it
                next();
            }
        }
        if(isLast()&& size <= current){ //if we didn't find the item 
            return false;
        }
    }
    T getItem(int i){//get the item at index i
        if(i <= size){//if i is an index in the array
            return myArray[i]; //return the item at index i
        }
        else{ //if not in array index
            cout<<"not in array index"<<endl;
        }
    }
    bool isFull(){ //if size is equal to the capacity and current index is equal to the size

        return current+1 == size && size == capacity;
    }
    int getSize(){//return the size ofthe array
        return size;
    }
    int getCapacity(){ //capacity of the array
        return capacity;
    }
};



#endif