/*
 * Copyright (C) 2014 iCub Facility - Istituto Italiano di Tecnologia
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
#ifndef _EOERROR_H_
#define _EOERROR_H_

#ifdef __cplusplus
extern "C" {
#endif


/** @file       EoError.h
    @brief      This header file contains the error codes and error strings used by the Ethernet boards in iCub. 
    @author     marco.accame@iit.it
    @date       Nov 10 2014
**/

/** @defgroup eo_EoErrors Error codes and associated strings in ETH protocol for iCub 
    This file contains error codes and error strings which are used in the iCub ETH protocol for iCub.
    Its use is in eOmn_info_properties_t::code.
    
    @{        
 **/



// - external dependencies --------------------------------------------------------------------------------------------

#include "EoCommon.h"


// - public #define  --------------------------------------------------------------------------------------------------

// these macros describe the partition of the 32 bits used by the errorcode into a category and a number.
// so far we use 8 bits to define a category (e.g., board system) and 24 bits to define a number (e.g., missing memory).
 
#define EOERROR_CATEG_MASK      0xFF000000
#define EOERROR_VALUE_MASK      0x00FFFFFF
#define EOERROR_CATEG_SHIFT     24


#define EOERROR_CATEGORY_DUMMY  EOK_uint08dummy
#define EOERROR_VALUE_DUMMY     EOK_uint32dummy
#define EOERROR_CODE_DUMMY      EOK_uint32dummy

// this macro-function should be used for constant initialisation, for all other cases use: eoerror_code_get() function
#define EOERRORCODE(cat, val)   ((val) & EOERROR_VALUE_MASK) | (((cat) << EOERROR_CATEG_SHIFT) & EOERROR_CATEG_MASK)


// - declaration of public user-defined types ------------------------------------------------------------------------- 

/** @typedef    typedef uint32_t eOerror_code_t
    @brief      generic type used to specify an error code. it is formed of 32 bits, of which the mbb is the category, 
                and the others are a value inside that category. We represent the bits of the category with type eOerror_category_t,
                whereas we represent the bits of the value with the enum type specific of the category.
                As an example, if the category is eoerror_category_EthBoardSystem, then the enum type for the values is eOerror_value_SYS_t
                
                We also use a generic type eOerror_value_t for generic function parameter or return value.
 **/
typedef uint32_t eOerror_code_t;


/** @typedef    typedef enum eOerror_category_t
    @brief      it contains the category in the msb in eOerror_code_t. if you want to add a new category: use CamelCaseConvention for the 
                enumerative label, add it just before eoerror_category_dummy.        
 **/
typedef enum
{
    eoerror_category_System                 = 0,    /**< errors generated by the system used inside the Ethernet board: EMS4, MC4plus, ... KEEP IT ZERO */
    eoerror_category_HardWare               = 1,    /**< errors related to hardware */
    eoerror_category_MotionControl          = 2,    /**< errors generated by motion control activity */
    eoerror_category_Skin                   = 3,    /**< errors generated by skin activity */
    eoerror_category_Debug                  = 4,    /**< errors generated specifically by debug activity */
    eoerror_category_Config                 = 5,    /**< errors generated specifically by application configuration activity */
    eoerror_category_ETHmonitor             = 6,    /**< errors generated specifically by the ETH monitor */
    eoerror_category_InertialSensor         = 7,
    eoerror_category_AnalogSensor           = 8,
    // add a new category in here. remember to increment eoerror_category_numberof 
    eoerror_category_dummy                   = EOERROR_CATEGORY_DUMMY   /**< used to express a dummy category. dont count it for eoerror_category_numberof */
} eOerror_category_t;

enum { eoerror_category_numberof = 9 };


/** @typedef    typedef uint32_t eOerror_value_t
    @brief      generic value for use as a function parameter. For usage, you must prefer the enumerative type relevant to the category.         
 **/
typedef uint32_t eOerror_value_t;


