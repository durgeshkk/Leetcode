#include<bits/stdc++.h>
using namespace std;

int ans = 0;
void merge(vector<int> &arr, int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vector<int> a(n1), b(n2);
    bool flag = false;
    for(int i = 0;i < n1;i++){
        a[i] = arr[l + i];
    }
    
    for(int i = 0 ;i < n2;i++){
        b[i] = arr[mid + i + 1];
    }

    int i = 0,j = 0,k = l;
    while(i < n1 && j < n2){
        if(a[i] < b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            if(i < n1){++ans;}
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = a[i];
        k++;
        i++;
    }
    while(j < n2){
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int> &arr, int l, int r){
    if(l < r){
        int mid = (l + r)/2;

        mergeSort(arr, l, mid);

        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }
}

int largestCountValue(vector<int> arr){
    int n = arr.size();
    ans = 0;
    mergeSort(arr, 0, n-1);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    
    cout<<largestCountValue(arr);
    return 0;
}