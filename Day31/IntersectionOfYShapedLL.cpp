class Solution
{
public:
    int len(Node *node)
    {
        int count= 0;
        while(node != nullptr)
        {
            node = node->next;
            count++;
        }
        return count;
    }
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        if(head1 == nullptr || head2 == nullptr)
            return head1==nullptr?head2->data : head1->data;
        // make a  cycle
        int len1 = len(head1),len2 = len(head2),diff = 0;
        Node *curr1 = head1, *curr2 = head2;
        if(len1 > len2)
        {
            diff = len1-len2;
            while(diff--)
                curr1 = curr1->next;
        }      
        else if(len2 > len1)
        {
            diff = len2-len1;
            while(diff--)
                curr2 = curr2->next;
        }
        else 
            diff = 0;
        if(curr1 == curr2)
            return curr1->data;
        while((curr1 && curr2) && curr1 != curr2)
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
            if(curr1 == curr2)
                return curr1->data;
        }
        
        return -1;
    }
};
