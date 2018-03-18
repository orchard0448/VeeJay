// --------------------------------------------------------------------------------
// FunctionScalar
//
// Derived from AbstractFunction
//
// Returns a fixed constant between 0 and 1
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

#ifndef FUNCTIONSCALAR_H
#define FUNCTIONSCALAR_H

// include AbstractFunction base class
#include <abstractfunction.h>

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

class FunctionScalar : public AbstractFunction
{
   Q_OBJECT
public:

   // scalar value
   double scalar;

   //----------Constructors------------------------------

   FunctionScalar(double s_, QObject *parent = nullptr);

   // ----------Getters--------------------------------

   // f()
   double f() const override;
};

#endif // FUNCTIONSCALAR_H
