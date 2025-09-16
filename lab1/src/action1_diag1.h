#pragma once

#include <qdialog.h>
#include <qwidget.h>

class FirstDialog final : public QDialog {
  Q_OBJECT
public:
  FirstDialog(QWidget *parent = nullptr);
};
