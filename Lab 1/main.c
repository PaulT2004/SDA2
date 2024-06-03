/*
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

//ex.1

struct destination
{
    char country[MAX];
    char city[MAX];
    int hour;
};

typedef struct destination Destination;

int count_lines(FILE* f){
    int lines = 1;
    char ch=fgetc(f);
    while(ch!=EOF){
        if(ch=="\n"){
            lines++;
        }
        ch=fgetc(f);
    }
    return lines;
}


void search(FILE* f)
{
    char element;
    int colomn=1;
    int row=1;
    int verification=0;
    printf("Introduceti elementul care doriti sa-l cautati:");
    scanf("\n%c" &element);
    char dh=fgetc(f);
    while(dh!=EOF){
        if(dh==element){
            printf("Elementul a fost gasit in randul %d in coloana %d", row, colomn);
            verification=1;
        }
        else if(dh=="\n"){
            colomn++;
            row=1;
        }
        else{
            row++;
        }
        dh=fgetc(f);
    }
    if(verification==0){
        printf("Elementul nu a fost gasit");
    }
}

int main()
{
    FILE* f = fopen("lab1.txt","r");

    int number_of_lines = count_lines(f);
    Destination detail[number_of_lines]

    printf(f, "%d", number_of_lines));

    for(int i=0;i<number_of_lines;i++){
        fscanf("%s %s %d", &detail.country[i], &detail.city[i], &detail.hour[i]);
    }
    fclose(f);

    for(int i=0;i<number_of_lines;i++){
        printf("%s %s %d", detail.country[i], detail.city[i], detail.hour[i]);
    }

    search(f);

    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 50

//ex.2

struct destination
{
    char country[MAX];
    char city[MAX];
    int hour;
};

typedef struct destination Destination;

int count_lines(FILE* f){
    int lines = 0;
    char ch=fgetc(f);
    while(ch!=EOF){
        if(ch=='\n'){
            lines++;
        }
        ch=fgetc(f);
    }
    return lines;
}

void search(FILE* f, Destination *detail)
{
    char element;
    int row=1;
    int colomn=1;
    int verification=0;
    printf("Introduceti elementul care doriti sa-l cautati:");
    scanf("\n%c", &element);
    rewind(f);
    char dh=fgetc(f);
    while(dh!=EOF){
        if(dh==element){
            printf("Elementul a fost gasit in randul %d", colomn);
            verification=1;
        }
        else if(dh=='\n'){
            colomn++;
        }
        dh=fgetc(f);
    }
    if(verification==0){
        printf("Elementul nu a fost gasit");
    }
    menu(f, detail);
}

void sort(FILE* f, Destination *detail)
{
    //sortare dupa timp
    int number_of_lines = count_lines(f);
    rewind(f);
    int count=0;
    while(count<number_of_lines){
        for(int i=0;i<number_of_lines;i++){
            if(detail[i].hour==count);
            printf("Tara: %s\nOras: %s\nOra: %d\n\n", detail[i].country, detail[i].city, detail[i].hour);
        }
        count++;
    }

}

void insert_end(FILE* f, Destination *detail)
{
    int number_of_lines = count_lines(f);
    detail = realloc(detail, number_of_lines+1*sizeof(Destination));

    printf("Introduceti tara, orasul si ora: ");
    scanf("\n%s %s %d", detail[number_of_lines+1].country, detail[number_of_lines+1].city, &detail[number_of_lines+1].hour);

    for(int i=0;i<=number_of_lines+1;i++){
        printf("%s %s %d", detail[i].country, detail[i].city, detail[i].hour);
    }
    menu(f, detail);
}

void insert_beginning(FILE* f, Destination *detail)
{
    int number_of_lines = count_lines(f);
    detail = realloc(detail, number_of_lines+1*sizeof(Destination));
    for(int i=number_of_lines+1;i-1>=1;i--){
        detail[i]=detail[i-1];
    }

    printf("Introduceti tara, orasul si ora: ");
    scanf("\n%s %s %d", detail[1].country, detail[1].city, &detail[1].hour);

    for(int i=0;i<=number_of_lines+1;i++){
        printf("%s %s %d", detail[i].country, detail[i].city, detail[i].hour);
    }
    menu(f, detail);
}

void insert_user(FILE* f, Destination *detail)
{
    int number_of_lines = count_lines(f);
    detail = realloc(detail, number_of_lines+1*sizeof(Destination));

    int place;
    printf("Introduceti locul in care doriti sa puneti datele: ");
    scanf("\n%d", &place);
    for(int i=number_of_lines+1;i-1>=place-1;i--){
        detail[i]=detail[i-1];
    }

    printf("Introduceti tara, orasul si ora: ");
    scanf("\n%s %s %d", detail[place-1].country, detail[place-1].city, &detail[place-1].hour);

    for(int i=0;i<=number_of_lines+1;i++){
        printf("%s %s %d", detail[i].country, detail[i].city, detail[i].hour);
    }
    menu(f, detail);
}

void delete_user(FILE* f, Destination *detail)
{
    int number_of_lines = count_lines(f);
    int place;
    printf("Introduceti locul in care doriti sa stergeti datele: ");
    scanf("\n%d", &place);
    for(int i=place-1;i<=number_of_lines;i++){
        detail[i]=detail[i+1];
    }
    detail = realloc(detail, number_of_lines-1*sizeof(Destination));

    for(int i=0;i<=number_of_lines-1;i++){
        printf("%s %s %d", detail[i].country, detail[i].city, detail[i].hour);
    }
    menu(f, detail);
}


void menu(FILE* f, Destination *detail){
    rewind(f);
    int number;
    printf("1 - Cautare\n2 - Sortare\n3 - Inserare la sfarsit\n4 - Inserare la inceput\n5 - Inserare de catre utilizator\n6 - Stergere\n7 - Iesire\n\n");
    scanf("\n%d", &number);
    if(number==1){
        search(f, detail);
    }
    else if(number==2){
        sort(f, detail);
    }
    else if(number==3){
        insert_end(f, detail);
    }
    else if(number==4){
        insert_beginning(f, detail);
    }
    else if(number==5){
        insert_user(f, detail);
    }
    else if(number==6){
        delete_user(f, detail);
    }
    else if(number==7){
        fclose(f);
        free(detail);
        exit(1);
    }
    else{
        printf("Ati introdus un alt numar, incercati din nou");
        menu(f, detail);
    }
}


int main()
{
    FILE* f = fopen("Lab1FileSDA.txt","r");
    if(f==NULL){
        printf("Fisierul nu se deschide");
        exit(1);
    }
    else{
        printf("Fisier deschis\n");
    }

    int number_of_lines = count_lines(f);
    Destination* detail = (Destination*)malloc(number_of_lines*sizeof(Destination));

    if(detail==NULL){
        printf("Alocarea nu a avut loc");
    }
    else{
        printf("Alocarea este\n\n");
    }

    for(int i=0;i<number_of_lines;i++){
        fscanf(f,"%s %s %d\n", detail[i].country, detail[i].city, &detail[i].hour);
    }

    for(int i=0;i<number_of_lines;i++){
        printf("Tara: %s\nOras: %s\nOra: %d\n\n", detail[i].country, detail[i].city, detail[i].hour);
    }

    menu(f, detail);

    return 0;
}



