#include <queue>
using namespace std;
#ifndef NODE
#define NODE
template <class DataType>
struct Node {
    DataType value;
    Node<DataType>* left = nullptr;
    Node<DataType>* right = nullptr;
};
#endif


#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

template <class DataType>
class BinarySearchTree {
public:
/**
 * COnstructor for Binary Search Tree
 */
    BinarySearchTree();
/**
 * gets the length
 * @return length
 */
    int getLength ();
/**
 * puts the item into a Binary Search Tree
 * @param item
 * @return true if the item was successfully inserted into the tree, else false

 */
    bool putItem(const DataType &item);
/**
 *
 * @param item
 * @param found_item
 * @return true if the item was found in the tree, else false
 */
    bool getItem(const DataType &item, DataType &found_item);
/**
 * Checks if the tree is full
 * @return false
 */
    bool isFull();
/**
 *
 * @param tree
 */
    void inOrder(Node<DataType>*tree);
/**
 *
 * @param tree
 */
    void Order(Node<DataType>*tree);
/**
 * Deletes all nodes in the tree.
 * @param tree
 */
    void deleteAll(Node<DataType>*tree);
/**
 * Deletes all nodes in the tree and sets the root to nullptr
 */
    void makeEmpty();
/**
 * has a similar function to makeEmpty
 */
    //Deconstructor
    ~BinarySearchTree();
/**
 * Initializes an internal queue for inorder traversal
 */
    void resetList();
/**
 * Adds elements to the internal queue during inorder traversal
 * @param tree
 */
    void addtoQueue(Node<DataType>*tree);
/**
 * Gets the next item in the internal queue
 * @param item
 * @return true if there's a next item, else false
 */
    bool getNextItem(DataType &item);
/**
 * Finds the maximum value in the tree
 * @param found_item
 * @return true if the tree is not empty, else false
 */
    bool max(DataType &found_item);
/**
 * Finds the maximum value in the subtree
 * @param root
 * @return max value
 */
    DataType findMax(Node<DataType>* root);
/**
 * Finds the minimum value in the tree
 * @param found_item
 * @return true if the tree is not empty, else false
 */
    bool min(DataType &found_item);
/**
 * Finds the minimum value in the subtree
 * @param root
 * @return min value
 */
    DataType findMin(Node<DataType>* root);
/**
 * Deletes a specific item from the tree
 * @param item
 * @param root
 * @return true if item is deleted, false if the item is not found
 */
    bool delete_Item(const DataType &item, Node<DataType>*root);
/**
 * Deletes a specific item from the tree
 * @param item
 * @return true if item is deleted, false if the item is not found
 */
    bool deleteItem(const DataType &item);
/**
 * Creates a deep copy of another tree
 * @param original_tree
 */
    void deepCopy(Node<DataType>*original_tree);
/**
 * Creates a deep copy of another tree
 * @param other
 */
    BinarySearchTree(const BinarySearchTree &other);
/**
 * Creates a deep copy of another tree
 * @param other
 */
    void operator = (const BinarySearchTree & other);
/**
 *
 * @return root
 */
    Node<DataType>* getRoot() const;

private:
    queue<DataType>orderedQueue;
    Node<DataType>* root;

    int length;
};
#include "BinarySearchTree.cpp"
#endif //BINARYSEARCHTREE_H
