// --------------------------------------------------------------------------------
// AbstractFunction
//
// This is an abstract class used for deriving functions that are used as inputs
// for graphic settings
//
// The main purpose is to create a common format for a variety of input formats.
// Formats include:
//      static values
//      functions of time
//      midi control
//
// Derived classes have member data and functions that allow them to interface with
// those input methods explictly, and this class provides the common functions
// required to access and scale the data
//
// the function converts all inputs to a scale from 0 to 1, and provides methods for
// scaling
//
// pull data from any object derived from this class with f()
//
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

#ifndef ABSTRACTFUNCTION_H
#define ABSTRACTFUNCTION_H

#include <QObject>

// --------------------------------------------------------------
// AbstractFunction Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors------------------------------
// Default Constructor
// ----------Getters--------------------------------
// f()
// --------------------------------------------------------------

class AbstractFunction: public QObject
{
    Q_OBJECT
private:

public:

   // ----------Constructors------------------------------

   // Default Constructor
   AbstractFunction(QObject *parent = nullptr);

   // ----------Getters--------------------------------

   // f()
   virtual double f() const = 0;

};

#endif // ABSTRACTFUNCTION_H
