#include <stdio.h>
#include <stdint.h>
#include <string.h>

//HOW TO COMPILE MY CODE IN VSCODE: 
//gcc milestone1.c milestone2.c milestone3.c utf8analyzer.c tests.c -o utf8analyzer_tests
//or just do the thingy with the a 

int32_t width_from_start_byte(char start_byte);


int32_t codepoint_at(char str[], int32_t cpi) {
    int32_t index = 0;
    for (int32_t i = 0; str[i] != '\0';) { // Note the change here: removing the increment from for loop
        int32_t bytes = width_from_start_byte(str[i]);
        if (bytes < 1) {
            return -1; // Invalid character
        }
        if (index == cpi) {
            int32_t codepoint = 0;
            for (int32_t j = 0; j < bytes; j++) {
                codepoint = (codepoint << 8) | (unsigned char) str[i + j]; // Combine bytes
            }
            return codepoint; // Return the full codepoint value
        }
        i += bytes; // Increment to the next codepoint
        index++;
    }
    return -1; // Codepoint index out of range
}

/*
Takes a UTF-8 encoded string and an codepoint index, and returns if the code point at that index is an animal emoji.
For simplicity for this question, we will define that that the “animal emojii” are in two ranges: 
from 🐀 to 🐿️ and from 🦀 to 🦮. (Yes, this technically includes things like 🐽 
which are only related to or part of an animal, and excludes a few things like 🙊, 😸, 
which are animal faces.). You may find the wikipedia page on Unicode emoji helpful here.
*/

char is_animal_emoji_at(char str[], int32_t cpi) {
int32_t codepoint = codepoint_at(str, cpi); 
//^ takes a string and an index as parameters; retrieves the code point (often the Unicode or ASCII value) of the character located at the specified index in the string.
    if (codepoint == -1) {
        return 0; // Invalid codepoint
    }
    // Check if the codepoint falls within the ranges for animal emojis
    if ((codepoint >= 0x1F400 && codepoint <= 0x1F43F) || // 🐀 to 🐿️
        (codepoint >= 0x1F980 && codepoint <= 0x1F992)) { // 🦀 to 🦮
        return 1; // It is an animal emoji
    }
    return 0; // Not an animal emoji
}

int milestone3() {


}


//byte = information storage 
//codepoint = specific combo of hexidecimal characters that correspond to a certain specific character