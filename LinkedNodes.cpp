
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "LinkedNodes.h"

Node::Node() {
    this->someString = "";
    this->next = NULL;
}

Node::Node(string aNumber, Node* nextLoc) {
    this->someString = aNumber;
    this->next = nextLoc;
}

void Node::InsertAfter(Node* nodePtr) {
    Node* tmpNext = 0;
    
    tmpNext = this->next;
    this->next = nodePtr;
    nodePtr->next = tmpNext;
    
}
Node* Node::GetNext() {
    return this->next;
}

void Node::SetNext(Node* nodePtr) {
    this->next = nodePtr;
    
}

string Node::GetString() const {
    return this->someString;
}

void Node::PrintNodeInfo() {
    cout << this->someString << " ";
    
}

