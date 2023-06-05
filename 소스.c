#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void pick(int n, int bucket[], int bucketSize, int toPick, int numbers[], int index, int result[]);

int main(void)
{
	int numbers[3] = { 3, 2, 1 };
	int t;
	int* testcase;
	int* bucket;
	int* result;
	int i;

	scanf("%d", &t);
	testcase = (int*)malloc(sizeof(int) * t);
	result = (int*)malloc(sizeof(int) * t);

	for (i = 0; i < t; i++) {
		scanf("%d", &testcase[i]);
		result[i] = 0;
	}

	for (i = 0; i < t; i++) {
		bucket = (int*)malloc(sizeof(int) * testcase[i]);
		pick(3, bucket, testcase[i], testcase[i], numbers, i, result);
		printf("%d\n", result[i]);
		free(bucket);
	}

	free(testcase);;
	free(result);

	return 0;
}

void pick(int n, int bucket[], int bucketSize, int toPick, int numbers[], int index, int result[]) {
	int lastIndex, smallest, i;

	lastIndex = bucketSize - toPick - 1;

	int sum = 0;
	for (i = 0; i <= lastIndex; i++) {
		sum += numbers[bucket[i]];
	}
	if (sum > bucketSize) {
		return;
	}
	else if (sum == bucketSize) {
		result[index]++;
	}
	if (toPick == 0) {
		return;
	}

	for (i = 0; i < n; i++) {
		bucket[lastIndex + 1] = i;
		pick(n, bucket, bucketSize, toPick - 1, numbers, index, result);
	}
}