#include <QApplication>
#include <QWidget>

#include <controlpanel.h>
#include <warpimage.h>
#include <finalgraphic.h>
#include <graphicmixer.h>
#include <QWidget>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   // Create WarpImage
   WarpImage warp1, warp2, warp3, warp4;

   // create two timers
   QTime   time1, time2, time3, time4;
   time1.start();
   time2.start();
   time3.start();
   time4.start();

   // offset timers
   time2 = time2.addMSecs(10000);
   time4 = time4.addMSecs(20000);

   // plug in timers
   warp1.set_qtime(&time1);
   warp2.set_qtime(&time2);
   warp3.set_qtime(&time3);
   warp4.set_qtime(&time4);

   // adjust max width and height of warp2
   warp2.set_max_rel_height(1);
   warp2.set_max_rel_width(0.8);

   // adjust max width and height of warp2
   warp3.set_max_rel_height(0.3);
   warp3.set_max_rel_width(1);

   // adjust max width and height of warp2
   warp3.set_max_rel_height(1);
   warp3.set_max_rel_width(0.3);

   // Create FinalGaphic
   FinalGraphic final;
   final.show();

   // Create Graphic Mixer
   GraphicMixer mixer;

   // add warp1's pixmap to mixer
   mixer.add_channel(warp1.get_pixmap(), QPainter::CompositionMode_Difference );
   mixer.add_channel(warp2.get_pixmap(), QPainter::CompositionMode_Difference );
   mixer.add_channel(warp3.get_pixmap(), QPainter::CompositionMode_Difference );


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
