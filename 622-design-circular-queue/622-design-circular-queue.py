class ListNode:
    def __init__(self, val: int = 0, prev: ListNode = None, next: ListNode = None):
        self.val = val
        self.prev = prev
        self.next = next

class MyCircularQueue:
    
    def __init__(self, k: int):
        self.front = None
        self.rear = None
        self.size = 0
        self.capacity = k

    def enQueue(self, value: int) -> bool:
        # self.printq()
        if self.isFull():
            return False
        
        node = ListNode(value)
        if self.front and self.rear:
            self.rear.next = node
            node.prev = self.rear
            node.next = self.front
            self.rear = node
        else:
            self.front = node
            self.rear = node
            # node.next = node
        self.size += 1
        
        # self.printq()
        return True
    
    def deQueue(self) -> bool:
        # self.printq()
        if self.isEmpty():
            return False
        
        if self.size == 1:
            self.front = None
            self.rear = None
        else:
            self.front = self.front.next
            self.front.prev = self.rear
        self.size -= 1
        
        # self.printq()
        return True

    def Front(self) -> int:
        return self.front.val if self.front else -1

    def Rear(self) -> int:
        return self.rear.val if self.rear else -1

    def isEmpty(self) -> bool:
        return self.size == 0
        
    def isFull(self) -> bool:
        return self.size == self.capacity
    
    def printq(self):
        node = self.front
        
        while node:
            print(f"{node.val} ->", end=" ")
            if node == self.rear:
                break
            node = node.next
            
        print(f"[end], size: {self.size}")
            
        


# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()