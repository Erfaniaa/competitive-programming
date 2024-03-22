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
    int pairSum(ListNode* head) {
        int m=0;
                std::stack<int> st;
        int count = 0;
        ListNode *current = head;
        
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        int check;
        int counter = 0;
        current = head;
        int half = count /2;
        while (current != nullptr)
        {
            if (counter < half)
            {
                st.push(current->val);
            }
            else if (counter == half)
            {
                if (count%2==0)
                {
                    check = current->val +st.top();
                    if (m < check) m=check;
                    st.pop();
                }

            }
            else
            {

                    check = current->val +st.top();
                    if (m < check) m=check;
                st.pop();
            }
            
            current = current->next;
            counter++;
        }
        return m;
    }
};