#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
typedef struct TNode {
    TElement data;
    struct TNode* left;
    struct TNode* right;
} TNode;

TNode* create_tree(TElement data, TNode* left, TNode* right)
{
    TNode* n = (TNode*)malloc(sizeof(TNode)); // root Node
    n->data = data;  // copy data
    n->left = left;  // connect left sub tree
    n->right = right; // connect right sub tree
    return n;          // return Root node
}

void delete_tree(TNode* n)
{
    if (n != NULL) {
        delete_tree(n->left);       //delete left sub tree
        delete_tree(n->right);      // delete right sub tree
        free(n);                    // delete root node
    }
}

int main()
{
    TNode *d = create_tree("D", NULL, NULL);
    TNode *e = create_tree("E",NULL,NULL);
    TNode *b = create_tree("B",d,e);
    TNode *f = create_tree("F",NULL,NULL);
    TNode *c = create_tree("C",f,NULL);
    TNode *root1 = create_tree("A",b,c);

    TNode* D = create_tree("D",NULL,NULL);
    TNode* C = create_tree("C",D,NULL);
    TNode* B = create_tree("B",C,NULL);
    TNode* root2 = create_tree("A",B,NULL);

    delete_tree(root1);
    delete_tree(root2);
    return 0;
}