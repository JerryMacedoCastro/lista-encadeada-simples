#include <iostream>
#include <stdio.h>
using namespace std;

struct node {
	int info;
	struct node* next;
};
typedef struct node List;


List* createList() {
	return NULL;
};

List* pushFront(List* list, int value) {
	List* newList = (List*)malloc(sizeof(List));
	newList->info = value;
	newList->next = list;
	return newList;
}

bool isEmptyList(List* list) {
	return list == NULL;
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

List* search(List* list, int value) {
	List* p;
	for (p = list; p != NULL; p = p->next) {
		if (p->info == value)
			return p;
	}
	return NULL; /* n�o achou o elemento */
}

List* removeFromList(List* list, int value) {
	List* previous = NULL;
	List* p = list;
	while (p != NULL && p->info != value) {
		previous = p;
		p = p->next;
	}
	if (p == NULL)
		return list;
	if (previous == NULL)
		list = p->next;
	else
		previous->next = p->next;
	free(p);
	return list;
}

List* removeFromListRecursive(List* list, int val) {
	if (!isEmptyList(list)) {
		if (list->info == val) {
			List* t = list;
			list = list->next;
			free(t);
		}
		else {
			list->next = removeFromListRecursive(list->next, val);
		}
	}
	return list;
}

void freeList(List* list) {
	List* p = list;
	while (p != NULL) {
		List* t = p->next;
		free(p);
		p = t;
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
		list = newList;
	}
	else { 
		newList->next = previous->next;
		previous->next = newList;
	}
	return list;
}

