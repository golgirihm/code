#ifndef MYLAYOUT_H
#define MYLAYOUT_H

#include <QLayout>
#include <QRect>

class myLayout : public QLayout
{
public:
    enum Position { West, North, South, East, Center };
    Position POS_ARRAY[5] = { West, North, South, East, Center };

    explicit myLayout(QWidget *parent, int margin = 0, int spacing = -1);
    myLayout(int spacing = -1);
    ~myLayout();

    void addItem(QLayoutItem *item);
    void addWidget(QWidget *widget, Position position);
    Qt::Orientations expandingDirections() const;
    bool hasHeightForWidth() const;
    int count() const;
    QLayoutItem *itemAt(int index) const;
    QSize minimumSize() const;
    void setGeometry(const QRect &rect);
    QSize sizeHint() const;
    QLayoutItem *takeAt(int index);

    void add(QLayoutItem *item, Position position);

private:
    struct ItemWrapper
    {
        ItemWrapper(QLayoutItem *i, Position p) {
            item = i;
            position = p;
        }

        QLayoutItem *item;
        Position position;
    };

    enum SizeType { MinimumSize, SizeHint };
    QSize calculateSize(SizeType sizeType) const;

    QList<ItemWrapper *> list;
};

#endif // MYLAYOUT_H
