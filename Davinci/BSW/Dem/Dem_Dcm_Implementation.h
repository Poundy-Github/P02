/* ********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2020 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 */
/*!
 *  \addtogroup Dem_Dcm
 *  \{
 *  \file       Dem_Dcm_Implementation.h
 *  \brief      Diagnostic Event Manager (Dem) Implementation file
 *  \details
 *********************************************************************************************************************/

/* ********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Savas Ates                    vissat        Vector Informatik GmbH
 *  Anna Bosch                    visanh        Vector Informatik GmbH
 *  Stefan Huebner                vishrs        Vector Informatik GmbH
 *  Thomas Dedler                 visdth        Vector Informatik GmbH
 *  Alexander Ditte               visade        Vector Informatik GmbH
 *  Matthias Heil                 vismhe        Vector Informatik GmbH
 *  Erik Jeglorz                  visejz        Vector Informatik GmbH
 *  Friederike Hitzler            visfrs        Vector Informatik GmbH
 *  Aswin Vijayamohanan Nair      visavi        Vector Informatik GmbH
 *  Fabian Wild                   viszfa        Vector Informatik GmbH
 *  Erwin Stamm                   visern        Vector Informatik GmbH
 *  Laura Henze                   visera        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  REFER TO DEM.H
 *********************************************************************************************************************/

#if !defined (DEM_DCM_IMPLEMENTATION_H)
#define DEM_DCM_IMPLEMENTATION_H

/* ********************************************************************************************************************
 *  GLOBAL MISRA JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 2880 EOF */ /* MD_DEM_2.1_UNREACHABLE_STATEMENT */
/* PRQA S 2982 EOF */ /* MD_DEM_2982 */
/* PRQA S 2983 EOF */ /* MD_DEM_2983 */
/* PRQA S 2985 EOF */ /* MD_DEM_2985 */
/* PRQA S 2986 EOF */ /* MD_DEM_2986 */
/* PRQA S 2987 EOF */ /* MD_DEM_2987 */
/* PRQA S 2991 EOF */ /* MD_DEM_2991 */
/* PRQA S 2992 EOF */ /* MD_DEM_2992 */
/* PRQA S 2995 EOF */ /* MD_DEM_2995 */
/* PRQA S 2996 EOF */ /* MD_DEM_2996 */
/* PRQA S 3415 EOF */ /* MD_DEM_13.5_cf */

/* ********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

                                                  /* Own subcomponent header */
/* ------------------------------------------------------------------------- */
#include "Dem_Dcm_Interface.h"

                                                    /* Used subcomponent API */
/* ------------------------------------------------------------------------- */
#include "Dem_ClientAccess_Implementation.h"
#include "Dem_FreezeFrameIterator_Interface.h"
#include "Dem_MemoryEntry_Implementation.h"
#include "Dem_SnapshotEntry_Implementation.h"
#include "Dem_ExtendedEntry_Implementation.h"
#include "Dem_DTCReadoutBuffer_Implementation.h"
#include "Dem_DTCReporting_Implementation.h"
#include "Dem_UDSStatus_Implementation.h"
#include "Dem_DTC_Implementation.h"
#include "Dem_Event_Implementation.h"
#include "Dem_DataReportIF_Implementation.h"
#include "Dem_Memory_Implementation.h"
#include "Dem_Indicator_Implementation.h"
#include "Dem_Data_Implementation.h"
#include "Dem_EventInternalStatus_Implementation.h"
#include "Dem_Iumpr_Implementation.h"

                                                   /* Subcomponents callbacks*/
/* ------------------------------------------------------------------------- */
#include "Dem_Error_Interface.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT CONSTANT MACROS
 *********************************************************************************************************************/

/*! Filename declaration */
#define DEM_DCM_IMPLEMENTATION_FILENAME "Dem_Dcm_Implementation.h"

/* ********************************************************************************************************************
 *  SUBCOMPONENT DATA
 *********************************************************************************************************************/


/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DECLARATIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \defgroup Dem_Dcm_Private Private Methods
 * \{
 */


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_ERec_CopyERec_FromSubEventMemoryEntry
 *****************************************************************************/
/*!
 * \brief         Copies the requested extended data record from a selected 
 *                memory entry to the destination buffer.
 *
 * \details       Copies the requested extended data record from a selected 
 *                memory entry to the destination buffer. Subevent memory entry 
 *                is identified by the index to the readout buffer array.
 *
 * \param[in]     ERecId
 *                Identifier of the requested extended data record
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     ReadoutBufferDataIndex
 *                Index to ReadoutBufferData in ReadoutBuffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \pre           - A DTC belonging to combined group type 2 has been selected
 *                  and copied to readout buffer
 *                - Function must be only called for copying User and Internal
 *                  extended data records from a subevent memory entry
 *                - Caller must ensure that the requested records are stored
 * 
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Dcm_ERec_CopyERec_FromSubEventMemoryEntry(
  CONST(uint8, AUTOMATIC) ERecId,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_ERec_CopyERec_CombinedDTC
 *****************************************************************************/
/*!
 * \brief         Reads the requested extended data record from all available
 *                subevents of a combined DTC
 *
 * \details       Reads the requested extended data record from all available
 *                subevents of a combined DTC
 *
 * \param[in]     ERecId
 *                Extended Data Record Identifier to be copied
 * \param[in]     ERecEntryIndex
 *                Index of the extended data record inside the Dem data collection
 *                table
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        E_OK
 *                Data was copied successfully.
 *
 * \pre           A DTC belonging to combined group type 2 has been selected
 *                and copied to readout buffer
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_CopyERec_CombinedDTC(
  CONST(uint8, AUTOMATIC) ERecId,
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC) ERecEntryIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_ERec_ReadNextRecord_CombinedEvent
 *****************************************************************************/
/*!
 * \brief         Validates the request to get an extended data record belonging 
 *                to a combined DTC in UDS format and copies the data.
 *
 * \details       Validates the request to get an extended data record belonging 
 *                to a combined DTC in UDS format and copies data into the given buffer.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                Read extended data record successful.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and 
 *                therefore invalid
 *
 * \pre           Function must be only invoked when a combined DTC is selected
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON) 
 *                && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds.
 ****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_ReadNextRecord_CombinedEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ERec_ReadNextRecord_NormalEvent
 *****************************************************************************/
/*!
 * \brief         Validates the request to get an extended data record in UDS
 *                format and copies the data.
 *
 * \details       Copies data into the given buffer.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    DestBuffer
 *                Pointer to the destination buffer
 * \param[in,out] BufSize
 *                In: Available space in the receiving buffer
 *                Out: Number of written bytes.
 *
 * \return        E_OK
 *                Read extended data record successful.
 * \return        DEM_BUFFER_TOO_SMALL
 *                provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and 
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds.
 ****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_ReadNextRecord_NormalEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ERec_GetSize_NormalEvent
 *****************************************************************************/
/*!
 * \brief         Get the size of one or all extended data record(s) belonging
 *                to a non combined event.
 *
 * \details       Get the size of one or all extended data record(s) belonging
 *                to a non combined event.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    SizeOfExtendedDataRecord
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_GetSize_NormalEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfExtendedDataRecord
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_ERec_GetSize_CombinedEvent
 *****************************************************************************/
/*!
 * \brief         Get the size of one or all extended data record(s) belonging
 *                to a combined DTC.
 *
 * \details       Get the size of one or all extended data record(s) belonging
 *                to a combined DTC.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    SizeOfExtendedDataRecord
 *                Size of selected extended data record in bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON)
 *                && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_GetSize_CombinedEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfExtendedDataRecord
  );
#endif


# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_ReadNextRecord_CombinedDTC
 *****************************************************************************/
/*!
 * \brief         Validates the request to copy snapshot record in UDS format
 *                and invokes the relevant functions to copy data to the given 
 *                buffer.
 *
 * \details       Validates the request to copy snapshot record in UDS format
 *                and invokes the relevant functions to copy data to the given 
 *                buffer.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[in,out] DestinationBuffer
 *                Pointer to destination buffer structure
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Selection function is not called.
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                provided buffer size too small.
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           Function shall be invoked only when a DTC supporting event
 *                combination type 2 has been selected.
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *                && DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds.
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_CombinedDTC(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_ReadNextRecord_NormalEvent
 *****************************************************************************/
/*!
 * \brief         Validates the request to get an extended data record in UDS
 *                format, and copies the data.
 *
 * \details       Copies data into the given buffer.
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[in,out] DestinationBuffer
 *                Pointer to destination buffer structure
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Selection function is not called.
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                provided buffer size too small.
 *
 * \return        DEM_PENDING: The requested value is calculated
 *                asynchronously and currently not available. The
 *                caller can retry later.
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *              
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds.
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_NormalEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_SelectFirstSource_CombinedEvent
 *****************************************************************************/
/*!
 * \brief         Select the first snapshot record source for a combined DTC
 *
 * \details       Select the first snapshot record source for a combined DTC
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 *
 * \param[in]     RecordNumber
 *                The record number to select
 *
 * \pre           -
 * \config        ((DEM_CFG_SUPPORT_DCM == STD_ON) 
 *                && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)) 
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_Dcm_SRec_SelectFirstSource_CombinedEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC) RecordNumber
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_SelectFirstSource_NormalEvent
 *****************************************************************************/
/*!
 * \brief         Select the first snapshot record source
 *
 * \details       Select the first snapshot record source
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 *
 * \param[in]     RecordNumber
 *                The record number to select
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE) 
Dem_Dcm_SRec_SelectFirstSource_NormalEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC) RecordNumber
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_GetSize_NormalEvent
 *****************************************************************************/
/*!
 * \brief         Get the size of one or all formatted snapshot record() 
 *                stored for a DTC (19 04).
 *
 * \details       Get the size of one or all formatted snapshot record() 
 *                stored for a DTC (19 04).
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    SizeOfFreezeFrame
 *                Pointer to receive the size in bytes
 *
 * \return        E_OK
 *                The requested data was returned
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 * \return        DEM_PENDING
 *                Not used by this implementation
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2, from the master partition only
 * \synchronous   FALSE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_GetSize_NormalEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_GetSize_SingleRecordCombinedEvent
 *****************************************************************************/
/*!
 * \brief         Calculates the size of a snapshot record belonging
 *                to a combined DTC
 *
 * \details       Calculates the size of a snapshot record belonging
 *                to a combined DTC
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_GetSize_SingleRecordCombinedEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif


#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
  &&  (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON) \
  &&  ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
     || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))))
/* ****************************************************************************
 * Dem_Dcm_SRec_CalculateSize_AllCombinedEvent
 *****************************************************************************/
/*!
 * \brief         Calculates the size of all snapshot records belonging to a 
 *                combined DTC.
 *
 * \details       Calculates the size of all snapshot records belonging to a 
 *                combined DTC .i.e. the sum of all snapshot records belonging
 *                to each subevent of the combined DTC.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                No snapshot records available
 *
 * \pre           The relevant subevent memory entries has to be locked for 
 *                Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *                ( DEM_CFG_SUPPORT_SRECS == STD_ON ||
 *                ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)))
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_AllCombinedEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_GetSize_CombinedEvent
 *****************************************************************************/
/*!
 * \brief         Get the size of one or all formatted snapshot record() 
 *                stored for a combined DTC (19 04).
 *
 * \details       Get the size of one or all formatted snapshot record() 
 *                stored for a combined DTC (19 04).
 *
 * \param[in]     ClientId
 *                Unique client id, assigned to the instance of the calling
 *                module.
 * \param[out]    SizeOfFreezeFrame
 *                Pointer to receive the size in bytes
 *
 * \return        E_OK
 *                The requested data was returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available.
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON) &&
 *                (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
 *
 * \context       TASK|ISR2, from the master partition only
 * \synchronous   FALSE
 * \reentrant     TRUE for different ClientIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_GetSize_CombinedEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame                                                                 /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_CopySRec_CombinedSubEvent
 *****************************************************************************/
/*!
 * \brief         Copies the requested snapshot record from a selected subevent 
 *                to the destination buffer.
 *
 * \details       Copies the requested snapshot record from a selected subevent 
 *                to the destination buffer. Subevent memory entry is identified
 *                by the index to the readout buffer array.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     ReadoutBufferDataIndex
 *                Index to ReadoutBufferData in ReadoutBuffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \pre           A DTC belonging to combined group type 2 has been selected
 *                and copied to readout buffer
 * 
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_SRec_CopySRec_CombinedSubEvent(
  CONST(uint8, AUTOMATIC) SRecId,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_CopySRec_CombinedDTC
 *****************************************************************************/
/*!
 * \brief         Reads the next snapshot record belonging to a combined DTC
 *                based on the snapshot record selection.
 *
 * \details       Reads the next snapshot record belonging to a combined DTC
 *                based on the snapshot record selection.
 *
 * \param[in]     SRecId
 *                Snapshot Record Identifier to be copied
 * \param[in]     SnapshotHeaderBitMaskIndex
 *                Index pointing to position of SRecId inside the DTC specific
 *                Record Number list
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        E_OK
 *                Data was copied successfully.
 *
 * \pre           A DTC belonging to combined group type 2 has been selected
 *                and copied to readout buffer
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CopySRec_CombinedDTC(
  CONST(uint8, AUTOMATIC) SRecId,
  CONST(uint8, AUTOMATIC) SnapshotHeaderBitMaskIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_ReadNextSRec_CombinedDTC
 *****************************************************************************/
/*!
 * \brief         Reads the next snapshot record belonging to a combined DTC
 *                based on the snapshot record selection.
 *
 * \details       Reads the next snapshot record belonging to a combined DTC
 *                based on the snapshot record selection.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 * \return        E_OK
 *                Record was copied successfully
 *
 * \pre           A DTC belonging to combined group type 2 has been selected
 *                and copied to readout buffer
 *
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ReadNextSRec_CombinedDTC(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ERec_TestRecordMatch
 *****************************************************************************/
/*!
 * \brief         Test whether filter for extended data record(s) matches
 *
 * \details       Return whether the given RecordNumber is accepted by the 
 *                RecordNumberFilter set in Readoutbuffer
 *                Following RecordNumbers are accepted:
 *                 - 0xFF: Records 0x01 .. 0xEF are always accepted
 *                 - 0xFE: Records 0x90 .. 0xEF are always accepted
 *                 - otherwise only RecordNumbers which equal the RecordNumberFilter
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     RecordNumber
 *                Extended data record number
 *
 * \return        TRUE
 *                The filter matches
 *
 * \return        FALSE
 *                The filter does not match
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE boolean Dem_Dcm_ERec_TestRecordMatch(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC) RecordNumber
  );
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ERec_CopyNextRecord
 *****************************************************************************/
/*!
 * \brief         Copies an extended data record into the given buffer
 *
 * \details       Copies records with types "internal", "global" and "user"
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer context
 * \param[in]     ReadoutBufferDataIndex
 *                Index to ReadoutBufferData inside the ReadoutBuffer
 *
 *
 * \return        E_OK
 *                Reading succeeded
 *
 * \return        DEM_BUFFER_TOO_SMALL
 *                provided buffer size too small
 *
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_CopyNextRecord(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC)  ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex
  );
#endif


# if (DEM_CFG_SUPPORT_DCM == STD_ON) \
    && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
      || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
      || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
      || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_TestRecordMatch
 *****************************************************************************/
/*!
 * \brief         Test whether filter for snapshot record(s) matches
 *
 * \details       Return whether the given RecordNumber is accepted by the filter
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     RecordNumber
 *                Snapshot data record number
 *
 * \return        TRUE
 *                The filter matches
 *
 * \return        FALSE
 *                The filter does not match
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_DCM == STD_ON) \
 *                && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
 *                  || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
 *                  || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
 *                  || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE) 
Dem_Dcm_SRec_TestRecordMatch(
 CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
 CONST(uint8, AUTOMATIC) RecordNumber
  );
#endif


# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_InitSnapshotIterator
 *****************************************************************************/
/*!
 * \brief         Initializes the given snapshot iterator
 *
 * \details       Initializes the given snapshot iterator depending on the
 *                selected source.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     ReadoutBufferDataIndex
 *                Index to ReadoutBufferData inside the ReadoutBuffer
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL FUNC(void, DEM_CODE) 
Dem_Dcm_SRec_InitSnapshotIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex
  );
#endif


# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_SelectNextSource
 *****************************************************************************/
/*!
 * \brief         Select the next snapshot record source
 *
 * \details       Move the source iterater to the next source depending
 *                on the selected record.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 *
 * \return        E_OK
 *                The next data source was selected
 * \return        DEM_NO_SUCH_ELEMENT
 *                No data source selected (end of iteration)
 *
 * \pre           -
 * \config        (DEM_CFG_SUPPORT_SRECS == STD_ON)
 *                 || (DEM_CFG_SUPPORT_OBDII == STD_ON)
 *                 || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
 *                 || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE) 
Dem_Dcm_SRec_SelectNextSource(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  );
#endif


#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (( (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
/* ****************************************************************************
 * Dem_Dcm_SRec_ReadNextRecord_Obd
 *****************************************************************************/
/*!
 * \brief         Reads the OBD freeze frame
 *
 * \details       Reads the OBD freeze frame
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to a DestinationBuffer structure
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config           ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
 *                && ( ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
 *                  || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_Obd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


# if ((DEM_CFG_SUPPORT_DCM == STD_ON) \
  && (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) \
  && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_ReadNextRecord_TimeSeries
 *****************************************************************************/
/*!
 * \brief         Reads a time series snapshot record
 *
 * \details       Reads a time series snapshot record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        ((DEM_CFG_SUPPORT_DCM == STD_ON) 
 *                 && (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) 
 *                 && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_TimeSeries(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_ReadNextRecord_Global
 *****************************************************************************/
/*!
 * \brief         Reads a global snapshot record
 *
 * \details       Reads a global snapshot record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_Global(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_ReadNextRecord_Standard
 *****************************************************************************/
/*!
 * \brief         Reads a standard snapshot record
 *
 * \details       Reads a standard snapshot record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \return        E_NOT_OK
 *                Selection function is not called.
 * \return        DEM_BUFFER_TOO_SMALL
 *                Provided buffer size too small.
 * \return        DEM_NO_SUCH_ELEMENT
 *                Record number is not supported by configuration and
 *                therefore invalid
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different ReadoutBufferIds
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_Standard(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_CalculateSize_TimeSeries
 *****************************************************************************/
/*!
 * \brief         Calculates the size of a time series snapshot record
 *
 * \details       Calculates the size of a time series snapshot record
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_FEATURE_NEED_TIME_SERIES == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_TimeSeries(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_CalculateSize_SingleRecordNormalEvent
 *****************************************************************************/
/*!
 * \brief         Calculates the size of a standard snapshot record
 *
 * \details       Calculates the size of a standard snapshot record
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_SingleRecordNormalEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_SRec_CalculateSize_SingleRecordCombinedEvent
 *****************************************************************************/
/*!
 * \brief         Calculates the size of a single stored snapshot record belonging
 *                to a combined DTC
 *
 * \details       Calculates the size of a single store snapshot record belonging
 *                to a combined DTC. The function adds up snapshot UDS sizes of
 *                all events which have the respective record stored.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in]     RecordNumber
 *                Snapshot record number
 * \param[in]     SnapshotHeaderBitMaskIndex
 *                Index of the SRec inside the DTC specifc SRec list
 *
 * \return        Accumulated size of stored record Id over all sub-events
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_SRECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL FUNC(uint16, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_SingleRecordCombinedEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONST(uint8, AUTOMATIC)  SnapshotHeaderBitMaskIndex
  );
#endif


#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
  && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    || (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON) \
    || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
    || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
    || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
/* ****************************************************************************
 * Dem_Dcm_SRec_CalculateSize_AllNormalEvent
 *****************************************************************************/
/*!
 * \brief         Calculates the size of all snapshot records
 *
 * \details       Calculates the size of all snapshot records
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                No snapshot records available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                ( DEM_CFG_SUPPORT_SRECS == STD_ON ||
 *                  DEM_FEATURE_NEED_TIME_SERIES == STD_ON ||
 *                  DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON ||
 *                  ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) ||
 *                  DEM_CFG_SUPPORT_WWHOBD == STD_ON )
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_AllNormalEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif


#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_FEATURE_NEED_OBD == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )
/* ****************************************************************************
 * Dem_Dcm_SRec_CopyNextRecord_ObdII
 *****************************************************************************/
/*!
 * \brief         Validates the request to get the OBD-II FreezeFrame in UDS
 *                Format, and copies the data.
 *
 * \details       This function does the necessary validations and eventually
 *                calls Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData to copy the OBD
 *                freeze frame data.
 *                If errors are detected, the appropriate negative response is
 *                returned.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer stucture
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        E_NOT_OK
 *                The requested record is not available for EventId
 * \return        DEM_BUFFER_TOO_SMALL
 *                The destination buffer is too small
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CopyNextRecord_ObdII(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_CopyNextRecord_WwhObd
 *****************************************************************************/
/*!
 * \brief         Validates the request to get the WWH-OBD FreezeFrame in UDS
 *                Format, and copies the data.
 *
 * \details       This function does the necessary validations and eventually
 *                calls Dem_DataReportIF_WWHOBDFreezeFrameCopyData to copy the WWH-OBD
 *                freeze frame data.
 *                If errors are detected, the appropriate negative response is
 *                returned.
 *
 * \param[in]     ReadoutBufferId
 *                Unique handle of the readout buffer
 * \param[in,out] DestinationBuffer
 *                Pointer to DestinationBuffer structure
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        E_NOT_OK
 *                The requested record is not available for EventId
 * \return        DEM_BUFFER_TOO_SMALL
 *                The destination buffer is too small
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CopyNextRecord_WwhObd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  );
#endif


#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )
/* ****************************************************************************
 * Dem_Dcm_SRec_CalculateSize_ObdII
 *****************************************************************************/
/*!
 * \brief         Calculates the total size of the OBD II freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \details       Calculates the total size of the OBD II freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII == STD_ON &&
 *                DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_ObdII(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_SRec_CalculateSize_WwhObd
 *****************************************************************************/
/*!
 * \brief         Calculates the total size of the WWH-OBD freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \details       Calculates the total size of the WWH-OBD freeze frame, when
 *                formatted as UDS snapshot record (19 04)
 *
 * \param[in]     EventId
 *                Unique handle of the Event.
 *                The EventId must be in range [1..Dem_Cfg_GlobalEventCount()[.
 * \param[out]    SizeOfFreezeFrame
 *                Number of bytes.
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           A memory entry has to be locked for Dcm readout
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_WWHOBD == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     FALSE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_WwhObd(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  );
#endif


#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 * Dem_Dcm_ERec_CalculateSize
 *****************************************************************************/
/*!
 * \brief         Calculates the size of an extended data record
 *
 * \details       Calculates the size of an extended data record
 *
 * \param[in]     CfgERecIndex
 *                Handle to Extended Data Record descriptor table
 * \param[in]     ReadoutBufferId
 *                Handle to readout buffer
 * \param[in]     MemoryEntryId
 *                Handle to memory entry
 * \param[in]     ExtendedEntryIndex
 *                Index of the extended data record
 *
 * \return        E_OK
 *                Data was found and returned
 * \return        DEM_NO_SUCH_ELEMENT
 *                The requested record is not available
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE
 *****************************************************************************/
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dcm_ERec_CalculateSize(
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC) CfgERecIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Cfg_MemoryEntryHandleType, AUTOMATIC)  MemoryEntryId,
  CONST(uint8, AUTOMATIC)  ExtendedEntryIndex
  );
