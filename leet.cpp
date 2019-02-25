//***********************************Leet Recorder***********************************//
// 1 解法用到的知识点加个备注，以便寻找及总结。  递归
//***




// ***
255 Verify Preorder Sequence in Binary Search Tree
a
class Solution{
public:
    bool verifyPreorder(<vector<int>& preorder){
        int low = INT_MIN;
        stack<int> s;
        for(auto a : preorder)
        {
            if(a < low) return false;
            while(!s.empty() && a > s.top())
            {
                low = s.top();s.pop();
            }
            s.push(a);
        }
        return true;
    }
};

b
class Solution{
public:
    bool verifyPreorder(vector<int>& preorder){
        int low = INT_MIN,i = -1;
        for(auto a : preorder){
            if(a < low) return false;
            while(i >= 0 && a > preorder[i]){
                low = preorder[i--];
            }
            preorder[++i] = a;
        }
        return true;
    }
};



687 Longest Univalue Path
class Solution{
public:
	int longestUnivaluePath(TreeNode* root){
		if(!root) return 0;
		int res = 0;
		helper(root,root,res);
		return res;
	}
	int helper(TreeNode* node,TreeNode* parent,int& res){
		if(!node) return 0;
		int left = helper(node->left,node,res);
		int right = helper(node->right,node,res);
		left = (node->left && node->val == node->left->val)? left+1:0;
		right = (node->right && node->val == node->right->val)? right+1:0;
		res = max(res,left+right);
		return max(left,right);
	}
};

// ***
677 Map Sum Pairs
a
class Solution{
public:
    void insert(string key,int val)
    {
        int diff = val -m[key].first,n = key.size();
        m[key].first = val;
        for(int i=n-1;i > 0;--i)
        {
            m[key.substr(0,i)].second += diff;
        }
    }

    int sum(string prefix){
        return m[prefix].first + m[prefix].second;
    }

private:
    unordered_map<string,pari<int,int>> m;
};

b 
class MapSum{
public:
    MapSum();
    void insert(string key,int val){
        m[key] = val;
    }

    int sum(string prefix){
        int res = 0,n = prefix.size();
        for(auto it=m.lower_bound(prefix);it != m.end();++it){
            if(it->first.substr(0,n) != prefix) break;
            res += it->second;
        }
        return res;
    }
private:
    map<string,int>m;
};


684 Redundant Connection(graph)
a


536 Construct Binary Tree from String
a
calss Solution{
public:
    TreeNode* str2tree(string s){
        if(s.empty()) return NULL;
        auto found = s.find('(');
        int val = (found == string::npos)?stoi(s):stoi(s.substr(0,found));
        TreeNode* cur = new TreeNode(val);
        if(found == string::npos) return cur;
        int start = found,cnt = 0;
        for(int i=start;i< s.size();++i)
        {
            if(s[i] == '(')
                cnt++;
            else if(s[i] == ')')
                cnt--;

            if(cnt==0 && start == found)
            {
                cur -> left = str2tree(s.sbustr(start+1,i-start-1));
                start = i+1;
            }
            else if(cnt == 0)
                cur -> right = str2tree(s.sbustr(start+1,i-start-1));
        }
        return cur;
    }
};



345. Reverse Vowels of a string
a
class Solution{
public:
    string reverseVowels(string s)
    {
        int left = 0,right = s.size()-1;

        while(left < right)
        {
            if(isVowels(s[left]) && isVowels(s[right]))
                swap(s[left++],s[right--]);
            else if(isVowels(s[left]))
                right--;
            else
                left++;
        }
        return s;
    }
private:
    bool isVowels(char c)
    {
        return c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U';
    }
};


344 Reverse string
a
class Solution{
public:
    string reverseString(string s)
    {
        int left = 0,right = s.size()-1;
        while(left < right)
            swap(s[left++],s[right--]);
        return s;
    }
};


