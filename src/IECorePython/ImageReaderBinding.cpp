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

#include "boost/python.hpp"

#include "IECore/ImageReader.h"
#include "IECore/VectorTypedData.h"
#include "IECorePython/ImageReaderBinding.h"
#include "IECorePython/ReaderBinding.h"

using std::string;
using namespace boost;
using namespace boost::python;
using namespace IECore;

namespace
{

static StringVectorDataPtr channelNames( ImageReader &that )
{
	StringVectorDataPtr result( new StringVectorData );
	that.channelNames( result->writable() );
	return result;
}

} // namespace

namespace IECorePython
{

void bindImageReader()
{

	ReaderClass<ImageReader>()
		.def( "isComplete", &ImageReader::isComplete )
		.def( "channelNames", &channelNames )
		.def( "dataWindow", &ImageReader::dataWindow )
		.def( "displayWindow", &ImageReader::displayWindow )
		.def( "readChannel", (DataPtr (ImageReader::*)( const std::string &, bool ))&ImageReader::readChannel, ( arg_("name"), arg_( "raw" ) = false ) )
		.def( "sourceColorSpace", &ImageReader::sourceColorSpace )
	;

}

} // namespace IECorePython
