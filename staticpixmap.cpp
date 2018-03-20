// --------------------------------------------------------------------------------
// StaticPixmap
//
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

// Class Header
#include "staticpixmap.h"

// required objects
#include <QImage>
#include <QPixmap>

// --------------------------------------------------------------------------------
//   ####   ####  #    #  ####  ##### #####  #    #  ####  #####  ####  #####   ####
//  #    # #    # ##   # #        #   #    # #    # #    #   #   #    # #    # #
//  #      #    # # #  #  ####    #   #    # #    # #        #   #    # #    #  ####
//  #      #    # #  # #      #   #   #####  #    # #        #   #    # #####       #
//  #    # #    # #   ## #    #   #   #   #  #    # #    #   #   #    # #   #  #    #
//   ####   ####  #    #  ####    #   #    #  ####   ####    #    ####  #    #  ####
// --------------------------------------------------------------------------------

// Default Constructor
StaticPixmap::StaticPixmap(const QString &image_path_, const QSize &imsize_, QObject *parent):
   input_image_path(image_path_),
   imsize(imsize_),
   QObject(parent)
{
   // ------ Path to Scaled Pixmap  ------------------------------------

   // pull image
   QImage image;
   image = QImage( input_image_path );

   // scale image
   image = image.scaledToWidth(imsize.rwidth());

   // convert to piximap
   pixmap_scaled    = new QPixmap();
   pixmap_scaled->convertFromImage(image);
   *pixmap_scaled   = pixmap_scaled->copy(QRect(0,0,imsize.rwidth(), imsize.rheight()));
}

// ------------------------------------------------------------------
//    ##    ####   ####  ######  ####   ####   ####  #####   ####
//   #  #  #    # #    # #      #      #      #    # #    # #
//  #    # #      #      #####   ####   ####  #    # #    #  ####
//  ###### #      #      #           #      # #    # #####       #
//  #    # #    # #    # #      #    # #    # #    # #   #  #    #
//  #    #  ####   ####  ######  ####   ####   ####  #    #  ####
// ------------------------------------------------------------------

// get_scaled_pixmap
QPixmap* StaticPixmap::get_scaled_pixmap()
{
   return pixmap_scaled;
}




















//
