/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *_step3Button;
    QPushButton *_step1Button;
    QSpacerItem *verticalSpacer;
    QPushButton *_remeshButton;
    QPushButton *_step2Button;
    QPushButton *_step4Button;
    QPushButton *_step5Button;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(400, 300);
        gridLayout = new QGridLayout(MyWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        _step3Button = new QPushButton(MyWidget);
        _step3Button->setObjectName(QString::fromUtf8("_step3Button"));

        gridLayout->addWidget(_step3Button, 3, 0, 1, 1);

        _step1Button = new QPushButton(MyWidget);
        _step1Button->setObjectName(QString::fromUtf8("_step1Button"));

        gridLayout->addWidget(_step1Button, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        _remeshButton = new QPushButton(MyWidget);
        _remeshButton->setObjectName(QString::fromUtf8("_remeshButton"));

        gridLayout->addWidget(_remeshButton, 0, 0, 1, 1);

        _step2Button = new QPushButton(MyWidget);
        _step2Button->setObjectName(QString::fromUtf8("_step2Button"));

        gridLayout->addWidget(_step2Button, 2, 0, 1, 1);

        _step4Button = new QPushButton(MyWidget);
        _step4Button->setObjectName(QString::fromUtf8("_step4Button"));

        gridLayout->addWidget(_step4Button, 4, 0, 1, 1);

        _step5Button = new QPushButton(MyWidget);
        _step5Button->setObjectName(QString::fromUtf8("_step5Button"));

        gridLayout->addWidget(_step5Button, 5, 0, 1, 1);


        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "Form", nullptr));
        _step3Button->setText(QApplication::translate("MyWidget", "Step 3", nullptr));
        _step1Button->setText(QApplication::translate("MyWidget", "Step 1", nullptr));
        _remeshButton->setText(QApplication::translate("MyWidget", "Remesh", nullptr));
        _step2Button->setText(QApplication::translate("MyWidget", "Step 2", nullptr));
        _step4Button->setText(QApplication::translate("MyWidget", "Step 4", nullptr));
        _step5Button->setText(QApplication::translate("MyWidget", "Step 5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
