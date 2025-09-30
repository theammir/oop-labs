#include "editor.h"
#include "canvas.h"
#include "shape.h"

static inline auto to_point(QMouseEvent *event) -> QPoint {
  return event->position().toPoint();
}

void PointEditor::on_mouse_down(QMouseEvent *event) {
  if (event->button() != Qt::LeftButton) {
    return;
  }
  drawing = true;
  cursor = to_point(event);
  if (canvas != nullptr) {
    canvas->update();
  }
}

void PointEditor::on_mouse_move(QMouseEvent *event) {
  if (!drawing) {
    return;
  }
  cursor = to_point(event);
  if (canvas != nullptr) {
    canvas->update();
  }
}

void PointEditor::on_mouse_up(QMouseEvent *event) {
  if (!drawing || event->button() != Qt::LeftButton) {
    return;
  }
  drawing = false;
  QPoint point = to_point(event);
  Shape::add_shape(new PointShape(point, point));
  if (canvas != nullptr) {
    canvas->update();
  }
}

void PointEditor::paint_preview(QPainter &painter) {
  if (!drawing) {
    return;
  }
  painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
  painter.setBrush(Qt::blue);
  const int r = 2;
  painter.drawEllipse(QRect(cursor.x() - r, cursor.y() - r, 2 * r, 2 * r));
}

void LineEditor::on_mouse_down(QMouseEvent *event) {
  if (event->button() != Qt::LeftButton) {
    return;
  }
  drawing = true;
  start = to_point(event);
  end = start;
  if (canvas != nullptr) {
    canvas->update();
  }
}

void LineEditor::on_mouse_move(QMouseEvent *event) {
  if (!drawing) {
    return;
  }
  end = to_point(event);
  if (canvas != nullptr) {
    canvas->update();
  }
}

void LineEditor::on_mouse_up(QMouseEvent *event) {
  if (!drawing || event->button() != Qt::LeftButton) {
    return;
  }
  drawing = false;
  end = to_point(event);
  Shape::add_shape(new LineShape(start, end));
  if (canvas != nullptr) {
    canvas->update();
  }
}

void LineEditor::paint_preview(QPainter &painter) {
  if (!drawing) {
    return;
  }
  painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
  painter.setBrush(Qt::NoBrush);
  painter.drawLine(start, end);
}

void RectEditor::on_mouse_down(QMouseEvent *event) {
  if (event->button() != Qt::LeftButton) {
    return;
  }
  drawing = true;
  start = to_point(event);
  end = start;
  if (canvas != nullptr) {
    canvas->update();
  }
}

void RectEditor::on_mouse_move(QMouseEvent *event) {
  if (!drawing) {
    return;
  }
  end = to_point(event);
  if (canvas != nullptr) {
    canvas->update();
  }
}

void RectEditor::on_mouse_up(QMouseEvent *event) {
  if (!drawing || event->button() != Qt::LeftButton) {
    return;
  }
  drawing = false;
  end = to_point(event);
  Shape::add_shape(new RectShape(start, end));
  if (canvas != nullptr) {
    canvas->update();
  }
}

void RectEditor::paint_preview(QPainter &painter) {
  if (!drawing) {
    return;
  }
  painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
  painter.setBrush(Qt::NoBrush);
  QRect rect = QRect(start, end).normalized();
  painter.drawRect(rect);
}

void EllipseEditor::on_mouse_down(QMouseEvent *event) {
  if (event->button() != Qt::LeftButton) {
    return;
  }
  drawing = true;
  center = to_point(event);
  corner = center;
  if (canvas != nullptr) {
    canvas->update();
  }
}

void EllipseEditor::on_mouse_move(QMouseEvent *event) {
  if (!drawing) {
    return;
  }
  corner = to_point(event);
  if (canvas != nullptr) {
    canvas->update();
  }
}

void EllipseEditor::on_mouse_up(QMouseEvent *event) {
  if (!drawing || event->button() != Qt::LeftButton) {
    return;
  }
  drawing = false;
  corner = to_point(event);
  Shape::add_shape(new EllipseShape(center, corner));
  if (canvas != nullptr) {
    canvas->update();
  }
}

void EllipseEditor::paint_preview(QPainter &painter) {
  if (!drawing) {
    return;
  }
  painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine));
  painter.setBrush(Qt::NoBrush);
  int rect_x = std::abs(corner.x() - center.x());
  int rect_y = std::abs(corner.y() - center.y());
  QRect rect(center.x() - rect_x, center.y() - rect_y, 2 * rect_x, 2 * rect_y);
  painter.drawEllipse(rect);
}
