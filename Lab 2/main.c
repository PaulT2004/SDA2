#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STRING_LENGTH 20

typedef struct clothes{
    const int data;
    char category[MAX_STRING_LENGTH];
    char country[MAX_STRING_LENGTH];
    const int size;
    char color[MAX_STRING_LENGTH];
    const float price;
    struct clothes *next;
}Clothes;

typedef struct list{
    Clothes * head;
}List;

/**
* creates the list
* @param none
* @return created list
*/

List *create_list(){
    List *list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

/**
* creates a node
* @param none
* @return created node
*/

Clothes *create_node(){
    Clothes *node = malloc(sizeof(Clothes));
    printf("Introduceti tipul de imbracaminte, tara de origine, marimea, culoarea si pretul(float): ");
    scanf("%s %s %d %s %f", node->category, node->country, &node->size, node->color, &node->price);
    node->data=0;
    return node;
}

/**
* creates a node when it is used the push front function
* @param none
* @return created node
*/

Clothes *create_push_front_node(){
    Clothes * node = malloc(sizeof(Clothes));
    printf("Introduceti tipul de imbracaminte, tara de origine, marimea, culoarea si pretul: ");
    scanf("%s %s %d %s %f", node->category, node->country, &node->size, node->color, &node->price);
    node->data=0;
    node->next=NULL;
    return node;
}

/**
* prints all the nodes from the list and its content
* @param the list
* @return none
*/

void print_list(List *list){
    Clothes *current_node = list->head;
    if(list->head==NULL){
        printf("Lista e goala");
        main_menu(list);
    }
    while(current_node != NULL){
         printf("Tipul de imbracaminte: %s\nTara de origine: %s\nMarimea: %d\nCuloarea: %s\nPretul: %.2f\n\n", current_node->category, current_node->country, current_node->size, current_node->color, current_node->price);
         current_node=current_node->next;
    }
    main_menu(list);
}

/**
* search the node for working in push or pop functions
* @param the list
* @return the node position
*/

int search_list(List *list]){
    int count=1;
    int search_item;
    printf("Introduceti in care nod vreti sa lucrati: ");
    scanf("\n%d", &search_item);
    Clothes * current_node = list->head;
    while(current_node!=NULL){
        if(current_node->data==search_item){
            return count;
        }
        count++;
        current_node=current_node->next;
    }
    if(search_item==count){
        return count;
    }
    return -1;
}

/**
* search a item of a node inserted by user
* @param the list
* @return the node position
*/

int search_by_item(List *list){
    int count=1;
    int search_menu;
    printf("1-Cautare dupa marime \n2-Cautare dupa pret \n3-Cautare dupa categorie/tara/culoare\n\n");
    scanf("\n%d", &search_menu);
    if(search_menu==1){
        int search_item;
        printf("Introduceti marimea pe care o cautati: ");
        scanf("\n%d", &search_item);
        Clothes *current_node = list->head;
        while(current_node!=NULL){
            if(current_node->data==search_item){
                return count;
            }
            else if(current_node->size==search_item){
                return count;
            }
            count++;
            current_node=current_node->next;
        }
        return -1;
    }
    else if(search_menu==2){
        float search_item;
        printf("Introduceti pretul pe care o cautati: ");
        scanf("\n%f", &search_item);
        Clothes *current_node = list->head;
        while(current_node!=NULL){
            if(current_node->price==search_item){
                return count;
            }
            count++;
            current_node=current_node->next;
        }
        return -1;
    }
    else if(search_menu==3){
        char search_item[MAX_STRING_LENGTH];
        printf("Introduceti categoria/tara/culoarea pe care o cautati: ");
        scanf("\n%s", search_item);
        printf("%d\n", strlen(search_item));
        Clothes *current_node = list->head;
        while(current_node!=NULL){
            if(strcpy(current_node->category,search_item)==0){
                return count;
            }
            else if(strcpy(current_node->country,search_item)==0){
                return count;
            }
            else if(strcpy(current_node->color,search_item)==0){
                return count;
            }
            count++;
            current_node=current_node->next;
        }
        return -1;
    }
    else{
        return -2;
    }

}

/**
* prints the search results from search_by_item function
* @param the list for using it in search_by_item function
* @return none
*/

void search_result(List *list){
    int which_node = search_by_item(list);
    if(which_node==-1){
        printf("Elementul nu a fost gasit");
    }
    else if(which_node==-2){
        printf("Ati introdus un numar gresit la meniul de cautare");
    }
    else{
        printf("Elementul a fost gasit in nodul %d", which_node);
    }
    main_menu(list);
}

/**
* checks if the id matches the node position, if not, the node data is changed according to the node position
* @param the list
* @return none
*/

void sort_id(List *list){
    int counter=1;
    Clothes *current_node = list->head;
    while(current_node!= NULL) {
        if(current_node->data!=counter){
            current_node->data=counter;
        }
        counter++;
        current_node = current_node->next;
    }
}

/**
* adds a node at the beginning of the list
* @param the list
* @return none
*/

void push_front(List *list){
    Clothes *new_node = create_push_front_node();
    new_node->next = list->head;
    list->head = new_node;

    sort_id(list);
    main_menu(list);
}

/**
* adds a node at the end of the list
* @param the list
* @return none
*/

void push_back(List *list){

    Clothes *new_node = create_node();

    sort_id(list);
    main_menu(list);
}

