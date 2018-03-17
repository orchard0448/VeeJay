// --------------------------------------------------------------------------------
// FunctionTimeSin
//
// Derived from AbstractFunction
//
// Performs c_off + c_mult*sin(*t)
//
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
   double   frequency = 0.1; // Hz

public:

   // ----------Constructors------------------------------

   // Default Constructor
   FunctionTimeSin(QObject *parent = nullptr);

   // ----------Getters--------------------------------

   // f()
   double f() const override;
};

#endif // FUNCTIONTIMESIN_H
