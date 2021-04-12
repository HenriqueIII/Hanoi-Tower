#ifndef RECT_H
#define RECT_H

#include "Point.h"

class Rect{
public:
    // Coordenadas do rectangulo
    int left, top, right, bottom;
    // Para definir rectângulos não iniciados
    Rect(){
        /* Corpo Vazio */
    }
    Rect(int l, int t, int r, int b);
    Rect(Point lt, Point rb);
    Rect(Point center, int height, int width);
    // Devolve o ponto central do rectângulo
    Point getCenter();
    // Mostra em Display o rectângulo na cor indicada
    void show(int color) const;
    // Retorna a intercepção entre o próprio e o paramêtro
    Rect intersect(const Rect &r) const;
    // Retorna a Intercepção do próprio com o inverso do param
    Rect intersectNot(const Rect &r) const;
    // Desloca o rectângulo, função do vector indicado
    const Rect & addEqual(Point delta);
};
#endif