// --------------------------------------------------------------------------------
// WarpImage
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/02/2018
// initial commit.
// --------------------------------------------------------------------------------

// supporting libraries
#include <QtMath>

// Class Header
#include "warpimage.h"

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
WarpImage::WarpImage(QObject *parent) : QObject(parent)
{
   // ------ Timer ------------------------------------

   // Image Update Timer
   image_update_timer = new QTimer(this);

   // connect timer to update
   QObject::connect(image_update_timer, QTimer::timeout, this, WarpImage::update_image);

   // start timer
   image_update_timer->start(1);

   // start warp_time
   warp_time   = new QTime();
   warp_time->start();

   // ------ Graphic ------------------------------------

   // pull image
   QImage image;
   image = QImage( base_image_path );

   // scale image
   image = image.scaledToWidth(width);

   // convert ot piximap
   piximage    = new QPixmap();
   piximage->convertFromImage(image);
   *piximage   = piximage->copy(QRect(0,0,width,height));
}

// ------------------------------------------------------------------
//    ##    ####   ####  ######  ####   ####   ####  #####   ####
//   #  #  #    # #    # #      #      #      #    # #    # #
//  #    # #      #      #####   ####   ####  #    # #    #  ####
//  ###### #      #      #           #      # #    # #####       #
//  #    # #    # #    # #      #    # #    # #    # #   #  #    #
//  #    #  ####   ####  ######  ####   ####   ####  #    #  ####
// ------------------------------------------------------------------

// get_pixmap
QPixmap* WarpImage::get_pixmap()
{
   return piximage;
}

// ------------------------------------------------------------------
//  #    # #    # #####   ##   #####  ####  #####   ####
//  ##  ## #    #   #    #  #    #   #    # #    # #
//  # ## # #    #   #   #    #   #   #    # #    #  ####
//  #    # #    #   #   ######   #   #    # #####       #
//  #    # #    #   #   #    #   #   #    # #   #  #    #
//  #    #  ####    #   #    #   #    ####  #    #  ####
// ------------------------------------------------------------------

// set_max_rel_width
void WarpImage::set_max_rel_width(double m_rel_w)
{
   max_relative_width   = m_rel_w;
}

// set_max_rel_height
void WarpImage::set_max_rel_height(double m_rel_h)
{
   max_relative_height   = m_rel_h;
}

// set_qtime
void WarpImage::set_qtime(QTime *time)
{
   warp_time   = time;
}

// effect_tunnel
void WarpImage::effect_tunnel(double increment)
{
   int rect_width    = increment*width*max_relative_width;
   int rect_height   = increment*height*max_relative_height;

   // calc left border based on width for centering
   //int left_border   = (width - rect_width)/2;
   int left_border   = 100; //width/8 - max_relative_height/2;
   //int top_border    = (height - rect_height)/2;
   int top_border    = 50; //height/4 - max_relative_height/2; ;

   // reset painter
   painter = new QPainter();

   // start painting
   painter->begin(piximage);

   // draw pixmap
   painter->drawPixmap( QRect(left_border,top_border,rect_width,rect_height), *piximage, QRect(0,0,width,height));

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
   effect_tunnel(abs(qSin(warp_time->elapsed()/4000.0)));

   // emit signal
   emit graphic_changed(piximage);

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


