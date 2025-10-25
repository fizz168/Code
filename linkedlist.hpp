#include <iostream>
#include<string>
using namespace std;
struct Node{
    int value;
    Node* next;
};
class LinkedList{
    private:
    Node* head, *tail, *cur;
    int size;

    public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        cur = nullptr;
        size = 0;
    }
    int getsize(){return size;}
    int gettail(){return tail->value;}
    int gethead(){return head->value;}
    
    void _traverse(){
        cur = head;
        while(cur->next){
            cur = cur->next;
        }
    }

    void _traverseTill(int pos){
        cur = head;
        for(int i = 0; i < pos - 1; i++){
            cur = cur->next;
        }
    }
    
    void insertFront(int value){
        Node*newNode = new Node{value, nullptr};
        newNode->next = head;
        head = newNode;
        if(size == 0){
            tail = newNode;
          
        }
        size++;
    }
void insertEnd(int value){
    if(size == 0){
        insertFront(value);
        return;
    }
    Node* newNode = new Node{value, nullptr};
    tail->next = newNode;
    size++;
    tail = newNode;
}
void insertAt(int pos, int value){
    if(pos == 0){
        insertFront(value);
        return;
    }
    if(pos >= size){
        insertEnd(value);
        return;
    }
    Node *newNode = new Node{value, nullptr};
    Node *temp;
    _traverseTill(pos);
    temp = cur->next;
    cur->next = newNode;
    newNode-> next = temp;
    size++;

}
void insertMiddle(int value){
    _traverseTill(size/2);
    Node *newNode = new Node{value, nullptr};
    Node *temp;
    temp = cur->next;
    cur->next = newNode;
    newNode->next = temp;
    size++;
}
void deleteFront(){
    if (head == nullptr){
        cout<< "the list is empty"<<endl;
        return;
    }
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
    size--;
    if(head == nullptr){
        tail = nullptr;
    }

}


void deleteEnd(){
    if(head == 0){
        cout<<"the list is empty"<<endl;
        return;
    }
    if(size == 1){
        deleteFront();
        return;
    }
   
    _traverseTill(size - 1);
    Node *temp = tail;
    tail = cur;
    tail->next = nullptr;
    delete temp;
    size--;
}
void deleteMiddle(){
    if(head == nullptr){
        cout<<"the list is empty"<<endl;
        return;
    }
    if(size == 1){
        deleteFront();
        return;
    }
    Node *temp;
    _traverseTill(size/2);
    temp = cur->next;
    cur->next = temp->next;
    if(temp == tail){
        tail = cur;
        delete temp;
        size--;
    }
}
void swapTwoNode(int posFirstNode, int posSecNode){
    if (head == nullptr || size == 1){
        cout<<"the list is empty or has only one node"<<endl;
        return;
    }
    if(posFirstNode < 0 || posSecNode < 0 || posFirstNode >= size || posSecNode >= size){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(posFirstNode == posSecNode){
        return; 
    }
    if(posFirstNode > posSecNode){
        int temp = posFirstNode;
        posFirstNode = posSecNode;
        posSecNode = temp;
    }
    Node *prevFirst = nullptr;
    Node *firstNode = head;
    if(posFirstNode == 0){
        firstNode = head;
    } else {
        _traverseTill(posFirstNode);
        prevFirst = cur;
        firstNode = cur->next;
    }
    Node *prevSec = nullptr;
    Node *secNode = head; 
    _traverseTill(posSecNode);
    prevSec = cur;
    secNode = cur->next;
    if(firstNode->next == secNode){
        if(prevFirst){
            prevFirst->next = secNode;
        } else {
            head = secNode; 
        }
        firstNode->next = secNode->next;
        secNode->next = firstNode;
        if(secNode == tail){
            tail = firstNode;
        }
    } else {
        if(prevFirst){
            prevFirst->next = secNode;
        } else {
            head = secNode; 
        }
        prevSec->next = firstNode;
        Node *temp = firstNode->next;
        firstNode->next = secNode->next;
        secNode->next = temp;
        if(firstNode == tail){
            tail = secNode;
        } else if(secNode == tail){
            tail = firstNode;
        }
    }
}
bool search(int value) {
    cur = head;  
    while (cur != nullptr) {
        if (cur->value == value) {
            return true;  
        cur = cur->next;  
    }
    return false; 

}
}
void print(){
   if(head == nullptr){
    cout<< "list is empty"<<endl;
    return;
   }
   cur = head;
   while(cur != nullptr){
    cout<< cur->value;
    if(cur->next != nullptr)
    cout<<"->";
    cur = cur->next;
   }
   cout<<endl;
}

};