/** @typedef    typedef enum eOerror_value_SYS_t
    @brief      it contains the values of the eoerror_category_System category. In case you need a new value: add it
                in consecutive mode without holes and increment eoerror_value_SYS_numberof. In case you need to remove a value, dont
                remove the number but simply rename it: that will help detecting old boards sending pairs {category, value} not supported yet.  
 **/
typedef enum
{
    eoerror_value_SYS_unspecified                           = 0,
    eoerror_value_SYS_tobedecided                           = 1,
    eoerror_value_SYS_memory_zerorequested                  = 2,
    eoerror_value_SYS_memory_notinitialised                 = 3,
    eoerror_value_SYS_memory_missing                        = 4,
    eoerror_value_SYS_mutex_timeout                         = 5,
    eoerror_value_SYS_wrongparam                            = 6,
    eoerror_value_SYS_wrongusage                            = 7,
    eoerror_value_SYS_runtimeerror                          = 8,
    eoerror_value_SYS_runninghappily                        = 9,
    eoerror_value_SYS_runninginfatalerrorstate              = 10,
    eoerror_value_SYS_ctrloop_execoverflowRX                = 11,
    eoerror_value_SYS_ctrloop_execoverflowDO                = 12,
    eoerror_value_SYS_ctrloop_execoverflowTX                = 13,
    eoerror_value_SYS_udptxfailure                          = 14,
    eoerror_value_SYS_ropparsingerror                       = 15,
    eoerror_value_SYS_halerror                              = 16,
    eoerror_value_SYS_osalerror                             = 17,
    eoerror_value_SYS_ipalerror                             = 18,
    eoerror_value_SYS_dispatcherfifooverflow                = 19,
    eoerror_value_SYS_configurator_udptxfailure             = 20,
    eoerror_value_SYS_runner_udptxfailure                   = 21,
    eoerror_value_SYS_runner_transceivererror               = 22,
    eoerror_value_SYS_canservices_rxfifooverflow            = 23,
    eoerror_value_SYS_canservices_txfifooverflow            = 24,
    eoerror_value_SYS_canservices_txbusfailure              = 25,
    eoerror_value_SYS_canservices_formingfailure            = 26,
    eoerror_value_SYS_canservices_parsingfailure            = 27,
    eoerror_value_SYS_canservices_txfifoputisok             = 28,
    eoerror_value_SYS_canservices_genericerror              = 29,
	eoerror_value_SYS_ctrloop_rxphaseaverage      	        = 30,
	eoerror_value_SYS_ctrloop_dophaseaverage      	        = 31,
	eoerror_value_SYS_ctrloop_txphaseaverage      	        = 32,
    eoerror_value_SYS_ctrloop_rxphasemax      	            = 33,
	eoerror_value_SYS_ctrloop_dophasemax      	            = 34,
	eoerror_value_SYS_ctrloop_txphasemax      	            = 35,
    eoerror_value_SYS_ctrloop_rxphasemin      	            = 36,
	eoerror_value_SYS_ctrloop_dophasemin      	            = 37,
	eoerror_value_SYS_ctrloop_txphasemin      	            = 38,
    eoerror_value_SYS_proxy_forward_ok                      = 39,
    eoerror_value_SYS_proxy_forward_fails                   = 40,
    eoerror_value_SYS_proxy_forward_callback_fails          = 41,
    eoerror_value_SYS_proxy_reply_ok                        = 42,
    eoerror_value_SYS_proxy_reply_fails                     = 43,
    eoerror_value_SYS_proxy_ropdes_notfound                 = 44,
    eoerror_value_SYS_canservices_canprint                  = 45,
    eoerror_value_SYS_canservices_rxmaisbug                 = 46,
    eoerror_value_SYS_canservices_rxfromwrongboard          = 47,
    eoerror_value_SYS_transceiver_rxseqnumber_error         = 48,
    eoerror_value_SYS_canservices_boards_missing            = 49,
    eoerror_value_SYS_canservices_boards_searched           = 50,
    eoerror_value_SYS_canservices_boards_found              = 51,
    eoerror_value_SYS_transceiver_rxseqnumber_restarted     = 52,
    eoerror_value_SYS_canservices_board_detected            = 53,
    eoerror_value_SYS_canservices_board_wrongprotversion    = 54,
    eoerror_value_SYS_canservices_board_notfound            = 55,
    eoerror_value_SYS_transceiver_rxinvalidframe_error      = 56,
    eoerror_value_SYS_canservices_boards_lostcontact        = 57,
    eoerror_value_SYS_canservices_boards_retrievedcontact   = 58,
    eoerror_value_SYS_bootstrapping                         = 59
} eOerror_value_SYS_t;

