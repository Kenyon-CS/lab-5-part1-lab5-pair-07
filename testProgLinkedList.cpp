//This program tests various operation of a linked list
//34 62 21 90 66 53 88 24 10 -999

#include <iostream>               //Line 1
#include <cassert>                //Line 2 (Needed for search/delete index)
#include "unorderedLinkedList.h"  //Line 3

using namespace std;              //Line 4

int main()                        //Line 5
{                                 //Line 6
    unorderedLinkedList<int> list1, list2;    //Line 7
    int num;                      //Line 8

    cout << "Line 9: Enter integers ending "
         << "with -999" << endl;   //Line 9
    cin >> num;                   //Line 10

    while (num != -999)           //Line 11
    {                             //Line 12
        list1.insertLast(num);    //Line 13
        cin >> num;               //Line 14
    }                             //Line 15

    cout << endl;                 //Line 16

    cout << "Line 17: list1: ";   //Line 17
    list1.print();                //Line 18
    cout << endl;                 //Line 19
    cout << "Line 20: Length of list1: "
         << list1.length() << endl; //Line 20

    list2 = list1;    //test the assignment operator Line 21

    cout << "Line 22: list2: ";   //Line 22
    list2.print();                //Line 23
    cout << endl;                 //Line 24
    cout << "Line 25: Length of list2: "
         << list2.length() << endl; //Line 25

    cout << "Line 26: Enter the number to be "
         << "deleted: ";          //Line 26
    cin >> num;                   //Line 27
    cout << endl;                 //Line 28

    list2.deleteNode(num);        //Line 29

    cout << "Line 30: After deleting " << num
         << " list2: " << endl;   //Line 30
    list2.print();                //Line 31
    cout << endl;                 //Line 32

    cout << "Line 33: Length of list2: "
         << list2.length() << endl; //Line 33

    // -----------------------------------------------------
    // --- NEW TESTS START HERE ---
    // -----------------------------------------------------

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
    list2.deleteSmallest(); // Deletes 10
    cout << "Line 39: list2 is now: ";
    list2.print();
    cout << endl;

    cout << "Line 40: Testing searchIndex(3)." << endl;
    // Assuming 21 was deleted, list is: 34 90 66 53 88 24 34
    // Item at index 3 is 66
    cout << "Item at index 3: " << list2.searchIndex(3) << endl;

    cout << "Line 41: Testing deleteIndex(5)." << endl;
    // Deletes 5th element (88)
    list2.deleteIndex(5);
    cout << "Line 42: list2 is now: ";
    list2.print();
    cout << endl;

    cout << "Line 43: Testing rotate on list2." << endl;
    // List is: 34 90 66 53 24 34
    list2.rotate();
    cout << "Line 44: list2 is now: ";
    list2.print(); // List should be: 90 66 53 24 34 34
    cout << endl;

    cout << "Line 45: Testing rotate on list2 again." << endl;
    list2.rotate();
    cout << "Line 46: list2 is now: ";
    list2.print(); // List should be: 66 53 24 34 34 90
    cout << endl;


    // -----------------------------------------------------
    // --- ORIGINAL ITERATOR TEST (STILL WORKS ON list1) ---
    // -----------------------------------------------------

    cout << endl << "Line 47: Output list1 "
         << "using an iterator" << endl;  //Line 47

    linkedListIterator<int> it;           //Line 48

    for (it = list1.begin(); it != list1.end();
                             ++it)      //Line 49
        cout << *it << " ";           //Line 50
    cout << endl;                     //Line 51

    //system("pause");
    return 0;                         //Line 52
}                                     //Line 53
