#include "Line.h"
#include "utils/Point.h"
#include "Board.h"
#include "utils/DeltaTime.h"

Line::Line() {
    for (int x=0; x < WIDTH; ++x)
        line[x] = NONE;
}

bool Line::isFilled() {
    for (int x = 0; x < WIDTH; ++x)
        if (line[x]==NONE)
            return false;
    return true;
}

void Line::show(int y) {
    for (Point p(0, y); p.getX() < WIDTH; p.setX( p.getX()+1 ))
        if (line[p.getX()] != NONE )
            Board::showBlock( p, line[p.getX()] );
}

void Line::hide(int y) {
    for (Point p(0, y); p.getX() < WIDTH; p.setX( p.getX()+1 ))
        Board::hideBlock( p );
}

void Line::blink(int y) {
    DeltaTime gap( 3.0F / BLINK_DELETE );
    for (int i=0; i < BLINK_DELETE; ++i) {
        gap.start();
        if ( i % 2 )
            show(y);
        else
            hide(y);
        gap.wait();
    }
}