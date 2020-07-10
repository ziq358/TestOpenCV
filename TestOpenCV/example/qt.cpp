//
//  qt.cpp
//  ex_qt
//
//  Created by 吴炎强 on 2020/7/7.
//  Copyright © 2020 johnwu. All rights reserved.
//

#include <QtWidgets/qapplication.h>
#include <iostream>

using namespace std;

int main( int argc, char* argv[] ) {
//  string path = "/Users/wuyanqiang/Documents/opencv/TestOpenCV/resource/test.avi";
    QApplication* app = new QApplication(argc, argv);
    return app->exec();
//  return app.exec();
}
