#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node *createNode(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *stack[100];
int top = -1;

void push(Node *node) { stack[++top] = node; }
Node *pop(void) { return stack[top--]; }

Node *buildExpressionTree(char postfix[]) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] == ' ') continue;

        if (isdigit((unsigned char)postfix[i])) {
            push(createNode(postfix[i]));
        } else {
            Node *op = createNode(postfix[i]);
            op->right = pop();
            op->left = pop();
            push(op);
        }
    }
    return pop();
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void displayTree(Node *root, int level) {
    if (root == NULL) return;
    displayTree(root->right, level + 1);
    for (int i = 0; i < level; i++) printf("    ");
    printf("%c\n", root->data);
    displayTree(root->left, level + 1);
}

int evaluateTree(Node *root) {
    if (root == NULL) return 0;
    if (isdigit((unsigned char)root->data))
        return root->data - '0';

    int left = evaluateTree(root->left);
    int right = evaluateTree(root->right);

    switch (root->data) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
    }
    return 0;
}

int main(void) {
    char postfix[] = "8 3 2 * + 6 2 / -";
    Node *root = buildExpressionTree(postfix);

    printf("Postfix Expression: %s\n\n", postfix);
    printf("Expression Tree:\n");
    displayTree(root, 0);

    printf("\nPreorder : "); preorder(root);
    printf("\nInorder  : "); inorder(root);
    printf("\nPostorder: "); postorder(root);

    printf("\n\nExpression Tree Evaluation = %d\n", evaluateTree(root));
    return 0;
}
