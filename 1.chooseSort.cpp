void process(vector<int> &arr) {
    if (arr == nullptr || arr.size() < 2) {
        return ;
    }
    for (int i = 0 ; i < arr.size() - 1; i++) { // 当前位置
        int minIndex = i;
        for (int j = i + 1; j < arr.size(); j++) {
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        swap(arr,i,minIndex);
    }
}
void swap(vector<int> &arr,int j,int j) {
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}
