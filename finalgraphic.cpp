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
FinalGraphic::FinalGraphic(QWidget *parent) : QWidget(parent)
{
   // Size
   resize(QSize(1000,500));

   // create label
   labelimage  = new QLabel(this);

   QImage ugh("C:\\Users\\Aidan\\Desktop\\krug.jpg");

   labelimage->setPixmap( (QPixmap::fromImage(ugh).scaledToWidth(1000)) );
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
