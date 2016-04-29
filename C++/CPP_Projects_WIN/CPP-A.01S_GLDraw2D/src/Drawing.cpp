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
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

// application includes ///////////////////////////////////////////////////////
#include "../../_COMMON/inc/UtilFLTK.h"
#include "../inc/Drawing.h"
#include "../inc/CPoint.h"
#include "../inc/CLine.h"
#include "../inc/CRectangle.h"
#include "../inc/CCircle.h"

// static data definitions ////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
// function: displayDrawing()
// purpose:  This function is called, if the GLUT window handler decides to
//           draw or redraw the window. This happens for instance if the user
//           draws a new figure or resizes or min/maximizes the window.
///////////////////////////////////////////////////////////////////////////////
void CDrawing::displayDrawing(EViewMode mode)
///////////////////////////////////////////////////////////////////////////////
{
	int height = 768;
	int width = 1024;
	const int arrSize = 40;
	srand((unsigned)time(NULL));
	CPoint pointArr[arrSize];
	CPoint *pointArray = new CPoint[arrSize];

	vector<CPoint*> vecPoint;
	vector<CLine*> vecLine;
	vector<CRectangle*> vecRectangle;
	vector<CCircle*> vecCircle;

	for (int i = 0; i < arrSize; i++)
	{
		pointArr[i].set((float)(rand() % width), (float)(rand() % height));
		pointArray[i].set((float)(rand() % width), (float)(rand() % height));
		vecPoint.push_back(new CPoint((float)(rand() % width), (float)(rand() % height)));

		vecLine.push_back(new CLine(
			CPoint((float)(rand() % width), (float)(rand() % height)), 
			CPoint((float)(rand() % width), (float)(rand() % height))));

		vecRectangle.push_back(new CRectangle(
			CPoint((float)(rand() % width), (float)(rand() % height)), 
			CPoint((float)(rand() % width), (float)(rand() % height))));

		vecCircle.push_back(new CCircle(CPoint((float)(rand() % width), (float)(rand() % height)), 
			(float)(rand() % 100)));

	}

	// check for viewing mode
	if (mode == VIEW_DRAWING)
	{
		for (int i = 0; i < arrSize; i++)
		{
			pointArr[i].draw();
			pointArray[i].draw();
		}

		for (unsigned int i = 0; i < arrSize; i++)
		{
			vecPoint[i]->draw();
			vecLine[i]->draw();
			vecRectangle[i]->draw();
			vecCircle[i]->draw();
		}
	}
	else // VIEW_LISTING
	{
		for (int i = 0; i < arrSize; i++)
		{
			cout << pointArr[i].list() << endl;
			cout << pointArray[i].list() << endl;
		}

		for (unsigned int i = 0; i < arrSize; i++)
		{
			cout << vecPoint[i]->list() << endl;
			cout << vecLine[i]->list() << endl;
			cout << vecRectangle[i]->list() << endl;
			cout << vecCircle[i]->list() << endl;
		}
	}

	delete[] pointArray;
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
	// TODO: insert code to clear drawing data
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
	// TODO: add code to append figure to list
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
	// TODO: add code to remove figure from list
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
	// TODO: add drawing file reading code here
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
	// TODO: add drawing file writing code here
}
// CDrawing::saveDrawingFile() ////////////////////////////////////////////////
