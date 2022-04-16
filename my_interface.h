//file: my_interface.h
//��������������

#ifndef MY_INTERFACE_H
#define MY_INTERFACE_H

#include"tools.h"
#include"cloud.h"
#include<string>
#include<vector>
using std::string;

class my_interface
{
public:
	//���ڽ�����г�ʼ������
	//����1������ͼ�Ŀ�� Ĭ��60
	//����2������ʾ���Ŀ�� Ĭ��30
	//����3��������ĸ߶� Ĭ��30
	//���ڽ�����д�С���������Ҵ�ӡ�߽�
	my_interface(int map_w = 60, int tooltip_w = 30, int l = 30);

	//��ӡ�߽�
	void print_edge()const;

	//����ʾ����ʾ���� 
	//����1��ʾ�ڵڼ�����ʾ
	//����2����һ���ַ�����ӡ
	//�������1������Χ���׳� out_of_range
	//�������2������Χ���׳� out_of_range
	void print_in_tip(int start,string& content)const;

	//��ӡ��ͼ����
	void print_map()const;

	//���õ�ͼ
	void set_map1();

	void set_map2();

	void set_map3();

	//�������������
	void clear_tip()const;

	//��յ�ͼ���������
	void clear_map()const;

	//���������� �õ� x, y ���� ע������ 30*60
	void set_see(int i,int j);
private:
	//��ӡ���±߿�
	//����1��ʾ�ӵڼ��п�ʼ��ӡ
	void print_width_edge(int start)const;

private:
	//��ͼ����Ŀ��
	int map_width;
	//��ʾ������Ŀ��
	int tooltip_width;
	//��������е�ͼ�Լ���ʾ���ĸ߶�
	int height;
	//������Ƶ��ܸ߶�
	int interface_height;
	//������Ƶ��ܿ��
	int interface_width;
	//��ŵ�ͼ
	bool map[30][30];

	cloud foggy;
};


#endif 


