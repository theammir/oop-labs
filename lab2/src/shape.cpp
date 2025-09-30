#include "shape.h"

void PointShape::show(QPainter &painter) {
  QPen pen(Qt::black);
  painter.setPen(pen);
  painter.setBrush(Qt::black);
  const int r = 2;
  painter.drawEllipse(QRect(start.x() - r, start.y() - r, 2 * r, 2 * r));
}

void LineShape::show(QPainter &painter) {
  QPen pen(Qt::black);
  painter.setPen(pen);
  painter.setBrush(Qt::NoBrush);
  painter.drawLine(start, end);
}

void RectShape::show(QPainter &painter) {
  QPen pen(Qt::black);
  painter.setPen(pen);
  painter.setBrush(QColor(173, 216, 230));
  QRect rect = QRect(start, end).normalized();
  painter.drawRect(rect);
}

void EllipseShape::show(QPainter &painter) {
  QPen pen(Qt::black);
  painter.setPen(pen);
  painter.setBrush(Qt::white);
  int rect_x = std::abs(end.x() - start.x());
  int rect_y = std::abs(end.y() - start.y());
  QRect rect(start.x() - rect_x, start.y() - rect_y, 2 * rect_x, 2 * rect_y);
  painter.drawEllipse(rect);
}
