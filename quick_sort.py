#快速排序
def quick_sort(data, left, right):
    if(left < right):
        mid = partition(data, left, right)#选出当前随机点位置
        quick_sort(data, left, mid-1) #左侧排序
        quick_sort(data, mid+1, right) #右侧排序

def partition(data, left, right):
    tmp = data[left] #随机数为范围内左侧第一个数值
    while (left < right):
        while((left < right) and (data[right] >= tmp)):
            right -= 1
        data[left] = data[right]
        while((left < right) and (data[left] <= tmp)):
            left += 1
        data[right] = data[left]
    data[left] = tmp
    return left #此时最左侧索引为mid所处位置

if __name__ == "__main__":
    data_list = [1, 3, 21, 6, 50, 33, 34, 58, 66]
    quick_sort(data_list, 0, len(data_list)-1)
    print(data_list)
