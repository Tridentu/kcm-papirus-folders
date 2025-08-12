#pragma once

#include <KQuickManagedConfigModule>
#include <QProcess>
#include "kcm_papirus_folders_config.h"

class PapirusFolderSettings : public KQuickManagedConfigModule
{
  Q_OBJECT

  Q_PROPERTY(PapirusFolders::Config *config READ config CONSTANT)

public:
    PapirusFolderSettings(QObject *parent, const KPluginMetaData &data);

    PapirusFolders::Config *config() const;
    void save() override;
    void notifyResult(int exitCode, QProcess::ExitStatus exitStatus);
private:
    PapirusFolders::Config *m_config;
    QProcess *m_process;
};
