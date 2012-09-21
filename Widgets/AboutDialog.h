#pragma once

#include "Global.h"

#include "ui_AboutDialog.h"

#include <QtGui/QDialog>
#include <QtGui/QWidget>

class AboutDialog : public QDialog, Ui::AboutDialog
{
    Q_OBJECT

    public:
        explicit AboutDialog(QWidget* parent = 0);

    private:
        Q_SLOT void closeDialog();
};
