Question1480:
    vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            nums[i]=sum;
        }
        return nums;
    }

Question1486:
    int xorOperation(int n, int start) {
        vector<int> testVec;
        for(int i=0;i<n;++i){
            testVec.push_back(start+2*i);
        }
        int res=testVec[0];
        for(int i=1;i<testVec.size();++i){
            res=res^(testVec[i]);
        }
        return res;
    }

Question🗡指58:
    string reverseLeftWords(string s, int n) {
        string temps=s.substr(0,n);
        s=s.substr(n,s.size()-1);
        s=s+temps;
        return s;
    }

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
