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
   QObject::connect(image_update_timer, QTimer::timeout, this, WarpImage::update);

   // start timer
   image_update_timer->start(1);

   // start time
   time.start();


   // ------ Image ------------------------------------

   // Size
   //resize(QSize(500,250));

   // pull image
   image = new QImage(QString("C:\\Users\\Aidan\\Desktop\\krug.jpg"));

   // scale image
   *image = image->scaledToWidth(1000);

   // convert ot piximap
   piximage    = new QPixmap();
   piximage->convertFromImage(*image);
   *piximage   = piximage->copy(QRect(0,0,1000,500));

   // add pixmap to label
   //labelimage  = new QLabel(this);
   //labelimage->setPixmap(piximage->scaledToWidth(1000));
}



// test slot
void WarpImage::update()
{

   // modify image
   //image->invertPixels();
   //increment_color();

   // modify pixmap with painter
   effect_tunnel(abs(qSin(time.elapsed()/2000.0)*80));

   // update pixmap and label
   //piximage->convertFromImage(*image);
   //labelimage->setPixmap(*piximage);

   // emit signal
   emit graphic_changed(piximage);

}

// effect_tunnel
void WarpImage::effect_tunnel(int increment)
{
   int imwidth = 1000;
   int imheight = 500;

   // image properties
   int w1 = increment*imwidth/100;
   int h1 = increment*imheight/100;
   int w0 = (imwidth - w1)/2;
   int h0 = (imheight - h1)/2;

   w0 = 0;
   h0 = 0;

   // reset painter
   painter = new QPainter();

   // start painting
   painter->begin(piximage);


   // draw pixmap
   painter->drawPixmap( QRect(w0,h0,w1,h1), *piximage, QRect(0,0,1000,500));

   // end painting
   painter->end();

}

// get_pixmap
QPixmap* WarpImage::get_pixmap()
{
   return piximage;
}










// increment color
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

// test_paint
void WarpImage::test_paint(int value)
{
   painter = new QPainter();

   painter->begin(piximage);
   painter->drawEllipse(0,0,10*value,100);
   painter->end();
}




