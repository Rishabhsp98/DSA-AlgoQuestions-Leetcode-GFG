class Solution
{
    public:
    Node *oh = nullptr,*ot = nullptr,*th = nullptr,*tt = nullptr;
    int len_(Node *node)
    {
        int count = 0;
        while(node != nullptr)
        {
            count++;
            node = node->next;
        }
        return count;
    }
    void addFirst(Node *node)
    {
        if(th == nullptr)
        {
            th = node;
            tt = node;
        }else{
            node->next = th;
            th = node;
        }
    }
    Node* pairWiseSwap(struct Node* head) 
    {
        // The task is to complete this method
        if(head == nullptr || head->next == nullptr)
            return head;
        int len = len_(head),k = 2,K = 0;
        Node *curr = head;
        while(len && curr != nullptr)
        {
            K = k;
            while(curr != nullptr && K--)
            {
                Node *next = curr->next;
                curr->next = nullptr;
                addFirst(curr);
                curr = next;
            }
            
            if(oh == nullptr)
            {
                oh = th; ot = tt;
            }else{
                ot->next = th;
                ot = tt;
            }
            th = nullptr , tt = nullptr;
            len -=k;
            // if(len < k)
            // {
            //     ot->next = curr;
            //     break;
            // }
        }
        return oh;
    }
};