enum { eoerror_value_SYS_numberof = 60 };


/** @typedef    typedef enum eOerror_value_HW_t
    @brief      it contains the values of the eoerror_category_HardWare category. In case you need a new value: add it
                in consecutive mode without holes and increment eoerror_value_HW_numberof. In case you need to remove a value, dont
                remove the number but simply rename it: that will help detecting old boards sending pairs {category, value} not supported yet.  
 **/
typedef enum
{
    eoerror_value_HW_first             = 0,
    eoerror_value_HW_second            = 1,
    eoerror_value_HW_strain_saturation = 2
} eOerror_value_HW_t;

enum { eoerror_value_HW_numberof = 3 };



/** @typedef    typedef enum eOerror_value_MC_t
    @brief      it contains the values of the eoerror_category_MotionControl category. In case you need a new value: add it
                in consecutive mode without holes and increment eoerror_value_MC_numberof. In case you need to remove a value, dont
                remove the number but simply rename it: that will help detecting old boards sending pairs {category, value} not supported yet.  
 **/
typedef enum
{
    eoerror_value_MC_motor_external_fault           = 0,
    eoerror_value_MC_motor_overcurrent              = 1,
    eoerror_value_MC_motor_i2t_limit                = 2,
    eoerror_value_MC_motor_hallsensors              = 3,
    eoerror_value_MC_motor_can_invalid_prot         = 4,
    eoerror_value_MC_motor_can_generic              = 5,
    eoerror_value_MC_motor_can_no_answer            = 6,
    eoerror_value_MC_axis_torque_sens               = 7,
    eoerror_value_MC_aea_abs_enc_invalid            = 8,
    eoerror_value_MC_aea_abs_enc_timeout            = 9,
    eoerror_value_MC_aea_abs_enc_spikes             = 10,
    
    eoerror_value_MC_motor_qencoder_dirty           = 11,
    eoerror_value_MC_motor_qencoder_index           = 12,
    eoerror_value_MC_motor_qencoder_phase           = 13,
    
    eoerror_value_MC_generic_error                  = 14,
    eoerror_value_MC_motor_wrong_state              = 15,
    
    eoerror_value_MC_joint_hard_limit               = 16,
    eoerror_value_MC_motor_qencoder_phase_disappeared   = 17
} eOerror_value_MC_t;

enum { eoerror_value_MC_numberof = 18 };



/** @typedef    typedef enum eOerror_value_SK_t
    @brief      it contains the values of the eoerror_category_Skin category. In case you need a new value: add it
                in consecutive mode without holes and increment eoerror_value_SK_numberof. In case you need to remove a value, dont
                remove the number but simply rename it: that will help detecting old boards sending pairs {category, value} not supported yet.  
 **/
typedef enum
{
    eoerror_value_SK_unspecified                    = 0,
    eoerror_value_SK_arrayofcandataoverflow         = 1,
    eoerror_value_SK_onoroff                        = 2,
    eoerror_value_SK_unexpecteddata                 = 3,
    eoerror_value_SK_obsoletecommand                = 4
} eOerror_value_SK_t;

enum { eoerror_value_SK_numberof = 5 };



/** @typedef    typedef enum eOerror_value_DEB_t
    @brief      it contains the values of the eoerror_category_Debug category.
 **/