#endif


#if ((DEM_CFG_SUPPORT_DCM == STD_ON)\
    && (DEM_CFG_SUPPORT_ERECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 * Dem_Dcm_ERec_CalculateSizeSingleERec_CombinedDTC
 *****************************************************************************/
/*!
 * \brief         Calculates the size of an extended data record over all 
 *                subevents of a combined DTC
 *
 * \details       Calculates the size of an extended data record over all 
 *                subevents of a combined DTC
 *
 * \param[in]     ERecId
 *                Identifier of the extended data record
 * \param[in]     ERecEntryIndex
 *                Index of the extended data record in the Dem_Cfg_DataCollectionTable
 * \param[in]     ReadoutBufferId
 *                Handle to readout buffer
 * \param[in]     CombinedGroupId
 *                Identifier of the combined DTC group
 *
 * \return        Size of the requested extended data record
 *
 * \pre           -
 * \config        DEM_CFG_SUPPORT_DCM == STD_ON &&
 *                DEM_CFG_SUPPORT_ERECS == STD_ON &&
 *                DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON
 *
 * \context       TASK|ISR2
 * \synchronous   TRUE
 * \reentrant     TRUE for different clients (ReadoutBuffer Ids)
 *****************************************************************************/
DEM_LOCAL FUNC(uint16, DEM_CODE)
Dem_Dcm_ERec_CalculateSizeSingleERec_CombinedDTC(
  CONST(uint8, AUTOMATIC)  ERecId,
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC)  ERecEntryIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Cfg_CombinedGroupIndexType, AUTOMATIC) CombinedGroupId
  );
#endif

/* ********************************************************************************************************************
 *  SUBCOMPONENT PRIVATE FUNCTION DEFINITIONS
 *********************************************************************************************************************/

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_ERec_CopyERec_FromSubEventMemoryEntry
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Dcm_ERec_CopyERec_FromSubEventMemoryEntry(
  CONST(uint8, AUTOMATIC) ERecId,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  boolean lERecCopied;
  uint8 lExtendedEntryIndex;
  Dem_ExtendedEntry_IterType lExtendedEntryIter;

  lERecCopied = FALSE;
  lExtendedEntryIndex = Dem_DTCReadoutBuffer_GetExtendedEntryIndex(
                          ReadoutBufferId,
                          ReadoutBufferDataIndex);
  lExtendedEntryIter = Dem_DTCReadoutBuffer_GetExtendedEntryIterator(
                          ReadoutBufferId,
                          ReadoutBufferDataIndex);

  /* Extended entry iterator is initialized during selection */
  while (Dem_ExtendedEntry_IterExists(&lExtendedEntryIter) == TRUE)                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_ERecIndexType lCfgERecIndex;

    lCfgERecIndex = Dem_ExtendedEntry_IterGet(&lExtendedEntryIter);                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */

    /* If the extended data number matches */
    if (ERecId == (uint8)Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)))
    {
      Dem_EventIdType lEventId;
      Dem_Cfg_MemoryEntryHandleType lMemoryEntryId;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, ReadoutBufferDataIndex);
      lMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, ReadoutBufferDataIndex);

      if ((Dem_Cfg_ERecType(lCfgERecIndex) == DEM_CFG_EREC_TYPE_INTERNAL)
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
          || (Dem_ExtendedEntry_IteratorIsExtendedRecordStored(lMemoryEntryId, lExtendedEntryIndex) == TRUE)                     /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
# endif
         )
      {
        Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, (uint8)Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)));       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        (void) Dem_DataReportIF_CopyExtendedDataRecord(lEventId,                                                                 /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                       lExtendedEntryIndex,
                                                       lCfgERecIndex,
                                                       lMemoryEntryId,
                                                       DestinationBuffer);
        lERecCopied = TRUE;
      }
    }

    Dem_ExtendedEntry_IterNext(&lExtendedEntryIter);                                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
    if (Dem_Cfg_ERecType(lCfgERecIndex) == DEM_CFG_EREC_TYPE_USER)
    {
      lExtendedEntryIndex++;
    }
# endif
    if (lERecCopied == TRUE)
    {
      break;
    }
  }

  Dem_Internal_AssertContinue((lERecCopied == TRUE), DEM_E_INCONSISTENT_STATE)
  Dem_DTCReadoutBuffer_SetExtendedEntryIterator(ReadoutBufferId,
                                                ReadoutBufferDataIndex,
                                                lExtendedEntryIter);
  Dem_DTCReadoutBuffer_SetExtendedEntryIndex(ReadoutBufferId,
                                             ReadoutBufferDataIndex,
                                             lExtendedEntryIndex);
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_ERec_CopyERec_CombinedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_CopyERec_CombinedDTC(
  CONST(uint8, AUTOMATIC) ERecId,
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC) ERecEntryIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_CombinedGroupIndexType lCombinedDTCGroupId;

  lCombinedDTCGroupId = Dem_Cfg_EventCombinedGroup(Dem_DTCReadoutBuffer_GetMasterEventId(ReadoutBufferId));

  if ((DestinationBuffer->BufferSize - DestinationBuffer->WriteIndex)
       < Dem_Dcm_ERec_CalculateSizeSingleERec_CombinedDTC(
           ERecId, ERecEntryIndex, ReadoutBufferId, lCombinedDTCGroupId)
     )
  { /* Supported record, but the buffer is not large enough for all the data */
    lReturnValue = DEM_BUFFER_TOO_SMALL;
  }
  else
  {
    Dem_Cfg_ExtendedDataRecordEventIterType lExtendedDataRecordEventIter;

    /* Return E_OK wherein:
      - Internal ERec has no memory entry
      - Internal or User ERecs and selected data elements cannot be read
      - User ERec is not stored
    */
    lReturnValue = E_OK;
    switch (Dem_Cfg_ERecType(ERecEntryIndex))
    {
      case DEM_CFG_EREC_TYPE_GLOBAL:
      {
        for (Dem_Cfg_ExtendedDataRecordEventIterInit(&lExtendedDataRecordEventIter, lCombinedDTCGroupId, ERecId);                /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_ExtendedDataRecordEventIterExists(&lExtendedDataRecordEventIter) == TRUE;                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_ExtendedDataRecordEventIterNext(&lExtendedDataRecordEventIter))                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          Dem_EventIdType lEventId;

          lEventId = Dem_Cfg_ExtendedDataRecordEventIterGet(&lExtendedDataRecordEventIter);                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
          if ((Dem_Cfg_EventAvailableByVariant(lEventId) == TRUE)
            && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(lEventId)) == FALSE))                  /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
          {
            Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, (uint8)Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(ERecEntryIndex)));  /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
            (void)Dem_DataReportIF_CopyExtendedDataRecord(lEventId,                                                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                          0x00U /* Unused parameter for Global ERecs */,
                                                          ERecEntryIndex,
                                                          DEM_MEMORYENTRY_HANDLE_INVALID /* Unused parameter for Global ERecs */,
                                                          DestinationBuffer);
          }
        }
        break;
      }

      case DEM_CFG_EREC_TYPE_INTERNAL:
      {
        for (Dem_Cfg_ExtendedDataRecordEventIterInit(&lExtendedDataRecordEventIter, lCombinedDTCGroupId, ERecId);                /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_ExtendedDataRecordEventIterExists(&lExtendedDataRecordEventIter) == TRUE;                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_Cfg_ExtendedDataRecordEventIterNext(&lExtendedDataRecordEventIter))                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          Dem_EventIdType lEventId;
          Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType lReadoutBufferEventDataIndex;

          lEventId = Dem_Cfg_ExtendedDataRecordEventIterGet(&lExtendedDataRecordEventIter);                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
          lReadoutBufferEventDataIndex = Dem_DTCReadoutBuffer_GetEventDataIndex(ReadoutBufferId, lEventId);

          /* Event has a memory entry, try to copy content */
          if (lReadoutBufferEventDataIndex != Dem_Cfg_SizeOfReadOutBufferData())
          {
            Dem_Dcm_ERec_CopyERec_FromSubEventMemoryEntry(ERecId,                                                                /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                          ReadoutBufferId,
                                                          lReadoutBufferEventDataIndex,
                                                          DestinationBuffer);
          }
        }
        break;
      }

# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
      case DEM_CFG_EREC_TYPE_USER:
      {
        uint8 lUserERecStorageIndex;
        uint8 lNumOccupiedReadoutBufferSlots;
        Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType lReadoutBufferEventDataIndex;

        lReadoutBufferEventDataIndex = DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT;
        lNumOccupiedReadoutBufferSlots = Dem_DTCReadoutBuffer_GetNumberOfOccupiedSlots(ReadoutBufferId);
        lUserERecStorageIndex = Dem_ExtendedEntry_CalculateUserERecStorageIndex(ERecId, lCombinedDTCGroupId);

        for ( /* Initialized to default slot */;
            lReadoutBufferEventDataIndex < lNumOccupiedReadoutBufferSlots;
            lReadoutBufferEventDataIndex++)
        {

          Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;

          lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, lReadoutBufferEventDataIndex);
          if (Dem_ExtendedEntry_GetUserERecStorageStatus(lUserERecStorageIndex, lReadoutBufferMemoryEntryId) == TRUE)
          {
            Dem_Dcm_ERec_CopyERec_FromSubEventMemoryEntry(ERecId,                                                                /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                          ReadoutBufferId,
                                                          lReadoutBufferEventDataIndex,
                                                          DestinationBuffer);
          }
        }
        break;
      }
# endif
      default:                                                                                                                   /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
        /* Do nothing */
        Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE)
        break;
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_ERec_ReadNextRecord_CombinedEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_ReadNextRecord_CombinedEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer                                                         /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  Std_ReturnType lReturnValue;

  lReturnValue = DEM_NO_SUCH_ELEMENT;

# if (DEM_CFG_SUPPORT_ERECS == STD_ON)
  {
    Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
    uint8 lRecordNumber;
    Dem_Cfg_ERecIndexType lERecEntryIndex;
    Dem_DTCReadoutBuffer_RecordNumberIteratorType lRecordNumberIterator;

    lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
    lRecordNumberIterator = Dem_DTCReadoutBuffer_GetRecordNumberIterator(lReadoutBufferId);

    for (/* Already initialized during ERec selection */;
         Dem_Cfg_DTCExtendedDataRecordIterExists(&lRecordNumberIterator) == TRUE;                                                /* SBSW_DEM_CALL_ITERATOR_POINTER */
         Dem_Cfg_DTCExtendedDataRecordIterNext(&lRecordNumberIterator))                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      lRecordNumber = Dem_Cfg_DTCExtendedDataRecordIterGetRecordNr(&lRecordNumberIterator);                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */

      lERecEntryIndex = Dem_Cfg_DTCExtendedDataRecordIterGetERecIndex(&lRecordNumberIterator);                           /* SBSW_DEM_CALL_ITERATOR_POINTER */

      if (Dem_Dcm_ERec_TestRecordMatch(lReadoutBufferId, lRecordNumber) == TRUE)
      {
        lReturnValue = Dem_Dcm_ERec_CopyERec_CombinedDTC(lRecordNumber, lERecEntryIndex,                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                         lReadoutBufferId, DestinationBuffer);
      }

      if (lReturnValue != DEM_NO_SUCH_ELEMENT)
      {
        /* record was found */
        break;
      }
    }

    /* Increment the iterator in case of a positive match
      For negative match does not make any difference */
    Dem_Cfg_DTCExtendedDataRecordIterNext(&lRecordNumberIterator);                                                       /* SBSW_DEM_CALL_ITERATOR_POINTER */
    Dem_DTCReadoutBuffer_SetRecordNumberIterator(lReadoutBufferId, &lRecordNumberIterator);                                      /* SBSW_DEM_POINTER_FORWARD_STACK */
  }
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestinationBuffer)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_ReadNextRecord_NormalEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_ReadNextRecord_NormalEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer                                                         /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
)
{
  Std_ReturnType lReturnValue;

  lReturnValue = DEM_NO_SUCH_ELEMENT;

# if (DEM_CFG_SUPPORT_ERECS == STD_ON)
  {
    Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
    Dem_ExtendedEntry_IterType lExtendedEntryIter;

    lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
    lExtendedEntryIter = Dem_DTCReadoutBuffer_GetExtendedEntryIterator(
                           lReadoutBufferId,
                           DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

    /* Find next record. */
    while (Dem_ExtendedEntry_IterExists(&lExtendedEntryIter) == TRUE)                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
    {
      Dem_Cfg_ERecIndexType lCfgERecIndex;

      lCfgERecIndex = Dem_ExtendedEntry_IterGet(&lExtendedEntryIter);                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */

      /* If the extended data number matches */
      if (Dem_Dcm_ERec_TestRecordMatch(lReadoutBufferId,
                                       (uint8)Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex))) == TRUE)
      {
        lReturnValue = Dem_Dcm_ERec_CopyNextRecord(lReadoutBufferId,
                                                   DestinationBuffer,                                                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                   DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
      }

      Dem_ExtendedEntry_IterNext(&lExtendedEntryIter);                                                                           /* SBSW_DEM_CALL_ITERATOR_POINTER */
      Dem_DTCReadoutBuffer_SetExtendedEntryIterator(lReadoutBufferId,
                                                    DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT,
                                                    lExtendedEntryIter);
      Dem_DTCReadoutBuffer_IncExtendedEntryIndex(lReadoutBufferId,
                                                 DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT,
                                                 Dem_Cfg_ERecType(lCfgERecIndex));

      if (lReturnValue != DEM_NO_SUCH_ELEMENT)
      {
        break;
      }
    }
  }
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestinationBuffer)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_GetSize_NormalEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_GetSize_NormalEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfExtendedDataRecord                                                         /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  Std_ReturnType lReturnValue;

  /* Find the Record number */
  lReturnValue = DEM_NO_SUCH_ELEMENT;

# if (DEM_CFG_SUPPORT_ERECS == STD_ON)
  {
    uint16 lAccumulatedSize;
    Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
    uint8 lRecordNumber;
    Dem_ExtendedEntry_IterType lExtendedEntryIter;
    Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType ReadoutBufferMemoryIndex;

    lAccumulatedSize = 0u;
    lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
    lRecordNumber = Dem_DTCReadoutBuffer_GetExtendedRecordNumber(lReadoutBufferId);
    ReadoutBufferMemoryIndex = DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT;

    if (lRecordNumber < 0xf0U)
    {
      Dem_EventIdType lEventId;
      Dem_Cfg_MemoryEntryHandleType lMemoryEntryId;
      uint8 lExtendedEntryIndex;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId, ReadoutBufferMemoryIndex);
      lMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(lReadoutBufferId, ReadoutBufferMemoryIndex);
      lExtendedEntryIndex = 0u;

      /* Look for one specific record */
      for (Dem_ExtendedEntry_IterInit(lEventId, &lExtendedEntryIter);                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_ExtendedEntry_IterExists(&lExtendedEntryIter) == TRUE;                                                            /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_ExtendedEntry_IterNext(&lExtendedEntryIter))                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        Dem_Cfg_ERecIndexType lCfgERecIndex;

        lCfgERecIndex = Dem_ExtendedEntry_IterGet(&lExtendedEntryIter);                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
        if (lRecordNumber == Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)))
        { /* If the record is supported, the result is always 'OK' */
          lReturnValue = E_OK;
          lAccumulatedSize = Dem_Dcm_ERec_CalculateSize(lCfgERecIndex,
                                                        lReadoutBufferId,
                                                        lMemoryEntryId,
                                                        lExtendedEntryIndex);
          break;
        }

# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
        if (Dem_Cfg_ERecType(lCfgERecIndex) == DEM_CFG_EREC_TYPE_USER)
        {
          lExtendedEntryIndex += 1u;
        }
# endif
      }
    }
    else
    {
      /* Look for all supported records */
      uint8 lERecMinNumber;
      Dem_EventIdType lEventId;
      if (lRecordNumber == 0xffU)
      {
        lERecMinNumber = 0x00U;
        lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId, ReadoutBufferMemoryIndex);
      }
#  if (DEM_FEATURE_NEED_OBD == STD_ON)
      else if (lRecordNumber == 0xfeU)
      {
        lERecMinNumber = 0x8fU;
        lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId, ReadoutBufferMemoryIndex);
      }
#  endif
      else
      {
        lERecMinNumber = 0xffU;
        lEventId = DEM_EVENT_INVALID;
      }

      if (lEventId != DEM_EVENT_INVALID)
      {
        Dem_Cfg_MemoryEntryHandleType lMemoryEntryId;
        uint8 lExtendedEntryIndex;

        lMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(lReadoutBufferId, ReadoutBufferMemoryIndex);
        lExtendedEntryIndex = 0u;

        for (Dem_ExtendedEntry_IterInit(lEventId, &lExtendedEntryIter);                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_ExtendedEntry_IterExists(&lExtendedEntryIter) == TRUE;                                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
             Dem_ExtendedEntry_IterNext(&lExtendedEntryIter))                                                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
        {
          Dem_Cfg_ERecIndexType lCfgERecIndex;

          lCfgERecIndex = Dem_ExtendedEntry_IterGet(&lExtendedEntryIter);                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
          if (Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)) > lERecMinNumber)
          { /* At least one record found - the result should be negative in case the event doesn't
                support any of the requested extended records. */
            lReturnValue = E_OK;
            lAccumulatedSize =
              (uint16)(lAccumulatedSize + Dem_Dcm_ERec_CalculateSize(lCfgERecIndex,
                                                                     lReadoutBufferId,
                                                                     lMemoryEntryId,
                                                                     lExtendedEntryIndex));
          }
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
          if (Dem_Cfg_ERecType(lCfgERecIndex) == DEM_CFG_EREC_TYPE_USER)
          {
            lExtendedEntryIndex += 1u;
          }
# endif
        }
      }
    }

    if (lReturnValue == E_OK)
    {
      *SizeOfExtendedDataRecord = lAccumulatedSize;                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SizeOfExtendedDataRecord)                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6030, 6050, 6080 */ /* MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) */

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_ERec_GetSize_CombinedEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_GetSize_CombinedEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfExtendedDataRecord                                                         /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  uint16 lAccumulatedSize;
  Std_ReturnType lReturnValue;

  /* Find the Record number */
  lAccumulatedSize = 0x00U;
  lReturnValue = DEM_NO_SUCH_ELEMENT;

# if (DEM_CFG_SUPPORT_ERECS == STD_ON)
  {
    uint8 lSelectedRecordNumber;
    Dem_Cfg_ERecIndexType lERecEntryIndex;
    Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
    Dem_Cfg_CombinedGroupIndexType lCombinedDTCGroup;

    lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
    lSelectedRecordNumber = Dem_DTCReadoutBuffer_GetExtendedRecordNumber(lReadoutBufferId);
    lCombinedDTCGroup = Dem_Cfg_EventCombinedGroup(Dem_DTCReadoutBuffer_GetMasterEventId(lReadoutBufferId));

    if (lSelectedRecordNumber < 0xf0U)
    { /* Process single record selection */
      if (Dem_ExtendedEntry_TestDTCHasERecConfigured(lSelectedRecordNumber, lCombinedDTCGroup, &lERecEntryIndex) == TRUE)        /* SBSW_DEM_POINTER_FORWARD_STACK */
      {
        lAccumulatedSize = Dem_Dcm_ERec_CalculateSizeSingleERec_CombinedDTC(
                             lSelectedRecordNumber,
                             lERecEntryIndex,
                             lReadoutBufferId,
                             lCombinedDTCGroup);
        lReturnValue = E_OK;
      }
    }
    else
    { /* Process multiple record selection */
      uint8 lERecMinNumber;
      Dem_Cfg_DTCExtendedDataRecordIterType lDTCExtendedDataRecordIter;

      if (lSelectedRecordNumber == 0xffU)
      {
        lERecMinNumber = 0x00U;
      }
#  if (DEM_FEATURE_NEED_OBD == STD_ON)
      else if (lSelectedRecordNumber == 0xfeU)
      {
        lERecMinNumber = 0x8fU;
      }
#  endif
      else
      {
        lERecMinNumber = 0xffU;
      }

      for (Dem_Cfg_DTCExtendedDataRecordIterInit(&lDTCExtendedDataRecordIter, lCombinedDTCGroup);                                /* SBSW_DEM_CALL_ITERATOR_POINTER */
          (Dem_Cfg_DTCExtendedDataRecordIterExists(&lDTCExtendedDataRecordIter) == TRUE);                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_DTCExtendedDataRecordIterNext(&lDTCExtendedDataRecordIter))                                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        uint8 lERecId;

        lERecId = Dem_Cfg_DTCExtendedDataRecordIterGetRecordNr(&lDTCExtendedDataRecordIter);                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */

        if (lERecId > lERecMinNumber)
        {
          Dem_Cfg_ERecIndexType lERecEntryIdx;

          /* At least one record found - the return should only be negative in case the event does not
             support any of the requested extended records. */
          lReturnValue = E_OK;
          lERecEntryIdx = Dem_Cfg_DTCExtendedDataRecordIterGetERecIndex(&lDTCExtendedDataRecordIter);                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
          lAccumulatedSize += Dem_Dcm_ERec_CalculateSizeSingleERec_CombinedDTC(
                                lERecId,
                                lERecEntryIdx,
                                lReadoutBufferId,
                                lCombinedDTCGroup
                                );
        }
      }
    }

    if (lReturnValue == E_OK)
    {
      *SizeOfExtendedDataRecord = lAccumulatedSize;                                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SizeOfExtendedDataRecord)                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif


# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_ReadNextRecord_NormalEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_NormalEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer                                                         /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  Std_ReturnType lReturnValue;
  boolean lContinue;
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestinationBuffer)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lContinue = TRUE;
  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);

  while (lContinue == TRUE)
  {
    Std_ReturnType lReadNextReturnValue;
    lReadNextReturnValue = DEM_NO_SUCH_ELEMENT;

    switch (Dem_DTCReadoutBuffer_GetSnapshotRecordSource(lReadoutBufferId))
    {
    case Dem_DTCReadoutBuffer_SnapshotSource_Obd:
# if ( ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) )
      lReadNextReturnValue = Dem_Dcm_SRec_ReadNextRecord_Obd(lReadoutBufferId, DestinationBuffer);                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
# endif
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Srec:
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
      lReadNextReturnValue = Dem_Dcm_SRec_ReadNextRecord_Standard(lReadoutBufferId, DestinationBuffer);                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
# endif
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal:
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast:
# if ((DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
      lReadNextReturnValue = Dem_Dcm_SRec_ReadNextRecord_TimeSeries(lReadoutBufferId, DestinationBuffer);                        /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
# endif
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Global:
# if (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON)
      lReadNextReturnValue = Dem_Dcm_SRec_ReadNextRecord_Global(lReadoutBufferId, DestinationBuffer);                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
# endif
      break;
    default:                                                                                                                     /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
      /* Dem_DTCReadoutBuffer_SnapshotSource_Invalid */
      break;
    }

    if (lReadNextReturnValue == DEM_NO_SUCH_ELEMENT)
    {
      Std_ReturnType lSelectNextReturnValue;

      lSelectNextReturnValue = Dem_Dcm_SRec_SelectNextSource(lReadoutBufferId);

      if (lSelectNextReturnValue == DEM_NO_SUCH_ELEMENT)
      {
        lReturnValue = lSelectNextReturnValue;
        lContinue = FALSE;
      }
    }
    else
    {
      lReturnValue = lReadNextReturnValue;
      lContinue = FALSE;
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

# if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION))
/* ****************************************************************************
 % Dem_Dcm_SRec_ReadNextRecord_CombinedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_CombinedDTC(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer                                                         /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  Std_ReturnType lReturnValue;
  boolean lContinue;
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;

  DEM_IGNORE_UNUSED_CONST_ARGUMENT(DestinationBuffer)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lContinue = TRUE;
  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);

  while (lContinue == TRUE)
  {
    Std_ReturnType lReadNextReturnValue;
    lReadNextReturnValue = DEM_NO_SUCH_ELEMENT;

    switch (Dem_DTCReadoutBuffer_GetSnapshotRecordSource(lReadoutBufferId))
    {
    case Dem_DTCReadoutBuffer_SnapshotSource_Obd:
# if ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))
      lReadNextReturnValue = Dem_Dcm_SRec_ReadNextRecord_Obd(lReadoutBufferId, DestinationBuffer);                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
# endif
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Srec:
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
      lReadNextReturnValue = Dem_Dcm_ReadNextSRec_CombinedDTC(lReadoutBufferId, DestinationBuffer);                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
# endif
      break;
    default:                                                                                                                     /* PRQA S 2016 */ /* MD_MSR_EmptyClause */
      /* Currently unsupported containers */
      /* Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal */
      /* Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast */
      /* Dem_DTCReadoutBuffer_SnapshotSource_Global */
      /* Dem_DTCReadoutBuffer_SnapshotSource_Invalid */
      break;
    }

    if (lReadNextReturnValue == DEM_NO_SUCH_ELEMENT)
    {
      Std_ReturnType lSelectNextReturnValue;

      lSelectNextReturnValue = Dem_Dcm_SRec_SelectNextSource(lReadoutBufferId);

      if (lSelectNextReturnValue == DEM_NO_SUCH_ELEMENT)
      {
        lReturnValue = lSelectNextReturnValue;
        lContinue = FALSE;
      }
    }
    else
    {
      lReturnValue = lReadNextReturnValue;
      lContinue = FALSE;
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_SelectFirstSource_CombinedEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_SRec_SelectFirstSource_CombinedEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC) RecordNumber
  )
{
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
  Dem_DTCReadoutBuffer_SnapshotSourceType lSource;

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);

  Dem_DTCReadoutBuffer_SelectSnapshotRecord(
    lReadoutBufferId,
    RecordNumber);

  if ( (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_OBD)
    || (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL) )
  {
# if  ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))
    {
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Obd;
    }
# else
#  if (DEM_CFG_SUPPORT_SRECS == STD_ON)
    if (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL)
    {
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Srec;
    }
    else
#  endif
    {
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
    }
# endif
  }
  else
  {
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Srec;
# else
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
# endif
  }

  Dem_DTCReadoutBuffer_SetSnapshotRecordSource(lReadoutBufferId, lSource);

  /* Snapshot source iterator used during readout only for OBDII freeze frames */
# if ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))
  if (lSource == Dem_DTCReadoutBuffer_SnapshotSource_Obd)
  {
    Dem_Cfg_ComplexIterType lSourceIterator;

    lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(
                        lReadoutBufferId,
                        DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

    Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 1);                                                                           /* SBSW_DEM_POINTER_FORWARD_STACK */

    Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(lReadoutBufferId,
                                                   DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT,
                                                   lSourceIterator);
  }
# endif

# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  {
    Dem_DTCReadoutBuffer_RecordNumberIteratorType lReadoutBufferRecordNumberIter;

    Dem_Cfg_DTCFreezeFrameRecordIterInit(&lReadoutBufferRecordNumberIter,                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
                                         Dem_Cfg_EventCombinedGroup(Dem_DTCReadoutBuffer_GetMasterEventId(lReadoutBufferId)));
    Dem_DTCReadoutBuffer_SetRecordNumberIterator(lReadoutBufferId, &lReadoutBufferRecordNumberIter);                             /* SBSW_DEM_POINTER_FORWARD_STACK */
  }
# endif
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_SelectFirstSource_NormalEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_SRec_SelectFirstSource_NormalEvent(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC) RecordNumber
  )
{
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
  Dem_DTCReadoutBuffer_SnapshotSourceType lSource;

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);

  Dem_DTCReadoutBuffer_SelectSnapshotRecord(
    lReadoutBufferId,
    RecordNumber);

  if ( (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_OBD)
    || (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL) )
  {
# if  ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
    || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Obd;
# else
    if (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL)
    {
# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Srec;
# else
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Global;
# endif
    }
    else
    {
      lSource = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
    }
# endif
  }
  else
# if (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
#  if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
  if ((RecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST) && (RecordNumber <= 0x2Fu))
  {
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast;
  }
  else
#  endif
  if ((RecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST)
    && (RecordNumber <= DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_LAST))
  {
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal;
  }
  else
# endif
# if (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON)
  if (RecordNumber == Dem_Cfg_GlobalSRecId())
  {
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Global;
  }
  else
# endif
  {
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Srec;
# else
    lSource = Dem_DTCReadoutBuffer_SnapshotSource_Invalid;
# endif
  }

  Dem_DTCReadoutBuffer_SetSnapshotRecordSource(lReadoutBufferId, lSource);

  Dem_Dcm_SRec_InitSnapshotIterator(lReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_GetSize_NormalEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_GetSize_NormalEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame                                                                 /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  Std_ReturnType lReturnValue;

# if ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
    || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
    || (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON) \
    || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
  Dem_EventIdType lEventId;                                                                                                      /* PRQA S 3203 */ /* MD_DEM_3203 */
  uint8 lMemoryId;                                                                                                               /* PRQA S 3203 */ /* MD_DEM_3203 */
  uint8 lRecordNumber;
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;
# endif

# if ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
    || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
    || (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON) \
    || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
  lEventId = Dem_DTCReadoutBuffer_GetEventId(lReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);                          /* PRQA S 3203 */ /* MD_DEM_3203 */
  lMemoryId = Dem_DTCReadoutBuffer_GetMemoryId(lReadoutBufferId);                                                                /* PRQA S 3203 */ /* MD_DEM_3203 */
  lRecordNumber = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(lReadoutBufferId);

    if (lRecordNumber == 0x00u)
    {
#  if ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))\
    || (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
      if (lMemoryId == DEM_CFG_MEMORYID_PRIMARY)
      {
#   if (DEM_CFG_SUPPORT_OBDII == STD_ON)
        lReturnValue = Dem_Dcm_SRec_CalculateSize_ObdII(lEventId, SizeOfFreezeFrame);                                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
#   endif
#   if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
        lReturnValue = Dem_Dcm_SRec_CalculateSize_WwhObd(lEventId, SizeOfFreezeFrame);                                           /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
#   endif
      }
      else
#  endif
      {
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    }
    else
#  if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
    if ((lRecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_FIRST)
      && (lRecordNumber <= DEM_DCM_SNAPSHOTDATARECORD_TMC_LAST))
    {
      lReturnValue = Dem_Dcm_SRec_CalculateSize_TimeSeries(lEventId, lRecordNumber, SizeOfFreezeFrame);                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
    else
#  endif
#  if (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON)
    if (lRecordNumber == Dem_Cfg_GlobalSRecId())
    {
      lReturnValue = E_OK;
      if (Dem_DTCReadoutBuffer_TestGlobalSnapshotStored(
            lReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT) == TRUE)
      {
        *SizeOfFreezeFrame = Dem_Cfg_GlobalSRecUdsSize();                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
      else
      {
        *SizeOfFreezeFrame = 0u;                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
    }
    else
#  endif
    if (lRecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL)
    {
      lReturnValue = Dem_Dcm_SRec_CalculateSize_AllNormalEvent(lReadoutBufferId, SizeOfFreezeFrame);                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
    else
#  if (DEM_CFG_SUPPORT_SRECS == STD_ON)
    {
      lReturnValue = Dem_Dcm_SRec_CalculateSize_SingleRecordNormalEvent(lReadoutBufferId, lRecordNumber, SizeOfFreezeFrame);     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
#  else
    {
      lReturnValue = DEM_NO_SUCH_ELEMENT;
    }
#  endif
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SizeOfFreezeFrame)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
  lReturnValue = DEM_NO_SUCH_ELEMENT;
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
    && (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_GetSize_SingleRecordCombinedEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_GetSize_SingleRecordCombinedEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  uint8 lSnapshotHeaderBitMaskIndex;
  Std_ReturnType lReturnValue;
  Dem_EventIdType lMasterEventId;
  Dem_Cfg_CombinedGroupIndexType lCombinedDTCGroup;

  lMasterEventId = Dem_DTCReadoutBuffer_GetMasterEventId(ReadoutBufferId);
  lCombinedDTCGroup = Dem_Cfg_EventCombinedGroup(lMasterEventId);
  lSnapshotHeaderBitMaskIndex = Dem_SnapshotEntry_FindSRecIndexInCombinedDTCSRecList(RecordNumber, lCombinedDTCGroup);

  if ((lSnapshotHeaderBitMaskIndex == DEM_SNAPSHOTENTRY_CONFIGURED_SREC_INDEX_INVALID)
    || (Dem_SnapshotEntry_SRecIsSupportedByAvailableCombinedEvent(lCombinedDTCGroup, RecordNumber) == FALSE))                    /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
  {
    *SizeOfFreezeFrame = 0x00U;                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    *SizeOfFreezeFrame = Dem_Dcm_SRec_CalculateSize_SingleRecordCombinedEvent(ReadoutBufferId,                                   /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
                                                                              RecordNumber,
                                                                              lSnapshotHeaderBitMaskIndex);
    lReturnValue = E_OK;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON) \
   && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
     || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))\
    ) )
/* ****************************************************************************
 % Dem_Dcm_SRec_CalculateSize_AllCombinedEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_AllCombinedEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;
  uint16 lSizeOfFreezeFrame;

  /* Initialize the negative return value */
  lSizeOfFreezeFrame = 0x00U;
  lReturnValue = DEM_NO_SUCH_ELEMENT;

# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  {
    Dem_EventIdType lEventId;
    Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType lReadoutBufferDataIndex;
    uint8 lNumOccupiedReadoutBufferEntries;
    Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;
    Dem_DTCReadoutBuffer_RecordNumberIteratorType lRecordNumberIterator;

    lRecordNumberIterator = Dem_DTCReadoutBuffer_GetRecordNumberIterator(ReadoutBufferId);
    if (Dem_Cfg_DTCFreezeFrameRecordIterExists(&lRecordNumberIterator) == TRUE)                                         /* SBSW_DEM_POINTER_FORWARD_STACK */
    {
      lSizeOfFreezeFrame = 0x00U;
      lNumOccupiedReadoutBufferEntries = Dem_DTCReadoutBuffer_GetNumberOfOccupiedSlots(ReadoutBufferId);

      for (lReadoutBufferDataIndex = DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT;
           lReadoutBufferDataIndex < lNumOccupiedReadoutBufferEntries;
           lReadoutBufferDataIndex++)
      {
        lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, lReadoutBufferDataIndex);
        lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, lReadoutBufferDataIndex);
        lSizeOfFreezeFrame += ((uint16)(Dem_SnapshotEntry_GetNumberOfStoredSnapshotRecords(lReadoutBufferMemoryEntryId)
                                          * Dem_Cfg_EventSRecUdsSize(lEventId)));
      }
      lReturnValue = E_OK;
    }
  }
# endif

# if ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))
  {
    if (Dem_DTCReadoutBuffer_GetOBDData_IsStored(ReadoutBufferId) == TRUE)
    {
      lSizeOfFreezeFrame += Dem_Cfg_GlobalObdIIFFUdsSize();
    }
    lReturnValue = E_OK;
  }
# endif

  *SizeOfFreezeFrame = lSizeOfFreezeFrame;                                                                                       /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_GetSize_CombinedEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_GetSize_CombinedEvent(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame                                                                 /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  Std_ReturnType lReturnValue;

# if ( (DEM_CFG_SUPPORT_SRECS == STD_ON)\
    || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)))
  uint8 lMemoryId;                                                                                                               /* PRQA S 3203 */ /* MD_DEM_3203 */
  uint8 lRecordNumber;
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
  lMemoryId = Dem_DTCReadoutBuffer_GetMemoryId(lReadoutBufferId);                                                                /* PRQA S 3203 */ /* MD_DEM_3203 */
  lRecordNumber = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(lReadoutBufferId);

  if (lRecordNumber == 0x00u)
  {
#  if ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON))
    if (lMemoryId == DEM_CFG_MEMORYID_PRIMARY)
    {
      if (Dem_DTCReadoutBuffer_GetOBDData_IsStored(lReadoutBufferId) == TRUE)
      {
        *SizeOfFreezeFrame = Dem_Cfg_GlobalObdIIFFUdsSize();                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
      else
      {
        *SizeOfFreezeFrame = 0u;                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }

      lReturnValue = E_OK;
    }
    else
#  endif
    {
      lReturnValue = DEM_NO_SUCH_ELEMENT;
    }
  }
  else if (lRecordNumber == DEM_DCM_SNAPSHOTDATARECORD_ALL)
  {
    lReturnValue = Dem_Dcm_SRec_CalculateSize_AllCombinedEvent(lReadoutBufferId, SizeOfFreezeFrame);                             /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
  else
#  if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  {
    lReturnValue = Dem_Dcm_SRec_GetSize_SingleRecordCombinedEvent(                                                               /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                     lReadoutBufferId, lRecordNumber, SizeOfFreezeFrame);
  }
#  else
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
#  endif
# else
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ClientId)                                                                                     /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(SizeOfFreezeFrame)                                                                            /* PRQA S 3112 */ /* MD_DEM_14.2 */
  lReturnValue = DEM_NO_SUCH_ELEMENT;
