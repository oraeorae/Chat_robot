/*
======================================= 
       【奥利奥聊天机器人1.0】 
       
作者QQ:2783608988      --奥利奥
欢迎大家加Q交流 提出宝贵意见
敬请期待下一版
程序原理：根据关键字和用户聊天  
程序特点：1. 添加惩罚机制（骂人有惩罚）； 
2.发出指定关键字能在电脑弹出某种东西。
		 
				时间：2016年9月9号
				 
=======================================
*/
 
/*				头文件					*/
# include <windows.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
 
/*				声明函数				*/
int chat(void);											//和机器人聊天 
void MainMean(void);									//显示标题，设置窗口 
void gotxy(int x, int y);								//光标到指定位置 
int CheckYello(char *c_string);							//检查是否有黄段子
int CheckUnlawful(char *c_string);						//检查是否有骂人内容		
int FindSpecifiedText(char *a_string,char *f_string);	//在指定文本中寻找字符串 
 
/*				全局变量				*/
int warning = 0;	//惩罚机制 
 
 
 int main(void)
{
 
	MainMean();
	
	HWND hWnd = FindWindow(NULL,"管理员:  奥利奥聊天机器人"); //★FindWindow靠名字来取得句柄   
 
	srand((unsigned)time(NULL));			//随机数种子
	int tips = ( rand() % 5 ) ;	 			//取随机数（0~4） 
	if( 0 == tips ) 
	{
		MessageBox(hWnd,TEXT("本程序有惩罚机制哦，在你骂人的时候，机器人就会惩罚你"),TEXT("小提示：【随机】"),MB_OK); 
	}
	else if( 1 == tips ) 
	{
		MessageBox(hWnd,TEXT("体验完本程序，并向作者提出3条建议，则可向作者免费索取源码"),TEXT("小提示：【随机】"),MB_OK); 
	}
	else if( 2 == tips ) 
	{
		MessageBox(hWnd,TEXT("本程序里有一些隐藏功能哦，期待你的发现"),TEXT("小提示："),MB_OK); 
	}
	else if( 3 == tips ) 
	{
		MessageBox(hWnd,TEXT("和机器人聊天的过程中 如果你发“QQ”，机器人会告诉你作者的QQ哦"),TEXT("小提示：【随机】"),MB_OK); 
	}
	else if( 4 == tips ) 
	{
		MessageBox(hWnd,TEXT("祝你玩的开心！只要你想，机器人会一直陪着你的 "),TEXT("小提示：【随机】"),MB_OK); 
	}
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //机器人气泡 
 
	while(1)
	{
		if(chat())	//和机器人聊天 
		{
			exit (0);//结束程序 
		}
	} 
	
 	return 0;
	
}	 
/*
================================================= 
本函数作用：显示标题和设置窗口 
================================================= 
*/
 void MainMean(void)
 {
 	system("title 奥利奥聊天机器人");			//改变窗口标题
	system("mode con: cols=38 lines=30");		//改变窗口大小 
 	system("cls");    							//清屏 		
	//gotoxy(0,0); 
 	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY); //设置控制台字体颜色 
	printf( "                                  \n"
			"            奥利奥聊天机器人      \n"
		    "                                  \n"); 
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_INTENSITY|COMMON_LVB_GRID_HORIZONTAL); //机器人气泡   
	printf( "★输入聊天内容↓                     \n\n" );
 	return;
 }
 
