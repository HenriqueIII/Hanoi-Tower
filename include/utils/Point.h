#ifndef POINT_H
#define POINT_H

class Point{
    int x, y;
public:
    Point(int xT, int yT);
    // Definição do construtor sem parâmetros
    Point();
    Point add(const Point & p) const;
    Point & addEqual(const Point & p);
    Point sub (const Point & p) const;
    int getX() const;
    int getY() const;
    bool isEqual(const Point & p) const;
    //Roda 90 graus com centro na origem
    Point & rotateRight();
    void setX(int xT);
    void setY(int yT);
};
#endif