# endif

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_CopySRec_CombinedSubEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_SRec_CopySRec_CombinedSubEvent(
  CONST(uint8, AUTOMATIC) SRecId,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Dem_Cfg_SnapshotEntry_IterType lSnapshotEntryIter;
  Dem_Cfg_SRecIndexType lSRecIndex;

  lSnapshotEntryIter = Dem_DTCReadoutBuffer_GetSnapshotEntryIterator(
                         ReadoutBufferId,
                         ReadoutBufferDataIndex);

  while (Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == TRUE)                                                          /* SBSW_DEM_POINTER_FORWARD_STACK */
  {
    lSRecIndex = Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter);                                          /* SBSW_DEM_POINTER_FORWARD_STACK */
    if (SRecId == Dem_Cfg_SRecId(lSRecIndex))
    {
        Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, Dem_Cfg_SRecId(lSRecIndex));                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        Dem_DataReportIF_SRecCopyData(DestinationBuffer,                                                                         /* SBSW_DEM_POINTER_DESTINATIONBUFFER_SOURCEBUFFER */
                                      Dem_SnapshotEntry_IteratorGetSnapshotRecordDataConstPtr(&lSnapshotEntryIter),              /* SBSW_DEM_POINTER_FORWARD_STACK */
                                      Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, ReadoutBufferDataIndex),
                                      Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, ReadoutBufferDataIndex));

      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }
    else
    {
      /* otherwise next snapshot record */
    }

    Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter);                                                                         /* SBSW_DEM_POINTER_FORWARD_STACK */
  }

  /* Detect an Inconsistent state.
     - Between the snapshot record storage status and DTC record storage status
     - Between DTC record storage status and configuration
  */
  Dem_Internal_AssertContinue(Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter), DEM_E_INCONSISTENT_STATE)                   /* SBSW_DEM_POINTER_FORWARD_STACK */

  Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter);                                                                           /* SBSW_DEM_POINTER_FORWARD_STACK */
  Dem_DTCReadoutBuffer_SetSnapshotEntryIterator(ReadoutBufferId,
                                                ReadoutBufferDataIndex,
                                                lSnapshotEntryIter);

}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_CopySRec_CombinedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CopySRec_CombinedDTC(
  CONST(uint8, AUTOMATIC) SRecId,
  CONST(uint8, AUTOMATIC)  SnapshotHeaderBitMaskIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_CombinedGroupIndexType lCombinedDTCGroupId;

  lCombinedDTCGroupId = Dem_Cfg_EventCombinedGroup(Dem_DTCReadoutBuffer_GetMasterEventId(ReadoutBufferId));
  if (Dem_SnapshotEntry_SRecIsSupportedByAvailableCombinedEvent(lCombinedDTCGroupId, SRecId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else if (DestinationBuffer->BufferSize < Dem_Dcm_SRec_CalculateSize_SingleRecordCombinedEvent(ReadoutBufferId, SRecId, SnapshotHeaderBitMaskIndex))
  { /* Supported record, but the buffer is not large enough for all the data */
    lReturnValue = DEM_BUFFER_TOO_SMALL;
  }
  else
  {
    uint8 lNumOccupiedReadoutBufferEntries;
    Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;
    Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType ReadoutBufferMemoryIndex;

    ReadoutBufferMemoryIndex = DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT;
    lNumOccupiedReadoutBufferEntries = Dem_DTCReadoutBuffer_GetNumberOfOccupiedSlots(ReadoutBufferId);

    for (; ReadoutBufferMemoryIndex < lNumOccupiedReadoutBufferEntries; ReadoutBufferMemoryIndex++)
    {
      lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, ReadoutBufferMemoryIndex);
      if (Dem_SnapshotEntry_GetSRecStorageStatus(SRecId, SnapshotHeaderBitMaskIndex, lReadoutBufferMemoryEntryId) == TRUE)
      {
        Dem_Dcm_SRec_CopySRec_CombinedSubEvent(SRecId, ReadoutBufferId, ReadoutBufferMemoryIndex, DestinationBuffer);            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
      }
    }
    lReturnValue = E_OK;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_ReadNextSRec_CombinedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ReadNextSRec_CombinedDTC(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Std_ReturnType lReturnValue;
  uint8 lRecordNumber;
  Dem_DTCReadoutBuffer_RecordNumberIteratorType lRecordNumberIterator;

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lRecordNumberIterator = Dem_DTCReadoutBuffer_GetRecordNumberIterator(ReadoutBufferId);

  for (/* Already initialized during SRec selection */;
       Dem_Cfg_DTCFreezeFrameRecordIterExists(&lRecordNumberIterator) == TRUE;                                          /* SBSW_DEM_CALL_ITERATOR_POINTER */
       Dem_Cfg_DTCFreezeFrameRecordIterNext(&lRecordNumberIterator))                                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    lRecordNumber = Dem_Cfg_DTCFreezeFrameRecordIterGet(&lRecordNumberIterator);                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */

    if (Dem_Dcm_SRec_TestRecordMatch(ReadoutBufferId, lRecordNumber) == TRUE)
    {
      uint8 lSnapshotHeaderBitMaskIndex;
      Dem_Cfg_CombinedGroupIndexType lCombinedDTCGroup;
      lCombinedDTCGroup = Dem_Cfg_EventCombinedGroup(Dem_DTCReadoutBuffer_GetMasterEventId(ReadoutBufferId));
      lSnapshotHeaderBitMaskIndex = Dem_DTCReadoutBuffer_GetSnapShotHeaderBitMaskIndex(                                          /* SBSW_DEM_POINTER_FORWARD_STACK */
                                      &lRecordNumberIterator, lCombinedDTCGroup);
      lReturnValue = Dem_Dcm_SRec_CopySRec_CombinedDTC(lRecordNumber,                                                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                       lSnapshotHeaderBitMaskIndex, ReadoutBufferId, DestinationBuffer);
      break;
    }
  }

  /* Increment the iterator in case of a positive match
     For negative match does not make any difference */
  Dem_Cfg_DTCFreezeFrameRecordIterNext(&lRecordNumberIterator);                                                         /* SBSW_DEM_CALL_ITERATOR_POINTER */
  Dem_DTCReadoutBuffer_SetRecordNumberIterator(ReadoutBufferId, &lRecordNumberIterator);                                         /* SBSW_DEM_POINTER_FORWARD_STACK */

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_TestRecordMatch
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE boolean Dem_Dcm_ERec_TestRecordMatch(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC) RecordNumber
  )
{
  boolean lMatch;
  uint8 lRecordNumberFilter;
  lRecordNumberFilter = Dem_DTCReadoutBuffer_GetExtendedRecordNumber(ReadoutBufferId);

  lMatch = FALSE;
  if ( (lRecordNumberFilter == DEM_DCM_EXTENDEDDATARECORD_ALL)
    && (RecordNumber >= DEM_DCM_EXTENDEDDATARECORD_FIRST)
    && (RecordNumber <= DEM_DCM_EXTENDEDDATARECORD_LAST))
  {
    lMatch = TRUE;
  }
# if (DEM_FEATURE_NEED_OBD == STD_ON)
  else if ( (lRecordNumberFilter == DEM_DCM_EXTENDEDDATARECORD_OBD)
    && (RecordNumber >= DEM_DCM_EXTENDEDDATARECORD_FIRST_OBD)
    && (RecordNumber <= DEM_DCM_EXTENDEDDATARECORD_LAST))
  {
    lMatch = TRUE;
  }
# endif
  else if (lRecordNumberFilter == RecordNumber)
  {
# if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
    if (Dem_DTCReadoutBuffer_TestCombinedEventSelected(ReadoutBufferId) == TRUE)
    {
      Dem_Cfg_CombinedGroupIndexType lCombinedDTCGroupId;

      lCombinedDTCGroupId = Dem_Cfg_EventCombinedGroup(Dem_DTCReadoutBuffer_GetMasterEventId(ReadoutBufferId));
      lMatch = Dem_ExtendedEntry_ERecIsSupportedByAvailableCombinedEvent(lCombinedDTCGroupId, RecordNumber);
    }
    else
# endif
    {
      lMatch = TRUE;
    }
  }
  else
  {
    /* lMatch already set to FALSE*/
  }

  return lMatch;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_CopyNextRecord
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_CopyNextRecord(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex
  )
{
  uint8 lERecType;
  Dem_ExtendedEntry_IterType lExtendedEntryIter;
  Dem_Cfg_ERecIndexType lCfgERecIndex;
  Std_ReturnType lReturnValue;

  lReturnValue = E_NOT_OK;

  lExtendedEntryIter = Dem_DTCReadoutBuffer_GetExtendedEntryIterator(
                         ReadoutBufferId,
                         ReadoutBufferDataIndex);
  if (Dem_ExtendedEntry_IterExists(&lExtendedEntryIter) == TRUE)                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    Dem_Cfg_MemoryEntryHandleType lMemoryEntryId;
    Dem_EventIdType lEventId;
    uint8 lExtendedEntryIndex;

    lMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(
                       ReadoutBufferId,
                       ReadoutBufferDataIndex);
    lExtendedEntryIndex = Dem_DTCReadoutBuffer_GetExtendedEntryIndex(
                          ReadoutBufferId,
                          ReadoutBufferDataIndex);
    lEventId = Dem_DTCReadoutBuffer_GetEventId(
                 ReadoutBufferId,
                 ReadoutBufferDataIndex);

    lCfgERecIndex = Dem_ExtendedEntry_IterGet(&lExtendedEntryIter);                                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */
    lERecType = Dem_Cfg_ERecType(lCfgERecIndex);

    if ((lERecType == DEM_CFG_EREC_TYPE_GLOBAL)
      || ((Dem_DTCReadoutBuffer_TestStoredDataAvailable(ReadoutBufferId) == TRUE)                                                /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
      && ((lERecType == DEM_CFG_EREC_TYPE_INTERNAL)
      || (Dem_ExtendedEntry_IteratorIsExtendedRecordStored(lMemoryEntryId, lExtendedEntryIndex) == TRUE)                         /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
      )
# endif
      )
      )
    {
      /* Check buffer size after stored status - the buffer does not need to be large enough for an empty response */
      if ((Dem_Cfg_DidSize(Dem_Cfg_ERecDid(lCfgERecIndex)) + 1u) > (uint16)(DestinationBuffer->BufferSize - DestinationBuffer->WriteIndex))
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      {
        Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, (uint8)Dem_Cfg_DidNumber(Dem_Cfg_ERecDid(lCfgERecIndex)));       /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        (void)Dem_DataReportIF_CopyExtendedDataRecord(lEventId,                                                                  /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
                                                    lExtendedEntryIndex,
                                                    lCfgERecIndex,
                                                    lMemoryEntryId,
                                                    DestinationBuffer);

        lReturnValue = E_OK;
      }
    }
    else
    {
      /* records currently not stored are returned with empty content */
      lReturnValue = E_OK;
      Dem_Data_ResetWriteIndexDestinationBuffer(DestinationBuffer);                                                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON) \
    && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    ||   ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
    ||   (DEM_CFG_SUPPORT_WWHOBD == STD_ON) \
    ||   (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_TestRecordMatch
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(boolean, DEM_CODE) Dem_Dcm_SRec_TestRecordMatch(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC) RecordNumber
  )
{
  boolean lMatch;
  uint8 lRecordNumberFilter;
  lRecordNumberFilter = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId);

  if (lRecordNumberFilter == DEM_DCM_SNAPSHOTDATARECORD_ALL)
  {
# if (DEM_CFG_SUPPORT_WWHOBD == STD_OFF) \
     && ((DEM_CFG_SUPPORT_OBDII == STD_OFF) || (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_OFF))
    /* exclude OBD Snapshot if necessary */
    if (RecordNumber == DEM_DCM_SNAPSHOTDATARECORD_OBD)
    {
      lMatch = FALSE;
    }
    else
# endif
    {
      lMatch = TRUE;
    }
  }
  else
  {
    if (lRecordNumberFilter == RecordNumber)
    {
      lMatch = TRUE;
    }
    else
    {
      lMatch = FALSE;
    }
  }
  return lMatch;
}
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_InitSnapshotIterator
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE) Dem_Dcm_SRec_InitSnapshotIterator(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType, AUTOMATIC)  ReadoutBufferDataIndex
  )
{
  Dem_Cfg_ComplexIterType lSourceIterator;

  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(
                      ReadoutBufferId,
                      ReadoutBufferDataIndex);
  switch (Dem_DTCReadoutBuffer_GetSnapshotRecordSource(ReadoutBufferId))
  {
    case Dem_DTCReadoutBuffer_SnapshotSource_Obd:
    case Dem_DTCReadoutBuffer_SnapshotSource_Global:
    {
      Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 1);                                                                           /* SBSW_DEM_POINTER_FORWARD_STACK */
    }
    break;

    case Dem_DTCReadoutBuffer_SnapshotSource_Srec:
    {
      Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);                                                                           /* SBSW_DEM_POINTER_FORWARD_STACK */
    }
    break;

    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast:
    {
      Dem_EventIdType lEventId;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, ReadoutBufferDataIndex);
      if (Dem_Cfg_EventSupportTimeSeriesFast(lEventId) == TRUE)
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator,                                                                                /* SBSW_DEM_POINTER_FORWARD_STACK */
          DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST,
          (uint16_least)DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST +
          Dem_Cfg_TimeSeriesPastSamplesFast() + Dem_Cfg_TimeSeriesFutureSamplesFast());
      }
      else
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);                                                                         /* SBSW_DEM_POINTER_FORWARD_STACK */
      }
    }
    break;

    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal:
    {
      Dem_EventIdType lEventId;

      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, ReadoutBufferDataIndex);

      if (Dem_Cfg_EventSupportTimeSeriesNormal(lEventId) == TRUE)
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator,                                                                                /* SBSW_DEM_POINTER_FORWARD_STACK */
          DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST,
          (uint16_least)DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST +
          Dem_Cfg_TimeSeriesPastSamplesNormal() + Dem_Cfg_TimeSeriesFutureSamplesNormal());
      }
      else
      {
        Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);                                                                         /* SBSW_DEM_POINTER_FORWARD_STACK */
      }
    }
    break;

    default:
    {
      Dem_Cfg_ComplexIterInit(&lSourceIterator, 0, 0);                                                                           /* SBSW_DEM_POINTER_FORWARD_STACK */
    }
    break;
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId,
                                                 ReadoutBufferDataIndex,
                                                 lSourceIterator);
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