typedef enum
{
    eoerror_value_DEB_tag00         = 0,
    eoerror_value_DEB_tag01         = 1,
    eoerror_value_DEB_tag02         = 2,
    eoerror_value_DEB_tag03         = 3,
    eoerror_value_DEB_tag04         = 4,
    eoerror_value_DEB_tag05         = 5,
    eoerror_value_DEB_tag06         = 6,
    eoerror_value_DEB_tag07         = 7,
    eoerror_value_DEB_hwfault1      = 8,
    eoerror_value_DEB_hwfault2      = 9,
    eoerror_value_DEB_hwfault3      = 10
} eOerror_value_DEB_t;

enum { eoerror_value_DEB_numberof = 11 };


/** @typedef    typedef enum eOerror_value_CFG_t
    @brief      it contains the values of the eoerror_category_Config category. 
 **/
typedef enum
{
    eoerror_value_CFG_candiscovery_started              = 0,
    eoerror_value_CFG_candiscovery_ok                   = 1,
    eoerror_value_CFG_candiscovery_detectedboard        = 2,
    eoerror_value_CFG_candiscovery_boardsmissing        = 3,
    eoerror_value_CFG_candiscovery_boardsinvalid        = 4,

    
    eoerror_value_CFG_skin_ok                           = 5,
    eoerror_value_CFG_skin_failed_toomanyboards         = 6,
    eoerror_value_CFG_skin_failed_candiscovery          = 7,
       
    eoerror_value_CFG_strain_ok                         = 8,
    eoerror_value_CFG_strain_failed_candiscovery        = 9,

    eoerror_value_CFG_mais_ok                           = 10,
    eoerror_value_CFG_mais_failed_candiscovery          = 11,
    eoerror_value_CFG_mais_failed_verify_because_active = 12,
       
    eoerror_value_CFG_mc_foc_ok                         = 13,
    eoerror_value_CFG_mc_foc_failed_candiscovery_of_foc = 14,
    eoerror_value_CFG_mc_foc_failed_encoders_verify     = 15,
        
    eoerror_value_CFG_mc_mc4_ok                         = 16,
    eoerror_value_CFG_mc_mc4_failed_candiscovery_of_mc4 = 17,
    eoerror_value_CFG_mc_mc4_failed_mais_verify         = 18,
    
    eoerror_value_CFG_mc_mc4plus_ok                     = 19,
    eoerror_value_CFG_mc_mc4plus_failed_encoders_verify = 20,    
    
    eoerror_value_CFG_encoders_ok                       = 21,
    eoerror_value_CFG_encoders_failed_verify            = 22,

    eoerror_value_CFG_inertials_ok                      = 23,
    eoerror_value_CFG_inertials_failed_toomanyboards    = 24,
    eoerror_value_CFG_inertials_failed_candiscovery     = 25,
    
    eoerror_value_CFG_comm_cannotloadaregularrop        = 26,
    
    eoerror_value_CFG_mc_mc4plusmais_ok                 = 27,
    eoerror_value_CFG_mc_mc4plusmais_failed_encoders_verify = 28, 
    eoerror_value_CFG_mc_mc4plusmais_failed_candiscovery_of_mais = 29,

    eoerror_value_CFG_services_not_verified_yet         = 30,
    eoerror_value_CFG_mc_not_verified_yet               = 31,
    eoerror_value_CFG_strain_not_verified_yet           = 32,        
    eoerror_value_CFG_mais_not_verified_yet             = 33,
    eoerror_value_CFG_skin_not_verified_yet             = 34,        
    eoerror_value_CFG_inertials_not_verified_yet        = 35,
    eoerror_value_CFG_inertials3_not_verified_yet       = 36,
    eoerror_value_CFG_encoders_not_verified_yet         = 37,

    eoerror_value_CFG_mc_using_onboard_config           = 38,
    eoerror_value_CFG_strain_using_onboard_config       = 39,
    eoerror_value_CFG_mais_using_onboard_config         = 40,
    eoerror_value_CFG_inertials_using_onboard_config    = 41,
    eoerror_value_CFG_inertials3_using_onboard_config   = 42,
    eoerror_value_CFG_skin_using_onboard_config         = 43,
    
    eoerror_value_CFG_inertials_failed_unsupportedsensor= 44,
    eoerror_value_CFG_inertials_changed_requestedrate   = 45,
    
    eoerror_value_CFG_inertials3_failed_unsupportedsensor= 46,
    eoerror_value_CFG_inertials3_changed_requestedrate  = 47,

    eoerror_value_CFG_inertials3_ok                     = 48,
    eoerror_value_CFG_inertials3_failed_toomanyboards   = 49,
    eoerror_value_CFG_inertials3_failed_candiscovery    = 50,
    eoerror_value_CFG_inertials3_failed_generic         = 51,
    
    eoerror_value_CFG_temperatures_not_verified_yet      = 52,
    eoerror_value_CFG_temperatures_ok                    = 53,
    eoerror_value_CFG_temperatures_failed_toomanyboards  = 54,
    eoerror_value_CFG_temperatures_failed_candiscovery   = 55,
    eoerror_value_CFG_temperatures_failed_generic        = 56,
    eoerror_value_CFG_temperatures_changed_requestedrate = 57,
    eoerror_value_CFG_temperatures_using_onboard_config  = 58,
    
    eoerror_value_CFG_psc_ok                            = 59,
    eoerror_value_CFG_psc_failed_candiscovery           = 60,
    eoerror_value_CFG_psc_failed_verify_because_active  = 61,
    eoerror_value_CFG_psc_not_verified_yet              = 62,
    eoerror_value_CFG_psc_using_onboard_config          = 63,
    eoerror_value_CFG_psc_changed_requestedrate         = 64,
    
    
    eoerror_value_CFG_mc_mc2pluspsc_ok                  = 65,
    eoerror_value_CFG_mc_mc2pluspsc_failed_encoders_verify = 66, 
    eoerror_value_CFG_mc_mc2pluspsc_failed_candiscovery_of_pscs = 67,
    
    eoerror_value_CFG_inertials_failed_notsupported = 68,
    eoerror_value_CFG_inertials3_failed_notsupported = 69,
    eoerror_value_CFG_temperatures_failed_notsupported = 70,
    eoerror_value_CFG_mais_failed_notsupported = 71,
    eoerror_value_CFG_strain_failed_notsupported = 72,
    eoerror_value_CFG_skin_failed_notsupported = 73,
    eoerror_value_CFG_psc_failed_notsupported = 74,
    eoerror_value_CFG_mc_failed_notsupported = 75,
    eoerror_value_CFG_encoders_failed_notsupported = 76,
    
    eoerror_value_CFG_pos_ok                            = 77,
    eoerror_value_CFG_pos_failed_candiscovery           = 78,
    eoerror_value_CFG_pos_failed_verify_because_active  = 79,
    eoerror_value_CFG_pos_not_verified_yet              = 80,
    eoerror_value_CFG_pos_using_onboard_config          = 81,
    eoerror_value_CFG_pos_changed_requestedrate         = 82,
    eoerror_value_CFG_pos_failed_notsupported           = 83,
    
    eoerror_value_CFG_mc_mc4plusfaps_ok                 = 84,
    eoerror_value_CFG_mc_mc4plusfaps_failed_encoders_verify = 85, 
    eoerror_value_CFG_mc_mc4plusfaps_failed_candiscovery_of_pmc = 86,    

    eoerror_value_CFG_mc_mc4pluspmc_ok                 = 87,
    eoerror_value_CFG_mc_mc4pluspmc_failed_encoders_verify = 88, 
    eoerror_value_CFG_mc_mc4pluspmc_failed_candiscovery_of_pmc = 89,  
    
} eOerror_value_CFG_t;

