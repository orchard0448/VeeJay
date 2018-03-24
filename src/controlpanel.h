// --------------------------------------------------------------------------------
// ControlPanel
//
// Written to Control Stuff
//
// --------------------------------------------------------------------------------
//    Aidan Orchard 01/31/2018
// initial commit.
// --------------------------------------------------------------------------------

#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

// Qt Libraries
#include <QWidget>
#include <QSlider>

// --------------------------------------------------------------
// ControlPanel Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors---------------------
// Default Constructor
// ----------Accessor Functions---------------------
// ----------Mutator Functions----------------------
// ----------File IO Functions-----------------------
// --------------------------------------------------------------

class ControlPanel : public QWidget
{
   Q_OBJECT

private:

   QSlider  *slider1;

public:

   // Default Constructor
   explicit ControlPanel(QWidget *parent = nullptr);

signals:
   void slider1Changed(int value);

public slots:


};

#endif // CONTROLPANEL_H
