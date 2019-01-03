/************************************************************/
/*                �������ߣ���������                        */
/*                �������ʱ�䣺2019/1/3                    */
/*                ���κ���������ϵ��740531307@qq.com        */
/************************************************************/
//@��Զ�����Ц��ȥ
 
#include<iostream>
#include<stdlib.h>
using namespace std;
 
typedef struct  BiNode
{
    int data;
    struct BiNode *lch, *rch;
} BiNode, *BiTree;
 
/*
 * ����������  ��������ԭ��
 *  1)�� b�ǿ����� ����false
    2)�� �ҵ�  ����true
    3)�ȵ�ǰ�ڵ�С����ô�������� �ҵ� ����Ǹ����ӣ��Һ��Ӷ�Ϊ�յĽڵ�
    4)���ҵ����Ǹ��ڵ���� �Ƚ� �ж��½ڵ���Ҫ���ں����
 */
bool searhBST(BiTree root , int data , BiTree f, BiTree &p)
{
    if(!root)
    {
        // root �Ƕ����������ڵ�
        // f ��Ҫ���ض��ڵ� p ���½��ڵ�
        p = f;
        return false;
    }
    else  if(data == root->data)
    {
        //��ǰ�ڵ��Ѿ�����
        p = root;
        return true;
    }
    else if(data < root->data)
    {
        //���ﶼ��������������f ���� root ��ʾ����û��data = =->value,�᷵������ҵ����Ǹ�����������������Ϊ�յĽڵ�
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
        // ��ǰ�ڵ� �Ѿ����ڵĻ��Ͳ��� �½�һ���ڵ�
        newp = (BiTree)malloc(sizeof(BiNode));
        newp->data = key;
        newp->lch = NULL;
        newp->rch = NULL;
 
        if(!p)
        {
            //��ǰ���ղŻ᷵��p��NULL
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

