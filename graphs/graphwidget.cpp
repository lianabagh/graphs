#include<iostream>
#include "graphwidget.h"
#include "edge.h"
#include <math.h>
#include"node.h"
#include <QKeyEvent>
#include <QRandomGenerator>

//! [0]
void GraphWidget::print_MST(int parent[],std::vector<int> vecish)

{
	for (int i=1;i<node_count;i++)
	{
		scene->addItem(new Edge(vec[i],vec[parent[i]],0-vecish[i]));
	}
//for (int u=0;u<node_count;u++)
//      {
//        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
	
  //            scene->addItem(new Edge(vec[u],vec[it->first],it->second));
    //  }
}



GraphWidget::GraphWidget( int row_count, int column_count, QWidget* parent)
    : QGraphicsView(parent)
    ,node_count(row_count*column_count)
    ,vec(row_count*column_count) 
{
    
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-100, -100, (row_count-1)*50 + 100, (column_count-1) * 50 + 100);
    setScene(scene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    scale(qreal(0.8), qreal(0.8));
    setWindowTitle(tr("Graph"));
    for(int i=0;i<row_count*column_count;i++)
    	{
		int row = i/row_count;
		int col = i%row_count;
		vec[i] = new Node(this);
		scene->addItem(vec[i]);
		vec[i]->setPos((col*50)-50,(row*50)-50);
	}
}
//! [1]
#if QT_CONFIG(wheelevent)
//! [5]
void GraphWidget::wheelEvent(QWheelEvent *event)
{
    scaleView(pow(2., -event->angleDelta().y() / 240.0));
}
//! [5]
#endif
void GraphWidget::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();
    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
        painter->fillRect(rightShadow, Qt::darkGray);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
        painter->fillRect(bottomShadow, Qt::darkGray);

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);
    painter->fillRect(rect.intersected(sceneRect), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(sceneRect);

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(14);
    painter->setFont(font);
}
//! [6]

//! [7]
void GraphWidget::scaleView(qreal scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
}
//! [7]


void GraphWidget::zoomIn()
{
    scaleView(qreal(1.2));
}

void GraphWidget::zoomOut()
{
    scaleView(1 / qreal(1.2));
}

