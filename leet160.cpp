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
    
    
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            ListNode* tmpA = headA;
            ListNode* tmpB = headB;
            size_t count = 0;
    
    
            while (tmpA != tmpB) {
                tmpA = tmpA->next ? tmpA->next : (++count, headB);
                tmpB = tmpB->next ? tmpB->next : (++count, headA);
                
                if (count > 2) {
                    return nullptr;
                }
              
            }
            return tmpA;
        }
    };