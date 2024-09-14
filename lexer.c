#include <string.h>
#include <stdio.h>

long int findSizeOfFile(char filename[]) {

    FILE * fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("ERROR NULL");
        return -1;
    }

    fseek(fp, 0, SEEK_END);

    long int res = ftell(fp);

    fclose(fp);
    //printf("%li", res);
    return res;
}

int main() {
    char input[100];
    printf("Please enter the name of the file you would like to parse: ");
    scanf("%s", &input);
    long int buffer = findSizeOfFile(input);

    char read[buffer]; //contents of file read ALSO NOT MEMORY SAFE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    FILE *in_file = fopen(input, "r");
    //FILE *out_file = fopen(input, "w"); //to write an output file

    if (in_file == NULL) {
        printf("Error! Could not find file!");
        return -1;
    }

    while (fgets(read, strlen(input), in_file)) {
        printf("%s", read);
    }

    // printf("%i",buffer);

    fclose(in_file);
    return 0;
}