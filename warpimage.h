// --------------------------------------------------------------------------------
// WarpImage
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/02/2018
// initial commit.
// --------------------------------------------------------------------------------

#ifndef WARPIMAGE_H
#define WARPIMAGE_H

#include <QWidget>
#include <QLabel>

// --------------------------------------------------------------
// ControlPanel Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors---------------------
// Default Constructor
// ----------Accessor Functions---------------------
// ----------Mutator Functions----------------------
// ----------File IO Functions-----------------------
// --------------------------------------------------------------

class WarpImage: public QWidget
{
private:
   // image
   QLabel      *labelimage;
   QPixmap     *piximage;
   QImage      *image;

public:

   // Default Constructor
   WarpImage(QWidget *parent = nullptr);

public slots:

   // test slot
   void test_slot(int value);
};

#endif // WARPIMAGE_H










