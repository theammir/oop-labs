#include "action2.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qapplication.h>
#include <qdialog.h>
#include <qkeysequence.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qmainwindow.h>
#include <qpointer.h>
#include <qpushbutton.h>
#include <qstatusbar.h>
#include <qstringlist.h>

class GroupListDialog final : public QDialog {
  Q_OBJECT
public:
  explicit GroupListDialog(QWidget *parent = nullptr) : QDialog(parent) {
    setWindowTitle("Вибір групи");

    auto *vbox = new QVBoxLayout(this);
    auto *label = new QLabel("Оберіть групу факультету:", this);
    vbox->addWidget(label);

    list = new QListWidget(this);
    list->setSelectionMode(QAbstractItemView::SingleSelection);
    vbox->addWidget(list);

    const QStringList groups = {"ІМ-41", "ІМ-42", "ІМ-43", "ІМ-44", "ІС-43"};
    list->addItems(groups);

    auto *hbox = new QHBoxLayout();
    btn_yes = new QPushButton("Так", this);
    auto *btn_cancel = new QPushButton("Відміна", this);
    btn_yes->setEnabled(false);

    hbox->addStretch();
    hbox->addWidget(btn_yes);
    hbox->addWidget(btn_cancel);
    vbox->addLayout(hbox);

    connect(list, &QListWidget::currentRowChanged, this,
            [this](int row) { btn_yes->setEnabled(row >= 0); });
    connect(btn_yes, &QPushButton::clicked, this, &QDialog::accept);
    connect(btn_cancel, &QPushButton::clicked, this, &QDialog::reject);
  }

  QString selectedGroup() const {
    if (auto *item = list->currentItem())
      return item->text();
    return {};
  }

private:
  QListWidget *list = nullptr;
  QPushButton *btn_yes = nullptr;
};

auto action2_callback(bool) -> QString {
  QPointer<QWidget> mainWin = QApplication::activeWindow();

  GroupListDialog dlg(mainWin.data());
  if (dlg.exec() == QDialog::Accepted) {
    const QString chosen = dlg.selectedGroup();
    return "Вибрано групу: " + chosen;
  }
  return "Лабораторна робота №1";
}

#include "action2.moc"
