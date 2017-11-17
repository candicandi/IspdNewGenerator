/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_create;
    QAction *action_open;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_insert_ok;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton_select_ok;
    QComboBox *comboBox_select_sheet;
    QFormLayout *formLayout;
    QComboBox *comboBox_sheet;
    QComboBox *comboBox_sheet_num;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit_optlog;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *label_status_result;
    QLabel *label_11;
    QProgressBar *uploadProgressBar;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QFormLayout *formLayout_6;
    QLineEdit *lineEdit_startid;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout_8;
    QLabel *label_15;
    QLineEdit *lineEdit_need_num;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_i;
    QLineEdit *lineEdit_v;
    QLineEdit *lineEdit_cap;
    QComboBox *comboBox_type;
    QComboBox *comboBox_size;
    QComboBox *comboBox_color;
    QComboBox *comboBox_bat;
    QComboBox *comboBox_water;
    QDateEdit *dateEdit;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_write;
    QMenuBar *menuBar;
    QMenu *menufile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1095, 921);
        action_create = new QAction(MainWindow);
        action_create->setObjectName(QStringLiteral("action_create"));
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QStringLiteral("action_open"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_6 = new QVBoxLayout(groupBox_5);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_insert_ok = new QPushButton(groupBox_5);
        pushButton_insert_ok->setObjectName(QStringLiteral("pushButton_insert_ok"));
        QFont font1;
        font1.setPointSize(20);
        font1.setItalic(false);
        pushButton_insert_ok->setFont(font1);

        gridLayout_2->addWidget(pushButton_insert_ok, 0, 2, 1, 1);

        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font1);

        gridLayout_2->addWidget(label_13, 0, 0, 1, 1);

        label_14 = new QLabel(groupBox_5);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font1);

        gridLayout_2->addWidget(label_14, 1, 0, 1, 1);

        pushButton_select_ok = new QPushButton(groupBox_5);
        pushButton_select_ok->setObjectName(QStringLiteral("pushButton_select_ok"));
        pushButton_select_ok->setFont(font1);

        gridLayout_2->addWidget(pushButton_select_ok, 1, 2, 1, 1);

        comboBox_select_sheet = new QComboBox(groupBox_5);
        comboBox_select_sheet->setObjectName(QStringLiteral("comboBox_select_sheet"));
        comboBox_select_sheet->setFont(font1);

        gridLayout_2->addWidget(comboBox_select_sheet, 1, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        comboBox_sheet = new QComboBox(groupBox_5);
        comboBox_sheet->setObjectName(QStringLiteral("comboBox_sheet"));
        comboBox_sheet->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, comboBox_sheet);

        comboBox_sheet_num = new QComboBox(groupBox_5);
        comboBox_sheet_num->setObjectName(QStringLiteral("comboBox_sheet_num"));
        comboBox_sheet_num->setFont(font1);

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox_sheet_num);


        gridLayout_2->addLayout(formLayout, 0, 1, 1, 1);


        verticalLayout_6->addLayout(gridLayout_2);


        horizontalLayout->addWidget(groupBox_5);

        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        textEdit_optlog = new QTextEdit(groupBox_4);
        textEdit_optlog->setObjectName(QStringLiteral("textEdit_optlog"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        textEdit_optlog->setFont(font2);

        verticalLayout_5->addWidget(textEdit_optlog);


        horizontalLayout->addWidget(groupBox_4);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(0, 0));
        groupBox_3->setMaximumSize(QSize(16777215, 120));
        groupBox_3->setFont(font);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        horizontalLayout_3->addWidget(label_10);

        label_status_result = new QLabel(groupBox_3);
        label_status_result->setObjectName(QStringLiteral("label_status_result"));
        label_status_result->setFont(font1);

        horizontalLayout_3->addWidget(label_status_result);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        horizontalLayout_3->addWidget(label_11);


        verticalLayout_4->addLayout(horizontalLayout_3);

        uploadProgressBar = new QProgressBar(groupBox_3);
        uploadProgressBar->setObjectName(QStringLiteral("uploadProgressBar"));
        uploadProgressBar->setFont(font1);
        uploadProgressBar->setValue(24);

        verticalLayout_4->addWidget(uploadProgressBar);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        formLayout_6 = new QFormLayout();
        formLayout_6->setSpacing(6);
        formLayout_6->setObjectName(QStringLiteral("formLayout_6"));
        lineEdit_startid = new QLineEdit(groupBox);
        lineEdit_startid->setObjectName(QStringLiteral("lineEdit_startid"));
        QFont font3;
        font3.setFamily(QStringLiteral("Aharoni"));
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        lineEdit_startid->setFont(font3);

        formLayout_6->setWidget(0, QFormLayout::FieldRole, lineEdit_startid);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font3);

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_16);


        horizontalLayout_5->addLayout(formLayout_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        formLayout_8 = new QFormLayout();
        formLayout_8->setSpacing(6);
        formLayout_8->setObjectName(QStringLiteral("formLayout_8"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font3);

        formLayout_8->setWidget(0, QFormLayout::LabelRole, label_15);

        lineEdit_need_num = new QLineEdit(groupBox);
        lineEdit_need_num->setObjectName(QStringLiteral("lineEdit_need_num"));
        lineEdit_need_num->setFont(font3);

        formLayout_8->setWidget(0, QFormLayout::FieldRole, lineEdit_need_num);


        horizontalLayout_5->addLayout(formLayout_8);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        formLayout_3->setWidget(5, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        formLayout_3->setWidget(6, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_9);

        lineEdit_i = new QLineEdit(groupBox);
        lineEdit_i->setObjectName(QStringLiteral("lineEdit_i"));
        lineEdit_i->setFont(font1);

        formLayout_3->setWidget(7, QFormLayout::FieldRole, lineEdit_i);

        lineEdit_v = new QLineEdit(groupBox);
        lineEdit_v->setObjectName(QStringLiteral("lineEdit_v"));
        lineEdit_v->setFont(font1);

        formLayout_3->setWidget(5, QFormLayout::FieldRole, lineEdit_v);

        lineEdit_cap = new QLineEdit(groupBox);
        lineEdit_cap->setObjectName(QStringLiteral("lineEdit_cap"));
        lineEdit_cap->setFont(font1);

        formLayout_3->setWidget(6, QFormLayout::FieldRole, lineEdit_cap);

        comboBox_type = new QComboBox(groupBox);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setFont(font1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, comboBox_type);

        comboBox_size = new QComboBox(groupBox);
        comboBox_size->setObjectName(QStringLiteral("comboBox_size"));
        comboBox_size->setFont(font1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, comboBox_size);

        comboBox_color = new QComboBox(groupBox);
        comboBox_color->setObjectName(QStringLiteral("comboBox_color"));
        comboBox_color->setFont(font1);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, comboBox_color);

        comboBox_bat = new QComboBox(groupBox);
        comboBox_bat->setObjectName(QStringLiteral("comboBox_bat"));
        comboBox_bat->setFont(font1);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, comboBox_bat);

        comboBox_water = new QComboBox(groupBox);
        comboBox_water->setObjectName(QStringLiteral("comboBox_water"));
        comboBox_water->setFont(font1);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, comboBox_water);

        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setFont(font1);

        formLayout_3->setWidget(8, QFormLayout::FieldRole, dateEdit);


        horizontalLayout_2->addLayout(formLayout_3);

        pushButton_reset = new QPushButton(groupBox);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));
        pushButton_reset->setMinimumSize(QSize(245, 350));
        pushButton_reset->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_reset);

        pushButton_write = new QPushButton(groupBox);
        pushButton_write->setObjectName(QStringLiteral("pushButton_write"));
        pushButton_write->setMinimumSize(QSize(245, 350));
        pushButton_write->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_write);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(groupBox);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1095, 23));
        menufile = new QMenu(menuBar);
        menufile->setObjectName(QStringLiteral("menufile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menufile->menuAction());
        menufile->addAction(action_create);
        menufile->addAction(action_open);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action_create->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", Q_NULLPTR));
        action_open->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        pushButton_insert_ok->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\346\217\222\345\205\245sheet", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251sheet", Q_NULLPTR));
        pushButton_select_ok->setText(QApplication::translate("MainWindow", "\347\241\256\345\256\232", Q_NULLPTR));
        comboBox_sheet->clear();
        comboBox_sheet->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Sheet", Q_NULLPTR)
        );
        comboBox_sheet_num->clear();
        comboBox_sheet_num->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "4", Q_NULLPTR)
         << QApplication::translate("MainWindow", "5", Q_NULLPTR)
         << QApplication::translate("MainWindow", "6", Q_NULLPTR)
         << QApplication::translate("MainWindow", "7", Q_NULLPTR)
         << QApplication::translate("MainWindow", "8", Q_NULLPTR)
         << QApplication::translate("MainWindow", "9", Q_NULLPTR)
         << QApplication::translate("MainWindow", "10", Q_NULLPTR)
         << QApplication::translate("MainWindow", "11", Q_NULLPTR)
         << QApplication::translate("MainWindow", "12", Q_NULLPTR)
         << QApplication::translate("MainWindow", "13", Q_NULLPTR)
         << QApplication::translate("MainWindow", "14", Q_NULLPTR)
         << QApplication::translate("MainWindow", "15", Q_NULLPTR)
         << QApplication::translate("MainWindow", "16", Q_NULLPTR)
         << QApplication::translate("MainWindow", "17", Q_NULLPTR)
         << QApplication::translate("MainWindow", "18", Q_NULLPTR)
         << QApplication::translate("MainWindow", "19", Q_NULLPTR)
         << QApplication::translate("MainWindow", "20", Q_NULLPTR)
        );
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\346\227\245\345\277\227", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\212\266\346\200\201", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\347\212\266\346\200\201\357\274\232", Q_NULLPTR));
        label_status_result->setText(QString());
        label_11->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\225\260\346\215\256\345\275\225\345\205\245", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245ID", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\351\234\200\346\261\202\344\270\252\346\225\260", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\344\272\247\345\223\201\345\236\213\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\344\272\247\345\223\201\345\244\247\345\260\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\344\272\247\345\223\201\351\242\234\350\211\262", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\224\265\346\261\240\347\261\273\345\236\213", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\351\230\262\346\260\264\347\255\211\347\272\247", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\347\224\265\345\216\213", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\347\224\265\346\261\240\345\256\271\351\207\217", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\350\276\223\345\205\245\347\224\265\346\265\201", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\346\227\245\346\234\237\346\227\266\351\227\264", Q_NULLPTR));
        pushButton_reset->setText(QApplication::translate("MainWindow", "\351\207\215\347\275\256", Q_NULLPTR));
        pushButton_write->setText(QApplication::translate("MainWindow", "\345\275\225\345\205\245", Q_NULLPTR));
        menufile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
