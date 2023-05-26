def selection_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

if __name__ == '__main__':
    n = int(input("Enter the number of elements: "))

    arr = []
    print("Enter the values:")
    for i in range(n):
        x = int(input("Element {}: ".format(i + 1)))
        arr.append(x)

    print("\nThe array you entered is:", end=" ")
    for num in arr:
        print(num, end=" ")

    print("\n\nPerforming Selection Sort on the given array...")
    selection_sort(arr)

    print("\nThe sorted array is:", end=" ")
    for num in arr:
        print(num, end=" ")
