#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 20

typedef struct person{
    char name[MAX_STRING_LENGTH];
    char surname[MAX_STRING_LENGTH];
    int age;
}Person;


typedef struct node{
    int key;
    Person *person;
    struct node *left;
    struct node *right;
}Node;

typedef struct binaryTree{
    Node *root;
}BinaryTree;

/**
* creates the binary tree
* @param none
* @return created binary tree
*/

BinaryTree *create_tree(){
    BinaryTree *tree = malloc(sizeof(Binarytree));
    tree->root=NULL;
    return tree;
}

/**
* creates a node in binary tree
* @param data inserted by user
* @return created node
*/

Node *create_node(){
    Node *node = malloc(sizeof(Node));
    printf("Insert node number, a name, a surname and an age: ");
    scanf("%d %s %s %d", &node->key, node->name, node->surname, &node->age);
    node->left=NULL;
    node->right=NULL;
    return node;
}

/**
* adds the created node in binary tree, type search binary tree, compares recursively with other nodes to see where it should be put so it remains a search binary tree
* @param the created node and a current node for comparison
* @return none
*/

void add_node(Node *new_node, Node *current_node){
    if(current_node->key>new_node->key){
        if(current_node->left==NULL){
            current_node->left=new_node;
        }
        else{
            add_node_in_binary_tree(new_node, current_node->left);
        }
    }
    else{
        if(current_node->right==NULL){
            current_node->right=new_node;
        }
        else{
            add_node_in_binary_tree(new_node, current_node->right);
        }
    }
}

/**
* prints recursively the binary tree using vsd which also prints it via dfs method
* @param the root
* @return none
*/

void print_vsd_and_print_dfs(Node *current_node){
    if(current_node!=NULL){
        printf("ID: %d\nName: %s\nSurname: %s\nAge: %d\n\n", current_node->key, current_node->name, current_node->surname, current_node->age);
        print_vsd_and_print_dfs(current_node->left);
        print_vsd_and_print_dfs(current_node->right);
    }
}

/**
* prints recursively the binary tree using svd
* @param the root
* @return none
*/

void print_svd(Node *current_node){
    if(current_node!=NULL){
        print_svd(current_node->left);
        printf("ID: %d\nName: %s\nSurname: %s\nAge: %d\n\n", current_node->key, current_node->name, current_node->surname, current_node->age);
        print_svd(current_node->right);
    }
}

/**
* prints recursively the binary tree using sdv
* @param the root
* @return none
*/

void print_sdv(Node *current_node){
    if(current_node!=NULL){
        print_sdv(current_node->left);
        print_sdv(current_node->right);
        printf("ID: %d\nName: %s\nSurname: %s\nAge: %d\n\n", current_node->key, current_node->name, current_node->surname, current_node->age);
    }
}

/**
* creates the binary tree
* @param the current node and id inserted by user
* @return the found node or null
*/

Node *search_node(Node *current_node, int node_id){
    if(current_node!=NULL){
        if(current_node->key==node_id){
            return current_node;
        }
        else if(current_node->key>node_id){
            return search_node(current_node->left, node_id);
        }
        else{
            return search_node(current_node->right, node_id);
        }
    }
    else{
        return NULL;
    }
}

/**
* calculates recursively the deep of the binary tree or a node inserted by user
* @param the root
* @return the depth of the tree
*/

int depth(Node *current_node){
    if(current_node==NULL){
        return 0;
    }
    else{
        int left_depth=depth_of_binary_tree(current_node->left);
        int right_depth=depth_of_binary_tree(current_node->right);
        if(left_depth>right_depth){
            return left_depth+1;
        }
        else{
            return right_depth+1;
        }
    }
}

/**
* finds the highest key of a node
* @param the root
* @return the highest key node
*/

int find_highest_id_node(Node *current_node){
    if(current_node->left==NULL && current_node->right==NULL){
        return current_node->key;
    }
    else{
        return find_highest_id_node(current_node->right);
    }
}

/**
* finds the nodes and adds it to the matrix for printing bfs
* @param the current node, a matrix for adding nodes on it and the current height
* @return none
*/

void find_bfs(Node *current_node, int max_depth, int max_id_node, int matrix[max_depth][max_id_node], int current_height){
    if(current_node!=NULL){
        current_height++;
        int node_number=current_node->key;
        matrix[current_height][node_number-1]=1;
        find_bfs(current_node->left, max_depth, max_id_node, matrix, current_height);
        find_bfs(current_node->right, max_depth, max_id_node, matrix, current_height);
    }
}

/**
* prints the bfs
* @param the tree
* @return none
*/

