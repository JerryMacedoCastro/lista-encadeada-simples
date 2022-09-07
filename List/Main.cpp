#include <stdio.h>
#include "LinkedCircularList.cpp"

int main(int argc, char** argv) {
	List* l = createList();
	l = pushBack(l, 2);

	show(l);

	if(isEmptyList(l)) {
		printf("Lista vazia \n");
	}


	
	printf("hello darkness my old friend\n");
}