#pragma once
#include "iocp\IocpModel.h"
#include <string>
#include <vector>
using namespace std;

#define	IDC_hLB_Output				40002
#define	IDC_hEB_InputServerIP		40003
#define	IDC_hEB_InputServerPort		40004
#define	IDC_hST_TextServerIP		40006
#define	IDC_hST_TextServerPort		40007
#define	IDC_hBtn_Start				50000
#define	IDC_hBtn_Stop				50001
#define	IDC_hBtn_Exit				50002

namespace MyServer
{
	class MyServerEngine
	{
	protected:
		HINSTANCE mhAppInst;	 //实例
		HWND mhMainWnd;	 //主窗口句柄
		LPCTSTR lpszApplicationName; //程序名
		LPCTSTR lpszTitle; //标题
		int mServerPort; //服务端口
		CIocpModel m_IOCP; // 主要对象，完成端口模型

		static HANDLE m_hMutexServerMsgs; //互斥对象
		vector<string> m_vtServerMsgs; //要显示的消息

		HWND hLB_Output;
		HWND hST_TextServerIP;
		HWND hEB_InputServerIP;
		HWND hST_TextServerPort;
		HWND hEB_InputServerPort;

		HWND hBtnStart;	 //开始监听
		HWND hBtnStop;	 //停止监听
		HWND hBtnExit;	 //退出按钮

	public:
		MyServerEngine(HINSTANCE hInstance);
		virtual ~MyServerEngine();

	public:
		HINSTANCE getAppInst();	 //返回实例
		HWND getMainWnd();	 //返回主窗口句柄

	public:
		virtual void Init(); //初始化
		virtual void InitMainWindow(); //初始化主窗口
		virtual void InitControls(HWND hWnd); //初始化主窗口中的控件
		virtual int Run(); //运行
		virtual void ShutDown(); //关闭

		virtual void AddServerMsgs(string& msg); //添加服务器消息
		virtual void SettleServerMsgs(); //处理服务器消息
		//主窗口处理函数
		virtual LRESULT msgProc(UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
		virtual void ShowText(string& msg); //显示消息
	};

	extern MyServerEngine* g_pServerEngine; //引擎对象
}

