#include "action1_diag1.h"
#include <qboxlayout.h>
#include <qlabel.h>
#include <qpushbutton.h>

FirstDialog::FirstDialog(QWidget *parent) : QDialog(parent) {
  setWindowTitle("Крок 1");

  auto *vbox = new QVBoxLayout(this);
  auto *label = new QLabel("Перше діалогове вікно", this);
  vbox->addWidget(label);

  auto *hbox = new QHBoxLayout();
  auto *btn_next = new QPushButton("Далі >", this);
  auto *btn_cancel = new QPushButton("Відміна", this);
  hbox->addStretch();
  hbox->addWidget(btn_next);
  hbox->addWidget(btn_cancel);
  vbox->addLayout(hbox);

  connect(btn_next, &QPushButton::clicked, this, &QDialog::accept);
  connect(btn_cancel, &QPushButton::clicked, this, &QDialog::reject);
}
