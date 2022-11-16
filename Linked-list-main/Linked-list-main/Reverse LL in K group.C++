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


Node* kReverse(Node* head, int k) {
    // base call
	if(head == NULL){
		return NULL;
	}
	
	//step 1: reverse first K nodes
	Node* next = NULL;
	Node* curr = head;
	Node* prev = NULL;
	int count = 0;
	
	while( curr != NULL && count < k){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
		count++;
		
	}
	
	//step 2 : Recurrsion
	if(next != NULL){
		head -> next = kReverse(next,k);
	}
	
	//step 3 : return head of previous list
	return prev;
	
	
	
}