/**
* the user inserts in which position he wants to add the node
* @param the list
* @return none
*/

void push_user(List *list){
    int insert_number = search_list(list);
    if(insert_number==-1){
        printf("Ati introdus in id invalid");
    }
    else if(insert_number==1){
        push_front(list);
    }
    else{
        Clothes *current_node = list->head;
        Clothes *previous_node;

        while(current_node->data != insert_number){
            previous_node = current_node;
            current_node = current_node->next;
        }
        if(current_node->next==NULL){
            push_back(list);
        }

        Clothes *new_node = create_node();
        new_node->next = current_node;
        previous_node->next = new_node;

        sort_id(list);
        main_menu(list);
    }
}

/**
* the user inserts in which position he wants to delete the node
* @param the list
* @return none
*/

void pop_user(List *list){
    int insert_number = search_list(list);
    if(insert_number==-1){
        printf("Ati introdus un numar invalid");

    }
    else if(insert_number==1){
        Clothes *old_node = list->head;
        list->head=old_node->next;
        free(old_node);

        sort_id(list);
        main_menu(list);

    }
    else{
        Clothes *old_node = list->head;
        Clothes *previous_node;
        for(int i=1;i<insert_number;i++){
            previous_node = old_node;
            old_node = previous_node->next;
        }
        if(old_node->next==NULL){
            previous_node->next = NULL;
            free(old_node);

            main_menu(list, data, category, country, size, color, price);
        }
        else{
            previous_node->next = old_node->next;
            free(old_node);

            sort_id(list);
            main_menu(list);
        }
    }
}

/**
* calculates and prints the inverted list
* @param the list
* @return none
*/

void inverted_list(List *list){
    Clothes *current_node = list->head;
    int find_max=0;
    while(current_node!=NULL){
        if(current_node->data>find_max){
            find_max=current_node->data;
        }
        current_node=current_node->next;
    }
    current_node = list->head;
    while(find_max>0){
        while(current_node!=NULL){
            if(current_node->data==find_max){
                printf("Tipul de imbracaminte: %s\nTara de origine: %s\nMarimea: %d\nCuloarea: %s\nPretul: %.2f\n\n", current_node->category, current_node->country, current_node->size, current_node->color, current_node->price);
            }
            current_node=current_node->next;
        }
        current_node = list->head;
        find_max--;
    }
    main_menu(list);
}

/**
* calculates and prints the list in ascending order according to one of the node item
* @param the list
* @return none
*/

void sort_list(List *list){
    int select_sort_list;
    printf("1-Dupa marime \n2-Dupa pret\n");
    scanf("\n%d", &select_sort_list);

    if(select_sort_list==1){
        Clothes *current_node=list->head;
        int increase_size=0;
        while(increase_size<100){
            while(current_node!=NULL){
                if(current_node->size==increase_size){
                    printf("Tipul de imbracaminte: %s\nTara de origine: %s\nMarimea: %d\nCuloarea: %s\nPretul: %.2f\n\n", current_node->category, current_node->country, current_node->size, current_node->color, current_node->price);
                }
                current_node=current_node->next;
            }
            current_node=list->head;
            increase_size++;
        }
        main_menu(list);
    }

    else if(select_sort_list==2){
        Clothes *current_node=list->head;
        float increase_price=0.00;
        while(increase_price<500){
            while(current_node!=NULL){
                if(fabs(current_node->price - increase_price) < 0.009){
                    printf("Tipul de imbracaminte: %s\nTara de origine: %s\nMarimea: %d\nCuloarea: %s\nPretul: %.2f\n\n", current_node->category, current_node->country, current_node->size, current_node->color, current_node->price);
                }
                current_node=current_node->next;
            }
            current_node=list->head;
            increase_price=increase_price+0.01;
        }
        main_menu(list);
    }

    else{
       printf("Ati introdus un numar invalid");
       main_menu(list);
    }
}

/**
* cleans the nodes of the list
* @param the list
* @return none
*/

void clean_list(List *list, ){
    Clothes *current_node = list->head;
    Clothes *next_node;
    while(current_node!=NULL){
        next_node=current_node->next;
        free(current_node);
        current_node=next_node;
    }
    list->head=NULL;
    main_menu(list);
}

/**
* a menu in which the user decides what he wants to do
* @param the list for using it in other functions
* @return none
*/

void main_menu(List *list){
    int select_menu;
    printf("\n\n1-Printeaza lista \n2-Cautarea unui element din lista \n3-Inserarea unui nod \n4-Stergerea unui nod \n5-Inversarea listei \n6-Curatirea listei \n7-Sortarea listei \n8-Iesire din program\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){
        print_list(list);
    }
    else if(select_menu==2){
        search_result(list);
    }
    else if(select_menu==3){
        push_user(list);
    }
    else if(select_menu==4){
        pop_user(list);
    }
    else if(select_menu==5){
        inverted_list(list);
    }
    else if(select_menu==6){
        clean_list(list);
    }
    else if(select_menu==7){
        sort_list(list);
    }
    else if(select_menu==8){
        free(list);
        exit(1);
    }
    else{
        printf("Ati pus alt numar");
        main_menu(list, data, category, country, size, color, price);
    }
}

/**
* creates the lists and adds a node on it
* @param none
* @return none
*/

int main()
{

    List * list = create_list();

    push_front(list);
    main_menu(list);

    return 0;
}
