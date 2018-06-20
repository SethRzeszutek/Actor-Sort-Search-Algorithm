
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//


#include "stdafx.h"
#include <iostream>
using namespace std;
#include "OuterLinkedList.h"
#include "LinkedList.h"
#include <vector>



OuterLinkedList::OuterLinkedList()
{
    firstLinkedList = NULL;  lastLinkedList = NULL;
}

bool OuterLinkedList::isEmptyLinked()
{
    return (firstLinkedList == NULL);
}

void OuterLinkedList::insertLinked(LinkedList d)
{
    
    OuterNode* newLinkList = new OuterNode(d);
    if(this->isEmptyLinked())
    {
        firstLinkedList = newLinkList;
    }
    else
    {
        lastLinkedList->SetNextLinkedNode(newLinkList);
    }
    lastLinkedList = newLinkList;
    /*
    OuterNode* newLinkList = new OuterNode(d);
    newLinkList->SetNextLinkedNode(firstLinkedList);
    firstLinkedList = newLinkList;
     */
}
void OuterLinkedList::displayLinked()
{
    cout << "Linked list of linked lists: " << endl;
    OuterNode* currentLinked = firstLinkedList;
    LinkedList tempList;
    if (currentLinked == NULL)
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        while (currentLinked != NULL)
        {
            tempList = currentLinked->getLinkedList();
            tempList.displayList();
            currentLinked = currentLinked->GetNextLinkedNode();

            //cout << "currentlyLinked is not NULL" << endl;
        }
        cout << endl;
    }
}
bool OuterLinkedList::searchOuter(string someString)
{
    OuterNode* currentLinked = firstLinkedList;
    LinkedList tempList;
    bool result;
    if (currentLinked == NULL)
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        while (currentLinked != NULL)
        {
            tempList = currentLinked->getLinkedList();
            result = tempList.search(someString);
            if(result == true)
            {
                return true;
            }
            currentLinked = currentLinked->GetNextLinkedNode();
            
            //cout << "currentlyLinked is not NULL" << endl;
        }
    }
    return false;
}

int OuterLinkedList::GetOuterCount()
{
    OuterNode* currentLinked = firstLinkedList;
    int numberCount = 0;
    while (currentLinked != NULL)             //adds to a variable for each item in teh list
    {
        numberCount++;
        currentLinked = currentLinked->GetNextLinkedNode();
    }
    return numberCount;
}





LinkedList OuterLinkedList::cycleOuter(int index)
{
    OuterNode* currentLinked = firstLinkedList;
    LinkedList tempList;
    int count = 0;
    
    
    int numberCount = 0;
    while (currentLinked != NULL)             //adds to a variable for each item in teh list
    {
        numberCount++;
        currentLinked = currentLinked->GetNextLinkedNode();
    }
    
    currentLinked = firstLinkedList;
    
    
    if(numberCount < index)
    {
        cout << "Error! Entered index too large! The index size of the list is 0-"<< numberCount << "." << endl;
        cout << "Printing what is in index "<< numberCount << "..." << endl;
    }
    
    if (currentLinked == NULL)
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        while (currentLinked != NULL)
        {
            tempList = currentLinked->getLinkedList();
            if(index == count)
            {
                return tempList;
            }
            currentLinked = currentLinked->GetNextLinkedNode();
            count++;
        }
    }
    return tempList;
}


LinkedList OuterLinkedList::getAllMovies(OuterLinkedList DataOuterList)
{
    LinkedList MovieList;
    for(int x=0; x<DataOuterList.GetOuterCount();x++)       //for each list in 2D-List
    {
        LinkedList tempList;
        tempList=DataOuterList.cycleOuter(x);
        for(int y=1;y<tempList.GetCount();y++)               //for each item in list- This is to create the correct amount of Lists for our 2-D list
        {
            if(MovieList.search(tempList.cycle(0)) != true)
            {
                MovieList.enqueue(tempList.cycle(0));
            }
        }
    }
    
    return MovieList;
}


LinkedList OuterLinkedList::getAllActors(OuterLinkedList DataOuterList)
{
    LinkedList ActorList;
    for(int x=0; x<DataOuterList.GetOuterCount();x++)       //for each list in 2D-List
    {
        LinkedList tempList;
        tempList=DataOuterList.cycleOuter(x);
        for(int y=1;y<tempList.GetCount();y++)               //for each item in list- This is to create the correct amount of Lists for our 2-D list
        {
            if(ActorList.search(tempList.cycle(y)) != true)
            {
            ActorList.enqueue(tempList.cycle(y));
            }
        }
    }
    
    return ActorList;
}


OuterLinkedList OuterLinkedList::deleteAllMovies(OuterLinkedList DataOuterList)
{
    OuterLinkedList returnList;
    LinkedList randomList;
    for(int x=0; x<DataOuterList.GetOuterCount();x++)       //for each list in 2D-List
    {
        LinkedList tempList;
        tempList=DataOuterList.cycleOuter(x);
        for(int y=1;y<tempList.GetCount();y++)               //for each item in list- This is to create the correct amount of Lists for our 2-D list
        {
            if(tempList.search(tempList.cycle(0)) != true)
            {
                
            }
        }
        tempList.delItem(tempList.cycle(0));
        returnList.insertLinked(tempList);
    }
    return returnList;
}

