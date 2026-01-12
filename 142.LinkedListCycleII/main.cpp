#include <iostream>
#include <vector>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {   
        if (!head || !head->next) return NULL;

        ListNode *rabbit = head;
        ListNode *turtle = head;
        
        rabbit =  rabbit->next->next;
        turtle = turtle->next;

        while(rabbit != turtle)
        {   
            if (!rabbit || !rabbit->next) return NULL;
            rabbit = rabbit->next->next;
            turtle = turtle->next;
        }

        // they met
        turtle = head;
        while(turtle != rabbit)
        {
            turtle = turtle->next;
            rabbit = rabbit->next;
            
        }
        return turtle;
    }
};

int main ()
{
    // Example usage:
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Create a cycle

    Solution solution;
    ListNode* cycleStart = solution.detectCycle(head);
    if (cycleStart)
        std::cout << "Cycle starts at node with value: " << cycleStart->val << std::endl;
    else
        std::cout << "No cycle detected." << std::endl;

    // Clean up memory (not shown here for brevity)
    return 0;
}