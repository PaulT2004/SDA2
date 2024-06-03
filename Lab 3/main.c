#include <stdio.h>
#include <stdlib.h>

typedef struct node_of_binary_tree{
    int node_id;
    struct node_of_binary_tree *left;
    struct node_of_binary_tree *right;
}Node_of_binary_tree;

typedef struct binary_tree{
    Node_of_binary_tree *root;
}Binary_tree;

/**
* creates the binary tree
* @param none
* @return created binary tree
*/

Binary_tree *create_binary_tree(){
    Binary_tree *tree = malloc(sizeof(Binary_tree));
    tree->root=NULL;
    return tree;
}

/**
* creates a node in binary tree
* @param data inserted by user
* @return created node
*/

Node_of_binary_tree *create_node_of_binary_tree(int data){
    Node_of_binary_tree *node = malloc(sizeof(Node_of_binary_tree));
    node->node_id=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

/**
* adds the created node in binary tree, type search binary tree, compares recursively with other nodes to see where it should be put so it remains a search binary tree
* @param the created node and a current node for comparison
* @return none
*/

void add_node_in_binary_tree(Node_of_binary_tree *new_node, Node_of_binary_tree *current_node){
    if(current_node->node_id>new_node->node_id){
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
* calculates recursively the deep of the binary tree or a node inserted by user
* @param the root or a node inserted by user
* @return none
*/

int depth_of_binary_tree_or_node(Node_of_binary_tree *current_node){
    if(current_node==NULL){
        return 0;
    }
    else{
        int left_depth=depth_of_binary_tree_or_node(current_node->left);
        int right_depth=depth_of_binary_tree_or_node(current_node->right);
        if(left_depth>right_depth){
            return left_depth+1;
        }
        else{
            return right_depth+1;
        }
    }
}

/**
* searches recursively the node for using it on calculating the depth then it prints the depth of the node
* @param a node inserted by user
* @return none
*/

void search_node_for_depth(Binary_tree *tree, Node_of_binary_tree *current_node, int data){
    if(current_node!=NULL){
        if(current_node->node_id==data){
            int depth_node=depth_of_binary_tree_or_node(current_node);
            printf("The depth of node %d: %d\n\n", data, depth_node-1);
            main_menu(tree);
        }
        else{
            search_node_for_depth(tree, current_node->left, data);
            search_node_for_depth(tree, current_node->right, data);
        }
    }
}

/**
* calculates recursively the height of a node then it prints it
* @param the tree, a node inserted by user, the node the user wants to find and the depth of the tree
* @return none
*/

void height_of_node_of_binary_tree(Binary_tree *tree, Node_of_binary_tree *current_node, int data, int current_height, int max_depth){
    current_height++;
    if(current_node!=NULL){
        if(current_node->node_id==data){
            printf("The height of node %d: %d\n\n", data, max_depth-current_height);
            main_menu(tree);
        }
        else{
            height_of_node_of_binary_tree(tree, current_node->left, data, current_height, max_depth);
            height_of_node_of_binary_tree(tree, current_node->right, data, current_height, max_depth);
        }
    }
}

/**
* prints recursively the binary tree using vsd
* @param the root
* @return none
*/

void print_binary_tree(Node_of_binary_tree *current_node){
    if(current_node!=NULL){
        printf("%d, ", current_node->node_id);
        print_binary_tree(current_node->left);
        print_binary_tree(current_node->right);
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
* a menu in which the user decides what he wants to do
* @param needs the tree for using them in functions
* @return none
*/

void main_menu(Binary_tree *tree){
    int select_menu;
    printf("Main menu: \nInsert: \n1-The deep of the tree \n2-The deep of a node \n3-The height of a node \n4-Print the tree \n5-Clean the tree nodes\n6-Exit the program\n\n");
    scanf("\n%d", &select_menu);
    if(select_menu==1){
        if(tree->root!=NULL){
            int depth_root=depth_of_binary_tree_or_node(tree->root);
            printf("The depth of the binary tree: %d\n\n", depth_root-1);
            main_menu(tree);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree);
        }
    }
    else if(select_menu==2){
        if(tree->root!=NULL){
            int data;
            printf("Insert from which node do you want to know the depth: ");
            scanf("\n%d", &data);
            search_node_for_depth(tree, tree->root, data);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree);
        }
    }
    else if(select_menu==3){
        if(tree->root!=NULL){
            int max_depth=depth_of_binary_tree_or_node(tree->root);
            int data;
            printf("Insert from which node do you want to know the height: ");
            scanf("\n%d", &data);
            int current_height=0;
            height_of_node_of_binary_tree(tree, tree->root, data, current_height, max_depth);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree);
        }
    }
    else if(select_menu==4){
        if(tree->root!=NULL){
            printf("The tree nodes: ");
            print_binary_tree(tree->root);
            printf("\n\n");
            main_menu(tree);
        }
        else{
            printf("The binary tree is empty\n\n");
            main_menu(tree);
        }
    }
    else if(select_menu==5){
        if(tree->root!=NULL){
            clean_binary_tree(tree->root);
            tree->root=NULL;
            printf("Tree cleaned\n\n");
            main_menu(tree);
        }
        else{
            printf("The binary tree is already cleaned\n\n");
            main_menu(tree);
        }
    }
    else if(select_menu==6){
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
        main_menu(tree);
    }
}

/**
* the user inserts the number of nodes and what number he wants the node have, then it goes to main menu
* @param none
* @return none
*/

int main()
{

    Binary_tree *tree = create_binary_tree();

    int number_of_nodes;
    printf("Insert the number of nodes you want the tree have: ");
    scanf("\n%d", &number_of_nodes);

    for(number_of_nodes;number_of_nodes>0;number_of_nodes--){
        int data;
        printf("Insert the number you want your node have: ");
        scanf("\n%d", &data);
        Node_of_binary_tree *new_node = create_node_of_binary_tree(data);
        if(tree->root==NULL){
            tree->root=new_node;
        }
        else{
            add_node_in_binary_tree(new_node,tree->root);
        }
    }
    printf("\n");

    main_menu(tree);

    return 0;
}
