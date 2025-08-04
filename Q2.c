#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    if(str[len-1] == '\n') str[len-1] = '\0';
    len = strlen(str);
    for(int i = len - 1; i >= 0; i--) {
        putchar(str[i]);
    }
    putchar('\n');
    return 0;
}
