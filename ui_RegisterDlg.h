/********************************************************************************
** Form generated from reading UI file 'RegisterDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDLG_H
#define UI_REGISTERDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RegisterDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *edt_P;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *edt_L;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Apply;
    QPushButton *btn_Cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RegisterDlg)
    {
        if (RegisterDlg->objectName().isEmpty())
            RegisterDlg->setObjectName(QString::fromUtf8("RegisterDlg"));
        RegisterDlg->resize(430, 250);
        RegisterDlg->setMinimumSize(QSize(430, 250));
        RegisterDlg->setMaximumSize(QSize(430, 250));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(10);
        RegisterDlg->setFont(font);
        RegisterDlg->setStyleSheet(QString::fromUtf8("background-color: rgb(45, 45, 45);"));
        verticalLayout_2 = new QVBoxLayout(RegisterDlg);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 24);
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label = new QLabel(RegisterDlg);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 85, 0);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        line = new QFrame(RegisterDlg);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(RegisterDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_2);

        edt_P = new QLineEdit(RegisterDlg);
        edt_P->setObjectName(QString::fromUtf8("edt_P"));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        edt_P->setFont(font3);
        edt_P->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 244, 244);"));
        edt_P->setReadOnly(true);

        horizontalLayout->addWidget(edt_P);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(RegisterDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_3);

        edt_L = new QLineEdit(RegisterDlg);
        edt_L->setObjectName(QString::fromUtf8("edt_L"));
        edt_L->setFont(font3);
        edt_L->setStyleSheet(QString::fromUtf8("background-color: rgb(244, 244, 244);\n"
""));
        edt_L->setMaxLength(24);

        horizontalLayout_2->addWidget(edt_L);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 20);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);

        line_2 = new QFrame(RegisterDlg);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(23);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btn_Apply = new QPushButton(RegisterDlg);
        btn_Apply->setObjectName(QString::fromUtf8("btn_Apply"));
        btn_Apply->setMinimumSize(QSize(0, 28));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        btn_Apply->setFont(font4);
        btn_Apply->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));

        horizontalLayout_3->addWidget(btn_Apply);

        btn_Cancel = new QPushButton(RegisterDlg);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setMinimumSize(QSize(0, 28));
        btn_Cancel->setFont(font4);
        btn_Cancel->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 221, 221);"));

        horizontalLayout_3->addWidget(btn_Cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(RegisterDlg);
        QObject::connect(btn_Cancel, SIGNAL(clicked()), RegisterDlg, SLOT(reject()));

        btn_Apply->setDefault(true);


        QMetaObject::connectSlotsByName(RegisterDlg);
    } // setupUi

    void retranslateUi(QDialog *RegisterDlg)
    {
        RegisterDlg->setWindowTitle(QApplication::translate("RegisterDlg", "Register Product", nullptr));
        label->setText(QApplication::translate("RegisterDlg", "SUPER VISOR", nullptr));
        label_2->setText(QApplication::translate("RegisterDlg", "Product Key=", nullptr));
        label_3->setText(QApplication::translate("RegisterDlg", "License Key=", nullptr));
        edt_L->setInputMask(QString());
        edt_L->setText(QString());
        btn_Apply->setText(QApplication::translate("RegisterDlg", "Apply", nullptr));
        btn_Cancel->setText(QApplication::translate("RegisterDlg", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDlg: public Ui_RegisterDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDLG_H
