/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int gcd(int a,int b)
    {
        if(a == 0 || b == 0)
            return a==0?b : a;
        if(a == b)
            return a;
        if(a > b)
            return gcd(a-b,b);
        return gcd(a,b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *curr = head;
        while(curr != nullptr)
        {
            if(curr->next != nullptr)
            {
                int x = curr->val;
                int y = curr->next->val;
                ListNode *next = curr->next;
                int ans = gcd(x,y);
                curr->next = new ListNode(ans);
                curr->next->next = next;
                curr = curr->next->next;
            }
            else
                curr = curr->next;
            
        }
        return head;
    }
};