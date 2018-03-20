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
#include <functionscalar.h>

class QPixmap;
class QSize;

// --------------------------------------------------------------
// WarpImage Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors------------------------------
// Default Constructor
// ----------Accessors------------------------------
// get_pixmap
// ----------Setters--------------------------------
// set_vert_bord1
// set_vert_bord2
// set_horz_bord1
// set_horz_bord2
// effect_warp
// ----------Slots----------------------------------
// update_image
// --------------------------------------------------------------

class WarpImage: public QObject
{
   Q_OBJECT

protected:

   // Size
   QSize       imsize;

   // input image path
   QString     input_image_path;

   // original scaled image pixmap
   QPixmap     *pixmap_scaled;

   // manipulated image
   QPixmap     *pixmap_warped;

   // paint device
   QPainter    *painter;

   // update timer
   QTimer      *image_update_timer;

   // borders
   //    relative to width and height
   AbstractFunction *vert_rel_bord1   = new FunctionScalar(0);
   AbstractFunction *vert_rel_bord2   = new FunctionScalar(1);
   AbstractFunction *horz_rel_bord1   = new FunctionScalar(0);
   AbstractFunction *horz_rel_bord2   = new FunctionScalar(1);

public:

   // ----------Constructors------------------------------

   // Default Constructor
   WarpImage(const QString &image_path_, const QSize &imsize_, QObject *parent = nullptr);

   // ----------Accessors--------------------------------

   // get_warped_pixmap
   QPixmap* get_warped_pixmap();

   // ----------Setters--------------------------------

   // set_vert_bord1
   void set_vert_bord1(AbstractFunction *func);

   // set_vert_bord2
   void set_vert_bord2(AbstractFunction *func);

   // set_horz_bord1
   void set_horz_bord1(AbstractFunction *func);

   // set_horz_bord2
   void set_horz_bord2(AbstractFunction *func);

   // effect_warp
   void effect_warp();

   // ----------Signals--------------------------------

signals:

   // ----------Slots----------------------------------

public slots:

   // update_image
   void update_image();
};

#endif // WARPIMAGE_H











































//