# if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_SelectNextSource
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_SelectNextSource(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId)
        == DEM_DCM_SNAPSHOTDATARECORD_ALL)
  {
    switch (Dem_DTCReadoutBuffer_GetSnapshotRecordSource(ReadoutBufferId))
    {
    case Dem_DTCReadoutBuffer_SnapshotSource_Obd:
# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Srec);
# else
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Global);
# endif
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Srec:
# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Global);
# else
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast);
# endif
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Global:
#  if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast);
#  else
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Srec);
#  endif
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Fast:
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal);
      lReturnValue = E_OK;
      break;
    case Dem_DTCReadoutBuffer_SnapshotSource_Tmc_Normal:
      Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Invalid);
      lReturnValue = DEM_NO_SUCH_ELEMENT;
      break;
    default:
      /* Dem_DTCReadoutBuffer_SnapshotSource_Invalid */
      lReturnValue = DEM_NO_SUCH_ELEMENT;
      break;
    }
  }
  else
  {
    Dem_DTCReadoutBuffer_SetSnapshotRecordSource(ReadoutBufferId, Dem_DTCReadoutBuffer_SnapshotSource_Invalid);
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }

  Dem_Dcm_SRec_InitSnapshotIterator(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

  return lReturnValue;
}
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && ( ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
/* ****************************************************************************
 % Dem_Dcm_SRec_ReadNextRecord_Obd
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_Obd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
)
{
  Dem_Cfg_ComplexIterType lSourceIterator;
  Std_ReturnType lReturnValue;

  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(
                      ReadoutBufferId,
                      DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

  if (Dem_Cfg_ComplexIterExists(&lSourceIterator) == FALSE)                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    if (Dem_Dcm_SRec_TestRecordMatch(ReadoutBufferId, 0x00u) == TRUE)
    {
# if (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)
      if (Dem_DTCReadoutBuffer_GetMemoryId(ReadoutBufferId) == DEM_CFG_MEMORYID_PRIMARY)
      {
        lReturnValue = Dem_Dcm_SRec_CopyNextRecord_ObdII(ReadoutBufferId, DestinationBuffer);                                    /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
      }
      else
# endif
# if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
      if (Dem_DTCReadoutBuffer_GetMemoryId(ReadoutBufferId) == DEM_CFG_MEMORYID_PRIMARY)
      {
        lReturnValue = Dem_Dcm_SRec_CopyNextRecord_WwhObd(ReadoutBufferId, DestinationBuffer);                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
      }
      else
# endif
      {
        lReturnValue = DEM_NO_SUCH_ELEMENT;
      }
    }
    else
    {
      lReturnValue = DEM_NO_SUCH_ELEMENT;
    }

    Dem_Cfg_ComplexIterNext(&lSourceIterator);                                                                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId,
                                                 DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT,
                                                 lSourceIterator);

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_FEATURE_NEED_OEM_EXTENSIONS_TMC == STD_ON) \
   && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_ReadNextRecord_TimeSeries
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_TimeSeries(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_ComplexIterType lSourceIterator;

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(
                      ReadoutBufferId,
                      DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

  while (Dem_Cfg_ComplexIterExists(&lSourceIterator) == TRUE)                                                                    /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    uint8 lRecordNumber;
    Dem_EventIdType lEventId;

    lRecordNumber = (uint8)Dem_Cfg_ComplexIterGet(&lSourceIterator);                                                             /* SBSW_DEM_CALL_ITERATOR_POINTER */
    lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

    if (Dem_Dcm_SRec_TestRecordMatch(ReadoutBufferId, lRecordNumber) == TRUE)
    {
      if (Dem_Cfg_EventSRecUdsSize(lEventId) > DestinationBuffer->BufferSize)
      {
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      {
        lReturnValue = E_OK;
        if (Dem_Data_TimeSeriesSRecIsStored(&Dem_Cfg_TimeSeriesReadoutBuffer, lRecordNumber) == TRUE)                            /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
        {
          Dem_ConstSharedDataPtrType lpSourceBuffer;

# if (DEM_FEATURE_NEED_TIME_SERIES_FAST == STD_ON)
          if ( (lRecordNumber >= DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST)
             && (lRecordNumber <= DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_LAST) )
          {
            lpSourceBuffer =
              Dem_Mem_TimeSeriesEntryGetFastConstDataPtr(&Dem_Cfg_TimeSeriesReadoutBuffer,
                                                         lRecordNumber - DEM_DCM_SNAPSHOTDATARECORD_TMC_FAST_FIRST);             /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
          }
          else
# endif
          {
            lpSourceBuffer =
              Dem_Mem_TimeSeriesEntryGetNormalConstDataPtr(&Dem_Cfg_TimeSeriesReadoutBuffer,
                                                           lRecordNumber - DEM_DCM_SNAPSHOTDATARECORD_TMC_NORMAL_FIRST);         /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
          }

          /* Initialize a DestinationBuffer Context. */
          Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, lRecordNumber);                                                /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */

          Dem_DataReportIF_SRecCopyData(DestinationBuffer,                                                                       /* SBSW_DEM_POINTER_DESTINATIONBUFFER_SOURCEBUFFER */
                                        lpSourceBuffer,
                                        lEventId,
                                        Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT));
        }
      }
      Dem_Cfg_ComplexIterNext(&lSourceIterator);                                                                                 /* SBSW_DEM_CALL_ITERATOR_POINTER */
      break;
    }

    Dem_Cfg_ComplexIterNext(&lSourceIterator);                                                                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId,
                                                 DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT,
                                                 lSourceIterator);

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_ReadNextRecord_Standard
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_Standard(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Std_ReturnType lReturnValue;
  Dem_Cfg_SnapshotEntry_IterType lSnapshotEntryIter;
  Dem_Cfg_SRecIndexType lSRecIndex;

  lReturnValue = DEM_NO_SUCH_ELEMENT;
  lSnapshotEntryIter = Dem_DTCReadoutBuffer_GetSnapshotEntryIterator(
                         ReadoutBufferId,
                         DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

  while (Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == TRUE)                                                          /* SBSW_DEM_POINTER_FORWARD_STACK */
  {
# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
    uint8 lRecordNumber;
# endif

    lSRecIndex = Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter);                                          /* SBSW_DEM_POINTER_FORWARD_STACK */

# if (DEM_CFG_SUPPORT_SRECS_CALCULATED == STD_ON)
    lRecordNumber = Dem_DTCReadoutBuffer_GetSnapshotRecordNumber(ReadoutBufferId);
    if (lRecordNumber < Dem_Cfg_SRecId(lSRecIndex))
    {
      /* overshoot -> snapshot not supported */
      lReturnValue = DEM_NO_SUCH_ELEMENT;
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }
    else
# endif
      if (Dem_Dcm_SRec_TestRecordMatch(ReadoutBufferId, Dem_Cfg_SRecId(lSRecIndex)) == TRUE)
    {
      Dem_EventIdType lEventId;
      lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
      if (DestinationBuffer->BufferSize < Dem_Cfg_EventSRecUdsSize(lEventId))
      {
        /* supported record, but the buffer is not large enough for all the data */
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      {
        if (Dem_SnapshotEntry_IteratorIsSnapshotRecordStored(&lSnapshotEntryIter) == TRUE)                                       /* SBSW_DEM_POINTER_FORWARD_STACK */
        {
          Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, Dem_Cfg_SRecId(lSRecIndex));                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
          Dem_DataReportIF_SRecCopyData(DestinationBuffer,                                                                       /* SBSW_DEM_POINTER_DESTINATIONBUFFER_SOURCEBUFFER */
                                        Dem_SnapshotEntry_IteratorGetSnapshotRecordDataConstPtr(&lSnapshotEntryIter),            /* SBSW_DEM_POINTER_FORWARD_STACK */
                                        lEventId,
                                        Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId,
                                        DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT));
        }

        lReturnValue = E_OK;
      }

      Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter);                                                                       /* SBSW_DEM_POINTER_FORWARD_STACK */
      break;                                                                                                                     /* PRQA S 0771 */ /* MD_DEM_14.6_opt */
    }
    else
    {
      /* otherwise next snapshot record */
    }

    Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter);                                                                         /* SBSW_DEM_POINTER_FORWARD_STACK */
  }

  Dem_DTCReadoutBuffer_SetSnapshotEntryIterator(ReadoutBufferId,
                                                DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT,
                                                lSnapshotEntryIter);

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON) */

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_ReadNextRecord_Global
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord_Global(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Dem_Cfg_ComplexIterType lSourceIterator;
  Std_ReturnType lReturnValue;

  lSourceIterator = Dem_DTCReadoutBuffer_GetSnapshotSourceIterator(
                      ReadoutBufferId,
                      DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

  if (Dem_Cfg_ComplexIterExists(&lSourceIterator) == FALSE)                                                                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
  {
    /* Global snapshot read with previous read operation, there is no second one */
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    if (DestinationBuffer->BufferSize < Dem_Cfg_GlobalSRecUdsSize())
    {
      /* supported record, but the buffer is not large enough for all the data */
      lReturnValue = DEM_BUFFER_TOO_SMALL;
    }
    else
    {
      if (Dem_DTCReadoutBuffer_TestGlobalSnapshotStored(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT) == TRUE)
      {
        Dem_EventIdType lEventId;
        Dem_DataPtrType lGlobalSnapshotDataPtr;
        Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;

        lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
        lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId,
                                                                            DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
        lGlobalSnapshotDataPtr = Dem_DTCReadoutBuffer_GetGlobalSnapshotDataPtr(
                                   ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

        Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, Dem_Cfg_GlobalSRecId());                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        Dem_DataReportIF_GlobalSnapshotCopyData(DestinationBuffer,                                                               /* SBSW_DEM_POINTER_DESTINATIONBUFFER_SOURCEBUFFER */
                                                lGlobalSnapshotDataPtr,                                                          /* SBSW_DEM_POINTER_FORWARD_STACK */
                                                lEventId,
                                                lReadoutBufferMemoryEntryId);
      }

      lReturnValue = E_OK;
    }
    Dem_Cfg_ComplexIterNext(&lSourceIterator);                                                                                   /* SBSW_DEM_CALL_ITERATOR_POINTER */
  }

  Dem_DTCReadoutBuffer_SetSnapshotSourceIterator(ReadoutBufferId,
                                                 DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT,
                                                 lSourceIterator);
  return lReturnValue;
}                                                                                                                                /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_CalculateSize_TimeSeries
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_TimeSeries(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_Data_TimeSeriesSRecIsValid(EventId, RecordNumber) == TRUE)
  {
    lReturnValue = E_OK;
    if (Dem_Data_TimeSeriesSRecIsStored(&Dem_Cfg_TimeSeriesReadoutBuffer, RecordNumber) == TRUE)                                 /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
    {
      *SizeOfFreezeFrame = Dem_Cfg_EventSRecUdsSize(EventId);                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    {
      *SizeOfFreezeFrame = 0u;                                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }
  else
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_SRECS == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_CalculateSize_SingleRecordNormalEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_SingleRecordNormalEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;

  /* Specific record not found is a negative result */
  Dem_Cfg_SnapshotEntry_IterType lSnapshotEntryIter;
  Dem_EventIdType lEventId;
  Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;

  lReturnValue = E_OK;
  lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
  lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

  for (Dem_SnapshotEntry_IteratorInit(lEventId, lReadoutBufferMemoryEntryId, &lSnapshotEntryIter);         /* SBSW_DEM_POINTER_FORWARD_STACK */
        Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == TRUE;                                                           /* SBSW_DEM_POINTER_FORWARD_STACK */
        Dem_SnapshotEntry_IteratorNext(&lSnapshotEntryIter))                                                                     /* SBSW_DEM_POINTER_FORWARD_STACK */
  {
    Dem_Cfg_SRecIndexType lCfgSRecIndex;
    lCfgSRecIndex = Dem_SnapshotEntry_IteratorGetSnapshotRecordIndex(&lSnapshotEntryIter);                                       /* SBSW_DEM_POINTER_FORWARD_STACK */
    DEM_IGNORE_UNUSED_VARIABLE(lCfgSRecIndex)                                                                                    /* PRQA S 3112 */ /* MD_DEM_14.2 */

    if (Dem_Cfg_SRecId(lCfgSRecIndex) == RecordNumber)
    {
      if (Dem_SnapshotEntry_IteratorIsSnapshotRecordStored(&lSnapshotEntryIter) == TRUE)                                         /* SBSW_DEM_POINTER_FORWARD_STACK */
      {
        *SizeOfFreezeFrame = Dem_Cfg_EventSRecUdsSize(lEventId);                                                                 /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
      else
      {
        *SizeOfFreezeFrame = 0u;                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
      break;
    }
  }

  if (Dem_SnapshotEntry_IteratorExists(&lSnapshotEntryIter) == FALSE)                                                            /* SBSW_DEM_POINTER_FORWARD_STACK */
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
    && (DEM_CFG_SUPPORT_SRECS == STD_ON) \
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_SRec_CalculateSize_SingleRecordCombinedEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(uint16, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_SingleRecordCombinedEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(uint8, AUTOMATIC)  RecordNumber,
  CONST(uint8, AUTOMATIC)  SnapshotHeaderBitMaskIndex
  )
{
  uint16 lSizeOfFreezeFrame;
  uint8 lNumOccupiedReadoutBufferEntries;
  Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;
  Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType ReadoutBufferDataIndex;

  lSizeOfFreezeFrame = 0x00U;
  lNumOccupiedReadoutBufferEntries = Dem_DTCReadoutBuffer_GetNumberOfOccupiedSlots(ReadoutBufferId);

  for (ReadoutBufferDataIndex = DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT;
       ReadoutBufferDataIndex < lNumOccupiedReadoutBufferEntries;
       ReadoutBufferDataIndex++)
  {
    lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, ReadoutBufferDataIndex);
    if (Dem_SnapshotEntry_GetSRecStorageStatus(RecordNumber, SnapshotHeaderBitMaskIndex, lReadoutBufferMemoryEntryId) == TRUE)
    {
      lSizeOfFreezeFrame += Dem_Cfg_EventSRecUdsSize(
        Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, ReadoutBufferDataIndex));
    }
  }

  return lSizeOfFreezeFrame;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && ( (DEM_CFG_SUPPORT_SRECS == STD_ON) \
     || (DEM_FEATURE_NEED_TIME_SERIES == STD_ON) \
     || (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON) \
     || ((DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON)) \
     || (DEM_CFG_SUPPORT_WWHOBD == STD_ON) ) )
/* ****************************************************************************
 % Dem_Dcm_SRec_CalculateSize_AllNormalEvent
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_AllNormalEvent(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;
  uint16 lSizeOfFreezeFrame;
  Dem_EventIdType lEventId;

  lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
# if (DEM_CFG_SUPPORT_SRECS == STD_ON)
  {
    Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;

    lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId,
                                                                        DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
    lSizeOfFreezeFrame =
      (uint16)(Dem_SnapshotEntry_GetNumberOfStoredSnapshotRecords(lReadoutBufferMemoryEntryId)
                 * Dem_Cfg_EventSRecUdsSize(lEventId));
  }
  lReturnValue = E_OK;
# else
  lSizeOfFreezeFrame = 0u;
  lReturnValue = DEM_NO_SUCH_ELEMENT;
# endif

# if (DEM_FEATURE_NEED_TIME_SERIES == STD_ON)
  {
    /* lReturnValue = E_OK already set since time series cannot be active if
       DEM_CFG_SUPPORT_SRECS is off */
    lSizeOfFreezeFrame += (uint16)(Dem_Data_TimeSeriesSRecCount(&Dem_Cfg_TimeSeriesReadoutBuffer)
                                      * Dem_Cfg_EventSRecUdsSize(lEventId));                                                     /* SBSW_DEM_POINTER_FORWARD_GLOBAL */
  }
# endif

# if (DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_ON)
  {
#  if (DEM_CFG_SUPPORT_SRECS == STD_OFF)
    lReturnValue = E_OK;
#  endif
    if (Dem_DTCReadoutBuffer_TestGlobalSnapshotStored(
          ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT) == TRUE)
    {
      lSizeOfFreezeFrame += Dem_Cfg_GlobalSRecUdsSize();                                                                         
    }
  }
# endif

# if (  (DEM_CFG_SUPPORT_WWHOBD == STD_ON)\
     || (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )
  {
    uint16 lSizeOfOBDFreezeFrame;

#  if(DEM_CFG_SUPPORT_WWHOBD == STD_ON)
    if (Dem_Dcm_SRec_CalculateSize_WwhObd(lEventId, &lSizeOfOBDFreezeFrame) == E_OK)                                             /* SBSW_DEM_POINTER_FORWARD_STACK */
#  else
    if (Dem_Dcm_SRec_CalculateSize_ObdII(lEventId, &lSizeOfOBDFreezeFrame) == E_OK)                                              /* SBSW_DEM_POINTER_FORWARD_STACK */
#  endif
    {
      lReturnValue = E_OK;
      lSizeOfFreezeFrame += lSizeOfOBDFreezeFrame;
    }
  }
# endif

 # if (DEM_CFG_SUPPORT_SRECS == STD_OFF && DEM_CFG_SUPPORT_GLOBAL_SRECS == STD_OFF)
  if (lReturnValue == E_OK)
# endif
  {
    /* At least one snapshot is configured for event */
    *SizeOfFreezeFrame = lSizeOfFreezeFrame;                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }
  return lReturnValue;
}
#endif

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )
/* ****************************************************************************
 % Dem_Dcm_SRec_CopyNextRecord_ObdII
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CopyNextRecord_ObdII(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
  if (Dem_Cfg_EventObdRelated(lEventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    lReturnValue = E_OK;
    if ( (Dem_DTCReadoutBuffer_GetOBDData_IsStored(ReadoutBufferId) == TRUE))
    {
      /* Event has a stored OBD freeze frame */
      if ((((uint32)DestinationBuffer->WriteIndex) + Dem_Cfg_GlobalObdIIFFUdsSize()) > DestinationBuffer->BufferSize)
      {
        /* supported record, but the buffer is not large enough for the data */
        lReturnValue = DEM_BUFFER_TOO_SMALL;
      }
      else
      {
        /* Read Freeze Frame */
        Dem_DataReportIF_BufferIndexType lBufferIdx;                                                                             /* PRQA S 0759 */ /* MD_MSR_Union */
        lBufferIdx.ReadoutBufferId = ReadoutBufferId;

        Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, 0x00U);                                                          /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
        Dem_DataReportIF_ObdIIFreezeFrameCopyUdsData(lBufferIdx,
                                                     DestinationBuffer,
                                                     DEM_DATAREPORTIF_SOURCE_OBDII_FF_READOUTBUFFER);                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */


        lReturnValue = E_OK;
      }
    } /* else FreezeFrame is not stored */
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON) && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_CopyNextRecord_WwhObd
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CopyNextRecord_WwhObd(
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Data_DestinationBufferPtrType, AUTOMATIC)  DestinationBuffer
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_DTCReadoutBuffer_GetEventId(ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);

  if (Dem_Cfg_EventObdRelated(lEventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    if (Dem_Cfg_EventWwhObdFFUdsSize(lEventId) > DestinationBuffer->BufferSize)
    { /* supported record, but the buffer is not large enough for all the data */
      lReturnValue = DEM_BUFFER_TOO_SMALL;
    }
    else
    {
      Dem_Cfg_MemoryIndexType lMemoryIndex;

      lMemoryIndex = Dem_Memory_FindIndex(lEventId);
      lReturnValue = E_OK;

      if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
      { /* process request if Freeze Frame is stored */
# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)                                                                             /* COV_DEM_UNSUPPORTED_FEATURE TX */
        if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(Dem_MemoryEntry_GetId(lMemoryIndex))) == FALSE)
# endif
        {
          Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;

          lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(
                                          ReadoutBufferId, DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT);
          Dem_Data_WriteDestinationBufferUint8(DestinationBuffer, 0x00u);                                                         /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
          Dem_DataReportIF_WWHOBDFreezeFrameCopyData(DestinationBuffer,                                                          /* SBSW_DEM_POINTER_DESTINATIONBUFFER_SOURCEBUFFER */
            (Dem_ConstSharedDataPtrType) Dem_MemoryEntry_GetWwhObdFreezeFrameDataPtr(lReadoutBufferMemoryEntryId),
            lEventId,
            lReadoutBufferMemoryEntryId);
        }
      }
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON) */

