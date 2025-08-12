/**
 * SPDX-FileCopyrightText: Year Author <author@domain.com>
 * SPDX-License-Identifier: GPL-2.0-or-later
 */


import QtQuick
import QtQuick.Controls as Controls
import QtQuick.Layouts as Layout

import org.kde.kirigami as Kirigami
import org.kde.kcmutils as KCMUtils

KCMUtils.SimpleKCM {

    Kirigami.FormLayout {
        anchors.fill: parent
        wideMode: true

        Controls.ComboBox {
            id: colorsTumbler
            property bool isReady: false
            Kirigami.FormData.label: "Folder Color:"
            model: ListModel {
                id: colorModel
                ListElement {
                    text: "Adwaita"
                    value: "adwaita"
                }
                ListElement {
                    text: "Black"
                    value: "black"
                }
                ListElement {
                    text: "Blue"
                    value: "blue"
                }
                ListElement {
                    text: "Blue-Grey"
                    value: "bluegrey"
                }
                ListElement {
                    text: "Breeze"
                    value: "breeze"
                }
                ListElement {
                    text: "Brown"
                    value: "brown"
                }
                ListElement {
                    text: "Carmine"
                    value: "carmine"
                }
                ListElement {
                    text: "Cyan"
                    value: "cyan"
                }
                ListElement {
                    text: "Dark Cyan"
                    value: "darkcyan"
                }
                ListElement {
                    text: "Deep Orange"
                    value: "deeporange"
                }
                ListElement {
                    text: "Green"
                    value: "green"
                }
                ListElement {
                    text: "Green"
                    value: "green"
                }
                ListElement {
                    text: "Grey"
                    value: "grey"
                }
                ListElement {
                    text: "Indigo"
                    value: "indigo"
                }
                ListElement {
                    text: "Magenta"
                    value: "magenta"
                }
                ListElement {
                    text: "Nordic"
                    value: "nordic"
                }
                ListElement {
                    text: "Orange"
                    value: "orange"
                }
                ListElement {
                    text: "Pale Brown"
                    value: "palebrown"
                }
                ListElement {
                    text: "Pale Orange"
                    value: "paleorange"
                }
                ListElement {
                    text: "Pink"
                    value: "pink"
                }
                ListElement {
                    text: "Red"
                    value: "red"
                }
                ListElement {
                    text: "Teal"
                    value: "teal"
                }
                ListElement {
                    text: "Violet"
                    value: "violet"
                }
                ListElement {
                    text: "White"
                    value: "white"
                }
                ListElement {
                    text: "Yaru"
                    value: "yaru"
                }
                ListElement {
                    text: "Yellow"
                    value: "yellow"
                }
            }
            textRole: "text"
            valueRole: "value"
            Component.onCompleted: () => {
                currentIndex = indexOfValue(kcm.config.folderColor);
                isReady = true;
            }

            onCurrentValueChanged: () => {
                if (isReady)
                    kcm.config.folderColor = currentValue
            }
        }

        Kirigami.Heading {
            text: "Folders"
            level: 2
        }

        Controls.Switch {
            id: papirusDarkSwitch
            Kirigami.FormData.label: "Update Papirus Dark?:"
            checked: kcm.config.updatePapirusDark
            onClicked: () => {
                kcm.config.updatePapirusDark = checked
            }
        }


        Controls.Switch {
            id: papirusLightSwitch
            Kirigami.FormData.label: "Update Papirus Light?:"
            checked: kcm.config.updatePapirusLight
            onClicked: () => {
                kcm.config.updatePapirusLight = checked
            }
        }


    }
}
