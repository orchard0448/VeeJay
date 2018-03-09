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
   mixed_pixmap = new QPixmap(QSize(width, height));

}

// ------------------------------------------------------------------
//  #    # #    # #####   ##   #####  ####  #####   ####
//  ##  ## #    #   #    #  #    #   #    # #    # #
//  # ## # #    #   #   #    #   #   #    # #    #  ####
//  #    # #    #   #   ######   #   #    # #####       #
//  #    # #    #   #   #    #   #   #    # #   #  #    #
//  #    #  ####    #   #    #   #    ####  #    #  ####
// ------------------------------------------------------------------

// add_channel
void GraphicMixer::add_channel(QPixmap *new_channel_pixmap, QPainter::CompositionMode mode)
{
   // this function adds a channel to the mixer
   //    inputs:  reference to the pixmap for the channel
   //             composition mode for the channel

   // chanel pixmap
   channel_pixmaps.push_back(new_channel_pixmap);

   // composition mode
   comp_modes.push_back(mode);
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
   // this function recomposes the mix product and emits an update signal
   //
   // mixing the composition entails creating a background and adding
   // each channel with the specified composition mode

   // begin painting
   mix_painter = new QPainter();

   mix_painter->begin(mixed_pixmap);

   // add white
   mix_painter->fillRect(0,0,width, height, background_color);

   // loop through each channel
   for(int ci = 0; ci < channel_pixmaps.size(); ci++)
   {
      // change composition mode
      mix_painter->setCompositionMode(comp_modes[ci]);

      // add channel 0
      mix_painter->drawPixmap(0,0,width,height, *channel_pixmaps[ci]);
   }

   mix_painter->end();

   // emit signal to final graphic
   graphic_remixed(mixed_pixmap);
}
























