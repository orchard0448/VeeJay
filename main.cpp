#include <QApplication>
#include <QWidget>

#include <controlpanel.h>
#include <warpimage.h>
#include <QWidget>

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

   // Create Control Panel
   ControlPanel controls;
   controls.show();

   // Create WarpImage
   WarpImage main_image;
   main_image.show();

   // conenct!
   QObject::connect(&controls, &ControlPanel::slider1Changed, &main_image, WarpImage::test_slot);

   return a.exec();
}
