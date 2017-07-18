#include"NAVIPAYES.h"
#include<fstream>
#include<sstream>
#include<string>

void DocTapDuLieu(char* duongDan, TapDuLieu &d)
{
	//1. Mở tập tin
	ifstream f;
	f.open(duongDan, fstream::in);
	d.soLuongAnDuoc = 0;
	d.soLuongCoDoc = 0;
	//2. Trong khi đọc chưa hết tập tin
	while (!f.eof())
	{
		string lineInput;
		//2.1 Đọc dòng dữ liệu
		getline(f, lineInput);
		istringstream tempStream(lineInput);
		//2.2 Phân tách theo dấu phẩy, tạo nấm và thêm vào
		Mushroom mush;	
		while (!tempStream.eof())
		{
			char c;
			tempStream >> mush.loaiNam >> c >> mush.hinhDang >> c >> mush.beMat >> c;
			tempStream >> mush.mauSac >> c >> mush.vetTham >> c >> mush.muiHuong >> c;
			tempStream >> mush.mauBaoTu >> c >> mush.phanBo >> c >> mush.moiTruong >> c;
			d.duLieu.push_back(mush);
			if (mush.loaiNam == 'p')
				d.soLuongCoDoc+=1;
			else d.soLuongAnDuoc+=1;
		}
	}
	f.close();
}
double XacSuatKhongDoc(const TapDuLieu &d) 
{
	double p = (d.soLuongAnDuoc + 1)*1.0 / (d.duLieu.size() + 2);
	return p;
}

double XacSuatCoDoc(const TapDuLieu &d)
{
	double p = 1.0 - XacSuatKhongDoc(d);
	return p;
}

int tinhM(const char &lop,const int& thuoctinh,const char &gt,const TapDuLieu &d)
{
	int dem = 0;
	for (size_t i = 0; i < d.duLieu.size(); i++)
	{
		if (d.duLieu[i].loaiNam == lop && d.duLieu[i].get_thuoctinh_i(thuoctinh) == gt)
			dem++;
	}
	return dem;
}

bool isContainVector_thuoctinh(const vector<char> &giatrithuoctinh,const char& giatri)
{
	size_t n = giatrithuoctinh.size();
	if (n == 0)
		return false;
	else
	{
		for (size_t i = 0; i < n; i++)
		{
			if (giatrithuoctinh[i] == giatri)
				return true;
		}
	}
	return false;
}

vector<char> set_giatrithuoctinh_i(const TapDuLieu &d,int i)
{
	vector<char>giatrithuoctinh;
	for (size_t j = 0; j < d.duLieu.size(); j++)
	{
		char gt = d.duLieu[j].get_thuoctinh_i(i);
		if (isContainVector_thuoctinh(giatrithuoctinh, gt) == false)
			giatrithuoctinh.push_back(gt);
	}
	return giatrithuoctinh;
}

void TinhXacXuatThuocTinh(NaiveBayes & NB,const TapDuLieu &data)
{
	char lopcodoc = 'p', lopkdoc = 'e';
	for (size_t i = 0; i < 8; i++)
	{
		vector<char>giatrithuoctinh = set_giatrithuoctinh_i(data, i);
		size_t k = giatrithuoctinh.size();
		for (size_t j = 0; j < k; j++)
		{
			int M1 = tinhM('e', i, giatrithuoctinh[j], data);
			int M2 = tinhM('p', i, giatrithuoctinh[j], data);
			double gt1= (M1+1.0) / (data.soLuongAnDuoc + k);
			double gt2 = (M1+1.0) / (data.soLuongCoDoc + k);
			NB.lopKhongDoc.setthuoctinh_i_char(i, giatrithuoctinh[j], gt1);
			NB.lopCoDoc.setthuoctinh_i_char(i, giatrithuoctinh[j], gt2);
		}
	}

}

void GhiModel(char* duongDan, const NaiveBayes &NB,const TapDuLieu &data)
{
	//1. Mở tập tin
	fstream f;
	f.open(duongDan, fstream::out);
	f << NB.xacSuatCoDoc << " " << NB.xacSuatKhongDoc << endl;
	for (size_t i = 0; i < 8; i++)
	{
		vector<char>giatrithuoctinh = set_giatrithuoctinh_i(data, i);
		size_t k = giatrithuoctinh.size();
		for (size_t j = 0; j < k; j++)
		{
			f << NB.lopCoDoc.getthuoctinh_i(i, j) << " ";
		}
		f << endl;
		for (size_t j = 0; j < k; j++)
		{
			f << NB.lopKhongDoc.getthuoctinh_i(i, j) << " ";
		}
		f << endl;
	}
	f.close();
}

void GhiOutput(char *duongDan,const NaiveBayes & NB,const TapDuLieu & mr_test)
{
	fstream f;
	f.open(duongDan, fstream::out);
	size_t n = mr_test.duLieu.size();
	for (size_t i = 0; i < n; i++)
	{
		double pkdoc = NB.xacSuatKhongDoc, pcodoc = NB.xacSuatCoDoc;
		for (size_t j = 0; j < 8; j++)
		{
			char thuoctinh = mr_test.duLieu[i].get_thuoctinh_i(j);
			pkdoc *= NB.lopKhongDoc.getthuoctinh_i_char(j, thuoctinh);
			pcodoc *= NB.lopCoDoc.getthuoctinh_i_char(j, thuoctinh);
		}
		char out = (pcodoc > pkdoc ? 'p' : 'e');
		f << out << "\t" << mr_test.duLieu[i].get_thuoctinh_i(8) << endl;
	}
	f.close();
}

void main(int argc,char *argv[])
{
	TapDuLieu data;
	DocTapDuLieu(argv[1], data);
	NaiveBayes NB;
	NB.xacSuatCoDoc = XacSuatCoDoc(data);
	NB.xacSuatKhongDoc = XacSuatKhongDoc(data);
	TinhXacXuatThuocTinh(NB, data);
	TapDuLieu mr_test;
	DocTapDuLieu(argv[2], mr_test);
	int b = 6;
	GhiModel(argv[3], NB, data);
	GhiOutput(argv[4], NB, mr_test);
}