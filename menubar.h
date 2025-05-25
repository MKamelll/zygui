#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QWidget>
#include <QEvent>

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit MenuBar(QWidget* parent = nullptr);

protected:
    bool event(QEvent* event) override;
};

#endif // MENUBAR_H
