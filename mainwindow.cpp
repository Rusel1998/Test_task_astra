#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QString path = QDir::homePath();

    model = new MyFileSystemModel(this);
    model->setRootPath(path);
    model->setFilter(QDir::AllDirs | QDir::Hidden | QDir::Files);

    tree = new QTreeView(this);
    tree->setModel(model);
    tree->setSortingEnabled(true);
    tree->setRootIndex(model->index(path));
    tree->setAlternatingRowColors(true);
    tree->header()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tree->header()->setStretchLastSection(true);

    NameFilterLabel = new QLabel("Отфильтровать по названию");
    NameFilterLineEdit = new QLineEdit("");

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(tree,0,0,1,5);
    mainLayout->addWidget(NameFilterLabel,1,3,1,1);
    mainLayout->addWidget(NameFilterLineEdit,1,4,1,1);

    QWidget* widget = new QWidget(this);
    widget->setLayout(mainLayout);
    setCentralWidget(widget);

    setWindowTitle(tr("Отображение дерева файловой системы с фильтром по именам"));
    resize(800, 600);

    QObject::connect(NameFilterLineEdit, SIGNAL(textChanged(QString)),
                     model, SLOT(identifyPathsOfName(QString)));
}
