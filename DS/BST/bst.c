#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"


TNODE *search(TNODE *root, char *name) {
	if (root == NULL || strcmp(root->data.name, name) == 0) return root;
	else {
		if (strcmp(name, root->data.name) < 0) {
			return search(root->left, name);
		} else if (strcmp(name, root->data.name) > 0) {
			return search(root->right, name);
		}
	}
	return NULL;
}

void insert(TNODE **rootp, char *name, float score) {
	if (*rootp == NULL) {
		*rootp = new_node(name, score);
	} else {
		TNODE *ptr = *rootp, *parent = NULL;

		while (ptr != NULL) {
			parent = ptr;
			if (strcmp(name, ptr->data.name) < 0) {
				ptr = ptr->left;
			} else if (strcmp (name, ptr->data.name) > 0) {
				ptr = ptr->right;
			}
		}
		if (strcmp(name, parent->data.name) < 0) {
			parent->left = new_node(name, score);
		} else if (strcmp(name, parent->data.name) > 0) {
			parent->right = new_node(name, score);
		}
	}
}

void delete_node(TNODE **rootp, char *name) {
	TNODE *ptr = *rootp, *parent = NULL, *smallest_node;

	// find the node to delete
	while (ptr != NULL && (strcmp(name, ptr->data.name) != 0)) {
		parent = ptr;
		ptr = (strcmp(name, ptr->data.name) < 0) ? ptr->left : ptr->right;
	}
	if (ptr == NULL) {
		// not found
		return;
	} else {
		// found
		// case 1: node to delete has no left child
		if (ptr->left == NULL) {
			if (parent == NULL) {
				*rootp = ptr->right;
			} else {
				if (parent->left == ptr) {
					parent->left = ptr->right;
				} else {
					parent->right = ptr->right;
				}
			}
		// case 2: node to delete has no right child
		} else if (ptr->right == NULL) {
			if (parent == NULL) {
				*rootp = ptr->left;
			} else {
				if (parent->left == ptr) {
					parent->left = ptr->left;
				} else if (parent->right == ptr) {
					parent->right = ptr->left;
				}
			}
		// case 3: node to delete has two children
		} else {
			smallest_node = extract_smallest_node(&ptr->right);
			if (parent == NULL) {
				*rootp = smallest_node;
			} else {
				if (parent->left == ptr) {
					parent->left = smallest_node;
				} else if (parent->right == ptr) {
					parent->right = smallest_node;
				}
			}
			smallest_node->left = ptr->left;
			smallest_node->right = ptr->right;
		}
		free(ptr);
	}
}


TNODE *new_node(char *name, float score) {
  TNODE *np = (TNODE *) malloc(sizeof(TNODE));
  if (np) {
    strcpy(np->data.name, name);
    np->data.score = score;
    np->left = NULL;
    np->right = NULL;
  }
  return np;
}

TNODE *extract_smallest_node(TNODE **rootp) {
  TNODE *p = *rootp, *parent = NULL;
  if (p) {
    while (p->left) {
      parent = p;
      p = p->left;
    }

    if (parent == NULL)
      *rootp = p->right;
    else
      parent->left = p->right;

    p->left = NULL;
    p->right = NULL;
  }

  return p;
}

void clean_tree(TNODE **rootp) {
  TNODE *root = *rootp;
  if (root) {
    if (root->left)
      clean_tree(&root->left);
    if (root->right)
      clean_tree(&root->right);
    free(root);
  }
  *rootp = NULL;
}
