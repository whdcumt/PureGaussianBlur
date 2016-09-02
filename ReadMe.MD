#【code.c】修改的可运行于ubuntu系统下的纯高斯模糊代码文件
#C语言知识点汇总
[1]#pragma pack(push,2) /#pragma pack() 字节的对齐
[参考博客1](http://www.cnblogs.com/King-Gentleman/p/5297355.html)
[参考博客2](http://blog.chinaunix.net/uid-25445243-id-2354324.html)<br>
[2]将typedef struct tagBITMAPINFOHEADER中的tagBITMAPINFOHEADER 删掉,运行结果不受影响<br>
[3]打开一个文件fopen().<br>
[4]根据文件的存储格式读取里面的内容fread().<br>
[5]综合BMP图像的结构,和知识点4和5,可以实现图像数据的读取.<br>
[7]将图像处理完后得到的bmp图像写入图像变量保存起来.<br>

