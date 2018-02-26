// --------------------------------------------------------------------------------
// FinalGraphic
//
// This class displays a final image after pre-processing
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 02/25/2018
// --------------------------------------------------------------------------------

#ifndef FINALGRAPHIC_H
#define FINALGRAPHIC_H

// Include headers
#include <QWidget>

// pre-declare classes
class QPixmap;
class QLabel;

// --------------------------------------------------------------
// FinalGraphic Class Declaration
// --------------------------------------------------------------
//
// ----------Constructors--------------------------
// Default Constructor (with QWidget)
// ----------Accessor Functions---------------------
// none
// ----------Mutator Functions----------------------
// none
// ----------File IO Functions----------------------
// none
// ----------Signals--------------------------------
// none
// ----------Slots----------------------------------
// update
// --------------------------------------------------------------


class FinalGraphic : public QWidget
{
   Q_OBJECT

private:
   // image
   QLabel      *labelimage;

public:

   // ----------Constructors---------------------

   // default constructor
   explicit FinalGraphic(QWidget *parent = nullptr);

   // ----------Signals--------------------------------

signals:


   // ----------Slots----------------------------------

public slots:

   // update
   void update(QPixmap *pixmap);

};

#endif // FINALGRAPHIC_H
