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
// 重实现，构造新的节点指向第一个节点
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





148 Sort List
Sort a linked list in O(n log n) time uing constant space complexity.

eg 1
	Input: 4->2->1->3
	Output: 1->2->3->4

// discuss
// 排序问题，应该可以找到数组对应的做法
class Solution {
public:
    ListNode* merge( ListNode* head1 , ListNode * head2){
        ListNode* d = new ListNode (0);            // dummy node
        ListNode* e = d;
        while(head1||head2){
            if(head1 && (!head2 || head1->val <= head2 -> val) ){
                e=e->next= head1 ; 
                head1 = head1 -> next;
            }
            if(head2 && (!head1 || head2->val < head1 -> val) ){
                e=e->next= head2 ; 
                head2 = head2 -> next;
            }
        }
        e->next = NULL;
        return d->next;
    }
   ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast =head->next;
         while(fast && fast->next){         // to find middle node     
            fast= fast->next->next;
            slow = slow->next;
        }
        ListNode* headb = slow->next;     // headb is start of 2nd half of list
        slow->next = NULL;                 
        return merge(sortList(head) , sortList(headb));
        }
};





150 Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation'.

1 Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

2 Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

3 Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22




// discuss
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<int (int, int) > > map = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };
        std::stack<int> stack;
        for (string& s : tokens) {
            if (!map.count(s)) {
                stack.push(stoi(s));
            } else {
                int op1 = stack.top();
                stack.pop();
                int op2 = stack.top();
                stack.pop();
                stack.push(map[s](op2, op1));
            }
        }
        return stack.top();
    }
};


int evalRPN(vector<string>& tokens) {
    stack<int> stn;
    for(auto s:tokens) {
        if(s.size()>1 || isdigit(s[0])) stn.push(stoi(s));
        else {
            auto x2=stn.top(); stn.pop();
            auto x1=stn.top(); stn.pop();
            switch(s[0]) {
                case '+': x1+=x2; break;
                case '-': x1-=x2; break;
                case '*': x1*=x2; break;
                case '/': x1/=x2; break;
            }
            stn.push(x1);
        }
    }
    return stn.top();
}


int evalRPN(vector<string>& tokens) {
        string s = tokens.back(); tokens.pop_back();
        if(s != "+" && s != "-" && s != "*" && s != "/") return stoi(s);
        
        int r2 = evalRPN(tokens), r1 = evalRPN(tokens);
        
        if(s == "+") return r1 + r2;
        if(s == "-") return r1 - r2;
        if(s == "*") return r1 * r2;
        if(s == "/") return r1 / r2;
    }