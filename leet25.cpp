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
        ListNode* reverse(ListNode* head) {
            ListNode* newHead{};
            ListNode* next{};
            ListNode* cur = head;
            while (cur) {
                newHead = cur->next;
                cur->next = next;
                next = cur;
                cur = newHead;
            }
    
            newHead = next;
            return newHead;
        }
    
        ListNode* get_tail(ListNode* subHead, int k) {
            int count{};
            ListNode* prev{};
            while(count != k && subHead) {
                ++count;
                prev = subHead;
                subHead = subHead->next;
            }
            return count == k ? prev : nullptr;
        }
    
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (k == 1) {
                return head;
            }
            size_t count = 1;
            ListNode* subHead = head;
            ListNode* subTail = nullptr;
            ListNode* subHead_next = head;
            ListNode* prevTail = nullptr;
            ListNode* new_head = head;
    
            while (subHead) {
                subTail = get_tail(subHead, k);
                if (!subTail) {
                    if (prevTail != nullptr) {
                        prevTail->next = subHead;
                    }
                    return head;
                }
                subHead_next = subTail->next;
                subTail->next = nullptr;
                new_head = reverse(subHead);
                if (count == 1) {
                    head = new_head;
                }
                if (prevTail != nullptr) {
                    prevTail->next = new_head;
                }
                prevTail = subHead;
                subHead = subHead_next;
                ++count;
            }
            return head;
        }
    };