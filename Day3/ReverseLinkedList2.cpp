class Solution {
public:
    ListNode *th = nullptr ,*tt = nullptr;
    int len_(ListNode *curr)
    {
        int count = 0;
        while(curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }
    void addFirst(ListNode *node)
    {
        if(th == nullptr)
        {
            th = node; tt = node;
        }
        else{
            node->next = th;
            th = node;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || head->next == nullptr)
            return head;
        int len = len_(head),idx = 1;
        ListNode *prev = nullptr,*curr = head;
        
        while(idx<=len)
        {
            if(idx==left)
            {
                while(idx<=right && curr)
                {
                    ListNode *next = curr->next;
                    curr->next = nullptr;
                    addFirst(curr);
                    curr = next;
                    idx++;
                }
                
                if(prev == nullptr)
                {
                    tt->next = curr;
                }
                else{
                    prev->next = th;
                    tt->next = curr;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
                idx++;
            }
        }
        return left==1 ? th : head;
    }
};