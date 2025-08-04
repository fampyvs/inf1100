#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define the struct node
// https://www.geeksforgeeks.org/how-to-create-a-linked-list-in-c/
// Copy from geeksforgeeks.
typedef struct Node { 
    void *data;
    struct Node *next;
} Node;

// Define the struct list
// For reference: https://www.geeksforgeeks.org/how-to-create-a-linked-list-in-c/
typedef struct list {
    struct Node *head;
    struct Node *tail;
} list_t;

/*
 * Returns a newly created, empty list.
 */
// https://www.geeksforgeeks.org/how-to-create-a-linked-list-in-c/
// Mostly as a reference, some things are copies from geeksforgeeks
list_t *list_create(void) { 
    // Allocating memory, and checking if it was successful
    list_t *new_list = malloc(sizeof(list_t)); // From geeksforgeeks, copy
    if (new_list == NULL) { // Got this from a youtube video, cant find it
        return NULL;
    }
    // Initializing the new list by setting head and tail to NULL. Geeksforgeeks mostly as reference.
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

/*
 * Frees the list; list and nodes, but not the items it holds.
 */
// https://stackoverflow.com/questions/6417158/c-how-to-free-nodes-in-the-linked-list
// Copy from stackoverflow, Author: insumity
void list_destroy(list_t *list) { 
    // Want to prevent the function from attemting to access memory that has not been allocated.
    if (list != NULL) { // Got all of these list != NULL from a youtube video, cant find it :(
        Node *current = list->head;
        Node *next;
        // Check for when you get to the end. Iterate through the list, free current. 
        // Set current to the next node
        while (current != NULL) { // Code by: insumity
            next = current->next;
            free(current);
            current = next;
        }
    }
    free(list);
}

/*
 * Adds an item first in the provided list.
 */
// https://www.geeksforgeeks.org/insert-a-node-at-front-beginning-of-a-linked-list/
// Code gotten from geeksforgeeks. Mostly
void list_addfirst(list_t *list, void *item) { 
    if (list == NULL) { // Same here, got it from a youtube video, cant find it.
        printf("list_addfirst: List is NULL\n");
        return;
    }
    // Allocating memory, and checking if it was successful
    Node *new_node = malloc(sizeof(Node));
        if (new_node == NULL) { 
        printf("Function list_addfirst: memory allocation failed\n");
        exit (1);
        }
    // Initializing the new node, making head point to the new node. From geeksforgeeks, mostly
    new_node->data = item;
    new_node->next = list->head;
    list->head = new_node;

}

/*
 * Adds an item last in the provided list.
 */
// https://www.geeksforgeeks.org/insert-node-at-the-end-of-a-linked-list/
// Website used for reference. But written by me.
void list_addlast(list_t *list, void *item) { 
    if (list == NULL) {
        printf("list_addlast: List is NULL\n");
        return;
    }
    // Allocating memory, and checking if it was successful
    Node *new_node = malloc(sizeof(Node));
        if (new_node == NULL) {
        printf("Function list_addlast: memory allocation failed\n");
        exit (1);
        }
    // Making the new node point to NULL, and date point to the item
    new_node->next = NULL;
    new_node->data = item;
    // If the list is empty, head and tail point to the new node
    if (list->head == NULL) { // This is mostly from the geeksforgeeks website, not line 95
        list->head = new_node;
        list->tail = new_node;
    } else { // Otherwise, tail points to the new node.
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

/*
 * Removes an item from the provided list, only freeing the node.
 */
// This was written by me.
void list_remove(list_t *list, void *item) {
    if (list == NULL) {
        return;
    }
    // Setting my startpoint to head
    Node *current = list->head;
    Node *prev = NULL;
    // Traverse the list, checking for the item, and removing it
    while (current != NULL) {
        if (current->data == item) {
            if (prev == NULL) {
                // Moving the head to the next node. Freeing the current node
                list->head = current->next;
            } else {
                // Moving the previous node to the next node. Freeing the current node
                prev->next = current->next;
            }
            free(current);
            return;
        }
        // Goes to the next node if the item is not found.
        prev = current;
        current = current->next;
    }
}



/*
 * Return the number of items in the list.
 */
// https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/
// Code from geeksforgeeks
int list_size(list_t *list) { 
    int count = 0;
    Node *current = list->head; 
    // Traverse the list till NULL, and increment count
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count; 
}


/*
 * List iterator interface
 */
// This is technically also from geeksforgeeks, but im using them as a reference. They are not the same.
// So written by me.
typedef struct list_iterator {
    struct Node *head;
    struct Node *current;
} list_iterator_t;

/*
 * Return a newly created list iterator for the given list.
 */
// Written by me, used list_t *list_create(void){ as a reference.
list_iterator_t *list_createiterator(list_t *list) {
    // Just a check to see if the list is NULL
    if (list == NULL) {
        return NULL;
    }
    // Initialize the iterator, giving it memory. If it fails, return NULL
    list_iterator_t *new_iterator = malloc(sizeof(list_iterator_t));
    if (new_iterator == NULL) {
        return NULL;
    }
    // Set the iterator to point to head
    new_iterator->head = list->head;
    new_iterator->current = list->head;

    return new_iterator;
}

/*
 * Free the memory for the given list iterator.
 */
// Written by me
void list_destroyiterator(list_iterator_t *iter) {
    free(iter);
}

/*
 * Move iterator to next item in list and return current.
 */
// Written by me. 
void *list_next(list_iterator_t *iter) {
    if (iter->current == NULL) {
        return NULL;
    }
    // Get the date the current node points to. Move to the next node
    void *data = iter->current->data;  
    iter->current = iter->current->next; 
    return data;
}

/*
 * Let iterator point to first item in list again.
 */
// Written by me.
void list_resetiterator(list_iterator_t *iter) {
    // Set the iterator to point to head
    iter->current = iter->head;
    
}