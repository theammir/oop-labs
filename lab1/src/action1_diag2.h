#pragma once

#include <qdialog.h>
#include <qwidget.h>

class SecondDialog final : public QDialog {
  Q_OBJECT
public:
  SecondDialog(QWidget *parent = nullptr);
  const static int kBackCode = 1001;
};
