//// Counting Inversions.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include<iostream>
using namespace std;

int merge(int A[], int left, int mid, int right)
{
	int S_I = 0;		//Significant inversions个数
	int *L = new int[mid - left + 1];
	int *R = new int[right - mid];
	int lLen = mid - left + 1;
	int rLen = right - mid;
	for (int i = 0; i < lLen; ++i)
		L[i] = A[left + i];
	for (int i = 0; i < rLen; ++i)
		R[i] = A[mid + 1 + i];
	int i = 0, j = 0, k = left;

	while ((i < lLen) && (j < rLen))
	{
		if (L[i] <= R[j])
		{
			A[k++] = L[i++];
		}
		else
		{
			A[k++] = R[j++];
		}
	}
	while (i < lLen)
	{
		A[k++] = L[i++];
	}
	while (j < rLen)
	{
		A[k++] = R[j++];
	}

	i = j = 0;
	while ((i < lLen) && (j < rLen))
	{
		if (L[i] > (2 * R[j]))
		{
			S_I += ((right - left) / 2 - i + 1);
			++j;
		}
		else ++i;
	}
	delete[] L;
	delete[] R;
	return S_I;
}



int mergeSort(int A[], int left, int right)
{
	int mid;
	int S_IL = 0, S_IR = 0, S_I = 0;
	if (left < right)
	{
		mid = left + (right - left) / 2;
		S_IL = mergeSort(A, left, mid);
		S_IR = mergeSort(A, mid + 1, right);
		S_I = merge(A, left, mid, right);
	}
	return (S_IL + S_IR + S_I);
}

int main()
{
	int len;
	int A[100];
	cout << "请输入序列长度： " << endl;
	while (cin >> len) 
	{
		cout << "请输入序列元素： " << endl;
		for (int i = 0; i < len; ++i)
		{
			cin >> A[i];
		}
		cout <<"Significant inversions个数:" <<  mergeSort(A, 0, len - 1) << endl;
	}
	return 0;
}

//令序列a1, a2, …, an排好序后为b1, b2, …, bn，要求重要逆序对的数目,设计算法如下：
//
//1) Sort - and-Count(L)
//{
//	If n = 1  then 没有逆序对
//	else k = n / 2, 将L分成两个自序列A和B;
//	(N1, A) = Sort - and-Count(A);
//	(N2, B) = Sort - and-Count(B);
//	(N3, L) = Merge - and-Count(A, B);
//	return N = N1 + N2 + N3和排好序的表L
//}
//
//2) Merge - and-Count(A, l, m, r)
//{
//	令A[l…m]为L, A[m + 1…r]为R;
//	i = 1, j = 1, InversionCount = 0;
//	for  k = m  to  r  do
//		if  L[i] > R[j] 
//			then
//			A[k] = L[i]
//			i++；
//		if  L[i] > 2R[j]
//			then       //进行逆序数的统计
//				InversionCount = InversionCount + j - k
//		else
//			A[k] = R[j]
//			j++;
//	end for
//}
//findLocalMinimum(T)
//{
//	if (T的值 < 左右子树根结点的值) || (子树若为空)
//		返回 T的值
//	else if (T的值 > 左子树根结点的值) && (T的值 < 右子树根结点的值)
//		返回 findLocalMinimum(T的右子树)
//	else if (T的值 < 左子树根结点的值) && (T的值 > 右子树根结点的值)
//		返回 findLocalMinimum(T的左子树)
//	else
//		返回 findLocalMinimum(T的左子树或T的右子树)
//		end if
//}
