#ifndef QTQMAKEWATCHERMENUDIALOG_H
#define QTQMAKEWATCHERMENUDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qthideandshowdialog.h"
#pragma GCC diagnostic pop

namespace Ui {
  class QtQmakeWatcherMenuDialog;
}

namespace ribi {

class QtQmakeWatcherMenuDialog : public QtHideAndShowDialog
{
  Q_OBJECT //!OCLINT

public:
  explicit QtQmakeWatcherMenuDialog(QWidget *parent = 0) noexcept;
  QtQmakeWatcherMenuDialog(const QtQmakeWatcherMenuDialog&) = delete;
  QtQmakeWatcherMenuDialog& operator=(const QtQmakeWatcherMenuDialog&) = delete;
  ~QtQmakeWatcherMenuDialog() noexcept;

protected:
  void keyPressEvent(QKeyEvent * event) noexcept;

private:
  Ui::QtQmakeWatcherMenuDialog *ui;

private slots:
  void on_button_about_clicked() noexcept;
  void on_button_quit_clicked() noexcept;
  void on_button_start_clicked() noexcept;
};

} //~namespace ribi

#endif // QTQMAKEWATCHERMENUDIALOG_H
