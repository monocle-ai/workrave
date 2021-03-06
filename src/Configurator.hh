// Configurator.hh 
//
// Copyright (C) 2001, 2002 Rob Caelers <robc@krandor.org>
// All rights reserved.
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

#ifndef CONFIGURATOR_HH
#define CONFIGURATOR_HH

#include <string>
#include <list>
#include <map>

using namespace std;

class ConfiguratorListener;

class Configurator
{
public:
  //! Constructor
  Configurator();

  //! Destructor
  virtual ~Configurator();

  //! Creates a Configurator with the specified type.
  static Configurator *create(string type);
  
  //! Loads the specified file.
  /*!
   *  \param filename file to load.
   *
   *  \retval true load succeeded.
   *  \retval false load failed.
   */
  virtual bool load(string filename) = 0;

  //! Saves the configuration to the specified file.
  /*!
   *  \param filename file to save.
   *
   *  \retval true save succeeded.
   *  \retval false save failed.
   */
  virtual bool save(string filename) = 0;

  //! Saves the configuration.
  /*!
   *  \retval true save succeeded.
   *  \retval false save failed.
   */
  virtual bool save() = 0;

  //! Returns the value of the specified attribute
  /*!
   *  \retval true value successfully returned.
   *  \retval false attribute not found.
   */
  virtual bool get_value(string key, string *out) const = 0;

  //! Returns the value of the specified attribute
  /*!
   *  \retval true value successfully returned.
   *  \retval false attribute not found.
   */
  virtual bool get_value(string key, bool *out) const = 0;

  //! Returns the value of the specified attribute
  /*!
   *  \retval true value successfully returned.
   *  \retval false attribute not found.
   */
  virtual bool get_value(string key, int *out) const = 0;

  //! Returns the value of the specified attribute
  /*!
   *  \retval true value successfully returned.
   *  \retval false attribute not found.
   */
  virtual bool get_value(string key, long *out) const = 0;

  //! Returns the value of the specified attribute
  /*!
   *  \retval true value successfully returned.
   *  \retval false attribute not found.
   */
  virtual bool get_value(string key, double *out) const = 0;

  //! Sets the value of the specified attribute.
  /*!
   *  \retval true attribute successfully set.
   *  \retval false attribute could not be set..
   */
  virtual bool set_value(string key, string v) = 0;

  //! Sets the value of the specified attribute.
  /*!
   *  \retval true attribute successfully set.
   *  \retval false attribute could not be set..
   */
  virtual bool set_value(string key, int v) = 0;

  //! Sets the value of the specified attribute.
  /*!
   *  \retval true attribute successfully set.
   *  \retval false attribute could not be set..
   */
  virtual bool set_value(string key, long v) = 0;

  //! Sets the value of the specified attribute.
  /*!
   *  \retval true attribute successfully set.
   *  \retval false attribute could not be set..
   */
  virtual bool set_value(string key, bool v) = 0;

  //! Sets the value of the specified attribute.
  /*!
   *  \retval true attribute successfully set.
   *  \retval false attribute could not be set..
   */
  virtual bool set_value(string key, double v) = 0;

  //! Adds the specified configuration change listener.
  /*!
   *  \param keyPrefix configuration path to monitor.
   *  \param listener listener to add.
   *
   *  \retval true listener successfully added.
   *  \retval false listener already added.
   */
  virtual bool add_listener(string keyPrefix, ConfiguratorListener *listener);

  //! Removes the specified configuration change listener.
  /*!
   *  \param listener listener to stop monitoring.
   *
   *  \retval true listener successfully removed.
   *  \retval false listener not found.
   */
  virtual bool remove_listener(ConfiguratorListener *listener);

  //! Returns all configuration directories below the specified path.
  virtual list<string> get_all_dirs(string key) const = 0;

  //! Does the spcified directory exist ?
  virtual bool exists_dir(string key) const = 0;

protected:
  void fire_configurator_event(string key);
  void strip_leading_slash(string &key) const;
  void strip_trailing_slash(string &key) const;
  void add_trailing_slash(string &key) const;
  
protected:
  typedef std::list<std::pair<string, ConfiguratorListener *> > Listeners;
  typedef std::list<std::pair<string, ConfiguratorListener *> >::iterator ListenerIter;
  
  //! Configuration change listeners.
  Listeners listeners;
};

#endif // CONFIGURATOR_HH
