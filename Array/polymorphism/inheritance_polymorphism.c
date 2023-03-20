#include <stdio.h>
#include <stdlib.h>

// Base class
typedef struct {
    void (*draw)(void*);
    void (*move)(void*, int, int);
} Shape;

// Derived class
typedef struct {
    Shape shape; // Inherits from Shape
    int x;
    int y;
} Point;

// Derived class
typedef struct {
    Shape shape; // Inherits from Shape
    Point origin;
    int radius;
} Circle;

// Virtual function to draw a Shape
void drawShape(void* shape) {
    Shape* s = (Shape*)shape;
    printf("Drawing shape...\n");
    s->draw(shape);
}

// Virtual function to draw a Point
void drawPoint(void* point) {
    Point* p = (Point*)point;
    printf("Drawing point at x=%d, y=%d\n", p->x, p->y);
}

// Virtual function to move a Shape
void moveShape(void* shape, int dx, int dy) {
    Shape* s = (Shape*)shape;
    printf("Moving shape...\n");
    s->move(shape, dx, dy);
}

// Virtual function to move a Point
void movePoint(void* point, int dx, int dy) {
    Point* p = (Point*)point;
    p->x += dx;
    p->y += dy;
    printf("Moving point to x=%d, y=%d\n", p->x, p->y);
}

// Virtual function to draw a Circle
void drawCircle(void* circle) {
    Circle* c = (Circle*)circle;
    printf("Drawing circle with origin=(");
    c->origin.shape.draw(&c->origin);
    printf(") and radius=%d\n", c->radius);
}

// Virtual function to move a Circle
void moveCircle(void* circle, int dx, int dy) {
    Circle* c = (Circle*)circle;
    c->origin.shape.move(&c->origin, dx, dy);
    printf("Moving circle to origin=(");
    c->origin.shape.draw(&c->origin);
    printf(")\n");
}

int main() {
    // Create a Circle object
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->origin.shape.draw = &drawPoint;
    circle->origin.shape.move = &movePoint;
    circle->origin.x = 10;
    circle->origin.y = 20;
    circle->radius = 5;
    circle->shape.draw = &drawCircle;
    circle->shape.move = &moveCircle;
    
    // Call the virtual functions for the Circle
    circle->shape.draw(circle);
    circle->shape.move(circle, 5, -5);
    
    // Free the memory
    free(circle);
    
    return 0;
}
