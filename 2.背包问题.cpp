#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10010;
int n;
int w[N];
int v[N];
//int getMaxValue(int w[],int v[],int bag) {
//	return process(w,v,0,0,bag);
//}
//int process(int w[],int v[],int index,int alreadyw,int bag) {
//	if (alreadyw > bag) {
//		return -1;
//	}
//	if (index == n) {
//		return 0;
//	}
//	int p1 = process(w, v, index + 1,alreadyw, bag);
//	int p2next = process(w,v,index + 1,alreadyw + w[index],bag);
//	int p2 = -1;
//	if (p2next != -1) {
//		p2 = v[index] + p2next;
//	}
//	return max(p1, p2);
//}
int getMaxValue(int w[],int v[],int bag) {
	return process(w,v,0,bag);
}
int process(int w[] ,int v[],int index,int rest) {
	if (rest <= 0)
		return -1;
	if (index == n)
		return 0;
	int p1 = process(w,v,index + 1,rest);
	int p2 = 0x3f;
	if (rest >= w[index]) {
		p2 = v[index] + process(w,v,index + 1,rest - w[index]);
	}
	return max(p1, p2);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	int bag;
	cin >> bag;
	int res = getMaxValue(w, v, bag);
	return 0;
}