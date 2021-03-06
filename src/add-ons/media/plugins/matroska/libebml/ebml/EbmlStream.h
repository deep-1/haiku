/****************************************************************************
** libebml : parse EBML files, see http://embl.sourceforge.net/
**
** <file/class description>
**
** Copyright (C) 2002-2004 Steve Lhomme.  All rights reserved.
**
** This file is part of libebml.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
** 
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
** 
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.
**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id: EbmlStream.h 639 2004-07-09 20:59:14Z mosu $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBEBML_STREAM_H
#define LIBEBML_STREAM_H

#include "EbmlTypes.h"
#include "IOCallback.h"
#include "EbmlElement.h"

START_LIBEBML_NAMESPACE

/*!
    \class EbmlStream
    \brief Handle an input/output stream of EBML elements
*/
class EBML_DLL_API EbmlStream {
	public:
		EbmlStream(IOCallback & output);
		~EbmlStream();
	
		/*!
			\brief Find a possible next ID in the data stream
			\param MaxDataSize The maximum possible of the data in the element (for sanity checks)
			\note the user will have to delete that element later
		*/
		EbmlElement * FindNextID(const EbmlCallbacks & ClassInfos, const uint64 MaxDataSize);

		EbmlElement * FindNextElement(const EbmlSemanticContext & Context, int & UpperLevel, const uint64 MaxDataSize, bool AllowDummyElt, unsigned int MaxLowerLevel = 1);

		inline IOCallback & I_O() {return Stream;}

	protected:
		IOCallback & Stream;
};

END_LIBEBML_NAMESPACE

#endif // LIBEBML_STREAM_H
