#include <iostream>
#include "list.h"
using namespace std;

LinkedList mergeSortedLists(LinkedList a, LinkedList b) {
    LinkedList result; // Create a new list to store the merged result
    int i = 0, j = 0;

    // Traverse both lists and merge
    while (i < a.getLength() && j < b.getLength()) {
        if (a.get(i) <= b.get(j)) {
            result.addBack(a.get(i));
            i++;
        } else {
            result.addBack(b.get(j));
            j++;
        }
    }

    // Add remaining elements from list `a`
    while (i < a.getLength()) {
        result.addBack(a.get(i));
        i++;
    }

    // Add remaining elements from list `b`
    while (j < b.getLength()) {
        result.addBack(b.get(j));
        j++;
    }

    return result;
}


int main() {
    LinkedList list1, list2;

    // Initialize list1 with sorted elements
    list1.addBack(1);
    list1.addBack(3);
    list1.addBack(5);

    // Initialize list2 with sorted elements
    list2.addBack(2);
    list2.addBack(4);
    list2.addBack(6);

    // Merge the two sorted lists
    LinkedList mergedList = mergeSortedLists(list1, list2);

    // Print the merged list
    mergedList.printList(); // Output: 1 2 3 4 5 6

    return 0;
}



