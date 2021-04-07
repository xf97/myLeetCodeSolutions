class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //用优先队列
        //两次通过，十五分钟，时间击败：58.24%，空间击败：33.68%
        if(k == 0){
            vector<int> result;
            return result;
        }
        if(arr.size() <= k){
            return arr;
        }
        else{
            priority_queue<int> pQueue; //优先队列，默认小顶堆
            //首先推入K个
            for(int i = 0; i < k; i++){
                pQueue.push(arr[i]);
            }
            //cout<<2<<endl;
            //然后推入后k个
            for(int i = k; i < arr.size(); i++){
                if(pQueue.top() > arr[i]){
                    //找到更小的元素了
                    pQueue.pop();
                    pQueue.push(arr[i]);
                }
                else{
                    continue;
                }
            }
            //cout<<1<<endl;
            //最后，返回结果
            vector<int> result(k, 0);
            for(int i = 0; i < k; i++){
                result[i] = pQueue.top();
                pQueue.pop();
            }
            return result;
        }
    }
};
