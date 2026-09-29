#include<stdio.h>
#include <stdlib.h>

void charbychar(char*,int);

int main(void){
    int max = 100;
    char *str = malloc(max);
    if (!str) return 1;

    printf("\nEnter a string: ");
    fgets(str, max, stdin);

    charbychar(str, 0);
}

void charbychar(char* str,int length){
    printf("\n");

    int i = 0;
    while (str[i])
    {
        printf("%c\n",str[i]);
        i++;
    }
}