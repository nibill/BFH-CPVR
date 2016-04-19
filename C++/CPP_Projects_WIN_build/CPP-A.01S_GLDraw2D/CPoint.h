#ifndef CPOINT_H
#define CPOINT_H

class CPoint
{

private:
	float x, y;
	static unsigned long ulCount;
	
public:
	CPoint();
	CPoint(float x, float y);
	CPoint(const CPoint& point);
	~CPoint();

	void set(float x, float y);
	void list();
	static int listCount();

};

#endif //CPOINT_H