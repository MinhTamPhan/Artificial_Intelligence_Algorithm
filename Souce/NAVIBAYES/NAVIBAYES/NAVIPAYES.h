#ifndef NAVIPAYES_H
#define NAVIPAYES_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;
#pragma once

struct Mushroom 
{
	char loaiNam;
	char hinhDang;
	char beMat;
	char mauSac;
	char vetTham;
	char muiHuong;
	char mauBaoTu;
	char phanBo;
	char moiTruong;
	char get_thuoctinh_i(int i)const
	{
		char rsl;
		switch (i)
		{
		case 0: rsl = hinhDang; break;
		case 1: rsl = beMat; break;
		case 2:rsl = mauSac; break;
		case 3:rsl = vetTham; break;
		case 4:rsl = muiHuong; break;
		case 5:rsl = mauBaoTu; break;
		case 6: rsl = phanBo; break;
		case 7:rsl = moiTruong; break;
		default: rsl = loaiNam;
			break;
		}
		return rsl;
	}
};

struct TapDuLieu
{
	vector<Mushroom> duLieu;
	int soLuongCoDoc;
	int soLuongAnDuoc;
};

struct XacSuatThuocTinh
{
	double xacSuatHinhDang[6];
	double xacSuatBeMat[4];
	double xacSuatMauSac[10];
	double xacSuatVetTham[2];
	double xacSuatMuiHuong[9];
	double xacSuatBaoTu[9];
	double xacSuatPhanBo[6];
	double xacSuatMoiTruong[7];
	void setthuoctinh_i_char(int i, char j, double gt)
	{
		switch (i)
		{
		case 0:
			switch (j)
			{
			case 'b':xacSuatHinhDang[0] = gt; break;
			case 'c':xacSuatHinhDang[1] = gt; break;
			case 'x':xacSuatHinhDang[2] = gt; break;
			case 'f':xacSuatHinhDang[3] = gt; break;
			case 'k':xacSuatHinhDang[4] = gt; break;
			case 's':xacSuatHinhDang[5] = gt; break;
			default:xacSuatHinhDang[5] = gt; break;
			}break;
		case 1:
			switch (j)
			{
			case 'f':xacSuatBeMat[0] = gt; break;
			case 'g':xacSuatBeMat[1] = gt; break;
			case 'y':xacSuatBeMat[2] = gt; break;
			case 's':xacSuatBeMat[3] = gt; break;
			default:xacSuatBeMat[3] = gt; break;
			}break;
		case 2:
			switch (j)
			{
			case 'n':xacSuatMauSac[0] = gt; break;
			case 'b':xacSuatMauSac[1] = gt; break;
			case 'c':xacSuatMauSac[2] = gt; break;
			case 'r':xacSuatMauSac[3] = gt; break;
			case 'p':xacSuatMauSac[4] = gt; break;
			case 'u':xacSuatMauSac[5] = gt; break;
			case 'e':xacSuatMauSac[6] = gt; break;
			case 'w':xacSuatMauSac[7] = gt; break;
			case 'y':xacSuatMauSac[8] = gt; break;
			case 'g':xacSuatMauSac[9] = gt; break;
			default:xacSuatMauSac[5] = gt;
			}break;
		case 3:
			switch (j)
			{
			case 't':xacSuatVetTham[0] = gt; break;
			default:xacSuatVetTham[1] = gt; break;
			}break;
		case 4:
			switch (j)
			{
			case 'a':xacSuatMuiHuong[0] = gt; break;
			case 'l':xacSuatMuiHuong[1] = gt; break;
			case 'c':xacSuatMuiHuong[2] = gt; break;
			case 'y':xacSuatMuiHuong[3] = gt; break;
			case 'f':xacSuatMuiHuong[4] = gt; break;
			case 'm':xacSuatMuiHuong[5] = gt; break;
			case 'n':xacSuatMuiHuong[6] = gt; break;
			case 'p':xacSuatMuiHuong[7] = gt; break;
			case 's':xacSuatMuiHuong[8] = gt; break;
			default:xacSuatMuiHuong[1] = gt;
			}break;
		case 5:
			switch (j)
			{
			case 'k':xacSuatBaoTu[0] = gt; break;
			case 'n':xacSuatBaoTu[1] = gt; break;
			case 'b':xacSuatBaoTu[2] = gt; break;
			case 'h':xacSuatBaoTu[3] = gt; break;
			case 'r':xacSuatBaoTu[4] = gt; break;
			case 'o':xacSuatBaoTu[5] = gt; break;
			case 'u':xacSuatBaoTu[6] = gt; break;
			case 'w':xacSuatBaoTu[7] = gt; break;
			case 'y':xacSuatBaoTu[8] = gt; break;
			default:xacSuatBaoTu[5] = gt;
			}break;
		case 6:
			switch (j)
			{
			case 's':xacSuatPhanBo[0] = gt; break;
			case 'c':xacSuatPhanBo[1] = gt; break;
			case 'n':xacSuatPhanBo[2] = gt; break;
			case 'a':xacSuatPhanBo[3] = gt; break;
			case 'v':xacSuatPhanBo[4] = gt; break;
			case 'y':xacSuatPhanBo[5] = gt; break;
			default:xacSuatPhanBo[4] = gt; break;
			}break;
		case 7:
			switch (j)
			{
			case 'g':xacSuatMoiTruong[0] = gt; break;
			case 'l':xacSuatMoiTruong[1] = gt; break;
			case 'm':xacSuatMoiTruong[2] = gt; break;
			case 'p':xacSuatMoiTruong[3] = gt; break;
			case 'u':xacSuatMoiTruong[4] = gt; break;
			case 'w':xacSuatMoiTruong[5] = gt; break;
			case 'd':xacSuatMoiTruong[6] = gt; break;
			default:xacSuatMoiTruong[3] = gt;
			}break;
		}
	}
	void setthuoctinh_i(int i, int j,double gt)
	{
		switch (i)
		{
		case 0: xacSuatHinhDang[j] = gt; break;
		case 1: xacSuatBeMat[j]=gt; break;
		case 2: xacSuatMauSac[j] = gt; break;
		case 3: xacSuatVetTham[j] = gt; break;
		case 4: xacSuatMuiHuong[j] = gt; break;
		case 5: xacSuatBaoTu[j] = gt; break;
		case 6: xacSuatPhanBo[j] = gt; break;
		case 7: xacSuatMoiTruong[j] = gt; break;
		}
	}
	double getthuoctinh_i_char(int i, char j) const
	{
		double gt;
		switch (i)
		{
		case 0: 
			switch (j)
			{
			case 'p':gt = xacSuatHinhDang[0]; break;
			case 'c':gt = xacSuatHinhDang[1]; break;
			case 'x':gt = xacSuatHinhDang[2]; break;
			case 'f':gt = xacSuatHinhDang[3]; break;
			case 'k':gt = xacSuatHinhDang[4]; break;
			case 's':gt = xacSuatHinhDang[5]; break;
			default :gt = xacSuatHinhDang[5];
			}break;
		case 1: 
			switch (j)
			{
			case 'f':gt = xacSuatBeMat[0]; break;
			case 'g':gt = xacSuatBeMat[1]; break;
			case 'y':gt = xacSuatBeMat[2]; break;
			case 's':gt = xacSuatBeMat[3]; break;
			default:gt = xacSuatBeMat[3];
			}break;
		case 2: 
			switch (j)
			{
			case 'n':gt = xacSuatMauSac[0]; break;
			case 'b':gt = xacSuatMauSac[1]; break;
			case 'c':gt = xacSuatMauSac[2]; break;
			case 'r':gt = xacSuatMauSac[3]; break;
			case 'p':gt = xacSuatMauSac[4]; break;
			case 'u':gt = xacSuatMauSac[5]; break;
			case 'e':gt = xacSuatMauSac[6]; break;
			case 'w':gt = xacSuatMauSac[7]; break;
			case 'y':gt = xacSuatMauSac[8]; break;
			case 'g':gt = xacSuatMauSac[8]; break;
			default:gt = xacSuatMauSac[5];
			}break;
		case 3: 
			switch (j)
			{
			case 't':gt = xacSuatVetTham[0]; break;
			case 'f':gt = xacSuatVetTham[1]; break;
			default:gt = xacSuatVetTham[1];
			}break;
		case 4:
			switch (j)
			{
			case 'a':gt = xacSuatMuiHuong[0]; break;
			case 'l':gt = xacSuatMuiHuong[1]; break;
			case 'c':gt = xacSuatMuiHuong[2]; break;
			case 'y':gt = xacSuatMuiHuong[3]; break;
			case 'f':gt = xacSuatMuiHuong[4]; break;
			case 'm':gt = xacSuatMuiHuong[5]; break;
			case 'n':gt = xacSuatMuiHuong[6]; break;
			case 'p':gt = xacSuatMuiHuong[7]; break;
			case 's':gt = xacSuatMuiHuong[8]; break;
			default:gt = xacSuatMuiHuong[1];
			}break;
		case 5: 
			switch (j)
			{
			case 'k':gt = xacSuatBaoTu[0]; break;
			case 'n':gt = xacSuatBaoTu[1]; break;
			case 'b':gt = xacSuatBaoTu[2]; break;
			case 'h':gt = xacSuatBaoTu[3]; break;
			case 'r':gt = xacSuatBaoTu[4]; break;
			case 'o':gt = xacSuatBaoTu[5]; break;
			case 'u':gt = xacSuatBaoTu[6]; break;
			case 'w':gt = xacSuatBaoTu[7]; break;
			case 'y':gt = xacSuatBaoTu[8]; break;
			default:gt = xacSuatBaoTu[5];
			}break;
		case 6: 
			switch (j)
			{
			case 's':gt = xacSuatPhanBo[0]; break;
			case 'c':gt = xacSuatPhanBo[1]; break;
			case 'n':gt = xacSuatPhanBo[2]; break;
			case 'a':gt = xacSuatPhanBo[3]; break;
			case 'v':gt = xacSuatPhanBo[4]; break;
			case 'y':gt = xacSuatPhanBo[5]; break;
			default:gt = xacSuatBaoTu[4];
			}break;
		case 7:
			switch (j)
			{
			case 'g':gt = xacSuatMoiTruong[0]; break;
			case 'l':gt = xacSuatMoiTruong[1]; break;
			case 'm':gt = xacSuatMoiTruong[2]; break;
			case 'p':gt = xacSuatMoiTruong[3]; break;
			case 'u':gt = xacSuatMoiTruong[4]; break;
			case 'w':gt = xacSuatMoiTruong[5]; break;
			case 'd':gt = xacSuatMoiTruong[6]; break;
			default:gt = xacSuatMoiTruong[3];
			}break;
		}
		return gt;
	}
	double getthuoctinh_i(int i, int j) const
	{
		double gt;
		switch (i)
		{
		case 0: gt = xacSuatHinhDang[j]; break;
		case 1: gt = xacSuatBeMat[j]; break;
		case 2: gt = xacSuatMauSac[j]; break;
		case 3: gt = xacSuatVetTham[j]; break;
		case 4: gt = xacSuatMuiHuong[j]; break;
		case 5: gt = xacSuatBaoTu[j]; break;
		case 6: gt = xacSuatPhanBo[j]; break;
		case 7: gt = xacSuatMoiTruong[j]; break;
		}
		return gt;
	}
};

struct NaiveBayes 
{
	double xacSuatKhongDoc;
	double xacSuatCoDoc;

	XacSuatThuocTinh lopKhongDoc;
	XacSuatThuocTinh lopCoDoc;
};

#endif // !NAVIPAYES_H