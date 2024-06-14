#include <iostream>
#include <cstdlib>

#define MAX_SHAPES 100

typedef enum shape_type {
    CIRCLE,
    RECTANGLE
} shape_type;

int shape_ids[MAX_SHAPES];
shape_type shape_types[MAX_SHAPES];
float diameters[MAX_SHAPES];
float heights[MAX_SHAPES];
float widths[MAX_SHAPES];

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

    shape_ids[num_shapes] = num_shapes + 1;
    shape_types[num_shapes] = CIRCLE;
    diameters[num_shapes] = diameter;

    float area = 3.14159 * diameter * diameter / 4;
    total_area += area;
    total_area_circles += area;
    num_circles++;
    num_shapes++;
}

void add_rectangle() 
{
    printf("What is the height of the rectangle: ");
    float height;
    scanf("%f", &height);

    printf("What is the width of the rectangle: ");
    float width;
    scanf("%f", &width);

    shape_ids[num_shapes] = num_shapes + 1;
    shape_types[num_shapes] = RECTANGLE;
    heights[num_shapes] = height;
    widths[num_shapes] = width;

    float area = height * width;
    total_area += area;
    total_area_rectangles += area;
    num_rectangles++;
    num_shapes++;
}

void list_items() 
{
    printf("Id\tType\t\tDimensions\n");
    printf("===================================\n");
    for (int i = 0; i < num_shapes; i++) {
        printf("%d\t", shape_ids[i]);

        if (shape_types[i] == CIRCLE) {
            printf("Circle\t\t%.2f\n", diameters[i]);
        } else if (shape_types[i] == RECTANGLE) {
            printf("Rectangle\t%.2f x %.2f\n", heights[i], widths[i]);
        }
    }
}

void get_statistics() 
{
    printf("Total shapes: %d\n", num_shapes);
    printf("Total number of rectangles: %d\n", num_rectangles);
    printf("Total number of circles: %d\n", num_circles);
    printf("Total area: %.2f\n", total_area);

    printf("The total area occupied by rectangles: %.2f (%.2f%%)\n",
           total_area_rectangles, total_area_rectangles / total_area * 100);

    printf("The total area occupied by circles: %.2f (%.2f%%)\n",
           total_area_circles, total_area_circles / total_area * 100);
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

    while (choice != 6) {
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
