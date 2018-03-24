// --------------------------------------------------------------------------------
// WarpImage
//
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

// supporting libraries
#include <QtMath>

// Class Header
#include "warpimage.h"

// supported libs
//#include "functiontimesin.h"

// std
#include <iostream>
using namespace std;

// --------------------------------------------------------------------------------
//   ####   ####  #    #  ####  ##### #####  #    #  ####  #####  ####  #####   ####
//  #    # #    # ##   # #        #   #    # #    # #    #   #   #    # #    # #
//  #      #    # # #  #  ####    #   #    # #    # #        #   #    # #    #  ####
//  #      #    # #  # #      #   #   #####  #    # #        #   #    # #####       #
//  #    # #    # #   ## #    #   #   #   #  #    # #    #   #   #    # #   #  #    #
//   ####   ####  #    #  ####    #   #    #  ####   ####    #    ####  #    #  ####
// --------------------------------------------------------------------------------

// Default Constructor
WarpImage::WarpImage(const QString &image_path_, const QSize &imsize_, QObject *parent) :
   input_image_path(image_path_),
   imsize(imsize_),
   QObject(parent)
{
   // ------ Timer ------------------------------------

   // Image Update Timer
   image_update_timer = new QTimer(this);

   // connect timer to update
   QObject::connect(image_update_timer, QTimer::timeout, this, WarpImage::update_image);

   // start timer
   image_update_timer->start(5);

   // ------ Path to Scaled Pixmap  ------------------------------------

   // pull image
   QImage image;
   image = QImage( input_image_path );

   // scale image
   image = image.scaledToWidth(imsize.rwidth());

   // convert to piximap
   //pixmap_scaled    = new QPixmap();
   //pixmap_scaled->convertFromImage(image);
   //*pixmap_scaled   = pixmap_scaled->copy(QRect(0,0,imsize.rwidth(), imsize.rheight()));

   // ------ Initialize Warped Pixmap  ------------------------------------

   //pixmap_warped  = new QPixmap(*pixmap_scaled);
}

// ------------------------------------------------------------------
//    ##    ####   ####  ######  ####   ####   ####  #####   ####
//   #  #  #    # #    # #      #      #      #    # #    # #
//  #    # #      #      #####   ####   ####  #    # #    #  ####
//  ###### #      #      #           #      # #    # #####       #
//  #    # #    # #    # #      #    # #    # #    # #   #  #    #
//  #    #  ####   ####  ######  ####   ####   ####  #    #  ####
// ------------------------------------------------------------------

// get_warped_pixmap
QPixmap* WarpImage::get_warped_pixmap()
{
   return pixmap_warped;
}

// ------------------------------------------------------------------
//  #    # #    # #####   ##   #####  ####  #####   ####
//  ##  ## #    #   #    #  #    #   #    # #    # #
//  # ## # #    #   #   #    #   #   #    # #    #  ####
//  #    # #    #   #   ######   #   #    # #####       #
//  #    # #    #   #   #    #   #   #    # #   #  #    #
//  #    #  ####    #   #    #   #    ####  #    #  ####
// ------------------------------------------------------------------

// set_vert_bord1
void WarpImage::set_vert_bord1(AbstractFunction *func)
{
   vert_rel_bord1    = func;
}

// set_vert_bord2
void WarpImage::set_vert_bord2(AbstractFunction *func)
{
   vert_rel_bord2    = func;
}

// set_horz_bord1
void WarpImage::set_horz_bord1(AbstractFunction *func)
{
   horz_rel_bord1    = func;
}

// set_horz_bord2
void WarpImage::set_horz_bord2(AbstractFunction *func)
{
   horz_rel_bord2    = func;
}

// effect_warp
void WarpImage::effect_warp()
{

   // calculate rectangle
   //    defined in Rect by starting location and size

   // define borders in terms of border1 and border2
   int horz_bord1   = horz_rel_bord1->f()*imsize.rheight();
   int horz_bord2   = horz_rel_bord2->f()*imsize.rheight();
   int vert_bord1   = vert_rel_bord1->f()*imsize.rwidth();
   int vert_bord2   = vert_rel_bord2->f()*imsize.rwidth();

   // find width and height of rect
   int rect_height   = qAbs(horz_bord1 - horz_bord2);
   int rect_width    = qAbs(vert_bord1 - vert_bord2);

   // determine starting point for rect
   int rect_x0       = min(vert_bord1, vert_bord2);
   int rect_y0       = min(horz_bord1, horz_bord2);

   // ----- Initialize Painter

   // reset painter
   painter = new QPainter();

   // start painting
   painter->begin(pixmap_warped);

   // draw pixmap
   painter->drawPixmap( QRect(rect_x0,rect_y0,rect_width,rect_height), *pixmap_scaled,
                        QRect(0,0,imsize.rwidth(),imsize.rheight()));

   // end painting
   painter->end();

}

// ---------------------------------------------------------------------
//  ####  #       ####  #####  ####
// #      #      #    #   #   #
//  ####  #      #    #   #    ####
//      # #      #    #   #        #
// #    # #      #    #   #   #    #
//  ####  ######  ####    #    ####
// ---------------------------------------------------------------------

// update_image
void WarpImage::update_image()
{
   // modify pixmap with painter
   effect_warp();
}






// increment color
/*
void WarpImage::increment_color(int increment)
{

   // declare vars for later
   QColor   pixcolor;
   uchar    *pixchar;
   QRgb     *rowdata;
   QRgb     pixrgb;
   int      hue;

   // get image data
   int w    = image->width();
   int h    = image->height();
   int np   = w*h;

   int pi = 0;

   // loop through each pixel
   for(int hi = 0; hi < h; hi++)
   {
      // pull row data
      rowdata = (QRgb*)(image->scanLine(hi));

      for(int wi = 0; wi < w; wi++)
      {

         pi++;

         // pull QRgb
         pixrgb = rowdata[wi];

         // Convert to QColor
         pixcolor    = QColor(pixrgb);

         // increment hue
         hue = pixcolor.hue();

         // mod hue
         pixcolor.setHsv( (hue + increment)%255, pixcolor.hsvSaturation(), pixcolor.value() );

         // push back into row
         rowdata[wi] = pixcolor.rgb();
      }
   }
}
*/


