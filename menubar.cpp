#include "menubar.h"

#include <QEvent>
#include <QAction>

MenuBar::MenuBar(QWidget* parent)
    : QMenuBar(parent)
{
    auto* fileMenu = addMenu("File");
    auto* packageMenu = addMenu("Package");
    auto* configurationMenu = addMenu("Configuration");
    auto* dependencies = addMenu("Dependencies");
    auto* options = addMenu("Options");
    auto* extras = addMenu("Extras");
    auto* help = addMenu("Help");
}

bool MenuBar::event(QEvent* event)
{
    if (event->type() == QEvent::Leave)
    {
        setActiveAction(new QAction(this));
    }

    return QMenuBar::event(event);
}
