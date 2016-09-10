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

#ifndef COREVARIATIONCOMMANDMESSAGE_H
#define COREVARIATIONCOMMANDMESSAGE_H

#include "control/CoreDomesticMessage.h"
#include "remote/VariationCommandMessage.h"

namespace deltadoreX2d
{

class CoreVariationCommandMessage : public CoreDomesticMessage, public virtual VariationCommandMessage
{
    public :
        CoreVariationCommandMessage();
        CoreVariationCommandMessage(const std::vector<byte>& frame);
        ~CoreVariationCommandMessage();

        Family getFamily() const;

        const VariationCommand& getCommand() const;
        void setCommand(const VariationCommand& command);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        VariationCommand m_command;
};
}

#endif /* COREVARIATIONCOMMANDMESSAGE_H */
