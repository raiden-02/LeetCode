class MyCircularQueue:

    def __init__(self, k: int):
        self.d = []
        self.k = k

    def enQueue(self, value: int) -> bool:
        if(self.k != 0):
            self.d.append(value)
            self.k -= 1
            return True
        return False

    def deQueue(self) -> bool:
        if(self.d != []):
            self.d.pop(0)
            self.k += 1
            return True
        return False

    def Front(self) -> int:
        if self.d == []:
            return -1
        return self.d[0]

    def Rear(self) -> int:
        if self.d == []:
            return -1
        return self.d[-1]

    def isEmpty(self) -> bool:
        return self.d == []

    def isFull(self) -> bool:
        return self.k == 0


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
