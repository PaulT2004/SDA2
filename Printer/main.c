#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 30

typedef struct document{
    int document_id;
    char document_name[MAX_STRING_LENGTH];
    int total_lines;
    int remaining_lines;
    struct document *next;
}Document;

typedef struct document_list{
    Document *head;
}Document_list;

typedef struct printer{
    int printer_id;
    int printing_per_second;
    Document *printing_document;
    struct printer *next;
}Printer;

typedef struct printer_list{
    Printer *head;
}Printer_list;

/**
* creates the list for documents
* @param none
* @return created list
*/

Document_list *create_document_list(){
    Document_list *document_list = malloc(sizeof(Document_list));
    document_list->head = NULL;
    return document_list;
}

/**
* creates the list for printers
* @param none
* @return created list
*/

Printer_list *create_printer_list(){
    Printer_list *printer_list = malloc(sizeof(Printer_list));
    printer_list->head = NULL;
    return printer_list;
}

/**
* creates a node for documents
* @param a counter for document id
* @return created node
*/

Document *create_document_node(int document_counter){
    Document* node = malloc(sizeof(Document));

    node->document_id=document_counter;
    printf("Enter document name: ");
    scanf("%s", node->document_name);
    node->total_lines=rand()%16+10;
    node->remaining_lines=node->total_lines;
    node->next=NULL;
    return node;
}

/**
* creates a node for printers
* @param a counter for printer id
* @return created node
*/

Printer *create_printer_node(int printer_counter){
    Printer* node = malloc(sizeof(Printer));

    node->printer_id=printer_counter;
    node->printing_per_second=rand()%16+5;
    node->printing_document=NULL;
    node->next=NULL;
    return node;
}

/**
* adds the created node for documents into the document list
* @param the list and a counter for create_document_node function
* @return none
*/

void push_document(Document_list *document_list, int document_counter){
    Document *new_node = create_document_node(document_counter);
    new_node->next = document_list->head;
    document_list->head = new_node;
}

/**
* adds the created node for printers into the printer list
* @param the list and a counter for create_document_node function
* @return none
*/

void push_printer(Printer_list *printer_list, int printer_counter){
    Printer *new_node = create_printer_node(printer_counter);
    new_node->next = printer_list->head;
    printer_list->head = new_node;
}

/**
* distribute documents to printers
* @param both document and printer lists
* @return none
*/

void printer_distribution(Document_list *document_list, Printer_list *printer_list){
    Document *current_document_node=document_list->head;
    Printer *current_printer_node=printer_list->head;
    int count=0;

    int max_document_size=0;
    while(current_document_node!=NULL){
        if(current_document_node->total_lines==current_document_node->remaining_lines && current_document_node->total_lines>max_document_size){
            max_document_size=current_document_node->total_lines;
        }
        current_document_node=current_document_node->next;
    }
    current_document_node=document_list->head;

    int max_printer_size=0;
    while(current_printer_node!=NULL){
        if(current_printer_node->printing_document==NULL && current_printer_node->printing_per_second>max_printer_size){
            max_printer_size=current_printer_node->printing_per_second;
        }
        current_printer_node=current_printer_node->next;
    }
    current_printer_node=printer_list->head;

    printf("%d, %d\n", max_document_size, max_printer_size);
    printf("1\n");
    while(current_printer_node!=NULL){
        printf("2\n");
        if(max_document_size>0 && current_printer_node->printing_per_second==max_printer_size){
            printf("3\n");
            while(current_document_node!=NULL){
                printf("4\n");
                if(current_document_node->total_lines==max_document_size){
                    printf("5\n");
                    current_printer_node->printing_document=current_document_node;
                }
            current_document_node=current_document_node->next;
            }
        }
        current_printer_node=current_printer_node->next;
    }
}

/**
* prints the both lists
* @param both lists
* @return none
*/

void print_lists(Document_list *document_list, Printer *current_printer_node){
    Document *current_document_node=document_list->head;
    int count_documents=0;
    while(current_document_node!=NULL){
         count_documents++;
         current_document_node=current_document_node->next;
    }
    current_document_node=document_list->head;

    printf("Number of available documents: %d\n", count_documents);

    while(current_document_node!=NULL){
         printf("Document ID: %d\nDocument name: %s\nTotal lines: %d\nLines left: %d\n\n", current_document_node->document_id, current_document_node->document_name, current_document_node->total_lines, current_document_node->remaining_lines);
         current_document_node=current_document_node->next;
    }

    while(current_printer_node!=NULL){
        if(current_printer_node->printing_document!=NULL){
            printf("Printer ID: %d\nPrinting per second: %d\n: %d\nCurrent printing document: %s\n\n", current_printer_node->printer_id, current_printer_node->printing_per_second, current_printer_node->printing_document);
        }
        else{
            printf("Printer ID: %d\nPrinting per second: %d\nCurrent printing document: none\n\n", current_printer_node->printer_id, current_printer_node->printing_per_second);
        }
        current_printer_node=current_printer_node->next;
    }
}

