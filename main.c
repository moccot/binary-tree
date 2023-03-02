#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

// Returns a pointer to the left node.
Node *left (Node *node) {
    Node *aux = node;

    if (aux->left != NULL)
        aux = aux->left;

    else
        return NULL;
    
    return aux;
}

// Returns a pointer to the right node.
Node *right (Node *node) {
    Node *aux = node;

    if (aux->right != NULL)
        aux = aux->right;

    else
        return NULL;
    
    return aux;
}

// Returns a pointer to the parent node.
Node *parent (Node *node) {
    Node *aux = node;

    if (aux->parent != NULL)
        aux = aux->parent;
    
    else
        return NULL;
    
    return aux;
}

// Retuns a pointer to the sibling node.
Node *sibling (Node *node) {
    Node *aux = node;

    if (aux == aux->parent->left) 
        if (aux->parent->right) {
            aux = aux->parent->right;
            return aux;
        }

        else {
            return NULL;
        }
    
    if (aux == aux->parent->right)
        if (aux->parent->left) {
            aux = aux->parent->left;
            return aux;
        }

        else {
            return NULL;
        }
    
    return NULL;
}

// Creates a new node.
Node *createNode (int data) {
    Node *node = (Node*) malloc (sizeof(Node));
    
    node->data = data;
    node->parent = NULL;
    node->right = NULL;
    node->left = NULL;

    return node;
}

// Inserts a left sibling in the given node.
int insertLeft (Node *node, int data) {
    Node *leftSibling = createNode(data);

    if (node->left == NULL) {
        node->left = leftSibling;
        node->left->parent = node;

        return 1;
    }

    else {
        return 0;
    }
}

// Inserts a right sibling in the given node.
int insertRight (Node *node, int data) {
    Node *rightSibling = createNode(data);

    if (node->right == NULL) {
        node->right = rightSibling;
        node->right->parent = node;

        return 1;
    }

    else {
        return 0;
    }
}

// Read a node in pre-order.
void preOrder (Node *node) {
    if (node != NULL) {
        printf("%d\n", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Read a node in order.
void inOrder (Node *node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%d\n", node->data);
        inOrder(node->right);
    }
}

// Read a node in post-order.
void postOrder (Node *node) {
    if (node != NULL) {
        preOrder(node->left);
        preOrder(node->right);
        printf("%d\n", node->data);
    }
}

int main (int argc, char **argv) {
    Node *binaryTree = createNode(12);

    binaryTree->left = createNode(20);
    binaryTree->right = createNode(2);

    binaryTree->left->left = createNode(15);
    binaryTree->left->right = createNode(13);
    
    binaryTree->right->left = createNode(5);
    binaryTree->right->right = createNode(8);

    printf("Reading in pre-order:\n");
    preOrder(binaryTree);

    printf("Reading in order:\n");
    inOrder(binaryTree);

    printf("Reading in post-order:\n");
    postOrder(binaryTree);
}
