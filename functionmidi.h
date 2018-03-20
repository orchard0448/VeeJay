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

#ifndef FUNCTIONMIDI_H
#define FUNCTIONMIDI_H

// --------------------------------------------------------------
// FunctionMidi Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors------------------------------
// Default Constructor
// ----------Getters--------------------------------
// f()
// --------------------------------------------------------------

class FunctionMidi: public AbstractFunction
{
   Q_OBJECT
public:

   // scalar value
   double midi_value;

   //----------Constructors------------------------------

   FunctionMidi(QObject *parent = nullptr);

   // ----------Getters--------------------------------

   // f()
   double f() const override;
};

#endif // FUNCTIONMIDI_H
