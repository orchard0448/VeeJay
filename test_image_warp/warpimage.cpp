// --------------------------------------------------------------------------------
// WarpImage
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/02/2018
// initial commit.
// --------------------------------------------------------------------------------

// Class Header
#include "warpimage.h"

// --------------------------------------------------------------------------------
//   ####   ####  #    #  ####  ##### #####  #    #  ####  #####  ####  #####   ####
//  #    # #    # ##   # #        #   #    # #    # #    #   #   #    # #    # #
//  #      #    # # #  #  ####    #   #    # #    # #        #   #    # #    #  ####
//  #      #    # #  # #      #   #   #####  #    # #        #   #    # #####       #
//  #    # #    # #   ## #    #   #   #   #  #    # #    #   #   #    # #   #  #    #
//   ####   ####  #    #  ####    #   #    #  ####   ####    #    ####  #    #  ####
// --------------------------------------------------------------------------------

// Default Constructor
WarpImage::WarpImage(QWidget *parent) : QWidget(parent)
{
   // Size
   resize(QSize(1000,500));

   // pull image
   image = new QImage(QString("C:\\Users\\Aidan\\Desktop\\krug.jpg"));

   // convert ot piximap
   piximage    = new QPixmap();
   piximage->convertFromImage(*image);

   // add pixmap to label
   labelimage  = new QLabel(this);
   labelimage->setPixmap(piximage->scaledToWidth(1000));
}



// test slot
void WarpImage::test_slot(int value)
{
   //message->setText(QString(value));
   image->invertPixels();
   piximage->convertFromImage(*image);
   labelimage->setPixmap(piximage->scaledToWidth(1000));

}















