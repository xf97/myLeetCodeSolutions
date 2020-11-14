class Solution {
public:
    /*
   感觉用count就可以
   time defeat: 23%
   space defeat: 15%
    */
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> inArr2Vec;
        for(int i : arr2){
            int num = count(arr1.begin(), arr1.end(), i);
            while (num > 0){
                inArr2Vec.emplace_back(i);
                num --;
            }
            //按值，从arr1中删除所有该值元素
            auto it = remove(arr1.begin(), arr1.end(), i);
            arr1.erase(it, arr1.end());
        }
        sort(arr1.begin(), arr1.end());
        inArr2Vec.insert(inArr2Vec.end(), arr1.begin(), arr1.end());
        return inArr2Vec;
    }
};
