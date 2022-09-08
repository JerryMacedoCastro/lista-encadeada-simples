#include <stdio.h>
#include "DoublyLinkedCircularList.h"

int main(int argc, char** argv) {
	List* l = createList();

	l = push(l, 1);
	l = push(l, 2);
	l = push(l, 5);
	l = push(l, 3);
	l = push(l, 7);

	show(l);

	l = removeFromList(l, 1);
	l = removeFromList(l, 7);
	l = removeFromList(l, 5);

	printf("\nhello darkness my old friend\n");
	show(l);

	
}