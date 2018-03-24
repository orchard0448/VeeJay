// --------------------------------------------------------------------------------
// FinalGraphic
//
// This class displays a final image after pre-processing
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/25/2018
// --------------------------------------------------------------------------------

// class header file
#include "finalgraphic.h"

#include <iostream>

#include <QPixmap>
#include <QLabel>

// --------------------------------------------------------------------------------
//   ####   ####  #    #  ####  ##### #####  #    #  ####  #####  ####  #####   ####
//  #    # #    # ##   # #        #   #    # #    # #    #   #   #    # #    # #
//  #      #    # # #  #  ####    #   #    # #    # #        #   #    # #    #  ####
//  #      #    # #  # #      #   #   #####  #    # #        #   #    # #####       #
//  #    # #    # #   ## #    #   #   #   #  #    # #    #   #   #    # #   #  #    #
//   ####   ####  #    #  ####    #   #    #  ####   ####    #    ####  #    #  ####
// --------------------------------------------------------------------------------


// Default Constructor
FinalGraphic::FinalGraphic(const QSize &imsize_, QWidget *parent) :
   QWidget(parent),
   imsize(imsize_)
{
   // Size
   resize(imsize);

   // create label
   labelimage  = new QLabel(this);

   // create pixmap of size
   QPixmap  temp_pixmap(imsize);
   temp_pixmap.fill(QColor(Qt::GlobalColor::white));
   labelimage->setPixmap(temp_pixmap);
   labelimage->setAlignment(Qt::AlignTop);

}

// ---------------------------------------------------------------------
//  ####  #       ####  #####  ####
// #      #      #    #   #   #
//  ####  #      #    #   #    ####
//      # #      #    #   #        #
// #    # #      #    #   #   #    #
//  ####  ######  ####    #    ####
// ---------------------------------------------------------------------

// update
void FinalGraphic::update(QPixmap *pixmap)
{
   labelimage->setPixmap(*pixmap);

   //std::cout<<pixmap->width();
}
