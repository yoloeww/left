void bubbleSort(vector<int> &arr) {
    if (arr == nullptr || arr.size() < 2) {
        return ;
    }
    int n = arr.size();
    for (int i = 0; i < n; i++) { // //控制交换次数
        for (int j = 0; j < n - i - 1; j ++) { // //向后冒泡 ,控制边界
            if(arr[j] > arr[j+1])//如果前一个值大于后一个值,交换
			{
				swap(arr[j],arr[j+1]);
			}		
        }
    }
}
