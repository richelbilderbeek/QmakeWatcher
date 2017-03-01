#include "qmakewatchermenudialog.h"

#include <iostream>

int ribi::QmakeWatcherMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 0;
  }
  return 0;
}

ribi::About ribi::QmakeWatcherMenuDialog::GetAbout() const noexcept
{
  ribi::About a {
    "Richel Bilderbeek",
    "QmakeWatcher",
    "tool to watch qmake's .pro to Makefile conversion",
    "November 21st of 2015",
    "2010-2015",
    "http://www.richelbilderbeek.nl/ToolQmakeWatcher.htm",
    GetVersion(),
    GetVersionHistory()
  };
  return a;
}

ribi::Help ribi::QmakeWatcherMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}

std::string ribi::QmakeWatcherMenuDialog::GetVersion() const noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::QmakeWatcherMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2013-09-20: version 1.0: initial version, conformized for ProjectRichelBilderbeek",
    "2013-11-04: version 1.1: conformized for ProjectRichelBilderbeekConsole",
    "2015-11-21: version 2.0: moved to own GitHub",
  };
}
