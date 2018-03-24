// --------------------------------------------------------------------------------
// FunctionTimeSin
//
// Derived from AbstractFunction
//
// Returns sin(2*pi*frequency*t) scaled from 0 to 1
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

#ifndef FUNCTIONTIMESIN_H
#define FUNCTIONTIMESIN_H

// include AbstractFunction base class
#include <abstractfunction.h>

// supporting libraries
#include <QtMath>
#include <QObject>
#include <QTime>

// --------------------------------------------------------------
// FunctionTimeSin Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors------------------------------
// Default Constructor
// ----------Getters--------------------------------
// f()
// ----------Setters--------------------------------
// ----------Signals--------------------------------
// ----------Slots----------------------------------
// --------------------------------------------------------------

class FunctionTimeSin : public AbstractFunction
{
   Q_OBJECT
protected:

   // main  timer
   QTime    *time;

   // frequency
   double   frequency; // Hz

   // phase offset (in terms of wavelengths)
   double phase_offset; // cycles

public:

   // ----------Constructors------------------------------

   // Default Constructor
   FunctionTimeSin(double f_, double phase_offset, QObject *parent = nullptr);

   // ----------Getters--------------------------------

   // f()
   double f() const override;
};

#endif // FUNCTIONTIMESIN_H
