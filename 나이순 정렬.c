#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct coordinates {
	int x;
	char y[101];
};

void Merge(struct coordinates* arr, int left, int mid, int right)	//x값 기준 정렬
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	struct coordinates* sortArr = (struct coordinates*)malloc(sizeof(struct coordinates) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx].x <= arr[rIdx].x)
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(struct coordinates* arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		Merge(arr, left, mid, right);
	}
}
int main(void)
{
	struct coordinates* coo;
	int size;
	int i;
	int count = 0, tmp, begin = 0, end = 0;;

	scanf("%d", &size);
	coo = (struct coordinates*)malloc(sizeof(struct coordinates) * size);

	for (i = 0; i < size; i++)
	{
		scanf("%d %s", &coo[i].x, &coo[i].y);
	}

	MergeSort(coo, 0, size - 1);
	for (i = 0; i < size; i++)
	{
		printf("%d %s\n", coo[i].x, coo[i].y);
	}


	return 0;
}