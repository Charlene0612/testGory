/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

//#include <stdio.h>
//#include "platform.h"
//#include "xil_printf.h"
//
//
//int main()
//{
//    init_platform();
//
//    print("Hello World\n\r");
//    print("Successfully ran Hello World application");
//    cleanup_platform();
//    return 0;
//}


//#include "xparameters.h"
//#include "xil_printf.h"
//#include "stdio.h"
//#include "bram_rd_ip.h"
//#include "TRlogic_bram.h"
//#include "xbram.h"
//#include "xscugic.h" // �����жϿ�����ͷ�ļ�
//#include "xil_exception.h"
//
//#define PL_BRAM_BASE        XPAR_BRAM_RD_IP_0_S01_AXI_BASEADDR   //PL_RAM_RD����ַ
//#define PL_BRAM_START       BRAM_RD_IP_S01_AXI_SLV_REG0_OFFSET   //RAMʹ���ź� �ļĴ�����ַ
//#define PL_BRAM_START_ADDR  BRAM_RD_IP_S01_AXI_SLV_REG1_OFFSET   //RAM��ʼ��ַ �ļĴ�����ַ
//#define PL_BRAM_LEN         BRAM_RD_IP_S01_AXI_SLV_REG2_OFFSET   //��дRAM��� �ļĴ�����ַ
//
//#define START_ADDR          0  //RAM��ʼ��ַ ��Χ:
//#define BRAM_DATA_BYTE      4  //BRAM�����ֽڸ���
//#define BRAM_DATA_WIDTH    32  // BRAM����λ����Ϊ��32λ���ݣ�������32λ
//
//uint32_t channel_data[1024*8];  //BRAM�������飬д��BRAM������
//// char ch_data[1024];            //д��BRAM���ַ�����
//int ch_data_len;               //д��BRAM���ַ�����
//char ch_data;
//
////��������
//void data_wr_bram();
//void data_rd_bram();
//
////main����
//int main()
//{
//    while(1)
//    {
//        printf("Please enter c to read and write BRAM\n") ;
//        scanf(" %c", &ch_data);        //�û������ַ�
//        // �ж�������ַ��Ƿ�Ϊ 'c'
//        if(ch_data == 'c') {
//            // ��ʼ�����飬��������ֻ�Ǽ򵥵����0��ʵ��Ӧ���п�����Ҫ�����ӵĳ�ʼ��
//            for (int i = 0; i < 1024*8; ++i) {
//                channel_data[i] = 80+i; // �����������ֵ
//            }
//
////            ch_data_len = 1024*8;
//            ch_data_len = 8;
//
//            data_wr_bram(); // ����ͨ���Ƚ�ֵ���ݲ�д��BRAM��
//            data_rd_bram(); // ��BRAM�ж�������
//        } else {
//            // ������� 'c'����ӡ��ʾ��Ϣ
//            xil_printf("please enter c to begin\n");
//        }
//    }
//    return 0;
//}
//
////������д��BRAM
//void data_wr_bram()
//{
//    int i=0,wr_cnt = 0;
//    //ÿ��ѭ����BRAM��д��1���ַ�
//    for(i = BRAM_DATA_BYTE*START_ADDR ; i < BRAM_DATA_BYTE*(START_ADDR + ch_data_len) ;
//            i += BRAM_DATA_BYTE){
//        XBram_WriteReg(XPAR_BRAM_0_BASEADDR,i,channel_data[wr_cnt]) ;
//        wr_cnt++;
//    }
//    //����BRAMд����ַ�������
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_LEN , BRAM_DATA_BYTE*ch_data_len) ;
//    //����BRAM����ʼ��ַ
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_START_ADDR, BRAM_DATA_BYTE*START_ADDR) ;
//    //����BRAM��ʼ�ź�
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_START , 1) ;
//    //����BRAM��ʼ�ź�
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_START , 0) ;
//}
//
////��BRAM�ж�������
//void data_rd_bram()
//{
//    int read_data=0,i=0;
//    //ѭ����BRAM�ж�������
//    for(i = BRAM_DATA_BYTE*START_ADDR ; i < BRAM_DATA_BYTE*(START_ADDR + ch_data_len) ;
//            i += BRAM_DATA_BYTE){
//        read_data = XBram_ReadReg(XPAR_BRAM_0_BASEADDR,i) ;
////        printf("BRAM address is %d\t,Read data is %c\n",i/BRAM_DATA_BYTE ,read_data) ;
//        printf("BRAM address is %d\t,Read data is 0x%04X\n", i/BRAM_DATA_BYTE, read_data);
//    }
//}


#include "xparameters.h"
#include "platform.h"
#include "xil_printf.h"
#include "stdio.h"
#include "bram_rd_ip.h"
#include "TRlogic_bram.h"
#include "xbram.h"
#include "xscugic.h" // �����жϿ�����ͷ�ļ�
#include "xil_exception.h"

