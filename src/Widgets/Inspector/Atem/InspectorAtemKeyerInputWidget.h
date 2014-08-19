#pragma once

#include "../../Shared.h"
#include "ui_InspectorAtemKeyerInputWidget.h"

#include "AtemDevice.h"

#include "Commands/Atem/AtemKeyerInputCommand.h"
#include "Events/Atem/AtemDeviceChangedEvent.h"
#include "Events/Rundown/RundownItemSelectedEvent.h"
#include "Models/LibraryModel.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>

#include <QtGui/QWidget>

class WIDGETS_EXPORT InspectorAtemKeyerInputWidget : public QWidget, Ui::InspectorAtemKeyerInputWidget
{
    Q_OBJECT

    public:
        explicit InspectorAtemKeyerInputWidget(QWidget* parent = 0);

    private:
        LibraryModel* model;
        AtemKeyerInputCommand* command;

        void loadAtemKeyer();
		void loadAtemInput(QMap<quint16, QAtemConnection::InputInfo> inputs);
        void blockAllSignals(bool block);

        Q_SLOT void keyerChanged(int);
        Q_SLOT void inputChanged(int);
        Q_SLOT void triggerOnNextChanged(int);
        Q_SLOT void rundownItemSelected(const RundownItemSelectedEvent&);
        Q_SLOT void atemDeviceChanged(const AtemDeviceChangedEvent&);
};
