/* * 
 *  $Id$
 *  
 *  This file is part of Fenice
 *
 *  Fenice -- Open Media Server
 *
 *  Copyright (C) 2005 by
 *  	
 *	- Federico Ridolfo	<federico.ridolfo@polito.it>
 *	- (LS)�			<team@streaming.polito.it>
 * 
 *  Fenice is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Fenice is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Fenice; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *  
 * */

#include <fenice/wsocket.h>

int Sock_read(Sock *s, void *buffer, int nbytes)
{
	//printf("Sock_read\n");
#if HAVE_SSL
	if(s->flags & USE_SSL)
		return sock_SSL_read(s->ssl,buffer,nbytes);
	else {
#endif
		if(s->socktype == UDP)	
			return sock_udp_read(s->fd,buffer,nbytes);
		if(s->socktype == TCP)	
			return sock_tcp_read(s->fd,buffer,nbytes);
		return 0;
#if HAVE_SSL
	}
#endif
}