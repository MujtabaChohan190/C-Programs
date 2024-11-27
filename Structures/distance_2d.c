// Define a structure to represent a point in 2D space with x and y coordinates. Implement
// functions to calculate the distance between two points and to check if a point lies within
// a specific rectangular boundary.

#include <stdio.h>
#include <math.h>

typedef struct {
    float x; // X-coordinate
    float y; // Y-coordinate
} Point;

// Function to calculate the distance between two points
float calculateDistance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)); //Sqrt introduces square root while pow squares the value eg : pow( x , 2 ) is x^2
}

// Function to check if a point lies within a rectangular boundary
// Rectangular boundary is defined by bottom-left and top-right corners
int isPointInRectangle(Point point, Point bottomLeft, Point topRight) {
    if (point.x >= bottomLeft.x && point.x <= topRight.x &&
        point.y >= bottomLeft.y && point.y <= topRight.y) {
        return 1; // True, point is within the rectangle
    }
    return 0; // False, point is outside the rectangle
}

int main() {
    
    Point p1 = {2.0, 3.0};
    Point p2 = {5.0, 7.0};

    // Calculate distance between points
    float distance = calculateDistance(p1, p2);
    printf("Distance between points: %.2f\n", distance);

    // Define a rectangle using bottom-left and top-right points
    Point bottomLeft = {1.0, 2.0};
    Point topRight = {6.0, 8.0};

    // Check if a point lies within the rectangle
    if (isPointInRectangle(p1, bottomLeft, topRight)) {
        printf("Point p1 lies within the rectangle.\n");
    } else {
        printf("Point p1 does not lie within the rectangle.\n");
    }

    if (isPointInRectangle(p2, bottomLeft, topRight)) {
        printf("Point p2 lies within the rectangle.\n");
    } else {
        printf("Point p2 does not lie within the rectangle.\n");
    }

    return 0;
}
