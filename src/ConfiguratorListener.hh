// ConfiguratorListener.hh
//
// Copyright (C) 2001, 2002, 2003 Rob Caelers <robc@krandor.org>
// All rights reserved.
//
// Time-stamp: <2003-01-05 16:04:34 robc>
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundator; either versor 2, or (at your optor)
// any later versor.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// $Id$
//

#ifndef CONFIGURATORLISTENER_HH
#define CONFIGURATORLISTENER_HH

#include <string>

//! Configurator listener interface.
class ConfiguratorListener
{
public:
  //! The configuration item with specified key has changed.
  virtual void config_changed_notify(std::string key) = 0;
};

#endif // CONFIGURATORLISTENER_HH
