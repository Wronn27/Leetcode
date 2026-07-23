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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        int count=0;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }

        n=count-n;
        if(n==0)
        {
            ListNode* t=head;
            head=head->next;
            delete(t);
            return head;
        }
        ListNode *prev=NULL;
        temp=head;
        while(n>0)
        {
            prev=temp;
            temp=temp->next;
            n--;
        }
        prev->next=prev->next->next;
        delete(temp);
        return head;
    }
};