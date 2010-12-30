// Copyright (C) 2009 Romain Goffe, Alexandre Dupas
//
// Songbook Creator is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Songbook Creator is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
// MA  02110-1301, USA.
//******************************************************************************

#ifndef __UTILS_HH__
#define __UTILS_HH__

#include <QString>

enum SbError { WrongDirectory, WrongExtension };

namespace SbUtils
{
  QString latexToUtf8(const QString & str);
  QString filenameToString(const QString & str);
  QString stringToFilename(const QString & str, const QString & sep);
}

#endif // __UTILS_HH__
