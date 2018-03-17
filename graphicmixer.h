// --------------------------------------------------------------------------------
// GraphicMixer
//
// This object interprets a set of pixmaps and combines them using specified
// composition
//
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

#ifndef GRAPHICMIXER_H
#define GRAPHICMIXER_H

// include QObject
#include <QObject>

// include other classes
#include <vector>

// predeclare classes and include Qt classes
#include <QPainter>
class QTimer;

// --------------------------------------------------------------
// FinalGraphic Class Declaration
// --------------------------------------------------------------
//
// ----------Constructors------------------------------
// Default Constructor
// ----------Mutators--------------------------------
// add_channel
// paint_alpha_gain_map
// paint_alpha_on_channel
// ----------Signals--------------------------------
// graphic_remixed
// ----------Slots----------------------------------
// remix
// --------------------------------------------------------------

class GraphicMixer : public QObject
{
   Q_OBJECT

private:

   // Size
   int   height   = 500;
   int   width    = 1000;

   // background color
   QColor            background_color = Qt::GlobalColor::white;

   // internal update timer
   QTimer            *remix_timer;

   // pixmap for channel combination
   QPixmap           *mixed_pixmap;

   // painters
   QPainter          *mix_painter;
   QPainter          *alpha_painter;

   // channel data
   std::vector<QPixmap*>                     channel_pixmap_originals;
   std::vector<QPixmap*>                     channel_pixmap_postalpha;
   std::vector<QPixmap*>                     channel_alpha_gain_maps;
   std::vector<int>                          channel_alpha;
   std::vector<QPainter::CompositionMode>    comp_modes;

public:

   // ----------Constructors------------------------------

   // Default Constructor
   explicit GraphicMixer(QObject *parent = nullptr);

   // ----------Mutators--------------------------------

   // add_channel
   void add_channel(QPixmap *new_channel_pixmap, const QPainter::CompositionMode &mode, const int &alpha_gain);

   // paint_alpha_gain_map
   void paint_alpha_gain_map(const int &channel_num);

   // paint_alpha_on_channel
   void paint_alpha_on_channel(const int &channel_num);


   // ----------Signals--------------------------------

signals:

   // graphic_remixed
   void graphic_remixed(QPixmap *pixmap);

   // ----------Slots----------------------------------

public slots:

   // remix
   void remix();
};

#endif // GRAPHICMIXER_H