#if ( (DEM_CFG_SUPPORT_DCM == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII == STD_ON) \
   && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) )
/* ****************************************************************************
 % Dem_Dcm_SRec_CalculateSize_ObdII
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_ObdII(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  { /* scan the freeze frame memory for the requested DTC */
    uint8 lSelectedIndex;
    lSelectedIndex = Dem_Mem_FreezeFrameFindIndex(EventId);

    /* Check if FreezeFrame is available */
    if (lSelectedIndex != Dem_Cfg_GlobalObdIIFFCount())
    {
      *SizeOfFreezeFrame = Dem_Cfg_GlobalObdIIFFUdsSize();                                                                       /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    else
    { /* FreezeFrame is not stored */
      *SizeOfFreezeFrame = 0u;                                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
    lReturnValue = E_OK;
  }

  return lReturnValue;
}
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_OBDII == STD_ON)
           && (DEM_CFG_SUPPORT_OBDII_FREEZEFRAME_IN_SVC19 == STD_ON) */

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_CalculateSize_WwhObd
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_CalculateSize_WwhObd(
  CONST(Dem_EventIdType, AUTOMATIC)  EventId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lReturnValue;

  if (Dem_Cfg_EventObdRelated(EventId) == FALSE)
  {
    lReturnValue = DEM_NO_SUCH_ELEMENT;
  }
  else
  {
    Dem_Cfg_MemoryIndexType lMemoryIndex;

    lReturnValue = E_OK;
    lMemoryIndex = Dem_Memory_FindIndex(EventId);

    if (lMemoryIndex != DEM_MEM_INVALID_MEMORY_INDEX)
    { /* process request if Freeze Frame is stored */
# if (DEM_FEATURE_NEED_AGING_REALLOCATION == STD_ON)                                                                             /* COV_DEM_UNSUPPORTED_FEATURE TX */
      if (DEM_MEM_TEST_AGING_ONLY(Dem_MemoryEntry_GetState(Dem_MemoryEntry_GetId(lMemoryIndex))) == TRUE)
      {
        *SizeOfFreezeFrame = 0u;                                                                                                  /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
      else
# endif
      {
        *SizeOfFreezeFrame = Dem_Cfg_EventWwhObdFFUdsSize(EventId);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
      }
    }
    else
    {
      *SizeOfFreezeFrame = 0u;                                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    }
  }

  return lReturnValue;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if ((DEM_CFG_SUPPORT_DCM == STD_ON)\
    && (DEM_CFG_SUPPORT_ERECS == STD_ON)\
    && (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_ERec_CalculateSizeSingleERec_CombinedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(uint16, DEM_CODE)
Dem_Dcm_ERec_CalculateSizeSingleERec_CombinedDTC(
  CONST(uint8, AUTOMATIC)  ERecId,
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC)  ERecEntryIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Cfg_CombinedGroupIndexType, AUTOMATIC) CombinedGroupId
  )
{
  uint16 lSizeOfExtRec;
  Dem_Cfg_ExtendedDataRecordEventIterType lExtendedDataRecordEventIter;

  lSizeOfExtRec = 0u;

  switch (Dem_Cfg_ERecType(ERecEntryIndex))
  {
    case DEM_CFG_EREC_TYPE_GLOBAL:
    {
      for (Dem_Cfg_ExtendedDataRecordEventIterInit(&lExtendedDataRecordEventIter, CombinedGroupId, ERecId);                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_ExtendedDataRecordEventIterExists(&lExtendedDataRecordEventIter) == TRUE;                                     /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Cfg_ExtendedDataRecordEventIterNext(&lExtendedDataRecordEventIter))                                               /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        Dem_EventIdType lEventId;
        lEventId = Dem_Cfg_ExtendedDataRecordEventIterGet(&lExtendedDataRecordEventIter);                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
        if ((Dem_Cfg_EventAvailableByVariant(lEventId) == TRUE)
          && (Dem_EventInternalStatus_TestEventDisconnected(Dem_Event_GetInternalStatus(lEventId)) == FALSE))                    /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        { /* Add one byte for RecordId */
          lSizeOfExtRec += (uint16)(Dem_Cfg_DidSize(Dem_Cfg_ERecDid(ERecEntryIndex)) + 1u);
        }
      }
      break;
    }

    case DEM_CFG_EREC_TYPE_INTERNAL:
    {
      for (Dem_Cfg_ExtendedDataRecordEventIterInit(&lExtendedDataRecordEventIter, CombinedGroupId, ERecId);                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
        Dem_Cfg_ExtendedDataRecordEventIterExists(&lExtendedDataRecordEventIter) == TRUE;                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
        Dem_Cfg_ExtendedDataRecordEventIterNext(&lExtendedDataRecordEventIter))                                                  /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
        Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType lReadoutBufferDataIndex;
        Dem_EventIdType lEventId;

        lEventId = Dem_Cfg_ExtendedDataRecordEventIterGet(&lExtendedDataRecordEventIter);                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */

        lReadoutBufferDataIndex = Dem_DTCReadoutBuffer_GetEventDataIndex(ReadoutBufferId, lEventId);

        /* Only count size of internal extended data records if the event has a memory entry */
        if ((lReadoutBufferDataIndex != Dem_Cfg_SizeOfReadOutBufferData())
            && (Dem_Data_ERecAllDataElementsStored(Dem_Cfg_ERecDid(ERecEntryIndex), ReadoutBufferId,                             /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
                  lReadoutBufferDataIndex) == TRUE)
           )
        { /* Add one byte for RecordId */
          lSizeOfExtRec += (uint16)(Dem_Cfg_DidSize(Dem_Cfg_ERecDid(ERecEntryIndex)) + 1u);
        }
      }
      break;
    }

# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
    case DEM_CFG_EREC_TYPE_USER:
    {
      uint8 lUserERecStorageIndex;
      uint8 lNumOccupiedReadoutBufferSlots;
      Dem_DTCReadoutBuffer_ReadoutBufferDataIndexType lReadoutBufferDataIndex;

      lReadoutBufferDataIndex = DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT;
      lNumOccupiedReadoutBufferSlots = Dem_DTCReadoutBuffer_GetNumberOfOccupiedSlots(ReadoutBufferId);
      lUserERecStorageIndex = Dem_ExtendedEntry_CalculateUserERecStorageIndex(ERecId, CombinedGroupId);

      for ( /* Initialized to default slot */;
          lReadoutBufferDataIndex < lNumOccupiedReadoutBufferSlots;
          lReadoutBufferDataIndex++)
      {

        Dem_Cfg_MemoryEntryHandleType lReadoutBufferMemoryEntryId;

        lReadoutBufferMemoryEntryId = Dem_DTCReadoutBuffer_GetMemoryEntryId(ReadoutBufferId, lReadoutBufferDataIndex);

        if ((Dem_ExtendedEntry_GetUserERecStorageStatus(lUserERecStorageIndex, lReadoutBufferMemoryEntryId) == TRUE)
          && (Dem_Data_ERecAllDataElementsStored(Dem_Cfg_ERecDid(ERecEntryIndex), ReadoutBufferId, lReadoutBufferDataIndex) == TRUE)) /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        { /* Add one byte for RecordId */
          lSizeOfExtRec += (uint16)(Dem_Cfg_DidSize(Dem_Cfg_ERecDid(ERecEntryIndex)) + 1u);
        }
      }
      break;
    }
# endif

    default:                                                                                                                     /* PRQA S 2016 */ /* MD_MSR_EmptyClause */ 
      Dem_Internal_AssertAlways(DEM_E_INCONSISTENT_STATE);
      break;
  }

  return lSizeOfExtRec;
}                                                                                                                                /* PRQA S 6050 */ /* MD_MSR_STCAL */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_CalculateSize
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint16, DEM_CODE)
Dem_Dcm_ERec_CalculateSize(
  CONST(Dem_Cfg_ERecIndexType, AUTOMATIC) CfgERecIndex,
  CONST(Dem_DTCReadoutBuffer_HandleType, AUTOMATIC) ReadoutBufferId,
  CONST(Dem_Cfg_MemoryEntryHandleType, AUTOMATIC)  MemoryEntryId,
  CONST(uint8, AUTOMATIC)  ExtendedEntryIndex
  )
{
  uint16 lSizeOfExtRec;
  uint8 lERecType;
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(MemoryEntryId)                                                                                /* PRQA S 3112 */ /* MD_DEM_14.2 */
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(ExtendedEntryIndex)                                                                           /* PRQA S 3112 */ /* MD_DEM_14.2 */

  lSizeOfExtRec = 0u;
  lERecType = Dem_Cfg_ERecType(CfgERecIndex);

  if (lERecType != DEM_CFG_EREC_TYPE_GLOBAL)
  {
    /* Test if event has a memory entry */
    if (Dem_DTCReadoutBuffer_TestStoredDataAvailable(ReadoutBufferId) == TRUE)
    {
# if (DEM_CFG_SUPPORT_USER_ERECS == STD_ON)
      if (  (lERecType == DEM_CFG_EREC_TYPE_INTERNAL)
        /* Test if requested record is stored for event */
        || (Dem_ExtendedEntry_IteratorIsExtendedRecordStored(MemoryEntryId, ExtendedEntryIndex) == TRUE))                        /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
# endif
      {
        if (Dem_Data_ERecAllDataElementsStored(
              Dem_Cfg_ERecDid(CfgERecIndex),
              ReadoutBufferId,
              DEM_DTCREADOUTBUFFER_DATAINDEX_DEFAULT) == TRUE)
        {
          lSizeOfExtRec = (uint16)(Dem_Cfg_DidSize(Dem_Cfg_ERecDid(CfgERecIndex)) + 1u);
        } /* else lSizeOfExtRec is already set to 0 */
      } /* else lSizeOfExtRec is already set to 0 */
    } /* else lSizeOfExtRec is already set to 0 */
  }
  else
  { /* Currently statistic data is always available, add record id to data size */
    lSizeOfExtRec = (uint16)(Dem_Cfg_DidSize(Dem_Cfg_ERecDid(CfgERecIndex)) + 1u);
  }

  return lSizeOfExtRec;
}
#endif /* (DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_ERECS == STD_ON) */

/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ********************************************************************************************************************
 *  SUBCOMPONENT API FUNCTION DEFINITIONS
 *********************************************************************************************************************/
