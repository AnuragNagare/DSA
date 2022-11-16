#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    //constructor
    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
    
    //destructor
    ~Node(){
        int val = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
            
        }
        
        cout<< "Memory free for node with data" << val<< endl;
    }
    
};

//traversing linked list
void print(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout<< temp -> data<<" ";
        temp = temp -> next;
        
    }
    
    cout<<endl;
    
    
}

//getting the length of linked list
int getlength(Node* head){
    int len = 0;
    Node* temp = head;
    
    while(temp != NULL){
        len++;
        temp = temp -> next;
        
    }
    
    return len;
}

void insertathead(Node* &tail,Node* &head,int d){
    if(head==NULL){
    Node* temp = new Node(d);
    head = temp;
    tail = temp;
        
    }
    else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
        
    }
    
}

void insertattail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
    Node* temp = new Node(d);
    tail = temp;
    head = temp;
        
    }
    else{
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
        
    }
    
    
}

void insertatposition(Node* &tail,Node* &head,int position, int d){
    
    //insert at start
    if(position==1){
        insertathead(tail,head,d);
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
        insertattail(tail,head,d);
        return;
    }
    
    
    //creating a node for d
    Node* nodetoinsert = new Node(d);
    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;
    
    
}

void deletenode(int position,Node* &head){
    //deleting first or start node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
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
        
        curr -> prev = NULL;
        prev -> next = curr -> next ;
        curr -> next = NULL;
        delete curr;
        
    }
}
    




int main(){
    
    Node* node1 = new Node(12);
    Node* head = node1;
    Node* tail = node1;
    
    print(head);
    
    //cout<<getlength(head)<<endl;
    
    insertathead(tail,head, 15);
    print(head);
    
    insertathead(tail,head, 36);
    print(head);
    
    
    insertathead(tail,head, 42);
    print(head);
    
    
    insertathead(tail,head, 52);
    print(head);
    
    insertattail(tail,head, 100);
    print(head);
    
    insertatposition(tail,head,2,234);
    print(head);
    
    insertatposition(tail,head,1,600);
    print(head);
    
    deletenode(1,head);
    print(head);
    
    
    
    
    
    cout<<getlength(head)<<endl;
    
    
    
    
    return 0;
}
