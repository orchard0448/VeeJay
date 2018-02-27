// --------------------------------------------------------------------------------
// WarpImage
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/02/2018
// initial commit.
// --------------------------------------------------------------------------------

#ifndef WARPIMAGE_H
#define WARPIMAGE_H

#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QTime>

class QPixmap;

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

class WarpImage: public QObject
{
   Q_OBJECT

private:
   // image
   QPixmap     *piximage;
   QImage      *image;

   // paint device
   QPainter    *painter;

   // timer & time
   QTimer      *image_update_timer;
   QTime       time;

public:

   // Default Constructor
   WarpImage(QObject *parent = nullptr);

   // tunnel effect
   void effect_tunnel(int value);

   // get_pixmap
   QPixmap* get_pixmap();

   // increment color
   void increment_color(int increment);

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










