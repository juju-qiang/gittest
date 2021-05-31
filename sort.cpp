#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

void BubbleSort(int (&num)[11]){
    int n=11;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            if(num[j]>num[j+1]){
                int temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
}

void SelectionSort(int (&num)[11]){
    int n=11;
    for(int i=0;i<n;i++){
        //num[0]到num[i-1]是现有有序序列；num[i]到num[n-1]是无序序列；
        int minindex=i;
        int j=i+1;
        for(j=i+1;j<n;j++){
            if(num[j]<num[minindex]){
                minindex=j;
            }
        }
        swap(num[i],num[minindex]);
    }
}

void InsertionSort(int (&num)[11]){
    int n=11;
    //默认第一个数字是有序的
    for(int i=1;i<n;i++){
        
        int temp=num[i];
        int preindex=i-1;
        while(preindex>=0&&num[preindex]>temp){
            num[preindex+1]=num[preindex];
            preindex--;
        
        }
        num[preindex+1]=temp;
        
    }
}

void shellsort1(int (&num)[11]){
    int i,j,gap;
    int n=11;
    for(gap=n/2;gap>0;gap/=2){
        for(i=0;i<gap;i++){
            for(j=i+gap;j<n;j+=gap){
                if(num[j]<num[j-gap]){
                    int temp=num[j];
                    int current=j-gap;
                    while(current>=0&&num[current]>temp){
                        //while()条件里不能直接用num[j],因为num[j]也是数组
                        //一部分，会被改变，要用temp存起来它的值
                        num[current+gap]=num[current];
                        current-=gap;
                    }
                    num[current+gap]=temp;
                }
            }
        }
    }
}

void shellsort2(int (&num)[11]){
    int n=11;
    int i,gap;
    //改进在于把三重循环改进成两重循环，将分组进行的插入
    //优化成各组交替进行的插入排序
    for(gap=n/2;gap>0;gap/=2){
        for(i=gap;i<n;i++){
            if(num[i]<num[i-gap]){
                int temp=num[i];
                int current=i-gap;
                while(current>=0&&num[current]>temp){
                    num[current+gap]=num[current];
                    current-=gap;
                }
                num[current+gap]=temp;
            }
        }
    }
}

void merge(int num[],int low,int mid,int high){
    int *temp=new int[high-low+1];
    int leftindex=low;
    int rightindex=mid+1;
    int tempk=0;
    while(leftindex<=mid&&rightindex<=high){
        if(num[leftindex]<num[rightindex]){
            temp[tempk]=num[leftindex];
            tempk++;
            leftindex++;
        }
        else{
            temp[tempk]=num[rightindex];
            tempk++;
            rightindex++;
        }
    }
    while(leftindex<=mid){
        temp[tempk] = num[leftindex];
        tempk++;
        leftindex++;
    }
    while(rightindex<=high){
        temp[tempk] = num[rightindex];
        tempk++;
        rightindex++;
    }
    for(int i=low,tempk=0;i<=high,tempk<=high-low;i++,tempk++){
        num[i]=temp[tempk];
    }
    delete []temp;
}

void  MergeSort(int num[],int low,int high){
   if(low>=high){
       return ;
   }
    int mid=low+(high-low)/2;
    MergeSort( num,low,mid);
    MergeSort(num,mid+1,high);
    merge(num,low,mid,high);
}

int PartitionQS(int num[],int low,int high){
   if(!(low<high)){
      // return low;
   }
    int pivot=num[low];
    int pivotPosition=low;
    for(int i=low+1;i<=high;i++){
        if(num[i]<pivot){
            //两次交换保证每次基准值只向前移动一位，防止有值漏下比较
            //太他妈精妙了！！！！
           swap(num[pivotPosition+1],num[i]);
            swap(num[pivotPosition],num[pivotPosition+1]);
            pivotPosition++;
        }
    }
    return pivotPosition;                   
}
void QuickSort(int num[],int low,int high){
   if(!(low<high)){//low==high,说明传入的队列只有一个数字
       return ;
   }
    //int pivot=num[low];
    int newpivot=PartitionQS(num,low,high);
    QuickSort(num,newpivot+1,high);
    QuickSort(num,low,newpivot-1);

}

void MaxHeapIfy(int nums[], int i, int n)
{
    //把父结点为第i个结点的树变成最大堆
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largestIndex = i;
    if (left < n && nums[largestIndex] < nums[left])
    {
        largestIndex = left;
    }
    if (right < n && nums[largestIndex] < nums[right])
    {
        largestIndex = right;
    }
    if (largestIndex != i)
    {
        swap(nums[largestIndex], nums[i]);
        MaxHeapIfy(nums, largestIndex, n);
    }
}

void BuildMaxHeap(int nums[], int n)
{
    //把每棵子树都调整好，整棵树就调整好了，0号结点的值就是最大值
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        MaxHeapIfy(nums, i, n);
    }
}

void HeapSort(int nums[],int n){
   //每次都把0号结点（当前无序区最大结点）交换到第i个结点，然后减小i的值
    BuildMaxHeap(nums,n);
    for(int i=n-1;i>0;i--){
        swap(nums[0],nums[i]);
        MaxHeapIfy(nums,0,i);
    }
}
int main(){
    int array[]={10,0,2,3,4,5,9,8,7,6,1};
    //xxsort(&array);
    //BubbleSort(array);
    //SelectionSort(array);
    //InsertionSort(array);
    //shellsort1(array);
    //shellsort2(array);
    //MergeSort(array,0,10);
    /*int n=sizeof(array)/4;
    cout<<n<<endl;*/
    //排序结果是从小到大输出
    //QuickSort(array,0,10);
    HeapSort(array,11);
    for(int i=0;i<11;i++){
        cout<<array[i]<<" ";
    }
    return 0;
}