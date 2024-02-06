#ifndef DataStructures_H
#define DataStructures_H

// Define the structure for a part
typedef struct Part{
    int partID;
    char storeAddress[64]; // Max length 64 per requirements
    char partName[64]; // Max length per requirements
    int price;
    int quantityOnHand;
  // Add other fields as needed (description, price, quantity, etc.)
} Part;

// Define the structure for a node in the linked list (used for chaining)
typedef struct Node{
        Part part;
        struct Node* next;
} Node;

// Define the structure for a hash table
typedef struct {
  // Hash Table structure details
  int size;
  Node** table; // Array of pointers to Nodes
} HashTable;

//Function prototypes
HashTable* createHashTable(int size);
void insertPart(HashTable* hashTable, Part* part);
Part* searchPart(HashTable* hashTable, int partID);
void deletePart(HashTable* hashTable, int partID);
void freeHashTable(HashTable* hashTable);



#endif /*DataStructures_H*/
