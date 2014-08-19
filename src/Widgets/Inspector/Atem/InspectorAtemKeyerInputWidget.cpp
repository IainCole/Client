#include "InspectorAtemKeyerInputWidget.h"

#include "Global.h"

#include "DatabaseManager.h"
#include "DeviceManager.h"
#include "AtemDeviceManager.h"
#include "GpiManager.h"
#include "EventManager.h"
#include "Models/Atem/AtemKeyerModel.h"

#include <QtGui/QApplication>

InspectorAtemKeyerInputWidget::InspectorAtemKeyerInputWidget(QWidget* parent)
    : QWidget(parent),
      model(NULL), command(NULL)
{
    setupUi(this);

    QObject::connect(&EventManager::getInstance(), SIGNAL(rundownItemSelected(const RundownItemSelectedEvent&)), this, SLOT(rundownItemSelected(const RundownItemSelectedEvent&)));

    loadAtemKeyer();
}

void InspectorAtemKeyerInputWidget::rundownItemSelected(const RundownItemSelectedEvent& event)
{
    this->model = event.getLibraryModel();

    blockAllSignals(true);

    if (dynamic_cast<AtemKeyerInputCommand*>(event.getCommand()))
    {
        this->command = dynamic_cast<AtemKeyerInputCommand*>(event.getCommand());

		this->comboBoxInput->clear();
        const QSharedPointer<AtemDevice> device = AtemDeviceManager::getInstance().getDeviceByName(this->model->getDeviceName());
        if (device != NULL)
            loadAtemInput(device->inputInfos());

        this->comboBoxKeyer->setCurrentIndex(this->comboBoxKeyer->findData(this->command->getKeyer()));
        this->checkBoxTriggerOnNext->setChecked(this->command->getTriggerOnNext());
    }

    blockAllSignals(false);
}

void InspectorAtemKeyerInputWidget::blockAllSignals(bool block)
{
    this->comboBoxKeyer->blockSignals(block);
    this->comboBoxInput->blockSignals(block);
    this->checkBoxTriggerOnNext->blockSignals(block);
}

void InspectorAtemKeyerInputWidget::loadAtemKeyer()
{
    // We do not have a command object, block the signals.
    // Events will not be triggered while we update the values.
    this->comboBoxKeyer->blockSignals(true);

    QList<AtemKeyerModel> models = DatabaseManager::getInstance().getAtemKeyer();
    foreach (AtemKeyerModel model, models)
        this->comboBoxKeyer->addItem(model.getName(), model.getValue());

    this->comboBoxKeyer->blockSignals(false);
}

void InspectorAtemKeyerInputWidget::loadAtemInput(QMap<quint16, QAtemConnection::InputInfo> inputs)
{
    // We do not have a command object, block the signals.
    // Events will not be triggered while we update the values
    this->comboBoxInput->blockSignals(true);

    this->comboBoxInput->clear();

    foreach (quint16 key, inputs.keys())
        this->comboBoxInput->addItem(inputs.value(key).longText, inputs.value(key).index);

    this->comboBoxInput->blockSignals(false);
}

void InspectorAtemKeyerInputWidget::keyerChanged(int index)
{
    this->command->setKeyer(this->comboBoxKeyer->itemData(index).toString());
}

void InspectorAtemKeyerInputWidget::inputChanged(int index)
{
	this->command->setInput(this->comboBoxInput->itemData(index).toString());
}

void InspectorAtemKeyerInputWidget::triggerOnNextChanged(int state)
{
    this->command->setTriggerOnNext((state == Qt::Checked) ? true : false);
}
