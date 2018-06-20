
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//

#ifndef LinkedList_h
#define LinkedList_h
#include "LinkedNodes.h"
using namespace std;
#include <iostream>
#include <stdio.h>
#include <string>

class LinkedList
{
private:
    Node* first;
    Node* last;
public:
    LinkedList();
    bool isEmpty();
    void insertFirst(string d);
    Node* deleteFirst();
    void insertLast(string d);
    void displayList();
    void displayStack();
    Node* delItem(string k);
    void makeEmpty();
    void push(string d);
    string pop();
    void enqueue(string d);
    string dequeue();
    int GetCount();
    bool search(string toSearch);
    string cycle(int index);
    LinkedList returnRest(LinkedList startList, string aString);
    vector<string> convertToVector();
    //void fillQueueWithNumbers(LinkedList& list, int length);
    LinkedList* appendList(LinkedList* b);
};



#endif /* LinkedList_h */

