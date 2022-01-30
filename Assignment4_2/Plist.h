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
        
        return myArray[current]; 
    }
    void start(){ 
        if(size != 0){ 
            current = 0;
        }
        else{
            
        }
        
    }
    void next(){ 
        if(current+1 != capacity){
            current++;
        }
        else{
            cout<<"index out of range"<<endl; 
        }
    }
    bool isLast(){
        if(get() ==myArray[size]){ 
            return true;
        }
        else{
            return false; 
        }
    }
    int getCurrent(){return current;} 

public:
    Plist(): capacity(5), size(0),current(-1),myArray(new T[size]){} 
    Plist(int cap): capacity(cap), size(0),current(-1),myArray(new T[size]){} 
    ~Plist(){ 
        delete[] myArray;
    }
    void add(T item){ 
        try{ 
            if(isFull()){ 
                throw out_of_range("Out of range - List is full, cannot add"); 
            }
            else{ 
                if(size == 0 && size < capacity){ 
                    size++; 
                    current++;
                    int temp; 
                    temp = getCurrent();
                    myArray[temp] = item; 
                }
                else{ 
                    start(); 
                    while(current<capacity){ 
                        if(current >=size){ 
                            int temp;
                            temp = getCurrent();
                            myArray[temp] = item; 
                            size++; 
                            break; 
                        }
                        else{
                            next(); 
                        }
                    }
                }

            }
        }
        catch(const out_of_range& oor){ 
            cerr<<"Error: "<<oor.what()<<endl;
        }
    }
    bool remove(T item){

        start(); 
        while(!isLast()){ 
            if(get() ==item){ 
                int temp,temp1; 
                temp = getCurrent(); 
                next(); 
                temp1 = getCurrent(); 
                myArray[temp] = myArray[temp1]; 
                size--;
                return true; 
                break;
    
            }
            else{
                next();
            }
        }
        if(isLast()&& size <= current){ 
            return false;
        }
    }
    T getItem(int i){       
        if(i <= size){         
            return myArray[i]; 
        }
        else{

        }
        
    }
    bool isFull(){ 

        return current+1 == size && size == capacity;
    }
    int getSize(){      
        return size;
    }
    int getCapacity(){
        return capacity;
    }
};



#endif