#define DEM_START_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*!
 * \addtogroup Dem_Dcm_Public
 * \{
 */

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_ReadNextRecord
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_ReadNextRecord(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                                                       /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
)
{
  Std_ReturnType lReturnValue;
  Dem_Data_DestinationBuffer lDestinationBuffer;

  Dem_Data_InitDestinationBuffer(&lDestinationBuffer, DestBuffer, *BufSize);                                                     /* SBSW_DEM_CALL_DESTINATIONBUFFER_INIT */

# if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
  if (Dem_DTCReadoutBuffer_TestCombinedEventSelected(Dem_ClientAccess_GetReadoutBuffer(ClientId)) == TRUE)
  {
    lReturnValue = Dem_Dcm_ERec_ReadNextRecord_CombinedEvent(ClientId, &lDestinationBuffer);                                     /* SBSW_DEM_POINTER_LOCAL_DESTINATIONBUFFER */
  }
  else
# endif
  {
    lReturnValue = Dem_Dcm_ERec_ReadNextRecord_NormalEvent(ClientId, &lDestinationBuffer);                                       /* SBSW_DEM_POINTER_LOCAL_DESTINATIONBUFFER */
  }

  if (lReturnValue == E_OK)
  {
    /* return number of written bytes */
    *BufSize = lDestinationBuffer.WriteIndex;                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_GetSize
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_ERec_GetSize(
  CONST(uint8, AUTOMATIC) ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  SizeOfExtendedDataRecord
  )
{
  Std_ReturnType lRetVal;

# if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
  if (Dem_DTCReadoutBuffer_TestCombinedEventSelected(Dem_ClientAccess_GetReadoutBuffer(ClientId)) == TRUE)
  {
    lRetVal = Dem_Dcm_ERec_GetSize_CombinedEvent(ClientId, SizeOfExtendedDataRecord);                                            /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
  else
# endif
  {
    lRetVal = Dem_Dcm_ERec_GetSize_NormalEvent(ClientId, SizeOfExtendedDataRecord);                                              /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }

  return lRetVal;
}
#endif


/* ****************************************************************************
 % Dem_Dcm_Init
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_Init(
  void
  )
{
#if (DEM_CFG_SUPPORT_DCM == STD_ON)
# if (DEM_CFG_SUPPORT_OBD_HIDE_OCCURRENCES == STD_ON)
  Dem_DTCReporting_SetObdHideOccurrences();
# endif
#endif
}

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_SelectFirstSource
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_SRec_SelectFirstSource(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC)  RecordNumber
  )
{
#if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
  if (Dem_DTCReadoutBuffer_TestCombinedEventSelected(Dem_ClientAccess_GetReadoutBuffer(ClientId)) == TRUE)
  {
    Dem_Dcm_SRec_SelectFirstSource_CombinedEvent(ClientId, RecordNumber);
  }
  else
#endif
  {
    Dem_Dcm_SRec_SelectFirstSource_NormalEvent(ClientId, RecordNumber);
  }
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ERec_SelectRecord
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(void, DEM_CODE)
Dem_Dcm_ERec_SelectRecord(
  CONST(uint8, AUTOMATIC) ClientId,
  CONST(uint8, AUTOMATIC)  RecordNumber
  )
{
  Dem_DTCReadoutBuffer_HandleType lReadoutBufferId;

  lReadoutBufferId = Dem_ClientAccess_GetReadoutBuffer(ClientId);
  Dem_DTCReadoutBuffer_SelectExtendedDataRecord(lReadoutBufferId, RecordNumber);
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_ReadNextRecord
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_ReadNextRecord(
  CONST(uint8, AUTOMATIC) ClientId,
  CONSTP2VAR(uint8, AUTOMATIC, DEM_APPL_DATA)  DestBuffer,                                                                       /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  CONSTP2VAR(uint16, AUTOMATIC, DEM_APPL_DATA)  BufSize                                                                          /* PRQA S 3673 */ /* MD_DEM_8.13_fp */
  )
{
  Std_ReturnType lReturnValue;
  Dem_Data_DestinationBuffer lDestinationBuffer;

  /* Initialize a DestinationBuffer Context. */
  Dem_Data_InitDestinationBuffer(&lDestinationBuffer, DestBuffer, *BufSize);                                                     /* SBSW_DEM_CALL_DESTINATIONBUFFER_INIT */

# if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
  if (Dem_DTCReadoutBuffer_TestCombinedEventSelected(Dem_ClientAccess_GetReadoutBuffer(ClientId)) == TRUE)
  {
    lReturnValue = Dem_Dcm_SRec_ReadNextRecord_CombinedDTC(ClientId, &lDestinationBuffer);                                       /* SBSW_DEM_POINTER_LOCAL_DESTINATIONBUFFER */
  }
  else
# endif
  {
    lReturnValue = Dem_Dcm_SRec_ReadNextRecord_NormalEvent(ClientId, &lDestinationBuffer);                                       /* SBSW_DEM_POINTER_LOCAL_DESTINATIONBUFFER */
  }

  if (lReturnValue == E_OK)
  {
    *BufSize = lDestinationBuffer.WriteIndex;                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_SRec_GetSize
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_SRec_GetSize(
  CONST(uint8, AUTOMATIC)  ClientId,
  CONSTP2VAR(uint16, AUTOMATIC, DEM_DCM_DATA)  SizeOfFreezeFrame
  )
{
  Std_ReturnType lRetVal;
# if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
  if (Dem_DTCReadoutBuffer_TestCombinedEventSelected(Dem_ClientAccess_GetReadoutBuffer(ClientId)) == TRUE)
  {
    lRetVal = Dem_Dcm_SRec_GetSize_CombinedEvent(ClientId, SizeOfFreezeFrame);                                                   /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }
  else
# endif
  {
    lRetVal = Dem_Dcm_SRec_GetSize_NormalEvent(ClientId, SizeOfFreezeFrame);                                                     /* SBSW_DEM_POINTER_FORWARD_ARGUMENT */
  }

  return lRetVal;
}
#endif

#if (DEM_FEATURE_NEED_OBD == STD_ON) && (DEM_CFG_SUPPORT_PID01 == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_ReadDataOfPID01
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL FUNC(void, DEM_CODE)
Dem_Dcm_ReadDataOfPID01(
  CONSTP2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  PID01value,
  CONST(uint8, AUTOMATIC) BufferSize
  )
{
  DEM_IGNORE_UNUSED_CONST_ARGUMENT(BufferSize)                                                                                   /* PRQA S 3112 */ /* MD_DEM_14.2 */
# if (DEM_DEV_RUNTIME_CHECKS == STD_ON)
  if (BufferSize < 4u)
  {
    Dem_Error_RunTimeCheckFailed(DEM_DCM_IMPLEMENTATION_FILENAME, __LINE__);                                                     /* SBSW_DEM_POINTER_RUNTIME_CHECK */
  }
  else
# endif
  {
    /*If major monitors is supported */
# if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
    uint32 lPid01;

    /* Set all groups to not supported and not completed (not supported = 0, supported = 1, completed/na = 0, not completed = 1u) */
    lPid01 = 0x007000FFUL;

    /* If Event Availabilty is supported the configuration contains only engine type,
       otherwise supported state of readines groups is also provided */
    lPid01 |= Dem_Cfg_GlobalPid01SupportedMask();
# endif
    /* If OBDII is supported */
# if (DEM_CFG_SUPPORT_OBDII == STD_ON)
    {
      /* If feature reset Confimred DTC on overflow or major monitors and event availablity is supported */
#  if ((DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_OFF) && \
      ((DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_OFF) || (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_OFF)))
      Dem_Memory_AllocMemEntriesIterType lStoredEventsIter;
#  endif
#   if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
      Dem_Cfg_ProcessedCombinedDTCGroupType lProcessedCombinedDTCGroups;
#endif

      Dem_EventIdType lConfirmedEvents;
      Dem_EventIdType lEventId;
      uint8 lGlobalMilState;
#   if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
      Dem_DTC_InitCombinedGroupProcessed(lProcessedCombinedDTCGroups);                                                           /* SBSW_DEM_POINTER_FORWARD_STACK */
#endif
      lConfirmedEvents = 0u;

#  if ((DEM_CFG_PROCESS_CDTC_ALL_DTC == STD_ON) || \
      ((DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON) && (DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)))
      /* Scan for events in confirmed state */
      for (lEventId = Dem_Cfg_GlobalPrimaryFirst();
        lEventId <= Dem_Cfg_GlobalPrimaryLast();
        lEventId++)
      {
#   if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON && DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
        uint8 lReadinessGroup;
        lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
        /* If event is available and assigned to a valid readiness group */
        if ( (lReadinessGroup != DEM_CFG_READINESS_NONE)
          && (Dem_Event_TestEventUnavailable(lEventId) == FALSE))                                                                /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        {
          /* Set readiness group to supported*/
          Dem_Util_SetReadinessGroupSupported(TRUE, lReadinessGroup, &lPid01);                                                   /* SBSW_DEM_POINTER_FORWARD_STACK */
        }
#   endif
#   if (DEM_CFG_SUPPORT_TYPE1_COMBINATION == STD_ON)
        if (lEventId != Dem_Cfg_GetMasterEvent(lEventId))
        { /* Don't match dependent combined events, only the group event */
          continue;                                                                                                              /* PRQA S 0770 */ /* MD_DEM_14.5 */
        }
#   endif
#  else
      /* Only the stored events are in confirmed state -> iterate over all stored events and count
      the number of OBD releated events */
      for (Dem_Memory_AllocMemEntriesChrono_IterInit(DEM_CFG_MEMORYID_PRIMARY, &lStoredEventsIter);                              /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Memory_AllocMemEntriesChrono_IterExists(&lStoredEventsIter) == TRUE;                                              /* SBSW_DEM_CALL_ITERATOR_POINTER */
           Dem_Memory_AllocMemEntriesChrono_IterNext(&lStoredEventsIter))                                                        /* SBSW_DEM_CALL_ITERATOR_POINTER */
      {
         /* Get EventId for current index */
         lEventId = Dem_MemoryEntry_GetEventId(
           Dem_MemoryEntry_GetId(Dem_Memory_AllocMemEntriesChrono_IterGetMemoryIndex(&lStoredEventsIter)));                      /* SBSW_DEM_CALL_ITERATOR_POINTER */
         /* verify that a valid EventId was returned */
         if (Dem_Event_TestValidHandle(lEventId) == TRUE)
#  endif
         { /* count Event if it is OBD related and confirmed bit is qualified */
           if ((Dem_Cfg_EventObdRelated(lEventId) == TRUE)
#   if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
             && (Dem_DTC_TestCombinedGroupProcessed(Dem_Cfg_EventCombinedGroup(lEventId), lProcessedCombinedDTCGroups) == FALSE) /* PRQA S 3415 */ /* MD_DEM_13.5_cf */ /* SBSW_DEM_POINTER_FORWARD_STACK */
#endif
             )
           {
             uint8 lDtcStatus;
             lDtcStatus = Dem_DTC_GenerateExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));
             if (Dem_UDSStatus_Test_CDTC(lDtcStatus) == TRUE)
             {
               lConfirmedEvents++;
             }
#   if (DEM_CFG_SUPPORT_TYPE2_COMBINATION == STD_ON)
             Dem_DTC_SetCombinedGroupProcessed(Dem_Cfg_EventCombinedGroup(lEventId), lProcessedCombinedDTCGroups);               /* SBSW_DEM_POINTER_FORWARD_STACK */
#endif
           }
         }
       }

      /* set max value if count exceeds 127 */
      if (lConfirmedEvents > 0x7fU)
      {
        lConfirmedEvents = 0x7fU;
      }

      if (Dem_Indicator_TestMilReportedActive() == TRUE)
      {
        lGlobalMilState = 0x80U;
      }
      else
      {
        lGlobalMilState = 0x00U;
      }

      /* MIL status and number of OBD relevant confirmed events */
      PID01value[0] = (uint8)((lGlobalMilState | (uint8)lConfirmedEvents));                                                      /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
    }
# endif
    /* Otherwise if WWHOBD is supported */
# if (DEM_CFG_SUPPORT_WWHOBD == STD_ON)
    /* If major monitors and event availablity is supported */
#  if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON && DEM_CFG_SUPPORT_EVENTAVAILABLE == STD_ON)
    {
      Dem_EventIdType lEventId;
      for (lEventId = Dem_Cfg_GlobalPrimaryFirst();
        lEventId <= Dem_Cfg_GlobalPrimaryLast();
        lEventId++)
      {
        uint8 lReadinessGroup = Dem_Cfg_EventReadinessGroup(lEventId);
        /* If event is assigned to readiness group and available */
        if ( (lReadinessGroup != DEM_CFG_READINESS_NONE)
          && (Dem_Event_TestEventUnavailable(lEventId) == FALSE)                                                                 /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
          )
        {
          /* Set readiness group to supported*/
          Dem_Util_SetReadinessGroupSupported(TRUE, Dem_Cfg_EventReadinessGroup(lEventId), &lPid01);                             /* SBSW_DEM_POINTER_FORWARD_STACK */
        }
      }
    }
#  endif
    PID01value[0] = 0x00u;                                                                                                        /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
# endif
     /* If major monitors is supported */
# if (DEM_CFG_SUPPORT_MAJOR_MONITORS == STD_ON)
    /* Get completed state of readiness groups and set value of remaining bytes in Pid01 (completed = 0, not completed = 1u) */
    lPid01 &= Dem_Mem_GetPid01CompletedMask();
    Dem_Data_SetStaticallyCalculatedReadinessStatus(&lPid01, DEM_DATA_PIDCONTEXT_PID01);                                         /* SBSW_DEM_POINTER_FORWARD_STACK */

    PID01value[1] = Dem_GetHiLoByte(lPid01);                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
    PID01value[2] = Dem_GetLoHiByte(lPid01);                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
    PID01value[3] = Dem_GetLoLoByte(lPid01);                                                                                     /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
# else
    /* Otherwise set remaining bytes in Pid01 to static values (Byte B = 0x04, Byte C = 0x00, Byte D = 0x00) */
    PID01value[1] = 0x04u; /* Comprehensive component monitoring supported and ready */                                           /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
    PID01value[2] = 0x00u; /* not supported */                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
    PID01value[3] = 0x00u; /* not supported */                                                                                    /* SBSW_DEM_POINTER_WRITE_ARGUMENT_BUFFER */
# endif
  }
}                                                                                                                                /* PRQA S 6010, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCAL, MD_MSR_STPTH */
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_GetStatusOfSelectedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetStatusOfSelectedDTC(
  uint8  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCStatus
  )
{
  Std_ReturnType lReturnValue;
  uint8 lMemoryId;

  lMemoryId = Dem_ClientAccess_GetSelectedMemoryId(ClientId);
  switch (lMemoryId)
  {
  case DEM_CFG_MEMORYID_PERMANENT:
    lReturnValue = DEM_NO_SUCH_ELEMENT;
    break;
  case DEM_CFG_MEMORYID_PRIMARY:
  case DEM_CFG_MEMORYID_SECONDARY:
  {
    Dem_EventIdType lEventId;

    lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

    if (lEventId != DEM_EVENT_INVALID)
    {
      uint8 lEventStatus;
      if (Dem_DTC_TestSuppressionOnDtcRetrieval(lEventId) == TRUE)
      {
        lReturnValue = DEM_WRONG_DTC;
      }
      else
      {
        lEventStatus = Dem_DTC_GenerateExternalOnlyStatus(lEventId, Dem_DTC_GetDTCStatus(lEventId));

        /* apply status availability mask */
        *DTCStatus = (uint8)(lEventStatus & Dem_Cfg_GlobalStatusMask());                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = E_OK;
      }
    }
    else
    {
      lReturnValue = E_NOT_OK;
    }
  }
    break;

  default:
    lReturnValue = E_NOT_OK;
    break;
  }
  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_GetSeverityOfSelectedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetSeverityOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(Dem_DTCSeverityType, AUTOMATIC, DEM_DCM_DATA)  DTCSeverity
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

  if (lEventId != DEM_EVENT_INVALID)
  {
    if (Dem_DTC_TestSuppressionOnDtcRetrieval(lEventId) == TRUE)
    {
      lReturnValue = DEM_WRONG_DTC;
    }
    else
    {
# if (DEM_CFG_SUPPORT_OBD_HIDE_OCCURRENCES == STD_ON)
      if ( (Dem_DTCReporting_TestObdHideOccurrences() == TRUE)
        && (Dem_Cfg_EventSignificance(lEventId) == DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)                                        /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        && (Dem_Cfg_EventObdRelated(lEventId) == TRUE) )                                                                         /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
      { /* Special case - skip Dependent OBD DTCs */
        lReturnValue = DEM_WRONG_DTC;
      }
      else
# endif
      {
        *DTCSeverity = Dem_Cfg_EventSeverity(lEventId);                                                                          /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = E_OK;
      }
    }
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}
#endif

#if (DEM_CFG_SUPPORT_DCM == STD_ON)
/* ****************************************************************************
 % Dem_Dcm_GetFunctionalUnitOfSelectedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetFunctionalUnitOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(uint8, AUTOMATIC, DEM_DCM_DATA)  DTCFunctionalUnit
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

  if (lEventId != DEM_EVENT_INVALID)
  {
    if (Dem_DTC_TestSuppressionOnDtcRetrieval(lEventId) == TRUE)
    {
      lReturnValue = DEM_WRONG_DTC;
    }
    else
    {
# if (DEM_CFG_SUPPORT_OBD_HIDE_OCCURRENCES == STD_ON)
      if ( (Dem_DTCReporting_TestObdHideOccurrences() == TRUE)
        && (Dem_Cfg_EventSignificance(lEventId) == DEM_CFG_EVENT_SIGNIFICANCE_OCCURRENCE)                                        /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
        && (Dem_Cfg_EventObdRelated(lEventId) == TRUE) )                                                                         /* PRQA S 3415 */ /* MD_DEM_13.5_cf */
      { /* Special case - skip Dependent OBD DTCs */
        lReturnValue = DEM_WRONG_DTC;
      }
      else
# endif
      {
        *DTCFunctionalUnit = Dem_Cfg_EventFunctionalUnit(lEventId);                                                              /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
        lReturnValue = E_OK;
      }
    }
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}
#endif

/* ****************************************************************************
 % Dem_Dcm_GetEventIdOfSelectedDTC
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(Std_ReturnType, DEM_CODE)
Dem_Dcm_GetEventIdOfSelectedDTC(
  CONST(uint8, AUTOMATIC)  ClientId,
  P2VAR(Dem_EventIdType, AUTOMATIC, DEM_APPL_DATA)  EventId
  )
{
  Std_ReturnType lReturnValue;
  Dem_EventIdType lEventId;

  lEventId = Dem_ClientAccess_GetSelectedEventId(ClientId);

  if (lEventId != DEM_EVENT_INVALID)
  {
    *EventId = lEventId;                                                                                                         /* SBSW_DEM_POINTER_WRITE_ARGUMENT */
    lReturnValue = E_OK;
  }
  else
  {
    lReturnValue = E_NOT_OK;
  }

  return lReturnValue;
}

#if ((DEM_CFG_SUPPORT_DCM == STD_ON) && (DEM_CFG_SUPPORT_WWHOBD == STD_ON) && (DEM_CFG_SUPPORT_PID91 == STD_ON))
/* ****************************************************************************
 % Dem_Dcm_TranslateActivationMode
 *****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
DEM_LOCAL_INLINE FUNC(uint8, DEM_CODE)
Dem_Dcm_TranslateActivationMode(
  CONST(Dem_IndicatorStatusType, AUTOMATIC)  ActivationMode
  )
{
  uint8 lReturnValue;

  switch (ActivationMode)
  {
  case DEM_INDICATOR_CONTINUOUS:
    lReturnValue = 0x03U;
    break;
  case DEM_INDICATOR_SHORT:
    lReturnValue = 0x02U;
    break;
  case DEM_INDICATOR_ON_DEMAND:
    lReturnValue = 0x01U;
    break;
  case DEM_INDICATOR_OFF:
    lReturnValue = 0x00U;
    break;
  default:
    Dem_Error_ReportError(DEM_INTERNAL_APIID, DEM_E_INCONSISTENT_STATE);
    lReturnValue = 0x00U;
    break;
  }
  return lReturnValue;
}
#endif
/*!
 * \}
 */
#define DEM_STOP_SEC_CODE
#include "MemMap.h"                                                                                                              /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* DEM_DCM_IMPLEMENTATION_H */

/*!
 * \}
 */
/* ********************************************************************************************************************
 *  END OF FILE: Dem_Dcm_Implementation.h
 *********************************************************************************************************************/
