#include <stdio.h>
#include <stdint.h>
#include <string.h>

int tests() {

    //MILESTONE 3 STUFF BELOW HERE 
    //int32_t codepoint_at(char str[], int32_t cpi)
    //Retrieves the decimal representation of the codepoint at the specified codepoint index in a UTF-8 encoded string.

    //char is_animal_emoji_at(char str[], int32_t cpi)
    //Checks if the codepoint at the given index in a UTF-8 string is an animal emoji.
    //Defined Ranges for Animal Emojis:
        //From 🐀 to 🐿️
        //From 🦀 to 🦮
    //Note: This definition includes some emojis related to animals but excludes others like animal faces.

}

//HOW TO COMPILE MY CODE IN VSCODE: 
//gcc milestone1.c milestone2.c milestone3.c utf8analyzer.c tests.c -o utf8analyzer_tests
//or just do the thingy with the a 

/*Instructions for running C on vscode: 
1) open a new terminal
2) switch (toggle) from powershell to Command Prompt (cmd)
3) navigate to the correct directory
4) in the terminal, type: gcc fileName.c
5) a file called a.exe appears in the directory (if not already there)
6) type a in the terminal, then press enter*/
