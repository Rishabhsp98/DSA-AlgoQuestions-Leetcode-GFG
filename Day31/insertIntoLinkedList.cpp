class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        // Code here
        Node *nnode = new Node(data);
        if(head == nullptr)
            return nnode;
        if(nnode->data < head->data)
        {
            nnode->next = head;
            return nnode;
        }
        Node *curr = head, *prev = nullptr;
        while(curr != nullptr)
        {
            if(prev != nullptr && curr->data >= data && prev->data <= data)
            {
                prev->next = nnode;
                nnode->next = curr;
                break;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        if(data >= prev->data)
            prev->next = nnode;
        return head;
    }
};