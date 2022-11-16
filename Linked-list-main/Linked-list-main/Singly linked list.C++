#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    //destructor
    ~Node(){
        int value = this -> data;
        if(this->next !=NULL){
            delete next;
            this -> next = NULL;
        }
        cout<<"memory is free for node with data"<< value<< endl;
        
    }
    
    
    
};

void insertathead(Node* &head, int d){
    
    //creating new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertattail(Node* &tail,int d){
    //creating new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
    
}

void inseratposition(Node* &tail,Node* &head,int position, int d){
    //inserting at 1st position
    if(position == 1){
    insertathead(head,d);
    return;
    }
    
    Node* temp = head;
    int cnt = 1;
    
    while(cnt<position-1){
        temp = temp -> next;
        cnt++;
        
    }
    
    //inserting at last position
    if(temp -> next == NULL){
        insertattail(tail,d);
        return;
    }
    
    
    //creating a node for d
    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next = nodetoinsert;
    
}

void print(Node* &head){
    Node* temp= head;
    
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    } 
    
    cout<<endl;
}

void deletenode(int position,Node* &head){
    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        
        //memory free start node
        temp -> next = NULL;
        delete temp;
        
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt<=position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
    }
}

int main()
{
    //creating a  new node
    Node* node1 = new Node(10);
    //cout<< node1 -> data << endl;
    //cout<< node1 ->next << endl;
    
    
    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    insertattail(tail,23);
    print(head);
    
    insertattail(tail,34);
    print(head);
    
    inseratposition(tail,head, 3, 100);
    print(head);
    
    inseratposition(tail,head, 5, 66);
    print(head);
    
    cout<<"head"<<head -> data <<endl;
    cout<<"tail"<<tail -> data <<endl;
    
    deletenode(1,head);
    print(head);
    
    
    
    
    return 0;
}
