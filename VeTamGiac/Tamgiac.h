#pragma once
#include <math.h>
#include "VeHinh.h"
class Tamgiac : public VeHinh
{
private:
	int x1, y1, x2, y2, x3, y3;
public:
	Tamgiac(CPoint p1, CPoint p2);
	Tamgiac(int mx1, int my1, int mx2, int my2, int mx3, int my3);
	void thietlap(int mx1, int my1, int mx2, int my2, int mx3, int my3);
	int tronghinh(CPoint p);
	CPoint getA();
	CPoint getB();
	CPoint getC();
	float dientich();
	float chuvi();


	void draw(CClientDC* pdc);
	Tamgiac();
	~Tamgiac();
};

