#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType.
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
//class unorderedLinkedList: public linkedListType<Type>
class unorderedLinkedList: public linkedListType<int>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to
      //    the last node, and count is incremented by 1.
      //

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem
      //    is deleted from the list. first points to the first
      //    node, last points to the last node of the updated
      //    list, and count is decremented by 1.

    void deleteSmallest(); 

    void deleteItems(const Type& deleteItem); 

    Type searchIndex(const int index) const; 

    void deleteIndex(const int index); 

    void rotate();
};


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = first; //set current to point to the first
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == NULL)   //if the list was empty, newNode is also
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode
                              //to NULL

    if (first == NULL)  //if the list is empty, newNode is
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2: the node to be deleted is the first node
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem)
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted
                                       //was the last node
                    last = trailCurrent; //update the value
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode

template <class Type>
void unorderedLinkedList<Type>::deleteSmallest() {
    nodeType<Type> *current = first->link;
    nodeType<Type> *previous = first;
    nodeType<Type> *minPtr = first;
    nodeType<Type> *deletePtr;
    if (first == NULL) {
        cout << "The Linked List is empty" << endl;
        return;
    } else if (first->link == NULL) {
        delete first; 
        first = NULL; 
        return; 
    }
    while (current != NULL) {
        if (current->info < minPtr->info) {
            minPtr = current;
            deletePtr = previous;
        }
        
        previous = current;
        current = current->link;
    }
    if (minPtr == first) {
        first = first->link;
    } else {
        deletePtr->link = minPtr->link; 
    } 
    delete minPtr; 
}

template <class Type>
void unorderedLinkedList<Type>::deleteItems(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;
    bool atLeastOneFound = false; 

    if (first == NULL)    //Case 1; the list is empty.
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        while (first != NULL && first->info == deleteItem) //Case 2: the node to be deleted is the first node
        {
            atLeastOneFound = true; 
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        if (first == NULL) { //end the implementation if the LL becomes empty
            return; 
        }
         //search the list for the node with the given info
        found = false;
        trailCurrent = first;  //set trailCurrent to point
                               //to the first node
        current = first->link; //set current to point to
                               //the second node

        while (current != NULL) 
        {
            if (current->info != deleteItem)
            {
                trailCurrent = current;
                current = current-> link;
            }
            else {
                found = true;
                atLeastOneFound = true; 
            }

            if (found) //Case 3; if found, delete the node 
            {
            trailCurrent->link = current->link;
            count--;

            if (last == current) 
                last = trailCurrent; 

            delete current;  
            }
            current = trailCurrent->link; 
            found = false;
        }//end while
        if (!atLeastOneFound) {
            cout << "The item to be deleted is not in "
                 << "the list." << endl;
        }
    }//end else
}//end deleteNode

template <class Type>
Type unorderedLinkedList<Type>::searchIndex(const int index) const {
    nodeType<Type> *current = first;
    int count = 1; 
    if (first==NULL) {
        cout << "Cannot search in an empty list" << endl; 
        assert(false); 
    } else {
        if (count == index) {
            return first->info; 
        }
        while (count < index && current != NULL) {
            current = current->link; 
            count++;
        }
        if (current == NULL) {
        cout << "Error: Index " << index << " is out of bounds." << endl;
        assert(false);
    }
        return current->info; 
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteIndex(const int index) {
    if (index < 1) {
        cout << "Error: Index " << index << " is invalid. Must be 1 or greater." << endl;
        assert(false);
    }
    nodeType<Type> *current = first;
    nodeType<Type> *trailCurrent = nullptr;
    int count = 1; 
    if (first==NULL) {
        cout << "Cannot remove item in an empty list" << endl; 
        assert(false); 
    } else {
        if (count == index) {
            current = first; 
            first = first -> link; 
            if (first == NULL) {
            last = NULL;
            }
            delete current;
            return;
        }
        while (count < index && current != NULL) {
            trailCurrent = current;
            current = current->link; 
            count++;
        }
        if (current == NULL) {
            cout << "Error: Index " << index << " is out of bounds." << endl;
            assert(false);
        }
        trailCurrent->link = current->link;
        
        if (last == current) {
            last = trailCurrent;
        }

        delete current;  
    }
}

template <class Type>
void unorderedLinkedList<Type>::rotate() {
    if (first == NULL || first->link == NULL) {
        return;
    }
    nodeType<Type> *nodeToMove = first;
    first = first->link;
    last->link = nodeToMove;
    last = nodeToMove;
    last->link = NULL;
}

#endif
