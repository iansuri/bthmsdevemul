/**
 *   This file is part of Bluetooth for Microsoft Device Emulator
 * 
 *   Copyright (C)-2009 2008 Dmitry Klionsky aka ten0s <dm.klionsky@gmail.com>
 *   
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __DEBUG_OUTPUT_H__
#define __DEBUG_OUTPUT_H__

#include <windows.h>

class DebugOutput
{
   enum { MAX_LENGTH = 1024 };

public:
   DebugOutput( LPCTSTR szHeader );
   void Print( LPCTSTR szFormat, ... );

private:
   TCHAR _szHeader[MAX_LENGTH];
};

#endif //__DEBUG_OUTPUT_H__