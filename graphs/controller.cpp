#include"controller.h"
#include"graphwidget.h"
#include "max_spanning.h"
#include<QMainWindow>
class Graph;
class GraphWidget;


controller::controller(int rows,int columns)
{
    GraphWidget *widget = new GraphWidget(rows,columns);
    Graph g(rows,columns);
    int *par_copy =  g.primMST();
    vector<int> vecish = g.get_edges();
    //list<pair<int,int>>* vecish = g.get_edges();
    widget->print_MST(par_copy,vecish);
    QMainWindow *mainWindow = new QMainWindow();

    mainWindow->setCentralWidget(widget);

    mainWindow->show();
}
