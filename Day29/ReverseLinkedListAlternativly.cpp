class Solution
{
    public:
    
    Node *reverse(Node *node)
    {
        Node *next=nullptr,*prev= nullptr,*curr = node;
        
        while(curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void rearrange(struct Node *head)
    {
        //add code here
        if(head == nullptr || head->next == nullptr)
            return;
        Node *curr1 = head,*curr2 = head->next,*temp = head->next,*prev = nullptr;
        
        
        while(curr1 != nullptr && curr2 != nullptr)
        {
            if(curr1->next != nullptr)
            {
                Node *next1 = curr1->next->next;
                prev = curr1;
                curr1->next = next1;
                curr1 = next1;
                // cout<<curr1->data<<" , ";
            }
        
            if(curr2->next != nullptr)
            {
                Node *next2 = curr2->next->next;
                curr2->next = next2;
                curr2 = next2;
            }
        }
        if(curr1  != nullptr)
        {
            prev = curr1;
            curr1->next = nullptr;
        }
        Node *nhead = reverse(temp);
        prev->next = nhead;
        
    }
};
