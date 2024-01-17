#ifndef DataStructures_H
#define DataStructures_H

//structure

typedef struct Part{
    int partID;
  // Part Structure Details
} Part;

typedef struct HashTable{
  // Hash Table structure details
} HashTable;

//Function prototypes
Hashtable* createHashTable(int size);
void insertPart(HashTable* hashTable, Part* part);
Part searchPart(HashTable* hashTable, int partID);
void deletePart(HashTable* hashTable, int partID);
void freeHashTable(HashTable* hashTable);



#endif /*DataStructures_H*/
