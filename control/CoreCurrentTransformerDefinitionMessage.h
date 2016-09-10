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

#ifndef CORECURRENTTRANSFORMERDEFINITIONMESSAGE_H
#define CORECURRENTTRANSFORMERDEFINITIONMESSAGE_H

#include "control/CoreDomesticMessage.h"
#include "metering/CurrentTransformerDefinitionMessage.h"

namespace deltadoreX2d
{

class CoreCurrentTransformerDefinitionMessage : public CoreDomesticMessage, public virtual CurrentTransformerDefinitionMessage
{
    public :
        CoreCurrentTransformerDefinitionMessage();
        CoreCurrentTransformerDefinitionMessage(const std::vector<byte>& frame);
        ~CoreCurrentTransformerDefinitionMessage();

        Family getFamily() const;

        const RegisterSelection& getCurrentTransformer1Definition() const;
        void setCurrentTransformer1Definition(const RegisterSelection& selection);
        const RegisterSelection& getCurrentTransformer2Definition() const;
        void setCurrentTransformer2Definition(const RegisterSelection& selection);
        const RegisterSelection& getCurrentTransformer3Definition() const;
        void setCurrentTransformer3Definition(const RegisterSelection& selection);

        void serialize(std::vector<byte>& frame) const;
		bool instanceOf(MessageClass type) const;
		Message* clone() const;
		void* derived();
		CoreMessage* core();

    private :
        RegisterSelection m_currentTransformer1;
        RegisterSelection m_currentTransformer2;
        RegisterSelection m_currentTransformer3;
};
}

#endif /* CORECURRENTTRANSFORMERDEFINITIONMESSAGE_H */
