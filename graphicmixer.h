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
public:
   explicit GraphicMixer(QObject *parent = nullptr);

   // ----------Signals--------------------------------

signals:

   // graphic_changed
   void update_finalgraphic(QPixmap *pixmap);

public slots:

   // update_channel
   void update_channel(QPixmap *pixmap);
};

#endif // GRAPHICMIXER_H
