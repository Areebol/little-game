//file: cloud.h

#ifndef CLOUD_H
#define CLOUD_H

//��������
class cloud
{
public:
	//��ʼ��
	cloud();

	//��������Ϊȫͼ������
	void reset();

	//���� x , y ����Ϊ����
	void set_clear(int i, int j);

	//���� x , y ����Ϊ������
	void set_dark(int i, int j);

	//�жϵ� x , y �Ƿ����
	bool is_see(int i, int j)const;
private:
	bool foggy[30][60];//���ݿ���̨�ĵ�Ԫ���С����  30*60
};

#endif