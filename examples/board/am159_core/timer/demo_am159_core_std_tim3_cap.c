/*******************************************************************************
*                                 AMetal
*                       ----------------------------
*                       innovating embedded platform
*
* Copyright (c) 2001-2018 Guangzhou ZHIYUAN Electronics Co., Ltd.
* All rights reserved.
*
* Contact information:
* web site:    http://www.zlg.cn/
*******************************************************************************/

/**
 * \file
 * \brief TIM3 ��ʱ�� CAP ���̣�ͨ����׼�ӿ�ʵ��
 *
 * - �������裺
 *   1. ʹ�öŰ��ߣ��� PIOA_0 �� PIOB_0 ���ӡ�
 *
 * - ʵ������
 *   1. TIM2 ͨ�� PIOA_0 ������� 2KHz �� PWM��
 *   2. TIM3 ��������ͨ�� 3 ʹ�� PIOB_0 ���Ų���
 *   3. ���ڴ�ӡ�����ò����ܵõ��� PWM �źŵ����ں�Ƶ�ʡ�
 *
 * \note
 *    ����۲촮�ڴ�ӡ�ĵ�����Ϣ����Ҫ�� PIOA_9 �������� PC ���ڵ� RXD��
 *
 * \par Դ����
 * \snippet demo_am159_core_std_tim3_cap.c src_am159_core_std_tim3_cap
 *
 * \internal
 * \par Modification history
 * - 1.00 16-04-22  nwt, first implementation
 * \endinternal
 */

/**
 * \addtogroup demo_if_am159_core_std_tim3_cap
 * \copydoc demo_am159_core_std_tim3_cap.c
 */

/** [src_am159_core_std_tim3_cap] */
#include "ametal.h"
#include "am_pwm.h"
#include "am_vdebug.h"
#include "am_zmf159_inst_init.h"
#include "demo_std_entries.h"
#include "demo_am159_core_entries.h"

/**
 * \brief �������
 */
void demo_am159_core_std_tim3_cap_entry (void)
{
    am_pwm_handle_t pwm_handle = am_zmf159_tim2_pwm_inst_init();

    AM_DBG_INFO("demo am159_core std tim3 cap!\r\n");

    /* TIM2 ���Ƶ��Ϊ 2KHz �� PWM */
    am_pwm_config(pwm_handle, 0, 500000 / 2, 500000);
    am_pwm_enable(pwm_handle, 0);

    demo_std_timer_cap_entry(am_zmf159_tim3_cap_inst_init(), 2);
}
/** [src_am159_core_std_tim3_cap] */

/* end of file */