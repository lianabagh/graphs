#include "graphwidget.h"
#include <QApplication>
#include <QTime>
#include <QMainWindow>
#include"max_spanning.h"
#include"controller.h"
class Graph;
int main(int argc, char **argv)
{
    int rows=0,columns=0;
    cout<<"Rows = ";
    cin>>rows;
    cout<<"Columns = ";
    cin>>columns;
    
    QApplication app(argc, argv);
    controller *cnt = new controller(rows,columns);    
   // GraphWidget *widget = new GraphWidget(rows,columns);
   // Graph g(rows,columns);
   // int *par_copy =  g.primMST();
   // widget->print_MST(par_copy);
   // QMainWindow mainWindow;

    //mainWindow.setCentralWidget(widget);

    //mainWindow.show();
    return app.exec();
}

