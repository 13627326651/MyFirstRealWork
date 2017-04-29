/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QPushButton *pushButton_10;
    QPushButton *pushButton_3;
    QPushButton *pushButton_11;
    QPushButton *pushButton_4;
    QPushButton *pushButton_12;
    QPushButton *pushButton_5;
    QPushButton *pushButton_13;
    QPushButton *pushButton_6;
    QPushButton *pushButton_14;
    QPushButton *pushButton_7;
    QPushButton *pushButton_15;
    QPushButton *pushButton_8;
    QPushButton *pushButton_16;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(568, 483);
        verticalLayout = new QVBoxLayout(MyWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textBrowser = new QTextBrowser(MyWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton = new QPushButton(MyWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_9 = new QPushButton(MyWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(MyWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_10 = new QPushButton(MyWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout->addWidget(pushButton_10, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(MyWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 0, 1, 1);

        pushButton_11 = new QPushButton(MyWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));

        gridLayout->addWidget(pushButton_11, 2, 1, 1, 1);

        pushButton_4 = new QPushButton(MyWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 3, 0, 1, 1);

        pushButton_12 = new QPushButton(MyWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));

        gridLayout->addWidget(pushButton_12, 3, 1, 1, 1);

        pushButton_5 = new QPushButton(MyWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 4, 0, 1, 1);

        pushButton_13 = new QPushButton(MyWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));

        gridLayout->addWidget(pushButton_13, 4, 1, 1, 1);

        pushButton_6 = new QPushButton(MyWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 5, 0, 1, 1);

        pushButton_14 = new QPushButton(MyWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));

        gridLayout->addWidget(pushButton_14, 5, 1, 1, 1);

        pushButton_7 = new QPushButton(MyWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 6, 0, 1, 1);

        pushButton_15 = new QPushButton(MyWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));

        gridLayout->addWidget(pushButton_15, 6, 1, 1, 1);

        pushButton_8 = new QPushButton(MyWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 7, 0, 1, 1);

        pushButton_16 = new QPushButton(MyWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));

        gridLayout->addWidget(pushButton_16, 7, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "Form", 0));
        pushButton->setText(QApplication::translate("MyWidget", "1.\350\216\267\345\217\226\346\211\200\346\234\211\347\227\205\344\272\272\344\277\241\346\201\257", 0));
        pushButton_9->setText(QApplication::translate("MyWidget", "9.\345\210\240\351\231\244\345\233\276\347\211\207", 0));
        pushButton_2->setText(QApplication::translate("MyWidget", "2 \350\216\267\345\217\226\346\214\207\345\256\232\346\202\243\350\200\205\347\232\204\346\211\200\346\234\211\346\243\200\346\237\245\344\277\241\346\201\257", 0));
        pushButton_10->setText(QApplication::translate("MyWidget", "10.\344\277\256\346\224\271\347\227\205\344\272\272\344\277\241\346\201\257", 0));
        pushButton_3->setText(QApplication::translate("MyWidget", "3 \350\216\267\345\217\226\346\214\207\345\256\232\346\202\243\350\200\205\346\214\207\345\256\232\346\243\200\346\237\245\347\232\204\346\211\200\346\234\211\345\233\276\347\211\207\344\277\241\346\201\257", 0));
        pushButton_11->setText(QApplication::translate("MyWidget", "11.\344\277\256\346\224\271\346\243\200\346\237\245\344\277\241\346\201\257", 0));
        pushButton_4->setText(QApplication::translate("MyWidget", "4 \346\267\273\345\212\240\347\227\205\344\272\272", 0));
        pushButton_12->setText(QApplication::translate("MyWidget", "12.\344\277\256\346\224\271\345\233\276\347\211\207\344\277\241\346\201\257", 0));
        pushButton_5->setText(QApplication::translate("MyWidget", "5 \346\267\273\345\212\240\346\243\200\346\237\245", 0));
        pushButton_13->setText(QApplication::translate("MyWidget", "13.\346\240\271\346\215\256\347\227\205\344\272\272id\350\216\267\345\217\226\347\227\205\344\272\272\344\277\241\346\201\257", 0));
        pushButton_6->setText(QApplication::translate("MyWidget", " 6 \346\267\273\345\212\240\345\233\276\347\211\207\344\277\241\346\201\257", 0));
        pushButton_14->setText(QApplication::translate("MyWidget", "14.\346\240\271\346\215\256\346\243\200\346\237\245id\350\216\267\345\217\226\346\243\200\346\237\245\344\277\241\346\201\257", 0));
        pushButton_7->setText(QApplication::translate("MyWidget", "7 \345\210\240\351\231\244\347\227\205\344\272\272", 0));
        pushButton_15->setText(QApplication::translate("MyWidget", "15.\350\216\267\345\217\226\346\202\243\350\200\205\346\200\273\346\225\260", 0));
        pushButton_8->setText(QApplication::translate("MyWidget", "8 \345\210\240\351\231\244\346\243\200\346\237\245", 0));
        pushButton_16->setText(QApplication::translate("MyWidget", "16\343\200\202\350\216\267\345\217\226\346\211\200\346\234\211\346\243\200\346\237\245\344\277\241\346\201\257", 0));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
