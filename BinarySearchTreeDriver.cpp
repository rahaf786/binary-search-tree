#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Customer.h"

using namespace std;

static const int CUSTOMER_SIZE = 100;

int main() {

    BinarySearchTree<Customer> list;
    BinarySearchTree<int> tree;
    BinarySearchTree<int> tree1;
    BinarySearchTree<int> tree2;
    ifstream in_file;
    in_file.open("customer_data/ Customer.txt");
    int element = 0;
    string temp;
    if (in_file.is_open()) {
        //reads the first line in the header
        getline(in_file, temp, '\n');
        while (!list.isFull()) {
            getline(in_file, temp, '\n');
            Customer customer = Customer(temp);
            list.putItem(customer);
            element++;
        }
    } else {
        cout << "Unable to open file" << endl;
    }
    cout << "Initial item created: " << endl;
    cout << "The total length of the item is: " << list.getLength() << endl;
    Customer customers1;
    for (int i = 0; i < list.getLength(); i++) {
        list.getNextItem(customers1);
        cout << customers1.toString() << endl;
    }

    list.resetList();

    BinarySearchTree<Customer> item2 = list;
    cout << "\nPrinting item 2 deep copy of item 1: " << endl;
    cout << "Item 2 should be the same length of item 1: " << item2.getLength() << endl;
    Customer customers2;
    for (int i = 0; i < item2.getLength(); i++) {
        item2.getNextItem(customers2);
        cout << customers2.toString() << endl;
    }

    item2.resetList();
    Customer found = Customer(
            "9026-HGfrmkk965s\tkblencoe0\tKarna\tBlencoe\t2 Scott Court\tAlbany\tNY\t12227\tkblencoe0@bloglovin.com\tFemale\tMohr Inc\tDesign Engineer\t5/26/2006\t767-10-7836\t7/13/1978\t367136\t722\t233426.61"
            "3555-HGce0op0cvp\tstrunks1\tSymon\tTrunks\t59 Sheridan Trail\tBuffalo\tNY\t14220\tstrunks1@ca.gov\tGenderqueer\tHalvorson, Rogahn and Gusikowski\tOffice Assistant IV\t1/1/2003\t585-47-6622\t8/29/1969\t184152\t655\t429028.34");
    if (list.deleteItem(found)) {
        cout << found.toString() << " has been deleted" << endl;
    } else {
        cout << found.toString() << "Not found in item" << endl;
    }

    cout << "\nItem 1 should not include: " << found.toString() << endl;
    cout << "New length of item 1: : " << list.getLength() << endl;
    for (int i = 0; i < list.getLength(); i++) {
        list.getNextItem(customers1);
        cout << customers1.toString() << endl;
    }
    list.resetList();

    Customer add = Customer(
            "3163-HGh6nvgynun\tlwicks2\tLem\tWicks\t540 Eagan Terrace\tJamaica\tNY\t11447\tlwicks2@state.gov\tMale\tLind LLC\tAssistant Media Planner\t10/22/2006\t705-78-7957\t3/30/1951\t367651\t671\t410114.86");
    list.putItem(add);
    cout << "\nItem 1 should now include: " << add.toString() << endl;
    cout << "New length of item: " << list.getLength() << endl;
    for (int i = 0; i < list.getLength(); i++) {
        list.getNextItem(customers1);
        cout << customers1.toString() << endl;
    }

    cout << "\nList 2 should remain unchanged: " << endl;
    cout << "Length of List: " << item2.getLength() << endl;
    Customer customers3;
    for (int i = 0; i < item2.getLength(); i++) {
        item2.getNextItem(customers3);
        cout << customers3.toString() << endl;
    }

    tree.putItem(10);
    tree.putItem(5);
    tree.putItem(15);
    tree.putItem(3);
    tree.putItem(7);

    // Test the max function
    int max_value;
    bool result_max = tree.max(max_value);

    if (result_max) {
        std::cout << "Maximum value in the tree: " << max_value << std::endl;
    } else {
        std::cout << "The tree is empty." << std::endl;
    }

    tree.putItem(10);
    tree.putItem(5);
    tree.putItem(15);
    tree.putItem(3);
    tree.putItem(7);

    // Test the min function
    int min_value;
    bool result_min = tree.min(min_value);

    if (result_min) {
        std::cout << "Minimum value in the tree: " << min_value << std::endl;
    } else {
        std::cout << "The tree is empty." << std::endl;
    }

    tree.putItem(10);
    tree.putItem(5);
    tree.putItem(15);
    tree.putItem(3);
    tree.putItem(7);

    // Display the original tree
    std::cout << "Original tree:" << std::endl;
    tree.inOrder(tree.getRoot()); // Assuming you have an inOrder function

    // Test the delete_Item function
    int item_to_delete = 10;
    bool result_delete = tree.deleteItem(item_to_delete);

    if (result_delete) {
        std::cout << "Deleted item: " << item_to_delete << std::endl;
    } else {
        std::cout << "Item not found or tree is empty." << std::endl;
    }

    // Display the tree after deletion
    std::cout << "Tree after deletion:" << std::endl;
    tree.inOrder(tree.getRoot());

    // Insert some elements into tree1
    tree1.putItem(10);
    tree1.putItem(5);
    tree1.putItem(15);

    // tree1
    std::cout << "Original tree (tree1):" << std::endl;
    tree1.inOrder(tree1.getRoot()); // Assuming you have an inOrder function

    // Use the operator= function to copy tree1 to tree2
    tree2 = tree1;

    // tree2
    std::cout << "Tree after assignment (tree2):" << std::endl;
    tree2.inOrder(tree2.getRoot());

    return 0;
}

