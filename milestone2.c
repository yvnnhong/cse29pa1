#include <stdio.h>
#include <stdint.h>
#include <string.h>

//HOW TO COMPILE MY CODE IN VSCODE: 
//gcc milestone1.c milestone2.c milestone3.c utf8analyzer.c
//or just do the thingy with the a 

//note: UTF stands for Unicode Transformation Format-8

/*Given the start byte of a UTF-8 sequence, return how many bytes it indicates the 
  sequence will take (start byte + continuation bytes). Returns 1 for ASCII characters, 
  and -1 if byte is not a valid start byte.*/

int32_t width_from_start_byte(char start_byte) {
    if((unsigned char) start_byte <= 0x7F) {
        return 1; 
        //1 byte ASCII character -- example: 'A'UTF-8 Encoding: 0x41 
    } else if((unsigned char) start_byte >= 0xc2 && (unsigned char) start_byte <= 0xDF){
        return 2; 
        //2 byte ASCII character -- example: 'é' (LATIN SMALL LETTER E WITH ACUTE)-- UTF-8 Encoding: 0xC3 0xA9
    } else if((unsigned char) start_byte >= 0xE0 && (unsigned char) start_byte <= 0xEF) {
        return 3; 
        //3 byte ASCII character -- Example: '€' (EURO SIGN) -- UTF 8 Encoding: 0xE2 0x82 0xAC 
    } else if((unsigned char) start_byte >= 0xF0 && (unsigned char) start_byte <= 0xF4) {
        return 4; 
        //4 byte ASCII character -- example: '𝄞' (MUSICAL SYMBOL G CLEF) -- UTF-8 Encoding: 0xF0 0x9D 0x84 0x9E
    }

    return -1; //invalid start byte
}


/*Takes a UTF-8 encoded string and returns the number of UTF-8 codepoints it represents.
  Returns -1 if there are any errors encountered in processing the UTF-8 string. */
//basically a function to compute the legnth of a UTF-8 encoded string in codepoints
//note: a code point is basically a character
int32_t utf8_strlen(char str[]) {
    int32_t len = 0;
    for(int i = 0; str[i] != '\0'; i=i+1) {
        int32_t bytes = width_from_start_byte(str[i]);
        if(bytes < 1) {
            return -1; //we return -1 if it is an invalid UTF-8 character
        }
        i=i+bytes;
        len=len+1;
    }
    return len; //return the total number of codepoints
}

/*
Given a UTF-8 encoded string, and a codepoint index, return the byte index in the 
string where the Unicode character at the given codepoint index starts.
Returns -1 if there are any errors encountered in processing the UTF-8 string.
*/
//basically we're writing a function to convert a codepoint index to byte index

int32_t codepoint_index_to_byte_index(char str[], int32_t cpi) {
    int32_t byte_index = 0;
    for(int32_t i = 0; i < cpi; i++) {
        int32_t bytes = width_from_start_byte(str[byte_index]);
        if(bytes < 1) {
            return -1; //invalid 
        }
        byte_index = byte_index + bytes; //move to next codepoint (character??)
    }
    return byte_index;
}

//note: the difference between a codepoint index and a byte index is 
/*
A codepoint index refers to the position of a character (codepoint) in a string, 
while a byte index refers to the position of a byte in the underlying byte representation of that string.

Key Differences:
Definition:

Codepoint Index: Counts the number of Unicode characters (codepoints) in a string. 
For example, in the string "abc😊", there are 4 codepoints: 'a', 'b', 'c', and '😊'.
Byte Index: Counts the individual bytes that make up the string in memory. The same string "abc😊" 
is represented in UTF-8 as 7 bytes: 'a', 'b', 'c' each take 1 byte, and '😊' takes 4 bytes.
Length:

The codepoint index is always less than or equal to the byte index, especially for 
strings containing multi-byte characters (like emojis or characters from certain languages).
 */


int milestone2() {


    //ALL MILESTONE 2 FUNCTIONS 
  

}