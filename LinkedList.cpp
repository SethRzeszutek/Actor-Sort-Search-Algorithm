//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "LinkedList.h"
#include <vector>

LinkedList::LinkedList()
{
    first = NULL;  last = NULL;
}

bool LinkedList::isEmpty()
{
    return (first == NULL);
}

void LinkedList::insertFirst(string d)
{
    Node* newLink = new Node(d);
    newLink->SetNext(first);
    first = newLink;
}

Node* LinkedList::deleteFirst()
{
    Node* temp = first;
    first = first->GetNext();
    return temp;
}

void LinkedList::insertLast(string d)
{
    Node* newLink = new Node(d);
    if (this->isEmpty())
    {
        first = newLink;
    }
    else
    {
        last->SetNext(newLink);
    }
    last = newLink;
}

void LinkedList::displayList()
{
    //cout << "List (first to last) is: " << endl;
    Node* current = first;
    if (current == NULL)
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout <<  current->GetString() << "," ;
            current = current->GetNext();
        }
        cout << " " << endl;
        cout << " " << endl;
    }
    
}

void LinkedList::displayStack()
{
    cout << "List (top to bottom) is: " << endl;
    Node* current = first;
    if (current == NULL)
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        while (current != NULL)
        {
            cout << "  " << current->GetString();
            current = current->GetNext();
        }
        cout << " " << endl;
    }
    
}


Node* LinkedList::delItem(string k)
{
    Node* current = first;
    Node* previous = first;
    while (current->GetString() != k)
    {
        if (current->GetNext() == NULL)
        {
            return NULL;
            
        }   else
        {
            previous = current;
            current = current->GetNext();
        }
    }
    if (current == first)
    {
        first = first->GetNext();
        
    }
    else
    {
        previous->SetNext(current->GetNext());
    }
    return current;
}
void LinkedList::makeEmpty()
{
    first = NULL;
    last = NULL;
}

void LinkedList::push(string d)
{
    insertFirst(d);
}

string LinkedList::pop()
{
    return deleteFirst()->GetString();
}

void LinkedList::enqueue(string d)
{
    insertLast(d);
}
string LinkedList::dequeue()
{
    return deleteFirst()->GetString();
}

LinkedList* LinkedList::appendList(LinkedList* b)
{
    while (!(b->isEmpty()))
    {
        this->insertLast(b->deleteFirst()->GetString());
        
    }
    return this;
    
}


int LinkedList::GetCount()
//PURPOSE: to count length
//VARIABLES: NONE
//RETURN: numberCount(integer)
{
    Node* current = first;
    int numberCount = 0;
    while (current != NULL)             //adds to a variable for each item in teh list
    {
        numberCount++;
        current = current->GetNext();
    }
    return numberCount;
}


bool LinkedList::search(string toSearch)
{
    Node* current = first;
        
    while (current != NULL)
    {
        if(toSearch == current->GetString())
        {
            //cout << "Found: " << current->GetString() << endl;
            return true;
        }
        else
        current = current->GetNext();
    }
    return false;
};



string LinkedList::cycle(int index)
{
    Node* current = first;
    int numberCount = 0;
    string returnString;
    while (current != NULL)             //adds to a variable for each item in teh list
    {
        if(index == numberCount)
        {
            returnString = current->GetString();
            return returnString;
        }
        numberCount++;
        current = current->GetNext();
    }
    return "Error";
}

LinkedList LinkedList::returnRest(LinkedList startList, string aString)
{
    startList.delItem(aString);
    return startList;
}

vector<string> LinkedList::convertToVector()
{
    Node* current = first;
    vector<string> vector;
    while (current != NULL)             //adds to a variable for each item in teh list
    {
        vector.push_back(current->GetString());
        current = current->GetNext();
    }
    return vector;

}