void print_bfs(BinaryTree *tree){
    int max_depth=depth_of_binary_tree(tree->root);
    int max_id_node=find_highest_id_node(tree->root);
    int matrix[max_depth][max_id_node];
    for(int i=0;i<max_depth;i++){
        for(int j=0;j<max_id_node;j++){
            matrix[i][j]=0;
        }
    }

    int current_height=-1;
    find_bfs(tree->root, max_depth, max_id_node, matrix, current_height);

    for(int i=0;i<max_depth;i++){
        printf("Height %d:\n\n", i+1);
        for(int j=0;j<max_id_node;j++){
            if(matrix[i][j]==1){
                int node_id=j+1;
                Node *get_node=search_node(tree->root, node_id);
                printf("ID: %d\nName: %s\nSurname: %s\nAge: %d\n\n\n", get_node->key, get_node->name, get_node->surname, get_node->age);
            }
        }
    }

}

/**
* cleans the nodes of the binary tree
* @param the root
* @return none
*/

void clean_binary_tree(Node_of_binary_tree *current_node){
    if(current_node!=NULL){
        clean_binary_tree(current_node->left);
        clean_binary_tree(current_node->right);
        free(current_node);
    }
}

/**
* adds the key nodes into a new array to be able to do the balance for the tree
* @param a node and an array
* @return none
*/

void add_nodes_to_array(Node_of_binary_tree *current_node, int number_of_nodes, int array[number_of_nodes]){
    if(current_node!=NULL){
        add_nodes_to_array(current_node->left, number_of_nodes, array);
        for(int i=0;i<number_of_nodes;i++){
            if(array[i]==0){
                array[i]=current_node->key;
            }
        }
        add_nodes_to_array(current_node->right, number_of_nodes, array);
    }
}

/**
* recursively finds the middle number of the current array for tree balancing, then splits into 2 new arrays without the middle one, it repeats until it can't be longer splited
* @param the current tree, the new tree and the current array
* @return none
*/


void recursive_balance_binary_tree(BinaryTree *tree, Binary_tree *new_tree, int array[], int number_of_nodes){
    int data=sizeof(array);
    if(data==2){
        int node_id=array[1];
        Node *new_node=search_node(tree->root, node_id);
        add_node(new_node,new_tree->root);
    }
    else if(data==1){
        int node_id=array[0];
        Node *new_node=search_node(tree->root, node_id);
        add_node(new_node, new_tree->root);
    }
    else{
        int *split_array=malloc(1*sizeof(int));
        split_array[0]=array[0];
        recursive_balance_binary_tree(tree, new_tree, split_array, number_of_nodes);
    }
    if(data%2==1){
        data=number_of_nodes/2;
        int node_id=array[data];
        Node *new_node=search_node(tree->root, node_id);
        add_node(new_node,new_tree->root);
        int *split_array_first_half=malloc(data*sizeof(int));
        int *split_array_second_half=malloc(data*sizeof(int));
        for(int i=0;i<data;i++){
            split_array_first_half[i]=array[i];
        }
        for(int i=0;i<data;i++){
            split_array_second_half[i]=array[i+data+1];
        }
        recursive_balance_binary_tree(tree, new_tree, split_array_first_half, number_of_nodes);
        recursive_balance_binary_tree(tree, new_tree, split_array_second_half, number_of_nodes);
    }
    else{
        data=number_of_nodes/2;
        int node_id=array[data];
        Node_of_binary_tree *new_node=search_node(tree->root, node_id);
        new_tree->root=new_node;
        int *split_array_first_half=malloc(data*sizeof(int));
        int *split_array_second_half=malloc(data-1*sizeof(int));
        for(int i=0;i<data;i++){
            split_array_first_half[i]=array[i];
        }
        for(int i=0;i<data-1;i++){
            split_array_second_half[i]=array[i+data+1];
        }

        recursive_balance_binary_tree(tree, new_tree, split_array_first_half, number_of_nodes);
        recursive_balance_binary_tree(tree, new_tree, split_array_second_half, number_of_nodes);
    }
}

/**
* creates a new tree, then it goes to the recursive function for creating the new tree, after it, the old tree gets cleaned and deleted
* @param the current tree
* @return none
*/

