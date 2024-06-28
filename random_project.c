#include <stdio.h>
#include <string.h>

// Define buffer size for reading strings
#define BUFFER_SIZE 100

// Function Prototypes
int menu_checker();
int search_all();
int search();

int main() {
    printf("--- Oxford --- \n");
    printf("What do you want to do today? \n ");
    printf("------------------------------\n");
    printf(":s (Search All Words) | :q (Quit) | :x (Search Words) \n");

    menu_checker();
    return 0;
}

// Function to check valid inputs from the user.
int menu_checker() {
    char userInput[2]; // Buffer to hold the user input
    fgets(userInput, sizeof(userInput), stdin);

    // Different cases based on user input
    if (userInput[0] == 's') {
        printf("\n Goodbye! \n");
        search_all();
        return 0;
    }

    if (userInput[0] == 'x') {
        search();
        return 0;
    }

    if (userInput[0] == 'q') {
        printf("Goodbye! :)");
        return 0;
    }

    // Handle invalid inputs and loop back to the menu checker
    else {
        printf("Invalid input! \n");
        menu_checker();
        return 0;
    }

    return 0;
}

// Function to search and display all words from the dictionary file.
int search_all() {
    FILE *dict;

    // Open the dictionary file for reading
    dict = fopen("Oxford_English_Dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error opening file!\n");
        return 1; // Return an error code
    }

    char string[BUFFER_SIZE];

    // Loop through the file and print each line
    while (fgets(string, BUFFER_SIZE, dict)) {
        printf("%s", string);
    }

    // Close the file
    fclose(dict);

    return 0;
}

// Placeholder for the search function
int search() {
    printf("What word do you want to search? \n");

    printf("Search: \n");

    return 0;
}