/**
* removes a document when all of his pages got printed, if no documents left, it cleans the document list if no more documents available
* @param the document list and the fully printed document
* @return none
*/

void pop_document(Document_list *document_list, Document *current_node){
    Document *old_node = document_list->head;
    Document *previous_node;
    int nodes_left=0;
    while(old_node->document_id!=current_node->document_id){
        nodes_left++;
        previous_node = old_node;
        old_node = previous_node->next;
    }
    if(old_node->next==NULL && nodes_left==0){
        free(old_node);
        document_list->head=NULL;
    }

    if(old_node->next==NULL){
        previous_node->next = NULL;
        free(old_node);
    }
    else{
        previous_node->next = old_node->next;
        free(old_node);
    }
}

/**
* prints the document according to the print power, after that, checks if all printers are empty and if there are no documents left, if yes, it exits the program, if not, the remained documents are added into printers
* @param both lists
* @return none
*/

void printer_execution(Document_list *document_list, Printer_list *printer_list){
    Printer *current_printer_node=printer_list->head;
    while(current_printer_node!=NULL){
        if(current_printer_node->printing_document!=NULL){
            current_printer_node->printing_document->remaining_lines=current_printer_node->printing_document->remaining_lines-current_printer_node->printing_per_second;
        }
        current_printer_node=current_printer_node->next;
    }
    current_printer_node=printer_list->head;

    int count_printers=0;
    int count_zero_pages_left=0;
    while(current_printer_node!=NULL){
        count_printers++;
        if(current_printer_node->printing_document==NULL){
            count_zero_pages_left++;
        }
        else if(current_printer_node->printing_document->remaining_lines<=0){
            pop_document(document_list, current_printer_node->printing_document);
            current_printer_node->printing_document=NULL;
            count_zero_pages_left++;
        }
        current_printer_node=current_printer_node->next;
    }
    current_printer_node=printer_list->head;

    if(count_printers==count_zero_pages_left && document_list->head==NULL){
        printf("No documents left, printers are empty");
        exit(1);
    }
    else{
        while(current_printer_node!=NULL){
            if(document_list->head!=NULL && current_printer_node->printing_document==NULL){
                printer_distribution(document_list,printer_list);
            }
        }
    }
}

/**
* a menu in which the user decides what he wants to do
* @param both lists for using them in different functions and a count as an unique id to be used when the user wants to add a new document
* @return none
*/

void main_menu(Document_list *document_list, Printer_list *printer_list, int count_document){
    int select_menu;
    printf("Main menu: \nInsert: \n1-Add a new document \n2-Show all printers and available documents \n3-Print\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){
        count_document++;
        push_document(document_list, count_document);
        main_menu(document_list, printer_list, count_document);
    }
    else if(select_menu==2){
        print_lists(document_list, printer_list->head);
        main_menu(document_list, printer_list, count_document);
    }
    else if(select_menu==3){
        printer_execution(document_list, printer_list);
        main_menu(document_list, printer_list, count_document);
    }
    else{
        printf("You inserted another number\n\n");
        main_menu(document_list, printer_list, count_document);
    }
}

/**
* firstly creates the lists, then adds nodes on random amount, then it puts the documents to printers, then goes to main menu
* @param both lists for using them in different functions and a count as an unique id to be used when the user wants to add a new document
* @return none
*/

int main()
{
    srand(time(NULL));
    Document_list * document_list = create_document_list();
    Printer_list * printer_list = create_printer_list();

    int count_document=0;
    int number_of_documents=rand()%7+4;
    while(number_of_documents>count_document){
        count_document++;
        push_document(document_list, count_document);
    }
    int count_printer=0;
    int number_of_printers=rand()%5+2;
    while(number_of_printers>count_printer){
        count_printer++;
        push_printer(printer_list, count_printer);
    }

    while(count_printer>0){
        printer_distribution(document_list, printer_list);
        count_printer--;
    }

    main_menu(document_list,printer_list,count_document);

    return 0;
}