void balance_binary_tree(Binary_tree *tree, int number_of_nodes){
    int array[number_of_nodes];
    for(int i=0;i<number_of_nodes;i++){
        array[i]=0;
    }
    add_nodes_to_array(tree->root, number_of_nodes, array);

    Binary_tree *new_tree = create_binary_tree();
    if(number_of_nodes%2==1){
        int data=number_of_nodes/2;
        int node_id=array[data];
        Node_of_binary_tree *new_node=search_node(tree->root, node_id);
        new_tree->root=new_node;
        int *split_array_first_half=malloc(data*sizeof(int));
        int *split_array_second_half=malloc(data*sizeof(int));
        for(int i=0;i<data;i++){
            split_array_first_half[i]=array[i];
        }
        for(int i=0;i<data;i++){
            split_array_second_half[i]=array[i+data+1];
        }
        recursive_balance_binary_tree(tree, new_tree, split_array_first_half, number_of_nodes);
        recursive_balance_binary_tree(tree, new_tree, split_array_second_half, number_of_nodes);
    }
    else{
        int data=number_of_nodes/2;
        int node_id=array[data];
        Node_of_binary_tree *new_node=search_node(tree->root, node_id);
        new_tree->root=new_node;
        int *split_array_first_half=malloc(data*sizeof(int));
        int *split_array_second_half=malloc(data-1*sizeof(int));
        for(int i=0;i<data;i++){
            split_array_first_half[i]=array[i];
        }
        for(int i=0;i<data-1;i++){
            split_array_second_half[i]=array[i+data+1];
        }

        recursive_balance_binary_tree(tree, new_tree, split_array_first_half, number_of_nodes);
        recursive_balance_binary_tree(tree, new_tree, split_array_second_half, number_of_nodes);
    }

    clean_binary_tree(tree->root);
    free(tree);

    main_menu(new_tree, number_of_nodes);
}



/**
* a menu in which the user decides what he wants to do
* @param needs the tree and the total number of nodes for using them in functions
* @return none
*/

void main_menu(Binary_tree *tree, int number_of_nodes){
    int select_menu;
    printf("Main menu: \nInsert: \n1-Search node \n2-Print VSD (DFS) \n3-Print SVD \n4-Print SDV \n5-Print BFS \n6-Balance the binary tree \n7-Clean the binary tree \n8-Exit the program\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){
        if(tree->root!=NULL){
            int node_id;
            printf("Insert which node do you want to search: ");
            scanf("\n%d", &node_id);
            Node_of_binary_tree *node=search_node(tree->root,node_id);
            if(node!=NULL){
                printf("ID: %d\nName: %s\nSurname: %s\nAge: %d\n\n", node->key, node->name, node->surname, node->age);
                main_menu(tree, number_of_nodes);
            }
            else{
                printf("Node not found\n\n");
                main_menu(tree, number_of_nodes);
            }
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree, number_of_nodes);
        }
    }
    else if(select_menu==2){
        if(tree->root!=NULL){
            print_vsd_and_print_dfs(tree->root);
            main_menu(tree, number_of_nodes);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree, number_of_nodes);
        }
    }
    else if(select_menu==3){
        if(tree->root!=NULL){
            print_svd(tree->root);
            main_menu(tree, number_of_nodes);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree, number_of_nodes);
        }
    }
    else if(select_menu==4){
        if(tree->root!=NULL){
            print_sdv(tree->root);
            main_menu(tree, number_of_nodes);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree, number_of_nodes);
        }
    }
    else if(select_menu==5){
        if(tree->root!=NULL){
            print_bfs(tree);
            main_menu(tree, number_of_nodes);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree, number_of_nodes);
        }
    }
    else if(select_menu==6){
        if(tree->root!=NULL){
            balance_binary_tree(tree, number_of_nodes);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree, number_of_nodes);
        }
    }
    else if(select_menu==7){
        if(tree->root!=NULL){
            clean_binary_tree(tree->root);
            tree->root=NULL;
            printf("Tree cleaned\n\n");
            main_menu(tree, number_of_nodes);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree, number_of_nodes);
        }
    }
    else if(select_menu==8){
        //deletes the binary tree and exit the program
        if(tree->root!=NULL){
            clean_binary_tree(tree->root);
            free(tree);
            printf("Binary tree roots and tree itself deleted\n");
            exit(1);
        }
        else{
            free(tree);
            printf("Binary tree deleted\n");
            exit(1);
        }
    }
    else{
        printf("You inserted another number\n\n");
        main_menu(tree, number_of_nodes);
    }
}

int main()
{
    Binary_tree *tree = create_binary_tree();

    int number_of_nodes;
    printf("Insert the number of nodes you want the tree have: ");
    scanf("\n%d", &number_of_nodes);

    for(number_of_nodes;number_of_nodes>0;number_of_nodes--){
        Node_of_binary_tree *new_node = create_node_of_binary_tree();
        if(tree->root==NULL){
            tree->root=new_node;
        }
        else{
            add_node_in_binary_tree(new_node, tree->root);
        }
    }
    printf("\n");

    main_menu(tree, number_of_nodes);

    return 0;
}
