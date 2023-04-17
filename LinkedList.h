#ifndef LinkedList_h
#define LinkedList_h

#include "Node.h"
#include <vector>
using namespace std;

class LinkedList
{
public:
    void AddNode(Node* head, Node* Temp,int num,int count); // adds a node to the end of the linked list
    void RemoveNode(Node* head, Node* Temp ,Node* p); // removes a node at the end
    void Printlist(Node* head, Node* Temp);// prints the elements of the linked list
    LinkedList create(LinkedList q, vector<int> v , int size, Node* head, Node* Temp, vector <int> v2); // creates the linked list
    int sum_nodes(Node* head, Node* Temp); // adds the numbers in each node together
};

#endif
