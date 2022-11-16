class Node
        {
        public: 
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };


*****************************************************************/
//it will return head of reversed list
Node* reverse1(Node* head)
{
	//base case
	if(head == NULL || head -> next == NULL)
	{
		return head;
	}
	
	Node* chotaHead = reverse1(head -> next);
	
	head -> next -> next = head;
	head -> next = NULL;
	
	return chotaHead;
	
	
}


void reverse(Node* &head,Node* curr,Node* prev)
{
 	//base case
	if(curr == NULL){
		head = prev;
		return ;
	}
	
	Node* forward = curr -> next;
	reverse(head,forward,curr);
	curr -> next = prev;
}



Node* reverseLinkedList(Node *head)
{
	return reverse1(head);
	
}

/*Code to find the middle of a linked list*/

class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

int getLength(Node* head)
{
	int length = 0;
	while(head != NULL)
	{
		length++;
		head = head -> next;
	}
	
	return length;
}
Node *findMiddle(Node *head) {
    int len = getLength(head);
	int ans = (len/2) ;
	
	Node* temp = head;
	int cnt = 0;
	while(cnt < ans){
		temp = temp -> next;
		cnt++;
	}
	return temp;
}
