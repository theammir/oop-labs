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
  auto *btnNext = new QPushButton("Далі >", this);
  auto *btnCancel = new QPushButton("Відміна", this);
  hbox->addStretch();
  hbox->addWidget(btnNext);
  hbox->addWidget(btnCancel);
  vbox->addLayout(hbox);

  connect(btnNext, &QPushButton::clicked, this, &QDialog::accept);
  connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}
