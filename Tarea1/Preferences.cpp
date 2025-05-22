#include <iostream>
#include <vector>

using namespace std;

int merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;
    int total = 0;

    for (; i < leftArr.size() && j < rightArr.size(); k++) {
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i++];
        }
        else {
            arr[k] = rightArr[j++];
            total += leftArr.size()-i;
        }
    }

    for (; i < leftArr.size(); k++, i++) arr[k] = leftArr[i];
    for (; j < rightArr.size(); k++, j++) arr[k] = rightArr[j];
    
    return total;
}

int mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return 0;

    int mid = (left + right) / 2;
    int a = mergeSort(arr, left, mid);
    int b = mergeSort(arr, mid + 1, right);
    int c = merge(arr, left, mid, right);

    return a+ b+ c;
}

int main()
{
    vector<int> a = {1,5,4,8,10,2,6,9,12,11,3,7};
    vector<int> b = { 3,7,10,14,18,19,2,11,16,17,23,25 };
    int conteo = mergeSort(b,0,b.size()-1);
    std::cout << conteo << std::endl;
    conteo = mergeSort(a,0,a.size()-1);
    std::cout << conteo << std::endl;
    
}
