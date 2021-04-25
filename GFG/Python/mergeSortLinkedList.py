# Python3 code to merge sort a linked list

# Creating a node, using class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    # Push new value to a linked list
    # using append technique
    def append(self, newValue):
        newNode = Node(newValue)

        if self.head is None:
            self.head = newNode
            return
        currNode = self.head
        while currNode.next is not None:
            currNode = currNode.next

        currNode.next = newNode

    def printList(self, head):
        if head is None:
            print(' ')
            return
        currNode = head
        while currNode:
            print(currNode.data, end= ' -> ')
            currNode = currNode.next
        print('NULL ')

    def getMiddle(self, head):
        if (head == None):
            return head
        
        slow = head
        fast = head

        while (fast.next is not None and
                fast.next.next is not None):
            slow = slow.next
            fast = fast.next.next

        return slow

    def mergeSort(self, head):
        if head is None or head.next is None:
            return head

        middle = self.getMiddle(head)
        nextToMiddle = middle.next

        middle.next = None

        left = self.mergeSort(head)
        right = self.mergeSort(nextToMiddle)

        sortedList = self.merge(left, right)
        return sortedList

    def merge(self, left, right):
        result = None

        if left == None:
            return right
        if right == None:
            return left

        if (left.data < right.data):
            result = left
            result.next = self.merge(left.next, right)
        else:
            result = right
            result.next = self.merge(left, right.next)

        return result
            


if __name__ == '__main__':
    li = LinkedList()

    li.append(15)
    li.append(12)
    li.append(65)
    li.append(5)
    li.append(34)
    li.append(43)
    li.append(16)
    
    print("The list before sorting: ")
    li.printList(li.head)
    li.head = li.mergeSort(li.head)

    print('The list after sorting: ')
    li.printList(li.head)