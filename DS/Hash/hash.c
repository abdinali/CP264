#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int htsize;

int hash(char* word) {
  unsigned int hash = 0, i;
  for (i = 0; word[i] != '\0'; i++) {
    hash = 31 * hash + word[i];
  }
  return hash % htsize;
}

HSNODE *new_hashnode(char *key, int value) {
	HSNODE *np = (HSNODE*)malloc(sizeof(HSNODE));

	if (np == NULL) return np;

	np->value = value;
	strcpy(np->key, key);
	np->next = NULL;

	return np;
}

HASHTABLE *new_hashtable(int size) {
	HASHTABLE *ht  = (HASHTABLE*)malloc(sizeof(HASHTABLE) * size);

	ht->size = size;
	ht->count = 0;

	// allocate memory for the array of pointers
	ht->hna = (HSNODE**)malloc(sizeof(HSNODE*) * size);

	return ht;
}

HSNODE *search(HASHTABLE *ht, char *key) {
	int i = hash(key);

	HSNODE *ptr = ht->hna[i];

	while (ptr != NULL && strcmp(ptr->key, key) != 0) {
		ptr = ptr->next;
	}
	if (ptr != NULL) {
		// found
		return ptr;
	} else {
		return NULL;
	}
}

int insert(HASHTABLE *ht, HSNODE *np) {
	int i = hash(np->key);

	HSNODE *ptr = ht->hna[i], *prev = NULL;

	while (ptr != NULL && strcmp(ptr->key, np->key) < 0) {
		prev = ptr;
		ptr = ptr->next;
	}

	if (ptr == NULL) {
		// insert at end
		if (prev == NULL) {
			// empty linked list
			ht->hna[i] = np;
		} else {
			prev->next = np;
		}
	} else if (strcmp(ptr->key, np->key) > 0) {
		// insert before other nodes
		if (prev == NULL) {
			// insert as first node
			np->next = ptr;
			ht->hna[i] = np;
		} else {
			np->next = ptr;
			prev->next = np;
		}
	} else {
		// hash node already exists, update existing hash node value with new node value
		ptr->value = np->value;
		free(np);
		return 0;
	}
	ht->count++;
	return 1;
}

int delete(HASHTABLE *ht, char *key) {
	int i = hash(key);

	HSNODE *ptr = ht->hna[i], *prev = NULL;

	while(ptr != NULL && strcmp(ptr->key, key) != 0) {
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr != NULL) {
		// found
		if (prev == NULL) {
			// first node
			ht->hna[i] = ptr->next;
		} else {
			// not the first node
			prev->next = ptr->next;
		}
		free(ptr);
		ht->count--;
		return 1;
	}
	return 0;
}


void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HSNODE *sp = ht->hna[0], *p, *temp;
  int i;
  for (i = 0; i < ht->size; i++) {
    p = ht->hna[i];
    while (p) {
      temp = p;
      p = p->next;
      free(temp);
    }
    ht->hna[i] = NULL;
  }
  free(ht->hna);
  ht->hna = NULL;
  *htp = NULL;
}
