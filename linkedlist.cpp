#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

void LinkedList::AddNode(Node* head, Node* Temp,int num, int count)
{
    
    while(Temp->next!=NULL) // loops throught the linked list until it reaches the last element
    {
        Temp=Temp->next;
    }
    
    Temp->next=new Node;// creates a new variable of type node in the heap
    Temp->data=num;
    Temp->occurance=count;
    Temp->next->next=NULL;
}

void LinkedList::RemoveNode(Node* head, Node* Temp , Node* p)
{
    
    while(p->next!=NULL)// lops through until temp is pointing to the element before the last element in the linked list
    {
        p=p->next;
        Temp=Temp->next;
    }
    
    delete Temp->next;
    Temp->next=NULL;
    
}

void LinkedList::Printlist(Node* head, Node* Temp)
{
    
    while(Temp->next!=NULL)// loops through the linked list and prints the number stored in each node and the occurance of that number in the vector
    {
        cout<<"Num: "<<Temp->data<<" occurrence: "<<Temp->occurance<<endl;
        Temp=Temp->next;
    }
}

LinkedList LinkedList::create(LinkedList q, vector<int> v, int size, Node* head, Node* Temp, vector <int> v2)// creates the linked list
{
    int count;
    int temp;
   
       for(int i=0 ; i<v.size() ; i++)// loops for the number of elements in the vector
       {
           count=0;
           temp=v.at(i);
           
           for(int j=0 ; j<v.size() ; j++)// checks for the number of times each element is stored in the vector
           {
               
              if(temp==v.at(j) && temp!=-1) // checks if the element stored in temp is equal to any of the elements stored in the vector
               {
                   count++;
                   if(v2[i]==0)
                   {
                       v2.at(i)=v.at(i);
                   }
                   v[j]=-1;// changes the values of the vector to -1 if it is found in the vector
               }
           }
           
           if(count>0)// adds a node at the end of the linked list for each element and their occurance
           {
               q.AddNode(head, Temp, v2.at(i),count);
           }
          
       }
    
    return q;
}

int LinkedList::sum_nodes(Node* head, Node* Temp)// adds all the values of the vector together
{
    int sum=0;
    
    while(Temp->next!=NULL)// loops through the linked list and gets the sum of all the elements in the linked list
    {
        sum=sum+(Temp->data*Temp->occurance);
        Temp=Temp->next;
    }
    
    return sum;
}
