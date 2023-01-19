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


