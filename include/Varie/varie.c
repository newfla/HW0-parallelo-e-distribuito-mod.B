//
// Created by bizzi on 14/03/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 30

/* generate a random floating point number from min to max */
double rand_from(double min, double max)
{
    srand(time(NULL));
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}


void fill_vector(double* vector, int n){
    if(vector==NULL)
        return;
    for (int i = 0; i < n; i++)
        vector[i]=rand_from(10,30);
}

void append_to_file (char* fileName, char* string){

    FILE* file=fopen(fileName,"a");
    char* newLine="\n";

    if (file==NULL)
        return;

    fseek(file,0,SEEK_END);

    if (ftell(file)!=0)
        fprintf(file,newLine);

    fputs(string,file);
    fclose(file);
}

void clean_file(char* fileName){
    FILE* file=fopen(fileName,"w");
    fclose(file);
}