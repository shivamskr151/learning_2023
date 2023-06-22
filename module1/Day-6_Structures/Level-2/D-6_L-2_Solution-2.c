#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float calculateDistance(struct Point p1, struct Point p2) {
    float distance;
    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

int main() {
    struct Point point1, point2;

   
    printf("Enter the coordinates of the first point:\n");
    printf("x1: ");
    scanf("%f", &point1.x);
    printf("y1: ");
    scanf("%f", &point1.y);

    printf("Enter the coordinates of the second point:\n");
    printf("x2: ");
    scanf("%f", &point2.x);
    printf("y2: ");
    scanf("%f", &point2.y);

    float distance = calculateDistance(point1, point2);

    printf("The distance between the points (%.2f, %.2f) and (%.2f, %.2f) is %.2f\n",
           point1.x, point1.y, point2.x, point2.y, distance);

    return 0;
}