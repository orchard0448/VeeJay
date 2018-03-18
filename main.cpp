#include <QApplication>
#include <QWidget>

#include <controlpanel.h>
#include <warpimage.h>
#include <finalgraphic.h>
#include <graphicmixer.h>
#include <functiontimesin.h>

int main(int argc, char *argv[])
{
   // main application
   QApplication a(argc, argv);

   // Image Paths
   QString  krug   = QString("C:\\Users\\Aidan\\Desktop\\krug.jpg");
   QString  stars1    = QString("C:\\Users\\Aidan\\Downloads\\pexels-photo-134074.jpeg");
   QString  stars2    = QString("C:\\Users\\Aidan\\Downloads\\pexels-photo-207529.jpeg");
   QString  sun1    = QString("C:\\Users\\Aidan\\Downloads\\sun-fireball-solar-flare-sunlight-87611.jpeg");
   QString  sun2    = QString("C:\\Users\\Aidan\\Downloads\\solar-flare-sun-eruption-energy-39561.jpeg");
   QString  moon1    = QString("C:\\Users\\Aidan\\Downloads\\pexels-photo-459475.jpeg");
   QString  moon2    = QString("C:\\Users\\Aidan\\Downloads\\pexels-photo-673902.jpeg");

   // Size for image processing
   QSize    imsize(1800, 1000);

   // Create WarpImage
   WarpImage stationary_moon(moon2, imsize);
   WarpImage warp2(stars2, imsize);
   WarpImage warp3(stars1, imsize);

   // create sin waves
   AbstractFunction *sin1   = new FunctionTimeSin(0.1, 0);
   AbstractFunction *sin2   = new FunctionTimeSin(0.1, 0.25);
   AbstractFunction *sin3   = new FunctionTimeSin(0.1, 0.5);
   AbstractFunction *sin4   = new FunctionTimeSin(0.1, 0.75);

   stationary_moon.set_vert_bord1(new FunctionScalar(0));
   stationary_moon.set_vert_bord2(new FunctionScalar(0));
   stationary_moon.set_horz_bord1(sin3);
   stationary_moon.set_horz_bord2(sin2);

   warp2.set_vert_bord1(sin2);
   warp2.set_vert_bord2(sin4);
   warp2.set_horz_bord1(sin4);
   warp2.set_horz_bord2(sin3);

   warp3.set_vert_bord1(sin3);
   warp3.set_vert_bord2(sin1);
   warp3.set_horz_bord1(sin1);
   warp3.set_horz_bord2(sin4);

   // Create FinalGaphic
   FinalGraphic final;
   final.show();

   // Create Graphic Mixer
   GraphicMixer mixer(imsize);

   // add warp1's pixmap to mixer
   mixer.add_channel(stationary_moon.get_pixmap(), QPainter::CompositionMode_SourceAtop , sin3);
   mixer.add_channel(warp2.get_pixmap(), QPainter::CompositionMode_Difference , sin2);
   mixer.add_channel(warp3.get_pixmap(), QPainter::CompositionMode_Difference , sin1);


   // Connect graphic mixer to final image
   QObject::connect(&mixer, GraphicMixer::graphic_remixed, &final, FinalGraphic::update);

   // connect warpimage to graphic mixer
   //QObject::connect(&warp1, WarpImage::graphic_changed, &mixer, GraphicMixer::update_channel);

   // Create Control Panel
   //ControlPanel controls;
   //controls.show();

   // conenct control slider to warp image slot
   //QObject::connect(&controls, &ControlPanel::slider1Changed, &main_image, WarpImage::test_slot);

   return a.exec();
}
