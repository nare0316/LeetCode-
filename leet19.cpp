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
            ListNode* first = head;
            for (size_t i{1}; i < n; ++i) {
                first = first->next;
            }
            ListNode* second = head;
            ListNode* prev = nullptr;
            
            while (first->next) {
                first = first->next;
                prev = second;
                second = second->next;
            }
    
            ListNode* tmp{};
            if (prev == nullptr) {
                tmp = head;
                head = head->next;
                delete tmp;
            } else {
                prev->next = second->next;
                delete second;
            }
            return head;
    
        }
    };