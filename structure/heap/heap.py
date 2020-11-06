import heapq



if __name__ == "__main__":
    arr = [4,5,1,2,6,3]
    arr1 = [10,9,8,11]
    # 初始化堆
    heapq.heapify(arr)
    
    # 插入元素
    heapq.heappush(arr, 7)

    # 弹出并返回最小元素
    m = heapq.heappop(arr)

    # 最大n个元素
    heapq.nlargest(3, arr)

    # 最小n个元素
    heapq.nsmallest(3, arr)

    # 合并
    heapq.merge(arr, arr1)