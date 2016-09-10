/*
** Copyright (C) 2010 Eff'Innov Technologies.  All rights reserved.
** May not be redistributed without prior written permission.
**
** Based on Java version by DeltaDore, subject to DeltaDore copyrights
**
** Note: Eff'Innov Technologies disclaims responsibility for any malfunction
** or error that may arise from any change to the current file, provided that such
** change have not been submitted to and formerly approved by Eff'Innov Technologies,
** prior to the occurence of such malfunction or error
**
** Author: Mickael Leforestier (mickael.leforestier@effinnov.com)
**
** History log:
** ------------------------------------------------------------------------------
** Author              | Date             | Changes
** ------------------------------------------------------------------------------
** mleforestier        | 092410           | First version
** ylebret             | 280212           | refactoring
*/

#include "control/CoreMeterReadingMessage.h"

namespace deltadoreX2d
{

CoreMeterReadingMessage::CoreMeterReadingMessage() :
	m_tariff(ElectricityTariff::BASE),
	m_unit(RegisterUnit::WH),
	m_selection(RegisterSelection::TOTAL)
{
    //
}

CoreMeterReadingMessage::CoreMeterReadingMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_tariff(frame[17] & 0xEF),
	m_unit(RegisterUnit::WH),
	m_selection(frame[16] & 0xFF)
{
    if ((frame[15] & 0xFF) == 0xF9)
    {
		if (!m_isAnswerRequest)
		{
			m_register = (frame[21] & 0xFF) << 24;
			m_register += (frame[20] & 0xFF) << 16;
			m_register += (frame[19] & 0xFF) << 8;
			m_register += frame[18] & 0xFF;
		}
	}
	else
	{
		m_unit = ((frame[17] & 0x10) == 0x10) ? RegisterUnit::EURO : RegisterUnit::KWH;
		if (!m_isAnswerRequest)
		{
			m_register = (frame[20] & 0xFF) << 16;
			m_register += (frame[19] & 0xFF) << 8;
			m_register += frame[18] & 0xFF;
		}
	}
}

CoreMeterReadingMessage::~CoreMeterReadingMessage()
{
    //
}

Family CoreMeterReadingMessage::getFamily() const
{
    return METERING;
}

const ElectricityTariffOption CoreMeterReadingMessage::getTariffOption() const
{
    return ElectricityTariffOption(m_tariff.toInt() & 0xE0);
}

void CoreMeterReadingMessage::setTariffOption(const ElectricityTariffOption& option)
{
    m_tariff = ElectricityTariff(option.toInt());
}

const ElectricityTariff& CoreMeterReadingMessage::getCurrentTariff() const
{
    return m_tariff;
}

void CoreMeterReadingMessage::setCurrentTariff(const ElectricityTariff& tariff)
{
    m_tariff = tariff;
}

const RegisterSelection& CoreMeterReadingMessage::getSelection() const
{
    return m_selection;
}

void CoreMeterReadingMessage::setSelection(const RegisterSelection& selection)
{
    m_selection = selection;
}

const RegisterUnit& CoreMeterReadingMessage::getUnit() const
{
    return m_unit;
}

void CoreMeterReadingMessage::setUnit(const RegisterUnit& unit)
{
    m_unit = unit;
}

long CoreMeterReadingMessage::getRegister() const
{
    return m_register;
}

void CoreMeterReadingMessage::setRegister(long value)
{
    m_register = value;
}

void CoreMeterReadingMessage::serialize(std::vector<byte>& frame) const
{
	if (m_unit == RegisterUnit::WH)
	{
		if (m_isAnswerRequest)
		{
			frame.assign(18, 0);
		}
		else
		{
			frame.assign(22, 0);
		    frame[18] = (byte)(m_register & 0xFF);
			frame[19] = (byte)((m_register >> 8) & 0xFF);
			frame[20] = (byte)((m_register >> 16) & 0xFF);
			frame[21] = (byte)((m_register >> 24) & 0xFF);
		}
		frame[15] = (byte)0xF9;
	}
	else
	{
		if (m_isAnswerRequest)
		{
			frame.assign(18, 0);
		}
		else
		{
			frame.assign(21, 0);
		    frame[18] = (byte)(m_register & 0xFF);
			frame[19] = (byte)((m_register >> 8) & 0xFF);
			frame[20] = (byte)((m_register >> 16) & 0xFF);
		}
		frame[15] = (byte)0x0E;
	}

	frame[16] = (byte)m_selection.toInt();
	frame[17] = (byte)m_tariff.toInt();
	if (m_unit == RegisterUnit::EURO) { frame[17] |= 0x10; }

    CoreDomesticMessage::serialize(frame);
}

bool CoreMeterReadingMessage::instanceOf(MessageClass type) const
{
	if (type == MeterReadingMessage_t) { return true; }
	return false;
}

Message* CoreMeterReadingMessage::clone() const
{
	return new CoreMeterReadingMessage(*this);
}

void* CoreMeterReadingMessage::derived()
{
	return (MeterReadingMessage*)this;
}

CoreMessage* CoreMeterReadingMessage::core()
{
	return this;
}
}
