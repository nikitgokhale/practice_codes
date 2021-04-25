

# Python3 program to perfrom a merge sort on a doubly linked list


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def printList(self, head):
        if (head is None):
            print(" ")
            return head

        currNode = head
        print("None <-> ")
        while (currNode):
            print(currNode.data, end=" <-> ")
            currNode = currNode.next
        
        print("None")

    # Given a reference to the head of a list and an
    # integer,inserts a new node on the front of list
    def push(self, newvalue):
        # 1. Allocates node
        # 2. Put the data in it
        newNode = Node(newvalue)

        # 3. Make next of new node as head and
        # previous as None (already None)
        newNode.next = self.head

        # 4. change prev of head node to new_node
        if self.head is not None:
            self.head.prev = newNode
        
        # 5. move the head to point to the new node
        self.head = newNode

    def getMiddle(self, head):
        if head is None:
            return head
            
        slow = head
        fast = head
        
        while (fast.next != None and
            fast.next.next != None):
            slow = slow.next
            fast = fast.next.next
            
        return slow
    
    def merge(self, left, right):
        if left is None:
            return right
        if right is None:
            return left
            
        if (left.data < right.data):
            left.next = self.merge(left.next, right)
            left.next.prev = left
            left.prev = None
            return left
        else:
            right.next = self.merge(left, right.next)
            right.next.prev = right
            right.prev = None
            return right

    def sortDoubly(self, head):
        #Your code here
        if head is None or head.next is None:
            return head
            
        middle = self.getMiddle(head)
        nextToMiddle = middle.next
        
        middle.next = None
        nextToMiddle.prev = None
        
        left = self.sortDoubly(head)
        right = self.sortDoubly(nextToMiddle)
        
        sortedList = self.merge(left, right)
        return sortedList
    


if __name__ == '__main__':
    dlt = DoublyLinkedList()

    dlt.push(15)
    dlt.push(12)
    dlt.push(65)
    dlt.push(5)
    dlt.push(34)
    dlt.push(43)
    dlt.push(16)

    print("Doubly Linked List before sorting: ")
    dlt.printList(dlt.head)

    dlt.head = dlt.sortDoubly(dlt.head)
    print("Doubly Linked List after sorting: ")
    dlt.printList(dlt.head)