enum { eoerror_value_CFG_numberof = 90 };


/** @typedef    typedef enum eOerror_value_ETHMON_t
    @brief      it contains the values of the eOerror_value_ETHmonitor_t category.
 **/
typedef enum
{
    eoerror_value_ETHMON_link_goes_up                   = 0,
    eoerror_value_ETHMON_link_goes_down                 = 1,
    eoerror_value_ETHMON_error_rxcrc                    = 2,
    eoerror_value_ETHMON_txseqnumbermissing             = 3,
    eoerror_value_ETHMON_juststarted                    = 4,
    eoerror_value_ETHMON_justverified                   = 5
} eOerror_value_ETHMON_t;

enum { eoerror_value_ETHMON_numberof = 6 };


/** @typedef    typedef enum eOerror_value_IS_t
    @brief      it contains the values of the eoerror_category_InertialSensor category. In case you need a new value: add it
                in consecutive mode without holes and increment eoerror_value_SK_numberof. In case you need to remove a value, dont
                remove the number but simply rename it: that will help detecting old boards sending pairs {category, value} not supported yet.  
 **/
typedef enum
{
    eoerror_value_IS_arrayofinertialdataoverflow        = 0,
    eoerror_value_IS_unknownsensor                      = 1
} eOerror_value_IS_t;

