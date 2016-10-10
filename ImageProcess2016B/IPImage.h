#pragma once
#include "DXManager.h"
class CIPImage
{
public:
	union PIXEL
	{
		struct { unsigned char r, g, b, a; }; //RGBA
		struct { unsigned char c, m, y, k; }; //CMYK
		struct { unsigned y0, u0, y1, v0; }; //YUY2
	};
protected:
	int		m_nPitch;   //Row size in bytes. Aka. Row Stride
	PIXEL*	m_pBuffer; //Puntero al primer pixel de la primer fila
	int		m_nSizeX; //Tamaño horizontal en pixeles
	int		m_nSizeY; //Tamaño venrtical en pixeles


public:
	PIXEL& operator()(int i, int j);
	static CIPImage* CreateImage(int sx, int sy, int nPitch);
	static void DestroyImage(CIPImage* pImage);
	static CIPImage* CaptureDesktop();
	static CIPImage* CreateImageFromFile(char* pszFileName); //Formato DIB "BMP"
	ID3D11Texture2D* CreateTexture(CDXManager* pManager);
	void Draw(int x, int y, HDC hdc);
protected:
	CIPImage();
	~CIPImage();
};

