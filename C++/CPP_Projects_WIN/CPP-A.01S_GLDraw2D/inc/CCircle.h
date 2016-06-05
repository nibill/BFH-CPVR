#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CPoint.h"

#include "Figure.h"

class CCircle : public CFigure
{
private:
	CPoint cent;
	float rad;
	static unsigned long ulCount;

public:
	CCircle();
	CCircle(CPoint cent, float rad);
	CCircle(CPoint p1, CPoint p2);
	CCircle(float x, float y, float r);
	CCircle(const CCircle& circle);
	CCircle operator+(CCircle circ);

	~CCircle();

	void set(CPoint cent, float rad);
	void set(float x, float y, float r);
	string list();
	void draw();
	virtual void load(std::istream*) override;
	virtual void save(std::ostream*) override;
	static int listCount();
};
#endif //CCIRCLE_H
