#include "solution.h"

int countElements(Node* tree) {
    if (!tree) {
        return 0;
    }

    return 1 + countElements(tree->left) + countElements(tree->right);
}


int countLeafs(Node* tree) {
    if (!tree) {
        return 0;
    }

    if (tree->left == nullptr && tree->right == nullptr) {
        return 1;
    }

    return countLeafs(tree->left) + countLeafs(tree->right);
}


int height(Node* tree) {
    if (!tree) {
        return 0;
    }

    int left = 1 + height(tree->left);
    int right = 1 + height(tree->right);

    return left >= right ? left : right;
}


int sumElements(Node* tree) {
    if (!tree) {
        return 0;
    }

    return tree->key + sumElements(tree->left) + sumElements(tree->right);
}


int sumElementsAtLevel(Node* tree, unsigned level) {
    if (!tree) {
        return 0;
    }

    if (level == 0) {
        return tree->key;
    }

    return sumElementsAtLevel(tree->left, level - 1) + sumElementsAtLevel(tree->right, level - 1);
}


bool symTrees(Node* first, Node* second) {
    if (!first && !second) {
        return true;
    }

    if (!first || !second) {
        return false;
    }

    if (first->key == second->key) {
        return symTrees(first->left, second->right) && symTrees(first->right, second->left);
    }

    return false;
}


bool isSymmetric(Node* tree) {
    if (!tree) {
        return true;
    }

    return symTrees(tree->left, tree->right);
}


bool isBST(Node* tree) {
    if (!tree) {
        return true;
    }

    if (!tree->left && !tree->right) {
        return true;
    }

    if (!tree->left && tree->right->key > tree->key) {
        return isBST(tree->right);
    }

    if (!tree->right && tree->left->key < tree->key) {
        return isBST(tree->left);
    }

    if (!tree->left || !tree->right) {
        return false;
    }

    if ((tree->left->key < tree->key) && (tree->right->key > tree->key)) {
        return isBST(tree->left) && isBST(tree->right);
    }

    return false;
}