/*****************************************************************************
 *
 * BROKER.H - Event broker includes for Nagios
 *
 * Copyright (c) 2002-2003 Ethan Galstad (nagios@nagios.org)
 * Last Modified:   08-19-2003
 *
 * License:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *****************************************************************************/

#ifndef _BROKER_H
#define _BROKER_H

#include "config.h"
#include "nagios.h"


/****** EVENT TYPES ************************/

#define NEBTYPE_NONE                          0

#define NEBTYPE_HELLO                         1
#define NEBTYPE_GOODBYE                       2
#define NEBTYPE_INFO                          3

#define NEBTYPE_PROCESS_START                 100
#define NEBTYPE_PROCESS_DAEMON                101
#define NEBTYPE_PROCESS_RESTART               102
#define NEBTYPE_PROCESS_SHUTDOWN              103

#define NEBTYPE_TIMEDEVENT_ADD                200
#define NEBTYPE_TIMEDEVENT_REMOVE             201
#define NEBTYPE_TIMEDEVENT_EXECUTE            202
#define NEBTYPE_TIMEDEVENT_DELAY              203   /* NOT IMPLEMENTED */
#define NEBTYPE_TIMEDEVENT_SKIP               204   /* NOT IMPLEMENTED */
#define NEBTYPE_TIMEDEVENT_SLEEP              205   /* NOT IMPLEMENTED */

#define NEBTYPE_LOG_DATA                      300
#define NEBTYPE_LOG_ROTATION                  301

#define NEBTYPE_SYSTEM_COMMAND                400

#define NEBTYPE_EVENTHANDLER_HOST             500
#define NEBTYPE_EVENTHANDLER_GLOBAL_HOST      501
#define NEBTYPE_EVENTHANDLER_SERVICE          502
#define NEBTYPE_EVENTHANDLER_GLOBAL_SERVICE   503

#define NEBTYPE_NOTIFICATION_HOST             600
#define NEBTYPE_NOTIFICATION_SERVICE          601
#define NEBTYPE_NOTIFICATION_CONTACT          602

#define NEBTYPE_SERVICECHECK_INITIATE         700
#define NEBTYPE_SERVICECHECK_RAW              701        /* NOT IMPLEMENTED */
#define NEBTYPE_SERVICECHECK_PROCESSED        702

#define NEBTYPE_HOSTCHECK_INITIATE            800        /* a check of the route to the host has been initiated */
#define NEBTYPE_HOSTCHECK_RAW                 801        /* the "raw" result of a host check */
#define NEBTYPE_HOSTCHECK_PROCESSED           802        /* the processed/final result of a host check */

#define NEBTYPE_COMMENT_ADD                   900
#define NEBTYPE_COMMENT_DELETE                901
#define NEBTYPE_COMMENT_LOAD                  902

#define NEBTYPE_FLAPPING_START                1000
#define NEBTYPE_FLAPPING_STOP                 1001

#define NEBTYPE_DOWNTIME_ADD                  1100
#define NEBTYPE_DOWNTIME_DELETE               1101
#define NEBTYPE_DOWNTIME_LOAD                 1102
#define NEBTYPE_DOWNTIME_START                1103
#define NEBTYPE_DOWNTIME_STOP                 1104



/****** EVENT FLAGS ************************/

#define NEBFLAG_NONE                          0
#define NEBFLAG_PROCESS_INITIATED             1         /* event was initiated by Nagios process */
#define NEBFLAG_USER_INITIATED                2         /* event was initiated by a user request */




/****** EVENT ATTRIBUTES *******************/

#define NEBATTR_NONE                          0

#define NEBATTR_BROKERFILE_ERROR              1

#define NEBATTR_BUFFER_OVERFLOW               1

#define NEBATTR_SHUTDOWN_NORMAL               1
#define NEBATTR_SHUTDOWN_ABNORMAL             2
#define NEBATTR_RESTART_NORMAL                4
#define NEBATTR_RESTART_ABNORMAL              8

#define NEBATTR_HOSTCHECK_ACTIVE              1
#define NEBATTR_HOSTCHECK_PASSIVE             2

#define NEBATTR_SERVICECHECK_ACTIVE           1
#define NEBATTR_SERVICECHECK_PASSIVE          2

#define NEBATTR_HOST_COMMENT                  1
#define NEBATTR_SERVICE_COMMENT               2

#define NEBATTR_HOST_FLAPPING                 1
#define NEBATTR_SERVICE_FLAPPING              2
#define NEBATTR_FLAPPING_STOP_NORMAL          4
#define NEBATTR_FLAPPING_STOP_DISABLED        8         /* flapping stopped because flap detection was disabled */

#define NEBATTR_HOST_DOWNTIME                 1
#define NEBATTR_SERVICE_DOWNTIME              2
#define NEBATTR_DOWNTIME_STOP_NORMAL          4
#define NEBATTR_DOWNTIME_STOP_CANCELLED       8

#define NEBATTR_EARLY_COMMAND_TIMEOUT         512



/****** EVENT BROKER FUNCTIONS *************/

#ifdef USE_EVENT_BROKER
struct timeval get_broker_timestamp(struct timeval *);
void broker_program_state(int,int,int,struct timeval *);
void broker_timed_event(int,int,int,timed_event *event,struct timeval *);
void broker_log_data(int,int,int,char *,unsigned long,struct timeval *);
void broker_event_handler(int,int,int,void *,int,int,double,int,int,int,char *,char *,struct timeval *);
void broker_ocp_data(int,int,int,void *,int,int,double,int,int,struct timeval *);
void broker_system_command(int,int,int,double,int,int,int,char *,char *,struct timeval *);
void broker_host_check(int,int,int,host *,int,int,double,double,int,int,int,char *,char *,char *,struct timeval *);
void broker_service_check(int,int,int,service *,double,double,int,int,int,char *,struct timeval *);
void broker_comment_data(int,int,int,char *,char *,time_t,char *,char *,int,int,unsigned long,struct timeval *);
void broker_downtime_data(int,int,int,char *,char *,time_t,char *,char *,time_t,time_t,int,unsigned long,unsigned long,unsigned long,struct timeval *);
void broker_flapping_data(int,int,int,void *,double,double,struct timeval *);
#endif

#endif
