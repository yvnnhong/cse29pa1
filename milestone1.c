#include <stdio.h>
#include <stdint.h>
#include <string.h>

//HOW TO COMPILE MY CODE IN VSCODE: 
//gcc milestone1.c milestone2.c milestone3.c utf8analyzer.c 
//or just do the thingy with the a 

//ALL MILESTONE 1 FUNCTIONS 

    //is_ascii: 
    //Checks if a UTF-8 encoded string contains only valid ASCII characters (emojis are NOT valid ascii characters)
    //(all bytes ≤ 127).

   int32_t is_ascii(char str[]) {
        for(int i=0; str[i] != '\0'; i++) { 
            //^Iterate through each character in the string until the null terminator ('\0') is reached:
            if((unsigned char)str[i] > 127) {
                //^checking if byte value is bigger than 127 (note: 128 unique values (from 0 to 127, inclusive))
                //casting to unsigned char => correct comparison for all character values
                return 0; //0=>false, so therefore the input is not ascii 
            }
        }
        return 1; //1=>true, so all the characters of the input are ascii 
   }


    //capitalize_ascii(char str[]) : 
    //Modifies the input string in-place, converting any ASCII lowercase letters (a-z) to uppercase 
    //(A-Z) while leaving other characters unchanged. Returns the number of characters updated.

    int32_t capitalize_ascii(char str[]) {
        int32_t converted_chars = 0; //keeping track of how many characters are non-uppercase 
        for(int i=0; str[i] != '\0'; i++) { 
            //^The loop iterates through each character in the string until it reaches the null terminator ('\0').
            if(str[i] >= 'a' && str[i] <= 'z') { //if the character is in lowercase, change to uppercase
                str[i] = str[i] - 'a' + 'A'; //change to uppercase-- note: 'a'=97 and 'A'=65
                converted_chars++;
            }
        }
        return converted_chars; //return the number of characters that were changed into uppercase 
    }
    //note: if a number such as 9 is inputted, my program will not crash; it will simply skip over the entire 'if' block

int milestone1() {


    //code goes here 

}

//My notes: (please don't grade these they're literally my lecture notes ahaha)
//note: in c, functions cannot be defined inside other functions 

//The term unsigned char refers to a data type in C that represents a character without any sign (positive or negative).
//The keyword unsigned specifies that the variable can only hold non-negative values.
//For unsigned char, this means it can store values from 0 to 255 instead of the typical signed char, 
//which can store values from -128 to 127.
//When working with raw byte data or when you need to ensure that values are always non-negative 
//(such as when dealing with ASCII values), using unsigned char helps prevent unintended negative values.
//This is particularly important when comparing byte values (like in the is_ascii function), as 
//ASCII characters range from 0 to 127. Using unsigned char ensures that comparisons are made correctly without negative interpretations.