enum { eoerror_value_IS_numberof = 2 };


/** @typedef    typedef enum eOerror_value_AS_t
    @brief      it contains the values of the eoerror_category_AnalogSensor category.  
 **/
typedef enum
{
    eoerror_value_AS_arrayoftemperaturedataoverflow     = 0,
    eoerror_value_AS_unknownsensor                      = 1
} eOerror_value_AS_t;

enum { eoerror_value_AS_numberof = 2 };

// - declaration of extern public variables, ... but better using use _get/_set instead -------------------------------


extern const eOerror_code_t eoerror_code_dummy;     // = EOERROR_CODE_DUMMY
extern const eOerror_value_t eoerror_value_dummy;   // = EOERROR_VALUE_DUMMY


// - declaration of extern public functions ---------------------------------------------------------------------------


/** @fn         extern eOerror_code_t eoerror_errorcode_get(eOerror_category_t cat, eOerror_value_t val)
    @brief      it retrieves the error code given a category and a value.
    @param      cat             the category
    @param      val             the value. Use relevant values for the enum of the specific category: eOerror_value_SYS_t, 
                                eOerror_value_HW_t, eOerror_value_MC_t, et cetera.
    @return     the valid error code or eoerror_code_dummy in case of wrong parameters.
 **/
extern eOerror_code_t eoerror_code_get(eOerror_category_t cat, eOerror_value_t val); 


/** @fn         extern eOerror_category_t eoerror_code2category(eOerror_code_t code)
    @brief      it retrieves the category given an error code.
    @param      code            the error code obtained from a message or from function eoerror_code_get(). 

    @return     the valid category or eoerror_category_dummy in case of unsupported code.
 **/
extern eOerror_category_t eoerror_code2category(eOerror_code_t code); 


/** @fn         extern eOerror_value_t eoerror_code2value(eOerror_code_t code)
    @brief      it retrieves the value given an error code.
    @param      code            the error code obtained from a message or from function eoerror_code_get(). 

    @return     the valid value or eoerror_value_dummy in case of unsupported code.
 **/
extern eOerror_value_t eoerror_code2value(eOerror_code_t code); 


/** @fn         extern const char* eoerror_code2string(eOerror_code_t code)
    @brief      it returns a string which describes the error code in argument. 
                if the argument maps to an existing code, then the associated 
                string is returned. Otherwise, it is returned a string with prefix "eoerror_INTERNALERROR__"
                which describes why a valid string could not be found.                
    @param      code            the error code obtained from a message or from function eoerror_code_get()
    @return     a zero-terminated string associated to the error code or an error string with prefix "eoerror_INTERNALERROR__".
 **/
extern const char* eoerror_code2string(eOerror_code_t code);



/** @}            
    end of group eo_EoError  
 **/

#ifdef __cplusplus
}       // closing brace for extern "C"
#endif 
 
#endif  // include-guard


// - end-of-file (leave a blank line after)----------------------------------------------------------------------------




