#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_ARRAY_ONE 100
#define SIZE_ARRAY_TWO 1000
#define SIZE_ARRAY_THREE 10000
#define SIZE_ARRAY_FOUR 100000

/**
* adds or changes the numbers from arrays
* @param the arrays
* @return none
*/

void add_numbers_in_array(int *array_one, int *array_two, int *array_three, int *array_four){
    srand(time(NULL));
    for(int i=0; i<SIZE_ARRAY_ONE; i++){
        array_one[i]=rand()%10000+1;
    }
    for(int i=0; i<SIZE_ARRAY_TWO; i++){
        array_two[i]=rand()%10000+1;
    }
    for(int i=0; i<SIZE_ARRAY_THREE; i++){
        array_three[i]=rand()%10000+1;
    }
    for(int i=0; i<SIZE_ARRAY_FOUR; i++){
        array_four[i]=rand()%10000+1;
    }
}

/**
* prints the arrays
* @param the arrays
* @return none
*/

void print_array(int *array_one, int *array_two, int *array_three, int *array_four){

    printf("100-number array: \n");
    for(int i=0; i<SIZE_ARRAY_ONE; i++){
        printf("%d\n", array_one[i]);
    }

    printf("\n1000-number array: \n");
    for(int i=0; i<SIZE_ARRAY_TWO; i++){
        printf("%d\n", array_two[i]);
    }

    printf("\n10k-number array: \n");
    for(int i=0; i<SIZE_ARRAY_THREE; i++){
        printf("%d\n", array_three[i]);
    }

    printf("\n100k-number array: \n");
    for(int i=0; i<SIZE_ARRAY_FOUR; i++){
        printf("%d\n", array_four[i]);
    }
    main_menu(array_one, array_two, array_three, array_four);
}

/**
* sorts the array using bubble sort
* @param the current array and its size
* @return none
*/