125 Valid Palindrome
a
class Solution{
public:
    bool isPalindrome(string s){
        int left = 0,right = s.size()-1;

        while(left < right)
        {
            if(!isalnum(s[left])) ++left;
            else if(!isalnum(s[right])) --right;
            else if((s[left] + 32 - 'a')%32 != (s[right] + 32 - 'a') %32) return false;
            else
            {
                ++left;--right;
            }
        }
        return true;
    }
};


28 Inplement strStr()
class Solution{
public:
    int strStr(string haystack,string needle){
// **   if(needle.empty())
            return 0;
        int len1 = haystack.size(), len2 = needle.size();
        if(len1 < len2)
            return -1;

        for(int i=0;i <= len1-len2;i++)
        {
            int j = 0;
            for(j;j < len2;j++)
            {
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == len2-1)
                return i;
        }
        return -1;
    }
};


524 Longeset Word in Dictionary through Deleting
a
class Solution{
public:
    string findLongestWord(string s,vector<string>& d){
        sort(d.begin(),d.end(),[](string a,string b){if(a.size() == b.size()) return a<b; return a.size() > b.size();});

        int len = d.size(),len2 = s.size();
        for(int i=0;i < len;i++)
        {
            int k=0;
            for(int j=0;j < len2;j++)
                if(k < d[i].size() && s[j]==d[i][k]) ++k;
            if(k == d[i].size()) return d[i];
        }
        return "";
    }
};


763 Partition Labels
class Solution{
public:
    vector<int> partitionLabels(string S){
        vector<int> res;
        int n = S.size(),start = 0,last = 0;
        unordered_map<char,int> m;
        for(int i=0;i < n;++i) m[S[i]] = i;

        for(int i=0;i < n;++i)
        {
            last = max(last,m[S[i]]);
            if(i == last)
            {
                res.push_back(i-start+1);
                start = i+1;
            }
        }
        return res;
    }
};


567 Permutation in String
a
class Solution{
public:
    bool checkInclusion(string s1,string s2){
        int n1 = s1.size(),n2 = s2.size();
        if(n1 > s2)             // 此函数可以不写该判断语句
            return false;
        vector<int> m1(128),m2(128);
        for(int i=0;i < n1;++i){
            ++m1[s1[i]];++m2[s2[i]];
        }
        if(m1 == m2) return true;
        for(int i=n1;i < n2;++i)
        {
            ++m2[s2[i]];
            --m2[s2[i-n1]];         // 滑窗的右边窗口
            if(m1 == m2) return true;
        }
        return false;
    }
};

b 
class Solution{
public:
    bool checkInclusion(string s1,string s2){
        int n1 = s1.size(),n2 = s2.size(),left = 0;
        vector<int> m(128);
        for(int i=0;i < n1;++i) m[s1[i]]++;

        for(int right=0;right < n2;++right)
        {
            if(++m[s2[right]] < 0)
            {
                while(--m[s2[left++]] != 0)
                    {};
            }
            if(right - left + 1 == n1)
                return true;
        }
        return false;
    }
};


487 Max Consecutive Ones II
a
class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int res = 0,cur = 0,cnt = 0;

        int len = nums.size();
        for(int i=0;i < len;i++)
        {
            cnt++;
            if(nums[i] == 0)
            {
                cur = cnt;
                cnt = 0;
            }
            res = max(res,cur+cnt);
        }
        return res;
    }
};








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
// map使用
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


// 对-33能处理吗
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

// 递归
// 抓住了一个关键点：连续两个都是数才会进行运算！
int evalRPN(vector<string>& tokens) {
        string s = tokens.back(); tokens.pop_back();
        if(s != "+" && s != "-" && s != "*" && s != "/") return stoi(s);
        
        int r2 = evalRPN(tokens), r1 = evalRPN(tokens);
        
        if(s == "+") return r1 + r2;
        if(s == "-") return r1 - r2;
        if(s == "*") return r1 * r2;
        if(s == "/") return r1 / r2;
    }