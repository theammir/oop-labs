#pragma once
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <array>

class Shape {
protected:
  QPoint start;
  QPoint end;

public:
  static inline std::array<Shape *, 126> shapes{};
  static inline int shapes_len = 0;

  Shape(QPoint start, QPoint end) : start(start), end(end) {}
  virtual ~Shape() = default;
  virtual void show(QPainter &painter) = 0;

  static void add_shape(Shape *shape) {
    if (shapes_len < 126) {
      shapes[shapes_len++] = shape;
    }
  }

  static void render_all(QPainter &painter) {
    for (int i = 0; i < shapes_len; ++i) {
      if (shapes[i] != nullptr) {
        shapes[i]->show(painter);
      }
    }
  }
};

class PointShape : public Shape {
public:
  using Shape::Shape;
  void show(QPainter &painter) override;
};

class LineShape : public Shape {
public:
  using Shape::Shape;
  void show(QPainter &painter) override;
};

class RectShape : public Shape {
public:
  using Shape::Shape;
  void show(QPainter &painter) override;
};

class EllipseShape : public Shape {
public:
  using Shape::Shape;
  void show(QPainter &painter) override;
};
