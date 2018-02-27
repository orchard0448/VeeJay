// --------------------------------------------------------------------------------
// GraphicMixer
//
// This object interprets a set of pixmaps and combines them using specified
// composition
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/25/2018
// --------------------------------------------------------------------------------

// class header file
#include "graphicmixer.h"

// include used classes
#include <QTimer>
#include <QPixmap>
#include <QPainter>

// --------------------------------------------------------------------------------
//   ####   ####  #    #  ####  ##### #####  #    #  ####  #####  ####  #####   ####
//  #    # #    # ##   # #        #   #    # #    # #    #   #   #    # #    # #
//  #      #    # # #  #  ####    #   #    # #    # #        #   #    # #    #  ####
//  #      #    # #  # #      #   #   #####  #    # #        #   #    # #####       #
//  #    # #    # #   ## #    #   #   #   #  #    # #    #   #   #    # #   #  #    #
//   ####   ####  #    #  ####    #   #    #  ####   ####    #    ####  #    #  ####
// --------------------------------------------------------------------------------

// Default Constructor
GraphicMixer::GraphicMixer(QObject *parent) : QObject(parent)
{
   // ------ Timer ------------------------------------

   // Initialize Remix Timer
   remix_timer = new QTimer(this);

   // connect timer to remix slot
   QObject::connect(remix_timer, QTimer::timeout, this, GraphicMixer::remix);

   // start timer
   remix_timer->start(1);

   // ------ Graphic ------------------------------------

   // initialize pixmap
   mixed_pixmap = new QPixmap();

   // initialize painter for image composition
   //mix_painter    = new QPainter(mixed_pixmap);

   // pull image
   QImage image(QString("C:\\Users\\Aidan\\Desktop\\krug.jpg"));

   // scale image
   image = image.scaledToWidth(width);

   // convert ot piximap
   mixed_pixmap->convertFromImage(image);
   *mixed_pixmap   = mixed_pixmap->copy(QRect(0,0,width,height));

}

// ------------------------------------------------------------------
//   ##    ####   ####  ######  ####   ####   ####  #####   ####
//  #  #  #    # #    # #      #      #      #    # #    # #
// #    # #      #      #####   ####   ####  #    # #    #  ####
// ###### #      #      #           #      # #    # #####       #
// #    # #    # #    # #      #    # #    # #    # #   #  #    #
// #    #  ####   ####  ######  ####   ####   ####  #    #  ####
// ------------------------------------------------------------------

// add_channel
void GraphicMixer::add_channel(QPixmap *new_channel_pixmap)
{
   channel_pixmaps.push_back(new_channel_pixmap);
}

// ---------------------------------------------------------------------
//  ####  #       ####  #####  ####
// #      #      #    #   #   #
//  ####  #      #    #   #    ####
//      # #      #    #   #        #
// #    # #      #    #   #   #    #
//  ####  ######  ####    #    ####
// ---------------------------------------------------------------------

// remix
void GraphicMixer::remix()
{
   // begin painting
   mix_painter = new QPainter();

   mix_painter->begin(mixed_pixmap);

   // add white
   mix_painter->fillRect(0,0,width,height,Qt::GlobalColor::white);

   // add channel 0
   mix_painter->drawPixmap(0,0,width,height, *channel_pixmaps[0]);

   // change composition mode
   mix_painter->setCompositionMode(QPainter::CompositionMode_Difference);

   // add channel 1
   mix_painter->drawPixmap(0,0,width,height, *channel_pixmaps[1]);

   // simply set equal for now
   //*mixed_pixmap   = *channel_pixmaps[0];

   mix_painter->end();

   // emit signal to final graphic
   update_finalgraphic(mixed_pixmap);
}
























