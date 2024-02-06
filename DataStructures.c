/* Implements the hash table and other necessary data structures for managing inventory efficiently.*/

#include "DataStructures.h"
#include <stdio.h>
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

// Function to read data from file and populate the hash table
void readDataFromFile(HashTable* hashTable, const char* fileName){
    FILE* file =fopen(fileName, "r");
    if (file == NULL){
        fprintf(stderr, "Error opening file: %s\n", fileName);
        return;
    }

    Part part;
    while (fscanf(file, "%d %64s %64s %d %d",
    &part.partID, part.storeAddress, part.partName, &part.price, &part.quantityOnHand) == 5){
        
        //Insert the part into the hash table
        insertPart(hashTable, &part);
    }

    fclose(file);
}


// Function to search for a part in the hash table
Part* searchPart(HashTable* hashTable, int partID) {
  // Implement the hash function to find the index
  int index = partID % hashTable->size;
  
  // Search for the part in the linked list at the computed index
  Node* current = hashTable->table[index];
  while (current != NULL) {
      if (current->part.partID == partID) {
          return &current->part;
      }
      current = current-> next;
  }
  
    // Part not found
    return NULL;
}

// Function to delete a part from the hash table
void deletePart(HashTable* hashTable, int partID) {
  // Implement the hash function to find the index
  int index = partID % hashTable->size;
  
  // Search for the part in the linked list at the computed index
  Node* current = hashTable->table[index];
  Node* previous = NULL;
  
  // Traverse the linked list to find the node to delete
  while (current != NULL) {
      if (current->part.partID == partID) {  
          // Remove the node from the linked list
          if (previous == NULL) {
          // The node to delete is the first node in the list
          hashTable->table[index] = current->next;
          } else {
              // The node to delete is not the first node
              previous->next = current->next;
          }
      // Free the memory allocated for the node
      free(current);
      return;
    }
    // Move to the next node
    previous = current;
    current = current->next;  
  }
}

// Function to free the memory allocated for the hash table
void freeHashTable(HashTable* hashTable){
    // Free each linked list and its nodes
    for (int i = 0; i < hashTable->size; ++i) {
        Node* current = hashTable->table[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current=next;
            }
        }
        
        // Free the array of pointersnand the hash table itself
        free(hashTable->table);
        free(hashTable);
}
        
        // Free the array of pointersnand the hash table itself
        free(hashTable->table);
        free(hashTable);
}
