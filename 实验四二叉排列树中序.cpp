/************************************************************/
/*                程序作者：爱的伊苏                        */
/*                程序完成时间：2019/1/3                    */
/*                有任何问题请联系：740531307@qq.com        */
/************************************************************/
//@永远得意的笑下去
 
#include<iostream>
#include<stdlib.h>
using namespace std;
 
typedef struct  BiNode
{
    int data;
    struct BiNode *lch, *rch;
} BiNode, *BiTree;
 
/*
 * 二叉排序树  插入数据原理
 *  1)若 b是空树， 返回false
    2)若 找到  返回true
    3)比当前节点小，那么进行搜索 找到 最后那个左孩子，右孩子都为空的节点
    4)和找到都那个节点进行 比较 判断新节点是要放在和这个
 */
bool searhBST(BiTree root , int data , BiTree f, BiTree &p)
{
    if(!root)
    {
        // root 是二叉树都根节点
        // f 是要返回都节点 p 是新建节点
        p = f;
        return false;
    }
    else  if(data == root->data)
    {
        //当前节点已经存在
        p = root;
        return true;
    }
    else if(data < root->data)
    {
        //这里都第三个参数不是f 而是 root 表示都是没有data = =->value,会返回最后找到的那个左子树或者右子树为空的节点
        return searhBST(root->lch, data, root, p);
    }
    else
    {
        return searhBST(root->rch, data, root, p);
    }
}
 
void InsertBST(BiTree &root , int key)
{
 
    BiTree p, newp;
    if(!searhBST(root, key, NULL, p))
    {
        // 当前节点 已经存在的话就不用 新建一个节点
        newp = (BiTree)malloc(sizeof(BiNode));
        newp->data = key;
        newp->lch = NULL;
        newp->rch = NULL;
 
        if(!p)
        {
            //当前树空才会返回p是NULL
            root = newp;
        }
        else if(key < p->data)
        {
            p->lch = newp;
        }
        else
        {
            p->rch = newp;
        }
    }
}
void  preOrder(BiTree root)
{
    if(root)
    {
        cout<<root->data<<" ";
        preOrder(root->lch);
        preOrder(root->rch);
    }
}
void postOrder(BiTree root)
{
    if(root)
    {
        postOrder(root->lch);
        postOrder(root->rch);
        cout<<root->data<<" ";
    }
}
void inOrder(BiTree root)
{
    if(root)
    {
        inOrder(root->lch);
        cout<<root->data<<" ";
        inOrder(root->rch);
    }
 
 
}
int main()
{
 
    int n ;
    cout << "请输入元素个数" << endl;
    while(cin>>n)
    {
        BiTree root = NULL;
        for(int i = 0; i < n; i++)
        {
            int num;
            cin>>num;
            InsertBST(root, num);
        }
        preOrder(root);
        cout<<endl;
        inOrder(root);
        cout<<endl;
        postOrder(root);
        cout<<endl;
    }
 
}

