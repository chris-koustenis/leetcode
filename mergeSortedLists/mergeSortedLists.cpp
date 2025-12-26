#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* tmp;
        if(ptr1 == nullptr) return ptr2;
        if(ptr2 == nullptr) return ptr1;

        if (ptr1->val > ptr2->val) {
            // Swap pointers to ensure ptr1 starts with the smaller value
            tmp = ptr1;
            ptr1 = ptr2;
            ptr2 = tmp;
        }

        while(ptr1 != nullptr || ptr2 != nullptr){
            while(ptr1->next != nullptr && ptr1->next->val < ptr2->val)
            {
                ptr1 = ptr1->next;
            }
            if(ptr1->next == nullptr)
            {
                ptr1->next = ptr2;
                return list1;
            }
            // Merging nodes
            tmp = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = tmp;
            while(ptr2->next != nullptr && ptr2->next->val < ptr1->val)
            {
                ptr2 = ptr2->next;
            }
            if(ptr2->next == nullptr)
            {
                ptr2->next = ptr1;
                return list1;
            }
            // Merging nodes
            tmp = ptr2->next;
            ptr2->next = ptr1;
            ptr2 = tmp;
        }
        return list1;
    }
};

int main() {
    Solution sol;
    // Creating first sorted linked list: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Creating second sorted linked list: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode* mergedList = sol.mergeTwoLists(list1, list2);

    // Print merged linked list
    ListNode* current = mergedList;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // Free allocated memory (not shown here for brevity)

    return 0;
}