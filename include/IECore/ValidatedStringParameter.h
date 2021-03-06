//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2010, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef IE_CORE_VALIDATEDSTRINGPARAMETER_H
#define IE_CORE_VALIDATEDSTRINGPARAMETER_H

#include "IECore/Export.h"
#include "IECore/SimpleTypedParameter.h"

namespace IECore
{

/// This class implements a StringParameter object with validation
/// of the value based on regular expressions.
class IECORE_API ValidatedStringParameter : public StringParameter
{
	public :

		IE_CORE_DECLARERUNTIMETYPED( ValidatedStringParameter, StringParameter );

		ValidatedStringParameter( const std::string &name, const std::string &description,
			const std::string &regex, const std::string &regexDescription = "", const std::string &defaultValue = "", bool allowEmptyString = true,
			const StringParameter::PresetsContainer &presets = StringParameter::PresetsContainer(), bool presetsOnly = false, ConstCompoundObjectPtr userData = 0 );

		const std::string &regex() const;
		const std::string &regexDescription() const;
		bool allowEmptyString() const;

		/// Implemented to return true only if value is an instance of StringData and
		/// the contained string matches the regular expression specified in the constructor.
		virtual bool valueValid( const Object *value, std::string *reason = 0 ) const;

	private :

		std::string m_regex;
		std::string m_regexDescription;
		bool m_allowEmptyString;

};

IE_CORE_DECLAREPTR( ValidatedStringParameter )

} // namespace IECore

#endif // IE_CORE_VALIDATEDSTRINGPARAMETER_H
