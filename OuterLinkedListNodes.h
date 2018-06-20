
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//

#ifndef OuterLinkedListNodes_h
#define OuterLinkedListNodes_h

#include <stdio.h>
#include "LinkedList.h"


class OuterNode {
public:
    OuterNode();
    OuterNode(LinkedList aLinkedList,OuterNode* nextLinkedLoc = 0);
    void SetNextLinkedNode(OuterNode* nodeOuterPtr);
    OuterNode* GetNextLinkedNode();
    void InsertAfterLinkedNode(OuterNode* nodeOuterPtr);
    LinkedList getLinkedList();
    
private:
    LinkedList someLinkedList;
    OuterNode* nextLinkedList;
    
};


#endif /* OuterLinkedListNodes_h */
