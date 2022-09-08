#include <iostream>
#include <stdio.h>
#include "DoublyList.h"

using namespace std;
namespace {

	List* createList() {
		List* newList = (List*)malloc(sizeof(List));
		newList->start = NULL;
		newList->end = NULL;
		newList->size = 0;
		return newList;
	}

	List* push(List* l, int info) {
		node* newList = (node*)malloc(sizeof(node));
		newList->info = info;
		if (l->size == 0) {
			l->start = newList;
			l->end = newList;
			l->size++;
		}
		else if (l->size == 1) {
			l->start->next = newList;
			l->start->prev = newList;
			l->end = newList;
			newList->prev = l->start;
			newList->next = l->start;
			l->size++;
		}
		else {
			l->start->prev = newList;
			newList->next = l->start;
			newList->prev = l->end;
			l->end->next = newList;
			l->end = newList;
			l->size++;
		}
		return l;
	}

	void show(List* l) {
		node* percorre = l->start;
		printf("%d ", percorre->info);
		percorre = percorre->next;
		while (percorre != l->start) {
			printf(" %d ", percorre->info);
			percorre = percorre->next;
		}
	}

	List* removeFromList(List* l, int value) {
		node* percorre = l->start, * aux;
		while (percorre->next != l->start) {
			if (percorre->info == value) {
				if (percorre == l->start) {
					l->start = percorre->next;
					l->end->next = l->start;
					l->start->prev = l->end;
					l->size--;
					free(percorre);
					return l;
				}
				else {
					percorre->prev->next = percorre->next;
					percorre->next->prev = percorre->prev;
					l->size--;
					free(percorre);
					return l;
				}
			}
			percorre = percorre->next;
		}
		if ((percorre->info == value) && (percorre == l->end)) {
			l->start->prev = l->end->prev;
			l->end = l->start->prev;
			l->end->next = l->start;
			l->size--;
			free(percorre);
			return l;
		}
		return l;
	}


	void freeList(List* l) {
		node* percorre = l->start->next;
		node* proximo;
		l->start = NULL;
		while (percorre->next != NULL) {
			proximo = percorre->next;
			free(percorre);
			proximo = percorre;
		}
		free(l);
	}
}