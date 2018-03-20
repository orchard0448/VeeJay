// --------------------------------------------------------------------------------
// StaticPixmap
//
// --------------------------------------------------------------------------------
//    Aidan Orchard
// --------------------------------------------------------------------------------

#ifndef STATICPIXMAP_H
#define STATICPIXMAP_H

#include <QObject>

// predeclare required classes
class QPixmap;
#include <QSize>

// --------------------------------------------------------------
// StaticPixmap Class Declaration
// --------------------------------------------------------------
// functions:
// ----------Constructors------------------------------
// Default Constructor
// ----------Accessors------------------------------
// get_sized_pixmap
// --------------------------------------------------------------

class StaticPixmap : public QObject
{
   Q_OBJECT

protected:

   // Size
   QSize       imsize;

   // input image path
   QString     input_image_path;

   // original scaled image pixmap
   QPixmap     *pixmap_scaled;

public:
   // ----------Constructors------------------------------

   // Default Constructor
   StaticPixmap(const QString &image_path_, const QSize &imsize_, QObject *parent = nullptr);

   // ----------Accessors--------------------------------

   // get_scaled_pixmap
   QPixmap* get_scaled_pixmap();

};

#endif // STATICPIXMAP_H
