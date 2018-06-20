
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//

#ifndef LinkedNodes_h
#define LinkedNodes_h

#include <stdio.h>
#include <string>
using namespace std;


class Node {
public:
    Node();
    Node(string aNumber,Node* nextLoc = 0);
    void InsertAfter(Node* nodePtr);
    void SetNext(Node* nodePtr);
    string GetString() const;
    Node* GetNext();
    void PrintNodeInfo();
private:
    string someString;
    Node* next;
    
};
#endif /* LinkedNodes_h */

