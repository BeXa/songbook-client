// Copyright (C) 2009-2011, Romain Goffe <romain.goffe@gmail.com>
// Copyright (C) 2009-2011, Alexandre Dupas <alexandre.dupas@gmail.com>
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
// 02110-1301, USA.
//******************************************************************************
#include <QtGui>
#include "make-songbook.hh"

CMakeSongbook::CMakeSongbook(CMainWindow* AParent)
  : CBuildEngine(AParent)
{
#ifdef Q_WS_WIN
  setProcessName("cmd.exe");
#else
  setProcessName("make");
  QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
  env.insert("LATEX_OPTIONS", "-halt-on-error");
  process()->setProcessEnvironment(env);
#endif
}

QWidget* CMakeSongbook::mainWidget()
{
  return NULL;
}

void CMakeSongbook::setProcessOptions(const QStringList & value)
{
  if(value.contains("clean") || value.contains("cleanall") || value.contains("clean.bat"))
    {
      setStatusActionMessage(tr("Removing temporary LaTeX files. Please wait..."));
      setStatusSuccessMessage(tr("Cleaning completed."));
      setStatusErrorMessage(tr("An error occured during the cleaning operation."));
    }
  else
    {
      setStatusActionMessage(tr("Building the songbook. Please wait..."));
      setStatusSuccessMessage(tr("Songbook successfully generated."));
      setStatusErrorMessage(tr("An error occured during the songbook generation.\n " 
			       "You may check compilation logs for more information."));
    }
  CBuildEngine::setProcessOptions(value);
}

//------------------------------------------------------------------------------
void CMakeSongbook::processExit(int exitCode, QProcess::ExitStatus exitStatus)
{
  if (exitStatus == QProcess::NormalExit && exitCode==0)
    {
      QString target;
#ifdef Q_WS_WIN
      if(processOptions().at(1).startsWith("make"))
        target = QString("file:///%1/%2.pdf").arg(workingPath()).arg(processOptions().at(2));
#else
      target = QString("file:///%1/%2").arg(workingPath()).arg(processOptions().at(0));
#endif
      if(target.endsWith("pdf"))
	QDesktopServices::openUrl(QUrl(target));
    }
  CBuildEngine::processExit(exitCode, exitStatus);
}
