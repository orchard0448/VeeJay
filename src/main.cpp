#include <QtWidgets/QApplication>
#include "ui/mainwindow.h"
#include <controlpanel.h>
#include <warpimage.h>
#include <finalgraphic.h>
#include <graphicmixer.h>
#include <functiontimesin.h>
#include <staticpixmap.h>
#include <functionmidi.h>
#include "Bridge.h"


#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QCoreApplication::setOrganizationName("Projectgus");
    //QCoreApplication::setOrganizationDomain("projectgus.com");
    //QCoreApplication::setApplicationName("Hairless MIDI Serial Bridge");
    MainWindow w;
    w.show();

    // --------------------------------------------------------------------------------
   // Paths & Directories
   // --------------------------------------------------------------------------------

   // Image Directory
   QString   dir_image   = "C:\\Users\\widellt\\Pictures\\Cyberpunk\\";

   // Image Paths
   QString  path_stars1         = QString(dir_image + "tyTest.jpg");
   QString  path_stars2         = QString(dir_image + "tyTest2.jpg");
   QString  path_sun_orange     = QString(dir_image + "tyTest3.jpg");
   QString  path_sun_purple     = QString(dir_image + "tyTest4.jpg");
   QString  path_moon_full      = QString(dir_image + "tyTest5.jpg");
   QString  path_sun_cutout     = QString(dir_image + "tyTest6.jpg");

   // logo paths
   QString  path_yuri_whole     = QString(dir_image + "tyTest7.jpg");
   QString  path_yuri_red       = QString(dir_image + "tyTest.jpg");
   QString  path_yuri_bw        = QString(dir_image + "tyTest9.jpg");

   // --------------------------------------------------------------------------------
  // Constants / Inputs
  // --------------------------------------------------------------------------------

  // Size for image processing
  QSize    imsize(1000, 600);
  QSize    finsize  = imsize;

  // create sin waves
  double frequency_main   = 0.10;
  AbstractFunction *sin0   = new FunctionTimeSin(frequency_main, 0);
  AbstractFunction *sin1   = new FunctionTimeSin(frequency_main, 0.25);
  AbstractFunction *sin2   = new FunctionTimeSin(frequency_main, 0.5);
  AbstractFunction *sin3   = new FunctionTimeSin(frequency_main, 0.75);

  //static_cast<FunctionMidi*>(mamaWindow->midiControl)->midiVal(bufCon);
  AbstractFunction *midiTest = new FunctionMidi();
  printf("Oh Hi: %f\n", static_cast<FunctionMidi*>(midiTest)->midiVal());

  // --------------------------------------------------------------------------------
  // Static Images
  // --------------------------------------------------------------------------------

  // Moon
  StaticPixmap static_moon(path_moon_full, imsize);

  // stars
  StaticPixmap static_stars(path_stars2, imsize);

  // yuris
  StaticPixmap yuri_whole(path_yuri_whole, imsize);
  StaticPixmap yuri_red(path_yuri_red, imsize);
  StaticPixmap yuri_bw(path_yuri_bw, imsize);

  // sun
  StaticPixmap static_sun_cutout(path_sun_cutout, imsize);

  // --------------------------------------------------------------------------------
  // Warp Images
  // --------------------------------------------------------------------------------

  // Images for Warping
  WarpImage stars1(path_stars1, imsize);
  WarpImage stars2(path_stars2, imsize);

  stars1.set_vert_bord1(sin1);
  stars1.set_vert_bord2(sin3);
  stars1.set_horz_bord1(sin3);
  stars1.set_horz_bord2(sin2);

  stars2.set_vert_bord1(sin2);
  stars2.set_vert_bord2(sin0);
  stars2.set_horz_bord1(sin0);
  stars2.set_horz_bord2(sin3);


   // --------------------------------------------------------------------------------
   // Mixer
   // --------------------------------------------------------------------------------

   // Create Graphic Mixer
  GraphicMixer mixer(imsize);


  //midi_control1->f(MainWindow::pitchBend);

  // add warp1's pixmap to mixer

  //mixer.add_channel(static_stars.get_scaled_pixmap(), QPainter::CompositionMode_SourceAtop , sin3);
  //mixer.add_channel(static_sun_cutout.get_scaled_pixmap(), QPainter::CompositionMode_Plus , new FunctionScalar(1));

  //mixer.add_channel(stars1.get_warped_pixmap(), QPainter::CompositionMode_Difference , sin2);
  //mixer.add_channel(static_moon.get_scaled_pixmap(), QPainter::CompositionMode_Difference , sin3);
  //mixer.add_channel(yuri_bw.get_scaled_pixmap(), QPainter::CompositionMode_Difference , new FunctionScalar(1));
  mixer.add_channel(yuri_red.get_scaled_pixmap(), QPainter::CompositionMode_SourceAtop , w.GetMidiControl());
  //mixer.add_channel(yuri_red.get_scaled_pixmap(), QPainter::CompositionMode_SourceAtop, midiTest);

  // Create FinalGaphic
  FinalGraphic final(finsize);
  final.show();

  //QObject::connect(&w, MainWindow::pitchBend, &final, FinalGraphic::update);

  // Connect graphic mixer to final image
  QObject::connect(&mixer, GraphicMixer::graphic_remixed, &final, FinalGraphic::update);


   return a.exec();
}
