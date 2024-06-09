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
//#include "xscugic.h" // 引入中断控制器头文件
//#include "xil_exception.h"
//
//#define PL_BRAM_BASE        XPAR_BRAM_RD_IP_0_S01_AXI_BASEADDR   //PL_RAM_RD基地址
//#define PL_BRAM_START       BRAM_RD_IP_S01_AXI_SLV_REG0_OFFSET   //RAM使能信号 的寄存器地址
//#define PL_BRAM_START_ADDR  BRAM_RD_IP_S01_AXI_SLV_REG1_OFFSET   //RAM起始地址 的寄存器地址
//#define PL_BRAM_LEN         BRAM_RD_IP_S01_AXI_SLV_REG2_OFFSET   //读写RAM深度 的寄存器地址
//
//#define START_ADDR          0  //RAM起始地址 范围:
//#define BRAM_DATA_BYTE      4  //BRAM数据字节个数
//#define BRAM_DATA_WIDTH    32  // BRAM数据位宽，因为是32位数据，所以是32位
//
//uint32_t channel_data[1024*8];  //BRAM数据数组，写入BRAM的数据
//// char ch_data[1024];            //写入BRAM的字符数组
//int ch_data_len;               //写入BRAM的字符个数
//char ch_data;
//
////函数声明
//void data_wr_bram();
//void data_rd_bram();
//
////main函数
//int main()
//{
//    while(1)
//    {
//        printf("Please enter c to read and write BRAM\n") ;
//        scanf(" %c", &ch_data);        //用户输入字符
//        // 判断输入的字符是否为 'c'
//        if(ch_data == 'c') {
//            // 初始化数组，这里我们只是简单地填充0，实际应用中可能需要更复杂的初始化
//            for (int i = 0; i < 1024*8; ++i) {
//                channel_data[i] = 80+i; // 或者填充其他值
//            }
//
////            ch_data_len = 1024*8;
//            ch_data_len = 8;
//
//            data_wr_bram(); // 生成通道比较值数据并写入BRAM中
//            data_rd_bram(); // 从BRAM中读出数据
//        } else {
//            // 如果不是 'c'，打印提示信息
//            xil_printf("please enter c to begin\n");
//        }
//    }
//    return 0;
//}
//
////将数据写入BRAM
//void data_wr_bram()
//{
//    int i=0,wr_cnt = 0;
//    //每次循环向BRAM中写入1个字符
//    for(i = BRAM_DATA_BYTE*START_ADDR ; i < BRAM_DATA_BYTE*(START_ADDR + ch_data_len) ;
//            i += BRAM_DATA_BYTE){
//        XBram_WriteReg(XPAR_BRAM_0_BASEADDR,i,channel_data[wr_cnt]) ;
//        wr_cnt++;
//    }
//    //设置BRAM写入的字符串长度
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_LEN , BRAM_DATA_BYTE*ch_data_len) ;
//    //设置BRAM的起始地址
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_START_ADDR, BRAM_DATA_BYTE*START_ADDR) ;
//    //拉高BRAM开始信号
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_START , 1) ;
//    //拉低BRAM开始信号
//    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, PL_BRAM_START , 0) ;
//}
//
////从BRAM中读出数据
//void data_rd_bram()
//{
//    int read_data=0,i=0;
//    //循环从BRAM中读出数据
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
#include "xscugic.h" // 引入中断控制器头文件
#include "xil_exception.h"

//BRAM读写参数配置
#define PL_BRAM_BASE        XPAR_BRAM_RD_IP_0_S01_AXI_BASEADDR   //PL_RAM_RD基地址
#define BRAM_WR_OVER       	BRAM_RD_IP_S01_AXI_SLV_REG0_OFFSET   //RAM写完信号 的寄存器地址
#define BRAM_START_ADDR  	BRAM_RD_IP_S01_AXI_SLV_REG1_OFFSET   //RAM起始地址 的寄存器地址
#define BRAM_RD_LEN         BRAM_RD_IP_S01_AXI_SLV_REG2_OFFSET   //读写RAM深度 的寄存器地址

