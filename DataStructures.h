#ifndef DataStructures_H
#define DataStructures_H

// Define the structure for a part
typedef struct Part{
    int partID;
  // Add other fields as needed (description, price, quantity, etc.)
} Part;

// Define the structure for a node in the linked list (used for chaining)
typedef struct Node{
        Part part;
        struct Node* next;
} Node;

// Define the structure for a hash table
typedef struct HashTable{
  // Hash Table structure details
  int size;
  Node** table; // Array of pointers to Nodes
} HashTable;

//Function prototypes
Hashtable* createHashTable(int size);
void insertPart(HashTable* hashTable, Part* part);
Part* searchPart(HashTable* hashTable, int partID);
void deletePart(HashTable* hashTable, int partID);
void freeHashTable(HashTable* hashTable);



#endif /*DataStructures_H*/
