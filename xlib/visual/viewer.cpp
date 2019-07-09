#include "viewer.hpp"

#include "canvas.hpp"

#include <QApplication>

#include <QtWidgets>


using namespace xlib;


void viewer::show( const canvas& object )
{
    int    qt_argc = 0;
    char** qt_argv = nullptr;

    QApplication application( qt_argc, qt_argv );

    QMainWindow window;

    QScrollArea area;

    QLabel label;

    const image& data = object.data();

    auto bits   = ( const uchar* )( data.buffer() );
    auto width  = data.width();
    auto height = data.height();
    auto format = QImage::Format_RGBA8888;

    label.setPixmap( QPixmap::fromImage( QImage( bits, width, height, format ) ) );

    area.setVisible( true );
    area.setWidget( &label );
    area.setWidgetResizable( true );

    window.setCentralWidget( &area );
    window.show();

    QApplication::exec();
}
