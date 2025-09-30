#pragma once
#include "editor.h"
#include <QWidget>

class Canvas : public QWidget {
  Q_OBJECT
private:
  Editor *editor = nullptr;

protected:
  void paintEvent(QPaintEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;
  void mouseReleaseEvent(QMouseEvent *event) override;

public:
  explicit Canvas(QWidget *parent = nullptr);
  void set_editor(Editor *editor);
};
