#ifndef _BINARY_TREES_H_
#define  _BINARY_TREES_H_


#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int h_size(binary_tree_t *root);
heap_t *heap_insert(heap_t **root, int value);
heap_t *order(binary_tree_t *root, int value, int index, int len);
heap_t *h_swap(heap_t *parent, heap_t *new, int value);

#endif /* _BINARY_TREES_H_ */
