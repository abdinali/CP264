#include <stdio.h>
#include <stdlib.h>

// display a doubly linked list, forwards and backwards

typedef struct node {
	struct node *prev;
	int data;
	struct node *next;
} NODE;

NODE *new_dnode(int val) {
	NODE *np = (NODE*) malloc(sizeof(NODE));
	if (np == NULL) {
		printf("malloc fails"); return NULL;
	}
	np->data = val;
	np->prev = NULL;
	np->next = NULL;

	return np;
}

void display_forward(NODE *start) {
	if (start == NULL) {
		return;
	}
	NODE *ptr = start;

	while (ptr != NULL) {
		if (ptr->next == NULL) {
			printf("%d", ptr->data);
		} else {
			printf("%d->", ptr->data);
		}
		ptr = ptr->next;
	}
}

void display_backward(NODE *end) {
	if (end == NULL) {
		return;
	}
	NODE *ptr = end;

	while (ptr != NULL) {
		if (ptr->prev == NULL) {
			printf("%d", ptr->data);
		} else {
			printf("%d->", ptr->data);
		}
		ptr = ptr->prev;
	}
}

void test_ds() {
	NODE *start = NULL;
	NODE *end = NULL;

	NODE *n1 = new_dnode(3);
	NODE *n2 = new_dnode(8);
	NODE *n3 = new_dnode(1);
	NODE *n4 = new_dnode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->prev = n3;
	n3->prev = n2;
	n2->prev = n1;

	start = n1;
	end = n4;

	display_forward(start);
	printf("\n");
	display_backward(end);
}

int main() {
	test_ds();
}
