#include "qtqmakewatchermaindialog.h"

#include <cassert>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

#include <QDesktopWidget>
#include <QFile>

#include "fileio.h"
#include "ui_qtqmakewatchermaindialog.h"

ribi::QtQmakeWatcherMainDialog::QtQmakeWatcherMainDialog(QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtQmakeWatcherMainDialog)
{
  ui->setupUi(this);
  ui->edit_pro->setWordWrapMode(QTextOption::NoWrap);
  ui->edit_makefile->setWordWrapMode(QTextOption::NoWrap);
  ui->edit_diff->setWordWrapMode(QTextOption::NoWrap);

  QObject::connect(ui->button_qmake,&QPushButton::clicked,
    this,&ribi::QtQmakeWatcherMainDialog::OnQmake
  );



  //Put the dialog in the screen center
  const QRect screen = QApplication::desktop()->screenGeometry();
  this->setGeometry(0,0,screen.width() * 8 / 10,screen.height() * 8 / 10);
  this->move( screen.center() - this->rect().center() );
}

ribi::QtQmakeWatcherMainDialog::~QtQmakeWatcherMainDialog() noexcept
{
  delete ui;
}

void ribi::QtQmakeWatcherMainDialog::OnQmake()
{
  //Save text to file
  {
    const std::string s = ui->edit_pro->document()->toPlainText().toStdString();
    std::ofstream f("tmp.pro");
    f << s << '\n';
  }
  //Execute commands
  {
    const bool has_error = std::system("cp Makefile oldmake");
    assert(!has_error);
    if (has_error) throw std::runtime_error("'cp Makefile oldmake' failed");
  }
  {
    const bool has_error = std::system("qmake tmp.pro");
    assert(!has_error);
    if (has_error) throw std::runtime_error("'qmake tmp.pro' failed");
  }
  bool has_diff = true;
  {
    const bool has_error = std::system("diff Makefile oldmake > tmp.txt");
    if (has_error) has_diff = false;
  }
  //Display Makefile
  {
    ui->edit_makefile->clear();
    const std::vector<std::string> v(ribi::fileio::FileIo().FileToVector("Makefile"));
    for(const std::string& s: v)
    {
      ui->edit_makefile->appendPlainText(QString(s.c_str()));
    }
  }
  //Display diff
  ui->edit_diff->setPlainText("No diff");
  if (has_diff)
  {
    ui->edit_diff->clear();
    const std::vector<std::string> v(ribi::fileio::FileIo().FileToVector("tmp.txt"));
    for(const std::string& s: v)
    {
      std::string t = s;
      if (!s.empty() && s[0] == '>')
      {
        //Old
        t = "<font color=#0000FF>&lt;"
          + s.substr(1,s.size()-1)
          + "</font>";
      }
      if (!s.empty() && s[0] == '<')
      {
        //New
        t = "<b><font color=#FF0000>&gt;"
          + s.substr(1,s.size()-1)
          + "</font></b>";
      }
      ui->edit_diff->appendHtml(QString(t.c_str()));
    }
  }
}

