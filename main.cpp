#include <QtGui/QApplication>
#include "mainwindow.h"
#include "multilingual_cli.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool cli = false;
    QList<QString>::iterator i = a.arguments().begin();
/*    ++i;*///test
    while(i != a.arguments().end()){
        if(*i == "-c" || *i == "--cli"){
            cli = true;
        }
        if(*i == "-h" || *i == "--help"){
            std::cout << "QMultilingual help" << std::endl;
            std::cout << "Created by Saljack" << std::endl;
            std::cout << "--help, -h - this help page" << std::endl;
            std::cout << "--cli, -c - run without gui" << std::endl;
            return 0;
        }
        ++i;
    }
    if(cli){
        Multilingual_cli cl;
//        delete cl;
        return 0;
    }
    MainWindow w;
    w.show();

    return a.exec();

}
