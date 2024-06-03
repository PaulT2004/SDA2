#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct destination
{
    char country[MAX];
    char city[MAX];
    int time;
};

typedef struct destination Destination;

int main()
{
    FILE* f = fopen("lab1.txt","r");
    if(f==NULL){
        printf("Failed");
    }
    else{
        printf("Success");
    }

    int number_of_lines = count_lines(f);
    Destination detail[number_of_lines];
    detail = (Destination*)malloc(number_of_lines*sizeof(Destination));

    for(int i=0;i<=number_of_lines;i++){
        fscanf(f, "%s %s %d", detail[i].country, detail[i].city, &detail[i].hour);
    }
    fclose(f);

    return 0;
}
