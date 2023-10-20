QT += widgets
requires(qtConfig(treeview))

SOURCES       = main.cpp \
    mainwindow.cpp \
    myfilesystemmodel.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/dirview
INSTALLS += target

HEADERS += \
    mainwindow.h \
    myfilesystemmodel.h

DISTFILES += \
    README.txt
