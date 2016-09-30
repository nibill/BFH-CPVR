/*/////////////////////////////////////////////////////////////////////////////
module:  declaration of drawing class
purpose: this class provides the interface to manage the geometric figures
		 of a drawing. This includes functions to display, append, remove
		 and the functionality to save/load figures from a file.

written: U.Kuenzler
version: 1.01
history: 1.00 - initial version of OpenGL drawing application
/////////////////////////////////////////////////////////////////////////////*/



// system includes ////////////////////////////////////////////////////////////
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Drawing.h"
#include "../inc/CPoint.h"
#include "../inc/CLine.h"
#include "../inc/CRectangle.h"
#include "../inc/CCircle.h"

// static data definitions ////////////////////////////////////////////////////
vector<CFigure*> CDrawing::_FigVector;
vector<CFigure*>::iterator pos;


int CDrawing::HEIGTH = 600;
int CDrawing::WIDTH = 800;

void CDrawing::windowSize(int width, int heigth)
{
	CDrawing::WIDTH = width;
	CDrawing::HEIGTH = heigth;
}

///////////////////////////////////////////////////////////////////////////////
// function: displayDrawing()
// purpose:  This function is called, if the GLUT window handler decides to
//           draw or redraw the window. This happens for instance if the user
//           draws a new figure or resizes or min/maximizes the window.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::displayDrawing(EViewMode mode)
///////////////////////////////////////////////////////////////////////////////
{
	//const int arrSize = 40;
	//srand((unsigned)time(NULL));
	//CPoint pointArr[arrSize];
	//CPoint *pointArray = new CPoint[arrSize];

	//vector<CPoint*> vecPoint;
	//vector<CLine*> vecLine;
	//vector<CRectangle*> vecRectangle;
	//vector<CCircle*> vecCircle;

	//for (int i = 0; i < arrSize; i++)
	//{
	//	pointArr[i].set((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH));
	//	pointArray[i].set((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH));
	//	vecPoint.push_back(new CPoint((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH)));

	//	vecLine.push_back(new CLine(
	//		CPoint((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH)),
	//		CPoint((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH))));

	//	vecRectangle.push_back(new CRectangle(
	//		CPoint((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH)),
	//		CPoint((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH))));

	//	vecCircle.push_back(new CCircle(CPoint((float)(rand() % CDrawing::WIDTH), (float)(rand() % CDrawing::HEIGTH)), (float)(rand() % 100)));

	//}

	// check for viewing mode
	if (mode == VIEW_DRAWING)
	{
		//for (int i = 0; i < arrSize; i++)
		//{
		//	pointArr[i].draw();
		//	pointArray[i].draw();
		//}

		//for (unsigned int i = 0; i < arrSize; i++)
		//{
		//	vecPoint[i]->draw();
		//	vecLine[i]->draw();
		//	vecRectangle[i]->draw();
		//	vecCircle[i]->draw();
		//}

		for (pos = _FigVector.begin(); pos != _FigVector.end(); ++pos)
		{
			(*pos)->draw();
		}
	}
	else // VIEW_LISTING
	{
		//for (int i = 0; i < arrSize; i++)
		//{
		//	cout << pointArr[i].list() << endl;
		//	cout << pointArray[i].list() << endl;
		//}

		//for (unsigned int i = 0; i < arrSize; i++)
		//{
		//	cout << vecPoint[i]->list() << endl;
		//	cout << vecLine[i]->list() << endl;
		//	cout << vecRectangle[i]->list() << endl;
		//	cout << vecCircle[i]->list() << endl;
		//	cout << " " << endl;
		//}

		for (vector<CFigure*>::iterator pos = _FigVector.begin(); pos != _FigVector.end(); ++pos)
		{
			cout << (*pos)->list();
		}
	}

	//// dynamische Objekte löschen
	//delete[] pointArray;

	//// Objekte in den Vektoren löschen -> ruft den Destruktor auf
	//for (unsigned int i = 0; i < arrSize; i++)
	//{
	//	delete vecPoint[i];
	//	delete vecLine[i];
	//	delete vecRectangle[i];
	//	delete vecCircle[i];
	//}

	//vecPoint.clear();
	//vecLine.clear();
	//vecRectangle.clear();
	//vecCircle.clear();

	CPoint::listCount();
	CLine::listCount();
	CRectangle::listCount();
	CCircle::listCount();
	cout << endl;
}
// CDrawing::displayDrawing() /////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: clearDrawing()
// purpose:  This function is called, if the user exits the application or
//           if the user clears the window or opens an existing drawing from
//           a file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::clearDrawing(void)
///////////////////////////////////////////////////////////////////////////////
{
	for (vector<CFigure*>::iterator pos = _FigVector.begin(); pos != _FigVector.begin(); ++pos)
	{
		delete *pos;

		// Figure Pointers aus Liste löschen
		_FigVector.clear();
	}
}
// CDrawing::clearDrawing() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: appendFigure()
// purpose:  This function is called, if the user starts drawing a new
//           figure in the window. For lines, rectangles and circles this
//           function is constantly called, until the user stops drawing by
//           releasing the left mouse button.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::appendFigure(EFigType figtype, const CPoint& p1, const CPoint& p2)
///////////////////////////////////////////////////////////////////////////////
{
	CFigure *pNewFig = 0;

	switch (figtype)
	{
	case FIG_POINT:
		pNewFig = new CPoint(p1);
		break;
	case FIG_LINE:
		pNewFig = new CLine(p1, p2);
		break;
	case FIG_RECT:
		pNewFig = new CRectangle(p1, p2);
		break;
	case FIG_CIRCLE:
		pNewFig = new CCircle(p1, p2);
		break;
	}

	_FigVector.push_back(pNewFig);
}
// CDrawing::appendFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: removeFigure()
// purpose:  This function is called, to remove temporary figures while the
//           user is interactively drawing lines, rectangles or circles.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::removeFigure(void)
///////////////////////////////////////////////////////////////////////////////
{
	if (!_FigVector.empty())
	{
		// Figur Objekt löschen
		delete _FigVector.back();

		// Pointer aus Liste löschen
		_FigVector.pop_back();
	}
}
// CDrawing::removeFigure() ///////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: loadDrawingFile()
// purpose:  This function is called, if the user loads a figure drawing
//           file from external storage. The read data will be used to re-
//           instantiate the corresponding figure objects.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::loadDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
	clearDrawing();

	ifstream ifs(filename);
	string line;

	while (getline(ifs, line))
	{
		if (line == ";") continue;

		int code = stoi(line);

		CFigure* fig = nullptr;
		switch (code)
		{
		case FIG_POINT:
			fig = new CPoint();
			break;
		case FIG_LINE:
			fig = new CLine();
			break;
		case FIG_RECT:
			fig = new CRectangle();
			break;
		case FIG_CIRCLE:
			fig = new CCircle();
			break;
		default:
			throw invalid_argument("Code not valid");
		}

		fig->load(&ifs);
		_FigVector.push_back(fig);
	}
}
// CDrawing::loadDrawingFile() ////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////
// function: saveDrawingFile()
// purpose:  This function is called, if the user saves a figure drawing
//           file to external storage. The filename parameter contains the
//           user selected file path of the drawing file.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::saveDrawingFile(const string& filename)
///////////////////////////////////////////////////////////////////////////////
{
	streambuf* buff = cout.rdbuf();
	ofstream ofs(filename);
	cout.rdbuf(ofs.rdbuf());

	for (pos = _FigVector.begin(); pos != _FigVector.end(); ++pos)
	{
		(*pos)->save(&cout);
		cout << ";" << endl;
	}

	cout.rdbuf(buff);
}
// CDrawing::saveDrawingFile() ////////////////////////////////////////////////
