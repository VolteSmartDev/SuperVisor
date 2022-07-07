/********************************************************************************
** Form generated from reading UI file 'generalsetdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERALSETDLG_H
#define UI_GENERALSETDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeneralSetDlg
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *check_AutoConnect;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QComboBox *combo_refreshTime;
    QLabel *label_4;
    QLabel *label_10;
    QVBoxLayout *verticalLayout;
    QRadioButton *radio_button;
    QRadioButton *radio_timer;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *edt_SaveTimeInterval;
    QLabel *label_2;
    QCheckBox *check_NodifyStatusSaved;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *check_AutoDailySave;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *edt_FoderPath;
    QPushButton *btn_SaveFolderBrowse;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *edt_ExportTime;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *check_DeletePastLog;
    QLineEdit *edt_DeleteDay;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *reset_database;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *check_AutoRunLED;
    QFormLayout *formLayout;
    QLabel *label_5;
    QFontComboBox *fontComboBox;
    QLabel *label_6;
    QSpinBox *spinBox_FontSize;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *GeneralSetDlg)
    {
        if (GeneralSetDlg->objectName().isEmpty())
            GeneralSetDlg->setObjectName(QString::fromUtf8("GeneralSetDlg"));
        GeneralSetDlg->resize(479, 320);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(8);
        GeneralSetDlg->setFont(font);
        GeneralSetDlg->setStyleSheet(QString::fromUtf8("background-color: rgb(249, 249, 249);"));
        verticalLayout_2 = new QVBoxLayout(GeneralSetDlg);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(GeneralSetDlg);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_7 = new QVBoxLayout(tab);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        check_AutoConnect = new QCheckBox(tab);
        check_AutoConnect->setObjectName(QString::fromUtf8("check_AutoConnect"));
        check_AutoConnect->setEnabled(true);
        QFont font2;
        font2.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font2.setPointSize(10);
        check_AutoConnect->setFont(font2);

        verticalLayout_7->addWidget(check_AutoConnect);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_2->addWidget(label_3);

        combo_refreshTime = new QComboBox(tab);
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->addItem(QString());
        combo_refreshTime->setObjectName(QString::fromUtf8("combo_refreshTime"));
        combo_refreshTime->setMinimumSize(QSize(0, 26));
        combo_refreshTime->setMaximumSize(QSize(60, 16777215));
        combo_refreshTime->setFont(font1);
        combo_refreshTime->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));

        horizontalLayout_2->addWidget(combo_refreshTime);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        horizontalLayout_2->addWidget(label_4);


        verticalLayout_7->addLayout(horizontalLayout_2);

        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_10->setFont(font3);

        verticalLayout_7->addWidget(label_10);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(30, -1, -1, -1);
        radio_button = new QRadioButton(tab);
        radio_button->setObjectName(QString::fromUtf8("radio_button"));
        radio_button->setChecked(true);

        verticalLayout->addWidget(radio_button);

        radio_timer = new QRadioButton(tab);
        radio_timer->setObjectName(QString::fromUtf8("radio_timer"));
        radio_timer->setChecked(false);

        verticalLayout->addWidget(radio_timer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(20, -1, -1, -1);
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        edt_SaveTimeInterval = new QLineEdit(tab);
        edt_SaveTimeInterval->setObjectName(QString::fromUtf8("edt_SaveTimeInterval"));
        edt_SaveTimeInterval->setEnabled(false);
        edt_SaveTimeInterval->setMinimumSize(QSize(0, 28));
        edt_SaveTimeInterval->setMaximumSize(QSize(50, 16777215));
        QFont font4;
        font4.setPointSize(10);
        edt_SaveTimeInterval->setFont(font4);
        edt_SaveTimeInterval->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_SaveTimeInterval->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(edt_SaveTimeInterval);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout);

        check_NodifyStatusSaved = new QCheckBox(tab);
        check_NodifyStatusSaved->setObjectName(QString::fromUtf8("check_NodifyStatusSaved"));
        check_NodifyStatusSaved->setEnabled(true);
        check_NodifyStatusSaved->setFont(font2);

        verticalLayout_7->addWidget(check_NodifyStatusSaved);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_5 = new QVBoxLayout(tab_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(-1, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(12);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        check_AutoDailySave = new QCheckBox(tab_2);
        check_AutoDailySave->setObjectName(QString::fromUtf8("check_AutoDailySave"));
        check_AutoDailySave->setEnabled(true);
        check_AutoDailySave->setFont(font4);

        verticalLayout_4->addWidget(check_AutoDailySave);

        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setFont(font4);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        edt_FoderPath = new QLineEdit(groupBox);
        edt_FoderPath->setObjectName(QString::fromUtf8("edt_FoderPath"));
        edt_FoderPath->setEnabled(true);
        edt_FoderPath->setMinimumSize(QSize(50, 28));
        QFont font5;
        font5.setPointSize(8);
        edt_FoderPath->setFont(font5);
        edt_FoderPath->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_FoderPath->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        edt_FoderPath->setReadOnly(true);

        horizontalLayout_5->addWidget(edt_FoderPath);

        btn_SaveFolderBrowse = new QPushButton(groupBox);
        btn_SaveFolderBrowse->setObjectName(QString::fromUtf8("btn_SaveFolderBrowse"));
        btn_SaveFolderBrowse->setMinimumSize(QSize(70, 28));
        btn_SaveFolderBrowse->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 4px;\n"
"	background-color: #dadada; color: 323232;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: #eaeaea;\n"
"}"));

        horizontalLayout_5->addWidget(btn_SaveFolderBrowse);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        edt_ExportTime = new QLineEdit(groupBox);
        edt_ExportTime->setObjectName(QString::fromUtf8("edt_ExportTime"));
        edt_ExportTime->setMinimumSize(QSize(50, 28));
        edt_ExportTime->setFont(font4);
        edt_ExportTime->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_ExportTime->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(edt_ExportTime);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout_4->addWidget(groupBox);


        verticalLayout_5->addLayout(verticalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        check_DeletePastLog = new QCheckBox(tab_2);
        check_DeletePastLog->setObjectName(QString::fromUtf8("check_DeletePastLog"));
        check_DeletePastLog->setEnabled(true);
        check_DeletePastLog->setFont(font4);

        horizontalLayout_7->addWidget(check_DeletePastLog);

        edt_DeleteDay = new QLineEdit(tab_2);
        edt_DeleteDay->setObjectName(QString::fromUtf8("edt_DeleteDay"));
        edt_DeleteDay->setMinimumSize(QSize(50, 28));
        edt_DeleteDay->setMaximumSize(QSize(60, 16777215));
        edt_DeleteDay->setFont(font4);
        edt_DeleteDay->setStyleSheet(QString::fromUtf8("border: 2px solid #00afff;\n"
"border-radius: 4px;\n"
"background-color: #ffffff; color: #323232;"));
        edt_DeleteDay->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(edt_DeleteDay);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_7->addWidget(label_11);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        reset_database = new QPushButton(tab_2);
        reset_database->setObjectName(QString::fromUtf8("reset_database"));

        horizontalLayout_3->addWidget(reset_database);


        verticalLayout_5->addLayout(horizontalLayout_3);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_6 = new QVBoxLayout(tab_3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        check_AutoRunLED = new QCheckBox(tab_3);
        check_AutoRunLED->setObjectName(QString::fromUtf8("check_AutoRunLED"));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Times New Roman"));
        font6.setPointSize(11);
        check_AutoRunLED->setFont(font6);

        verticalLayout_6->addWidget(check_AutoRunLED);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(tab_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font4);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        fontComboBox = new QFontComboBox(tab_3);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        QFont font7;
        font7.setPointSize(12);
        fontComboBox->setFont(font7);
        fontComboBox->setStyleSheet(QString::fromUtf8("background-color: #ffffff; color: #323232;"));
        fontComboBox->setCurrentFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, fontComboBox);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font4);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        spinBox_FontSize = new QSpinBox(tab_3);
        spinBox_FontSize->setObjectName(QString::fromUtf8("spinBox_FontSize"));
        spinBox_FontSize->setFont(font4);
        spinBox_FontSize->setStyleSheet(QString::fromUtf8("background-color: #ffffff; color: #323232;"));
        spinBox_FontSize->setMinimum(12);
        spinBox_FontSize->setSingleStep(2);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBox_FontSize);


        verticalLayout_6->addLayout(formLayout);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_2->addWidget(tabWidget);

        line = new QFrame(GeneralSetDlg);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        btn_OK = new QPushButton(GeneralSetDlg);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));
        btn_OK->setMinimumSize(QSize(80, 36));
        btn_OK->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 4px;\n"
"	background-color: #00afff; color: white;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: #23ccff;\n"
"}"));

        horizontalLayout_4->addWidget(btn_OK);

        btn_Cancel = new QPushButton(GeneralSetDlg);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));
        btn_Cancel->setMinimumSize(QSize(80, 36));
        btn_Cancel->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-radius: 4px;\n"
"	background-color: #dadada; color: 323232;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"	background-color: #eaeaea;\n"
"}\n"
"\n"
"QPushButton::pressed {\n"
"	background-color: #cacaca;\n"
"}"));

        horizontalLayout_4->addWidget(btn_Cancel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(GeneralSetDlg);
        QObject::connect(btn_Cancel, SIGNAL(clicked()), GeneralSetDlg, SLOT(reject()));

        tabWidget->setCurrentIndex(0);
        btn_OK->setDefault(true);


        QMetaObject::connectSlotsByName(GeneralSetDlg);
    } // setupUi

    void retranslateUi(QDialog *GeneralSetDlg)
    {
        GeneralSetDlg->setWindowTitle(QApplication::translate("GeneralSetDlg", "Settings", nullptr));
        check_AutoConnect->setText(QApplication::translate("GeneralSetDlg", "Connect to PLC device automatically when the program starts", nullptr));
        label_3->setText(QApplication::translate("GeneralSetDlg", "Refresh table status every  ", nullptr));
        combo_refreshTime->setItemText(0, QApplication::translate("GeneralSetDlg", "1", nullptr));
        combo_refreshTime->setItemText(1, QApplication::translate("GeneralSetDlg", "2", nullptr));
        combo_refreshTime->setItemText(2, QApplication::translate("GeneralSetDlg", "3", nullptr));
        combo_refreshTime->setItemText(3, QApplication::translate("GeneralSetDlg", "4", nullptr));
        combo_refreshTime->setItemText(4, QApplication::translate("GeneralSetDlg", "5", nullptr));
        combo_refreshTime->setItemText(5, QApplication::translate("GeneralSetDlg", "6", nullptr));
        combo_refreshTime->setItemText(6, QApplication::translate("GeneralSetDlg", "7", nullptr));
        combo_refreshTime->setItemText(7, QApplication::translate("GeneralSetDlg", "8", nullptr));
        combo_refreshTime->setItemText(8, QApplication::translate("GeneralSetDlg", "9", nullptr));
        combo_refreshTime->setItemText(9, QApplication::translate("GeneralSetDlg", "10", nullptr));
        combo_refreshTime->setItemText(10, QApplication::translate("GeneralSetDlg", "15", nullptr));
        combo_refreshTime->setItemText(11, QApplication::translate("GeneralSetDlg", "30", nullptr));
        combo_refreshTime->setItemText(12, QApplication::translate("GeneralSetDlg", "60", nullptr));

        label_4->setText(QApplication::translate("GeneralSetDlg", "seconds", nullptr));
        label_10->setText(QApplication::translate("GeneralSetDlg", "Log table status", nullptr));
        radio_button->setText(QApplication::translate("GeneralSetDlg", "When button event is triggered.", nullptr));
        radio_timer->setText(QApplication::translate("GeneralSetDlg", "When timer is triggered.", nullptr));
        label->setText(QApplication::translate("GeneralSetDlg", "Save status into database every  ", nullptr));
        edt_SaveTimeInterval->setInputMask(QApplication::translate("GeneralSetDlg", "00", nullptr));
        edt_SaveTimeInterval->setText(QApplication::translate("GeneralSetDlg", "1", nullptr));
        label_2->setText(QApplication::translate("GeneralSetDlg", "minutes", nullptr));
        check_NodifyStatusSaved->setText(QApplication::translate("GeneralSetDlg", "Notify when status data saved into database.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("GeneralSetDlg", "General", nullptr));
        check_AutoDailySave->setText(QApplication::translate("GeneralSetDlg", "Automatically export status logs everyday", nullptr));
        groupBox->setTitle(QApplication::translate("GeneralSetDlg", "Automatic export settings", nullptr));
        label_7->setText(QApplication::translate("GeneralSetDlg", "Folder path to save=", nullptr));
        edt_FoderPath->setText(QApplication::translate("GeneralSetDlg", "D:/", nullptr));
        btn_SaveFolderBrowse->setText(QApplication::translate("GeneralSetDlg", "Browse", nullptr));
        label_8->setText(QApplication::translate("GeneralSetDlg", "Export logs at", nullptr));
        edt_ExportTime->setInputMask(QApplication::translate("GeneralSetDlg", "99:99;_", nullptr));
        edt_ExportTime->setText(QApplication::translate("GeneralSetDlg", "19:00", nullptr));
        edt_ExportTime->setPlaceholderText(QApplication::translate("GeneralSetDlg", "19:00", nullptr));
        label_9->setText(QApplication::translate("GeneralSetDlg", " everyday (eg. 01:30)", nullptr));
        check_DeletePastLog->setText(QApplication::translate("GeneralSetDlg", "Delete status logs from database past than  ", nullptr));
        edt_DeleteDay->setInputMask(QApplication::translate("GeneralSetDlg", "D", nullptr));
        edt_DeleteDay->setText(QApplication::translate("GeneralSetDlg", "2", nullptr));
        edt_DeleteDay->setPlaceholderText(QApplication::translate("GeneralSetDlg", "30", nullptr));
        label_11->setText(QApplication::translate("GeneralSetDlg", "months", nullptr));
        reset_database->setText(QApplication::translate("GeneralSetDlg", "Delete All data from database.", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("GeneralSetDlg", "Status logging", nullptr));
        check_AutoRunLED->setText(QApplication::translate("GeneralSetDlg", "Automatically run LED Display Programs when the program starts.", nullptr));
        label_5->setText(QApplication::translate("GeneralSetDlg", "Font style", nullptr));
        label_6->setText(QApplication::translate("GeneralSetDlg", "Font size", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("GeneralSetDlg", "LED Display", nullptr));
        btn_OK->setText(QApplication::translate("GeneralSetDlg", "Apply", nullptr));
        btn_Cancel->setText(QApplication::translate("GeneralSetDlg", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GeneralSetDlg: public Ui_GeneralSetDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERALSETDLG_H
