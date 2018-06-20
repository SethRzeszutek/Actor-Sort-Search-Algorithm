
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//


#include "stdafx.h"
#include <iostream>
using namespace std;
#include "OuterLinkedListNodes.h"
#include "LinkedList.h"


OuterNode::OuterNode() {
    this->someLinkedList = someLinkedList;
    this->nextLinkedList = NULL;
}
OuterNode::OuterNode(LinkedList aLinkedList, OuterNode* nextLinkedLoc) {
    this->someLinkedList = aLinkedList;
    this->nextLinkedList = nextLinkedLoc;
}
void OuterNode::SetNextLinkedNode(OuterNode* nodeOuterPtr) {
    this->nextLinkedList = nodeOuterPtr;
    
}
OuterNode* OuterNode::GetNextLinkedNode() {
    return this->nextLinkedList;
    
}
void OuterNode::InsertAfterLinkedNode(OuterNode* nodeOuterPtr) {
    OuterNode* tmpNext = 0;
    tmpNext = this->nextLinkedList;
    this->nextLinkedList = nodeOuterPtr;
    nodeOuterPtr->nextLinkedList = tmpNext;
}
LinkedList OuterNode::getLinkedList()
{
    return this->someLinkedList;
}
