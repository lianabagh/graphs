#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H
#include<QGraphicsScene>
#include <QGraphicsView>
#include<QVector>
class Node;

//! [0]
class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:
    GraphWidget( int row_count,int column_count,QWidget *parent = nullptr);
    void print_MST(int parent[],std::vector<int> vec);

public slots:
    void zoomIn();
    void zoomOut();

protected:
    void drawBackground(QPainter *painter, const QRectF &rect) override;
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif

    void scaleView(qreal scaleFactor);
private:
	int node_count;
	QVector<Node*> vec;	
	QGraphicsScene* scene;


};
#endif // GRAPHWIDGET_H
