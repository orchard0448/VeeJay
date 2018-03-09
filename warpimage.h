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

   // timer & time
   QTimer      *image_update_timer;
   QTime       *warp_time;

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

   // set_qtime
   void set_qtime(QTime *time);

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





