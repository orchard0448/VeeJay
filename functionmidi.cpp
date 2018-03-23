// --------------------------------------------------------------------------------
// FunctionMidi
//
// Derived from AbstractFunction
//
// For compatability with other AbstractFunction plugins, instantiate objects
// dynamically
//
// AbstractFunction *midi_control1 = new FunctionMidi()
//
// manipulate double midi_value stored in class to change midi value.
//
// Returns a fixed constant between 0 and 1
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

#include "functionmidi.h"

// --------------------------------------------------------------------------------
//   ####   ####  #    #  ####  ##### #####  #    #  ####  #####  ####  #####   ####
//  #    # #    # ##   # #        #   #    # #    # #    #   #   #    # #    # #
//  #      #    # # #  #  ####    #   #    # #    # #        #   #    # #    #  ####
//  #      #    # #  # #      #   #   #####  #    # #        #   #    # #####       #
//  #    # #    # #   ## #    #   #   #   #  #    # #    #   #   #    # #   #  #    #
//   ####   ####  #    #  ####    #   #    #  ####   ####    #    ####  #    #  ####
// --------------------------------------------------------------------------------

FunctionMidi::FunctionMidi(QObject *parent) : AbstractFunction(parent)
{

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
double FunctionMidi::f() const
{
   return midi_value;
}
