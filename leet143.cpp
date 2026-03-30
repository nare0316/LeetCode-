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
        ListNode* get_mid(ListNode* head) {
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    
        ListNode* reverse(ListNode* head) {
            ListNode* next = nullptr;
            ListNode* new_head = head;
            ListNode* cur = head;
            while(new_head) {
                new_head = cur->next;
                cur->next = next;
                next = cur;
                cur = new_head;
            }
            new_head = next;
            return new_head;
        }
    
        void reorderList(ListNode* head) {
            if (!head || !head->next) {
                return;
            }
            ListNode* mid = get_mid(head);
            ListNode* second_part = reverse(mid);
    
            ListNode* tmp = head;
            ListNode* first = head;
            ListNode* Next = head->next;
    
            while (second_part->next){
                tmp = Next;
                first->next = second_part;
                second_part = second_part->next;
                first = first->next;
                first->next = tmp;
                Next = tmp->next;
                first = first->next;
            } 
        }
    };