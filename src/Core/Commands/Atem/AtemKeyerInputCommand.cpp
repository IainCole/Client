#include "AtemKeyerInputCommand.h"

#include "Global.h"

AtemKeyerInputCommand::AtemKeyerInputCommand(QObject* parent)
    : AbstractCommand(parent),
      keyer(Atem::DEFAULT_KEYER), input(Atem::DEFAULT_KEYER_INPUT), triggerOnNext(Atem::DEFAULT_TRIGGER_ON_NEXT)
{
}

const QString& AtemKeyerInputCommand::getKeyer() const
{
    return this->keyer;
}

const QString& AtemKeyerInputCommand::getInput() const
{
    return this->input;
}

bool AtemKeyerInputCommand::getTriggerOnNext() const
{
    return this->triggerOnNext;
}

void AtemKeyerInputCommand::setKeyer(const QString& keyer)
{
    this->keyer = keyer;
    emit keyerChanged(this->keyer);
}

void AtemKeyerInputCommand::setInput(const QString& input)
{
    this->input = input;
    emit inputChanged(this->input);
}

void AtemKeyerInputCommand::setTriggerOnNext(bool triggerOnNext)
{
    this->triggerOnNext = triggerOnNext;
    emit triggerOnNextChanged(this->triggerOnNext);
}

void AtemKeyerInputCommand::readProperties(boost::property_tree::wptree& pt)
{
    AbstractCommand::readProperties(pt);

    setKeyer(QString::fromStdWString(pt.get(L"keyer", Atem::DEFAULT_KEYER.toStdWString())));
    setInput(pt.get(L"input", Atem::DEFAULT_KEYER_INPUT));
    setTriggerOnNext(pt.get(L"triggeronnext", Atem::DEFAULT_TRIGGER_ON_NEXT));
}

void AtemKeyerInputCommand::writeProperties(QXmlStreamWriter* writer)
{
    AbstractCommand::writeProperties(writer);

    writer->writeTextElement("keyer", this->getKeyer());
    writer->writeTextElement("input", this->getInput());
    writer->writeTextElement("triggeronnext", (getTriggerOnNext() == true) ? "true" : "false");
}
