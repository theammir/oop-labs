#pragma once
#include <QMouseEvent>
#include <QPainter>

class Canvas;

class Editor {
protected:
  Canvas *canvas = nullptr;

public:
  virtual ~Editor() = default;
  virtual void on_mouse_down(QMouseEvent *event) = 0;
  virtual void on_mouse_move(QMouseEvent *event) = 0;
  virtual void on_mouse_up(QMouseEvent *event) = 0;
  virtual void paint_preview(QPainter &painter) = 0;
  void set_canvas(Canvas *canvas_) { canvas = canvas_; }
};

class PointEditor : public Editor {
public:
  void on_mouse_down(QMouseEvent *event) override;
  void on_mouse_move(QMouseEvent *event) override;
  void on_mouse_up(QMouseEvent *event) override;
  void paint_preview(QPainter &painter) override;

private:
  bool drawing = false;
  QPoint cursor;
};

class LineEditor : public Editor {
public:
  void on_mouse_down(QMouseEvent *event) override;
  void on_mouse_move(QMouseEvent *event) override;
  void on_mouse_up(QMouseEvent *event) override;
  void paint_preview(QPainter &painter) override;

private:
  bool drawing = false;
  QPoint start;
  QPoint end;
};

class RectEditor : public Editor {
public:
  void on_mouse_down(QMouseEvent *event) override;
  void on_mouse_move(QMouseEvent *event) override;
  void on_mouse_up(QMouseEvent *event) override;
  void paint_preview(QPainter &painter) override;

private:
  bool drawing = false;
  QPoint start;
  QPoint end;
};

class EllipseEditor : public Editor {
public:
  void on_mouse_down(QMouseEvent *event) override;
  void on_mouse_move(QMouseEvent *event) override;
  void on_mouse_up(QMouseEvent *event) override;
  void paint_preview(QPainter &painter) override;

private:
  bool drawing = false;
  QPoint center;
  QPoint corner;
};
