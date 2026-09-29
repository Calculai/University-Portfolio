#include <stdio.h>
#include <stdlib.h>

char* reverse(char*);

int main(void) {  
    int max = 100;
    char *str = malloc(max);
    if (!str) return 1;

    printf("\nEnter a string: ");
    fgets(str, max, stdin);

    str = reverse(str);

    printf("%s\n\n", str);

    free(str);
    return 0;
}

char* reverse(char* str){
    int length = 0;

    while (str[length]) {length++;}

    char *temp = malloc((length + 1) * sizeof(char));
    if (temp == NULL) return NULL;

    for (int i = 0; i < length; i++) {
        temp[i] = str[length - 1 - i];
    }
    temp[length] = '\0'; 

    for (int i = 0; i <= length; i++) {
        str[i] = temp[i];
    }

    free(temp);

    return str;
}
