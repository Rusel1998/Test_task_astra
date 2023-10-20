#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QHeaderView>
#include "myfilesystemmodel.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QTreeView *tree;
    MyFileSystemModel *model;

    QLabel* NameFilterLabel;
    QLineEdit* NameFilterLineEdit;
};

#endif // MAINWINDOW_H
