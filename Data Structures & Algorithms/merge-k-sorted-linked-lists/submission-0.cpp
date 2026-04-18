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
        ListNode* ans = new ListNode(-1);
        ListNode* ptr = ans;
        auto cmp = [](ListNode* &a, ListNode* &b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minPq;
        for(int i=0; i<lists.size(); i++){
            minPq.push(lists[i]);
        }
        while(minPq.size()){
            auto top = minPq.top();
            minPq.pop();
            ptr->next = top;
            ptr = ptr->next;
            if(top->next){
                minPq.push(top->next);
            }
        }
        return ans->next;
    }
};
