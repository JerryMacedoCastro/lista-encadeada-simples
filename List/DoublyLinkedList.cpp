#include <iostream>
#include <stdio.h>
using namespace std;

struct node {
	int info;
	struct node* next;
    struct node* prev;
};  
typedef struct node List;

List* createList() {
	return NULL;
};


bool isEmptyList(List* list) {
	return list == NULL;
}

List* pushFront(List* list, int value) {
    List* newList = (List*) malloc(sizeof(List)); 
    newList->info = value;
    newList->next = list;
    newList->prev = NULL;
    if (list != NULL)
        list->prev = newList;
    return newList;
}

List* search(List* list, int value) {
    List* p;
    for (p = list; p != NULL; p = p->next)
       if (p->info == value)
           return p;
    return NULL; 
}

List* removeElement(List* list, int val) {
    List* p = search(list, val); 
    if (p == NULL) 
       return list;

    if (list == p)
        list = p->next;
    else
        p->prev->next = p->next;
    
    if (p->next != NULL) 
        p->next->prev = p->prev;

    free(p);
    return list;
}

List* removeFromListRecursive(List* list, int val) {
	if (!isEmptyList(list)) {
		if (list->info == val) {
			List* t = list;
			list = list->next;
			if(list != NULL)
            	list->prev = t->prev;
			free(t);
		}
		else {
			list->next = removeFromListRecursive(list->next, val);
		}
	}
	return list;
}


void show(List* list) {
	List* p;
	for (p = list; p != NULL; p = p->next)
		printf("% d", p->info);
	printf("\n");
}


void showRecursive(List* list) {
	if (list == NULL) return;
	else {
		cout << list->info << " ";
		list = list->next;
		showRecursive(list);
	}
}

void showReverseRecursive(List* l) {
	List* h = l;
	if (h != NULL) {
		l = h->next;
		showReverseRecursive(l);
		printf("%d ", h->info);
	}
}

List* addOrdered (List* list, int value) {
	List* newList;
	List* previous = NULL; 
	List* p = list; 
	while (p != NULL && p->info < value) {
		previous = p;
		p = p->next;
	}
	newList = (List*) malloc(sizeof(List));
	newList->info = value;

	if (previous == NULL) {
		newList->next = list;
        newList->prev = NULL;
		list = newList;
	}
	else { 
		newList->next = previous->next;
        newList->prev = previous;
		previous->next = newList;
	}

	return list;
}

bool isEqualLists (List* list1, List* list2) {
	List* p1; 
	List* p2; 
	for (p1=list1, p2=list2; p1 != NULL && p2 != NULL;  p1 = p1->next, p2 = p2->next) 
		if (p1->info != p2->info) 
			return false;
	return p1 == p2;
}