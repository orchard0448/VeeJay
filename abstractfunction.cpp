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
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

// class header file
#include "abstractfunction.h"

// --------------------------------------------------------------------------------
//   ####   ####  #    #  ####  ##### #####  #    #  ####  #####  ####  #####   ####
//  #    # #    # ##   # #        #   #    # #    # #    #   #   #    # #    # #
//  #      #    # # #  #  ####    #   #    # #    # #        #   #    # #    #  ####
//  #      #    # #  # #      #   #   #####  #    # #        #   #    # #####       #
//  #    # #    # #   ## #    #   #   #   #  #    # #    #   #   #    # #   #  #    #
//   ####   ####  #    #  ####    #   #    #  ####   ####    #    ####  #    #  ####
// --------------------------------------------------------------------------------

// Default Constructor
AbstractFunction::AbstractFunction(QObject *parent) : QObject(parent)
{
    // do nothing
}


// ----------------------------------------------------------
//  ####  ###### ##### ##### ###### #####   ####
// #    # #        #     #   #      #    # #
// #      #####    #     #   #####  #    #  ####
// #  ### #        #     #   #      #####       #
// #    # #        #     #   #      #   #  #    #
//  ####  ######   #     #   ###### #    #  ####
// ----------------------------------------------------------

// f()
//virtual double f() const
