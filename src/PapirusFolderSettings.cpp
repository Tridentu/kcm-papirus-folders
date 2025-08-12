#include "PapirusFolderSettings.h"


#include <KPluginFactory>
#include <KNotification>
#include <KLocalizedString>

K_PLUGIN_CLASS_WITH_JSON(PapirusFolderSettings, "kcm_papirus_folders.json")

PapirusFolderSettings::PapirusFolderSettings(QObject *parent, const KPluginMetaData& data) : KQuickManagedConfigModule(parent, data), m_config(new PapirusFolders::Config(this))
{
    qmlRegisterAnonymousType<PapirusFolders::Config>("io.github.tridentu.papirusfolders.private", 1);

    setButtons(Help | Apply | Default);
}

PapirusFolders::Config *PapirusFolderSettings::config() const { return m_config; }

void PapirusFolderSettings::save() {
    KQuickManagedConfigModule::save();
    qDebug() << "Running papirus-folders...";
    {
        QString program = QStringLiteral("papirus-folders");
        QStringList arguments;
        arguments << QStringLiteral("-t") << QStringLiteral("Papirus");
        qDebug() << config()->folderColor() << " selected";
        arguments << QStringLiteral("-C") << config()->folderColor();


        m_process = new QProcess(this);
        connect(m_process, &QProcess::finished, this, &PapirusFolderSettings::notifyResult);
        m_process->start(program, arguments);
    }
    if (config()->updatePapirusDark()){
        QString program = QStringLiteral("papirus-folders");
        QStringList arguments;
        arguments << QStringLiteral("-t") << QStringLiteral("Papirus-Dark");
        qDebug() << config()->folderColor() << " selected";
        arguments << QStringLiteral("-C") << config()->folderColor();


        m_process = new QProcess(this);
        connect(m_process, &QProcess::finished, this, &PapirusFolderSettings::notifyResult);
        m_process->start(program, arguments);
    }
    if (config()->updatePapirusLight()){
        QString program = QStringLiteral("papirus-folders");
        QStringList arguments;
        arguments << QStringLiteral("-t") << QStringLiteral("Papirus-Light");
        qDebug() << config()->folderColor() << " selected";
        arguments << QStringLiteral("-C") << config()->folderColor();


        m_process = new QProcess(this);
        connect(m_process, &QProcess::finished, this, &PapirusFolderSettings::notifyResult);
        m_process->start(program, arguments);
    }
}

void PapirusFolderSettings::notifyResult(int exitCode, QProcess::ExitStatus exitStatus){
    if(exitCode == 0){
        KNotification *notification = new KNotification(QStringLiteral("folderColorSaved"));
        notification->setComponentName(QStringLiteral("papirus_folders"));
        notification->setText(i18n("Your preferred Papirus folder color has been saved"));
        notification->setIconName(QStringLiteral("folder-") + config()->folderColor());
        notification->sendEvent();
    } else {
        KNotification *notification = new KNotification(QStringLiteral("folderColorNotSaved"));
        notification->setComponentName(QStringLiteral("papirus_folders"));
        notification->setText(i18n("Your preferred Papirus folder color has failed to save"));
        notification->setIconName(QStringLiteral("folder-nordic"));
        notification->sendEvent();
    }
}


#include "PapirusFolderSettings.moc"
