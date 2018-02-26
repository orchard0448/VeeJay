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
   WarpImage main_image;

   // Create FinalGaphic
   FinalGraphic final;
   final.show();

   // Create Graphic Mixer
   GraphicMixer mixer;

   // connect warpimage to graphic mixer
   QObject::connect(&main_image, WarpImage::graphic_changed, &mixer, GraphicMixer::update_channel);

   // Connect graphic mixer to final image
   QObject::connect(&mixer, GraphicMixer::update_finalgraphic, &final, FinalGraphic::update);

   // Create Control Panel
   //ControlPanel controls;
   //controls.show();

   // conenct control slider to warp image slot
   //QObject::connect(&controls, &ControlPanel::slider1Changed, &main_image, WarpImage::test_slot);

   return a.exec();
}
