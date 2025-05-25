#include "mainwindow.h"
#include "menubar.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QCheckBox>
#include <QLabel>
#include <QComboBox>
#include <Qt>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QAbstractItemView>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Zygui");
    setMinimumSize(800, 480);
    setMenuBar(new MenuBar(this));

    auto* central = new QWidget(this);
    auto* mainLayout = new QHBoxLayout(central);

    auto* vbox = new QVBoxLayout;

    auto* viewDropDown = new QComboBox;
    viewDropDown->addItems({"View",
                            "Patterns",
                            "Package Classification",
                            "Languages",
                            "Repositories",
                            "Services",
                            "Search",
                            "Installation Summary"
                           });
    vbox->addWidget(viewDropDown);

    auto* searchInLabel = new QLabel("Search in");
    vbox->addWidget(searchInLabel);

    auto* nameCheckBox = new QCheckBox("Name");
    nameCheckBox->setChecked(true);
    auto* keywordsCheckBox = new QCheckBox("Keywords");
    keywordsCheckBox->setChecked(true);
    auto* summaryCheckBox = new QCheckBox("Summary");
    summaryCheckBox->setChecked(true);

    auto* descriptionCheckBox = new QCheckBox("Description");
    auto* rpmProvidesCheckBox = new QCheckBox("RPM \"Provides\"");
    auto* rpmRequiresCheckBox = new QCheckBox("RPM \"Requires\"");
    auto* fileListCheckBox = new QCheckBox("File List");

    vbox->addWidget(nameCheckBox);
    vbox->addWidget(keywordsCheckBox);
    vbox->addWidget(summaryCheckBox);
    vbox->addWidget(descriptionCheckBox);
    vbox->addWidget(rpmProvidesCheckBox);
    vbox->addWidget(rpmRequiresCheckBox);
    vbox->addWidget(fileListCheckBox);

    auto* searchModeDropDown = new QComboBox;
    searchModeDropDown->addItems({"Contains",
                                  "Begins With",
                                  "Exact Match",
                                  "Use Wild Cards",
                                  "Use Regular Expression"
                                 });

    vbox->addWidget(searchModeDropDown);

    auto* caseSensitiveCheckBox = new QCheckBox("Case Sensitive");
    vbox->addWidget(caseSensitiveCheckBox);

    vbox->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    mainLayout->addLayout(vbox);

    auto* model = new QStandardItemModel(0, 4);
    model->setHeaderData(0, Qt::Horizontal, "Package");
    model->setHeaderData(1, Qt::Horizontal, "Summary");
    model->setHeaderData(2, Qt::Horizontal, "Installed(Available)");
    model->setHeaderData(3, Qt::Horizontal, "Size");

    auto* tabs = new QTabWidget;
    auto tabsNames = {
        QString("Search"),
        QString("Installation Summary"),
        QString("Patterns")
    };

    foreach (auto& tabName, tabsNames) {
        auto* packagesTable = new QTableView;
        packagesTable->setModel(model);
        packagesTable->setSortingEnabled(true);
        packagesTable->horizontalHeader()->setSectionsClickable(true);
        packagesTable->horizontalHeader()->setSortIndicatorShown(true);
        packagesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        packagesTable->verticalHeader()->hide();
        packagesTable->setShowGrid(false);
        packagesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        packagesTable->setSelectionMode(QAbstractItemView::SingleSelection);

        auto* widget = new QWidget;
        auto* vbox = new QVBoxLayout(widget);
        vbox->addWidget(packagesTable);
        tabs->addTab(widget, tabName);
    }

    mainLayout->addWidget(tabs);

    setCentralWidget(central);
}

MainWindow::~MainWindow()
{
}


