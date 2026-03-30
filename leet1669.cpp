/**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
 */
class Solution {
    public:
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode* start = list1;
            size_t i = 0;
            while (i < a - 1) {
                start = start->next;
                ++i;
            }
            ListNode* removing_node = start->next;
            ListNode* next = nullptr;
            i = 0;
            while (i < (b - a + 1)) {
                next = removing_node->next;
                delete removing_node;
                removing_node = next;
                ++i;
            }
            start->next = list2;
            ListNode* list2_tail = list2;
            while (list2_tail->next) {
                list2_tail = list2_tail->next;
            }
            list2_tail->next = next;
            return list1;
        }
    };