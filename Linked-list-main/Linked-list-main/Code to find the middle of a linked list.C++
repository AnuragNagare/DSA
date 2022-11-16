
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
Node* getMiddle(Node* head)
{
	if(head == NULL || head -> next == NULL)
		return head;
	
	//2 nodes
	if(head -> next -> next == NULL)
	{
		return head -> next;
	}
	
	Node* slow = head;
	Node* fast = head -> next;
	
	
	while(fast != NULL)
	{
		fast = fast -> next;
		if(fast != NULL)
		{
			fast = fast -> next;
		}
		
		slow = slow -> next;
	}
	
	return slow;
		  
}




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
	
	return getMiddle(head);
	
	
	/*
    int len = getLength(head);
	int ans = (len/2) ;
	
	Node* temp = head;
	int cnt = 0;
	while(cnt < ans){
		temp = temp -> next;
		cnt++;
	}
	return temp;
	*/
}
