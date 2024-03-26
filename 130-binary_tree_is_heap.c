#include "binary_tree.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 *
 * @tree: pointer to root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (tree->left && tree->n < tree->left->n)
        return 0;

    if (tree->right && tree->n < tree->right->n)
        return 0;

    if (tree->left && !binary_tree_is_heap(tree->left))
        return 0;

    if (tree->right && !binary_tree_is_heap(tree->right))
        return 0;

    return 1;
}
#include <stdio.h>
#include "binary_tree.h"

/**
 * main - entry point
 *
 * Return: always 0
 */
int main(void)
{
    binary_tree_t *binary_tree = NULL;

    binary_tree_t *left_child = binary_tree_node(binary_tree, 7);
    binary_tree_t *right_child = binary_tree_node(binary_tree, 3);
    binary_tree_t *left_grandchild = binary_tree_node(left_child, 4);
    binary_tree_t *right_grandchild = binary_tree_node(right_child, 8);

    binary_tree_t *node_10 = binary_tree_node(right_grandchild, 10);
    binary_tree_t *node_11 = binary_tree_node(node_10, 11);

    binary_tree = binary_tree_node(binary_tree, 5);
    binary_tree_insert_left(binary_tree, 12);
    binary_tree_insert_right(binary_tree, 19);
    binary_tree_insert_left(binary_tree->right, 23);
    binary_tree_insert_right(binary_tree->right, 40);

    binary_tree_insert_left(left_grandchild, 1);
    binary_tree_insert_right(left_grandchild, 6);
    binary_tree_insert_left(left_child, left_grandchild);
    binary_tree_insert_right(left_child, right_grandchild);
    binary_tree_insert_right(right_child, node_10);

    binary_tree_print(binary_tree);

    if (binary_tree_is_heap(binary_tree))
        printf("The binary tree is a valid Max Binary Heap.\n");
    else
        printf("The binary tree is not a valid Max Binary Heap.\n");

    return 0;
}
