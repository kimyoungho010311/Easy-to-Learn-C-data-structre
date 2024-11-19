#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

#define VisitNode(n) (printf("[%c] ", (n)->data))

void preorder(TNode* n) {
    if (n != NULL) {
        VisitNode(n);
        preorder(n->left);
        preorder(n->right);
    }
}

void inorder(TNode* n) {
    if (n != NULL) {
        inorder(n->left);
        VisitNode(n);
        inorder(n->right);
    }
}

void postorder(TNode* n) {
    if (n != NULL) {
        postorder(n->left);
        postorder(n->right);
        VisitNode(n);
    }
}

#define MAX_SIZE 100
typedef TNode* Element;
#include "../ch04/CircularQueue.h"

void levelorder(TNode* root) {
    if (root != NULL) {
        init_queue();
        enqueue(root);
        while (!is_empty()) {
            TNode* n = dequeue();
            VisitNode(n);
            if (n->left != NULL) enqueue(n->left);
            if (n->right != NULL) enqueue(n->right);
        }
    }
}

int main() {
    TNode d = {'D', NULL, NULL};
    TNode e = {'E', NULL, NULL};
    TNode b = {'B', &d, &e};
    TNode f = {'F', NULL, NULL};
    TNode c = {'C', &f, NULL};
    TNode a = {'A', &b, &c};

    TNode* root = &a;

    printf("\n  In-Order : ");
    inorder(root);
    printf("\n  Pre-Order : ");
    preorder(root);
    printf("\n  Post-Order : ");
    postorder(root);
    printf("\n  Level-Order : ");
    levelorder(root);
    printf("\n");

    return 0;
}