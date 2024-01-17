/* Implements the hash table and other necessary data structures for managing inventory efficiently.*/

#include "DataStructures.h"
#include <stdlib.h>

// Function to create a new node
Node* createNode(Part part){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode != NULL){
    newNode->part = part;
    newNode->next = NULL;
    }
    return newNode;
}

// Function to creat a hash table
HashTable* createHashTable(int size) {
  HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
  if (hashTable != NULL){
  hashTable->size = size;
  hashTable->table = (Node**)malloc(sizeof(Node*) * size);
  if (hashTable->table != NULL){
      // Initialize each table entry to NULL
      for (int i = 0; i < size; ++i){
          hashTable->table[i] = NULL;
          }
    } else {
    free(hashTable);
    hashTable = NULL;
    }
  }
  return hashTable;
}

// Function to insert a part into the hash table
void insertPart(HashTable* hashTable, Part* part) {
    // Implement the hash function
    int index = part->partID % hashTable->size;
    
    // Create a new node for the part
    Node* newNode = createNode(*part);
    
    // Insert the node into the linked list at the computed index
    if (newNode != NULL) {
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

// Function to search for a part in the hash table
Part* searchPart(HashTable* hashTable, int partID) {
  // Implement the logic to delete a part from the hash table
}

// Function to delete a part from the hash table
void deletePart(HashTable* hashTable, int partID) {
  // Implement the logic to delete a part from the hash table
}

// Function to free the memory allocated for the hash table
void freeHashTable(HashTable* hashTable){
    // Implement the logic to free the memory allocation
}
