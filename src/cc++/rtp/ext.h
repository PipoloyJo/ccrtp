// Copyright (C) 1999-2002 Open Source Telecom Corporation.
//  
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software 
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
// 
// As a special exception to the GNU General Public License, permission is 
// granted for additional uses of the text contained in its release 
// of ccRTP.
// 
// The exception is that, if you link the ccRTP library with other
// files to produce an executable, this does not by itself cause the
// resulting executable to be covered by the GNU General Public License.
// Your use of that executable is in no way restricted on account of
// linking the ccRTP library code into it.
// 
// This exception does not however invalidate any other reasons why
// the executable file might be covered by the GNU General Public License.
// 
// This exception applies only to the code released under the 
// name ccRTP.  If you copy code from other releases into a copy of
// ccRTP, as the General Public License permits, the exception does
// not apply to the code that you add in this way.  To avoid misleading
// anyone as to the status of such modified files, you must delete
// this exception notice from them.
// 
// If you write modifications of your own for ccRTP, it is your choice
// whether to permit this exception to apply to your modifications.
// If you do not wish that, delete this exception notice.  

/** 
 * @file ext.h 
 * @short ccRTP Stack extensions.
 **/

#ifndef CCXX_RTP_EXT_H
#define CCXX_RTP_EXT_H

#include <cc++/socket.h>
#include <cc++/rtp/ioqueue.h>

#ifdef  CCXX_NAMESPACES
namespace ost {
#endif

/**
 * @defgroup rtpext ccRTP Extension classes
 * @{
 **/

/**
 * @class RTPDuplex rtp.h cc++/rtp.h
 *
 * A peer associated RTP socket pair for physically connected peer
 * hosts.  This has no RTCP and assumes the receiver is connected
 * to a known transmitter, hence no "foreign" packets will arrive.
 *
 * @author David Sugar
 * @short RTP peer host over UDP.
 */
class CCXX_CLASS_EXPORT RTPDuplex : public RTPDataQueue, protected UDPReceive, public UDPTransmit
{
public:
	/**
	 * @param bind network address this socket is to be bound
	 * @param local transport port this socket is to be bound
	 * @param remote peer transpor port
	 */
	RTPDuplex(const InetAddress &bind, tpport_t local, tpport_t remote);

	/**
	 *
	 */
	virtual
	~RTPDuplex();

	/**
	 * @param host peer address
	 * @param port peer port. If not specified, the same as the
	 *        local is used
	 * @return socket status
	 */
	Socket::Error 
	connect(const InetHostAddress &host, tpport_t port = 0);

protected:

	/**
	 * @param timeout how much time to wait for new data
	 * @return if there is some new data
	 */
	bool 
	isPendingData(microtimeout_t timeout)
	{ return isPendingReceive(timeout); }

	/**
	 * @param buffer pointer to data to be written
	 * @param len how many octets to write
	 * @return number of octets written
	 */
	size_t 
	writeData(const unsigned char *const buffer, size_t len)
	{ return UDPTransmit::transmit((const char *)buffer, len); }

	/**
	 * @param buffer where to store the retrieved data
	 * @param len how many octets to read
	 * @return number of octets read
	 */
	size_t
	readData(unsigned char *buffer, size_t len)
	{ return UDPReceive::receive(buffer, len); }

	/**
	 * @return the associated peer information
	 */
	SyncSource &getPeer();

private:
	tpport_t dataBasePort;
};

/*@}*/ // rtpext

#ifdef	CCXX_NAMESPACES
};
#endif

#endif //CCXX_RTP_EXT_H

/** EMACS **
 * Local variables:
 * mode: c++
 * c-basic-offset: 8
 * End:
 */