/*
==================================== 
函数作用：在指定文本中寻找字符串 
参数1：待寻找的字符串 
参数2：用作寻找的字符串
返回值：找到返回0，没有找到返回1 
==================================== 
*/
int FindSpecifiedText(char *a_string,char *f_string)
{
	int a_n =0 , f_n = 0 ,same;
	while( a_string[a_n] != '\0' )	//检测待寻找的字符串是否结束 
	{
		if( a_string[a_n] == f_string[f_n])	//如果第一个“字符”相等，则进入继续判断 
		{
			same = 1 ; 
//stricmp
			while(a_string[++a_n] == f_string[++f_n])	
			{
				if( f_string[f_n] != '\0' )
				{
					++same;	//计算相同字符的个数 
				}
			} 
		
		}
		a_n++;
			
	}
	
	f_n = 0;
	while( f_string[f_n++] != '\0' ) //利用while语句计算用作寻找的字符串的数量（包含'/0'）
	{
		;
	}
	
	
	//for( f_n = 0;f_string[f_n++] != '\0';);//利用for语句计算用作寻找的字符串的数量（包含'/0'）
	
 
//	printf("same = %d,f_n = %d\n",same,f_n-1); //输入调试信息 
 
	if( same == --f_n )  //如果相同字符的个数等于用作寻找的字符串的数组个数 那么说明有相同
		return 0;
	else 	
		return 1; 
	
}
/*
============================== 
函数作用：检查是否有黄段子 
函数参数：待检查的字符串  
返回值：检查到返回0，否则返回1 
============================== 
*/
int CheckYello(char *c_string)			
{
 
	if( ! FindSpecifiedText(c_string,"开房") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"三级") )
		return 0; 	
	else if ( ! FindSpecifiedText(c_string,"上床") )
		return 0; 	
	else if ( ! FindSpecifiedText(c_string,"啪啪啪") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"黄色") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"AV") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"av") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"做爱") )
		return 0; 	
	else 
		return 1; 
} 
 
/*
============================== 
函数作用：检查是否有骂人内容 
函数参数：待检查的字符串  
返回值：检查到返回0，否则返回1 
============================== 
*/
int CheckUnlawful(char *c_string)
{
	if( ! FindSpecifiedText(c_string,"艹") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"操你") )
		return 0; 	
	else if ( ! FindSpecifiedText(c_string,"草你") )
		return 0; 	
	else if ( ! FindSpecifiedText(c_string,"傻逼") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"傻刁") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"傻屌") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"傻吊") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"神经") )
	return 0; 
	else if ( ! FindSpecifiedText(c_string,"妈逼") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"死全家") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"草泥马") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"fuck") )
		return 0; 		
	else if ( ! FindSpecifiedText(c_string,"逼逼") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"白痴") )
		return 0; 
	else if ( ! FindSpecifiedText(c_string,"bb") )
		return 0; 	
		
	else 
		return 1; 
} 
 
 
 
 
int chat(void)
{
	 ; //用户和机器人的聊天内容 
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY); //用户气泡 
	printf("◆用户："); 
	
	int message ;
	char string[20] = {0};//清零 
	
	gets(string); //获取用户的聊天内容 
	printf("\n");
	SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN|FOREGROUND_INTENSITY); //机器人气泡 
	
/*
	检测内容：黄段子，骂人内容，“笑话”“新闻”“唱歌”“吃屎”“吃惊” “去死”
“滚”“不”（“不可能”“是不是”“能不能”“好不好”
“不哭”“不要哭”“不要”“不是”“不可以”“不会”
“可不可以”“行不行”
）
“算了”“免费”“知道”“其他”“无聊” “什么”“问题” 
“谢谢”“笨蛋”“蠢”“主人”“QQ”“qq”“博客”“密码”
“C语言”“c语言”“机器人”“在吗”“哈”“呵”“恩”
“嗯”“怕”“88”“再见”“拜”“哪里”“地址”“住址”
“什么时候”“几点”“时间”“多少”“几”“帅”“不如”
“你”（“你真”“爱你”“你猜”“性别”“你是谁”“你谁”
“打你”“帅”“酷”“你好”）“哥”“爸”“爷”“弟”
“儿”“孙”“我”（“伤心”“帮我”“生气”）“才”
 数字1到9 
	检测内容按先后顺序，有优先级之分 
*/
 
 
 
/*	if( ! FindSpecifiedText(string,"我") )      
	{
		if( ! FindSpecifiedText(string,"猪") ) 
		{	
			printf("●机器人：你才知道你是猪啊\n\n");	
			return 0; 
		}
		
		
	} */
