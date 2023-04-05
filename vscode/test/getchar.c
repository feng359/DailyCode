#include<stdio.h>
#include<stdlib.h>


int main(){

    char ch;

    while((ch = getchar()) != EOF){

        putchar(ch);
    }

    system("pause");
    return 0;
}