'''
学不会并查集不准走
'''
class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))

    def union(self, index1: int, index2: int):
        #把两路树合并
        self.parent[self.find(index2)] = self.find(index1)

    def find(self, index: int) -> int:
        #级级向上的树状结构
        #根节点的父节点index是自己
        if self.parent[index] != index:
            #其他的都会层层向上直到返回自己的父节点
            self.parent[index] = self.find(self.parent[index])
        return self.parent[index]

class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        #使用email作为唯一键值
        emailToIndex = dict()   #email到email在字典中的下标顺序？
        emailToName = dict()    #email到姓名
        #遍历每个账户
        for account in accounts:
            name = account[0]
            #每个邮件地址
            for email in account[1:]:
                if email not in emailToIndex:
                    emailToIndex[email] = len(emailToIndex) #这个email放在字典的第几个位置？字典是线性存储？
                    #解答，上面这个字典的值并没有什么特殊意义，只要能够给每个email一个唯一标识即可，因此使用字典当时的长度也行
                    emailToName[email] = name   #email和所有者的关系，会不会同一email持有者有多个名字？不会，题目默认
        #建立并查集，长度是email，用于关联尽可能多的email
        uf = UnionFind(len(emailToIndex))
        #填充并查集
        for account in accounts:
            #所有邮箱都关联到第一个邮箱地址，随着遍历，即使跨账户， 也能够关联起来
            firstIndex = emailToIndex[account[1]]
            for email in account[2:]:
                uf.union(firstIndex, emailToIndex[email])
        #直呼内行，collection.defaultdict如果传入列表，能够将列表第一个作为键，后面的都作为值
        indexToEmails = collections.defaultdict(list)
        for email, index in emailToIndex.items():
            index = uf.find(index)  #并查集，返回同一路的email
            #填充
            indexToEmails[index].append(email)
        #填充的结果准备好了，重建结果
        ans = list()
        for emails in indexToEmails.values():
            #emails[0]是因为返回任意账户，都能返回名字
            ans.append([emailToName[emails[0]]] + sorted(emails))
        return ans
