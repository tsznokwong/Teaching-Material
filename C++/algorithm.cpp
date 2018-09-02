#include<cstdio>
using namespace std;

template <class Max>
Max maximum(Max array[],int size){
    //func: maximum in array
    //  in: array, size
    // out: max value
    int max=array[0];
    for(int i=0;i<size;++i)
        if(max<array[i])
            max=array[i];
    return max;
}

template <class Min>
Min minimum(Min array[],int size){
    //func: minimum in array
    //  in: array, size
    // out: min value
    int min=array[0];
    for(int i=0;i<size;++i)
        if(min>array[i])
            min=array[i];
    return min;
}

template <class T>
void swap(T *a,T *b){
    //func: swapping value
    //  in: address of two object
    T tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

template <class R>
void reverse(R array[],int size){
    //func: reverse order of array
    //  in: array, size
    for(int i=0;i<size/2;++i)
        swap(&array[i],&array[size-i-1]);
}

template <class Bsort>
void bubble_sort(Bsort array[],int size,bool asc){
    //func: bubble sort
    //  in: array, size, ascending or not
    for(int i=0;i<size;++i){
        bool cnt=false;
        for(int j=0;j<size-1-i;++j)
            if(array[j]>array[j+1]){
                swap(&array[j],&array[j+1]);
                cnt=true;
            }
        if(!cnt)break;
    }
    if(!asc)
        reverse(array,size);
}

template <class Isort>
void insertion_sort(Isort array[],int size,bool asc){
    //func: insertion sort
    //  in: array, size, ascending or not
    for(int i=0;i<size;++i)
        for(int j=i;j>0;--j)
            if(array[j]<array[j-1])
                swap(&array[j],&array[j-1]);
            else break;
    if(!asc)
        reverse(array,size);
}

template <class Ssort>
void selection_sort(Ssort array[],int size,bool asc){
    //func: selection sort
    //  in: array, size, ascending or not
    for(int i=0;i<size-1;++i){
        int min=i;
        for(int j=i;j<size;++j)
            if(array[j]<array[min])
                min=j;
        swap(&array[i],&array[min]);
    }
    if(!asc)
        reverse(array,size);
}

template <class Csort>
void counting_sort(Csort array[],int size,bool asc){
    //func: counting sort
    //  in: array, size, ascending or not
    int min=minimum(array,size),max=maximum(array,size);
    int cnt[max-min];
    for(int i=0;i<max+1-min;++i)
        cnt[i]=0;
    for(int i=0;i<size;++i)
        ++cnt[array[i]-min];
    int k=0;
    for(int i=0;i<max+1-min;++i)
        for(int j=0;j<cnt[i];++j)
            array[k++]=i+min;
    if(!asc)
        reverse(array,size);
}

template <class Shsort>
void shell_sort(Shsort array[],int size,bool asc){
    //func: shell sort
    //  in: array, size, ascending or not
    int incr;
    int isize=size-size%3+1;
    for(incr=isize;incr>0;incr=incr-3)
        for(int i=incr;i<size;++i)
            for(int j=i;j>=incr;j-=incr)
                if(array[j]<array[j-incr])
                    swap(&array[j],&array[j-incr]);
                else break;
    if(!asc)
        reverse(array,size);
}
template <class Merge>
void merge(Merge array[],int pos,int size){
    Merge b[size];
    int i=pos,j=pos+size/2;
    for(int k=0;k<size;++k){
        if(i<pos+size/2&&(j>=pos+size||array[i]<=array[j])){
            b[k]=array[i];
            ++i;
        }
        else{
            b[k]=array[j];
            ++j;
        }
    }
    for(int k=0;k<size;++k)
        array[pos+k]=b[k];
        
}
template <class Msort>
void merge_sort(Msort array[],int pos,int size){
    if(size==1)return;
    merge_sort(array,pos,size/2);
    merge_sort(array,pos+size/2,size-size/2);
    merge(array,pos,size);
}
template <class Lsearch>
Lsearch linear_search(Lsearch array[],int size,Lsearch target){
    //func: linear search
    //  in: array, size, target
    // out: index of target (unable to find return -1)
    for(int i=0;i<size;++i)
        if(array[i]==target)
            return i;
    return -1;
}

template <class Bsearch>
Bsearch binary_search(Bsearch array[],int size,Bsearch target){
    //func: binary search
    //  in:: array, size, target
    //  out: index of target (unable to find return -1)
    int up,mid,low;
    low=-1; up=size;
    while(up-low>1){
        mid=(up+low)/2;
        if(target<=array[mid]) up=mid;
        else low=mid;
    }
    if(target==array[up])return up;
    else return -1;
}

template <class Isearch>
Isearch interpolation_search(Isearch array[],int size,Isearch target){
    //func: interpolation search
    //  in:: array, size, target
    //  out: index of target (unable to find return -1)
    int up,mid,low;
    low=0; up=size-1;
    while(up-low>1){
        mid=low+(up-low)/(array[up]-array[low])*(target-array[low]);
        if(target<array[mid]) up=mid;
        else if(target>array[mid])low=mid;
        else break;
        
    }
    if(target==array[mid])return mid;
    else return -1;
}


int main(){
    int x[50];
    int a,b,n;
  //  scanf("%d%d",&a,&b);
  //  swap(&a,&b);
  //  printf("%d %d\n",abs(a),b);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&x[i]);
   // bubble_sort(x,n,1);
   // insertion_sort(x,n,0);
   // selection_sort(x,n,0);
   // reverse(x,n);
   // counting_sort(x,n,1);
   // shell_sort(x,n,1);
    merge_sort(x,0,n);
    for(int i=0;i<n;++i)
        printf("%d%c",x[i],i<n-1?' ':'\n');
    //printf("%d\n",interpolation_search(x,n,8));
    return 0;
}













