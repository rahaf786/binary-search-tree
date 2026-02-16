#include "BinarySearchTree.h"
using namespace std;
template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree() {
    root = nullptr;
    length = 0;
}

template <class DataType>
int BinarySearchTree<DataType>::getLength() {
    return length;
}

template <class DataType>
bool BinarySearchTree<DataType>::putItem(const DataType &item) {
    Node<DataType> *temp = new Node<DataType>;
    temp->value = item;
    temp->right = nullptr;
    temp->left = nullptr;

    if (length == 0) {
        root = temp;
        length++;
        return true;
    }

    Node<DataType> *curr = root;
    while (curr != nullptr) {
        if (item < curr->value) {
            if (curr->left == nullptr) {
                curr->left = temp;
                length++;
                return true;
            }
            curr = curr->left;
            continue;
        } else if (item > curr->value) {
            if (curr->right == nullptr) {
                curr->right = temp;
                length++;
                return true;
            }
            curr = curr->right;
            continue;
        }
        else {
            return false;
        }
    }
}



template <class DataType>
bool BinarySearchTree<DataType>::getItem(const DataType &item, DataType &found_item) {
    Node<DataType> *curr = root;

    while (curr != nullptr) {
        if (item == curr->value) {
            found_item = curr->value;
            return true;
        } else if (item < curr->value) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    return false;
}
//
template <class DataType>
bool BinarySearchTree<DataType>::isFull() {
    return false;
}

template <class DataType>
void BinarySearchTree<DataType>::deleteAll(Node<DataType>* tree) {
    // Base Case
    if (tree == nullptr) {
        return;
    }

    deleteAll(tree->left);
    deleteAll(tree->right);
    delete tree;
}

template <class DataType>
void BinarySearchTree<DataType>::makeEmpty() {
    deleteAll(root);
    root = nullptr;
    length = 0;
}

template <class DataType>
BinarySearchTree<DataType>::~BinarySearchTree() {
    deleteAll(root);
    length = 0;
    root = nullptr;
}
//
template <class DataType>
void BinarySearchTree<DataType>::resetList() {
    addtoQueue(root);
}

template <class DataType>
void BinarySearchTree<DataType>::addtoQueue(Node<DataType>* tree) {
    // Base Case
    if (tree == nullptr) {
        return;
    }

    // Recursive Case
    addtoQueue(tree->left);
    orderedQueue.push(tree->value);
    addtoQueue(tree->right);
}
//
template <class DataType>
bool BinarySearchTree<DataType>::getNextItem(DataType &item) {
    if (orderedQueue.empty()) {
        return false;
    }
    item = orderedQueue.front();
    orderedQueue.pop();
    return true;
}

template <class DataType>
bool BinarySearchTree<DataType>::max(DataType &found_item) {
    if (root == nullptr) {
        return false;
    }

    Node<DataType>* current = root;
    while (current->right != nullptr) {
        current = current->right;
    }

    found_item = current->value;
    return true;
}

template <class DataType>
DataType BinarySearchTree<DataType>::findMax(Node<DataType>* root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->right == nullptr) {
        return root;
    }
    return findMax(root->right);
}

template <class DataType>
bool BinarySearchTree<DataType>::min(DataType &found_item) {
    if (root == nullptr) {
        return false;
    }

    Node<DataType>* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }

    found_item = current->value;
    return true;
}

template <class DataType>
DataType BinarySearchTree<DataType>::findMin(Node<DataType>* tree) {
    if (tree->left == nullptr) {
        return tree->value;
    }
    return findMin(tree->left);
}
template <class DataType>
bool BinarySearchTree<DataType>::delete_Item(const DataType &item, Node<DataType>*tree) {
    // Case 0 (Empty)
    if (root == nullptr) {
        return false;
    }

    Node<DataType> *curr = tree;
    Node<DataType> *parent = nullptr;

    while (curr != nullptr) {
        if (curr->value == item) {
            break;
        }
        parent = curr;
        if (item < curr->value) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    if (curr == nullptr) {
        return false;
    }
    // Case #1 (No children)
    if (curr->left == nullptr && curr->right == nullptr) {
        //checking if root
        if (parent == nullptr) {
            delete curr;
            root = nullptr;
            length = 0;
        } else {
            delete curr;
            if (item < parent->value) {
                //delete parent->left;
                parent->left = nullptr;
            } else {
                //delete parent->right;
                parent->right = nullptr;
            }
            length--;
        }
        return true;
    }
        // Case #2 (One child)
    else if (curr->left == nullptr || curr->right == nullptr) {
        Node<DataType> *child = nullptr;
        //check if root
        if (parent == nullptr) {
            //Node = root with 1 child
            if (curr->left != nullptr) {
                root = curr->left;
            }
            else {
                root = curr->right;
            }
            length--;
            return true;
        }

        if (curr->left != nullptr) {
            child = curr->left;
            //delete curr;
            //length--;
        }
        else {
            child = curr->right;
        }
        if (item < parent->value) {
            parent->left = child;
        }
        else {
            parent->right = child;
//            delete curr;
        }
        delete curr;
        length--;
        return true;
    }
        //Case #3 (2 children)
    else if (curr->left != nullptr && curr->right != nullptr) {
        //check if root
        curr-> value = findMin(curr->right);
        delete_Item (item, curr-> right);
        return true;
    }

}

template<class DataType>
bool BinarySearchTree<DataType>::deleteItem(const DataType &item) {

        return delete_Item(item, root);
    }

template <class DataType>
void BinarySearchTree<DataType>::deepCopy(Node<DataType>*original_tree) {
    // Base case
    if (original_tree == nullptr) {
        return;
    }
    // Recursive case
    putItem(original_tree->value);
    deepCopy(original_tree->left);
    deepCopy(original_tree->right);
}

template <class DataType>
BinarySearchTree<DataType>::BinarySearchTree(const BinarySearchTree &other) {
    length = 0;
    root = nullptr;
    deepCopy(other.root);
}

template <class DataType>
void BinarySearchTree<DataType>::operator=(const BinarySearchTree &other) {
    deleteAll(root);

    root = nullptr;
    length = 0;
    deepCopy(other.root);
}

