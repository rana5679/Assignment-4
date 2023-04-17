#include <iostream>
#include <vector>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

void insertAfter(int firstValue, int secondValue, int size , vector <int> &v)// this function loops through the vector and looks for the first value and inserts the second value after it and pushes back the value that was in the position after the first value
{
    int Temp;
    
    for(int i=0; i<v.size() ; i++)// loops through the vector
    {
        if(firstValue==v[i])// looks for the first value in the vector
        {
            Temp=v[i+1];
            v.push_back(Temp);
            v[i+1]=secondValue;
        }
    }
}

int main()
{
    int size;
    
    cout<<"Enter the number of integers you want to enter"<<endl;
    cin>>size;
    int num;
    
    vector <int> v;
    
    for(int i=0 ; i<size; i++)// inputs the numbers into the vector
    {
        cout<<"Enter the number"<<endl;
        cin>>num;
        
        v.push_back(num);
    }
    
    vector <int> v2(100,0); // declares a second vector
    
    cout<<endl;
    
    int firstnum,secondnum;
    
    cout<<"Enter a number and another number you want to add after it"<<endl;
    cin>>firstnum>>secondnum;
    cout<<endl;
    
    insertAfter(firstnum,secondnum,size,v);// calls the function
    
    for(int i=0 ; i<v.size() ; i++) // prints the content of the vector after the insert after function
    {
        cout<<v.at(i)<<endl;
    }
    
    cout<<endl;
    
    
    
    LinkedList list;
    
    Node* head= new Node;
    Node* Temp;
    
    Temp=head;
    
    list.create(list, v, size, head, Temp,v2); // linked list is created
    list.Printlist(head, Temp); // prints elements
    cout<<endl;
    
    Node* p=Temp->next; // declare a pointer
    
    list.RemoveNode(head, Temp,p); // removes a node
    
    list.Printlist(head, Temp);
    
    
    list.AddNode(head,Temp,10,2);
    
    cout<<endl;
    
    list.Printlist(head, Temp);
    
    cout<<endl;
    
    cout<<"The sum of the values in the list: "<<list.sum_nodes(head,Temp)<<endl;// displays the sum of the nodes
    
  
    return 0;
    
}

