/********************************************************************************
** Form generated from reading UI file 'popstargame.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPSTARGAME_H
#define UI_POPSTARGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PopStarGame
{
public:
    QPushButton *btn_StartGame;
    QPushButton *btn_GameInstruction;
    QPushButton *btn_GameVersion;
    QPushButton *btn_ExitGame;

    void setupUi(QDialog *PopStarGame)
    {
        if (PopStarGame->objectName().isEmpty())
            PopStarGame->setObjectName(QStringLiteral("PopStarGame"));
        PopStarGame->resize(382, 514);
        btn_StartGame = new QPushButton(PopStarGame);
        btn_StartGame->setObjectName(QStringLiteral("btn_StartGame"));
        btn_StartGame->setGeometry(QRect(100, 290, 180, 40));
        btn_GameInstruction = new QPushButton(PopStarGame);
        btn_GameInstruction->setObjectName(QStringLiteral("btn_GameInstruction"));
        btn_GameInstruction->setGeometry(QRect(100, 348, 180, 40));
        btn_GameVersion = new QPushButton(PopStarGame);
        btn_GameVersion->setObjectName(QStringLiteral("btn_GameVersion"));
        btn_GameVersion->setGeometry(QRect(100, 402, 180, 40));
        btn_ExitGame = new QPushButton(PopStarGame);
        btn_ExitGame->setObjectName(QStringLiteral("btn_ExitGame"));
        btn_ExitGame->setGeometry(QRect(100, 459, 180, 40));

        retranslateUi(PopStarGame);

        QMetaObject::connectSlotsByName(PopStarGame);
    } // setupUi

    void retranslateUi(QDialog *PopStarGame)
    {
        PopStarGame->setWindowTitle(QApplication::translate("PopStarGame", "Dialog", 0));
        btn_StartGame->setText(QString());
        btn_GameInstruction->setText(QString());
        btn_GameVersion->setText(QString());
        btn_ExitGame->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PopStarGame: public Ui_PopStarGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPSTARGAME_H
