#include<stdio.h>
int main()
{
    char filepath[200] = "D:\\marks.csv";
    FILE *fptr = fopen(filepath, "r");
    char token;
    do{
        token = fgetc(fptr);
        if (token == ','){
            printf("\t");
        }
        else{
            printf("%c", token);
        }
    }
    while(token != EOF);
    return 0;
}
