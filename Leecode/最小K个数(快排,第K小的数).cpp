url::https://leetcode-cn.com/problems/smallest-k-lcci/


class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if(k==0){
            return vector<int>{};
        }
        int r=findKofArr(arr,0,arr.size()-1,k);
        return vector<int>{arr.begin(),arr.begin()+r+1};
    }
    int findKofArr(vector<int> &arr,int p,int q,int k){
        int r=par(arr,p,q);
        if(r-p==k-1){
            return r;
        }
        else if(r-p<k-1){
            return findKofArr(arr,r+1,q,k-(r-p)-1);
        }
        else{
            return findKofArr(arr, p, r, k);
        }
    }
    // void quicksort(vector<int> &arr,int p,int q){
    //     if(p>=q){
    //         return;
    //     }
    //     int r=par(arr,p,q);
    //     quicksort(arr,p,r-1);
    //     quicksort(arr,r+1,q);
    // }
    int par(vector<int> &arr,int  p,int q){
        int r=rand()%(q-p+1)+p;
        swap(arr[r],arr[p]);
        int i=p,j=p+1;
        int priv=arr[i];
        for(;j<arr.size();++j){
            if(arr[j]<priv){
                swap(arr[j],arr[++i]);
            }
        }
        swap(arr[p],arr[i]);
        return i;
    }
};
