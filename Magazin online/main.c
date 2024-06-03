#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

struct shop
{
    char data[10];
    int id;
    char product_name[MAX];
    char product_category[MAX];
    char product_subcategory[MAX];
    double unit_price;
    int quantity_sold;
    char sale_country[MAX];
    char sale_city[MAX];
    double total_cost;
};

typedef struct shop Shop;

int count_lines(FILE* f){
    int lines = 1;
    char ch=fgetc(f);
    while(ch!=EOF){
        if(ch=='\n'){
            lines++;
        }
        ch=fgetc(f);
    }
    return lines;
}

void profit(Shop *detail, int number_of_lines)
{
    char search_month[2];
    char search_year[4];
    double count=0;
    printf("Enter month (format MM) and year (format YYYY): ");
    scanf("%s %s", search_month, search_year);
    for(int i=0;i<number_of_lines;i++){
        char data_i[10];
        strcpy(data_i, detail[i].data);
        char month_i[2];
        char year_i[4];
        strncpy(month_i,data_i+3,2);
        strncpy(year_i,data_i+6,4);
        if(strcmp(search_month,month_i)==0 && strcmp(search_year,year_i)==0){
            count+=detail[i].total_cost;
        }
    }
    printf("Profit in month %s, year %s: %.2lf\n\n", search_month, search_year, count);
    menu(detail, number_of_lines);
}

void top_products(Shop *detail, int number_of_lines)
{
    char top_1[MAX], top_2[MAX], top_3[MAX], top_4[MAX], top_5[MAX];
    double count_top_1=0, count_top_2=0, count_top_3=0, count_top_4=0, count_top_5=0;
    for(int i=0;i<number_of_lines;i++){
        double count=0;
        for(int j=0;j<number_of_lines;j++){
            if(i>j && strcmp(detail[i].product_name,detail[j].product_name)==0){
                continue;
            }
            if(strcmp(detail[i].product_name,detail[j].product_name)==0){
                count+=detail[j].total_cost;
            }
        }
        if(count>count_top_1){
            count_top_5=count_top_4;
            strcpy(top_5, top_4);
            count_top_4=count_top_3;
            strcpy(top_4, top_3);
            count_top_3=count_top_2;
            strcpy(top_3, top_2);
            count_top_2=count_top_1;
            strcpy(top_2, top_1);
            count_top_1=count;
            strcpy(top_1, detail[i].product_name);
        }
        else if(count>count_top_2){
            count_top_5=count_top_4;
            strcpy(top_5, top_4);
            count_top_4=count_top_3;
            strcpy(top_4, top_3);
            count_top_3=count_top_2;
            strcpy(top_3, top_2);
            count_top_2=count;
            strcpy(top_2, detail[i].product_name);
        }
        else if(count>count_top_3){
            count_top_5=count_top_4;
            strcpy(top_5, top_4);
            count_top_4=count_top_3;
            strcpy(top_4, top_3);
            count_top_3=count;
            strcpy(top_3, detail[i].product_name);
        }
        else if(count>count_top_4){
            count_top_5=count_top_4;
            strcpy(top_5, top_4);
            count_top_4=count;
            strcpy(top_4, detail[i].product_name);
        }
        else if(count>count_top_5){
            count_top_5=count;
            strcpy(top_5, detail[i].product_name);
        }
    }

    printf("Top 5 products:\n#1: %s\n#2: %s\n#3: %s\n#4: %s\n#5: %s\n\n", top_1, top_2, top_3, top_4, top_5);

    menu(detail, number_of_lines);
}

void distribution(Shop *detail, int number_of_lines)
{
    char search_category[MAX];
    printf("Enter category: ");
    scanf("%s", search_category);
    int count=0;
    for(int i=0;i<number_of_lines;i++){
        if(strcmp(search_category,detail[i].product_category)==0){
            count+=detail[i].quantity_sold;
        }
    }
    printf("Quantity sold: %s\n\n", count);

    menu(detail, number_of_lines);
}

void top_cities(Shop *detail, int number_of_lines)
{
    char search_country[MAX];
    printf("Enter country: ");
    scanf("%s", search_country);

    char top_city[MAX];
    double count_top_city=0;
    for(int i=0;i<number_of_lines;i++){
        if(strcmp(search_country,detail[i].sale_country)!=0){
            continue;
        }
        double count=0;
        for(int j=0;j<number_of_lines;j++){
            if(i>j && strcmp(detail[i].sale_city,detail[j].sale_city)==0){
                continue;
            }
            if(strcmp(detail[i].sale_city,detail[j].sale_city)==0){
                count+=detail[j].quantity_sold;
            }
        }
        if(count>count_top_city){
        count_top_city=count;
        strcpy(top_city, detail[i].sale_city);
        }
    }
    if(count_top_city==0){
        printf("You wrote the wrong country\n\n");
    }
    else{
        printf("The city with the biggest sold things from %s: %s\n\n",search_country, top_city);
    }

    menu(detail, number_of_lines);
}

void tendency(Shop *detail, int number_of_lines)
{
    char search_subcategory[MAX];
    char search_month_one[2];
    int count_month_one=0;
    char search_month_two[2];
    int count_month_two=0;
    printf("Enter subcategory: ");
    scanf("%s", search_subcategory);
    printf("Enter 2 different months (format MM): ");
    scanf("%s %s", search_month_one, search_month_two);
    for(int i=0;i<number_of_lines;i++){
        char data_i[10];
        strcpy(data_i, detail[i].data);
        char month_i[2];
        strncpy(month_i,data_i+3,2);
        if(strcmp(search_month_one,month_i)==0){
            count_month_one+=detail[i].quantity_sold;
        }
        else if(strcmp(search_month_two,month_i )==0){
            count_month_two+=detail[i].quantity_sold;
        }
    }
    if(count_month_one>count_month_two){
        printf("In month %s is selling more than month %s\n\n", search_month_one, search_month_two);
    }
    else{
        printf("In month %s is selling more than month %s\n\n", search_month_two, search_month_one);
    }

    menu(detail, number_of_lines);
}

void menu(Shop *detail, int number_of_lines)
{
    int select;
    printf("1 - Profit/month \n2 - Top 5 most profitable products \n3 - Distribution on category \n4 - Best city on every country \n5 - Tendency on subcategory \n6 - Quit\n\n");
    scanf("\n%d", &select);
    if(select==1){
        profit(detail, number_of_lines);
    }
    else if(select==2){
        top_products(detail, number_of_lines);
    }
    else if(select==3){
        distribution(detail, number_of_lines);
    }
    else if(select==4){
        top_cities(detail, number_of_lines);
    }
    else if(select==5){
        tendency(detail, number_of_lines);
    }
    else if(select==6){
        free(detail);
        exit(1);
    }
    else{
        printf("Wrong number");
        menu(detail, number_of_lines);
    }

}

int main()
{
    FILE* f = fopen("magazin.txt","r");

    int number_of_lines = count_lines(f);
    Shop *detail = malloc(number_of_lines*sizeof(Shop));

    if(f==NULL){
        printf("File not opened");
        exit(1);
    }


    for(int i=0;i<number_of_lines;i++){
        fscanf(f,"%s %d %s %s %s %lf %d %s %s", detail[i].data, &detail[i].id, detail[i].product_name, detail[i].product_category, detail[i].product_subcategory, &detail[i].unit_price, &detail[i].quantity_sold, detail[i].sale_country, detail[i].sale_city);
        detail[i].total_cost=detail[i].unit_price*detail[i].quantity_sold;
    }
    fclose(f);

    menu(detail, number_of_lines);
}
