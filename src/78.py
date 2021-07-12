class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        #昨晚欧洲杯有点困，做个简单的中等题
        #先耍赖
        #itertools.combinations能够返回自己
        #耍赖成功，两分钟，一次提交，时间击败-99.67%，空间击败-90.65%
        '''
        result = list()
        for i in range(len(nums) + 1):
            #从0-长度为本身
            for res in itertools.combinations(nums, i):
                #从nums中逐个取出长度为i的集合
                result.append(res)
        return result
        '''
        #现在要好好写个普通方法，感觉能够递归回溯
        #由底向上，长的都是由短的逐个拼接起来的
        #例如[1,2,3]的所有子集
        #长度为0：[]
        #长度为1：[1], [2], [3] (长度为0的加上自己)
        #长度为2：[1,2], [1,3], [2,3](长度为1的加上一个非自己的元素。题目保证元素互不相同，那么拿掉自己以后，就不会在自己递归向下的路径中有自己)
        #长度为3：[1,2,3] (本身。返回值中要包含递归方法的直接返回值)
        #处理递归边界
        #十分钟，一次提交，时间击败-99.67%，空间击败-5.07%
        if len(nums) == 0:
            return [[]]
        else:
            #否则，拿掉一位元素后(只能是首位或者末位，因为不知道这一层的nums有几位)，再向下递归
            #比如，拿掉首位
            #再比如
            tempResult =  self.subsets(nums[1:])
            return tempResult + [[nums[0]] + i  for  i  in tempResult]
