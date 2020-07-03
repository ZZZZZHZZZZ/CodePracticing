//五道简单题这两道还有点意思
面试题02.03:
    void deleteNode(ListNode* node) {
        ListNode* nextNode=node->next->next;
        node->val=node->next->val;
        node->next=nextNode;
    }

面试题16.01：
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0]^=numbers[1];
        numbers[1]^=numbers[0];
        numbers[0]^=numbers[1];
        return numbers;
    }
