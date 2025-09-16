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
  auto *btnBack = new QPushButton("< Назад", this);
  auto *btnYes = new QPushButton("Так", this);
  auto *btnCancel = new QPushButton("Відміна", this);
  hbox->addStretch();
  hbox->addWidget(btnBack);
  hbox->addWidget(btnYes);
  hbox->addWidget(btnCancel);
  vbox->addLayout(hbox);

  connect(btnBack, &QPushButton::clicked, this, [this]() { done(kBackCode); });
  connect(btnYes, &QPushButton::clicked, this, &QDialog::accept);
  connect(btnCancel, &QPushButton::clicked, this, &QDialog::reject);
}
