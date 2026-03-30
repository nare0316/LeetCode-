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
        ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next || !head->next->next) {
                return head;
            }
            ListNode* odd_head = head;
            ListNode* even_head = head->next;
    
            ListNode* odd_tmp = odd_head;
            ListNode* even_tmp = even_head;
            while (odd_tmp->next && even_tmp->next) {
                odd_tmp->next = even_tmp->next;
                odd_tmp = odd_tmp->next;
                even_tmp->next = odd_tmp->next;
                even_tmp = even_tmp->next;
            }
            odd_tmp->next = even_head;
            return odd_head;
        }
    };