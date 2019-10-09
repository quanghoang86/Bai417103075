#include "pch.h"
#include "Tamgiac.h"
Tamgiac::Tamgiac()
{
}
Tamgiac::Tamgiac(CPoint p1, CPoint p2)
{
	point1.x = p1.x;
	point1.y = p1.y;
	point2.x = p2.x;
	point2.y = p2.y;
	x1 = (p1.x + p2.x) / 2;
	y1 = p1.y;
	x2 = p1.x;
	y2 = p2.y;
	x3 = p2.x;
	y3 = p2.y;

}
Tamgiac::Tamgiac(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1;
	x2 = mx2;
	x3 = mx3;
	y1 = my1;
	y2 = my2;
	y3 = my3;
}
void Tamgiac::thietlap(int mx1, int my1, int mx2, int my2, int mx3, int my3)
{
	x1 = mx1;
	x2 = mx2;
	x3 = mx3;
	y1 = my1;
	y2 = my2;
	y3 = my3;
}
CPoint Tamgiac::getA()
{
	return CPoint(x1, y1);
}
CPoint Tamgiac::getB()
{
	return CPoint(x2, y2);
}
CPoint Tamgiac::getC()
{
	return CPoint(x3, y3);
}
void Tamgiac::draw(CClientDC* pdc)
{


	pdc->MoveTo(x1, y1);
	pdc->LineTo(x2, y2);
	pdc->LineTo(x3, y3);
	pdc->LineTo(x1, y1);
	CString str, cv, a, s;
	a = "Dien tich: ";
	pdc->TextOutW(800, 20, a);
	str.Format(_T("%f"), dientich());
	pdc->TextOutW(880, 20, str);
	a = "Chu vi: ";
	pdc->TextOutW(800, 55, a);
	cv.Format(_T("%f"), chuvi());
	pdc->TextOutW(880, 55, cv);
}
float Tamgiac::dientich()
{
	float s = 0;
	float p = 0;
	s = (float)((0.5) * abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)));
	return s;
}
float Tamgiac::chuvi()
{
	float kq;
	kq = (sqrt((x2 - x1) * (x2 - x1)) + sqrt((y2 - y1) * (y2 - y1))) + (sqrt((x3 - x2) * (x3 - x2)) + sqrt((y3 - y2) * (y3 - y2))) + (sqrt((x3 - x1) * (x3 - x1)) + sqrt((y3 - y1) * (y3 - y1)));
	return kq;
}

int Tamgiac::tronghinh(CPoint p)
{
	Tamgiac tg1, tg2, tg3;
	tg1.thietlap(x1, y1, x2, y2, p.x, p.y);
	tg2.thietlap(x2, y2, x3, y3, p.x, p.y);
	tg3.thietlap(x3, y3, x1, y1, p.x, p.y);
	int kq = -1;
	if ((tg1.dientich() + tg2.dientich() + tg3.dientich()) == dientich())
		kq = 1;
	return kq;
}


Tamgiac::~Tamgiac()
{
}
