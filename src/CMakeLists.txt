kcmutils_add_qml_kcm(kcm_papirus_folders)
target_sources(kcm_papirus_folders PRIVATE
    PapirusFolderSettings.cpp
    PapirusFolderSettings.h
)

kconfig_add_kcfg_files(kcm_papirus_folders GENERATE_MOC kcm_papirus_folders_config.kcfgc)

target_link_libraries(kcm_papirus_folders PRIVATE
    Qt::Quick
    KF6::CoreAddons
    KF6::KCMUtils
    KF6::I18n
    KF6::Notifications
)

install(FILES papirus_folders.notifyrc  DESTINATION ${KDE_INSTALL_KNOTIFYRCDIR})
