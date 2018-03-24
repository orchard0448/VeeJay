// --------------------------------------------------------------------------------
// GraphicMixer
//
// This object interprets a set of pixmaps and combines them using specified
// composition
//
// --------------------------------------------------------------------------------
//    Aidan Orchard
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
GraphicMixer::GraphicMixer(const QSize &imsize_, QObject *parent) :
   imsize(imsize_),
   QObject(parent)
{
   // ------ Timer ------------------------------------

   // Initialize Remix Timer
   remix_timer = new QTimer(this);

   // connect timer to remix slot
   QObject::connect(remix_timer, QTimer::timeout, this, GraphicMixer::remix);

   // start timer
   remix_timer->start(10);

   // ------ Graphic ------------------------------------

   // initialize pixmap
   mixed_pixmap = new QPixmap(imsize);

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
void GraphicMixer::add_channel(QPixmap *new_channel_pixmap, const QPainter::CompositionMode &mode,
                               AbstractFunction* alphafunction)
{
   // this function adds a channel to the mixer
   //    inputs:  reference to the pixmap for the channel
   //             composition mode for the channel

   // chanel pixmap
   channel_pixmap_originals.push_back(new_channel_pixmap);

   // composition mode
   comp_modes.push_back(mode);

   // create an alpha gain pixmap for this pixmap
   channel_alpha_gain_maps.push_back(new QPixmap(imsize));

   // create a post-alpha pixmap for channel
   channel_pixmap_postalpha.push_back(new QPixmap(imsize));

   // create alpha for this channel
   channel_alpha.push_back(alphafunction);
}

// paint_alpha_gain_map
void GraphicMixer::paint_alpha_gain_map(const int &channel_num)
{

   // create a painter
   QPainter    painter(channel_alpha_gain_maps[channel_num]);

   // change composition mode
   painter.setCompositionMode(QPainter::CompositionMode_Source);

   // draw rectangle
   painter.fillRect(0, 0, imsize.rwidth(), imsize.rheight(),
                    QBrush(QColor(0, 0, 0, channel_alpha[channel_num]->f()*255)));

   // end paint
   painter.end();

}

// paint_alpha_on_channel
void GraphicMixer::paint_alpha_on_channel(const int &channel_num)
{
   // paint alpha gain map
   paint_alpha_gain_map(channel_num);

   // begin painting
   alpha_painter = new QPainter();
   alpha_painter->begin(channel_pixmap_postalpha[channel_num]);

   // add original alpha
   alpha_painter->drawPixmap(0,0,imsize.rwidth(), imsize.rheight(), *channel_alpha_gain_maps[channel_num]);

   // change composition mode
   alpha_painter->setCompositionMode(QPainter::CompositionMode_SourceIn);

   // paint channel
   alpha_painter->drawPixmap(0,0,imsize.rwidth(), imsize.rheight(), *channel_pixmap_originals[channel_num]);

   // fin
   alpha_painter->end();
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

   // --- repaint each alpha channel
   // loop through each channel
   for(int ci = 0; ci < channel_pixmap_originals.size(); ci++)
   {
      // re-paint the alpha mixed channel
      paint_alpha_on_channel(ci);
   }

   // begin painting
   mix_painter = new QPainter();

   mix_painter->begin(mixed_pixmap);

   // add white
   mix_painter->fillRect(0,0,imsize.rwidth(), imsize.rheight(), background_color);

   // loop through each channel
   for(int ci = 0; ci < channel_pixmap_originals.size(); ci++)
   {
      // change composition mode
      mix_painter->setCompositionMode(comp_modes[ci]);

      // add channel 0
      mix_painter->drawPixmap(0,0,imsize.rwidth(), imsize.rheight(), *channel_pixmap_postalpha[ci]);
   }

   mix_painter->end();

   // emit signal to final graphic
   graphic_remixed(mixed_pixmap);
}
























