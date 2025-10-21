//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999

#include <iostream>               //Line 1
#include <cassert>                //Line 2 (Needed for search/delete index)
#include "unorderedLinkedList.h"  //Line 3

#include <iostream>
#include "unorderedLinkedList.h" // Assumes linkedList.h is included by this file

using namespace std;

int main()                          //Line 5
{                                   //Line 6
    unorderedLinkedList<int> list1, list2;  //Line 7
    int num;                            //Line 8

    cout << "Line 9: Enter integers ending "
         << "with -999" << endl;     //Line 9
    cin >> num;                         //Line 10

    while (num != -999)                 //Line 11
    {                                   //Line 12
        list1.insertLast(num);      //Line 13
        cin >> num;                 //Line 14
    }                                   //Line 15

    cout << endl;                       //Line 16

    cout << "Line 17: list1: ";         //Line 17
    list1.print();                      //Line 18
    cout << endl;                       //Line 19
    cout << "Line 20: Length of list1: "
         << list1.length() << endl; //Line 20

    list2 = list1;  //test the assignment operator Line 21

    cout << "Line 22: list2: ";         //Line 22
    list2.print();                      //Line 23
    cout << endl;                       //Line 24
    cout << "Line 25: Length of list2: "
         << list2.length() << endl; //Line 25

    cout << "Line 26: Enter the number to be "
         << "deleted: ";             //Line 26
    cin >> num;                         //Line 27
    cout << endl;                       //Line 28

    list2.deleteNode(num);              //Line 29

    cout << "Line 30: After deleting " << num
         << " list2: " << endl;     //Line 30
    list2.print();                      //Line 31
    cout << endl;                       //Line 32

    cout << "Line 33: Length of list2: "
         << list2.length() << endl; //Line 33

    cout << endl;
    cout << "Line 34: Adding 34 and 62 to list2 for more tests." << endl;
    list2.insertLast(34);
    list2.insertLast(62);
    cout << "Line 35: list2 is now: ";
    list2.print();
    cout << endl;

    cout << "Line 36: Testing deleteItems(62) on list2." << endl;
    list2.deleteItems(62); // Deletes both 62s
    cout << "Line 37: list2 is now: ";
    list2.print();
    cout << endl;

    cout << "Line 38: Testing deleteSmallest on list2." << endl;
    list2.deleteSmallest(); // Deletes 10 (assuming 10 was smallest)
    cout << "Line 39: list2 is now: ";
    list2.print();
    cout << endl;

    cout << "Line 40: Testing searchIndex(3)." << endl;
    // Assuming 10 and one 62 were deleted.
    // If original was 10 62 21 90 66 53 88 24
    // And list1 was copied, then 21 deleted, 34, 62 added:
    // list2: 10 62 90 66 53 88 24 34 62
    // deleteItems(62): 10 90 66 53 88 24 34
    // deleteSmallest(10): 90 66 53 88 24 34
    // Item at index 3 is 53
    cout << "Item at index 3: " << list2.searchIndex(3) << endl;

    cout << "Line 41: Testing deleteIndex(5)." << endl;
    // Deletes 5th element (24)
    list2.deleteIndex(5);
    cout << "Line 42: list2 is now: ";
    list2.print();
    cout << endl;

    cout << "Line 43: Testing rotate on list2." << endl;
    // List is: 90 66 53 88 34
    list2.rotate();
    cout << "Line 44: list2 is now: ";
    list2.print(); // List should be: 66 53 88 34 90
    cout << endl;

    cout << "Line 45: Testing rotate on list2 again." << endl;
    list2.rotate();
    cout << "Line 46: list2 is now: ";
    list2.print(); // List should be: 53 88 34 90 66
    cout << endl;

    cout << endl << "--- Starting Extreme Case Tests ---" << endl;
    unorderedLinkedList<int> testList;

    cout << endl << "Line 47: Testing deleteSmallest on empty list." << endl;
    testList.deleteSmallest(); // Should print "The Linked List is empty"
    cout << "Line 48: testList is now: ";
    testList.print();
    cout << endl;

    cout << "Line 49: Testing deleteSmallest on one-item list." << endl;
    testList.insertLast(100);
    cout << "List before: "; testList.print(); cout << endl;
    testList.deleteSmallest(); // Should empty the list
    cout << "Line 50: testList is now: ";
    testList.print(); // Should be empty
    cout << endl;

    cout << "Line 51: Testing deleteSmallest with duplicates (smallest first)." << endl;
    testList.insertLast(5);
    testList.insertLast(10);
    testList.insertLast(5);
    testList.insertLast(20);
    cout << "List before: "; testList.print(); cout << endl;
    testList.deleteSmallest(); // Should delete the *first* 5
    cout << "Line 52: testList is now: ";
    testList.print(); // Should be: 10 5 20
    cout << endl;

    cout << "Line 53: Testing deleteSmallest (smallest last)." << endl;
    testList.deleteSmallest(); // Deletes the 5
    cout << "Line 54: testList is now: ";
    testList.print(); // Should be: 10 20
    cout << endl;
    
    testList.destroyList(); // Clean up for next test

    cout << endl << "Line 55: Testing deleteItems on empty list." << endl;
    testList.deleteItems(10); // Should print "Cannot delete..."
    
    cout << "Line 56: Testing deleteItems on one-item list (item found)." << endl;
    testList.insertLast(10);
    cout << "List before: "; testList.print(); cout << endl;
    testList.deleteItems(10); // Should empty the list
    cout << "Line 57: testList is now: ";
    testList.print(); // Empty
    cout << endl;

    cout << "Line 58: Testing deleteItems on one-item list (item not found)." << endl;
    testList.insertLast(20);
    cout << "List before: "; testList.print(); cout << endl;
    testList.deleteItems(10); // Should print "The item... not in list"
    cout << "Line 59: testList is now: ";
    testList.print(); // 20
    cout << endl;

    cout << "Line 60: Testing deleteItems to delete ALL items." << endl;
    testList.destroyList();
    testList.insertLast(5);
    testList.insertLast(5);
    testList.insertLast(5);
    cout << "List before: "; testList.print(); cout << endl;
    testList.deleteItems(5); // Should empty the list
    cout << "Line 61: testList is now: ";
    testList.print(); // Empty
    cout << endl;

    testList.destroyList();
    testList.insertLast(10);
    testList.insertLast(20);
    testList.insertLast(30);
    cout << endl << "Line 62: testList is: ";
    testList.print(); // 10 20 30
    cout << endl;

    cout << "Line 63: Testing searchIndex(1) (first item)." << endl;
    cout << "Item at index 1: " << testList.searchIndex(1) << endl; // Should be 10

    cout << "Line 64: Testing searchIndex(3) (last item)." << endl;
    cout << "Item at index 3: " << testList.searchIndex(testList.length()) << endl; // Should be 30

    cout << "Line 65: Testing deleteIndex(1) (first item)." << endl;
    testList.deleteIndex(1);
    cout << "Line 66: testList is now: ";
    testList.print(); // 20 30
    cout << endl;

    cout << "Line 67: Testing deleteIndex(2) (last item)." << endl;
    testList.deleteIndex(testList.length()); // length is 2
    cout << "Line 68: testList is now: ";
    testList.print(); // 20
    cout << endl;
    
    cout << "Line 69: Testing deleteIndex(1) (only item)." << endl;
    testList.deleteIndex(1);
    cout << "Line 70: testList is now: ";
    testList.print(); // Empty
    cout << endl;

    cout << endl << "--- Testing Invalid Index Cases ---" << endl;
    
    cout << "Line 71: Testing searchIndex BUG: index 0 or negative." << endl;
    testList.insertLast(99);
    cout << "List is: "; testList.print(); cout << endl;
    cout << "Item at index 0: " << testList.searchIndex(0) << endl; // Bug: returns 99
    cout << "Item at index -5: " << testList.searchIndex(-5) << endl; // Bug: returns 99
    
    cout << endl << "--- The following tests will cause assertion failures ---" << endl;
    cout << "Note: Uncommenting these lines will terminate the program." << endl;
    
    // cout << "Line 72: Testing searchIndex out of bounds (Asserts)." << endl;
    // testList.searchIndex(5); // Asserts
    
    // cout << "Line 73: Testing deleteIndex out of bounds (Asserts)." << endl;
    // testList.deleteIndex(5); // Asserts

    // cout << "Line 74: Testing deleteIndex with invalid index 0 (Asserts)." << endl;
    // testList.deleteIndex(0); // Asserts
    
    testList.destroyList(); // Empty the list
    
    // cout << "Line 75: Testing deleteIndex on empty list (Asserts)." << endl;
    // testList.deleteIndex(1); // Asserts
    
    // cout << "Line 76: Testing searchIndex on empty list (Asserts)." << endl;
    // testList.searchIndex(1); // Asserts

    testList.destroyList();
    cout << endl << "Line 77: Testing rotate on empty list." << endl;
    testList.rotate();
    cout << "Line 78: testList is now: ";
    testList.print(); // Empty
    cout << endl;

    cout << "Line 79: Testing rotate on one-item list." << endl;
    testList.insertLast(50);
    cout << "List before: "; testList.print(); cout << endl;
    testList.rotate();
    cout << "Line 80: testList is now: ";
    testList.print(); // 50
    cout << endl;

    cout << "Line 81: Testing rotate on two-item list." << endl;
    testList.insertLast(60);
    cout << "List before: "; testList.print(); cout << endl;
    testList.rotate();
    cout << "Line 82: testList is now: ";
    testList.print(); // 60 50
    cout << endl;

    testList.rotate(); // Rotate back
    cout << "Line 83: Rotating back: ";
    testList.print(); // 50 60
    cout << endl;
    
    cout << "--- End of Extreme Case Tests ---" << endl;

    cout << endl << "Line 84: Output list1 "
         << "using an iterator" << endl;  //Line 84

    linkedListIterator<int> it;           //Line 85

    for (it = list1.begin(); it != list1.end();
                                 ++it)  //Line 86
        cout << *it << " ";           //Line 87
    cout << endl;                       //Line 88

    //system("pause");
    return 0;                           //Line 89
}                                       //Line 90