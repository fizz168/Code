#include<iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
    

};
int main(){
    Node* head;
    Node* tail;
    Node* current;

    Node Omra;
    Omra.value = 5;

    Node Viseth;
    Viseth.value = 10;
    Viseth.next = nullptr;

    Omra.next = &Viseth;
    head = &Viseth;
    tail = &Omra;
    Node Reach;
    Reach.value= 20;
    Reach.next = nullptr;
   tail = &Reach;
   Viseth.next = &Reach;
    


    current = head;
    while(current != nullptr){
        cout<<current->value <<endl;
        current = current->next;
    }

    return 0;
}