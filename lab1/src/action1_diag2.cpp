#include "action1_diag2.h"
#include <qboxlayout.h>
#include <qdialog.h>
#include <qlabel.h>
#include <qpushbutton.h>
#include <qwidget.h>

SecondDialog::SecondDialog(QWidget *parent) : QDialog(parent) {
  setWindowTitle("Крок 2");

  auto *vbox = new QVBoxLayout(this);
  auto *label = new QLabel("Друге діалогове вікно", this);
  vbox->addWidget(label);

  auto *hbox = new QHBoxLayout();
  auto *btn_back = new QPushButton("< Назад", this);
  auto *btn_yes = new QPushButton("Так", this);
  auto *btn_cancel = new QPushButton("Відміна", this);
  hbox->addStretch();
  hbox->addWidget(btn_back);
  hbox->addWidget(btn_yes);
  hbox->addWidget(btn_cancel);
  vbox->addLayout(hbox);

  connect(btn_back, &QPushButton::clicked, this, [this]() { done(kBackCode); });
  connect(btn_yes, &QPushButton::clicked, this, &QDialog::accept);
  connect(btn_cancel, &QPushButton::clicked, this, &QDialog::reject);
}
