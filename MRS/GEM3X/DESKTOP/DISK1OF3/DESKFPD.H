/*	DESKFPD.H	06/11/84 - 03/25/85	Lee Lorenzen	*/
/*	for 3.0		11/4/87			mdf		*/
/*
*       Copyright 1999, Caldera Thin Clients, Inc.                      
*       This software is licenced under the GNU Public License.         
*       Please see LICENSE.TXT for further information.                 
*                                                                       
*                  Historical Copyright                                 
*	-------------------------------------------------------------
*	GEM Desktop					  Version 3.0
*	Serial No.  XXXX-0000-654321		  All Rights Reserved
*	Copyright (C) 1987			Digital Research Inc.
*	-------------------------------------------------------------
*/


#define OP_COUNT 0
#define OP_DELETE 1
#define OP_COPY 2

#define D_PERM 0x0001

#define V_ICON 0
#define V_TEXT 1

#define S_NAME 0
#define S_DATE 1
#define S_SIZE 2
#define S_TYPE 3
#define S_DISK 4

#define E_NOERROR 0
#define E_NOFNODES 100
#define E_NOPNODES 101
#define E_NODNODES 102

#define NUM_FNODES 400
#define NUM_PNODES 3			/* one more than windows for	*/
					/*   unopen disk copy		*/

#define FNODE struct filenode
FNODE
{
	FNODE		*f_next;
	BYTE		f_junk;		/* to align on even boundaries	*/
	BYTE		f_attr;
/* BugFix	*/
	UWORD		f_time;
	UWORD		f_date;
/* */
	LONG		f_size;
	BYTE		f_name[LEN_ZFNAME];
	WORD		f_obid;
	ANODE		*f_pa;
	WORD		f_isap;
};


#define PNODE struct pathnode
PNODE
{
	PNODE		*p_next;
	WORD		p_flags;
	WORD		p_attr;
	BYTE		p_spec[LEN_ZPATH];
	FNODE		*p_flist;
	WORD		p_count;
	LONG		p_size;
};


