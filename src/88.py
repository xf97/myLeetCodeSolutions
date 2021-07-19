class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        #干翻字节！
        #字节怎么现在都是简单题了，你不给力呀，整点得劲的给兄弟试试呀
        #归并排序
        #先看看使用额外空间Om+n的解法
        #边界情况
        #两次提交，注意python的深度赋值，十二分钟
        #时间击败-90.92%，空间击败-43.16%
        if m ==0:
            nums1[:] = nums2   #改变引用
            return
        elif n == 0:
            return
        else:
            pm, pn = 0, 0 #pointerM, pointerN
            result = list()
            while pm < m or pn < n:
                #先处理一个走完的情况
                if  pm >= m:
                    while pn < n:
                        result.append(nums2[pn])
                        pn += 1
                elif pn >= n:
                    while pm < m:
                        result.append(nums1[pm])
                        pm += 1
                else:
                    #两个都还有的情况
                    if nums1[pm] < nums2[pn]:
                        result.append(nums1[pm])
                        pm += 1
                    else:
                        result.append(nums2[pn])
                        pn += 1
        #print(result)
        nums1[:] = result
        return

