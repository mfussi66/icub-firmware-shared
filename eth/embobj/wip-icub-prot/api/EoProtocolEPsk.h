/*
 * Copyright (C) 2013 iCub Facility - Istituto Italiano di Tecnologia
 * Author:  Marco Accame
 * email:   marco.accame@iit.it
 * website: www.robotcub.org
 * Permission is granted to copy, distribute, and/or modify this program
 * under the terms of the GNU General Public License, version 2 or any
 * later version published by the Free Software Foundation.
 *
 * A copy of the license can be found at
 * http://www.robotcub.org/icub/license/gpl.txt
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details
*/

// - include guard ----------------------------------------------------------------------------------------------------
#ifndef _EOPROTOCOLEPSK_H_
#define _EOPROTOCOLEPSK_H_

#ifdef __cplusplus
extern "C" {
#endif


/** @file       EoProtocolEPsk.h
    @brief      This header file gives the ...
    @author     marco.accame@iit.it
    @date       06/05/2013
**/

/** @defgroup eo_protocol_ep_sk Protocol for skin endpoint 
    Ivreververv e
    
    @{        
 **/



// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"
#include "EoProtocolCommon.h"
#include "EoProtocolEP.h"
#include "EoSkin.h"
#include "EOnv.h"




// - public #define  --------------------------------------------------------------------------------------------------
// empty-section


// - declaration of public user-defined types ------------------------------------------------------------------------- 


/** @typedef    typedef enum eOprot_endpoint_skin_t;
    @brief      It contains all the endpoints used for skin. 
 **/
typedef enum
{
    eoprot_ep_sk_leftlowerarm       = eoprot_endpoint_sk_leftlowerarm,
    eoprot_ep_sk_rightlowerarm      = eoprot_endpoint_sk_rightlowerarm
} eOprot_endpoint_skin_t;


enum { eoprot_endpoints_skin_numberof = 2 };


/** @typedef    typedef eOsk_entity_t eOprotEntityEPsk_t
    @brief      It contains the entities in endpoint skin: skin and mais
 **/
typedef eOsk_entity_t eOprotEntityEPsk_t;

enum { eoprot_ep_sk_entities_numberof = eosk_entities_numberof };


// - definition of the skin: number of them in each endpoint, tag and funtyp values

typedef enum
{   
    eoprot_ep_sk_skins_numberof_leftlowerarm          = 1,
    eoprot_ep_sk_skins_numberof_rightlowerarm         = 1
} eOprot_ep_sk_skins_numberof_t;

  

/** @typedef    typedef enum eOprot_ep_sk_skin_tag_t
    @brief      It contains the tags for all variables in the skin endpoints.
                See definition of eOsk_skin_t (and its fields) in file EoSkin.h for explanation of the variables.
 **/
typedef enum
{
    eoprot_ep_sk_skin_tag_config__sigmode                   = 0,
    eoprot_ep_sk_skin_tag_status__arrayof10canframes        = 1
} eOprot_ep_sk_skin_tag_t;

enum { eoprot_ep_sk_skin_tags_numberof = 2 };  // it MUST be equal to the number of tags. 


/** @typedef    typedef enum eOprot_ep_sk_skin_funtyp_t
    @brief      It contains the function and type for all the network variables. There must be a one-to-one
                correspondence to the values in eOprot_ep_sk_skin_tag_t.
 **/
typedef enum
{
    eoprot_ep_sk_skin_funtyp_config__sigmode                = EO_nv_FUNTYP(eo_nv_FUN_cfg, eo_nv_TYP_b08),
    eoprot_ep_sk_skin_funtyp_status__arrayof10canframes     = EO_nv_FUNTYP(eo_nv_FUN_inp, eo_nv_TYP_arr)
} eOprot_ep_sk_skin_funtyp_t; 

enum { eoprot_ep_sk_skin_funtyps_numberof = 2 };  // it MUST be equal to the number of tags. 


// - structures implementing the endpoints
  

/** @typedef    typedef struct eOprot_ep_sk_lowerarm_t;
    @brief      contains all the variables in the endpoint skin
 **/
typedef struct                  // 176+0 = 176              
{
    eOsk_skin_t                 skin;
} eOprot_ep_sk_lowerarm_t;      EO_VERIFYsizeof(eOprot_ep_sk_lowerarm_t, 176);


typedef eOprot_ep_sk_lowerarm_t eOprot_ep_sk_leftlowerarm_t;
typedef eOprot_ep_sk_lowerarm_t eOprot_ep_sk_rightlowerarm_t;


// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------
// empty-section

// - these three are used to configure the endpoint into a EOnvsCfg object
// empty-section


// - declaration of extern public functions ---------------------------------------------------------------------------


/** @fn         extern uint16_t eoprot_ep_sk_variable_numberof_Get(eOprotEP_t ep)
    @brief      This function retrieves the number of variables given the endpoint @e ep
    @param      ep              the endpoint
    @return     the number of variables.
  */
extern uint16_t eoprot_ep_sk_variables_numberof_Get(eOprotEP_t ep);


/** @fn         extern uint16_t eoprot_ep_sk_variable_progressivenumber_Get(eOprotEP_t ep)
    @brief      This function retrieves the progressive number of a variable given the endpoint @e ep and the @e id
    @param      ep              the endpoint
    @return     the progressive number or EOK_uint16dummy if invalid .
  */
extern uint16_t eoprot_ep_sk_variable_progressivenumber_Get(eOprotEP_t ep, eOprotID_t id);


/** @fn         extern uint16_t eoprot_ep_sk_skins_numberof_Get(eOprotEP_t ep)
    @brief      This function retrieves the number of comms entities given the endpoint @e ep
    @param      ep              the endpoint
    @return     the number of comms.
  */
extern uint16_t eoprot_ep_sk_skins_numberof_Get(eOprotEP_t ep);


extern uint16_t eoprot_ep_sk_ram_sizeof_Get(eOprotEP_t ep);

extern uint16_t eoprot_ep_sk_variable_ram_sizeof_Get(eOprotEP_t ep, eOprotID_t id);

extern void* eoprot_ep_sk_variable_ram_Extract(void* epram, eOprotEP_t ep, eOprotID_t id);

extern void* eoprot_ep_sk_variable_rom_Get(eOprotEP_t ep, eOprotID_t id);

extern const eOsk_skin_t* eoprot_ep_sk_skin_default_Get(void);




/** @}            
    end of group eo_protocol_ep_sk  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 
 
#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------

