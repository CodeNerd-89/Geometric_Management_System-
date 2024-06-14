#include <iostream>
#include <stdlib.h>

#define MAX_SHAPES 100

typedef enum shape_type {
    CIRCLE,
    RECTANGLE
} shape_type;

typedef struct rectangle {
    float height;
    float width;
} rectangle;

typedef struct shape {
    int id;
    shape_type type;
    union {
        float diameter;
        rectangle rect;
    };
} shape;

shape warehouse[MAX_SHAPES];
int num_shapes = 0;
float total_area = 0.0;
float total_area_rectangles = 0.0;
float total_area_circles = 0.0;
int num_rectangles = 0;
int num_circles = 0;

void add_circle() {
    printf("What is the diameter of the circle: ");
    float diameter;
    scanf("%f", &diameter);
    warehouse[num_shapes].id = num_shapes + 1;
    warehouse[num_shapes].type = CIRCLE;
    warehouse[num_shapes].diameter = diameter;
    float area = 3.14159 * diameter * diameter / 4;
    total_area += area;
    total_area_circles += area;
    num_circles++;
    num_shapes++;
}

void add_rectangle() {
    printf("What is the height of the rectangle: ");
    float height;
    scanf("%f", &height);

    printf("What is the width of the rectangle: ");
    float width;
    scanf("%f", &width);
    warehouse[num_shapes].id = num_shapes + 1;
    warehouse[num_shapes].type = RECTANGLE;
    warehouse[num_shapes].rect.height = height;
    warehouse[num_shapes].rect.width = width;
    float area = height * width;
    total_area += area;
    total_area_rectangles += area;
    num_rectangles++;
    num_shapes++;
}

void list_items() {
    printf("Id\tType\t\tDimensions\n");
    printf("===================================\n");
    for (int i = 0; i < num_shapes; i++) {
        printf("%d\t", warehouse[i].id);

        switch (warehouse[i].type) {
            case CIRCLE:
                printf("Circle\t\t%.2f\n", warehouse[i].diameter);
                break;
            case RECTANGLE:
                printf("Rectangle\t%.2f x %.2f\n", warehouse[i].rect.height, warehouse[i].rect.width);
                break;
        }
    }
}

void get_statistics() {
    printf("Total shapes: %d\n", num_shapes);
    printf("Total number of rectangles: %d\n", num_rectangles);
    printf("Total number of circles: %d\n", num_circles);
    printf("Total area: %.2f\n", total_area);
    printf("The total area occupied by rectangles: %.2f (%.2f%%)\n", total_area_rectangles, total_area_rectangles / total_area * 100);
    printf("The total area occupied by circles: %.2f (%.2f%%)\n", total_area_circles, total_area_circles / total_area * 100);
}

void exit_program() {
    exit(0);
}

int main() {
    printf("1. Add a circle\n");
    printf("2. Add a rectangle\n");
    printf("3. List items\n");
    printf("4. Get statistics\n");
    printf("5. Exit\n");

    int choice;
    scanf("%d", &choice);

    while (choice != 5) {
        switch (choice) {
            case 1:
                add_circle();
                break;
            case 2:
                add_rectangle();
                break;
            case 3:
                list_items();
                break;
            case 4:
                get_statistics();
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("1. Add a circle\n");
        printf("2. Add a rectangle\n");
        printf("3. List items\n");
        printf("4. Get statistics\n");
        printf("5. Exit\n");

        scanf("%d", &choice);
    }

    exit_program();
    return 0;
}
