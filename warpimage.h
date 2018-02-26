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
#include <QPainter>
#include <QTimer>
#include <QTime>

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
   Q_OBJECT

private:
   // image
   QLabel      *labelimage;
   QPixmap     *piximage;
   QImage      *image;

   // paint device
   QPainter    *painter;

   // timer & time
   QTimer      *timer;
   QTime       time;

public:

   // Default Constructor
   WarpImage(QWidget *parent = nullptr);

   // increment color
   void increment_color(int increment);

   // tunnel effect
   void effect_tunnel(int value);

   // test paint
   void test_paint(int value);

   // ----------Signals--------------------------------

signals:

   // graphic_changed
   void graphic_changed(QPixmap *pixmap);

   // ----------Slots----------------------------------

public slots:

   // test slot
   void update();
};

#endif // WARPIMAGE_H










