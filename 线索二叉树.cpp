//
// Created by 黄灏 on 2019-05-27.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct BitNode
{
    char data;
    struct  BitNode *lchild, *rchild; //左右孩子
    bool Ltag; //左右标志 0表示指向孩子 1表示指向前驱或者后继
    bool Rtag;
}BitNode, *BiTree;

BiTree p; //中序线索化的时候记录刚刚访问的节点

void createBiTree(BiTree &T)
{
    char a;
    cin>>a;
    if(a!='#')
    {
        T->data = a;
        T->Rtag = T->Ltag = 0;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
    else
        T = NULL;
}

void InThreading(BiTree &T) //线索化
{
    if(T)
    {
        InThreading(T->lchild);
        if(!T->lchild)
        {
            T->lchild = p;
            T->Ltag = 1;
        }
        if(!T->rchild)
        {
            T->rchild = p;
            T->Rtag = 1;
        }
        p = T;
        InThreading(T->rchild);
    }
}

int main(void)
{
    BiTree T;
    createBiTree(T);
    InThreading(T);

    return 0;
}