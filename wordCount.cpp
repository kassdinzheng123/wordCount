#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int charCount(FILE *fp) {
	char temp;
	int num = 0;
	temp = fgetc(fp);
	while ( temp != EOF ) {
		temp = fgetc(fp);
		num++;
	}
	return num;
}

int wordCount(FILE *fp) {
	int w = 0;
	char a = fgetc(fp);
	while ( a != EOF) {
		if ( (a >= 'a' && a <= 'z') || ( a >= 'A' && a <= 'Z') || ( a >= '0' && a <= '9') ) {
			while ( (a >= 'a' && a <= 'z') || ( a >= 'A' && a <= 'Z') || ( a >= '0' && a <= '9') )
				a = fgetc(fp);
			w++;
			a = fgetc(fp);

		} else
			a = fgetc(fp);
	}
	return w;
}

int main(int argc, char *argv[]) {
	int num = 0;
	int w = 0;
	if ( argc == 3 ) {

		char data;
		FILE *fp = fopen(argv[2], "r");

		if (!fp) {
			printf("错误：文件读取失败\n");
			return -1;
		}

		//对参数进行判断

		if ( !strcmp(argv[1], "-c") ) { //字符数
			num = charCount(fp);
			printf("该文本文件的字符数为：%d\n", num);
		} else if ( !strcmp(argv[1], "-w") ) { //单词数
			w = wordCount(fp);
			printf("该文本文件的单词数为：%d\n", w);

		}

		else {
			printf("错误：参数超出范围！\n");
			printf("允许参数：-c，-w，-l\n");
		}
		int n = fclose(fp);
	} else {
		printf("错误：运行参数必须要3个\n");
		printf("用法：wc.exe [parameter] [file_name]\n");
	}
	system("pause");
	return 0;
}
