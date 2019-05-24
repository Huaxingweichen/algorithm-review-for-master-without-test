//
// Created by 黄灏 on 2019-05-22.
//

#include <iostream>
using namespace std;

int num[100];//数组存储排序的数字
int sorted_num[100];//归并排序和插入排序中的中间数组
int n;//排序的数量



void mergesort(int i, int j) //递归方式的归并排序，二分下去
{
    if(j-i>=2)
    {
        mergesort(i,j-(j-i)/2);
        mergesort(j-(j-i)/2,j);
        int pa = i;
        int pb = j-(j-i)/2;
        int flag = i;
        while (pa<(j-(j-i)/2)&&pb<j)
        {
            if(num[pa]<=num[pb])
                sorted_num[flag++] = num[pa++];
            else
                sorted_num[flag++] = num[pb++];
        }
        while (pa<(j-(j-i)/2))
        {
            sorted_num[flag++] = num[pa++];
        }
        while (pb<j)
        {
            sorted_num[flag++] = num[pb++];
        }
        for (int k = i; k < j; ++k) {
            num[k] = sorted_num[k];
        }
    }

}

void bubblesort() //简单的冒泡排序
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if(num[j]>num[j+1])
            {
                int temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }
}

void insertsort() //简单的插入排序
{
    sorted_num[0] = num[0];
    for (int i = 1; i < n; ++i) {
        int f = 0;
        for (int j = i-1; j >= 0; --j) {
            if(num[i]<sorted_num[j]) {
                sorted_num[j + 1] = sorted_num[j];
            }
            else {
                f++;
                sorted_num[j+1] = num[i];
                break;
            }
        }
        if(f==0)sorted_num[0] = num[i];
    }
    for (int l = 0; l < n; ++l) {
        num[l] = sorted_num[l];
    }
}

void selectsort()//简单的选择排序
{
    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i; j < n; ++j) {
            if(num[min_index]>num[j])
                min_index = j;
        }
        int temp = num[min_index];
        num[min_index] = num[i];
        num[i] = temp;
    }
}

void quicksort(int i,int j)//快排的递归实现
{
    if(i<j){
        int temp = num[j];
        int pa = i;
        int pb = j;
        for (int k = i; k < j; ++k) {
            if(num[k]>temp)
            {
                int t = num[pb];
                num[pb--] = num[k];
                num[k] = t;
            }
        }
        num[pb] = temp;
        quicksort(i,pb-1);
        quicksort(pb+1,j);
    }
}

void shellsort() //希尔排序
{
    int j,k;
    for (int i = n/2; i > 0; i/=2) {
        for (j = i; j < n; ++j) {
            int temp = num[j];
            for (k = j-i; k >=0&&num[k]>temp; k-=i) {
                num[k+i] = num[k];
            }
            num[k+i] =  temp;
        }

    }
}

void adjustheap(int sign, int len)//调整堆
{
    int temp = num[sign];
    for (int i = sign*2+1; i < len; i = i*2+1) {
        if(i+1<len&&num[i+1]>num[i])
            i++;
        if(num[i]>temp){
            num[sign] = num[i];
            sign = i;
        }
    }
    num[sign] = temp;
}

void heapsort(int length) // 堆排序
{
    for (int k = length/2 -1; k >= 0; --k) {
        adjustheap(k,length);
    }
    for (int j = length-1; j >=0 ; --j) {
        int temp = num[j];
        num[j] = num[0];
        num[0] = temp;
        adjustheap(0,j);
    }
}



int main(void)
{

    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>num[i];
    }
//    mergesort(0,n);
//    bubblesort();
//    insertsort();
//    selectsort();
//    quicksort(0,n-1);
//    shellsort();
    heapsort(n);
    for (int i = 0; i < n; ++i) {
        cout<<num[i]<<" ";
    }
    return 0;
}