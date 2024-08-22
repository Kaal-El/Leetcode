class LockingTree:
    def __init__(self, parent: List[int]):
        self.tree={}
        self.parent=parent
        for i in range(len(parent)):
            if parent[i]==-1:
                continue
            if parent[i] in self.tree:
                self.tree[parent[i]].append(i)
            else:
                self.tree[parent[i]]=[i]
        self.locks=[]
        for i in range(len(parent)):
            self.locks.append([0,0])
        # print(self.locks,self.tree)


    def lock(self, num: int, user: int) -> bool:
        if(self.locks[num][0]==0):
            self.locks[num][0]=1
            self.locks[num][1]=user
            # print(self.locks)
            return True
        return False

    def unlock(self, num: int, user: int) -> bool:
        if(self.locks[num][0]==1 and self.locks[num][1]==user):
            self.locks[num][0]=0
            self.locks[num][1]=0
            return True
        return False

    def upgrade(self, num: int, user: int) -> bool:
        if(self.locks[num][0]==0 and self.checkDescendent(num)==True and self.checkAncestor(num)==True):
            self.locks[num][0]=1
            self.locks[num][1]=user
            self.unlockDescendent(num)
            return True
        return False
    
    def unlockDescendent(self,num):
        node=[]
        if num in self.tree:
            node.extend(self.tree[num])
        while(len(node)!=0):
            a=node.pop(0)
            self.locks[a][0]=0
            self.locks[a][1]=0
            if a in self.tree:
                node.extend(self.tree[a])
    
    def checkDescendent(self,num):
        node=[]
        if num in self.tree:
            node.extend(self.tree[num]) 
        while(len(node)!=0):
            a=node.pop(0)
            if self.locks[a][0]==1:
                return True
            if a in self.tree:
                node.extend(self.tree[a])
        return False
    
    def checkAncestor(self,num):
        if num==0:
            return True
        node=[self.parent[num]]
        while(len(node)!=0):
            a=node.pop(0)
            if self.locks[a][0]==1:
                return False
            elif a==0:
                return True
            node.append(self.parent[a])



# Your LockingTree object will be instantiated and called as such:
# obj = LockingTree(parent)
# param_1 = obj.lock(num,user)
# param_2 = obj.unlock(num,user)
# param_3 = obj.upgrade(num,user)