LinkedList OuterLinkedList::compareAndAdd(LinkedList startList, OuterLinkedList fullList)
{
    LinkedList fullActorList;
    int tempListCount = startList.GetCount();
    for(int x=0; x<tempListCount;x++)       //for each item in List
    {
        string actor = startList.cycle(x);
        int fullListCount = fullList.GetOuterCount();
        for(int y=0; y<fullListCount;y++)       //for each list in 2D-List
        {
            LinkedList tempList = fullList.cycleOuter(y);
            int tempListCount = tempList.GetCount();
            for(int z=0;z<tempListCount;z++)
            {
                string tempCompare = tempList.cycle(z);
                //cout << actor << " == " << tempCompare <<endl;
                if(actor == tempCompare)
                {
                    LinkedList temp;
                    temp = tempList.returnRest(tempList, actor);
                    for(int a=0;a<(tempListCount);a++)
                    {
                        string item = temp.cycle(a);
                        fullActorList.enqueue(item);
                        fullActorList.delItem(actor);
                    }
                }
            }
        }
    }
    return fullActorList;
}













OuterLinkedList OuterLinkedList::createNetwork(OuterLinkedList DataOuterList)
{
    
    OuterLinkedList ActorNetwork, noMovieFullList;
    LinkedList ActorList= DataOuterList.getAllActors(DataOuterList);
    LinkedList allActorList, allMovieList;
    //LinkedList tempActorList;
    
    
    
    
    allActorList = DataOuterList.getAllActors(DataOuterList);
    
    cout << "Number of actors:" << allActorList.GetCount() << endl;
    
    allMovieList = DataOuterList.getAllMovies(DataOuterList);
    
    cout << "Number of Movies:" << allMovieList.GetCount() << endl;
    
    noMovieFullList = DataOuterList.deleteAllMovies(DataOuterList);
    
    //cleanedList.displayLinked();
    //actorList.displayList();
    //movieList.displayList();
    
    cout << "Progress Load:" << endl;
    int ActorListCount = ActorList.GetCount();
    for(int z=0;z<ActorListCount;z++)               //for each item in list- This is to create the correct amount of Lists for our 2-D list
    {
        LinkedList oneLineActorList;
        string actorToCompare = ActorList.cycle(z);
        cout << "*" ;
        int noMovieFullListCount = noMovieFullList.GetOuterCount();
        for(int x=0; x<noMovieFullListCount;x++)                //for each list in 2D-List
        {
            LinkedList eachLineList;
            eachLineList=noMovieFullList.cycleOuter(x);         //each list in the 2Dlist
            int eachLineCount = eachLineList.GetCount();
            for(int y=0;y<eachLineCount;y++)                    //for each item in list
            {
                string actorInList = eachLineList.cycle(y);     //grabs actor in list
                if(actorToCompare==actorInList)                 //if actor grabbed from list matches actor name fromthe ActorList
                {
                    LinkedList newList;
                    newList = eachLineList;
                    //eachLineList.displayList();
                    string actor = newList.cycle(y);
                    //int eachLineListCount2 = eachLineList.GetCount();
                    for(int t=0;t<eachLineCount;t++)                    //for each item in list
                    {
                        oneLineActorList.enqueue(newList.cycle(t));     //we push each
                    }
                    //oneLineActorList = noMovieFullList.compareAndAdd(newList, noMovieFullList);
                    oneLineActorList = oneLineActorList.returnRest(oneLineActorList, actor);
                    
                    oneLineActorList.insertFirst(actor);
                }
            }
        }
        ActorNetwork.insertLinked(oneLineActorList);
    }
    
    cout << endl;
    
    return ActorNetwork;
}










OuterLinkedList OuterLinkedList::createActorNetwork(LinkedList actorList)
{
    OuterNode* currentLinked = firstLinkedList;
    OuterLinkedList returnOuterLink;
    LinkedList tempLinkedList;
    vector<string> tempVector, actorVector, finalVector;
    int count = 1;

    while (currentLinked != NULL)             //adds to a variable for each item in teh list
    {
        vector<string>  finalVector;
        tempLinkedList=firstLinkedList->getLinkedList();
        tempVector = tempLinkedList.convertToVector();
        actorVector = actorList.convertToVector();
        
        for(int i=0;i<actorVector.size();i++)
        {
           
            for(int j=0;j<tempVector.size();j++)
            {
                
                if(tempVector[j]==actorVector[i])
                {
                    //cout << tempVector[j]<<"==" << actorVector[i]<<endl;
                    cout << count << " ";
                    count++;
                    finalVector.push_back(tempVector[j]);
                }
            }
        }
        currentLinked = currentLinked->GetNextLinkedNode();
    }
    cout << endl;
    cout << finalVector.size() <<endl;
    for(int i=0;i<finalVector.size();i++)
    {
        cout << finalVector[i] << " ";
    }
    cout << endl;
    
    return returnOuterLink;
}


