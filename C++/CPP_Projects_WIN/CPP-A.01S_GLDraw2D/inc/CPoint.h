#ifndef CPOINT_H
#define CPOINT_H

#include <string>

#include "Figure.h"

using namespace std;

class CPoint : virtual public CFigure
{
	friend class CLine;
	friend class CRectangle;
	friend class CCircle;

private:
	float x, y;
		
public:
	static int listCount();
	static unsigned long ulCount;

	CPoint();
	CPoint(float x, float y);
	CPoint(const CPoint& point);
	CPoint operator+(CPoint point);
	CPoint operator-(CPoint point);
	~CPoint();

	void set(float x, float y);
	string list() override;
	void draw() override;
	void load(std::istream*)override;
	void save(std::ostream*)override;
};

#endif //CPOINT_H