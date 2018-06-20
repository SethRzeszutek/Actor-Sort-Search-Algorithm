
//  Rzeszutek_Assignment11
//
//  Created by Seth Rzeszutek
//  Date:11/26/17
//

#include "stdafx.h"
#include "LinkedList.h"
#include "LinkedNodes.h"
#include "OuterLinkedList.h"
#include "OuterLinkedListNodes.h"
#include <iostream>
#include <algorithm> // for  transform
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <time.h>               ////DELETE
using namespace std;

void printVector(vector<vector<string>> returnVector)
//PURPOSE: Prints vector
//VARIABLES: returnVector( Vector to be displayed)
//RETURN: NONE
{
    //cout <<"returnVector size: "<< returnVector.size() << endl;
    
    for (vector<std::vector<int>>::size_type i=0; i < returnVector.size(); i++)         //cycle throough returnvector[i]
    {
        for (vector<std::vector<int>>::size_type j=0; j < returnVector[i].size(); j++)  //cycle throough returnvector[i][j]
        {
            cout << returnVector[i][j] << ",";
        }
        cout << endl;
        cout << endl;
    }
    cout<<endl;
}


void testPrintVector(vector<vector<string>> returnVector)
//PURPOSE: Prints vector
//VARIABLES: returnVector( Vector to be displayed)
//RETURN: NONE
{
    //cout <<"returnVector size: "<< returnVector.size() << endl;
    
    for (vector<std::vector<int>>::size_type i=0; i < returnVector.size(); i++)         //cycle throough returnvector[i]
    {
            cout << returnVector[0][i] << " ";
    }
    cout<<endl;
}

int countWords(string textFileName)
//PURPOSE: Counts words in file
//VARIABLES: textFileName( A string that includes the filepath)
//RETURN: count(number of words)
{
    //Previously used more when using arrays instead of vectors, you can see that would be more difficult
    int count = 0;
    ifstream myfile;
    string word;
    myfile.open(textFileName);
    while (myfile >> word)
    {
        ++count;
    }
    myfile.close();
    return count;
}


vector<vector<string>> getFileData(string textFileName)
//PURPOSE: Grabs file Data
//VARIABLES: textFileName( A string that includes the filepath)
//RETURN: returnString( String that contains the data from the text file)
{
    
    //string appPath = Path.GetDirectoryName(Application.ExecutablePath);
    string line ,tempFileString;
    int count = 0;
    ifstream myfile;
    string fileLocation;
    vector<string> dataList;
    
    vector<vector<string>> returnVector;
    
    count = countWords(textFileName);
    //string* fileArray = new string[count];      //new fileArray, this is what is left over after my transitions from Arrays to Vectors, it works fine so it could not hurt to keep
    myfile.open(textFileName);                  //opens the file
    
    //int i = 0;
    while (getline(myfile, line, '\n'))   // You can have a different delimiter
    {
        dataList.push_back(line);
        
    }
    for (int i=0; i< dataList.size(); i++)    //parse all strings in the tempvector by space
    {
        string value;
        vector<string> tempdataList;
        
        
        // For each character in the string
        for (string::const_iterator iter = dataList[i].begin(); iter != dataList[i].end(); iter++)
        {
            // If we've hit the terminal character
            if (*iter == '\t')
            {
                // If we have some characters accumulated
                if (!value.empty())
                {
                    // Add them to the result vector
                    tempdataList.push_back(value);
                    value.clear();
                }
            }
            else
            {
                // Accumulate the next character into the sequence
                value += *iter;
            }
        }
        if (!value.empty())
        {
            tempdataList.push_back(value);
        }
        
        returnVector.push_back(tempdataList);
    }

    //printVector(returnVector);
    myfile.close();
    
    return returnVector;
}





int main() {
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Start time:" << asctime(timeinfo) << endl;
    
    
    
    string textFileName = "movies2005.txt";
    //string textFileName;
    
    string returnString,test;
    vector<vector<string>> dataList;
    
    dataList=getFileData(textFileName);
    LinkedList listOne, listTwo, listThree, actorList, movieList, testList;
    OuterLinkedList OuterList, cleanedList;
    OuterLinkedList ActorNetwork, testOuter, testOuterFinal;
    
    
    
    
    
    
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Pulled Data from Text:" << asctime(timeinfo) << endl;
    
    
    
    
    
    
    
    for (vector<std::vector<int>>::size_type i=0; i < dataList.size(); i++)         //cycle throough returnvector[i]
    {
        LinkedList tempLinkedList;
        for (vector<std::vector<int>>::size_type j=0; j < dataList[i].size(); j++)  //cycle throough returnvector[i][j]
        {
            tempLinkedList.enqueue(dataList[i][j]);
            //cout << returnVector[i][j] << ",";
        }
        OuterList.insertLinked(tempLinkedList);
    }
    
    
    
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Data put into 2D Linked List:" << asctime(timeinfo) << endl;
    
    
    
    
    
    
    //OuterList.displayLinked();
    //OuterList.searchOuter("Mr. Cee");
    
    //(OuterList.cycleOuter(5)).displayList();
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Create Actor Linked List and Movie Linked List:" << asctime(timeinfo) << endl;

    
    
    
    
    
    
    
    
    //actorList = OuterList.getAllActors(OuterList);
    
    //cout << "Number of actors:" << actorList.GetCount() << endl;
    ActorNetwork = OuterList.createNetwork(OuterList);
    
    
    
    
    
    
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "Create Actor Network:" << asctime(timeinfo) << endl;

    
    
    
    
    
    
    
    
    //ActorNetwork.displayLinked();
    
    
    /*
    listOne.enqueue("z");
    listOne.enqueue("a");
    listOne.enqueue("b");
    listOne.enqueue("c");
    listOne.enqueue("d");
    listOne.enqueue("e");
    listOne.enqueue("f");
    
    listTwo.enqueue("z");
    listTwo.enqueue("g");
    listTwo.enqueue("h");
    listTwo.enqueue("i");
    listTwo.enqueue("j");
    listTwo.enqueue("k");
    listTwo.enqueue("f");
    
    listThree.enqueue("z");
    listThree.enqueue("l");
    listThree.enqueue("m");
    listThree.enqueue("n");
    listThree.enqueue("o");
    listThree.enqueue("k");
    listThree.enqueue("q");
    //listOne.search("d");
    
    //listOne.displayList();
    //listTwo = listOne.returnRest(listOne, "f");
    //listTwo.displayList();
    
    for(int i=0;i<(listThree.convertToVector()).size();i++)
    {
        cout << (listThree.convertToVector())[i];
    }
    
    testOuter.insertLinked(listOne);
    testOuter.insertLinked(listTwo);
    testOuter.insertLinked(listThree);
    
    //testOuterFinal = testOuter.createNetwork(testOuter);
    //testOuterFinal.displayLinked();
    
    */
    
    
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    cout << "End time:" << asctime(timeinfo) << endl;
   
    cout << "Made it to the end." << endl;
    
    return 0;
}
