HGDIOBJ SelectObject(
  _In_  HDC hdc,        // Ŀ�� DC �ľ��
  _In_  HGDIOBJ hgdiobj // ��ѡ�еĶ���
);

HPEN CreatePen(
  _In_  int fnPenStyle,     // ��ʽ
  _In_  int nWidth,         // ���
  _In_  COLORREF crColor    // ��ɫ
);

BOOL MoveToEx(
  _In_   HDC hdc,           // ����Ŀ��DC�ľ��
  _In_   int X,             // x ����
  _In_   int Y,             // y ����
  _Out_  LPPOINT lpPoint    // �����ƶ���ĵ�ǰ����
);

BOOL LineTo(
  _In_  HDC hdc,    // Ŀ��DC���
  _In_  int nXEnd,  // Ŀ��λ�� x ����
  _In_  int nYEnd   // Ŀ��λ�� y ����
);



1�������� ��Ŀ->����->MFC��ʹ�ã�����׼Windows���Ϊ�ڹ���DLL��ʹ��MFC

2���Ҽ�����->������->�߼�->��ڵ㣺WinMainCRTStartup