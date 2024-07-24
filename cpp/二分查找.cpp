#include <iostream>
using std::cout;
using std::endl;

int binarySearch(int arr[], int length, int target) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // 防止溢出

        if (arr[mid] == target) {
            return mid; // 找到目标元素
        }

        if (arr[mid] < target) {
            left = mid + 1; // 目标在右半部分
        } else {
            right = mid - 1; // 目标在左半部分
        }
    }
    return -1; // 未找到目标元素
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int target = 7;
    int length = sizeof(arr) / sizeof(arr[0]); // 在主函数中计算数组长度
    
    int result = binarySearch(arr, length, target);

    if (result == -1) {
        cout << "元素未找到" << endl;
    } else {
        cout << "元素找到了，位置为: " << result << endl;
    }
    return 0;
}
