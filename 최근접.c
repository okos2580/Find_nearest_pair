/*
�̸�:������
�й�:202210423
���α׷� ��:�ֱ���.c
���α׷� ��¥:2023.5.07(��)
���α׷� ����: �ֱ������� ã�� 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ����ü ����: ����Ʈ�� ��Ÿ���� ����ü
typedef struct {
    int x;
    int y;
} Point;

// �� ����Ʈ ������ �Ÿ��� ����ϴ� �Լ�
double distance(Point p1, Point p2) {
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}

// �ֱ��� ���� ã�� �Լ�
void findClosestPairs(Point* points, FILE* outputFile) {
    double minDistance = -1; // �ּ� �Ÿ� ���� �ʱ�ȭ
    int index1 = -1, index2 = -1; // �ֱ��� ���� �ε��� ���� �ʱ�ȭ

    // ��� ������ �ֿ� ���� �Ÿ� ���
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

    // ��� ���
    fprintf(outputFile, "�ֱ��� ��: (%d, %d)�� (%d, %d)\n", points[index1].x, points[index1].y, points[index2].x, points[index2].y);
    fprintf(outputFile, "�ּ� �Ÿ�: %lf\n", minDistance);
}

int main() {
    FILE* inputFile = fopen("data.txt", "r");
    FILE* outputFile = fopen("result.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return 1;
    }

    Point points[8]; // 8���� ����Ʈ�� ������ �迭

    // ����Ʈ ������ �б�
    for (int i = 0; i < 8; i++) {
        fscanf(inputFile, "%d %d", &points[i].x, &points[i].y);
    }

    findClosestPairs(points, outputFile); // �ֱ��� �� ã��

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
