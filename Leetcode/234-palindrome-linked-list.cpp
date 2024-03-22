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
    bool isPalindrome(ListNode* head) {
        std::stack<int> st;
        int count = 0;
        ListNode *current = head;
        
        while (current != nullptr)
        {
            count++;
            current = current->next;
        }
        
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
                    if (st.top() == current->val)
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }

            }
            else
            {
                    if (st.top() == current->val)
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
            }
            
            current = current->next;
            counter++;
        }
        if (st.empty()) return true;
        else return false;
    }
        
        
};