#include "action1.h"
#include "action2.h"
#include <qaction.h>
#include <qapplication.h>
#include <qlabel.h>
#include <qmainwindow.h>
#include <qmenubar.h>
#include <qnamespace.h>
#include <qobject.h>
#include <qstatusbar.h>
#include <qtmetamacros.h>

#define WINWIDTH 360
#define WINHEIGHT 120

class MainWindow final : public QMainWindow {
  Q_OBJECT
private:
  QLabel *label = new QLabel("Лабораторна робота №1");

public:
  MainWindow() {
    auto *menu = menuBar()->addMenu("&Mеню");
    auto *action1 = menu->addAction("Робота &1");
    auto *action2 = menu->addAction("Робота &2");

    connect(action1, &QAction::triggered, this, action1_callback);
    connect(action2, &QAction::triggered, this, [this] {
      QString chosen = action2_callback();
      label->setText(chosen);
    });

    label->setAlignment(Qt::AlignCenter);
    auto font = label->font();
    font.setPointSize(20);
    font.setBold(true);
    label->setFont(font);

    setCentralWidget(label);
  }
};

auto main(int argc, char *argv[]) -> int {
  QApplication app(argc, argv);
  MainWindow win;
  win.resize(WINWIDTH, WINHEIGHT);
  win.show();

  return QApplication::exec();
}

#include "main.moc"
