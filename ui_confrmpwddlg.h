/********************************************************************************
** Form generated from reading UI file 'confrmpwddlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFRMPWDDLG_H
#define UI_CONFRMPWDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ConfrmPwdDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *edt_Pwd;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ConfrmPwdDlg)
    {
        if (ConfrmPwdDlg->objectName().isEmpty())
            ConfrmPwdDlg->setObjectName(QString::fromUtf8("ConfrmPwdDlg"));
        ConfrmPwdDlg->resize(328, 135);
        verticalLayout = new QVBoxLayout(ConfrmPwdDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ConfrmPwdDlg);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        edt_Pwd = new QLineEdit(ConfrmPwdDlg);
        edt_Pwd->setObjectName(QString::fromUtf8("edt_Pwd"));
        edt_Pwd->setMinimumSize(QSize(220, 28));
        edt_Pwd->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_Pwd->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(edt_Pwd);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_OK = new QPushButton(ConfrmPwdDlg);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMinimumSize(QSize(70, 30));
        btn_OK->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 4px;\n"
"	background-color: #00afff; color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: #23ccff;\n"
"}"));

        horizontalLayout_2->addWidget(btn_OK);

        btn_Cancel = new QPushButton(ConfrmPwdDlg);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setMinimumSize(QSize(70, 30));
        btn_Cancel->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 4px;\n"
"	background-color: #dadada; color: 323232;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: #eaeaea;\n"
"}"));

        horizontalLayout_2->addWidget(btn_Cancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        QWidget::setTabOrder(edt_Pwd, btn_OK);
        QWidget::setTabOrder(btn_OK, btn_Cancel);

        retranslateUi(ConfrmPwdDlg);
        QObject::connect(btn_Cancel, SIGNAL(clicked()), ConfrmPwdDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfrmPwdDlg);
    } // setupUi

    void retranslateUi(QDialog *ConfrmPwdDlg)
    {
        ConfrmPwdDlg->setWindowTitle(QApplication::translate("ConfrmPwdDlg", "Confirm Manager Password", nullptr));
        label->setText(QApplication::translate("ConfrmPwdDlg", "Confirm Manager Password", nullptr));
        btn_OK->setText(QApplication::translate("ConfrmPwdDlg", "OK", nullptr));
        btn_Cancel->setText(QApplication::translate("ConfrmPwdDlg", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfrmPwdDlg: public Ui_ConfrmPwdDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFRMPWDDLG_H
