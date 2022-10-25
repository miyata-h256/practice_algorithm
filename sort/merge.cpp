#include<iostream>
#include<vector>
using namespace std;

void MergeSort(vector<int> &a,int left,int right){
    if(right - left == 1) return;

    int mid = left + (right-left)/2;

    //[left,mid)をソート
    MergeSort(a,left,mid);

    //[mid,right)をソート
    MergeSort(a,mid,right);

    //左と右のソート結果をコピー
    vector<int> buf;
    for(int i=left;i<mid;i++) buf.push_back(a[i]);
    for(int i=right-1;i>=mid;i--) buf.push_back(a[i]);


    //併合する(実際のソート部分)
    int index_left = 0;
    int index_right = (int)buf.size()-1;
    for(int i=left;i<right;i++){
        //左側採用
        if(buf[index_left]<=buf[index_right]){
            a[i] = buf[index_left++];
        }
        //右側採用
        else{
            a[i] = buf[index_right--];
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> a(N);

    for(int i=0;i<N;i++) cin >> a[i];

    printf("Before Sort: ");
    for(int i=0;i<N;i++){
        printf("%5d",a[i]);
    }
    putchar('\n');

    MergeSort(a,0,N);

    printf("After Sort: ");
    for(int i=0;i<N;i++){
        printf("%5d",a[i]);
    }

    putchar('\n');
}