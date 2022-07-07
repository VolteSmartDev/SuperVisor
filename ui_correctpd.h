/********************************************************************************
** Form generated from reading UI file 'correctpd.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORRECTPD_H
#define UI_CORRECTPD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CorrectPD
{
public:
    QPushButton *btn_correct;
    QPushButton *btn_cancel;
    QLabel *label_4;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *edt_tableid;
    QLabel *label_2;
    QLineEdit *edt_curproducts;
    QLabel *label_3;
    QLineEdit *edt_newproducts;
    QLineEdit *edt_date;
    QLabel *label_6;

    void setupUi(QDialog *CorrectPD)
    {
        if (CorrectPD->objectName().isEmpty())
            CorrectPD->setObjectName(QString::fromUtf8("CorrectPD"));
        CorrectPD->resize(435, 210);
        CorrectPD->setMinimumSize(QSize(435, 210));
        CorrectPD->setMaximumSize(QSize(435, 210));
        btn_correct = new QPushButton(CorrectPD);
        btn_correct->setObjectName(QString::fromUtf8("btn_correct"));
        btn_correct->setGeometry(QRect(110, 170, 91, 32));
        btn_correct->setMinimumSize(QSize(0, 32));
        btn_cancel = new QPushButton(CorrectPD);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(240, 170, 91, 32));
        btn_cancel->setMinimumSize(QSize(0, 32));
        label_4 = new QLabel(CorrectPD);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 0, 308, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));
        label_4->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(CorrectPD);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 40, 371, 121));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        edt_tableid = new QLineEdit(layoutWidget);
        edt_tableid->setObjectName(QString::fromUtf8("edt_tableid"));
        edt_tableid->setMinimumSize(QSize(0, 24));
        edt_tableid->setFont(font1);
        edt_tableid->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, edt_tableid);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        edt_curproducts = new QLineEdit(layoutWidget);
        edt_curproducts->setObjectName(QString::fromUtf8("edt_curproducts"));
        edt_curproducts->setMinimumSize(QSize(0, 24));
        edt_curproducts->setFont(font1);
        edt_curproducts->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, edt_curproducts);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        edt_newproducts = new QLineEdit(layoutWidget);
        edt_newproducts->setObjectName(QString::fromUtf8("edt_newproducts"));
        edt_newproducts->setMinimumSize(QSize(0, 24));
        edt_newproducts->setFont(font1);

        formLayout->setWidget(3, QFormLayout::FieldRole, edt_newproducts);

        edt_date = new QLineEdit(layoutWidget);
        edt_date->setObjectName(QString::fromUtf8("edt_date"));
        edt_date->setMinimumSize(QSize(0, 24));
        edt_date->setFont(font1);
        edt_date->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, edt_date);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_6);


        retranslateUi(CorrectPD);

        QMetaObject::connectSlotsByName(CorrectPD);
    } // setupUi

    void retranslateUi(QDialog *CorrectPD)
    {
        CorrectPD->setWindowTitle(QApplication::translate("CorrectPD", "Manual Products Correction", nullptr));
        btn_correct->setText(QApplication::translate("CorrectPD", "Correct", nullptr));
        btn_cancel->setText(QApplication::translate("CorrectPD", "Cancel", nullptr));
        label_4->setText(QApplication::translate("CorrectPD", "Products Correction", nullptr));
        label->setText(QApplication::translate("CorrectPD", "Table ID", nullptr));
        edt_tableid->setText(QApplication::translate("CorrectPD", "1234", nullptr));
        label_2->setText(QApplication::translate("CorrectPD", "Last Products", nullptr));
        edt_curproducts->setText(QApplication::translate("CorrectPD", "123", nullptr));
        label_3->setText(QApplication::translate("CorrectPD", "Correct Products", nullptr));
        edt_newproducts->setText(QApplication::translate("CorrectPD", "1234", nullptr));
        edt_date->setText(QApplication::translate("CorrectPD", "1234", nullptr));
        label_6->setText(QApplication::translate("CorrectPD", "Product Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CorrectPD: public Ui_CorrectPD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORRECTPD_H