/*	下面不用else if的原因是：防止出现进入上面的代码，找不到合适的，从而导致没有回复的内容	*/
	
	if( warning > 3  && warning < 10 )
	{
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
		printf("★机器人拒绝接受你的信息\n\n");
		warning++;
	}
	else if( warning > 10 ) 
	{
		printf("●机器人：哈哈，你是不是怕了？帮你取消吧\n\n");
		system("shutdown -a");	//取消关机
		warning = 0;
	}
 	else if( ! CheckUnlawful(string) )
 	{
 		if( 0 == warning )
 		{
 			srand((unsigned)time(NULL));			//随机数种子
			message = ( rand() % 4 ) ;	 			//取随机数（0~9） 
			if( 0 == message ) 
			{
				printf("●机器人：你怎么可以骂人呢\n\n");
			}
			else if(  1 == message )
			{
				printf("●机器人：呦，小心我打你\n\n");
			}
			else if( 2 == message ) 
			{
				printf("●机器人：素质满天飞\n\n");
			}
			else if( 3 == message ) 
			{
				printf("●机器人：哼，我不理你了\n\n");
			}
			
 		}
 		else if( 1 == warning ) 
		{
			printf("●机器人：这么嚣张，我给你点教训。欢迎继续侮辱我\n\n");
			int i;
			for( i = 0 ; i < 10 ; i++ )	//弹出10个命令提示符（惩罚机制1） 
			{
				system("start");     	
			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
			printf("★机器人帅气地丢给你10个命令提示符\n\n");
		}
 		else if( 2 == warning )
 		{
 			printf("●机器人：既然你还这么不服,那我就继续给惩罚\n\n");
 			int a;
			for( a = 0 ; a < 20 ; a++ )	//弹出20个命令提示符 （惩罚机制2） 
			{
				system("start");     	
			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
			printf("★机器人再次帅气地丢给你20个命令提示符\n\n"); 
		 }
		else if( 3 == warning )
 		{
 			printf("●机器人：好吧我输了，再见\n\n");
			system("shutdown -s -t 180");     	//3分钟后关机（惩罚机制2） 
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
			printf("★机器人认输了 你真棒\n\n");
		}
	
		warning++; //惩罚机制+1 
		
	}
	else if( ! CheckYello(string) )
	{
		message = ( rand() % 4 ) ;	 			//取随机数（0~3） 
		if( ! message ) 
		{
			printf("●机器人：看错你了 没想到你是这种人\n\n");
		}
		else if(  1 == message )
		{
			printf("●机器人：你好污啊 真讨厌\n\n");
		}
		else if( 2 == message ) 
		{
			printf("●机器人：别跟我聊这么污的话题 好吗\n\n");
		}
		else if( 3 == message ) 
		{
			printf("●机器人：注意注意 老司机出来开车了 \n\n");
		}
		system("start http://www.360kan.com/ct/OUPna57kLIz2CT.html");	//打开网站【天线宝宝】 
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
		printf("★机器人看你如此饥渴难耐，抛出一个视频网站\n\n");
	} 
	else if( ! FindSpecifiedText(string,"笑话") ) 
	{
		printf("●机器人：我给你讲个小笑话。从前有个人…哈哈哈\n\n");
	} 	
	else if( ! FindSpecifiedText(string,"新闻") ) 
	{
		printf("●机器人：新华社报道:昨日晚间,天津市有个包子去打狗,就再也没有回来……\n\n");
	} 
	else if( ! FindSpecifiedText(string,"唱歌") ) 
	{
		printf("●机器人：唱歌？我先让你听听我的声音，你再决定\n\n");
		Sleep(500); 
		printf("\a\a\a");//发出声音 
		printf("★机器人发出动听的声音，滴~滴~\n\n");
	
	} 
	else if( ! FindSpecifiedText(string,"吃屎") ) 
	{
		printf("●机器人：哎呦，我不喜欢吃你\n\n");
	} 
	else if( ! FindSpecifiedText(string,"吃惊") ) 
	{
		printf("●机器人：吃惊…我还吃鲸鱼呢- -\n\n");
	} 
	else if( ! FindSpecifiedText(string,"去死") ) 
	{
		printf("●机器人：我永远也不会死 ：）\n\n");
	} 
	else if( ! FindSpecifiedText(string,"滚") ) 
	{
		printf("●机器人：滚来滚去~滚来滚去~\n\n");
	} 
	
	
	else if( ! FindSpecifiedText(string,"不") )
	{
		if( ! FindSpecifiedText(string,"不可能")) 
		{
			printf("●机器人：凡事皆有可能\n\n");
		}
		else if( ! FindSpecifiedText(string,"是不是") ) 
		{
			message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
			if( ! message ) 
			{
				printf("●机器人：你猜\n\n");
			}
			else if( 1 == message ) 
			{
				printf("●机器人：是\n\n");
			}
			else if( 2 == message ) 
			{
				printf("●机器人：不是\n\n");
			}
		}
		else if( ! FindSpecifiedText(string,"能不能") ) 
		{
			printf("●机器人：不能 没商量\n\n");
		}
		else if( ! FindSpecifiedText(string,"好不好") ) 
		{
			printf("●机器人：好～\n\n");
		}
		else if( ! FindSpecifiedText(string,"不哭") || ! FindSpecifiedText(string,"不要哭") ) 
		{
			printf("●机器人：我不哭谁哭啊，你来？\n\n");
		}
	 	else if( ! FindSpecifiedText(string,"不要") ) 
		{
			printf("●机器人：那你要什么呀\n\n");
		} 
		else if( ! FindSpecifiedText(string,"不是")  )
		{
	 		printf("●机器人：不是吗？不然是什么\n\n");
		} 
		else if( ! FindSpecifiedText(string,"不可以") )
		{
		 	printf("●机器人：好吧 那算了\n\n");
		} 
		else if( ! FindSpecifiedText(string,"不会"))
		{
		 	printf("●机器人：没技术 我教你\n\n");
		} 
		else if( ! FindSpecifiedText(string,"可不可以") )
		{
	 		printf("●机器人：当然可以啊\n\n");
		} 
		else if( ! FindSpecifiedText(string,"行不行") )
		{
	 		printf("●机器人：行啊，只要你想\n\n");
		} 
		else if( ! FindSpecifiedText(string,"不信") )
		{
	 		printf("●机器人：是吗，怎么才信呢\n\n");
		} 
		else
		{
			printf("●机器人：那就好\n\n");	
		} 
	} 
	else if( ! FindSpecifiedText(string,"计算") )
	{
	 	printf("●机器人：我暂时不想动脑，你用计算器算吧\n\n");
	 	system("calc");	//打开计算器 
	 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
	 	printf("★机器人扔出计算器给你用\n\n");
	}
	else if( ! FindSpecifiedText(string,"算了") )
	{
	 	printf("●机器人：那该怎么办？\n\n");
	} 
	else if( ! FindSpecifiedText(string,"免费") )
	{
	 	printf("●机器人：那也不行！\n\n");
	} 
	else if( ! FindSpecifiedText(string,"知道") )
	{
	 	printf("●机器人：知道就好.\n\n");
	} 
	else if( ! FindSpecifiedText(string,"其他") )
	{
	 	printf("●机器人：你说呀！！\n\n");
	} 
	else if( ! FindSpecifiedText(string,"无聊") )
	{
	 	printf("●机器人：让我陪你聊天吧，我知道好多事情呢\n\n");
	} 
 	else if( ! FindSpecifiedText(string,"什么") || ! FindSpecifiedText(string,"问题") )
	{
		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
			if( ! message ) 
			{
				printf("●机器人：你为什么不问问神奇的海螺呢\n\n");
			}
			else if( 1 == message ) 
			{
				printf("●机器人：我也不知道啊，你怎么不问问度娘\n\n");
			}
			else if( 2 == message ) 
			{
				printf("●机器人：我帮你叫我的老师过来 不用谢我\n\n");
				system("start https://www.baidu.com/"); 			//打开【百度一下，你就知道】  	
				printf("★机器人送给你一个网址\n\n");
			
			 } 
	} 
	else if( ! FindSpecifiedText(string,"谢谢") )
	{	
		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
		if( 0 ==  message ) 
		{
			printf("●机器人：不用谢，对我来说是小菜一碟的事.\n\n");
		}
		else if( 1 == message ) 
		{
			printf("●机器人：不用谢 我是奥利奥机器人\n\n");
		}
		else if( 2 == message ) 
		{ 
			printf("●机器人：你太客气了，跟我还客气什么啊\n\n");
		}
	
	} 
	else if( ! FindSpecifiedText(string,"笨蛋") )
	{
	 	printf("●机器人：我是很笨哦，聪明的话就不跟你聊天了.\n\n");
	} 
	else if( ! FindSpecifiedText(string,"蠢") )
	{
	 	printf("●机器人：我是很蠢哦，聪明的话就不跟你聊天了.\n\n");
	} 
	else if( ! FindSpecifiedText(string,"主人") || ! FindSpecifiedText(string,"作者"))
	{
	 	printf("●机器人：我的主人是奥利奥 , 我诞生于2016年\n\n");
	} 
	else if( ! FindSpecifiedText(string,"QQ") || ! FindSpecifiedText(string,"qq") )
	{
	 	printf("●机器人：我没有QQ,我的主人QQ是2783608988。随便帮你打开我主人的空间\n\n");
	 	system("start http://user.qzone.qq.com/2783608988/main"); //打开QQ空间 怪咖i [http://2783608988.qzone.qq.com] 
	 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
	 	printf("★机器人帮你打开了作者的QQ空间\n\n");
	} 
	else if( ! FindSpecifiedText(string,"博客") )
	{
	 	printf("●机器人：我没有博客,不过我的主人有。我帮你打开我主人的博客\n\n");
	 	system("start http://blog.csdn.net/qq_34028920"); //打开博客 qq_34028920的博客 - 博客频道 - CSDN.NET 
	 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
	 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);//系统提示气泡 
		printf("★机器人帮你打开了作者的博客\n\n"); 
	} 
	else if( ! FindSpecifiedText(string,"密码") ) 
	{
		printf("●机器人：密码是*****，慢慢破译吧\n\n");
	} 
	
	else if( ! FindSpecifiedText(string,"C语言") || ! FindSpecifiedText(string,"c语言") ) 
	{
		printf("●机器人：你怎么知道我是C语言做的\n\n");
	} 
 
	else if( ! FindSpecifiedText(string,"机器人") ) 
	{
		printf("●机器人：你是在说我吗？\n\n");
	} 
	
	else if( ! FindSpecifiedText(string,"在吗") ) 
	{
		printf("●机器人：不在【自动回复】\n\n");
	} 
	else if( ! FindSpecifiedText(string,"哈") || ! FindSpecifiedText(string,"呵"))
	{
	
		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
		
			if( 0 == message ) 
			{
				printf("●机器人：你笑得那么开心干嘛 \n\n");
			}
			else if( 1 == message ) 
			{
				printf("●机器人：你笑得没有我笑的可爱 \n\n");
			}
			else if( 2 == message ) 
			{
				printf("●机器人：你现在的心情很好吧？\n\n");
			}
	 
	} 
	else if( ! FindSpecifiedText(string,"恩") || ! FindSpecifiedText(string,"嗯"))
	{
	 	printf("●机器人：啦啦啦\n\n");
	} 
 
	else if( ! FindSpecifiedText(string,"怕") )
	{
	 	printf("●机器人：知道怕了就好\n\n");
	} 
	else if( ! FindSpecifiedText(string,"88")||! FindSpecifiedText(string,"再见")||! FindSpecifiedText(string,"拜") ) 
	{
		printf("●机器人：和你聊天很快乐，下次再见\n\n");
		return 1; 
	} 
	else if( ! FindSpecifiedText(string,"哪里") || ! FindSpecifiedText(string,"地址") || ! FindSpecifiedText(string,"住址") )
	{
	 	printf("●机器人：在这里\n\n");
	} 
	else if( ! FindSpecifiedText(string,"什么时候") )
	{
	 	printf("●机器人：猴年马月\n\n");
	} 
	else if( ! FindSpecifiedText(string,"几点") || ! FindSpecifiedText(string,"时间") )
	{
	 	printf("●机器人：看你电脑的右下角\n\n");
	} 
	else if(  ! FindSpecifiedText(string,"多少") || ! FindSpecifiedText(string,"几") ) 
	{
		message = ( rand() % 2 ) ;	 			//取随机数（0~1） 
		
		if( 0 == message ) 
		{
		printf("●机器人：哎，我也不知道\n\n");	
		} 
		if( 1 == message ) 
		{
		printf("●机器人：你说多少就多少。\n\n");	
		} 
	} 
	else if(  ! FindSpecifiedText(string,"帅") ) 
	{
		printf("●机器人：没错，我最帅\n\n");	
	} 
/*	else if(  ! FindSpecifiedText(string,"虽然") ) 
	{
		printf("●机器人：\n\n");	
	} */
	else if(  ! FindSpecifiedText(string,"不如") ) 
	{
		printf("●机器人：好啊 好啊\n\n");	
	} 
	else if(  ! FindSpecifiedText(string,"您好") || ! FindSpecifiedText(string,"hello") || ! FindSpecifiedText(string,"hi") ) 
	{
		printf("●机器人：嗨，很高兴见到你\n\n");	
	} 
 
	else if( ! FindSpecifiedText(string,"哥") || ! FindSpecifiedText(string,"爸") || ! FindSpecifiedText(string,"爷") ) 
	{
			printf("●机器人：恩，乖\n\n");
	} 
	else if( ! FindSpecifiedText(string,"弟") || ! FindSpecifiedText(string,"儿") || ! FindSpecifiedText(string,"孙") ) 
	{
			printf("●机器人：啊？这里信号不好，再说一遍\n\n");
	} 
	else if( ! FindSpecifiedText(string,"我") ) 
	{
		if( ! FindSpecifiedText(string,"伤心")/*||! FindSpecifiedText(string,"哭")*/) 
		{
			printf("●机器人：谁欺负你了 我替你打他\n\n");
		}
		else if( ! FindSpecifiedText(string,"帮我") )
		{
		 	printf("●机器人：我不帮你 自己的事自己做\n\n");
		} 
	 	else if( ! FindSpecifiedText(string,"生气") ) 
		{
			printf("●机器人：哦，关我什么事\n\n");
		} 		
		else
		{
			printf("●机器人：你怎么了\n\n");
		}
	} 
	else if( ! FindSpecifiedText(string,"才") ) 
	{
		printf("●机器人：怎么这么晚\n\n");
	}
	else if( ! FindSpecifiedText(string,"你") )
	{
		if( ! FindSpecifiedText(string,"你真")) 
		{
			printf("●机器人：一般一般，天下第三\n\n");
		}
		else if( ! FindSpecifiedText(string,"爱你")) 
		{
			printf("●机器人：我也爱我强大的主人\n\n");
		}
	 	else if( ! FindSpecifiedText(string,"你猜") ) 
		{
			printf("●机器人：你猜我猜不猜？\n\n");
		} 
		else if( ! FindSpecifiedText(string,"性别") ) 
		{
			printf("●机器人：我可是纯爷们 \n\n");
		} 
		else if( ! FindSpecifiedText(string,"你是谁") || ! FindSpecifiedText(string,"你谁") )
		{
	 		printf("●机器人：我是帅气的奥利奥机器人\n\n");
		} 
		else if( ! FindSpecifiedText(string,"打你") ) 
		{
			printf("●机器人：你确定？我的头可比钢还硬\n\n");
		} 
		else if( ! FindSpecifiedText(string,"你好") )
		{
			printf("●机器人：你好啊，我最喜欢跟人聊天了\n\n");
		}
	/*	else if( ! FindSpecifiedText(string,"帅") || ! FindSpecifiedText(string,"酷")) 
		{
			printf("●机器人：谢谢夸奖\n\n");
		} */
		else
		{
			printf("●机器人：我？我怎么了\n\n");	
		} 
	} 
 
	/*	else if( ! FindSpecifiedText(string,"1") ! FindSpecifiedText(string,"2") || ! FindSpecifiedText(string,"3") || ! FindSpecifiedText(string,"4") || ! FindSpecifiedText(string,"5") || ! FindSpecifiedText(string,"6") || ! FindSpecifiedText(string,"7") || ! FindSpecifiedText(string,"8") || ! FindSpecifiedText(string,"9"))*/
	else if( ! FindSpecifiedText(string,"110") ) 
	{
		
	}
 
  	else 
  	{ 
  		message = ( rand() % 3 ) ;	 			//取随机数（0~2） 
		
			if( 0 == message ) 
			{
				printf("●机器人：我不确定我是否能理解你说的是什么 ...\n\n");
			}
			else if( 1 == message ) 
			{
				printf("●机器人：我还小，智慧不足，等我升级以后就能理解你说的话了！\n\n");
			}
			else if( 2 == message ) 
			{
				printf("●机器人： 对不起，我没明白你的意思！……\n\n");
			}
 	
	 	
	}
 
	
	return 0;
 } 
 
 
/*
======================================= 
本函数作用：光标到指定位置 
参数1：指定列x
参数2：指定行y
参数3：1表示ASCLL码 2表示表示非ASCLL码 
======================================= 
*/
void gotoxy(int x, int y)						//光标到指定位置 
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);		//获得标准输出输出的句柄
	COORD pos = { x,y };						//表示一个字符在控制台屏幕上的坐标(ASCLL码宽度为1 非ASCLL码宽度为2)
	SetConsoleCursorPosition(hOut, pos);		//光标定位在对应的位置	
	return;
}

