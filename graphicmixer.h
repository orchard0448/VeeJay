// --------------------------------------------------------------------------------
// GraphicMixer
//
// This object interprets a set of pixmaps and combines them using specified
// composition
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/25/2018
// --------------------------------------------------------------------------------

#ifndef GRAPHICMIXER_H
#define GRAPHICMIXER_H

// include QObject
#include <QObject>

// include other classes
#include <vector>

// predeclare classes
class QTimer;
class QPainter;

// --------------------------------------------------------------
// FinalGraphic Class Declaration
// --------------------------------------------------------------
//
// ----------Constructors--------------------------
// Default Constructor (with QObject parent)
// ----------Accessor Functions---------------------
// none
// ----------Mutator Functions----------------------
// none
// ----------File IO Functions----------------------
// none
// ----------Signals--------------------------------
// update_finalgraphic
// ----------Slots----------------------------------
// update_channel
// --------------------------------------------------------------

class GraphicMixer : public QObject
{
   Q_OBJECT

private:

   // Size
   int   height   = 500;
   int   width    = 1000;

   // internal update timer
   QTimer            *remix_timer;

   // pixmap for channel combination
   QPixmap           *mixed_pixmap;
   QPainter          *mix_painter;

   // list of pixmaps being mixed
   std::vector<QPixmap*>  channel_pixmaps;

public:

   // Default Constructor
   explicit GraphicMixer(QObject *parent = nullptr);

   // add_channel
   void add_channel(QPixmap *new_channel_pixmap);

   // ----------Signals--------------------------------

signals:

   // graphic_changed
   void update_finalgraphic(QPixmap *pixmap);

public slots:

   // remix
   void remix();
};

#endif // GRAPHICMIXER_H
