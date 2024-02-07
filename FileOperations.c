/*Handles reading from and writing to inventory data files, ensuring data integrity. */
/*Handles reading from and writing to inventory data files, ensuring data integrity. */

#include <stdio.h>>
#include <stdlib.h>
#include <string.h>

#define MAX_ADDRESS_LEN 64
#define MAX_NAME_LEN 64
#define MAX_DESCRIPTION_LEN 64

typedef struct{
    char storeAddress[MAX_ADDRESS_LEN];
    char partName[MAX_NAME_LEN];
    char partDescription[MAX_DESCRIPTION_LEN];
    unsigned int partID;
    unsigned int price;
    unsigned int quantity;
    } InventoryEntry;

void writeInventoryToFile(const char *fileName, const InventoryItem *inventory, size_t itemCount) {
    FILE *file = fopen(fileName, "wb");
    if (file == NULL) {
            fprintf(stderr, "Error opening file: %s\n", fileName);
            return;
    }

    // Write each inventory item to the file
    fwrite(inventory, sizeof(InventoryItem), itemCount, file);

    fclose(file);
}

int main() {
    // Determine the number of inventory entries
    int numEntries = 10;

    //Allocate memory for the array of inventory entries
    InventoryEntry *inventory = (InventoryEntry *)malloc(numEntries * sizeof(InventoryEntry));
    if (inventory == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    //Populate the inventory entries

}
