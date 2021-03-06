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
#ifndef __BUILD_ENGINE_HH__
#define __BUILD_ENGINE_HH__

#include <QWidget>
#include <QString>
#include <QProcess>

class QDialog;
class QDialogButtonBox;
class CMainWindow;

class CBuildEngine : public QWidget
{
  Q_OBJECT
  
  public:
  CBuildEngine(CMainWindow* parent=NULL);
  				
public slots:
  virtual void processExit(int exitCode, QProcess::ExitStatus exitStatus);
  virtual void processError(QProcess::ProcessError error);
  virtual void readProcessOut();
  
  virtual void dialog();
  virtual void action();
 
  virtual void setWorkingPath(QString);
 
public:
  virtual QWidget* mainWidget()=0;
  virtual CMainWindow* parent();
  
  virtual QString processName() const;
  virtual void setProcessName(const QString & value);

  virtual QString windowTitle() const;
  virtual void setWindowTitle(const QString & value);
  
  virtual QString statusSuccessMessage() const;
  virtual void setStatusSuccessMessage(const QString & value);

  virtual QString statusErrorMessage() const;
  virtual void setStatusErrorMessage(const QString & value);

  virtual QString statusActionMessage() const;
  virtual void setStatusActionMessage(const QString & value);

  virtual QStringList processOptions() const;
  virtual void setProcessOptions(const QStringList & value);
  
  virtual QProcess* process() const;

  virtual QString workingPath() const;
    
private:
  CMainWindow* m_parent;
  QProcess* m_process;
  QDialog* m_dialog;
  QString m_workingPath;
  
  QString m_processName;
  QString m_windowTitle;
  QString m_statusActionMessage;
  QString m_statusSuccessMessage;
  QString m_statusErrorMessage;
  QStringList m_processOptions;

};
#endif // __BUILD_ENGINE_HH__
