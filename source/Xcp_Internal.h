/* Copyright (C) 2010 Peter Fridlund
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */


#ifndef XCP_INTERNAL_H_
#define XCP_INTERNAL_H_

#include "Xcp_Cfg.h"
#include "Xcp_ConfigTypes.h"

#define XCP_PID_RES  							0xFF
#define XCP_PID_ERR  							0xFE
#define XCP_PID_EV								0xFD
#define XCP_PID_SERV 		   					0xFC


/*********************	  COMMANDS	  *****************/

/* STANDARD COMMANDS */
													/* OPTIONAL */
#define XCP_PID_CMD_STD_CONNECT 				0xFF	// N
#define XCP_PID_CMD_STD_DISCONNECT 				0xFE	// N
#define XCP_PID_CMD_STD_GET_STATUS				0xFD	// N
#define XCP_PID_CMD_STD_SYNCH					0xFC	// N
#define XCP_PID_CMD_STD_GET_COMM_MODE_INFO		0xFB	// Y
#define XCP_PID_CMD_STD_GET_ID					0xFA	// Y
#define XCP_PID_CMD_STD_SET_REQUEST				OxF9	// Y
#define XCP_PID_CMD_STD_GET_SEED				0xF8	// Y
#define XCP_PID_CMD_STD_UNLOCK					0xF7	// Y
#define XCP_PID_CMD_STD_SET_MTA					0xF6	// Y
#define XCP_PID_CMD_STD_UPLOAD					0xF5	// Y
#define XCP_PID_CMD_STD_SHORT_UPLOAD			0xF4	// Y
#define XCP_PID_CMD_STD_BUILD_CHECKSUM			0xF3	// Y
#define XCP_PID_CMD_STD_TRANSPORT_LAYER_CMD 	0xF2	// Y
#define XCP_PID_CMD_STD_USER_CMD				0xF1	// Y

/* CALIBRATION COMMANDS */
													/* OPTIONAL */
#define XCP_PID_CMD_CAL_DOWNLOAD				0xF0	// N
#define XCP_PID_CMD_CAL_DOWNLOAD_NEXT			0xEF	// Y
#define XCP_PID_CMD_CAL_DOWNLOAD_MAX			0xEE	// Y
#define XCP_PID_CMD_CAL_SHORT_DOWNLOAD			0xED	// Y
#define XCP_PID_CMD_CAL_MODIFY_BITS				0xEC	// Y

/* PAGE SWITCHING COMMANDS */
													/* OPTIONAL */
#define XCP_PID_CMD_PAG_SET_CAL_PAGE			0xEB	// N
#define XCP_PID_CMD_PAG_GET_CAL_PAGE			0xEA	// N
#define XCP_PID_CMD_PAG_GET_PAG_PROCESSOR_INFO	0xE9	// Y
#define XCP_PID_CMD_PAG_GET_SEGMENT_INFO		0xE8	// Y
#define XCP_PID_CMD_PAG_GET_PAGE_INFO			0xE7	// Y
#define XCP_PID_CMD_PAG_SET_SEGMENT_MODE		0xE6	// Y
#define XCP_PID_CMD_PAG_GET_SEGMENT_MODE		0xE5	// Y
#define XCP_PID_CMD_PAG_COPY_CAL_PAGE			0xE4	// Y

/* DATA SCQUISITION AND STIMULATION COMMANDS */
													/* OPTIONAL */
#define XCP_PID_CMD_DAQ_CLEAR_DAQ_LIST			0xE3	// N
#define XCP_PID_CMD_DAQ_SET_DAQ_LIST			0xE2	// N
#define XCP_PID_CMD_DAQ_WRITE_DAQ				0xE1	// N
#define XCP_PID_CMD_DAQ_SET_DAQ_LIST_MODE		0xE0	// N
#define XCP_PID_CMD_DAQ_GET_DAQ_LIST_MODE		0xDF	// N
#define XCP_PID_CMD_DAQ_START_STOP_DAQ_LIST		0xDE	// N
#define XCP_PID_CMD_DAQ_START_STOP_SYNCH		0xDD	// N
#define XCP_PID_CMD_DAQ_GET_DAQ_CLOCK			0xDC	// Y
#define XCP_PID_CMD_DAQ_READ_DAQ				0xDB	// Y
#define XCP_PID_CMD_DAQ_GET_DAQ_PROCESSOR_INFO	0xDA	// Y
#define XCP_PID_CMD_DAQ_GET_DAQ_RESOLUTION_INFO	0xD9	// Y
#define XCP_PID_CMD_DAQ_GET_DAQ_LIST_INFO		0xD8	// Y
#define XCP_PID_CMD_DAQ_GET_DAQ_EVENT_INFO		0xD7	// Y
#define XCP_PID_CMD_DAQ_GET_FREE_DAQ			0xD6	// Y
#define XCP_PID_CMD_DAQ_GET_ALLOC_DAQ			0xD5	// Y
#define XCP_PID_CMD_DAQ_GET_ALLOC_ODT			0xD4	// Y
#define XCP_PID_CMD_DAQ_GET_ALLOC_ODT_ENTRY		0xD3	// Y

/* NON-VOLATILE MEMORY PROGRAMMING COMMANDS */
													/* OPTIONAL */
