#include <stdio.h>
#include "LinkedListStruct.cpp"

int main(int argc, char** argv) {
	List* l = createList();
	l = addOrdered(l, 10);
	l = addOrdered(l, 12);
	l = addOrdered(l, 4);
	l = addOrdered(l, 50);
	l = addOrdered(l, 1);
	
	show(l);
	printf("hello darkness my old friend\n");
}