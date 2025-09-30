#include "canvas.h"
#include "editor.h"
#include <QActionGroup>
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>

class MainWindow : public QMainWindow {
  Q_OBJECT
private:
  Canvas *canvas = nullptr;

  PointEditor point_editor;
  LineEditor line_editor;
  RectEditor rect_editor;
  EllipseEditor ellipse_editor;

public:
  MainWindow() {
    canvas = new Canvas(this);
    setCentralWidget(canvas);

    menuBar()->addMenu("Файл");
    auto *menu = menuBar()->addMenu("&Oб'єкти");
    menuBar()->addMenu("Довідка");

    auto *action_point = new QAction("&Tочка", this);
    auto *action_line = new QAction("Л&iнія", this);
    auto *action_rect = new QAction("П&pямокутник", this);
    auto *action_ellipse = new QAction("&Eліпс", this);

    action_point->setCheckable(true);
    action_line->setCheckable(true);
    action_rect->setCheckable(true);
    action_ellipse->setCheckable(true);

    auto *group = new QActionGroup(this);
    group->setExclusive(true);
    group->addAction(action_point);
    group->addAction(action_line);
    group->addAction(action_rect);
    group->addAction(action_ellipse);

    menu->addAction(action_point);
    menu->addAction(action_line);
    menu->addAction(action_rect);
    menu->addAction(action_ellipse);

    connect(action_point, &QAction::triggered, this,
            [this] { canvas->set_editor(&point_editor); });
    connect(action_line, &QAction::triggered, this,
            [this] { canvas->set_editor(&line_editor); });
    connect(action_rect, &QAction::triggered, this,
            [this] { canvas->set_editor(&rect_editor); });
    connect(action_ellipse, &QAction::triggered, this,
            [this] { canvas->set_editor(&ellipse_editor); });

    action_point->setChecked(true);
    canvas->set_editor(&point_editor);

    resize(1000, 700);
    setWindowTitle("Лабораторна робота №2");
  }
};

#include "main.moc"

auto main(int argc, char *argv[]) -> int {
  QApplication app(argc, argv);
  MainWindow window;
  window.show();
  return QApplication::exec();
}

// vim: sw=2 ts=2
