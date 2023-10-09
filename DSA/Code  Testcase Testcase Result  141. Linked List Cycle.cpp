class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_map<ListNode*,int> mp;
       ListNode* t = head;
       while(t)
       {
           if(mp.find(t) != mp.end())
           return true;
           mp[t]++;
           t = t->next;
       }
       return false;
    }
};
