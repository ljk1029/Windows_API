一、
WM_COMMAND
消息中有两个参 数，wparam、lparam，定义如下：

wParam 高两个字节 通知码

wParam 低两字节 命令ID

lParam 发送命令消息的子窗体句柄。

list控件
WC_LISTVIEW

插入列
LVM_INSERTCOLUMN

列结构
typedef struct _LVCOLUMN {
	UINT mask;            //说明此结构中哪些成员是有效的
	int fmt;              //列的对齐方式
	int cx;               //列的初始宽度
	LPTSTR pszText;       //列的标题
	int cchTextMax;       //pszText所指向的缓冲区的大小
	int iSubItem;         //与列关联的子项的索引值，从0开始
	int iImage;           //与列关联的图像列表中指定图像的索引值
	int iOrder;           //第几列，0代表最左一列
} LVCOLUMN, FAR *LPLVCOLUMN;

项结构
typedef struct _LVITEM {
	UINT   mask;        //说明LVITEM结构中哪些成员有效
	int    iItem;       //项目的索引值(可以视为行号)从0开始
	int    iSubItem;    //子项的索引值(可以视为列号)从0开始
	UINT   state;       //子项的状态
	UINT   stateMask;   //状态有效的屏蔽位
	LPTSTR pszText;     //主项或子项的名称
	int    cchTextMax;   //pszText所指向的缓冲区大小
	int    iImage;       //关联图像列表中指定图像的索引值
	LPARAM lParam;       //程序定义的32位参数
	int iIndent;          //表示图像位置缩进的单位
} LVITEM, FAR *LPLVITEM;
