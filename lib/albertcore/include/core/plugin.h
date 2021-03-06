// albert - a simple application launcher for linux
// Copyright (C) 2014-2017 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once
#include <QDir>
#include <QObject>
#include <QString>
#include <QSettings>
#include <memory>
#include "core_globals.h"

#define ALBERT_PLUGIN_IID_PREFIX "org.albert.pluginv1-alpha"

namespace Core {

class PluginPrivate;

class EXPORT_CORE Plugin : public QObject
{
    Q_OBJECT

public:

    Plugin(const QString &id);
    ~Plugin();

    /**
     * @brief id
     * This is the global unique identifier of the plugin
     * @return
     */
    const QString &id() const;

    /**
     * @brief cacheLocation
     * @return The recommended cache location for the plugin.
     * @note If the dir does not exist it will be crated.
     */
    QDir cacheLocation() const;

    /**
     * @brief configLocation
     * @return The recommended config location for the plugin.
     * @note If the dir does not exist it will be crated.
     */
    QDir configLocation() const;

    /**
     * @brief dataLocation
     * @return The recommended data location for the plugin
     * @note If the dir does not exist it will be crated.
     */
    QDir dataLocation() const;

    /**
     * @brief settings
     * This is a convenience function returning the default settings object for this plugin. It is
     * located in the config location defined in this plugin and has the basename "config". Note
     * that QSettings is not thread-safe, so if you want to access the settings concurrently you
     * should create a new instance with the path of this object.
     * @return The settings object
     */
    QSettings &settings();

private:

    std::unique_ptr<PluginPrivate> d;

};

}