//TRlogic参数配置
#define TRLOGIC_BASE		XPAR_TRLOGIC_BRAM_0_S01_AXI_BASEADDR
#define CNT_EN       		TRLOGIC_BRAM_S01_AXI_SLV_REG0_OFFSET
#define CHANNEL_EN			TRLOGIC_BRAM_S01_AXI_SLV_REG1_OFFSET
#define PULSE_WIDTH			TRLOGIC_BRAM_S01_AXI_SLV_REG2_OFFSET
#define CNT_CYCLE			TRLOGIC_BRAM_S01_AXI_SLV_REG3_OFFSET

//中断相关的信号定义
#define INTC_DEVICE_ID 		XPAR_SCUGIC_SINGLE_DEVICE_ID //中断控制器ID
#define INTC_RD_OVER_ID		XPAR_FABRIC_BRAM_RD_IP_0_BRAM_RD_OVER_INTR //中断信号bram_rd_over的ID
#define INT_TYPE_RISING_EDGE        0x03
//#define INT_TYPE_MASK				0x01
#define INT_ICCPMR_OFFSET 	0xF8F00104
#define INT_ICCICR_OFFSET 	0xF8F00100


#define START_ADDR          0  //RAM起始地址 范围:
#define BRAM_DATA_BYTE      4  //BRAM中每个数据的字节个数
// #define BRAM_DATA_WIDTH    32  // BRAM数据位宽，因为是32位数据，所以是32位

uint32_t channel_data[1024*8];  //BRAM数据数组，写入BRAM的数据
// char ch_data[1024];            //写入BRAM的字符数组
int 	ch_data_len;               //写入BRAM的数据个数
char 	ch_data;

//函数声明
void data_wr_bram();
//void data_rd_bram();

//中断控制器实例
XScuGic ScuGic;

static	void	IntrHandler(void *IntcInstancePtr);
static  void 	CPU_Init(void);
static  int 	InterruptInit(XScuGic *IntcInstancePtr);


//main函数
int main(void)
{
    init_platform();
    CPU_Init();

	int Status;
    // 初始化中断控制器
    Status = InterruptInit(&ScuGic);
    if (Status != XST_SUCCESS) {
        xil_printf("Interrupt initialization failed\r\n");
        return XST_FAILURE;
    }

    //配置定时器需要的参数
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, CNT_EN , 0x0001) ;
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, CHANNEL_EN , 0xffff) ;
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0014) ; //20个时钟周期
//    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0190) ;//400，有IN信号，但不对
//    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0064) ;//100，有IN信号，但不对
//    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, PULSE_WIDTH , 0x0032) ;//50
    TRLOGIC_BRAM_mWriteReg(TRLOGIC_BASE, CNT_CYCLE , 0x1f40) ; //8000个时钟周期



    while(1)
    {
        printf("Please enter c to read and write BRAM\r\n") ;
        scanf(" %c", &ch_data);        //用户输入字符
        // 判断输入的字符是否为 'c'
        if(ch_data == 'c') {
            // 初始化数组
            for (int i = 0; i < 1024*8; ++i) {
//                channel_data[i] = 0x00600050; // 或者填充其他值
                channel_data[i] = 0x00f000c8;//240和200
            }

            ch_data_len = 1024*8;
//            ch_data_len = 32;
            printf("write BRAM begin\r\n") ;
            data_wr_bram(); // 生成通道比较值数据并写入BRAM中
            // data_rd_bram(); // 从BRAM中读出数据

            // 进入等待状态，直到中断触发
            while (1) {
            	;
            }

            // 进入低功耗状态等待中断，直到有中断发生
//            asm("wfi");

        } else {
            // 如果不是 'c'，打印提示信息
            xil_printf("please enter c to begin\r\n");
        }
    }
    cleanup_platform();
    return 0;

    // return 0;
//    return XST_SUCCESS;
}


//中断处理函数
void IntrHandler(void *CallbackRef)
{
//	XScuGic *IntcInstancePtr = (XScuGic *)CallbackRef;
	// 重新开始执行data_wr_bram和data_rd_bram
    data_wr_bram();
    // data_rd_bram();
    xil_printf("BRAM write again due to interrupt\r\n");
//    XScuGic_Disable(IntcInstancePtr, INTC_RD_OVER_ID);
//    XScuGic_AcknowledgeInterrupt(IntcInstancePtr, INTC_RD_OVER_ID);
}


