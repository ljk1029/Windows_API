HGDIOBJ SelectObject(
  _In_  HDC hdc,        // 目标 DC 的句柄
  _In_  HGDIOBJ hgdiobj // 被选中的对象
);

HPEN CreatePen(
  _In_  int fnPenStyle,     // 样式
  _In_  int nWidth,         // 宽度
  _In_  COLORREF crColor    // 颜色
);

BOOL MoveToEx(
  _In_   HDC hdc,           // 操作目标DC的句柄
  _In_   int X,             // x 坐标
  _In_   int Y,             // y 坐标
  _Out_  LPPOINT lpPoint    // 保存移动后的当前坐标
);

BOOL LineTo(
  _In_  HDC hdc,    // 目标DC句柄
  _In_  int nXEnd,  // 目标位置 x 坐标
  _In_  int nYEnd   // 目标位置 y 坐标
);



1、需设置 项目->常规->MFC的使用：讲标准Windows库改为在共享DLL中使用MFC

2、右键属性->链接器->高级->入口点：WinMainCRTStartup