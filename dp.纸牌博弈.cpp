#include<iostream>
using namespace std;
int f(int arr[], int l, int r) {
	if (r == l) {
		return arr[l];
	}
	return max(arr[l] + s(arr, l + 1, r),arr[r] + s(arr, l, r - 1));
}
int s(int arr[], int l, int r) {
	if (l == r) {
		return 0;
	}
	return min(f(arr,l + 1,r),f(arr,l,r - 1))
}
int main() {

	int arr[] = {1,49,23,32};
	return 0;
}
