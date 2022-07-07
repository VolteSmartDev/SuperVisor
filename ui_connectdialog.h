/********************************************************************************
** Form generated from reading UI file 'connectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTDIALOG_H
#define UI_CONNECTDIALOG_H

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

class Ui_ConnectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *edt_DeviceID;
    QLabel *label_3;
    QLineEdit *edt_Start;
    QLineEdit *edt_IP;
    QLabel *label;
    QLineEdit *edt_Port;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *edt_ValCont;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_Connect;
    QPushButton *btn_Close;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *ConnectDialog)
    {
        if (ConnectDialog->objectName().isEmpty())
            ConnectDialog->setObjectName(QString::fromUtf8("ConnectDialog"));
        ConnectDialog->resize(400, 257);
        QFont font;
        font.setPointSize(11);
        ConnectDialog->setFont(font);
        ConnectDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        verticalLayout = new QVBoxLayout(ConnectDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_5 = new QLabel(ConnectDialog);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setPointSize(10);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        edt_DeviceID = new QLineEdit(ConnectDialog);
        edt_DeviceID->setObjectName(QString::fromUtf8("edt_DeviceID"));
        edt_DeviceID->setMinimumSize(QSize(60, 32));
        edt_DeviceID->setMaximumSize(QSize(60, 16777215));
        QFont font2;
        font2.setPointSize(16);
        edt_DeviceID->setFont(font2);
        edt_DeviceID->setStyleSheet(QString::fromUtf8("padding: 0px 8px;\n"
"                    border: 1px solid #e0e0e0;\n"
"                    border-radius: 4px;\n"
"                    background-color: #ffffff"));
        edt_DeviceID->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edt_DeviceID, 1, 1, 1, 1);

        label_3 = new QLabel(ConnectDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        edt_Start = new QLineEdit(ConnectDialog);
        edt_Start->setObjectName(QString::fromUtf8("edt_Start"));
        edt_Start->setMinimumSize(QSize(0, 32));
        edt_Start->setMaximumSize(QSize(60, 16777215));
        edt_Start->setFont(font2);
        edt_Start->setStyleSheet(QString::fromUtf8("padding: 0px 8px;\n"
"                    border: 1px solid #e0e0e0;\n"
"                    border-radius: 4px;\n"
"                    background-color: #ffffff"));
        edt_Start->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edt_Start, 3, 1, 1, 1);

        edt_IP = new QLineEdit(ConnectDialog);
        edt_IP->setObjectName(QString::fromUtf8("edt_IP"));
        edt_IP->setMinimumSize(QSize(0, 32));
        edt_IP->setFont(font2);
        edt_IP->setStyleSheet(QString::fromUtf8("padding: 0px 8px;\n"
"                    border: 1px solid #e0e0e0;\n"
"                    border-radius: 4px;\n"
"                    background-color: #ffffff"));

        gridLayout->addWidget(edt_IP, 0, 1, 1, 2);

        label = new QLabel(ConnectDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        edt_Port = new QLineEdit(ConnectDialog);
        edt_Port->setObjectName(QString::fromUtf8("edt_Port"));
        edt_Port->setMinimumSize(QSize(60, 32));
        edt_Port->setMaximumSize(QSize(60, 16777215));
        edt_Port->setFont(font2);
        edt_Port->setStyleSheet(QString::fromUtf8("padding: 0px 8px;\n"
"                    border: 1px solid #e0e0e0;\n"
"                    border-radius: 4px;\n"
"                    background-color: #ffffff"));
        edt_Port->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edt_Port, 2, 1, 1, 1);

        label_2 = new QLabel(ConnectDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_4 = new QLabel(ConnectDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        edt_ValCont = new QLineEdit(ConnectDialog);
        edt_ValCont->setObjectName(QString::fromUtf8("edt_ValCont"));
        edt_ValCont->setMinimumSize(QSize(0, 32));
        edt_ValCont->setMaximumSize(QSize(60, 16777215));
        edt_ValCont->setFont(font2);
        edt_ValCont->setStyleSheet(QString::fromUtf8("padding: 0px 8px;\n"
"                    border: 1px solid #e0e0e0;\n"
"                    border-radius: 4px;\n"
"                    background-color: #ffffff"));
        edt_ValCont->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(edt_ValCont, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        line = new QFrame(ConnectDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_Connect = new QPushButton(ConnectDialog);
        btn_Connect->setObjectName(QString::fromUtf8("btn_Connect"));
        btn_Connect->setMinimumSize(QSize(80, 36));
        btn_Connect->setMaximumSize(QSize(16777215, 36));
        QFont font3;
        font3.setPointSize(8);
        btn_Connect->setFont(font3);
        btn_Connect->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 4px;\n"
"	background-color: #00afff; color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: #23ccff;\n"
"}"));

        horizontalLayout->addWidget(btn_Connect);

        btn_Close = new QPushButton(ConnectDialog);
        btn_Close->setObjectName(QString::fromUtf8("btn_Close"));
        btn_Close->setMinimumSize(QSize(80, 36));
        btn_Close->setMaximumSize(QSize(16777215, 36));
        btn_Close->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 4px;\n"
"	background-color: #dadada; color: 323232;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: #eaeaea;\n"
"}"));

        horizontalLayout->addWidget(btn_Close);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ConnectDialog);
        QObject::connect(btn_Close, SIGNAL(clicked()), ConnectDialog, SLOT(reject()));

        btn_Connect->setDefault(true);


        QMetaObject::connectSlotsByName(ConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectDialog)
    {
        ConnectDialog->setWindowTitle(QApplication::translate("ConnectDialog", "Connect to Modbus", nullptr));
        label_5->setText(QApplication::translate("ConnectDialog", "Device ID:", nullptr));
        edt_DeviceID->setText(QApplication::translate("ConnectDialog", "1", nullptr));
        label_3->setText(QApplication::translate("ConnectDialog", "Start Address:", nullptr));
        edt_Start->setText(QApplication::translate("ConnectDialog", "20", nullptr));
        edt_IP->setInputMask(QString());
        label->setText(QApplication::translate("ConnectDialog", "Modbus TCP/IP Address:", nullptr));
        edt_Port->setText(QApplication::translate("ConnectDialog", "502", nullptr));
        label_2->setText(QApplication::translate("ConnectDialog", "Port:", nullptr));
        label_4->setText(QApplication::translate("ConnectDialog", "Entry Count:", nullptr));
        edt_ValCont->setText(QApplication::translate("ConnectDialog", "48", nullptr));
        btn_Connect->setText(QApplication::translate("ConnectDialog", "Connect", nullptr));
        btn_Close->setText(QApplication::translate("ConnectDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectDialog: public Ui_ConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTDIALOG_H
