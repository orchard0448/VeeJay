#include <QApplication>
#include <QWidget>

#include <controlpanel.h>
#include <warpimage.h>
#include <finalgraphic.h>
#include <QWidget>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   // Create WarpImage
   WarpImage main_image;
   main_image.show();

   // Create FinalGaphic
   FinalGraphic final;
   final.show();

   // connect warpimage to finalgraphic
   QObject::connect(&main_image, WarpImage::graphic_changed, &final, FinalGraphic::update);

   // Create Control Panel
   //ControlPanel controls;
   //controls.show();


   // conenct!
   //QObject::connect(&controls, &ControlPanel::slider1Changed, &main_image, WarpImage::test_slot);

   return a.exec();
}
