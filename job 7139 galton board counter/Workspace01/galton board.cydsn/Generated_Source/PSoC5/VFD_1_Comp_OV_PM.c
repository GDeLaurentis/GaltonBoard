/*******************************************************************************
* File Name: VFD_1_Comp_OV.c
* Version 2.0
*
* Description:
*  This file provides the power management source code APIs for the
*  Comparator.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "VFD_1_Comp_OV.h"

static VFD_1_Comp_OV_backupStruct VFD_1_Comp_OV_backup;


/*******************************************************************************
* Function Name: VFD_1_Comp_OV_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
*******************************************************************************/
void VFD_1_Comp_OV_SaveConfig(void) 
{
    /* Empty since all are system reset for retention flops */
}


/*******************************************************************************
* Function Name: VFD_1_Comp_OV_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
********************************************************************************/
void VFD_1_Comp_OV_RestoreConfig(void) 
{
    /* Empty since all are system reset for retention flops */    
}


/*******************************************************************************
* Function Name: VFD_1_Comp_OV_Sleep
********************************************************************************
*
* Summary:
*  Stop and Save the user configuration
*
* Parameters:
*  void:
*
* Return:
*  void
*
* Global variables:
*  VFD_1_Comp_OV_backup.enableState:  Is modified depending on the enable 
*   state of the block before entering sleep mode.
*
*******************************************************************************/
void VFD_1_Comp_OV_Sleep(void) 
{
    /* Save Comp's enable state */    
    if(VFD_1_Comp_OV_ACT_PWR_EN == (VFD_1_Comp_OV_PWRMGR & VFD_1_Comp_OV_ACT_PWR_EN))
    {
        /* Comp is enabled */
        VFD_1_Comp_OV_backup.enableState = 1u;
    }
    else
    {
        /* Comp is disabled */
        VFD_1_Comp_OV_backup.enableState = 0u;
    }    
    
    VFD_1_Comp_OV_Stop();
    VFD_1_Comp_OV_SaveConfig();
}


/*******************************************************************************
* Function Name: VFD_1_Comp_OV_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  VFD_1_Comp_OV_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VFD_1_Comp_OV_Wakeup(void) 
{
    VFD_1_Comp_OV_RestoreConfig();
    
    if(VFD_1_Comp_OV_backup.enableState == 1u)
    {
        /* Enable Comp's operation */
        VFD_1_Comp_OV_Enable();

    } /* Do nothing if Comp was disabled before */ 
}


/* [] END OF FILE */
