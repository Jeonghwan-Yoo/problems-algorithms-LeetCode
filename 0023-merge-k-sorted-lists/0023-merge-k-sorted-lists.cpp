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
    ListNode* mergeKLists(vector<ListNode*>& lists) {     
        priority_queue<int, vector<int>, greater<int>> allNumbers;
        for (ListNode* list: lists) {
            while (list != nullptr) {
                allNumbers.emplace(list->val);
                list = list->next;
            }
        }
        
        ListNode* head = new ListNode();
        ListNode* ret = head;
        while (!allNumbers.empty()) {
            head->next = new ListNode(allNumbers.top());
            head = head->next;
            allNumbers.pop();
        }
        
        return ret->next;
    }
};