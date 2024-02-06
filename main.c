/*Entry  point where program execution begins. Handles user input and interacts with other modules. */
#include "DataStructures.h"
#include "DataStructures.c"
#include <stdio.h>

int main(){
        // Create a hash table
        HashTable* hashTable = createHashTable(100); // Adjust size as need
        
        // Create a sample part
        Part samplePart = {1001};
        
        // Insert the sample part into the hash table 
        insertPart(hashTable, &samplePart);
        
        // Search for the part in the hash table
        Part* foundPart = searchPart(hashTable, 1001);
        
        // Check if part was found and print its information
        if (foundPart != NULL){
            printf("Part found: Part ID - %d\n", foundPart->partID);
        } else {
                printf("Part not found.\n");
        }
        
        // Delete the part from the hash table
        deletePart(hashTable, 1001);
        
        // Free the memory allocated for the hash table
        freeHashTable(hashTable);
        
        return 0;   
}