void bubble_sort(int *array, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

/**
* switches the numbers from an array if necessarily
* @param the current array
* @return the switched (or non-switched) numbers
*/

int switch_quick_sort(int *array, int low_number, int high_number){
    int temp=array[high_number];
    int temp_switch;
    int i=(low_number-1);
    for(int j=low_number;j<=high_number;j++){
        if(array[j]<temp){
            i++;
            temp_switch=array[i];
            array[i]=array[j];
            array[j]=temp_switch;
        }
    }
    temp_switch=array[i+1];
    array[i+1]=array[high_number];
    array[high_number]=temp_switch;
    return i+1;
}

/**
* sorts the array using quick sort
* @param the arrays
* @return none
*/

void quick_sort(int *array, int low_number, int high_number){
    if(low_number<high_number){
        int temp=switch_quick_sort(array, low_number, high_number);

        quick_sort(array, low_number, temp-1);
        quick_sort(array, temp+1, high_number);
    }
}

/**
* sorts and tracks how much time it requires to sort for different methods and sizes of array
* @param the arrays
* @return none
*/

void sorting_array(int *array_one, int *array_two, int *array_three, int *array_four){
    clock_t start_sorting, finish_sorting;
    float time_required;

    printf("Bubble sort: \n");

    start_sorting=clock();
    bubble_sort(array_one, SIZE_ARRAY_ONE);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting an 100-number array: %.3f\n", time_required);

    start_sorting=clock();
    bubble_sort(array_two, SIZE_ARRAY_TWO);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting an 1000-number array: %.3f\n", time_required);

    start_sorting=clock();
    bubble_sort(array_three, SIZE_ARRAY_THREE);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting a 10k-number array: %.3f\n", time_required);

    start_sorting=clock();
    bubble_sort(array_four, SIZE_ARRAY_FOUR);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting an 100k-number array: %.3f\n\n", time_required);

    add_numbers_in_array(array_one, array_two, array_three, array_four);

    printf("Quick sort: \n");

    start_sorting=clock();
    quick_sort(array_one, 0, SIZE_ARRAY_ONE-1);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting an 100-number array: %.3f\n", time_required);

    start_sorting=clock();
    quick_sort(array_two, 0, SIZE_ARRAY_TWO-1);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting an 1000-number array: %.3f\n", time_required);

    start_sorting=clock();
    quick_sort(array_three, 0, SIZE_ARRAY_THREE-1);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting a 10k-number array: %.3f\n", time_required);

    start_sorting=clock();
    quick_sort(array_four, 0, SIZE_ARRAY_FOUR-1);
    finish_sorting=clock();

    time_required=(float)(finish_sorting-start_sorting)/CLOCKS_PER_SEC;
    printf("Time required for sorting an 100k-number array: %.3f\n\n", time_required);

    add_numbers_in_array(array_one, array_two, array_three, array_four);
}

/**
* a sorting menu in which the user decides what he wants to do
* @param needs the arrays for using them in functions
* @return none
*/

void sorting_menu(int *array_one, int *array_two, int *array_three, int *array_four){
    int select_menu;
    printf("Main menu: \nInsert: \n1-Printing array \n2-Sorting and calculating time required \n3-Go to main menu\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){
        print_array(array_one, array_two, array_three, array_four);
        sorting_menu(array_one, array_two, array_three, array_four);
    }
    else if(select_menu==2){
        sorting_array(array_one, array_two, array_three, array_four);
        sorting_menu(array_one, array_two, array_three, array_four);
    }
    else if(select_menu==3){
        main_menu(array_one, array_two, array_three, array_four);
    }
    else{
        printf("You inserted another number\n\n");
        sorting_menu(array_one, array_two, array_three, array_four);
    }
}



/**
* searches a number by using linear search method
* @param needs the tree for using them in functions
* @return the found number
*/

int linear_search(int *array, int size, int data){
    for(int i=0; i<size; i++){
        if(array[i]==data){
            return i;
        }
    }
    return -1;
}

/**
* searches a number by using binary search method
* @param needs the tree for using them in functions
* @return the found number
*/

int binary_search(int *array, int low_count, int high_count, int data){
    while(low_count<=high_count){
        int middle=low_count+(high_count-low_count)/2;
        if(array[middle]==data){
            return middle;
        }
        else if(array[middle]<data){
            low_count=middle+1;
        }
        else{
            high_count=middle-1;
        }
    }
    return -1;
}

/**
* sorts and tracks how much time it requires to search 10k times for different methods and sizes of array
* @param the arrays
* @return none
*/

void searching_array(int *array_one, int *array_two, int *array_three, int *array_four){
    clock_t start_searching, finish_searching;
    float time_required;

    printf("Linear search: \n");

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=linear_search(array_one, SIZE_ARRAY_ONE, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on an 100-number array: %.3f\n", time_required);

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=linear_search(array_two, SIZE_ARRAY_TWO, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on an 1000-number array: %.3f\n", time_required);

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=linear_search(array_three, SIZE_ARRAY_THREE, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on a 10k-number array: %.3f\n", time_required);

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=linear_search(array_four, SIZE_ARRAY_FOUR, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on an 100k-number array: %.3f\n\n", time_required);

    printf("Binary search: \n");

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=binary_search(array_one, 0, SIZE_ARRAY_ONE, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on an 100-number array: %.3f\n", time_required);

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=binary_search(array_two, 0, SIZE_ARRAY_TWO, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on an 1000-number array: %.3f\n", time_required);

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=binary_search(array_three, 0, SIZE_ARRAY_THREE, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on a 10k-number array: %.3f\n", time_required);

    start_searching=clock();
    for(int times_searched=1; times_searched<=10000; times_searched++){
        int data=rand()%10000+1;
        int result=binary_search(array_four, 0, SIZE_ARRAY_FOUR, data);
    }
    finish_searching=clock();

    time_required=(float)(finish_searching-start_searching)/CLOCKS_PER_SEC;
    printf("Time required for searching 10k times on an 100k-number array: %.3f\n\n", time_required);
}

/**
* a searching menu in which the user decides what he wants to do
* @param needs the arrays for using them in functions
* @return none
*/

void searching_menu(int *array_one, int *array_two, int *array_three, int *array_four){
    int select_menu;
    printf("Main menu: \nInsert: \n1-Printing array \n2-Sorting and calculating time required \n3-Go to main menu\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){
        print_array(array_one, array_two, array_three, array_four);
        searching_menu(array_one, array_two, array_three, array_four);
    }
    else if(select_menu==2){
        searching_array(array_one, array_two, array_three, array_four);
        searching_menu(array_one, array_two, array_three, array_four);
    }
    else if(select_menu==3){
        main_menu(array_one, array_two, array_three, array_four);
    }
    else{
        printf("You inserted another number\n\n");
        searching_menu(array_one, array_two, array_three, array_four);
    }
}

/*
void calculate_fibo(){

}
*/

/**
* a menu in which the user decides what he wants to do
* @param needs the tree for using them in functions
* @return none
*/

/*
void fibonacci_menu(int *array_one, int *array_two, int *array_three, int *array_four){
    int select_menu;
    printf("Main menu: \nInsert: \n1-Find a random N fibo term \n2-Calculating the time required to find fibo with different N terms \n3-Go to main menu\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){

    }
    else if(select_menu==2){

    }
    else if(select_menu==3){
        main_menu(&array_one, &array_two, &array_three, &array_four);
    }
    else{
        printf("You inserted another number\n\n");
        fibonacci_menu(&array_one, &array_two, &array_three, &array_four);
    }
}
*/

/**
* a menu in which the user decides what he wants to do
* @param needs the arrays for using them in functions
* @return none
*/

void main_menu(int *array_one, int *array_two, int *array_three, int *array_four){
    int select_menu;
    printf("Main menu: \nInsert: \n1-Sorting an array in ascending order \n2-Searching a number \n3-Calculate Fibonacci \n4-Exit the program\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){
        sorting_menu(array_one, array_two, array_three, array_four);
    }
    else if(select_menu==2){
        searching_menu(array_one, array_two, array_three, array_four);
    }
    /*
    else if(select_menu==3){
        fibonacci_menu(&array_one, &array_two, &array_three, &array_four);
    }
    */
    else if(select_menu==4){
        free(array_one);
        free(array_two);
        free(array_three);
        free(array_four);
        exit(1);
    }
    else{
        printf("You inserted another number\n\n");
        main_menu(array_one, array_two, array_three, array_four);
    }
}



int main()
{
    int *array_one=malloc(SIZE_ARRAY_ONE*sizeof(int));
    int *array_two=malloc(SIZE_ARRAY_TWO*sizeof(int));
    int *array_three=malloc(SIZE_ARRAY_THREE*sizeof(int));
    int *array_four=malloc(SIZE_ARRAY_FOUR*sizeof(int));
    if(array_one==NULL || array_two==NULL || array_three==NULL || array_four==NULL){
        printf("FAILED");
        exit(1);
    }

    add_numbers_in_array(array_one, array_two, array_three, array_four);
    main_menu(array_one, array_two, array_three, array_four);
    return 0;
}
