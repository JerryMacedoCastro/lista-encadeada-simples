#include <iostream>
#include <stdio.h>
#include "List.h"

using namespace std;
namespace {

	List* createList() {
		return NULL;
	};

	bool isEmptyList(List* list) {
		return list == NULL;
	}

	List* pushBack(List* list, int value) {
		List* p = list;
		List* newList;
		newList = (List*)malloc(sizeof(List));
		if (isEmptyList(list)) {
			newList->info = value;
			newList->next = newList;
			return newList;
		}
		else {
			while (p->next != list) {
				p = p->next;
			}
			newList->info = value;
			newList->next = list;
			p->next = newList;
		}
		return list;
	}

	void show(List* list) {
		List* p = list;
		do {
			printf("% d", p->info);
			p = p->next;
		} while (p != list);
		printf("\n");
	}

	List* search(List* list, int value) {
		List* p = list;
		do {
			if (p->info == value) {
				return p;
			}
			p = p->next;
		} while (p != list);
		return NULL; /* n�o achou o elemento */
	}

	List* removeFromList(List* list, int value) {
		List* previous = NULL;
		List* p = list;
		if (list->info == value) {
			while (p->next != list) 
				p = p->next;
			list = list->next;
			p->next = list;
			return list;
		}

		while (p->next != list && p->info != value) {
			previous = p;
			p = p->next;
		}
		if (p->info == value) {
			previous->next = p->next;
		}
		free(p);
		return list;
	}

	List* removeFromListRecursive(List* list, int val) {
		if (!isEmptyList(list)) {
			List* p = list;
			List* f = list;

			if (list->info == val) {
				while (p->next != list)
					p = p->next;
				list = list->next;
				p->next = list;
				free(f);
			} else {
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




}
