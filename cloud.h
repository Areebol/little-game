//file: cloud.h

#ifndef CLOUD_H
#define CLOUD_H

//迷雾覆盖类
class cloud
{
public:
	//初始化
	cloud();

	//重新设置为全图不可视
	void reset();

	//将点 x , y 设置为可视
	void set_clear(int i, int j);

	//将点 x , y 设置为不可视
	void set_dark(int i, int j);

	//判断点 x , y 是否可视
	bool is_see(int i, int j)const;
private:
	bool foggy[30][60];//根据控制台的单元格大小定义  30*60
};

#endif