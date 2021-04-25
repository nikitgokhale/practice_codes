def quickSort(head):
    #return head after sorting
    dataList = []
    while head:
        dataList.append(head.data)
        head = head.next
    
    resList = quick(dataList)
    for i in resList:
        print(i, end=" ")
            
def quick(dataList):
    if len(dataList) <= 1:
        return dataList
    else:
        pivot = dataList.pop()
        left = []
        right = []
        
        for data in dataList:
            if data < pivot:
                left.append(data)
            else:
                right.append(data)
    return quick(left)+[pivot]+quick(right)