//中断初始化函数
static int InterruptInit(XScuGic *IntcInstancePtr)
{
    int Status;
    XScuGic_Config *IntcConfig;
    printf("Initialize the interrupt system >>>>>>\r\n");

    // 初始化中断控制器
    IntcConfig = XScuGic_LookupConfig(INTC_DEVICE_ID);//查找 GIC 的ID
    if (NULL == IntcConfig) {
        return XST_FAILURE;
    }

    Status = XScuGic_CfgInitialize(IntcInstancePtr, IntcConfig, IntcConfig->CpuBaseAddress);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }

    // 设置并打开中断异常处理函数
    Xil_ExceptionInit();
    Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT, (Xil_ExceptionHandler)XScuGic_InterruptHandler, IntcInstancePtr);
    // 使能中断
    Xil_ExceptionEnable();

    // 连接中断源到中断控制器
    Status = XScuGic_Connect(IntcInstancePtr, INTC_RD_OVER_ID, (Xil_ExceptionHandler)IntrHandler, NULL);
//    Status = XScuGic_Connect(IntcInstancePtr, INTC_RD_OVER_ID, (Xil_ExceptionHandler)IntrHandler, (void *)1);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }

    //中断配置
//    SetIntcTypeRisingEdge(IntcInstancePtr, INTC_RD_OVER_ID);
//    IntcTypeSetup(&ScuGic,  INTC_RD_OVER_ID, INT_TYPE_RISING_EDGE);   //重要
//    IntcTypeEnable(&ScuGic,  INTC_RD_OVER_ID, INT_TYPE_MASK);
    // 设置中断的优先级和触发类型
    XScuGic_SetPriorityTriggerType(IntcInstancePtr,       // 中断控制器实例
        INTC_RD_OVER_ID,  // 中断源ID
        0xA0,              // 优先级，数值越小优先级越高
		INT_TYPE_RISING_EDGE // 触发类型，上升沿触发
    );


    // 使能中断源
    XScuGic_Enable(IntcInstancePtr, INTC_RD_OVER_ID);
    printf("Initialize completed \r\n");

    return XST_SUCCESS;
}


void CPU_Init( )
{
    //中断优先级都是A0,优先级高于F0，CPU可接受这些中断
	Xil_Out32(INT_ICCPMR_OFFSET,0xF0);
    //处理器能接收IRQ，使能中断信号连接到处理器
	Xil_Out32(INT_ICCICR_OFFSET,0x07);
}


//将数据写入BRAM
void data_wr_bram()
{
    int i=0,wr_cnt = 0;
    //每次循环向BRAM中写入1个字符
    for(i = BRAM_DATA_BYTE*START_ADDR ; i < BRAM_DATA_BYTE*(START_ADDR + ch_data_len) ;
            i += BRAM_DATA_BYTE){
        XBram_WriteReg(XPAR_BRAM_0_BASEADDR,i,channel_data[wr_cnt]) ;
        wr_cnt++;
    }
    //设置BRAM写入的字符串长度
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_RD_LEN , BRAM_DATA_BYTE*ch_data_len) ;
    //设置BRAM的起始地址
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_START_ADDR, BRAM_DATA_BYTE*START_ADDR) ;
    //拉高BRAM写完信号
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_WR_OVER , 1) ;
    //拉低BRAM写完信号
    BRAM_RD_IP_mWriteReg(PL_BRAM_BASE, BRAM_WR_OVER , 0) ;
}

//从BRAM中读出数据
// void data_rd_bram()
// {
//     int read_data=0,i=0;
//     //循环从BRAM中读出数据
//     for(i = BRAM_DATA_BYTE*START_ADDR ; i < BRAM_DATA_BYTE*(START_ADDR + ch_data_len) ;
//             i += BRAM_DATA_BYTE){
//         read_data = XBram_ReadReg(XPAR_BRAM_0_BASEADDR,i) ;
// //        printf("BRAM address is %d\t,Read data is %c\n",i/BRAM_DATA_BYTE ,read_data) ;
//         printf("BRAM address is %d\t,Read data is 0x%04X\n", i/BRAM_DATA_BYTE, read_data);
//     }
// }
