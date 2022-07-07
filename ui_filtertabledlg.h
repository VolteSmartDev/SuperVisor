/********************************************************************************
** Form generated from reading UI file 'filtertabledlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERTABLEDLG_H
#define UI_FILTERTABLEDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterTableDlg
{
public:
    QLabel *label;
    QPushButton *btn_apply;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QCheckBox *ck_1;
    QCheckBox *ck_9;
    QCheckBox *ck_2;
    QCheckBox *ck_10;
    QCheckBox *ck_3;
    QCheckBox *ck_11;
    QCheckBox *ck_4;
    QCheckBox *ck_12;
    QCheckBox *ck_5;
    QCheckBox *ck_13;
    QCheckBox *ck_6;
    QCheckBox *ck_14;
    QCheckBox *ck_7;
    QCheckBox *ck_15;
    QCheckBox *ck_8;
    QCheckBox *ck_16;
    QCheckBox *ck_All;

    void setupUi(QDialog *FilterTableDlg)
    {
        if (FilterTableDlg->objectName().isEmpty())
            FilterTableDlg->setObjectName(QString::fromUtf8("FilterTableDlg"));
        FilterTableDlg->resize(460, 350);
        FilterTableDlg->setMinimumSize(QSize(460, 350));
        FilterTableDlg->setMaximumSize(QSize(460, 350));
        label = new QLabel(FilterTableDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 10, 308, 36));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 170, 255);"));
        label->setAlignment(Qt::AlignCenter);
        btn_apply = new QPushButton(FilterTableDlg);
        btn_apply->setObjectName(QString::fromUtf8("btn_apply"));
        btn_apply->setGeometry(QRect(180, 310, 101, 31));
        QFont font1;
        font1.setPointSize(10);
        btn_apply->setFont(font1);
        layoutWidget = new QWidget(FilterTableDlg);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 50, 381, 251));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ck_1 = new QCheckBox(layoutWidget);
        ck_1->setObjectName(QString::fromUtf8("ck_1"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(14);
        ck_1->setFont(font2);
        ck_1->setChecked(true);

        gridLayout->addWidget(ck_1, 0, 0, 1, 1);

        ck_9 = new QCheckBox(layoutWidget);
        ck_9->setObjectName(QString::fromUtf8("ck_9"));
        ck_9->setFont(font2);
        ck_9->setChecked(true);

        gridLayout->addWidget(ck_9, 0, 1, 1, 1);

        ck_2 = new QCheckBox(layoutWidget);
        ck_2->setObjectName(QString::fromUtf8("ck_2"));
        ck_2->setFont(font2);
        ck_2->setChecked(true);

        gridLayout->addWidget(ck_2, 1, 0, 1, 1);

        ck_10 = new QCheckBox(layoutWidget);
        ck_10->setObjectName(QString::fromUtf8("ck_10"));
        ck_10->setFont(font2);
        ck_10->setChecked(true);

        gridLayout->addWidget(ck_10, 1, 1, 1, 1);

        ck_3 = new QCheckBox(layoutWidget);
        ck_3->setObjectName(QString::fromUtf8("ck_3"));
        ck_3->setFont(font2);
        ck_3->setChecked(true);

        gridLayout->addWidget(ck_3, 2, 0, 1, 1);

        ck_11 = new QCheckBox(layoutWidget);
        ck_11->setObjectName(QString::fromUtf8("ck_11"));
        ck_11->setFont(font2);
        ck_11->setChecked(true);

        gridLayout->addWidget(ck_11, 2, 1, 1, 1);

        ck_4 = new QCheckBox(layoutWidget);
        ck_4->setObjectName(QString::fromUtf8("ck_4"));
        ck_4->setFont(font2);
        ck_4->setChecked(true);

        gridLayout->addWidget(ck_4, 3, 0, 1, 1);

        ck_12 = new QCheckBox(layoutWidget);
        ck_12->setObjectName(QString::fromUtf8("ck_12"));
        ck_12->setFont(font2);
        ck_12->setChecked(true);

        gridLayout->addWidget(ck_12, 3, 1, 1, 1);

        ck_5 = new QCheckBox(layoutWidget);
        ck_5->setObjectName(QString::fromUtf8("ck_5"));
        ck_5->setFont(font2);
        ck_5->setChecked(true);

        gridLayout->addWidget(ck_5, 4, 0, 1, 1);

        ck_13 = new QCheckBox(layoutWidget);
        ck_13->setObjectName(QString::fromUtf8("ck_13"));
        ck_13->setFont(font2);
        ck_13->setChecked(true);

        gridLayout->addWidget(ck_13, 4, 1, 1, 1);

        ck_6 = new QCheckBox(layoutWidget);
        ck_6->setObjectName(QString::fromUtf8("ck_6"));
        ck_6->setFont(font2);
        ck_6->setChecked(true);

        gridLayout->addWidget(ck_6, 5, 0, 1, 1);

        ck_14 = new QCheckBox(layoutWidget);
        ck_14->setObjectName(QString::fromUtf8("ck_14"));
        ck_14->setFont(font2);
        ck_14->setChecked(true);

        gridLayout->addWidget(ck_14, 5, 1, 1, 1);

        ck_7 = new QCheckBox(layoutWidget);
        ck_7->setObjectName(QString::fromUtf8("ck_7"));
        ck_7->setFont(font2);
        ck_7->setChecked(true);

        gridLayout->addWidget(ck_7, 6, 0, 1, 1);

        ck_15 = new QCheckBox(layoutWidget);
        ck_15->setObjectName(QString::fromUtf8("ck_15"));
        ck_15->setFont(font2);
        ck_15->setChecked(true);

        gridLayout->addWidget(ck_15, 6, 1, 1, 1);

        ck_8 = new QCheckBox(layoutWidget);
        ck_8->setObjectName(QString::fromUtf8("ck_8"));
        ck_8->setFont(font2);
        ck_8->setChecked(true);

        gridLayout->addWidget(ck_8, 7, 0, 1, 1);

        ck_16 = new QCheckBox(layoutWidget);
        ck_16->setObjectName(QString::fromUtf8("ck_16"));
        ck_16->setFont(font2);
        ck_16->setChecked(true);

        gridLayout->addWidget(ck_16, 7, 1, 1, 1);

        ck_All = new QCheckBox(FilterTableDlg);
        ck_All->setObjectName(QString::fromUtf8("ck_All"));
        ck_All->setGeometry(QRect(340, 20, 111, 25));
        ck_All->setFont(font2);
        ck_All->setChecked(true);

        retranslateUi(FilterTableDlg);

        QMetaObject::connectSlotsByName(FilterTableDlg);
    } // setupUi

    void retranslateUi(QDialog *FilterTableDlg)
    {
        FilterTableDlg->setWindowTitle(QApplication::translate("FilterTableDlg", "Table Filter", nullptr));
        label->setText(QApplication::translate("FilterTableDlg", "TABLE FILTER", nullptr));
        btn_apply->setText(QApplication::translate("FilterTableDlg", "Apply", nullptr));
        ck_1->setText(QApplication::translate("FilterTableDlg", "Table 1", nullptr));
        ck_9->setText(QApplication::translate("FilterTableDlg", "Table 9", nullptr));
        ck_2->setText(QApplication::translate("FilterTableDlg", "Table 2", nullptr));
        ck_10->setText(QApplication::translate("FilterTableDlg", "Table 10", nullptr));
        ck_3->setText(QApplication::translate("FilterTableDlg", "Table 3", nullptr));
        ck_11->setText(QApplication::translate("FilterTableDlg", "Table 11", nullptr));
        ck_4->setText(QApplication::translate("FilterTableDlg", "Table 4", nullptr));
        ck_12->setText(QApplication::translate("FilterTableDlg", "Table 12", nullptr));
        ck_5->setText(QApplication::translate("FilterTableDlg", "Table 5", nullptr));
        ck_13->setText(QApplication::translate("FilterTableDlg", "Table 13", nullptr));
        ck_6->setText(QApplication::translate("FilterTableDlg", "Table 6", nullptr));
        ck_14->setText(QApplication::translate("FilterTableDlg", "Table 14", nullptr));
        ck_7->setText(QApplication::translate("FilterTableDlg", "Table 7", nullptr));
        ck_15->setText(QApplication::translate("FilterTableDlg", "Table 15", nullptr));
        ck_8->setText(QApplication::translate("FilterTableDlg", "Table 8", nullptr));
        ck_16->setText(QApplication::translate("FilterTableDlg", "Table 16", nullptr));
        ck_All->setText(QApplication::translate("FilterTableDlg", "Select All", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterTableDlg: public Ui_FilterTableDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTERTABLEDLG_H
