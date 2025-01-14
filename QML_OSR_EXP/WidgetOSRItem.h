#ifndef WIDGETOSRITEM_H
#define WIDGETOSRITEM_H

#include <QQuickPaintedItem>

class WidgetOSRItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QVariant osrWidget WRITE setOSRWidget)
public:
    WidgetOSRItem();

    void setOSRWidget(QVariant w); //* 加入要渲染的widget，不维护这个weiget的生命周期, var -->> QWidget*
    bool sendEventToOSRWidget(QEvent* e); //* 给widget发送事件

    virtual void paint(QPainter *painter) override; //重载paint函数

protected:
    virtual bool eventFilter(QObject* obj, QEvent* e) override;

    //当item改变大小位置的时候在这里同步改变OSRWidget的位置和大小
#if (QT_VERSION >= QT_VERSION_CHECK(6,0,0))
    virtual void geometryChange(const QRectF &newGeometry, const QRectF &oldGeometry) override;
#else
    virtual void geometryChanged(const QRectF & newGeometry, const QRectF & oldGeometry) override;
#endif
    virtual bool event(QEvent *e) override; //*只有通过这个函数处理的才会转成对应的Event,在这里过滤消息

private:
    QWidget* mOSRWidget;
};

#endif // WIDGETOSRITEM_H
