/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
        int len1 = list_length(l1);
        int len2 = list_length(l2);
        ListNode* bigger = len1 > len2 ? l1 :l2;
        ListNode* smaller = len1 > len2 ? l2 :l1;
        int lens = len1 < len2 ? len1 : len2;
        int c = 0;
        ListNode* n  = new ListNode(0);
        ListNode* solution = n;
        do {
            if(smaller && bigger) {
                int tmp = bigger->val + smaller->val + c;
                n->val = tmp%10;
                c = tmp/10;
                smaller = smaller->next;
                bigger = bigger->next;
            } else if(bigger) {
                n->val = bigger->val+c;
                c = n->val / 10;
                n->val = n->val % 10;
                bigger = bigger->next;
            } else {
                n->val = c;
                c = 0;
            }
            if(bigger || c == 1) {
                n->next = new ListNode(0);
                n = n->next;
            }
        } while(bigger || c == 1);
        
        return solution;
    }
    
    
    int list_length(ListNode* head) {
        
        int len = 0;
        while(head->next) {
            len++;
            head = head->next;
        }
        len++;
        return len;
        
    }
};

