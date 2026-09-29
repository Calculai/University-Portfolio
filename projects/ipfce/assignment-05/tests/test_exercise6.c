#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "circle.h"

int main() {
    // Test 1: five_circles function
    circle c[5];
    five_circles(c);
    for (int i = 0; i < 5; i++) {
        assert(c[i].p.x == i);
        assert(c[i].p.y == i);
        assert(c[i].r == i);
    }

    // Test 2: circle_is_valid
    circle valid_circle = {{0, 0}, 5};
    circle invalid_circle = {{1, 2}, 0};
    circle invalid_circle2 = {{3, 4}, -1};
    assert(circle_is_valid(&valid_circle) == true);
    assert(circle_is_valid(&invalid_circle) == false);
    assert(circle_is_valid(&invalid_circle2) == false);

    // Test 3: translate
    circle c1 = {{5, 10}, 3};
    point p1 = {1, -1};
    translate(&c1, &p1);
    assert(c1.p.x == 6 && c1.p.y == 9 && c1.r == 3);

    circle c2 = {{0, 0}, 1};
    point p2 = {-2, 3};
    translate(&c2, &p2);
    assert(c2.p.x == -2 && c2.p.y == 3 && c2.r == 1);

    circle c3 = {{-1, -1}, 4};
    point p3 = {0, 0};
    translate(&c3, &p3);
    assert(c3.p.x == -1 && c3.p.y == -1 && c3.r == 4);

    printf("Exercise 6 tests passed\n");
    return 0;
}
