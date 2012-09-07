#include "AboutDialog.h"

#include <QtCore/QDebug>
#include <QtCore/QString>

AboutDialog::AboutDialog(QWidget* parent) : QDialog(parent)
{
    setupUi(this);
}

void AboutDialog::closeDialog()
{
    close();
}
