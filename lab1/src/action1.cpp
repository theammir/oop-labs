#include "action1.h"
#include "action1_diag1.h"
#include "action1_diag2.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qapplication.h>
#include <qdialog.h>
#include <qlabel.h>
#include <qpointer.h>
#include <qpushbutton.h>
#include <qstring.h>

static auto run(QWidget *parent) -> bool {
  for (;;) {
    FirstDialog first(parent);
    if (first.exec() != QDialog::Accepted) {
      return false;
    }

    SecondDialog second(parent);
    const int result = second.exec();
    if (result == QDialog::Accepted) {
      return true;
    }
    if (result == SecondDialog::kBackCode) {
      continue;
    }
    return false;
  }
}

void action1_callback(bool checked) {
  QPointer<QWidget> parent = QApplication::activeWindow();
  (void)run(parent.data());
}
