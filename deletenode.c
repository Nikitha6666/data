#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the minimum value node in a BST
struct Node* findMin(struct Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a value from the BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Function to perform level order traversal of a BST
void levelOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Queue for level order traversal
    struct Node** queue = (struct Node**)malloc(100 * sizeof(struct Node*));
    int front = -1, rear = -1;

    // Enqueue the root
    queue[++rear] = root;

    while (front <= rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL) {
            queue[++rear] = current->left;
        }

        if (current->right != NULL) {
            queue[++rear] = current->right;
        }
    }

    // Free the allocated memory for the queue
    free(queue);
}

// Function to free the memory of a BST
void freeBST(struct Node* root) {
    if (root == NULL) {
        return;
    }

    freeBST(root->left);
    freeBST(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    // Delete a node (for example, deleting 30)
    root = deleteNode(root, 30);

    printf("Level Order Traversal after deleting 30: ");
    levelOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the BST
    freeBST(root);

    return 0;
}
