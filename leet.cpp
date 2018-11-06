//***********************************Leet Recorder***********************************//


147 Insertion Sort List
Sort a linked list using insertion sort.
	// movie

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.

eg 1
	Input: 4->2->1->3
	Output: 1->2->3->4

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode *input,*pos,*preinput;
        
//         preinput = head;
//         input = head -> next;
//         preinput -> next = preinput -> next -> next;
        
//         while(preinput -> next)
//         {
//             pos = head;
//             while(pos)
//             {
//                 if(input->val <= pos->val)
//                 {
//                     input -> next = pos -> next;
//                     pos -> next = input;
//                     swap(pos -> val, input -> val);
//                     break;
//                 }
//                 else
//                     pos = pos -> next;
//             }
//             input = preinput -> next;
//             preinput -> next = preinput -> next -> next;
//         }
//         return head;
//     }
// };


// method：用一个指针指向需插入的结点，一个指针从头遍历找到该节点插入位置
// tip: 在当前节点前插入节点时，采用在该节点后插入节点，并交换两节点的值


// discuss
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur) {
            if ((cur -> next) && (cur -> next -> val < cur -> val)) {
                while ((pre -> next) && (pre -> next -> val < cur -> next -> val)) {
                    pre = pre -> next;
                }
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                pre = dummy;
            }
            else {
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};


