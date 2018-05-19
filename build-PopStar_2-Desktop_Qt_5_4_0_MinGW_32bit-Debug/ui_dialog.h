/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLineEdit *lineEdit_Grade;
    QLineEdit *lineEdit_isSuccess;
    QLineEdit *lineEdit_CurrScore;
    QPushButton *btn_Vedio;
    QPushButton *btn_Music;
    QLineEdit *lineEdit_TotalScore;
    QLineEdit *lineEdit_GoalScore;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(382, 514);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        lineEdit_Grade = new QLineEdit(Dialog);
        lineEdit_Grade->setObjectName(QStringLiteral("lineEdit_Grade"));
        lineEdit_Grade->setGeometry(QRect(60, 30, 31, 21));
        lineEdit_Grade->setFocusPolicy(Qt::NoFocus);
        lineEdit_Grade->setAlignment(Qt::AlignCenter);
        lineEdit_isSuccess = new QLineEdit(Dialog);
        lineEdit_isSuccess->setObjectName(QStringLiteral("lineEdit_isSuccess"));
        lineEdit_isSuccess->setGeometry(QRect(60, 60, 61, 31));
        lineEdit_isSuccess->setFocusPolicy(Qt::NoFocus);
        lineEdit_isSuccess->setStyleSheet(QStringLiteral(""));
        lineEdit_isSuccess->setAlignment(Qt::AlignCenter);
        lineEdit_CurrScore = new QLineEdit(Dialog);
        lineEdit_CurrScore->setObjectName(QStringLiteral("lineEdit_CurrScore"));
        lineEdit_CurrScore->setGeometry(QRect(130, 50, 121, 31));
        lineEdit_CurrScore->setFocusPolicy(Qt::NoFocus);
        lineEdit_CurrScore->setAlignment(Qt::AlignCenter);
        btn_Vedio = new QPushButton(Dialog);
        btn_Vedio->setObjectName(QStringLiteral("btn_Vedio"));
        btn_Vedio->setGeometry(QRect(270, 1, 61, 51));
        btn_Music = new QPushButton(Dialog);
        btn_Music->setObjectName(QStringLiteral("btn_Music"));
        btn_Music->setGeometry(QRect(328, 1, 61, 51));
        lineEdit_TotalScore = new QLineEdit(Dialog);
        lineEdit_TotalScore->setObjectName(QStringLiteral("lineEdit_TotalScore"));
        lineEdit_TotalScore->setGeometry(QRect(90, 4, 101, 21));
        lineEdit_TotalScore->setMouseTracking(true);
        lineEdit_TotalScore->setFocusPolicy(Qt::NoFocus);
        lineEdit_TotalScore->setStyleSheet(QStringLiteral(""));
        lineEdit_TotalScore->setAlignment(Qt::AlignCenter);
        lineEdit_GoalScore = new QLineEdit(Dialog);
        lineEdit_GoalScore->setObjectName(QStringLiteral("lineEdit_GoalScore"));
        lineEdit_GoalScore->setGeometry(QRect(192, 25, 78, 25));
        lineEdit_GoalScore->setFocusPolicy(Qt::NoFocus);
        lineEdit_GoalScore->setAlignment(Qt::AlignCenter);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        lineEdit_Grade->setText(QApplication::translate("Dialog", "1", 0));
        lineEdit_isSuccess->setText(QString());
        lineEdit_CurrScore->setText(QApplication::translate("Dialog", "3", 0));
        btn_Vedio->setText(QString());
        btn_Music->setText(QString());
        lineEdit_TotalScore->setText(QApplication::translate("Dialog", "6", 0));
        lineEdit_GoalScore->setText(QApplication::translate("Dialog", "7", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
