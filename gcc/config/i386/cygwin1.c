/* Helper routines for cygwin-specific command-line parsing.
   Contributed by Christopher Faylor (cgf@redhat.com)
   Copyright 2003 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include <string.h>

void
mingw_scan (argc, argv, spec_machine)
    int argc ATTRIBUTE_UNUSED;
    const char *const *argv;
    char **spec_machine;
{
  putenv ("GCC_CYGWIN_MINGW=0");
 
  while (*++argv)
    if (strcmp (*argv, "-mno-win32") == 0)
      putenv ("GCC_CYGWIN_WIN32=0");
    else if (strcmp (*argv, "-mwin32") == 0)
      putenv ("GCC_CYGWIN_WIN32=1");
    else if (strcmp (*argv, "-mno-cygwin") == 0)
      {
	char *p = strstr (*spec_machine, "-cygwin");
	if (p)
	  {
	    int len = p - *spec_machine;
	    char *s = xmalloc (strlen (*spec_machine) + 3);
	    memcpy (s, *spec_machine, len);
	    strcpy (s + len, "-mingw32");
	    *spec_machine = s;
	  }
	putenv ("GCC_CYGWIN_MINGW=1");
      }
  return;
}
