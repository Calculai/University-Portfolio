#include "circle.h"
#include "point.h"


void five_circles(circle c[]) {
    for (int i = 0; i < 5; i++)
    {
        c[i].p.x = i;
        c[i].p.y = i;
        c[i].r = i;
    }
    
}

bool circle_is_valid(const circle *c) {
    
    if (c->r > 0)
    {
        return true;
    }
    
    return false;
}

void translate(circle *c, const point *p) {
    c->p.x = c->p.x + p->x;
    c->p.y = c->p.y + p->y;
}