//BRAM��д��������
#define PL_BRAM_BASE        XPAR_BRAM_RD_IP_0_S01_AXI_BASEADDR   //PL_RAM_RD����ַ
#define BRAM_WR_OVER       	BRAM_RD_IP_S01_AXI_SLV_REG0_OFFSET   //RAMд���ź� �ļĴ�����ַ
#define BRAM_START_ADDR  	BRAM_RD_IP_S01_AXI_SLV_REG1_OFFSET   //RAM��ʼ��ַ �ļĴ�����ַ
#define BRAM_RD_LEN         BRAM_RD_IP_S01_AXI_SLV_REG2_OFFSET   //��дRAM��� �ļĴ�����ַ

//TRlogic��������
#define TRLOGIC_BASE		XPAR_TRLOGIC_BRAM_0_S01_AXI_BASEADDR
#define CNT_EN       		TRLOGIC_BRAM_S01_AXI_SLV_REG0_OFFSET
#define CHANNEL_EN			TRLOGIC_BRAM_S01_AXI_SLV_REG1_OFFSET
#define PULSE_WIDTH			TRLOGIC_BRAM_S01_AXI_SLV_REG2_OFFSET
#define CNT_CYCLE			TRLOGIC_BRAM_S01_AXI_SLV_REG3_OFFSET

//�ж���ص��źŶ���
#define INTC_DEVICE_ID 		XPAR_SCUGIC_SINGLE_DEVICE_ID //�жϿ�����ID
#define INTC_RD_OVER_ID		XPAR_FABRIC_BRAM_RD_IP_0_BRAM_RD_OVER_INTR //�ж��ź�bram_rd_over��ID
#define INT_TYPE_RISING_EDGE        0x03
//#define INT_TYPE_MASK				0x01
#define INT_ICCPMR_OFFSET 	0xF8F00104
#define INT_ICCICR_OFFSET 	0xF8F00100


#define START_ADDR          0  //RAM��ʼ��ַ ��Χ:
#define BRAM_DATA_BYTE      4  //BRAM��ÿ�����ݵ��ֽڸ���
// #define BRAM_DATA_WIDTH    32  // BRAM����λ����Ϊ��32λ���ݣ�������32λ

uint32_t channel_data[1024*8];  //BRAM�������飬д��BRAM������
// char ch_data[1024];            //д��BRAM���ַ�����
int 	ch_data_len;               //д��BRAM�����ݸ���
char 	ch_data;

//��������
void data_wr_bram();
//void data_rd_bram();

//�жϿ�����ʵ��
XScuGic ScuGic;

static	void	IntrHandler(void *IntcInstancePtr);
static  void 	CPU_Init(void);
static  int 	InterruptInit(XScuGic *IntcInstancePtr);


//main����
int main(void)
{
    init_platform();
    CPU_Init();

	int Status;
    // ��ʼ���жϿ�����
    Status = InterruptInit(&ScuGic);
    if (Status != XST_SUCCESS) {
        xil_printf("Interrupt initialization failed\r\n");
        return XST_FAILURE;
    }

    //���ö�ʱ����Ҫ�Ĳ���
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, CNT_EN , 0x0001) ;
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, CHANNEL_EN , 0xffff) ;
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0014) ; //20��ʱ������
//    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0190) ;//400����IN�źţ�������
//    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0064) ;//100����IN�źţ�������
//    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0032) ;//50
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, CNT_CYCLE , 0x1f40) ; //8000��ʱ������



    while(1)
    {
        printf("Please enter c to read and write BRAM\r\n") ;
        scanf(" %c", &ch_data);        //�û������ַ�
        // �ж�������ַ��Ƿ�Ϊ 'c'
        if(ch_data == 'c') {
            // ��ʼ������
            for (int i = 0; i < 1024*8; ++i) {
//                channel_data[i] = 0x00600050; // �����������ֵ
                channel_data[i] = 0x00f000c8;//240��200
            }

            ch_data_len = 1024*8;
//            ch_data_len = 32;
            printf("write BRAM begin\r\n") ;
            data_wr_bram(); // ����ͨ���Ƚ�ֵ���ݲ�д��BRAM��
            // data_rd_bram(); // ��BRAM�ж�������

            // ����ȴ�״̬��ֱ���жϴ���
            while (1) {
            	;
            }

            // ����͹���״̬�ȴ��жϣ�ֱ�����жϷ���
//            asm("wfi");

        } else {
            // ������� 'c'����ӡ��ʾ��Ϣ
            xil_printf("please enter c to begin\r\n");
        }
    }
    cleanup_platform();
    return 0;

    // return 0;
