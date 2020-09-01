class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        openRoom = [0]
        myKeys = list()
        while len(openRoom) < len(rooms):
            preLength = len(openRoom)
            myKeys.extend(self.getNewKeys(openRoom, rooms))
            myKeys = list(set(myKeys))
            openRoom.extend(myKeys)
            openRoom = list(set(openRoom))
           # print(myKeys)
            #print(openRoom)
            if preLength == len(openRoom):
                return False
            else:
                continue
        return True
            
    def getNewKeys(self, _room, _allRooms):
        temp = list()
        for i in _room:
            temp.extend(_allRooms[i])
        return list(set(temp))
