#ifndef EDGE_H
#define EDGE_H

#include <QGraphicsItem>

class Node;

class Edge : public QGraphicsItem

{
public:
    Edge(Node *sourceNode, Node *destNode,int weight);
    Node *sourceNode() const;
    Node *destNode() const;
    void adjust();


protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    Node *source, *dest;
    int weight;
    QPointF sourcePoint;
    QPointF destPoint;
    qreal arrowSize = 10;
};

#endif // EDGE_H
