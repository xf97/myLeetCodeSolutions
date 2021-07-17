class Solution {
    //手写快排，成就达成
    //干翻美团
    //十五分钟，一次提交，时间击败-64.94%，空间击败-31.64%
private:
    int getPartition(vector<int> & _nums, int _left, int _right){
        //选定切分位置
        int pos = rand() % (_right - _left + 1);    //生成小于长度的随机数
        pos += _left;   //加上左边起始量
        swap(_nums[pos], _nums[_right]);    //库函数swap
        //对_left - (_right - 1)内排序
        return doPartition(_nums, _left, _right);
    }

    int doPartition(vector<int> & _nums, int _left, int _right){
        //开始排序
        int i = _left -  1;
        for(int j = _left; j < _right; ++ j){
            if(_nums[j] < _nums[_right]){
                //发现小的了，交换
                i ++;
                swap(_nums[j], _nums[i]);
            }
        }
        //结束以后，把主元放回自己的位置
        swap(_nums[i + 1],  _nums[_right]);
        return (i + 1);
    }

    void quickSort(vector<int> & _nums, int _left, int _right){
        //递归向下的函数
        if(_left <  _right){
            //选定切分位置，并且排好左右的序列
            int pos = getPartition(_nums, _left, _right);
            //递归向下
            quickSort(_nums, _left, pos - 1);
            quickSort(_nums, pos + 1, _right);
        }
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        //兄弟们，给我冲排序数组
        //手写快排的时候到了
        //官方题解的快排还写得挺好理解的，开整
        srand(time(0));     //选定随机数种子
        quickSort(nums, 0, nums.size() - 1);    //开始快排
        return nums;    
    }
};
