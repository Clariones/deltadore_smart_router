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

#include "control/CoreCompositeMeterReadingMessage.h"

namespace deltadoreX2d
{

CoreCompositeMeterReadingMessage::CoreCompositeMeterReadingMessage() :
	m_tariff(ElectricityTariff::BASE),
	m_unit(RegisterUnit::WH),
	m_selection(CompositeRegisterSelection::CURRENT_TRANSFORMERS_1_2_3)
{
    //
}

CoreCompositeMeterReadingMessage::CoreCompositeMeterReadingMessage(const std::vector<byte>& frame) :
	CoreDomesticMessage(frame),
	m_tariff(frame[17] & 0xEF),
	m_unit(RegisterUnit::WH),
	m_selection(frame[16] & 0xFF)
{
    if ((frame[15] & 0xFF) == 0x0E)
    {
		m_unit = ((frame[17] & 0x10) == 0x10) ? RegisterUnit::EURO : RegisterUnit::KWH;
	}
	if (!m_isAnswerRequest)
	{
		if (m_unit == RegisterUnit::WH)
		{
			m_register1 = (frame[21] & 0xFF) << 24;
			m_register1 += (frame[20] & 0xFF) << 16;
			m_register1 += (frame[19] & 0xFF) << 8;
			m_register1 += frame[18] & 0xFF;
			m_register2 = (frame[25] & 0xFF) << 24;
			m_register2 += (frame[24] & 0xFF) << 16;
			m_register2 += (frame[23] & 0xFF) << 8;
			m_register2 += frame[22] & 0xFF;
			m_register3 = (frame[29] & 0xFF) << 24;
			m_register3 += (frame[28] & 0xFF) << 16;
			m_register3 += (frame[27] & 0xFF) << 8;
			m_register3 += frame[26] & 0xFF;
		}
		else
		{
			m_register1 = (frame[20] & 0xFF) << 16;
			m_register1 += (frame[19] & 0xFF) << 8;
			m_register1 += frame[18] & 0xFF;
			m_register2 = (frame[23] & 0xFF) << 16;
			m_register2 += (frame[22] & 0xFF) << 8;
			m_register2 += frame[21] & 0xFF;
			m_register3 = (frame[26] & 0xFF) << 16;
			m_register3 += (frame[25] & 0xFF) << 8;
			m_register3 += frame[24] & 0xFF;
		}
	}
}

CoreCompositeMeterReadingMessage::~CoreCompositeMeterReadingMessage()
{
    //
}

Family CoreCompositeMeterReadingMessage::getFamily() const
{
    return METERING;
}

const ElectricityTariffOption CoreCompositeMeterReadingMessage::getTariffOption() const
{
    return ElectricityTariffOption(m_tariff.toInt() & 0xE0);
}

void CoreCompositeMeterReadingMessage::setTariffOption(const ElectricityTariffOption& option)
{
    if (option == ElectricityTariffOption::BASE)
    {
        m_tariff = ElectricityTariff::BASE;
    }
    else
    {
        m_tariff = ElectricityTariff(option.toInt() + 14);
    }
}

const ElectricityTariff& CoreCompositeMeterReadingMessage::getCurrentTariff() const
{
    return m_tariff;
}

void CoreCompositeMeterReadingMessage::setCurrentTariff(const ElectricityTariff& tariff)
{
    m_tariff = tariff;
}

const CompositeRegisterSelection& CoreCompositeMeterReadingMessage::getSelection() const
{
	return m_selection;
}

void CoreCompositeMeterReadingMessage::setSelection(const CompositeRegisterSelection& selection)
{
	m_selection = selection;
}

const RegisterUnit& CoreCompositeMeterReadingMessage::getUnit() const
{
    return m_unit;
}

void CoreCompositeMeterReadingMessage::setUnit(const RegisterUnit& unit)
{
    m_unit = unit;
}

long CoreCompositeMeterReadingMessage::getRegister1() const
{
    return m_register1;
}

void CoreCompositeMeterReadingMessage::setRegister1(long value)
{
    m_register1 = value;
}

long CoreCompositeMeterReadingMessage::getRegister2() const
{
    return m_register2;
}

void CoreCompositeMeterReadingMessage::setRegister2(long value)
{
    m_register2 = value;
}

long CoreCompositeMeterReadingMessage::getRegister3() const
{
    return m_register3;
}

void CoreCompositeMeterReadingMessage::setRegister3(long value)
{
    m_register3 = value;
}

void CoreCompositeMeterReadingMessage::serialize(std::vector<byte>& frame) const
{
	if (m_isAnswerRequest)
	{
		frame.assign(18, 0);
	}
	else if (m_unit == RegisterUnit::WH)
	{
		frame.assign(30, 0);

	    frame[18] = (byte)(m_register1 & 0xFF);
		frame[19] = (byte)((m_register1 >> 8) & 0xFF);
		frame[20] = (byte)((m_register1 >> 16) & 0xFF);
		frame[21] = (byte)((m_register1 >> 24) & 0xFF);
		frame[22] = (byte)(m_register2 & 0xFF);
		frame[23] = (byte)((m_register2 >> 8) & 0xFF);
		frame[24] = (byte)((m_register2 >> 16) & 0xFF);
		frame[25] = (byte)((m_register2 >> 24) & 0xFF);
		frame[26] = (byte)(m_register3 & 0xFF);
		frame[27] = (byte)((m_register3 >> 8) & 0xFF);
		frame[28] = (byte)((m_register3 >> 16) & 0xFF);
		frame[29] = (byte)((m_register3 >> 24) & 0xFF);
	}
	else
	{
		frame.assign(27, 0);

		frame[18] = (byte)(m_register1 & 0xFF);
		frame[19] = (byte)((m_register1 >> 8) & 0xFF);
		frame[20] = (byte)((m_register1 >> 16) & 0xFF);
		frame[21] = (byte)(m_register2 & 0xFF);
		frame[22] = (byte)((m_register2 >> 8) & 0xFF);
		frame[23] = (byte)((m_register2 >> 16) & 0xFF);
		frame[24] = (byte)(m_register3 & 0xFF);
		frame[25] = (byte)((m_register3 >> 8) & 0xFF);
		frame[26] = (byte)((m_register3 >> 16) & 0xFF);
	}
	frame[17] = (byte)m_tariff.toInt();
	if (m_unit == RegisterUnit::EURO) { frame[17] |= 0x10; }
	frame[16] = (byte)m_selection.toInt();
	frame[15] = (m_unit == RegisterUnit::WH) ? (byte)0xF9 : (byte)0x0E;

    CoreDomesticMessage::serialize(frame);
}

bool CoreCompositeMeterReadingMessage::instanceOf(MessageClass type) const
{
	if (type == CompositeMeterReadingMessage_t) { return true; }
	return false;
}

Message* CoreCompositeMeterReadingMessage::clone() const
{
	return new CoreCompositeMeterReadingMessage(*this);
}

void* CoreCompositeMeterReadingMessage::derived()
{
	return (CompositeMeterReadingMessage*)this;
}

CoreMessage* CoreCompositeMeterReadingMessage::core()
{
	return this;
}
}
