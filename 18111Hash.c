#include <stdio.h>#include <stdlib.h>void swap(int *heap, int i1, int i2){	int temp = heap[i1];	heap[i1] = heap[i2];	heap[i2] = temp;}void bubbleUp(int *timeInArea, int index){	while (1) {		if (index == 1) break;		if (timeInArea[(int)index/2] > timeInArea[index]) {			swap(timeInArea, (int)index/2, index);			index = (int)index/2;		} else break;	}}int main(){	int N, M, B, num, time, testB, minTime;	scanf("%d %d %d", &N, &M, &B);	int *height = (int *)malloc(sizeof(int) * (N * M + 1));	for (int i = 1; i <= N*M; i++) {		scanf("%d", &num);		height[i] = num;	}	int *timeInArea = (int *)malloc(sizeof(int) * (N * M + 1));	int *hashtableOfHeight = (int *)malloc(sizeof(int) * N * M * 514);	// 모든 height 를 돌아가며 각각 걸리는 시간을 계산, 배열에 저장.	for (int i = 1; i <= N*M; i++) {		testB = B;		time = 0;		for (int j = 1; j <= N*M; j++) {			if (height[i] == height[j]) time+=0;			// area에 블록을 추가. 인벤토리에서 블록을 제거. 			else if (height[i] > height[j]) {				time += (height[i] - height[j]);				testB--;			}			else { // area에서 블록을 제거. 인벤토리에 블록을 추가. 				time += (height[j] - height[i]) * 2; 				testB++;			}		}		if (testB < 0) {			// time 은 절대 513이 될 수 없다. 땅의 높이는 256을 초과할 수 없기 때문에.			// -> 이건 한 블록에 대한 얘기지. 전체 블록에 대한 것은 어마어마하게 큰 숫자이지. 			time = 513; 		}				timeInArea[i] = time; 		bubbleUp(timeInArea, i);		if (height[i] > hashtableOfHeight[time]) hashtableOfHeight[time] = height[i]; 	}	minTime = timeInArea[1];	printf("%d %d\n", minTime, hashtableOfHeight[minTime]);	free(height);	free(timeInArea);	free(hashtableOfHeight);	return 0;}