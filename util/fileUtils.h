/*******************************************************************************
*                                                                              *
* fileUtils.h -- Nirvana Editor File Utilities Header File                     *
*                                                                              *
* Copyright 2003 The NEdit Developers                                          *
*                                                                              *
* This is free software; you can redistribute it and/or modify it under the    *
* terms of the GNU General Public License as published by the Free Software    *
* Foundation; either version 2 of the License, or (at your option) any later   *
* version. In addition, you may distribute versions of this program linked to  *
* Motif or Open Motif. See README for details.                                 *
*                                                                              *
* This software is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or        *
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for    *
* more details.                                                                *
*                                                                              *
* You should have received a copy of the GNU General Public License along with *
* software; if not, write to the Free Software Foundation, Inc., 59 Temple     *
* Place, Suite 330, Boston, MA  02111-1307 USA                                 *
*                                                                              *
* Nirvana Text Editor                                                          *
* July 31, 2001                                                                *
*                                                                              *
*******************************************************************************/

#ifndef FILEUTILS_H_
#define FILEUTILS_H_

#include <string>
#include "string_view.h"
#include "FileFormats.h"

class QString;

bool ConvertToDosFileStringEx(std::string &fileString);
FileFormats FormatOfFileEx(view::string_view fileString);
int CompressPathname(char *pathname);
int NormalizePathname(char *pathname);
int ParseFilenameEx(const QString &fullname, QString *filename, QString *pathname);
QString ExpandTildeEx(const QString &pathname);
QString GetTrailingPathComponentsEx(const QString &path, int noOfComponents);
QString ReadAnyTextFileEx(const QString &fileName, bool forceNL);
QString ResolvePathEx(const QString &pathname);
void ConvertFromDosFileString(char *inString, int *length, char *pendingCR);
void ConvertFromMacFileString(char *fileString, int length);
void ConvertToMacFileStringEx(std::string &fileString);

QString NormalizePathnameEx(const QString &pathname);
QString NormalizePathnameEx(const std::string &pathname);

#endif
