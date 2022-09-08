#pragma once
#pragma once
struct node {
	int info;
	struct node* next;
	struct node* prev;
	struct node* start;
	struct node* end;
	int size;
};
typedef struct node List;