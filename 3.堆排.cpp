# 一、堆排序

> 堆其实是一颗完全二叉树，左节点（2 * i - 1），右节点（2 *  i + 1），根节点（i - 1）/ 2。
> 在堆中插入一个新的元素，需要判断该元素和根节点大小关系，并且进行调整，保证当前结构是一个大根堆。
**> 构建最大堆是一个自下向上的过程。**
## 1、堆类
```cpp
class Bigheap{
   public:
   void heapInsert(vector<int> arr, int index); //构建最大堆
   void heaply(vector<int> arr, int index, int heapSize); // 删除节点
   void heapSort(vector<int> arr); //堆排
};
```

## 2、构建最大堆

```cpp
void heapInsert(vector<int> arr, int index){ //构建最大堆
        int parent = (index - 1) / 2;
        while (arr[index] > arr[parent]) { // 子节点的值大于父节点的值
 			swap(arr, index, parent); //交换父子
 			index = parent; //子变成了旧的父
 			parent = (index - 1) / 2; //父变为他的上一个
		}
}
```
## 3 、删除一个节点

```cpp
// 某个数在index位置，想下移动保持最大堆
// 自上而下的调整
void heaply(vector<int> arr, int index, int heapSize) {
		int left = index * 2 + 1;
		// 如果有子孩子就判断
		while (left < heapSize) {
		    // 左右孩子之间比较最大值
			int largest = (left + 1 < heapSize && arr[left] < arr[left + 1] ? left + 1 : left;
			largest = arr[largest] > arr[index] ? largest : index;   //父子之间比较最大值
			if (largest == index) // 父节点已经是最大值 {
			  break;
			  }
			 swap(arr, index, largest);
			 index = largest; //然后继续往上走
 			 left = index * 2 + 1;
		}
}
```
## 4、堆排序

```cpp
void heapSort(vector<int> arr) {
		if(arr == NULL || arr.size() < 2)
		return;
		int heapSize = arr.size();
		for (int i = 0; i < heapSize; i ++) {
			heapInsert(arr, i);	
		}
		while (heapSize > 0) {
 		 	swap (arr, 0, --heapSize);  //将最大值移动到队尾并且遮蔽最大值
 		 	heapfy (arr, 0, heapSize);  //将队尾写入队头，自上而下调整为最大堆
		}
}
```

# 二、计数排序

  > - 计数排序是不基于比较的排序 
   >-  不基于比较的排序，都是根据具体的数据状况做的排序，应用范围不广，很窄的一路数据排序算法。
   > - 假设一个整数数组，里面的数都是员工的年龄 
   >  - 分析： 由于员工的年龄是18-60岁之间，所以我们假设数据的范围为0-100
   > - 我们申请一个长度为100的数组，我们规定在数组的第18位置上的数为18岁的人有多少个（频数）。 即下标为年龄，位置上的数为该年龄的数量。
   > - 该算法的时间复杂度为O(N)
   
## 1、思路

 - 先准备一个有限个数（比如200）的整型辅助数组，挨个遍历原始数组，得到的值是 i，则将辅助数组 i 位置的值加一
 - 遍历辅助数组，如果数组位置 i 上的值是k，则输出k个i，得到的即是排好序的数组

```cpp

   void countSort(vector<int> arr){
      if(arr.size() < 2)
      return;
      int maxt = Integer.MIN_VALUE;
      for(int v : arr) {
         maxt = max(maxt, v);
 	  }
 	  // 统计每个数出现的个数
 	  vector<int> nums(maxt + 1);
 	  for(int v : arr) {
 	  	nums[v]++;
 	  }
 	  // 从小到大开始排
 	  int i = 0;
 	  for (int j = 0; j < nums.size(); j++) {
 	     while (nums[j] -- > 0)
 	     arr[i++] = j;
 	  }
	}
  
```
# 三、基数排序
>适用于十进制正整数

 1. 遍历整个数组，得到最大值的十进制位数，同时将不满足最大位数的数高位补0。
 2. 准备十个桶，从0 - 9编号，每个桶大小为原数组大小。
3. 遍历数组，以个位数为标准，个位数的值是 i，则将其放到第 i 号桶里；遍历完后，从0号桶开始，挨个将里面的数倒出来（先进先出）。此时的数是根据个位数排序。
4. 遍历数组，以十位数为标准，十位数的值是 i，则将其放到第 i 号桶里；遍历完后，从0号桶开始，挨个将里面的数倒出来（先进先出），此时的数是根据十位数排序。

```cpp
 void radixSort(vector<int> arr){
      if(arr.size() < 2)
      return;
      sort(arr, 0, arr.size() - 1, maxBit(arr));
      }
 void maxBit(vector<int> arr){    
 	int maxt = Integer.MIN_VALUE;
    for (int value : arr) {
        maxt = max(maxt, value);
    }
    int res = 0;
    while (maxt != 0) {
        res++;
        maxt /= 10;
    }
    return res;
 }
void sort(vector<int> arr, int l, int r, int digit) {
	int radix = 10;
}
```
