#include<iostream>
#include <string>
#include"linkedlist.hpp"
using namespace std;
int main(){
    LinkedList list;
    list.insertFront(5);
    list.insertFront(4);
    list.insertFront(10);
    list.insertEnd(30);
    list.insertAt(2, 8);
    list.insertMiddle(9);
    list.deleteFront();
    list.deleteMiddle();
    list.swapTwoNode(0, 3);
   
    list.print();
  
 
    return 0;
}