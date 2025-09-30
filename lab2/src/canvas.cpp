#include "canvas.h"
#include "shape.h"
#include <QPaintEvent>
#include <QPainter>
#include <qcolor.h>

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
  setMouseTracking(true);
  setMinimumSize(800, 600);
}

void Canvas::set_editor(Editor *editor_) {
  editor = editor_;
  if (editor != nullptr) {
    editor->set_canvas(this);
  }
}

void Canvas::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  painter.fillRect(rect(), QColor(255, 255, 255));

  Shape::render_all(painter);
  if (editor != nullptr) {
    editor->paint_preview(painter);
  }
}

void Canvas::mousePressEvent(QMouseEvent *event) {
  if (editor != nullptr) {
    editor->on_mouse_down(event);
  }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
  if (editor != nullptr) {
    editor->on_mouse_move(event);
  }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
  if (editor != nullptr) {
    editor->on_mouse_up(event);
  }
}
