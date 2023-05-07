/*
이름:김태정
학번:202210423
프로그램 명:최근접.c
프로그램 날짜:2023.5.07(일)
프로그램 설명: 최근접점쌍 찾기 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 구조체 정의: 포인트를 나타내는 구조체
typedef struct {
    int x;
    int y;
} Point;

// 두 포인트 사이의 거리를 계산하는 함수
double distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// 최근접 쌍을 찾는 함수
void findClosestPairs(Point* points, FILE* outputFile) {
    double minDistance = -1; // 최소 거리 변수 초기화
    int index1 = -1, index2 = -1; // 최근접 쌍의 인덱스 변수 초기화

    // 모든 가능한 쌍에 대해 거리 계산
    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 8; j++) {
            double d = distance(points[i], points[j]);
            if (minDistance == -1 || d < minDistance) {
                minDistance = d;
                index1 = i;
                index2 = j;
            }
        }
    }

    // 결과 출력
    fprintf(outputFile, "최근접 쌍: (%d, %d)와 (%d, %d)\n", points[index1].x, points[index1].y, points[index2].x, points[index2].y);
    fprintf(outputFile, "최소 거리: %lf\n", minDistance);
}

int main() {
    FILE* inputFile = fopen("data.txt", "r");
    FILE* outputFile = fopen("result.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    Point points[8]; // 8개의 포인트를 저장할 배열

    // 포인트 데이터 읽기
    for (int i = 0; i < 8; i++) {
        fscanf(inputFile, "%d %d", &points[i].x, &points[i].y);
    }

    findClosestPairs(points, outputFile); // 최근접 쌍 찾기

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
