#ifndef QTQMAKEWATCHERMAINDIALOG_H
#define QTQMAKEWATCHERMAINDIALOG_H

#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qthideandshowdialog.h"
#pragma GCC diagnostic pop

namespace Ui {
  class QtQmakeWatcherMainDialog;
}

namespace ribi {

class QtQmakeWatcherMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT

public:
  explicit QtQmakeWatcherMainDialog(QWidget *parent = nullptr);
  QtQmakeWatcherMainDialog(const QtQmakeWatcherMainDialog&) = delete;
  QtQmakeWatcherMainDialog& operator=(const QtQmakeWatcherMainDialog&) = delete;
  ~QtQmakeWatcherMainDialog() noexcept;

private:
  Ui::QtQmakeWatcherMainDialog *ui;


private slots:
  void OnQmake();
};

} //~namespace ribi

#endif // QTQMAKEWATCHERMAINDIALOG_H
