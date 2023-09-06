void insertSort(vector<int> &arr) {
    if (arr == nullptr || arr.size() < 2) {
        return ;
    }
    
    for (int i = 1; i < arr.size(); i++) { // 0 - 0 有序的
    
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1] ; j--) { // 想有序
            swap(arr,j, j + 1);
        }
        
    }
}
