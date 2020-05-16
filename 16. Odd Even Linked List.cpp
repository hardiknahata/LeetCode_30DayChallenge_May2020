/*

Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

Example 2:
Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

*/

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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(head==NULL) return head; //if linked list is empty return it
        
        ListNode *tail = head;      //tail points to end pointer
        ListNode *res = head;       //res stores the address to first node, for returning the modified LL
        int nodes=0;
        
        while(tail->next!=NULL)
        {
            tail=tail->next;
            nodes++;
        }
        nodes++;
        
        int loops = nodes/2;    //we will have to loops nodes/2 times to alter the LL correctly
    
        while(loops)
        {
            tail->next = head->next;    
            tail = tail->next;          
            head->next = tail->next;
            tail->next = NULL;
            head=head->next;
        loops--;
        }
        
    return res;
    }
};
