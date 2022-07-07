/********************************************************************************
** Form generated from reading UI file 'changepwddlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEPWDDLG_H
#define UI_CHANGEPWDDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ChangePwdDlg
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLabel *label_10;
    QLineEdit *edt_NewPwd2;
    QLineEdit *edt_OldPwd;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_5;
    QLineEdit *edt_NewPwd1;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *ChangePwdDlg)
    {
        if (ChangePwdDlg->objectName().isEmpty())
            ChangePwdDlg->setObjectName(QString::fromUtf8("ChangePwdDlg"));
        ChangePwdDlg->resize(388, 197);
        verticalLayout = new QVBoxLayout(ChangePwdDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ChangePwdDlg);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setVerticalSpacing(18);
        label_6 = new QLabel(ChangePwdDlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_10 = new QLabel(ChangePwdDlg);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 2, 0, 1, 1);

        edt_NewPwd2 = new QLineEdit(ChangePwdDlg);
        edt_NewPwd2->setObjectName(QString::fromUtf8("edt_NewPwd2"));
        edt_NewPwd2->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_NewPwd2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(edt_NewPwd2, 2, 1, 1, 1);

        edt_OldPwd = new QLineEdit(ChangePwdDlg);
        edt_OldPwd->setObjectName(QString::fromUtf8("edt_OldPwd"));
        edt_OldPwd->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_OldPwd->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(edt_OldPwd, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 2, 1, 1);

        label_5 = new QLabel(ChangePwdDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        edt_NewPwd1 = new QLineEdit(ChangePwdDlg);
        edt_NewPwd1->setObjectName(QString::fromUtf8("edt_NewPwd1"));
        edt_NewPwd1->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_NewPwd1->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(edt_NewPwd1, 1, 1, 1, 1);

        gridLayout->setColumnMinimumWidth(1, 200);

        verticalLayout->addLayout(gridLayout);

        line = new QFrame(ChangePwdDlg);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(16);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_OK = new QPushButton(ChangePwdDlg);
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

        btn_Cancel = new QPushButton(ChangePwdDlg);
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


        retranslateUi(ChangePwdDlg);
        QObject::connect(btn_Cancel, SIGNAL(clicked()), ChangePwdDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ChangePwdDlg);
    } // setupUi

    void retranslateUi(QDialog *ChangePwdDlg)
    {
        ChangePwdDlg->setWindowTitle(QApplication::translate("ChangePwdDlg", "Change Manager Password", nullptr));
        label->setText(QApplication::translate("ChangePwdDlg", "Change Manager Password", nullptr));
        label_6->setText(QApplication::translate("ChangePwdDlg", "New Password=", nullptr));
        label_10->setText(QApplication::translate("ChangePwdDlg", "Retype new Password=", nullptr));
        label_5->setText(QApplication::translate("ChangePwdDlg", "Current Password=", nullptr));
        btn_OK->setText(QApplication::translate("ChangePwdDlg", "OK", nullptr));
        btn_Cancel->setText(QApplication::translate("ChangePwdDlg", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangePwdDlg: public Ui_ChangePwdDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEPWDDLG_H
