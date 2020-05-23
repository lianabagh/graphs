#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>
#include <QVector>

class Edge;
class GraphWidget;

class Node : public QGraphicsItem
{
public:
    Node(GraphWidget *graphWidget);

    void addEdge(Edge *edge);
    QVector<Edge*> edges() const;

    enum { Type = UserType + 1 };
    int type() const override { return Type; }


    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QVector<Edge*> edgeList;
    GraphWidget *graph;
};

#endif // NODE_H
