
class Solution {
public:
    int record[12];
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */
    bool isvaild(int record[],int i,int j) {
    for(int k = 0; k < i; k++) {
        if (record[k] == j || (abs(record[k] - j) == abs(i - k)))
            return false;
    }
    return true;
}
int process(int index,int record[],int n) {
    if (index == n) {
        return 1;
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
        if (isvaild(record,index,j)) {
            record[index] = j;
            res += process(index + 1,record,n);
        }
    }
    return res;
}
    int Nqueen(int n) {
        // write code here
         if (n < 1 || n > 32)
            return 0;
         int res = process(0,record,n);
         return res;
    }
};