#define XCP_PID_CMD_PGM_PRODRAM_START			0xD2	// N
#define XCP_PID_CMD_PGM_PROGRAM_CLEAR			0xD1	// N
#define XCP_PID_CMD_PGM_PROGRAM					0xD0	// N
#define XCP_PID_CMD_PGM_PROGRAM_RESET			0xCF	// N
#define XCP_PID_CMD_PGM_GET_PGM_PROCESSOR_INFO	0xCE	// Y
#define XCP_PID_CMD_PGM_GET_SECTOR_INFO			0xCD	// Y
#define XCP_PID_CMD_PGM_PROGRAM_PREPARE			0xCC	// Y
#define XCP_PID_CMD_PGM_PROGRAM_FORMAT			0xCB	// Y
#define XCP_PID_CMD_PGM_PROGRAM_NEXT			0xCA	// Y
#define XCP_PID_CMD_PGM_PROGRAM_MAX				0xC9	// Y
#define XCP_PID_CMD_PGM_PROGRAM_VERIFY			0xC8	// Y


/* ERROR CODES */

#define XCP_ERR_CMD_SYNCH						0x00

#define XCP_ERR_CMD_BUSY						0x10
#define XCP_ERR_DAQ_ACTIVE						0x11
#define XCP_ERR_PGM_ACTIVE						0x12

#define XCP_ERR_CMD_UNKNOWN                     0x20
#define XCP_ERR_CMD_SYNTAX						0x21
#define XCP_ERR_OUT_OF_RANGE					0x22
#define XCP_ERR_WRITE_PROTECTED					0x23
#define XCP_ERR_ACCESS_DENIED					0x24
#define XCP_ERR_ACCESS_LOCKED					0x25
#define XCP_ERR_PAGE_NOT_VALID					0x26
#define XCP_ERR_MODE_NOT_VALID					0x27
#define XCP_ERR_SEGMENT_NOT_VALID				0x28
#define XCP_ERR_SEQUENCE						0x29
#define XCP_ERR_DAQ_CONFIG						0x2A

#define XCP_ERR_MEMORY_OVERFLOW					0x30
#define XCP_ERR_GENERIC							0x31
#define XCP_ERR_VERIFY							0x31





/* COMMAND LIST FUNCTION CALLBACK */

typedef Std_ReturnType (*Xcp_CmdFuncType)(uint8, void*, int);

typedef struct {
    Xcp_CmdFuncType fun; /**< pointer to function to use */
    int             len; /**< minumum len of command     */
} Xcp_CmdListType;





/* INTERNAL GLOBAL VARIABLES */

extern const Xcp_ConfigType *g_XcpConfig;




/* BYTESTREAM FUNCTIONS */

#define GET_UINT8(data, offset) (*((uint8*)(data)+offset))

#define SET_UINT8(data, offset, value) do {                 \
         ((uint8*)(data))[offset] = ((value) & 0xFFFFFFFF); \
        } while(0)



/* RX/TX FIFO */

typedef struct {
    unsigned int  len;
    unsigned char data[XCP_MAX_DTO];
} Xcp_BufferType;

typedef struct {
    Xcp_BufferType  b[XCP_MAX_RXTX_QUEUE+2];
    Xcp_BufferType* w;
    Xcp_BufferType* r;
    Xcp_BufferType* e;
} Xcp_FifoType;

static inline void Xcp_FifoInit(Xcp_FifoType *fifo)
{
    fifo->w = fifo->b;
    fifo->r = fifo->b;
    fifo->e = fifo->b+sizeof(fifo->b)/sizeof(fifo->b[0]);
}

static inline Xcp_BufferType* Xcp_FifoNext(Xcp_FifoType *fifo, Xcp_BufferType* p)
{
    if(p+1 == fifo->e)
        return fifo->b;
    else
        return p+1;
}

static inline Xcp_BufferType* Xcp_FifoWrite_Get(Xcp_FifoType *fifo)
{
    Xcp_BufferType* n = Xcp_FifoNext(fifo, fifo->w);
    if(n == fifo->r)
        return NULL;
    return fifo->w;
}

static inline Xcp_BufferType* Xcp_FifoWrite_Next(Xcp_FifoType *fifo)
{
    fifo->w = Xcp_FifoNext(fifo, fifo->w);
    return Xcp_FifoWrite_Get(fifo);
}

static inline Xcp_BufferType* Xcp_FifoRead_Get(Xcp_FifoType *fifo)
{
    if(fifo->r == fifo->w)
        return NULL;
    return fifo->r;
}

static inline Xcp_BufferType* Xcp_FifoRead_Next(Xcp_FifoType *fifo)
{
    fifo->r = Xcp_FifoNext(fifo, fifo->r);
    return Xcp_FifoRead_Get(fifo);
}

#define FIFO_GET_WRITE(fifo, it) \
    if(Xcp_FifoWrite_Get(&fifo) == NULL) { DEBUG(DEBUG_HIGH, "FIFO_GET_WRITE - no free buffer to write") } \
    for(Xcp_BufferType* it = Xcp_FifoWrite_Get(&fifo); it; it = NULL, Xcp_FifoWrite_Next(&fifo))

#define FIFO_FOR_READ(fifo, it) \
    for(Xcp_BufferType* it = Xcp_FifoRead_Get(&fifo); it; it = Xcp_FifoRead_Next(&fifo))





/* CALLBACK FUNCTIONS */

extern void Xcp_RxIndication(void* data, int len);
extern Std_ReturnType Xcp_Transmit    (void* data, int len);

#endif /* XCP_INTERNAL_H_ */
