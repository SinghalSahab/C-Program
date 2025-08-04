#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_LEN 50

int main() {
    char paragraph[5000];
    fgets(paragraph, sizeof(paragraph), stdin);

    // Convert to lowercase and replace non-alphabetic chars with spaces
    for(int i = 0; paragraph[i]; i++) {
        if (!isalpha(paragraph[i])) paragraph[i] = ' ';
        else paragraph[i] = tolower(paragraph[i]);
    }

    char words[MAX_WORDS][MAX_LEN];
    int freq[MAX_WORDS] = {0}, count = 0;

    char *token = strtok(paragraph, " ");
    while(token) {
        int found = 0;
        for(int i = 0; i < count; i++) {
            if(strcmp(words[i], token) == 0) {
                freq[i]++;
                found = 1;
                break;
            }
        }
        if(!found && token[0] != '\0') {
            strcpy(words[count], token);
            freq[count] = 1;
            count++;
        }
        token = strtok(NULL, " ");
    }

    for(int i = 0; i < count; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }

    return 0;
}
