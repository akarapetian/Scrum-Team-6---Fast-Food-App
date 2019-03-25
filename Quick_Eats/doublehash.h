/*
 * Sean Cox
 * CS1D
 * Lebowitz
 * Assignment 6
 */
#ifndef DOUBLEHASH_H_
#define DOUBLEHASH_H_
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <QString>
#include <QDebug>
#include <fstream>
#include <math.h>
using namespace std;

struct node{
    int key;
    QString username;
    QString password;
    int accessLevel;
};

// Hash table size
#define TABLE_SIZE 31

// Used in second hash function.
#define PRIME 17

class DoubleHash
{
    // Pointer to an array containing buckets
    node *hashTable;
    int curr_size;

public:
    // function to check if hash table is empty
    bool isEmpty(){
        return (curr_size == 0);
    }

    // function to check if hash table is full
    bool isFull(){
        // if hash size reaches maximum size
        return (curr_size == TABLE_SIZE);
    }

    // function to calculate first hash
    int hash1(int key){
        return (key % TABLE_SIZE);
    }

    // function to calculate second hash
    int hash2(int key){
        return (PRIME - (key % PRIME));
    }

    DoubleHash(){
        hashTable = new node[TABLE_SIZE];
        curr_size = 0;
        for (int i=0; i<TABLE_SIZE; i++)
            hashTable[i].key = -1;
        string valid = "MW";
        insertHash(valid[0]+valid[1],"MW","MW",2);
        valid = "foodie";
        insertHash(valid[0]+valid[1]+valid[2]+valid[3]+valid[4]+valid[5],"foodie","foodie",1);
    }

    void removeKey(int key){
        // If hash table is empty
        if (isEmpty())
            return;

        //Find key starting from hash1 key value
        int i = 0;
        int index = hash1(key);
        while(hashTable[index].key != key && i != TABLE_SIZE){
            index = (index+1)%TABLE_SIZE;
            i++;
        }

        //IF i is 31 then it did not find the key
        if(i == TABLE_SIZE)
            return;

        //remove hash index
        hashTable[index].key = -1;
        hashTable[index].username = "";
        hashTable[index].password = "";
        hashTable[index].accessLevel = 0;

        //Maintain the hash
        index = (index+1)%TABLE_SIZE;
        while(hashTable[index].key != -1){
            int tempKey = hashTable[index].key;
            QString tempStr = hashTable[index].username;
            QString tempStr2 = hashTable[index].password;
            int tempAccessLevel = hashTable[index].accessLevel;
            hashTable[index].key = -1;
            hashTable[index].username = "";
            hashTable[index].password = "";
            hashTable[index].accessLevel = 0;
            insertHash(tempKey,tempStr,tempStr2,tempAccessLevel);
            index = (index+1)%TABLE_SIZE;
        }
    }

    // function to insert key into hash table
    void insertHash(int key,QString str, QString str2,int accLevel){
        // if hash table is full
        if (isFull())
            return;

        // get index from first hash
        int index = hash1(key);

        // if collision occurs
        if (hashTable[index].key != -1){
            // get index2 from second hash
            int index2 = hash2(key);
            int i = 1;
            while (1){
                // get newIndex
                int newIndex = (index + i * index2) %
                                        TABLE_SIZE;

                // if no collision occurs, store
                // the key
                if (hashTable[newIndex].key == -1){
                    hashTable[newIndex].key = key;
                    hashTable[newIndex].username = str;
                    hashTable[newIndex].password = str2;
                    hashTable[newIndex].accessLevel = accLevel;
                    break;
                }
                i++;
            }
        }

        // if no collision occurs
        else{
            hashTable[index].key = key;
            hashTable[index].username = str;
            hashTable[index].password = str2;
            hashTable[index].accessLevel = accLevel;
        }
        curr_size++;
    }

    // Function to display the hash table
    int validEntry(QString un,QString pass){
        int uKey = 0;
        int pKey = 0;
        bool uValid =false;
        bool pValid= false;
        for (int i = 0;i<un.size();i++) {
            uKey += un.toStdString()[i];
        }
        for (int i = 0;i<pass.size();i++) {
            pKey += pass.toStdString()[i];
        }

        int index = hash1(uKey);
        int i =0;
        while(hashTable[index].key != uKey && i != TABLE_SIZE){
            index = (index+1)%TABLE_SIZE;
            i++;
        }

        //IF i is 31 then it did not find the key
        if(i == TABLE_SIZE)
            return 0;
        uValid = (un == hashTable[index].username);
        if(!(uValid))
            return 0;

        index = hash1(pKey);
        i =0;
        while(hashTable[index].key != pKey && i != TABLE_SIZE){
            index = (index+1)%TABLE_SIZE;
            i++;
        }
        //IF i is 31 then it did not find the key
        if(i == TABLE_SIZE)
            return 0;

        pValid = (pass == hashTable[index].password);

        if(uValid && pValid){
            return hashTable[index].accessLevel;
        }
    }
};


#endif /* DOUBLEHASH_H_ */
