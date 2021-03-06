// Mutex.hh --- Mutex synchronization
//
// Copyright (C) 2001, 2002, 2003 Rob Caelers <robc@krandor.org>
// All rights reserved.
//
// Time-stamp: <2003-01-05 00:41:28 robc>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// $Id$
//

#ifndef MUTEX_HH
#define MUTEX_HH

#include <windows.h>

/*!
 * A Mutex class.
 */
class Mutex 
{
protected:
  //! The window critical section.
  CRITICAL_SECTION critical_section;

public:
  //! Constructor.
  Mutex()
  {
    InitializeCriticalSection(&critical_section);
  }

  //! Destructor
  ~Mutex()
  {
    DeleteCriticalSection(&critical_section);
  }

  //! Locks the mutex.
  void lock()
  {
    EnterCriticalSection(&critical_section);
  }

  //! Unlocks the mutex.
  void unlock()
  {
    LeaveCriticalSection(&critical_section);
  }
};


#endif // MUTEX_HH
