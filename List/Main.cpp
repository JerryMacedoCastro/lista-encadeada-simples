#include <stdio.h>
#include "DoublyLinkedList.cpp"

int main(int argc, char** argv) {
	List* l1 = createList();
	List* l2 = createList();
	l1 = addOrdered(l1, 10);
	l1 = addOrdered(l1, 4);
	l1 = addOrdered(l1, 29);
	l1 = addOrdered(l1, 2);
	l1 = addOrdered(l1, 7);

	l2 = l1;
	// showRecursive(l);
	// l = removeFromListRecursive(l, 29);
	if (isEqualLists(l1, l2)) 
		printf("Listas iguais");
	else 
		printf("Listas Diferentes");
	
	printf("\n");

	
	printf("hello darkness my old friend\n");
}