//    return XST_SUCCESS;
}


//�жϴ�����
void IntrHandler(void *CallbackRef)
{
//	XScuGic *IntcInstancePtr = (XScuGic *)CallbackRef;
	// ���¿�ʼִ��data_wr_bram��data_rd_bram
    data_wr_bram();
    // data_rd_bram();
    xil_printf("BRAM write again due to interrupt\r\n");
//    XScuGic_Disable(IntcInstancePtr, INTC_RD_OVER_ID);
//    XScuGic_AcknowledgeInterrupt(IntcInstancePtr, INTC_RD_OVER_ID);
}


//�жϳ�ʼ������
static int InterruptInit(XScuGic *IntcInstancePtr)
{
    int Status;
    XScuGic_Config *IntcConfig;
    printf("Initialize the interrupt system >>>>>>\r\n");

    // ��ʼ���жϿ�����
    IntcConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);//���� GIC ��ID
    if (NULL == IntcConfig) {
        return XST_FAILURE;
    }

    Status = XScuGic_CfgInitialize(IntcInstancePtr, IntcConfig, IntcConfig->CpuBaseAddress);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }

    // ���ò����ж��쳣������
    Xil_ExceptionInit();
    Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT, (Xil_ExceptionHandler)XScuGic_InterruptHandler, IntcInstancePtr);
    // ʹ���ж�
    Xil_ExceptionEnable();

    // �����ж�Դ���жϿ�����
    Status = XScuGic_Connect(IntcInstancePtr, INTC_RD_OVER_ID, (Xil_ExceptionHandler)IntrHandler, NULL);
//    Status = XScuGic_Connect(IntcInstancePtr, INTC_RD_OVER_ID, (Xil_ExceptionHandler)IntrHandler, (void *)1);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }

    //�ж�����
//    SetIntcTypeRisingEdge(IntcInstancePtr, INTC_RD_OVER_ID);
//    IntcTypeSetup(&ScuGic,  INTC_RD_OVER_ID, INT_TYPE_RISING_EDGE);   //��Ҫ
//    IntcTypeEnable(&ScuGic,  INTC_RD_OVER_ID, INT_TYPE_MASK);
    // �����жϵ����ȼ��ʹ�������
    XScuGic_SetPriorityTriggerType(IntcInstancePtr,       // �жϿ�����ʵ��
        INTC_RD_OVER_ID,  // �ж�ԴID
        0xA0,              // ���ȼ�����ֵԽС���ȼ�Խ��
		INT_TYPE_RISING_EDGE // �������ͣ������ش���
    );


    // ʹ���ж�Դ
    XScuGic_Enable(IntcInstancePtr, INTC_RD_OVER_ID);
    printf("Initialize completed \r\n");

    return XST_SUCCESS;
}


void CPU_Init( )
{
    //�ж����ȼ�����A0,���ȼ�����F0��CPU�ɽ�����Щ�ж�
	Xil_Out32(INT_ICCPMR_OFFSET,0xF0);
    //�������ܽ���IRQ��ʹ���ж��ź����ӵ�������
	Xil_Out32(INT_ICCICR_OFFSET,0x07);
}


//������д��BRAM
void data_wr_bram()
{
    int i=0,wr_cnt = 0;
    //ÿ��ѭ����BRAM��д��1���ַ�
    for(i = BRAM_DATA_BYTE*START_ADDR ; i < BRAM_DATA_BYTE*(START_ADDR + ch_data_len) ;
            i += BRAM_DATA_BYTE){
        XBram_WriteReg(XPAR_BRAM_0_BASEADDR,i,channel_data[wr_cnt]) ;
        wr_cnt++;
    }
    //����BRAMд����ַ�������
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_RD_LEN , BRAM_DATA_BYTE*ch_data_len) ;
    //����BRAM����ʼ��ַ
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_START_ADDR, BRAM_DATA_BYTE*START_ADDR) ;
    //����BRAMд���ź�
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_WR_OVER , 1) ;
    //����BRAMд���ź�
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_WR_OVER , 0) ;
}

//��BRAM�ж�������
// void data_rd_bram()
// {
//     int read_data=0,i=0;
//     //ѭ����BRAM�ж�������
//     for(i = BRAM_DATA_BYTE*START_ADDR ; i < BRAM_DATA_BYTE*(START_ADDR + ch_data_len) ;
//             i += BRAM_DATA_BYTE){
//         read_data = XBram_ReadReg(XPAR_BRAM_0_BASEADDR,i) ;
// //        printf("BRAM address is %d\t,Read data is %c\n",i/BRAM_DATA_BYTE ,read_data) ;
//         printf("BRAM address is %d\t,Read data is 0x%04X\n", i/BRAM_DATA_BYTE, read_data);
//     }
// }
