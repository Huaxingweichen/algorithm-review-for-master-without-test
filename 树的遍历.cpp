//
// Created by 黄灏 on 2019-05-27.
//

#include <iostream>
using namespace std;

/*
 * 本脚本实现树的先序、中序、后序、层次遍历，树的存储形式是一维数组，-1表示空。
 */

int tree[100];//树存储数组
int n;//节点个数

void PreOrderTraverse(int i)
{
    if(tree[i]!=-1)
    {
        cout<<tree[i];
        PreOrderTraverse(2*i);
        PreOrderTraverse(2*i+1);
    }
}

void InOrderTraverse(int i)
{
    if(tree[i]!=-1)
    {
        InOrderTraverse(2*i);
        cout<<tree[i];
        InOrderTraverse(2*i+1);
    }
}

void PostOrderTraverse(int i)
{
    if(tree[i]!=-1)
    {
        PostOrderTraverse(2*i);
        PostOrderTraverse(2*i+1);
        cout<<tree[i];
    }
}

int main(void)
{
    memset(tree,-1,100* sizeof(int));
    cin>>n;
    for (int i = 1; i <= n; ++i) {
        cin>>tree[i];
    }
    PreOrderTraverse(1);
    cout<<endl;
    InOrderTraverse(1);
    cout<<endl;
    PostOrderTraverse(1);
    cout<<endl;
    //层次遍历对于这一种存储方式来说，嘻嘻嘻嘻
    for (int j = 1; j <= n; ++j) {
        cout<<tree[j];
    }
}