// brute force

// using dummy linked list

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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *dummy = new ListNode();
        ListNode *tmp = dummy; // Initialize tmp with the dummy node

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                tmp->next = list1;
                list1 = list1->next;
            }
            else
            {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next; // Move tmp to the next merged node
        }

        // If any list still has remaining nodes, append them to the merged list
        if (list1 != NULL)
        {
            tmp->next = list1;
        }
        else
        {
            tmp->next = list2;
        }

        return dummy->next;
    }
};

// Optimal Approach (In place without using extra space)

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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        if (list1->val > list2->val)
            swap(list1, list2);

        ListNode *res = list1;

        while (list1 != NULL && list2 != NULL)
        {
            ListNode *tmp = NULL;
            while (list1 != NULL && list1->val <= list2->val)
            {
                tmp = list1;
                list1 = list1->next;
            }
            tmp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};