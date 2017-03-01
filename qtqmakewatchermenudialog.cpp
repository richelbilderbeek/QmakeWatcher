#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#include "qtqmakewatchermenudialog.h"

#include <QDesktopWidget>
#include <QKeyEvent>

#include "qmakewatchermenudialog.h"
#include "qtaboutdialog.h"
#include "qtqmakewatchermaindialog.h"
#include "qthideandshowdialog.h"
#include "ui_qtqmakewatchermenudialog.h"
#pragma GCC diagnostic pop

ribi::QtQmakeWatcherMenuDialog::QtQmakeWatcherMenuDialog(QWidget *parent) noexcept :
    QtHideAndShowDialog(parent),
    ui(new Ui::QtQmakeWatcherMenuDialog)
{
  ui->setupUi(this);
}

ribi::QtQmakeWatcherMenuDialog::~QtQmakeWatcherMenuDialog() noexcept
{
  delete ui;
}

void ribi::QtQmakeWatcherMenuDialog::keyPressEvent(QKeyEvent * event) noexcept
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void ribi::QtQmakeWatcherMenuDialog::on_button_about_clicked() noexcept
{
  ribi::About a = ribi::QmakeWatcherMenuDialog().GetAbout();
  a.AddLibrary("QtHideAndShowDialog version: " + QtHideAndShowDialog::GetVersion());
  ribi::QtAboutDialog d(a);
  d.setWindowIcon(this->windowIcon());
  d.setStyleSheet(this->styleSheet());
  this->ShowChild(&d);
}

void ribi::QtQmakeWatcherMenuDialog::on_button_quit_clicked() noexcept
{
  close();
}

void ribi::QtQmakeWatcherMenuDialog::on_button_start_clicked() noexcept
{
  QtQmakeWatcherMainDialog d;
  ShowChild(&d);
}

