//Brute Force

//T.C --> O(N) + O(N/2) 

// O(N) for traversing the whole linked list and counting or getting the middle of the linked list and then again
// traversing for N/2 times to return the middle of the linked list.



//Optimal Approach

//T.C --> O(N/2)
//S.C --> O(1)

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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *newNode = NULL;

        while (head != NULL)
        {
            ListNode *next = head->next; // dummy node
            head->next = newNode;

            newNode = head;
            head = next;
        }
        return newNode;
    }
};