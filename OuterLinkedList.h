
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//


#ifndef OuterLinkedList_h
#define OuterLinkedList_h

#include <stdio.h>
#include "OuterLinkedListNodes.h"



class OuterLinkedList
{
private:
    OuterNode* firstLinkedList;
    OuterNode* lastLinkedList;
public:
    OuterLinkedList();
    bool isEmptyLinked();
    void insertLinked(LinkedList d);
    void displayLinked();
    bool searchOuter(string someString);
    OuterLinkedList createActorNetwork(LinkedList actorList);
    OuterLinkedList createNetwork(OuterLinkedList DataOuterList);
    LinkedList cycleOuter(int index);
    LinkedList getAllActors(OuterLinkedList DataOuterList);
    LinkedList getAllMovies(OuterLinkedList DataOuterList);
    OuterLinkedList deleteAllMovies(OuterLinkedList DataOuterList);
    LinkedList compareAndAdd(LinkedList startList, OuterLinkedList fullList);
    int GetOuterCount();
};

#endif  /*OuterLinkedList_h */
 
