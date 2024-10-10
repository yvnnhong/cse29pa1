#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

// Function prototypes from other files 
int32_t is_ascii(char str[]);
int32_t capitalize_ascii(char str[]);
int32_t utf8_strlen(char str[]);
int32_t width_from_start_byte(char start_byte);
int32_t codepoint_at(char str[], int32_t cpi);
char is_animal_emoji_at(char str[], int32_t cpi);

void print_bytes_per_codepoint(char str[]) {
    for (int i = 0; str[i] != '\0';) {
        int32_t bytes = width_from_start_byte(str[i]);
        if (bytes < 1) {
            printf("Invalid UTF-8 sequence encountered.\n");
            return;
        }
        printf("%d ", bytes);
        i += bytes;
    }
    printf("\n");
}

int main() {
    char input[256];

    printf("Enter a UTF-8 encoded string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character

    // Check if input is valid ASCII
    printf("Valid ASCII: %s\n", is_ascii(input) ? "true" : "false");

    // Capitalize ASCII
    char capitalized[256];
    strcpy(capitalized, input); // Copy input to capitalize
    int32_t updated_chars = capitalize_ascii(capitalized);
    printf("Uppercased ASCII: \"%s\"\n", capitalized);
    printf("Characters updated: %d\n", updated_chars);

    // Length in bytes
    printf("Length in bytes: %lu\n", strlen(input));

    // Number of code points
    int32_t num_codepoints = utf8_strlen(input);
    if (num_codepoints < 0) {
        printf("Error in processing the UTF-8 string.\n");
    } else {
        printf("Number of code points: %d\n", num_codepoints);
    }

    // Bytes per code point
    printf("Bytes per code point: ");
    print_bytes_per_codepoint(input);

    // Substring of the first 6 code points
    char substring[256];
    int32_t total_length = 0;
    for (int i = 0; i < 6 && total_length < sizeof(substring) - 1; i++) {
        int32_t bytes = width_from_start_byte(input[total_length]);
        if (bytes < 1) break; // Stop if invalid byte
        strncat(substring, input + total_length, bytes);
        total_length += bytes;
    }
    substring[total_length] = '\0'; // Null-terminate the substring
    printf("Substring of the first 6 code points: \"%s\"\n", substring);

    // Code points as decimal numbers
    printf("Code points as decimal numbers: ");
    for (int i = 0; i < num_codepoints; i++) {
        printf("%d ", codepoint_at(input, i));
    }
    printf("\n");

    // Check for animal emojis
    printf("Animal emojis: ");
    for (int i = 0; i < num_codepoints; i++) {
        if (is_animal_emoji_at(input, i)) {
            printf("%c ", codepoint_at(input, i)); // Use codepoint_at to print the emoji character
        }
    }
    printf("\n");

    return 0;
}
