#pragma once
class HCode
{
private:
	static const int MaxH = 100;//哈夫曼树的最大高度不超过100
public:
	char cd[MaxH];//
	int start;//cd[start-n0]是哈夫曼编码
	HCode();
	~HCode();
};

