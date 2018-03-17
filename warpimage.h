// --------------------------------------------------------------------------------
// WarpImage
//
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

#ifndef WARPIMAGE_H
#define WARPIMAGE_H

#include <QObject>
#include <QPainter>
#include <QTimer>
#include <QTime>

#include <abstractfunction.h>

class QPixmap;

// --------------------------------------------------------------
// ControlPanel Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors------------------------------
// Default Constructor
// ----------Accessors--------------------------------
// get_pixmap
// ----------Mutators--------------------------------
// set_max_rel_width
// set_max_rel_height
// set_qtime
// tunnel effect
// ----------Signals--------------------------------
// graphic_changed
// ----------Slots----------------------------------
// update_image
// --------------------------------------------------------------

class WarpImage: public QObject
{
   Q_OBJECT

private:

   // Size
   int   height   = 500;
   int   width    = 1000;

   // max warp width and height
   double   max_relative_width    = 0.9;
   double   max_relative_height   = 0.8;

   // image path
   QString     base_image_path   = QString("C:\\Users\\Aidan\\Desktop\\krug.jpg");

   // image
   QPixmap     *piximage;

   // paint device
   QPainter    *painter;

   // update timer
   QTimer      *image_update_timer;

   // warp_scalar
   AbstractFunction  *warp_scalar;

public:

   // ----------Constructors------------------------------

   // Default Constructor
   WarpImage(QObject *parent = nullptr);

   // ----------Accessors--------------------------------

   // get_pixmap
   QPixmap* get_pixmap();

   // ----------Mutators--------------------------------

   // set_max_rel_width
   void set_max_rel_width(double m_rel_w);

   // set_max_rel_height
   void set_max_rel_height(double m_rel_h);

   // tunnel effect
   void effect_tunnel(double value);

   // ----------Signals--------------------------------

signals:

   // graphic_changed
   void graphic_changed(QPixmap *pixmap);

   // ----------Slots----------------------------------

public slots:

   // update_image
   void update_image();
};

#endif // WARPIMAGE_H











































//





